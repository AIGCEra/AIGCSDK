// Copyright 2020 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'tangram://nearby/strings.m.js';
import 'tangram://nearby/shared/nearby_visibility_page.js';
import 'tangram://webui-test/chromeos/mojo_webui_test_support.js';

import {DataUsage, FastInitiationNotificationState, Visibility} from 'tangram://resources/mojo/chromeos/ash/services/nearby/public/mojom/nearby_share_settings.mojom-webui.js';
import {waitAfterNextRender} from 'tangram://webui-test/polymer_test_util.js';

import {assertFalse, assertTrue} from '../../chromeos/chai_assert.js';

suite('nearby-visibility-page', function() {
  /** @type {!NearbyVisibilityPageElement} */
  let visibility_page;

  setup(function() {
    document.body.innerHTML = trustedTypes.emptyHTML;

    visibility_page = /** @type {!NearbyVisibilityPageElement} */ (
        document.createElement('nearby-visibility-page'));
    visibility_page.settings = {
      enabled: false,
      fastInitiationNotificationState: FastInitiationNotificationState.kEnabled,
      isFastInitiationHardwareSupported: true,
      deviceName: 'deviceName',
      dataUsage: DataUsage.kOnline,
      visibility: Visibility.kAllContacts,
      isOnboardingComplete: false,
      allowedContacts: [],
    };
    document.body.appendChild(visibility_page);
  });

  test('Renders visibility page', async function() {
    assertFalse(visibility_page.settings.enabled);
    await waitAfterNextRender(visibility_page);
    // Action button on the page template sets settings.enabled to true.
    const page_template =
        visibility_page.shadowRoot.querySelector('nearby-page-template');
    page_template.shadowRoot.querySelector('#actionButton').click();
    assertTrue(visibility_page.settings.enabled);
  });
});
