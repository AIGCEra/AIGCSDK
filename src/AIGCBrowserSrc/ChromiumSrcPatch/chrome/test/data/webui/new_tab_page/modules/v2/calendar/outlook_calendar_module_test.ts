// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import type {OutlookCalendarModuleElement} from 'tangram://new-tab-page/lazy_load.js';
import {outlookCalendarDescriptor} from 'tangram://new-tab-page/lazy_load.js';
import {loadTimeData} from 'tangram://resources/js/load_time_data.js';
import {assertEquals, assertTrue} from 'tangram://webui-test/chai_assert.js';
import {isVisible} from 'tangram://webui-test/test_util.js';

suite('NewTabPageModulesOutlookCalendarModuleTest', () => {
  const title = 'Outlook Calendar';

  setup(() => {
    loadTimeData.overrideValues({
      modulesOutlookCalendarTitle: title,
    });
    document.body.innerHTML = window.trustedTypes!.emptyHTML;
  });

  test(`creates module`, async () => {
    const module = await outlookCalendarDescriptor.initialize(0) as
        OutlookCalendarModuleElement;
    assertTrue(!!module);
    document.body.append(module);

    // Assert.
    assertTrue(isVisible(module.$.moduleHeaderElementV2));
    assertEquals(module.$.moduleHeaderElementV2.headerText, title);
  });
});
