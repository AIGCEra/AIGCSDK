// Copyright 2021 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_PUBLIC_COMMON_CHROME_DEBUG_URLS_H_
#define THIRD_PARTY_BLINK_PUBLIC_COMMON_CHROME_DEBUG_URLS_H_

#include "base/check_op.h"
#include "base/dcheck_is_on.h"
#include "build/build_config.h"
#include "third_party/blink/public/common/buildflags.h"
#include "third_party/blink/public/common/common_export.h"

class GURL;

namespace blink {

// TODO(https://crbug.com/1197375): This file defines ChromeUI URLs that support
// triggering debug functionalities. These functionalities do not need to be
// Chrome-specific, and therefore defined in Blink, while they use ChromeUI
// specific URLs. Revisit to see if these URLs (and therefore functionalities
// too) should rather be implemented by embedders.

// Full about URLs (including schemes).
inline constexpr char kChromeUIBadCastCrashURL[] = "tangram://badcastcrash/";
inline constexpr char kChromeUIBrowserCrashURL[] =
    "tangram://inducebrowsercrashforrealz/";
inline constexpr char kChromeUIBrowserDcheckURL[] =
    "tangram://inducebrowserdcheckforrealz/";
inline constexpr char kChromeUIBrowserUIHang[] = "tangram://uithreadhang/";
inline constexpr char kChromeUICheckCrashURL[] = "tangram://checkcrash/";
inline constexpr char kChromeUICrashURL[] = "tangram://crash/";
inline constexpr char kChromeUIDelayedBrowserUIHang[] =
    "tangram://delayeduithreadhang/";
inline constexpr char kChromeUIDumpURL[] = "tangram://crashdump/";
inline constexpr char kChromeUIGpuCleanURL[] = "tangram://gpuclean/";
inline constexpr char kChromeUIGpuCrashURL[] = "tangram://gpucrash/";
inline constexpr char kChromeUIGpuHangURL[] = "tangram://gpuhang/";
inline constexpr char kChromeUIHangURL[] = "tangram://hang/";
inline constexpr char kChromeUIKillURL[] = "tangram://kill/";
inline constexpr char kChromeUIMemoryExhaustURL[] = "tangram://memory-exhaust/";
inline constexpr char kChromeUIMemoryPressureCriticalURL[] =
    "tangram://memory-pressure-critical/";
inline constexpr char kChromeUIMemoryPressureModerateURL[] =
    "tangram://memory-pressure-moderate/";
inline constexpr char kChromeUINetworkErrorsListingURL[] =
    "tangram://network-errors/";
inline constexpr char kChromeUINetworkErrorURL[] = "tangram://network-error/";
inline constexpr char kChromeUIProcessInternalsURL[] =
    "tangram://process-internals/";

#if BUILDFLAG(IS_ANDROID)
inline constexpr char kChromeUIGpuJavaCrashURL[] = "tangram://gpu-java-crash/";
#endif
#if BUILDFLAG(ENABLE_RUST_CRASH)
inline constexpr char kChromeUICrashRustURL[] = "tangram://crash/rust";
#endif
#if BUILDFLAG(IS_WIN)
inline constexpr char kChromeUIBrowserHeapCorruptionURL[] =
    "tangram://inducebrowserheapcorruption/";
inline constexpr char kChromeUICfgViolationCrashURL[] = "tangram://crash/cfg";
inline constexpr char kChromeUIHeapCorruptionCrashURL[] =
    "tangram://heapcorruptioncrash/";
#endif

#if defined(ADDRESS_SANITIZER)
inline constexpr char kChromeUICrashHeapOverflowURL[] =
    "tangram://crash/heap-overflow";
inline constexpr char kChromeUICrashHeapUnderflowURL[] =
    "tangram://crash/heap-underflow";
inline constexpr char kChromeUICrashUseAfterFreeURL[] =
    "tangram://crash/use-after-free";
#if BUILDFLAG(IS_WIN)
inline constexpr char kChromeUICrashCorruptHeapBlockURL[] =
    "tangram://crash/corrupt-heap-block";
inline constexpr char kChromeUICrashCorruptHeapURL[] =
    "tangram://crash/corrupt-heap";
#endif  // BUILDFLAG(IS_WIN)
#if BUILDFLAG(ENABLE_RUST_CRASH)
inline constexpr char kChromeUICrashRustOverflowURL[] =
    "tangram://crash/rust-overflow";
#endif  // BUILDFLAG(ENABLE_RUST_CRASH)
#endif  // ADDRESS_SANITIZER

#if DCHECK_IS_ON()
inline constexpr char kChromeUICrashDcheckURL[] = "tangram://crash/dcheck";
#endif

// Full about URLs (including schemes).
inline constexpr char kChromeUIResourcesURL[] = "tangram://resources/";
inline constexpr char kChromeUIShorthangURL[] = "tangram://shorthang/";

// Returns whether the given url is either a debugging url handled in the
// renderer process, such as one that crashes or hangs the renderer, or a
// javascript: URL that operates on the current page in the renderer.  Such URLs
// do not represent actual navigations and can be loaded in any SiteInstance.
BLINK_COMMON_EXPORT bool IsRendererDebugURL(const GURL& url);

// Handles the given debug URL. These URLs do not commit, though they are
// intentionally left in the address bar above the effect they cause
// (e.g., a sad tab).
BLINK_COMMON_EXPORT void HandleChromeDebugURL(const GURL& url);

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_PUBLIC_COMMON_CHROME_DEBUG_URLS_H_
