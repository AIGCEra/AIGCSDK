/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web pages,
 *    which are composed of standard DOM elements and binary components supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet based
 *    on modern javscript/Web technology.
// Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 *******************************************************************************/

#pragma once

public enum class Disposition
{
	UNKNOWN = 0x00000000,
	CURRENT_TAB = 0x00000001,
	// Indicates that only one tab with the url should exist in the same window.
	SINGLETON_TAB = 0x00000002,
	NEW_FOREGROUND_TAB = 0x00000003,
	NEW_BACKGROUND_TAB = 0x00000004,
	NEW_POPUP = 0x00000005,
	NEW_WINDOW = 0x00000006,
	SAVE_TO_DISK = 0x00000007,
	OFF_THE_RECORD = 0x00000008,
	IGNORE_ACTION = 0x00000009,
	// Activates an existing tab containing the url, rather than navigating.
	// This is similar to SINGLETON_TAB, but searches across all windows from
	// the current profile and anonymity (instead of just the current one);
	// closes the current tab on switching if the current tab was the NTP with
	// no session history; and behaves like CURRENT_TAB instead of
	// NEW_FOREGROUND_TAB when no existing tab is found.
	SWITCH_TO_TAB = 0x0000000a
	// Update when adding a new disposition.
};