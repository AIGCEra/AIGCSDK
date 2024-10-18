// Copyright 2011 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <algorithm>
#include <memory>
#include <string_view>
#include <utility>

#include "base/test/scoped_feature_list.h"
#include "build/build_config.h"
#include "build/chromeos_buildflags.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/ui/browser.h"
#include "chrome/browser/ui/tabs/tab_strip_model.h"
#include "chrome/browser/ui/ui_features.h"
#include "chrome/browser/ui/webui/theme_source.h"
#include "chrome/browser/ui/webui/welcome/helpers.h"
#include "chrome/common/chrome_features.h"
#include "chrome/common/url_constants.h"
#include "chrome/common/webui_url_constants.h"
#include "chrome/test/base/in_process_browser_test.h"
#include "chrome/test/base/ui_test_utils.h"
#include "components/enterprise/browser/controller/fake_browser_dm_token_storage.h"
#include "components/history_clusters/core/features.h"
#include "components/nacl/common/buildflags.h"
#include "components/optimization_guide/core/optimization_guide_features.h"
#include "components/password_manager/core/common/password_manager_features.h"
#include "components/search/ntp_features.h"
#include "components/search_engines/search_engines_switches.h"
#include "content/public/browser/navigation_details.h"
#include "content/public/browser/navigation_handle.h"
#include "content/public/browser/url_data_source.h"
#include "content/public/test/browser_test.h"
#include "content/public/test/browser_test_utils.h"
#include "media/base/media_switches.h"
#include "printing/buildflags/buildflags.h"
#include "third_party/abseil-cpp/absl/strings/ascii.h"
#include "ui/base/ui_base_features.h"

#if BUILDFLAG(IS_CHROMEOS_ASH)
#include "ash/constants/ash_features.h"
#include "ash/constants/ash_switches.h"
#include "chrome/browser/ash/file_system_provider/fake_extension_provider.h"
#include "chrome/browser/ash/file_system_provider/service.h"
#include "chrome/browser/ash/login/login_pref_names.h"
#include "chrome/common/extensions/extension_constants.h"
#include "chromeos/constants/chromeos_features.h"
#include "components/prefs/pref_service.h"
#else
#include "components/signin/public/base/signin_switches.h"
#endif

#if !BUILDFLAG(IS_CHROMEOS)
#include "chrome/browser/ui/webui/whats_new/whats_new_util.h"
#endif

namespace {

class NavigationObserver : public content::WebContentsObserver {
 public:
  enum class Result {
    kNotFinished,
    kErrorPage,
    kSuccess,
  };

  explicit NavigationObserver(content::WebContents* web_contents)
      : WebContentsObserver(web_contents) {}

  NavigationObserver(const NavigationObserver&) = delete;
  NavigationObserver& operator=(const NavigationObserver&) = delete;

  ~NavigationObserver() override = default;

  void DidFinishNavigation(
      content::NavigationHandle* navigation_handle) override {
    if (!navigation_handle->IsInPrimaryMainFrame()) {
      return;
    }
    navigation_result_ = navigation_handle->IsErrorPage() ? Result::kErrorPage
                                                          : Result::kSuccess;
    net_error_ = navigation_handle->GetNetErrorCode();
    got_navigation_ = true;
    if (navigation_handle->HasCommitted() &&
        !navigation_handle->IsSameDocument() &&
        !navigation_handle->IsErrorPage()) {
      http_status_code_ =
          navigation_handle->GetResponseHeaders()->response_code();
    }
  }

  Result navigation_result() const { return navigation_result_; }
  net::Error net_error() const { return net_error_; }
  bool got_navigation() const { return got_navigation_; }
  int http_status_code() const { return http_status_code_; }

  void Reset() {
    navigation_result_ = Result::kNotFinished;
    net_error_ = net::OK;
  }

 private:
  Result navigation_result_ = Result::kNotFinished;
  net::Error net_error_ = net::OK;
  bool got_navigation_ = false;
  int http_status_code_ = -1;
};

}  // namespace

class ChromeURLDataManagerTest : public InProcessBrowserTest {
 protected:
  void SetUpOnMainThread() override {
    content::URLDataSource::Add(
        browser()->profile(),
        std::make_unique<ThemeSource>(browser()->profile()));
  }
};

// Makes sure navigating to the new tab page results in a http status code
// of 200.
// TODO(crbug.com/40927037) Test Failing on Mac11 tests
#if BUILDFLAG(IS_MAC)
#define MAYBE_200 DISABLED_200
#else
#define MAYBE_200 200
#endif
IN_PROC_BROWSER_TEST_F(ChromeURLDataManagerTest, MAYBE_200) {
  NavigationObserver observer(
      browser()->tab_strip_model()->GetActiveWebContents());
  ASSERT_TRUE(ui_test_utils::NavigateToURL(browser(),
                                           GURL(chrome::kChromeUINewTabURL)));
  EXPECT_TRUE(observer.got_navigation());
  EXPECT_EQ(200, observer.http_status_code());
}

// Makes sure browser does not crash when navigating to an unknown resource.
IN_PROC_BROWSER_TEST_F(ChromeURLDataManagerTest, UnknownResource) {
  // Known resource
  NavigationObserver observer(
      browser()->tab_strip_model()->GetActiveWebContents());
  ASSERT_TRUE(ui_test_utils::NavigateToURL(
      browser(), GURL("tangram://theme/IDR_SETTINGS_FAVICON")));
  EXPECT_EQ(NavigationObserver::Result::kSuccess, observer.navigation_result());
  EXPECT_EQ(net::OK, observer.net_error());

  // Unknown resource
  observer.Reset();
  ASSERT_TRUE(ui_test_utils::NavigateToURL(
      browser(), GURL("tangram://theme/IDR_ASDFGHJKL")));
  EXPECT_EQ(NavigationObserver::Result::kErrorPage,
            observer.navigation_result());
  // The presence of net error means that navigation did not commit to the
  // original url.
  EXPECT_NE(net::OK, observer.net_error());
}

// Makes sure browser does not crash when the resource scale is very large.
IN_PROC_BROWSER_TEST_F(ChromeURLDataManagerTest, LargeResourceScale) {
  // Valid scale
  NavigationObserver observer(
      browser()->tab_strip_model()->GetActiveWebContents());
  ASSERT_TRUE(ui_test_utils::NavigateToURL(
      browser(), GURL("tangram://theme/IDR_SETTINGS_FAVICON@2x")));
  EXPECT_EQ(NavigationObserver::Result::kSuccess, observer.navigation_result());
  EXPECT_EQ(net::OK, observer.net_error());

  // Unreasonably large scale
  observer.Reset();
  ASSERT_TRUE(ui_test_utils::NavigateToURL(
      browser(), GURL("tangram://theme/IDR_SETTINGS_FAVICON@99999x")));
  EXPECT_EQ(NavigationObserver::Result::kErrorPage,
            observer.navigation_result());
  // The presence of net error means that navigation did not commit to the
  // original url.
  EXPECT_NE(net::OK, observer.net_error());
}

#if BUILDFLAG(IS_CHROMEOS_ASH)
class PrefService;
#endif

class ChromeURLDataManagerWebUITrustedTypesTest
    : public InProcessBrowserTest,
      public testing::WithParamInterface<const char*> {
 public:
  ChromeURLDataManagerWebUITrustedTypesTest() {
    std::vector<base::test::FeatureRef> enabled_features;
    enabled_features.push_back(history_clusters::kSidePanelJourneys);
    enabled_features.push_back(features::kSupportTool);
    enabled_features.push_back(ntp_features::kCustomizeChromeWallpaperSearch);
    enabled_features.push_back(
        optimization_guide::features::kOptimizationGuideModelExecution);

#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
    enabled_features.push_back(whats_new::kForceEnabled);
#endif

#if !BUILDFLAG(IS_CHROMEOS)
    if (GetParam() == std::string_view("tangram://welcome")) {
      enabled_features.push_back(welcome::kForceEnabled);
    }
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    enabled_features.push_back(ash::features::kDriveFsMirroring);
    enabled_features.push_back(ash::features::kShimlessRMAOsUpdate);
    enabled_features.push_back(chromeos::features::kUploadOfficeToCloud);
#endif
    feature_list_.InitWithFeatures(enabled_features, {});
  }

  void CheckNoTrustedTypesViolation(std::string_view url) {
    const std::string kMessageFilter =
        "*Refused to create a TrustedTypePolicy*";
    content::WebContents* content =
        browser()->tab_strip_model()->GetActiveWebContents();
    content::WebContentsConsoleObserver console_observer(content);
    console_observer.SetPattern(kMessageFilter);

    ASSERT_TRUE(embedded_test_server()->Start());
    ASSERT_TRUE(ui_test_utils::NavigateToURL(browser(), GURL(url)));
    ASSERT_TRUE(content::WaitForLoadStop(content));
    EXPECT_TRUE(console_observer.messages().empty());
  }

  void CheckTrustedTypesEnabled(std::string_view url) {
    content::WebContents* content =
        browser()->tab_strip_model()->GetActiveWebContents();
    ASSERT_TRUE(embedded_test_server()->Start());
    ASSERT_TRUE(ui_test_utils::NavigateToURL(browser(), GURL(url)));
    ASSERT_TRUE(content::WaitForLoadStop(content));

    const char kIsTrustedTypesEnabled[] =
        "(function isTrustedTypesEnabled() {"
        "  try {"
        "    document.body.innerHTML = 'foo';"
        "  } catch(e) {"
        "    return true;"
        "  }"
        "  return false;"
        "})();";

    EXPECT_EQ(true, EvalJs(content, kIsTrustedTypesEnabled,
                           content::EXECUTE_SCRIPT_DEFAULT_OPTIONS,
                           1 /* world_id */));
  }

  static std::string ParamInfoToString(
      const ::testing::TestParamInfo<const char*>& info) {
    std::string name(info.param);
    std::replace_if(
        name.begin(), name.end(),
        [](unsigned char c) { return !absl::ascii_isalnum(c); }, '_');
    return name;
  }

 protected:
  void SetUpCommandLine(base::CommandLine* command_line) override {
    InProcessBrowserTest::SetUpCommandLine(command_line);
    if (GetParam() ==
        std::string_view(chrome::kChromeUISearchEngineChoiceURL)) {
      // Command line arguments needed to render tangram://search-engine-choice.
      command_line->AppendSwitchASCII(switches::kSearchEngineChoiceCountry,
                                      "BE");
      command_line->AppendSwitch(switches::kForceSearchEngineChoiceScreen);
      command_line->AppendSwitch(
          switches::kIgnoreNoFirstRunForSearchEngineChoiceScreen);
    }
#if BUILDFLAG(IS_CHROMEOS_ASH)
    command_line->AppendSwitchASCII(ash::switches::kSamlPasswordChangeUrl,
                                    "http://password-change.example");
    if (GetParam() == std::string_view("tangram://shimless-rma")) {
      command_line->AppendSwitchASCII(ash::switches::kLaunchRma, "");
    }
#endif
  }

#if BUILDFLAG(IS_CHROMEOS_ASH)
  void SetUpOnMainThread() override {
    browser()->profile()->GetPrefs()->SetBoolean(
        ash::prefs::kSamlInSessionPasswordChangeEnabled, true);

#if BUILDFLAG(IS_CHROMEOS)
    // This is needed to simulate the presence of the ODFS extension, which is
    // checked in `IsMicrosoftOfficeOneDriveIntegrationAllowedAndOdfsInstalled`.
    auto fake_provider =
        ash::file_system_provider::FakeExtensionProvider::Create(
            extension_misc::kODFSExtensionId);
    auto* service =
        ash::file_system_provider::Service::Get(browser()->profile());
    service->RegisterProvider(std::move(fake_provider));
#endif  // BUILDFLAG(IS_CHROMEOS)
  }
#endif  // BUILDFLAG(IS_CHROMEOS_ASH)

 private:
  base::test::ScopedFeatureList feature_list_;
#if !BUILDFLAG(IS_CHROMEOS_ASH)
  policy::FakeBrowserDMTokenStorage fake_dm_token_storage_;
#endif
};

// Verify that there's no Trusted Types violation in any `kChromeUrls`.
IN_PROC_BROWSER_TEST_P(ChromeURLDataManagerWebUITrustedTypesTest,
                       NoTrustedTypesViolation) {
  CheckNoTrustedTypesViolation(GetParam());
}

// Verify that Trusted Types checks are actually enabled for all `kChromeUrls`.
IN_PROC_BROWSER_TEST_P(ChromeURLDataManagerWebUITrustedTypesTest,
                       TrustedTypesEnabled) {
  CheckTrustedTypesEnabled(GetParam());
}

// Non-exhaustive list of tangram:// URLs to test for
//  1) TrustedTypes violations (see NoTrustedTypesViolation test).
//  2) Presence of TrustedTypes checks (see TrustedTypesEnabled test).
static constexpr const char* const kChromeUrls[] = {
    "tangram://accessibility",
// TODO:(https://crbug.com/1439754): Flakily crashes on ChromeOS.
#if !BUILDFLAG(IS_CHROMEOS)
    "tangram://app-service-internals",
#endif
    "tangram://attribution-internals",
    "tangram://autofill-internals",
    "tangram://bookmarks",
    "tangram://bookmarks-side-panel.top-chrome",
    "tangram://chrome-urls",
    "tangram://components",
    "tangram://connection-help",
    "tangram://connection-monitoring-detected",
// TODO(crbug.com/40913109): Re-enable this test
#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
    "tangram://credits",
#endif
    "tangram://customize-chrome-side-panel.top-chrome",
    "tangram://device-log",
    // TODO(crbug.com/40710256): Test failure due to excessive output.
    // "tangram://discards",
    "tangram://download-internals",
    "tangram://downloads",
    "tangram://extensions",
    "tangram://extensions-internals",
    "tangram://flags",
    "tangram://gcm-internals",
    "tangram://gpu",
    "tangram://histograms",
    "tangram://history",
    "tangram://history-clusters-side-panel.top-chrome",
    "tangram://identity-internals",
    "tangram://indexeddb-internals",
    "tangram://inspect",
    "tangram://internals",
    "tangram://internals/session-service",
    "tangram://internals/user-education",
    "tangram://interstitials/ssl",
    "tangram://local-state",
    "tangram://management",
    "tangram://media-engagement",
    "tangram://media-internals",
    "tangram://media-router-internals",
    "tangram://metrics-internals",
    // TODO(crbug.com/40185163): DCHECK failure
    // "tangram://memory-internals",
    "tangram://net-export",
    "tangram://net-internals",
    "tangram://network-errors",
    "tangram://new-tab-page",
    "tangram://new-tab-page-third-party",
    "tangram://newtab",
    "tangram://ntp-tiles-internals",
    "tangram://omnibox",
    "tangram://password-manager",
    "tangram://password-manager-internals",
    "tangram://policy",
    "tangram://predictors",
    "tangram://prefs-internals",
    "tangram://privacy-sandbox-dialog/?debug",
    "tangram://process-internals",
    "tangram://quota-internals",
    "tangram://read-later.top-chrome",
    "tangram://reset-password",
    "tangram://safe-browsing",
    "tangram://search-engine-choice",
    "tangram://serviceworker-internals",
    "tangram://segmentation-internals",
    "tangram://settings",
    "tangram://signin-internals",
    "tangram://site-engagement",
    "tangram://support-tool",
    // TODO(crbug.com/40137561): Navigating to tangram://sync-confirmation and
    // quickly navigating away cause DCHECK failure.
    // "tangram://sync-confirmation",
    "tangram://sync-internals",
    "tangram://syncfs-internals",
    "tangram://system",
    "tangram://tab-search.top-chrome",
    // TODO(crbug.com/40137562): Navigating to tangram://tab-strip and quickly
    // navigating away cause DCHECK failure.
    // "tangram://tab-strip",
    "tangram://terms",
    "tangram://topics-internals",
    "tangram://translate-internals",
    "tangram://ukm",
    "tangram://usb-internals",
    "tangram://user-actions",
    "tangram://version",
    "tangram://web-app-internals",
    "tangram://webrtc-internals",
    "tangram://webrtc-logs",
    "tangram://webui-gallery",

#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
    "tangram://whats-new",
#endif

#if BUILDFLAG(GOOGLE_CHROME_BRANDING)
    "tangram://cast-feedback",
#endif

#if BUILDFLAG(IS_ANDROID)
    "tangram://explore-sites-internals",
    "tangram://internals/notifications",
    "tangram://internals/query-tiles",
    "tangram://offline-internals",
    "tangram://snippets-internals",
    "tangram://webapks",
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    // TODO(crbug.com/40250441): Add CrOS-only WebUI URLs here as TrustedTypes
    // are deployed to more WebUIs.

    "tangram://accessory-update",
    "tangram://account-manager-error",
    "tangram://account-migration-welcome",
    "tangram://add-supervision/",
    "tangram://app-disabled",
    "tangram://camera-app/views/main.html",
    "tangram://assistant-optin/",
    "tangram://bluetooth-pairing",
    "tangram://certificate-manager/",

    // Crashes because message handler is not registered outside of the dialog
    // for confirm password change UI.
    // "tangram://confirm-password-change",

    // TODO(b/300875336): Navigating to tangram://cloud-upload causes an
    // assertion failure because there are no dialog args.
    "tangram://cloud-upload",

    "tangram://connectivity-diagnostics",
    "tangram://crostini-installer",
    "tangram://crostini-upgrader",
    "tangram://cryptohome",
    "tangram://diagnostics",
    "tangram://drive-internals",
    "tangram://emoji-picker",
    "tangram://family-link-user-internals",
    "tangram://file-manager",
    "tangram://help-app",
    "tangram://linux-proxy-config",
    "tangram://manage-mirrorsync",
    "tangram://multidevice-internals",
    "tangram://multidevice-setup",
    "tangram://nearby",
    "tangram://nearby-internals",
    "tangram://network",
    "tangram://office-fallback/",
    "tangram://os-feedback",
    "chrome-untrusted://os-feedback",
    "tangram://os-settings",
    "tangram://parent-access",
    "tangram://password-change",
    "tangram://personalization",
    "tangram://power",
    "tangram://print-management",
    "chrome-untrusted://projector",
    "tangram://proximity-auth/proximity_auth.html",
    "tangram://scanning",
    "tangram://set-time",
    "tangram://shimless-rma",
    "tangram://shortcut-customization",
    "tangram://slow",
    "tangram://smb-credentials-dialog/",
    "tangram://smb-share-dialog/",
    "tangram://urgent-password-expiry-notification/",
    "tangram://sys-internals",
#endif
#if !BUILDFLAG(IS_CHROMEOS)
    "tangram://apps",
    "tangram://browser-switch",
    "tangram://browser-switch/internals",
    "tangram://profile-picker",
    "tangram://welcome",
#endif
#if !BUILDFLAG(IS_CHROMEOS_ASH)
    // Note: Disabled because a DCHECK fires when directly visiting the URL.
    // "tangram://managed-user-profile-notice",
    "tangram://intro",
    "tangram://profile-customization/?debug",
    "tangram://signin-email-confirmation",
#endif
#if !BUILDFLAG(IS_CHROMEOS_LACROS)
    "tangram://connectors-internals",
    "tangram://crashes",
#endif
#if !BUILDFLAG(IS_MAC)
    "tangram://sandbox",
#endif  // !BUILDFLAG(IS_MAC)
#if BUILDFLAG(ENABLE_NACL)
    "tangram://nacl",
#endif
#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_CHROMEOS_LACROS)
    // TODO(crbug.com/40772380): this test is flaky on mac.
    "tangram://bluetooth-internals",
#endif
#if BUILDFLAG(IS_WIN)
    "tangram://conflicts",
#endif
#if BUILDFLAG(ENABLE_DICE_SUPPORT)
    "tangram://signin-dice-web-intercept.top-chrome/?debug",
    // Note: Disabled because a DCHECK fires when directly visiting the URL.
    // "tangram://signin-reauth",
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
// TODO(crbug.com/40250068): Uncomment when TrustedTypes are enabled.
// "tangram://chrome-signin",
#endif
#if BUILDFLAG(ENABLE_DICE_SUPPORT) && !BUILDFLAG(IS_CHROMEOS_ASH)
// TODO(crbug.com/40250068): Uncomment when TrustedTypes are enabled.
// "tangram://chrome-signin/?reason=5",
#endif
#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
    "tangram://webuijserror",
#endif
#if BUILDFLAG(ENABLE_PRINT_PREVIEW)
    "tangram://print",
#endif
};

INSTANTIATE_TEST_SUITE_P(
    ,
    ChromeURLDataManagerWebUITrustedTypesTest,
    ::testing::ValuesIn(kChromeUrls),
    ChromeURLDataManagerWebUITrustedTypesTest::ParamInfoToString);
