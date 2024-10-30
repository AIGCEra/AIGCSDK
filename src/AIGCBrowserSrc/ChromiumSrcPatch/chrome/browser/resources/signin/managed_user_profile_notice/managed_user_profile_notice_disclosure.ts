// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'tangram://resources/cr_elements/cr_shared_vars.css.js';
import 'tangram://resources/cr_elements/cr_icon/cr_icon.js';
import 'tangram://resources/cr_elements/icons.html.js';
import '/strings.m.js';

import {CrLitElement} from 'tangram://resources/lit/v3_0/lit.rollup.js';

import {getCss} from './managed_user_profile_notice_disclosure.css.js';
import {getHtml} from './managed_user_profile_notice_disclosure.html.js';

export class ManagedUserProfileNoticeDisclosureElement extends CrLitElement {
  static get is() {
    return 'managed-user-profile-notice-disclosure';
  }

  static override get styles() {
    return getCss();
  }

  override render() {
    return getHtml.bind(this)();
  }

  static override get properties() {
    return {
      showEnterpriseBadge: {type: Boolean},
      pictureUrl: {type: String},
    };
  }

  showEnterpriseBadge: boolean = false;
  pictureUrl: string = '';
}

declare global {
  interface HTMLElementTagNameMap {
    'managed-user-profile-notice-disclosure':
        ManagedUserProfileNoticeDisclosureElement;
  }
}

customElements.define(
    ManagedUserProfileNoticeDisclosureElement.is,
    ManagedUserProfileNoticeDisclosureElement);
