// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import './auto_tab_groups/auto_tab_groups_page.js';
import './declutter/declutter_page.js';
import './tab_organization_selector_button.js';

import {PluralStringProxyImpl} from 'tangram://resources/js/plural_string_proxy.js';
import {CrLitElement} from 'tangram://resources/lit/v3_0/lit.rollup.js';

import type {DeclutterPageElement} from './declutter/declutter_page.js';
import {getCss} from './tab_organization_selector.css.js';
import {getHtml} from './tab_organization_selector.html.js';
import type {Tab} from './tab_search.mojom-webui.js';
import {DeclutterCTREvent, SelectorCTREvent, TabDeclutterEntryPoint, TabOrganizationFeature} from './tab_search.mojom-webui.js';
import type {TabSearchApiProxy} from './tab_search_api_proxy.js';
import {TabSearchApiProxyImpl} from './tab_search_api_proxy.js';

export interface TabOrganizationSelectorElement {
  $: {
    autoTabGroupsPage: HTMLElement,
    declutterPage: DeclutterPageElement,
  };
}


export class TabOrganizationSelectorElement extends CrLitElement {
  static get is() {
    return 'tab-organization-selector';
  }

  static override get styles() {
    return getCss();
  }

  override render() {
    return getHtml.bind(this)();
  }

  static override get properties() {
    return {
      declutterHeading_: {type: String},
      disableDeclutter_: {type: Boolean},
      selectedState_: {type: Number},
    };
  }

  protected selectedState_: TabOrganizationFeature =
      TabOrganizationFeature.kSelector;
  protected declutterHeading_: string = '';
  protected disableDeclutter_: boolean = false;
  private apiProxy_: TabSearchApiProxy = TabSearchApiProxyImpl.getInstance();
  private listenerIds_: number[] = [];
  private visibilityChangedListener_: () => void;

  constructor() {
    super();

    this.visibilityChangedListener_ = () => {
      if (document.visibilityState === 'visible') {
        this.apiProxy_.getStaleTabs().then(
            ({tabs}) => this.updateDeclutterTabs_(tabs));
      }
    };
  }

  override connectedCallback() {
    super.connectedCallback();
    this.apiProxy_.getStaleTabs().then(
        ({tabs}) => this.updateDeclutterTabs_(tabs));
    this.apiProxy_.getTabOrganizationFeature().then(
        ({feature}) => this.updateSelectedFeature_(feature));
    const callbackRouter = this.apiProxy_.getCallbackRouter();
    this.listenerIds_.push(callbackRouter.staleTabsChanged.addListener(
        this.updateDeclutterTabs_.bind(this)));
    this.listenerIds_.push(
        callbackRouter.tabOrganizationFeatureChanged.addListener(
            this.updateSelectedFeature_.bind(this)));
    document.addEventListener(
        'visibilitychange', this.visibilityChangedListener_);
  }

  override disconnectedCallback() {
    super.disconnectedCallback();
    this.listenerIds_.forEach(
        id => this.apiProxy_.getCallbackRouter().removeListener(id));
    document.removeEventListener(
        'visibilitychange', this.visibilityChangedListener_);
  }

  maybeLogFeatureShow(): void {
    if (this.selectedState_ === TabOrganizationFeature.kSelector) {
      this.logSelectorCtrValue_(SelectorCTREvent.kSelectorShown);
    } else if (this.selectedState_ === TabOrganizationFeature.kDeclutter) {
      this.$.declutterPage.logCtrValue(DeclutterCTREvent.kDeclutterShown);
    }
  }

  protected onAutoTabGroupsClick_(): void {
    this.logSelectorCtrValue_(SelectorCTREvent.kAutoTabGroupsClicked);
    this.apiProxy_.requestTabOrganization();
    this.selectedState_ = TabOrganizationFeature.kAutoTabGroups;
    this.apiProxy_.setOrganizationFeature(this.selectedState_);
    this.$.autoTabGroupsPage.classList.toggle('changed-state', false);
  }

  protected onDeclutterClick_(): void {
    this.logSelectorCtrValue_(SelectorCTREvent.kDeclutterClicked);

    chrome.metricsPrivate.recordEnumerationValue(
        'Tab.Organization.Declutter.EntryPoint',
        TabDeclutterEntryPoint.kSelector, TabDeclutterEntryPoint.MAX_VALUE + 1);

    this.$.declutterPage.logCtrValue(DeclutterCTREvent.kDeclutterShown);
    this.selectedState_ = TabOrganizationFeature.kDeclutter;
    this.apiProxy_.setOrganizationFeature(this.selectedState_);
  }

  protected onBackClick_(): void {
    this.logSelectorCtrValue_(SelectorCTREvent.kSelectorShown);
    this.selectedState_ = TabOrganizationFeature.kSelector;
    this.apiProxy_.setOrganizationFeature(this.selectedState_);
  }

  private async updateDeclutterTabs_(tabs: Tab[]): Promise<void> {
    const declutterTabCount = tabs.length;
    this.disableDeclutter_ = declutterTabCount === 0;
    this.declutterHeading_ =
        await PluralStringProxyImpl.getInstance().getPluralString(
            'declutterSelectorHeading', declutterTabCount);
  }

  private updateSelectedFeature_(feature: TabOrganizationFeature) {
    if (feature === TabOrganizationFeature.kNone) {
      return;
    }
    if (feature === TabOrganizationFeature.kDeclutter &&
        this.disableDeclutter_) {
      this.selectedState_ = TabOrganizationFeature.kSelector;
    } else {
      this.selectedState_ = feature;
    }
  }

  private logSelectorCtrValue_(event: SelectorCTREvent) {
    chrome.metricsPrivate.recordEnumerationValue(
        'Tab.Organization.SelectorCTR', event, SelectorCTREvent.MAX_VALUE + 1);
  }
}

declare global {
  interface HTMLElementTagNameMap {
    'tab-organization-selector': TabOrganizationSelectorElement;
  }
}

customElements.define(
    TabOrganizationSelectorElement.is, TabOrganizationSelectorElement);
