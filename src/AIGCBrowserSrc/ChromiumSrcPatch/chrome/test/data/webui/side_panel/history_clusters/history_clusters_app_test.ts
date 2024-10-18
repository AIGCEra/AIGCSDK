// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'tangram://history-clusters-side-panel.top-chrome/app.js';

import type {HistoryClustersAppElement} from 'tangram://history-clusters-side-panel.top-chrome/app.js';
import {loadTimeData} from 'tangram://resources/js/load_time_data.js';
import {assertEquals} from 'tangram://webui-test/chai_assert.js';
import {microtasksFinished} from 'tangram://webui-test/test_util.js';

suite('HistoryClustersAppTest', () => {
  let app: HistoryClustersAppElement;

  setup(async () => {
    document.body.innerHTML = window.trustedTypes!.emptyHTML;

    app = document.createElement('history-clusters-app');
    document.body.appendChild(app);
    await microtasksFinished();
  });

  test('SwitchesSearchIcon', async () => {
    assertEquals('', app.$.searchbox.iconOverride);

    // Enable history embeddings and verify icon has switched.
    loadTimeData.overrideValues({enableHistoryEmbeddings: true});
    document.body.innerHTML = window.trustedTypes!.emptyHTML;
    app = document.createElement('history-clusters-app');
    document.body.appendChild(app);
    await microtasksFinished();
    assertEquals('history-embeddings:search', app.$.searchbox.iconOverride);
  });
});