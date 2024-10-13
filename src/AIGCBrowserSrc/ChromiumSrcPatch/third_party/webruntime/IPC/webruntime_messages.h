// Copyright 2022 TangramTeam. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WEB_RUNTIMR_MESSAGES_H_
#define WEB_RUNTIMR_MESSAGES_H_

// IPC messages for interacting with frames.

#include <stddef.h>
#include <stdint.h>

#include <map>
#include <set>
#include <string>
#include <vector>

#include "base/unguessable_token.h"
#include "build/build_config.h"
#include "content/common/buildflags.h"
#include "content/common/common_param_traits_macros.h"
#include "content/common/content_export.h"
#include "content/common/content_param_traits.h"
#include "content/public/common/common_param_traits.h"
#include "content/public/common/referrer.h"

#include "ipc/ipc_channel_handle.h"
#include "ipc/ipc_message_start.h"
#include "ipc/ipc_message_macros.h"

using FrameMsg_TANGRAM_HOST_String_Map = std::map<std::wstring, std::wstring>;

using FrameMsg_TANGRAM_HOST_LONG_Map = std::map<std::wstring, long>;

using FrameMsg_TANGRAM_HOST_INT64_Map = std::map<std::wstring, __int64>;

using FrameMsg_TANGRAM_HOST_FLOAT_Map = std::map<std::wstring, float>;

#undef IPC_MESSAGE_EXPORT
#define IPC_MESSAGE_EXPORT CONTENT_EXPORT

#define IPC_MESSAGE_START FrameMsgStart

// begin Add by TangramTeam 20220113
IPC_MESSAGE_ROUTED4(TangramRendererIPCMsg,
                    FrameMsg_TANGRAM_HOST_String_Map /* string map */,
                    FrameMsg_TANGRAM_HOST_LONG_Map /* long map*/,
                    FrameMsg_TANGRAM_HOST_INT64_Map /* int64 map*/,
                    FrameMsg_TANGRAM_HOST_FLOAT_Map /* param3 */)

IPC_MESSAGE_ROUTED6(TangramFrameHostMsg_Message,
                    std::wstring /* id */,
                    std::wstring /* param1 */,
                    std::wstring /* param2 */,
                    std::wstring /* param3 */,
                    std::wstring /* param4 */,
                    std::wstring /* param5 */)
IPC_MESSAGE_ROUTED6(TangramFrameHostMsg_Message2,
                    std::wstring /* id */,
                    std::wstring /* param1 */,
                    __int64 /* param2 */,
                    __int64 /* param3 */,
                    std::wstring /* param4 */,
                    std::wstring /* param5 */)
IPC_MESSAGE_ROUTED4(TangramHostIPCMsg,
                    FrameMsg_TANGRAM_HOST_String_Map /* string map */,
                    FrameMsg_TANGRAM_HOST_LONG_Map /* long map*/,
                    FrameMsg_TANGRAM_HOST_INT64_Map /* int64 map*/,
                    FrameMsg_TANGRAM_HOST_FLOAT_Map /* float map */)
// end Add by TangramTeam 20220113

// Adding a new message? Stick to the sort order above: first platform
// independent FrameMsg, then ifdefs for platform specific FrameMsg, then
// platform independent FrameHostMsg, then ifdefs for platform specific
// FrameHostMsg.

#endif  // WEB_RUNTIMR_MESSAGES_H_
