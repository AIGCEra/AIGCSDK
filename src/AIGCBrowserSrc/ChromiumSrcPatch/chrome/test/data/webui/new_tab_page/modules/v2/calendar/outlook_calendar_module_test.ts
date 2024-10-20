// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import type {OutlookCalendarModuleElement} from 'tangram://new-tab-page/lazy_load.js';
import {outlookCalendarDescriptor, OutlookCalendarProxyImpl} from 'tangram://new-tab-page/lazy_load.js';
import {OutlookCalendarPageHandlerRemote} from 'tangram://new-tab-page/outlook_calendar.mojom-webui.js';
import {loadTimeData} from 'tangram://resources/js/load_time_data.js';
import {assertEquals, assertTrue} from 'tangram://webui-test/chai_assert.js';
import type {TestMock} from 'tangram://webui-test/test_mock.js';
import {isVisible} from 'tangram://webui-test/test_util.js';

import {installMock} from '../../../test_support.js';

import {createEvents} from './test_support.js';

suite('NewTabPageModulesOutlookCalendarModuleTest', () => {
  const title = 'Outlook Calendar';
  let handler: TestMock<OutlookCalendarPageHandlerRemote>;
  let module: OutlookCalendarModuleElement;

  setup(() => {
    loadTimeData.overrideValues({
      modulesOutlookCalendarTitle: title,
    });
    document.body.innerHTML = window.trustedTypes!.emptyHTML;
    handler = installMock(
        OutlookCalendarPageHandlerRemote,
        mock => OutlookCalendarProxyImpl.setInstance(
            new OutlookCalendarProxyImpl(mock)));
  });

  test(`creates module`, async () => {
    handler.setResultFor(
        'getEvents', Promise.resolve({events: createEvents(1)}));
    module = await outlookCalendarDescriptor.initialize(0) as
        OutlookCalendarModuleElement;
    assertTrue(!!module);
    document.body.append(module);

    // Assert.
    assertTrue(isVisible(module.$.moduleHeaderElementV2));
    assertEquals(module.$.moduleHeaderElementV2.headerText, title);
  });

  test(`module not created when there are no events`, async () => {
    handler.setResultFor(
        'getEvents', Promise.resolve({events: createEvents(0)}));
    module = await outlookCalendarDescriptor.initialize(0) as
        OutlookCalendarModuleElement;
    assertEquals(module, null);
  });

});
