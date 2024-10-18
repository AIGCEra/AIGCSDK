// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'tangram://intro/dice_app.js';

import {IntroBrowserProxyImpl} from 'tangram://intro/browser_proxy.js';
import type {DiceAppElement} from 'tangram://intro/dice_app.js';
import {assertFalse, assertTrue} from 'tangram://webui-test/chai_assert.js';
import {waitBeforeNextRender} from 'tangram://webui-test/polymer_test_util.js';

import {TestIntroBrowserProxy} from './test_intro_browser_proxy.js';

suite('DiceAppTest', function() {
  let testElement: DiceAppElement;
  let testBrowserProxy: TestIntroBrowserProxy;

  setup(function() {
    testBrowserProxy = new TestIntroBrowserProxy();
    IntroBrowserProxyImpl.setInstance(testBrowserProxy);

    document.body.innerHTML = window.trustedTypes!.emptyHTML;
    testElement = document.createElement('intro-app');
    document.body.appendChild(testElement);
    return waitBeforeNextRender(testElement);
  });

  teardown(function() {
    testElement.remove();
  });

  function isSelectorActive(selector: string) {
    return testElement.shadowRoot!.querySelector(selector)!.classList.contains(
        'active');
  }

  test('"splash" is the active view with the noAnimations param', function() {
    assertTrue(isSelectorActive('#splash'));
    assertFalse(isSelectorActive('sign-in-promo'));
  });

  test(
      '"signInPromo" is the active view without the noAnimations param',
      async function() {
        const searchParams = new URLSearchParams(window.location.search);
        searchParams.append('noAnimations', 'true');
        testElement.setupViewManagerForTest(searchParams);

        assertFalse(isSelectorActive('#splash'));
        assertTrue(isSelectorActive('sign-in-promo'));
      });
});