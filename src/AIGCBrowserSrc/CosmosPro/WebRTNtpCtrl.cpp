#include "stdafx.h"
#include "cosmos.h"
#include "WebRTNtpCtrl.h"

using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Reflection;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Threading;
using namespace System::Threading::Tasks;

using System::Runtime::InteropServices::Marshal;

namespace Universe
{
	System::Void WebRTNtpCtrl::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		// Specify that the link was visited.
		this->linkLabel1->LinkVisited = true;

		// Navigate to a URL.
		Universe::WebRT::CreateBrowser(IntPtr::Zero, L"https://github.com/AIGCEra");
	}
}