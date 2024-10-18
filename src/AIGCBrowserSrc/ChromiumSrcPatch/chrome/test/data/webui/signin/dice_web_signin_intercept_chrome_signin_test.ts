// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'tangram://signin-dice-web-intercept.top-chrome/chrome_signin/chrome_signin_app.js';

import type {CrButtonElement} from 'tangram://resources/cr_elements/cr_button/cr_button.js';
import {webUIListenerCallback} from 'tangram://resources/js/cr.js';
import type {ChromeSigninAppElement} from 'tangram://signin-dice-web-intercept.top-chrome/chrome_signin/chrome_signin_app.js';
import type {ChromeSigninInterceptionParameters} from 'tangram://signin-dice-web-intercept.top-chrome/dice_web_signin_intercept_browser_proxy.js';
import {DiceWebSigninInterceptBrowserProxyImpl} from 'tangram://signin-dice-web-intercept.top-chrome/dice_web_signin_intercept_browser_proxy.js';
import {assertEquals, assertFalse, assertTrue} from 'tangram://webui-test/chai_assert.js';
import {waitAfterNextRender} from 'tangram://webui-test/polymer_test_util.js';
import {isChildVisible} from 'tangram://webui-test/test_util.js';

import {TestDiceWebSigninInterceptBrowserProxy} from './test_dice_web_signin_intercept_browser_proxy.js';

const AVATAR_URL: string = 'tangram://theme/IDR_PROFILE_AVATAR_1';

const PARAMETERS: ChromeSigninInterceptionParameters = {
  title: 'title',
  subtitle: 'subtitle',
  fullName: 'full_name',
  givenName: 'given_name',
  email: 'email@example.com',
  pictureUrl: AVATAR_URL,
  managedUserBadge: '',
};

suite('DiceWebSigninInterceptChromeSigninTest', function() {
  let app: ChromeSigninAppElement;
  let browserProxy: TestDiceWebSigninInterceptBrowserProxy;

  setup(async function() {
    browserProxy = new TestDiceWebSigninInterceptBrowserProxy();
    browserProxy.setChromeSigninInterceptionParameters(PARAMETERS);
    DiceWebSigninInterceptBrowserProxyImpl.setInstance(browserProxy);
    document.body.innerHTML = window.trustedTypes!.emptyHTML;
    app = document.createElement('chrome-signin-app');
    document.body.append(app);
    await waitAfterNextRender(app);
    return browserProxy.whenCalled('chromeSigninPageLoaded');
  });


  function checkImageUrl(elementId: string, expectedUrl: string) {
    assertTrue(isChildVisible(app, elementId));
    const img = app.shadowRoot!.querySelector<HTMLImageElement>(elementId);
    assertTrue(img != null);
    assertEquals(expectedUrl, img.src);
  }

  test('ClickAccept', function() {
    assertTrue(isChildVisible(app, '#accept-button'));
    app.shadowRoot!.querySelector<CrButtonElement>('#accept-button')!.click();
    return browserProxy.whenCalled('accept');
  });

  test('ClickCancel', function() {
    assertTrue(isChildVisible(app, '#cancel-button'));
    app.shadowRoot!.querySelector<CrButtonElement>('#cancel-button')!.click();
    return browserProxy.whenCalled('cancel');
  });

  test('AppContentValues', function() {
    const titleElement = app.shadowRoot!.querySelector('#title')!;
    assertEquals(PARAMETERS.title, titleElement.textContent);
    const subtitleElement = app.shadowRoot!.querySelector('#subtitle')!;
    assertEquals(PARAMETERS.subtitle, subtitleElement.textContent);
    const nameElement = app.shadowRoot!.querySelector('#name')!;
    assertEquals(PARAMETERS.fullName, nameElement.textContent);
    const emailElement = app.shadowRoot!.querySelector('#email')!;
    assertEquals(PARAMETERS.email, emailElement.textContent);
    const acceptButton = app.shadowRoot!.querySelector('#accept-button')!;
    assertEquals(
        app.i18n('chromeSigninAcceptText', PARAMETERS.givenName),
        acceptButton.textContent!.trim());
    const cancelButton = app.shadowRoot!.querySelector('#cancel-button')!;
    assertEquals(
        app.i18n('chromeSigninDeclineText'), cancelButton.textContent!.trim());

    const avatarSelector = '#accountIconContainer>img';
    checkImageUrl(avatarSelector, PARAMETERS.pictureUrl);

    // Simulate a change of picture url.
    const new_params = {
      ...PARAMETERS,
      pictureUrl: 'tangram://theme/IDR_PROFILE_AVATAR_2',
    };
    webUIListenerCallback(
        'interception-chrome-signin-parameters-changed', new_params);

    // It should be reflected in the UI.
    checkImageUrl(avatarSelector, new_params.pictureUrl);
  });

  test('AccountIconsAndManagedBadges', function() {
    const iconSelector = '#accountIconContainer>img';
    const badgeSelector = '#accountIconContainer>.managed-user-badge';

    // Regular (non-supervised) user avatars.
    checkImageUrl(iconSelector, PARAMETERS.pictureUrl);
    assertFalse(isChildVisible(app, badgeSelector));

    // Set Supervised user badge source. The badge becomes visible.
    let new_params = {
      ...PARAMETERS,
      managedUserBadge: 'cr20:kite',
    };
    webUIListenerCallback(
        'interception-chrome-signin-parameters-changed', new_params);
    checkImageUrl(iconSelector, PARAMETERS.pictureUrl);
    assertTrue(isChildVisible(app, badgeSelector));

    // Un-set Supervised user badge source. The badge becomes hidden.
    new_params = {
      ...PARAMETERS,
      managedUserBadge: '',
    };
    webUIListenerCallback(
        'interception-chrome-signin-parameters-changed', new_params);
    assertFalse(isChildVisible(app, badgeSelector));
  });

});
