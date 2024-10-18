// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// These test suites test the local-certs-section-v2 component.

import 'tangram://resources/cr_components/certificate_manager/local_certs_section_v2.js';
import 'tangram://certificate-manager/strings.m.js';

import {PluralStringProxyImpl} from '//resources/js/plural_string_proxy.js';
import type {CertManagementMetadata} from 'tangram://resources/cr_components/certificate_manager/certificate_manager_v2.mojom-webui.js';
import {CertificatesV2BrowserProxy} from 'tangram://resources/cr_components/certificate_manager/certificates_v2_browser_proxy.js';
import type {LocalCertsSectionV2Element} from 'tangram://resources/cr_components/certificate_manager/local_certs_section_v2.js';
import {assertEquals, assertFalse, assertNull, assertTrue} from 'tangram://webui-test/chai_assert.js';
import {TestPluralStringProxy} from 'tangram://webui-test/test_plural_string_proxy.js';
import {isVisible, microtasksFinished} from 'tangram://webui-test/test_util.js';

import {TestCertificateManagerProxy} from './certificate_manager_v2_test_support.js';

class CertManagerTestPluralStringProxy extends TestPluralStringProxy {
  override text: string = '';

  override getPluralString(messageName: string, itemCount: number) {
    if (messageName === 'certificateManagerV2NumCerts') {
      this.methodCalled('getPluralString', {messageName, itemCount});
    }
    return Promise.resolve(this.text);
  }
}

suite('LocalCertsSectionV2Test', () => {
  let localCertsSection: LocalCertsSectionV2Element;
  let testProxy: TestCertificateManagerProxy;

  setup(async () => {
    document.body.innerHTML = window.trustedTypes!.emptyHTML;
    testProxy = new TestCertificateManagerProxy();
    CertificatesV2BrowserProxy.setInstance(testProxy);
  });

  function initializeElement() {
    localCertsSection = document.createElement('local-certs-section-v2');
    document.body.appendChild(localCertsSection);
  }

  test('Policy - OS certs number string', async () => {
    const pluralStringProxy = new CertManagerTestPluralStringProxy();
    PluralStringProxyImpl.setInstance(pluralStringProxy);
    pluralStringProxy.text = '5 certificates';
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: true,
      numUserAddedSystemCerts: 5,
      isIncludeSystemTrustStoreManaged: true,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await pluralStringProxy.whenCalled('getPluralString');
    await microtasksFinished();

    assertEquals(
        '5 certificates', localCertsSection.$.numSystemCerts.innerText,
        'num system certs string incorrect');
    assertTrue(isVisible(localCertsSection.$.numSystemCerts));
  });

  test('Policy - OS certs imported and managed', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: true,
      numUserAddedSystemCerts: 4,
      isIncludeSystemTrustStoreManaged: true,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();

    assertTrue(
        localCertsSection.$.importOsCerts.checked, 'os toggle state wrong');
    assertTrue(
        isVisible(localCertsSection.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertTrue(
        isVisible(localCertsSection.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertTrue(
        isVisible(localCertsSection.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
  });

  test('Policy - OS certs imported but not managed', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: true,
      numUserAddedSystemCerts: 4,
      isIncludeSystemTrustStoreManaged: false,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();

    assertTrue(
        localCertsSection.$.importOsCerts.checked,
        'os import toggle state wrong');
    assertFalse(
        isVisible(localCertsSection.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertTrue(
        isVisible(localCertsSection.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertTrue(
        isVisible(localCertsSection.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
  });

  test('Policy - OS certs not imported but managed', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: false,
      numUserAddedSystemCerts: 4,
      isIncludeSystemTrustStoreManaged: true,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();

    assertFalse(
        localCertsSection.$.importOsCerts.checked,
        'os import toggle state wrong');
    assertTrue(isVisible(localCertsSection.$.numSystemCerts));
    assertTrue(
        isVisible(localCertsSection.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertTrue(
        isVisible(localCertsSection.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertFalse(
        isVisible(localCertsSection.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
  });

  test('Policy - OS certs not imported and not managed', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: false,
      numUserAddedSystemCerts: 3,
      isIncludeSystemTrustStoreManaged: false,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();

    assertFalse(
        localCertsSection.$.importOsCerts.checked,
        'os import toggle state wrong');
    assertTrue(isVisible(localCertsSection.$.numSystemCerts));
    assertFalse(
        isVisible(localCertsSection.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertTrue(
        isVisible(localCertsSection.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertFalse(
        isVisible(localCertsSection.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
  });

  test('view OS certs not visible when 0 certs', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: false,
      numUserAddedSystemCerts: 0,
      isIncludeSystemTrustStoreManaged: false,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();

    assertFalse(
        isVisible(localCertsSection.$.viewOsImportedCerts),
        'view imported os certs should not be visible w/ 0 certs');
  });

  // <if expr="is_win or is_macosx">
  test('Open native certificate management', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: true,
      numUserAddedSystemCerts: 0,
      isIncludeSystemTrustStoreManaged: true,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();
    assertTrue(
        isVisible(localCertsSection.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    localCertsSection.$.manageOsImportedCerts.click();
    await testProxy.handler.whenCalled('showNativeManageCertificates');
  });
  // </if>

  test('no admin certs, hide custom section', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: true,
      numUserAddedSystemCerts: 0,
      isIncludeSystemTrustStoreManaged: true,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();
    const customSection =
        localCertsSection.shadowRoot!.querySelector('#customCertsSection');
    assertNull(customSection, 'custom certs section not hidden');
  });

  test('have admin certs, show custom section', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: true,
      numUserAddedSystemCerts: 0,
      isIncludeSystemTrustStoreManaged: true,
      numPolicyCerts: 5,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();
    const customSection =
        localCertsSection.shadowRoot!.querySelector('#customCertsSection');
    const linkRow = customSection!.querySelector('cr-link-row');
    assertEquals('5 certificates', linkRow!.subLabel);
  });
});