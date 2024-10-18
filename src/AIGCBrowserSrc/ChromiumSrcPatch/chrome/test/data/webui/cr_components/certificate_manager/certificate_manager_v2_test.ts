// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// These test suites test the certificate-manager v2 component.

import 'tangram://resources/cr_components/certificate_manager/certificate_manager_v2.js';
import 'tangram://certificate-manager/strings.m.js';

import {PluralStringProxyImpl} from '//resources/js/plural_string_proxy.js';
import type {CertificateManagerV2Element} from 'tangram://resources/cr_components/certificate_manager/certificate_manager_v2.js';
import type {CertManagementMetadata} from 'tangram://resources/cr_components/certificate_manager/certificate_manager_v2.mojom-webui.js';
import type {CertificatePasswordDialogElement} from 'tangram://resources/cr_components/certificate_manager/certificate_password_dialog.js';
import {CertificatesV2BrowserProxy} from 'tangram://resources/cr_components/certificate_manager/certificates_v2_browser_proxy.js';
import {assertDeepEquals, assertEquals, assertFalse, assertNull, assertTrue} from 'tangram://webui-test/chai_assert.js';
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

suite('CertificateManagerV2Test', () => {
  let certManager: CertificateManagerV2Element;
  let testProxy: TestCertificateManagerProxy;

  setup(async () => {
    document.body.innerHTML = window.trustedTypes!.emptyHTML;
    testProxy = new TestCertificateManagerProxy();
    CertificatesV2BrowserProxy.setInstance(testProxy);
  });

  function initializeElement() {
    certManager = document.createElement('certificate-manager-v2');
    document.body.appendChild(certManager);
  }

  // <if expr="not (is_win or is_macosx or is_linux)">
  test('provisioned client certs not present', async () => {
    initializeElement();
    await microtasksFinished();

    const parentElement =
        certManager.shadowRoot!.querySelector('#provisionedClientCerts');
    // The provisioned client certs section should not be present on other OSes.
    assertFalse(
        !!parentElement,
        'provisionedClientCerts element was unexpectedly found');
  });
  // </if>

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
        '5 certificates', certManager.$.numSystemCerts.innerText,
        'num system certs string incorrect');
    assertTrue(isVisible(certManager.$.numSystemCerts));
  });

  test('Policy - OS certs imported and managed', async () => {
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

    assertTrue(certManager.$.importOsCerts.checked, 'os toggle state wrong');
    assertTrue(
        isVisible(certManager.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertTrue(
        isVisible(certManager.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertTrue(
        isVisible(certManager.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
  });

  test('Policy - OS certs imported but not managed', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: true,
      numUserAddedSystemCerts: 0,
      isIncludeSystemTrustStoreManaged: false,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();

    assertTrue(
        certManager.$.importOsCerts.checked, 'os import toggle state wrong');
    assertFalse(
        isVisible(certManager.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertTrue(
        isVisible(certManager.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertTrue(
        isVisible(certManager.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
  });

  test('Policy - OS certs not imported but managed', async () => {
    const metadata: CertManagementMetadata = {
      includeSystemTrustStore: false,
      numUserAddedSystemCerts: 0,
      isIncludeSystemTrustStoreManaged: true,
      numPolicyCerts: 0,
    };
    testProxy.handler.setCertManagementMetadata(metadata);
    initializeElement();

    await testProxy.handler.whenCalled('getCertManagementMetadata');
    await microtasksFinished();

    assertFalse(
        certManager.$.importOsCerts.checked, 'os import toggle state wrong');
    assertFalse(isVisible(certManager.$.numSystemCerts));
    assertTrue(
        isVisible(certManager.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertFalse(
        isVisible(certManager.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertFalse(
        isVisible(certManager.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
  });

  test('Policy - OS certs not imported and not managed', async () => {
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
        certManager.$.importOsCerts.checked, 'os import toggle state wrong');
    assertFalse(isVisible(certManager.$.numSystemCerts));
    assertFalse(
        isVisible(certManager.$.importOsCertsManagedIcon),
        'enterprise managed icon visibility wrong');
    assertFalse(
        isVisible(certManager.$.viewOsImportedCerts),
        'view imported os certs link visibility wrong');
    // <if expr="is_win or is_macosx">
    assertFalse(
        isVisible(certManager.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    // </if>
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
    certManager.$.localMenuItem.click();
    await microtasksFinished();
    assertTrue(
        isVisible(certManager.$.manageOsImportedCerts),
        'imported os certs external link visibility wrong');
    certManager.$.manageOsImportedCerts.click();
    await testProxy.handler.whenCalled('showNativeManageCertificates');
  });

  test('Open native client certificate management', async () => {
    initializeElement();
    certManager.$.clientMenuItem.click();

    await microtasksFinished();
    assertTrue(
        isVisible(certManager.$.manageOsImportedClientCerts),
        'imported os certs external link visibility wrong');
    certManager.$.manageOsImportedClientCerts.click();
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
        certManager.shadowRoot!.querySelector('#customCertsSection');
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
        certManager.shadowRoot!.querySelector('#customCertsSection');
    const linkRow = customSection!.querySelector('cr-link-row');
    assertEquals('5 certificates', linkRow!.subLabel);
  });

  test('show admin certs', async () => {
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
        certManager.shadowRoot!.querySelector('#customCertsSection');
    const linkRow = customSection!.querySelector('cr-link-row');
    linkRow!.click();
    await microtasksFinished();
    assertTrue(certManager.$.adminCertsSection.classList.contains('selected'));
  });

  test('navigate back from admin certs', async () => {
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
        certManager.shadowRoot!.querySelector('#customCertsSection');
    const linkRow = customSection!.querySelector('cr-link-row');
    linkRow!.click();
    await microtasksFinished();
    assertTrue(certManager.$.adminCertsSection.classList.contains('selected'));
    certManager.$.adminCertsSection.$.backButton.click();
    await microtasksFinished();
    assertFalse(certManager.$.adminCertsSection.classList.contains('selected'));
    assertTrue(certManager.$.localCertSection.classList.contains('selected'));
  });

  test('show platform certs', async () => {
    initializeElement();
    await microtasksFinished();
    assertFalse(
        certManager.$.platformCertsSection.classList.contains('selected'));
    certManager.$.viewOsImportedCerts.click();
    await microtasksFinished();
    assertTrue(
        certManager.$.platformCertsSection.classList.contains('selected'));
  });

  test('navigate back from platform certs', async () => {
    initializeElement();
    await microtasksFinished();
    certManager.$.viewOsImportedCerts.click();
    await microtasksFinished();
    assertTrue(
        certManager.$.platformCertsSection.classList.contains('selected'));
    certManager.$.platformCertsSection.$.backButton.click();
    await microtasksFinished();
    assertFalse(
        certManager.$.platformCertsSection.classList.contains('selected'));
    assertTrue(certManager.$.localCertSection.classList.contains('selected'));
  });

  test('show platform client certs then navigate back', async () => {
    initializeElement();
    // Go to client section.
    certManager.$.clientMenuItem.click();
    await microtasksFinished();
    assertTrue(certManager.$.clientCertSection.classList.contains('selected'));
    assertFalse(certManager.$.platformClientCertsSection.classList.contains(
        'selected'));

    // Click into client platform certs section.
    certManager.$.viewOsImportedClientCerts.click();
    await microtasksFinished();
    assertTrue(
        certManager.$.platformClientCertsSection.classList.contains('selected'),
        'not visible after click');

    // Go back to client certs.
    certManager.$.platformClientCertsSection.$.backButton.click();
    await microtasksFinished();
    assertFalse(
        certManager.$.platformClientCertsSection.classList.contains('selected'),
        'visible after click');
    assertTrue(
        certManager.$.clientCertSection.classList.contains('selected'),
        'main pane not visible');
  });

  test('click local certs section', async () => {
    initializeElement();
    certManager.$.localMenuItem.click();
    await microtasksFinished();
    assertTrue(certManager.$.localCertSection.classList.contains('selected'));
  });

  test('click client certs section', async () => {
    initializeElement();
    certManager.$.clientMenuItem.click();
    await microtasksFinished();
    assertTrue(certManager.$.clientCertSection.classList.contains('selected'));
  });

  test('click crs certs section', async () => {
    initializeElement();
    certManager.$.crsMenuItem.click();
    await microtasksFinished();
    assertTrue(certManager.$.crsCertSection.classList.contains('selected'));
  });

  // Tests opening the password dialog through the mojo interface and
  // retrieving the result of the mojo call, as well as testing that the dialog
  // is added and removed from the DOM as necessary.
  test('askForImportPassword ok', async () => {
    initializeElement();
    await microtasksFinished();

    const doTest = async (expectedPassword: string) => {
      // The password dialog should not be present in the DOM initially.
      assertNull(certManager.shadowRoot!.querySelector('#passwordDialog'));

      const promise = testProxy.callbackRouterRemote.askForImportPassword();
      await microtasksFinished();

      const passwordDialog =
          certManager.shadowRoot!
              .querySelector<CertificatePasswordDialogElement>(
                  '#passwordDialog');
      assertTrue(!!passwordDialog);
      assertTrue(passwordDialog.$.dialog.open);
      assertEquals('', passwordDialog.$.password.value);
      passwordDialog.$.password.value = expectedPassword;
      passwordDialog.$.ok.click();

      assertDeepEquals({password: expectedPassword}, await promise);
    };

    await doTest('something secret');

    // Try showing the dialog again - the dialog should work multiple times,
    // and the password field should be cleared (not still containing the value
    // previously entered).
    await doTest('something different');

    // The password dialog should no longer be present in the DOM.
    assertNull(certManager.shadowRoot!.querySelector('#passwordDialog'));
  });

  // Tests that cancelling the password dialog is signalled through the mojo
  // interface by returning a null result.
  test('askForImportPassword cancel', async () => {
    initializeElement();
    await microtasksFinished();

    // The password dialog should not be present in the DOM initially.
    assertNull(certManager.shadowRoot!.querySelector('#passwordDialog'));

    {
      const promise = testProxy.callbackRouterRemote.askForImportPassword();
      await microtasksFinished();

      const passwordDialog =
          certManager.shadowRoot!
              .querySelector<CertificatePasswordDialogElement>(
                  '#passwordDialog');
      assertTrue(!!passwordDialog);
      assertTrue(passwordDialog.$.dialog.open);
      assertEquals('', passwordDialog.$.password.value);
      passwordDialog.$.password.value = 'something secret';
      passwordDialog.$.cancel.click();

      assertDeepEquals({password: null}, await promise);
    }

    // The password dialog should no longer be present in the DOM.
    assertNull(certManager.shadowRoot!.querySelector('#passwordDialog'));

    // Try showing the dialog again - the dialog should work multiple times,
    // and the password field should be cleared (not still containing the value
    // previously entered).
    {
      const promise = testProxy.callbackRouterRemote.askForImportPassword();
      await microtasksFinished();

      const passwordDialog =
          certManager.shadowRoot!
              .querySelector<CertificatePasswordDialogElement>(
                  '#passwordDialog');
      assertTrue(!!passwordDialog);
      assertTrue(passwordDialog.$.dialog.open);
      assertEquals('', passwordDialog.$.password.value);
      passwordDialog.$.password.value = 'something different';
      passwordDialog.$.ok.click();

      assertDeepEquals({password: 'something different'}, await promise);
    }

    // The password dialog should no longer be present in the DOM.
    assertNull(certManager.shadowRoot!.querySelector('#passwordDialog'));
  });
});
