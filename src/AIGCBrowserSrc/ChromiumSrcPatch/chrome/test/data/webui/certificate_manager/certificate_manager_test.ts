// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This tests loading the Certificate Manager V2 from the
// tangram://certificate-manager URL

import {assertTrue} from 'tangram://webui-test/chai_assert.js';

suite('CertificateManager', () => {
  test('element check', () => {
    const element = document.querySelector('certificate-manager-v2');
    assertTrue(!!element);
  });
});
