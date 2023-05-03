// Copyright 2021 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_APP_CHROME_EXE_MAIN_WIN_H_
#define CHROME_APP_CHROME_EXE_MAIN_WIN_H_

#include <stdint.h>

int InitAppStatic(bool bSupportCrashReporting);
int IsBrowserModelStatic(bool bSupportCrashReporting);

#endif  // CHROME_APP_CHROME_EXE_MAIN_WIN_H_
