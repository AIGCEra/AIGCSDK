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

namespace Universe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TangramNewChildForm
	/// </summary>
	public ref class NewChildForm : public System::Windows::Forms::Form
	{
	public:
		NewChildForm(void)
		{
			m_pParent = nullptr;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		System::Windows::Forms::ListView^ GetListView()
		{
			return NewTemplateListView;
		}
		Form^ m_pParent;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewChildForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ NewTemplateListView;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->NewTemplateListView = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// NewTemplateListView
			// 
			this->NewTemplateListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->NewTemplateListView->HideSelection = false;
			this->NewTemplateListView->Location = System::Drawing::Point(39, 52);
			this->NewTemplateListView->MultiSelect = false;
			this->NewTemplateListView->Name = L"NewTemplateListView";
			this->NewTemplateListView->Size = System::Drawing::Size(1085, 706);
			this->NewTemplateListView->TabIndex = 0;
			this->NewTemplateListView->UseCompatibleStateImageBehavior = false;
			this->NewTemplateListView->DoubleClick += gcnew System::EventHandler(this, &NewChildForm::NewTemplateListView_DoubleClick);
			// 
			// TangramNewChildForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1162, 843);
			this->Controls->Add(this->NewTemplateListView);
			this->Name = L"NewChildForm";
			this->ShowInTaskbar = false;
			this->Text = L"NewChildForm";
			this->TopMost = true;
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void NewTemplateListView_DoubleClick(System::Object^ sender, System::EventArgs^ e);
	};
}
