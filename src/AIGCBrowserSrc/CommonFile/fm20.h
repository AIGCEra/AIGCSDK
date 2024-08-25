// Created by Microsoft (R) C/C++ Compiler Version 14.00.23026.0 (9dc7507f).
//
// c:\users\sunhui2\documents\visual studio 2015\projects\atlproject2\atlproject2\debug\fm20.tlh
//
// C++ source equivalent of Win32 type library C:\WINDOWS\SysWOW64\FM20.DLL
// compiler-generated file created 11/04/15 at 11:19:46 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

//
// Forward references and typedefs
//
namespace MSForm {
	struct __declspec(uuid("0d452ee1-e08f-101a-852e-02608c4d0bb4"))
		/* LIBID */ __MSForms;
	struct __declspec(uuid("bef6e003-a874-101a-8bba-00aa00300cab"))
		/* dispinterface */ Font;
	enum fmDropEffect;
	enum fmAction;
	struct __declspec(uuid("ec72f590-f375-11ce-b9e8-00aa006b1a69"))
		/* dual interface */ IDataAutoWrapper;
	struct __declspec(uuid("82b02370-b5bc-11cf-810f-00a0c9030074"))
		/* dual interface */ IReturnInteger;
	struct __declspec(uuid("82b02371-b5bc-11cf-810f-00a0c9030074"))
		/* dual interface */ IReturnBoolean;
	struct __declspec(uuid("82b02372-b5bc-11cf-810f-00a0c9030074"))
		/* dual interface */ IReturnString;
	struct __declspec(uuid("8a683c90-ba84-11cf-8110-00a0c9030074"))
		/* dual interface */ IReturnSingle;
	struct __declspec(uuid("8a683c91-ba84-11cf-8110-00a0c9030074"))
		/* dual interface */ IReturnEffect;
	struct /* coclass */ ReturnInteger;
	struct /* coclass */ ReturnBoolean;
	struct /* coclass */ ReturnString;
	struct /* coclass */ ReturnSingle;
	struct /* coclass */ ReturnEffect;
	struct /* coclass */ DataObject;
	enum fmMode;
	enum fmMousePointer;
	enum fmScrollBars;
	enum fmScrollAction;
	enum fmCycle;
	enum fmZOrder;
	enum fmBorderStyle;
	enum fmTextAlign;
	enum fmAlignment;
	enum fmBorders;
	enum fmBackStyle;
	enum fmButtonStyle;
	enum fmPicPosition;
	enum fmVerticalScrollBarSide;
	enum fmLayoutEffect;
	enum fmSpecialEffect;
	enum fmDragState;
	enum fmPictureSizeMode;
	enum fmPictureAlignment;
	struct __declspec(uuid("04598fc6-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ IControl;
	struct __declspec(uuid("04598fc7-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ Controls;
	struct __declspec(uuid("29b86a70-f52e-11ce-9bce-00aa00608e01"))
		/* dual interface */ IOptionFrame;
	struct __declspec(uuid("04598fc8-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ _UserForm;
	struct __declspec(uuid("9a4bbf53-4e46-101b-8bbd-00aa003e3b29"))
		/* dispinterface */ ControlEvents;
	struct /* coclass */ Control;
	struct __declspec(uuid("5b9d8fc8-4a71-101b-97a6-00000b65c08b"))
		/* dispinterface */ FormEvents;
	struct __declspec(uuid("cf3f94a0-f546-11ce-9bce-00aa00608e01"))
		/* dispinterface */ OptionFrameEvents;
	struct /* coclass */ UserForm;
	struct /* coclass */ Frame;
	enum fmButtonEffect;
	enum fmOrientation;
	enum fmSnapPoint;
	enum fmPicturePosition;
	enum fmDisplayStyle;
	enum fmShowListWhen;
	enum fmShowDropButtonWhen;
	enum fmMultiSelect;
	enum fmListStyle;
	enum fmEnterFieldBehavior;
	enum fmDragBehavior;
	enum fmMatchEntry;
	enum fmDropButtonStyle;
	enum fmStyle;
	enum fmTabOrientation;
	enum fmTabStyle;
	enum fmIMEMode;
	struct __declspec(uuid("04598fc1-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ ILabelControl;
	struct __declspec(uuid("04598fc4-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ ICommandButton;
	struct __declspec(uuid("8bd21d13-ec42-11ce-9e0d-00aa006002f3"))
		/* dual interface */ IMdcText;
	struct __declspec(uuid("8bd21d23-ec42-11ce-9e0d-00aa006002f3"))
		/* dual interface */ IMdcList;
	struct __declspec(uuid("8bd21d33-ec42-11ce-9e0d-00aa006002f3"))
		/* dual interface */ IMdcCombo;
	struct __declspec(uuid("8bd21d43-ec42-11ce-9e0d-00aa006002f3"))
		/* dual interface */ IMdcCheckBox;
	struct __declspec(uuid("8bd21d53-ec42-11ce-9e0d-00aa006002f3"))
		/* dual interface */ IMdcOptionButton;
	struct __declspec(uuid("8bd21d63-ec42-11ce-9e0d-00aa006002f3"))
		/* dual interface */ IMdcToggleButton;
	struct __declspec(uuid("04598fc3-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ IScrollbar;
	struct __declspec(uuid("a38bffc3-a5a0-11ce-8107-00aa00611080"))
		/* dual interface */ Tab;
	struct __declspec(uuid("944acf93-a1e6-11ce-8104-00aa00611080"))
		/* dual interface */ Tabs;
	struct __declspec(uuid("04598fc2-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ ITabStrip;
	struct __declspec(uuid("79176fb3-b7f2-11ce-97ef-00aa006d2776"))
		/* dual interface */ ISpinbutton;
	struct __declspec(uuid("4c599243-6926-101b-9992-00000b65c6f9"))
		/* dual interface */ IImage;
	struct __declspec(uuid("5512d111-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLSubmitButton;
	struct __declspec(uuid("5512d113-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLImage;
	struct __declspec(uuid("5512d115-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLReset;
	struct __declspec(uuid("5512d117-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLCheckbox;
	struct __declspec(uuid("5512d119-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLOption;
	struct __declspec(uuid("5512d11b-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLText;
	struct __declspec(uuid("5512d11d-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLHidden;
	struct __declspec(uuid("5512d11f-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLPassword;
	struct __declspec(uuid("5512d123-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLSelect;
	struct __declspec(uuid("5512d125-5cc6-11cf-8d67-00aa00bdce1d"))
		/* dual interface */ IWHTMLTextArea;
	struct __declspec(uuid("978c9e22-d4b0-11ce-bf2d-00aa003f40d0"))
		/* dispinterface */ LabelControlEvents;
	struct /* coclass */ Label;
	struct __declspec(uuid("7b020ec1-af6c-11ce-9f46-00aa00574a4f"))
		/* dispinterface */ CommandButtonEvents;
	struct /* coclass */ CommandButton;
	struct __declspec(uuid("8bd21d12-ec42-11ce-9e0d-00aa006002f3"))
		/* dispinterface */ MdcTextEvents;
	struct /* coclass */ TextBox;
	struct __declspec(uuid("8bd21d22-ec42-11ce-9e0d-00aa006002f3"))
		/* dispinterface */ MdcListEvents;
	struct /* coclass */ ListBox;
	struct __declspec(uuid("8bd21d32-ec42-11ce-9e0d-00aa006002f3"))
		/* dispinterface */ MdcComboEvents;
	struct /* coclass */ ComboBox;
	struct __declspec(uuid("8bd21d42-ec42-11ce-9e0d-00aa006002f3"))
		/* dispinterface */ MdcCheckBoxEvents;
	struct __declspec(uuid("8bd21d52-ec42-11ce-9e0d-00aa006002f3"))
		/* dispinterface */ MdcOptionButtonEvents;
	struct __declspec(uuid("8bd21d62-ec42-11ce-9e0d-00aa006002f3"))
		/* dispinterface */ MdcToggleButtonEvents;
	struct /* coclass */ CheckBox;
	struct /* coclass */ OptionButton;
	struct /* coclass */ ToggleButton;
	struct /* coclass */ NewFont;
	struct __declspec(uuid("7b020ec2-af6c-11ce-9f46-00aa00574a4f"))
		/* dispinterface */ ScrollbarEvents;
	struct /* coclass */ ScrollBar;
	struct __declspec(uuid("7b020ec7-af6c-11ce-9f46-00aa00574a4f"))
		/* dispinterface */ TabStripEvents;
	struct /* coclass */ TabStrip;
	struct __declspec(uuid("79176fb2-b7f2-11ce-97ef-00aa006d2776"))
		/* dispinterface */ SpinbuttonEvents;
	struct /* coclass */ SpinButton;
	struct __declspec(uuid("4c5992a5-6926-101b-9992-00000b65c6f9"))
		/* dispinterface */ ImageEvents;
	struct /* coclass */ Image;
	struct __declspec(uuid("796ed650-5fe9-11cf-8d68-00aa00bdce1d"))
		/* dispinterface */ WHTMLControlEvents;
	struct __declspec(uuid("47ff8fe0-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents1;
	struct __declspec(uuid("47ff8fe1-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents2;
	struct __declspec(uuid("47ff8fe2-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents3;
	struct __declspec(uuid("47ff8fe3-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents4;
	struct __declspec(uuid("47ff8fe4-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents5;
	struct __declspec(uuid("47ff8fe5-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents6;
	struct __declspec(uuid("47ff8fe6-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents7;
	struct __declspec(uuid("47ff8fe8-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents9;
	struct __declspec(uuid("47ff8fe9-6198-11cf-8ce8-00aa006cb389"))
		/* dispinterface */ WHTMLControlEvents10;
	struct /* coclass */ HTMLSubmit;
	struct /* coclass */ HTMLImage;
	struct /* coclass */ HTMLReset;
	struct /* coclass */ HTMLCheckbox;
	struct /* coclass */ HTMLOption;
	struct /* coclass */ HTMLText;
	struct /* coclass */ HTMLHidden;
	struct /* coclass */ HTMLPassword;
	struct /* coclass */ HTMLSelect;
	struct /* coclass */ HTMLTextArea;
	enum fmTransitionEffect;
	struct __declspec(uuid("5cef5613-713d-11ce-80c9-00aa00611080"))
		/* dual interface */ IPage;
	struct __declspec(uuid("92e11a03-7358-11ce-80cb-00aa00611080"))
		/* dual interface */ Pages;
	struct __declspec(uuid("04598fc9-866c-11cf-ab7c-00aa00c08fcf"))
		/* dual interface */ IMultiPage;
	struct __declspec(uuid("7b020ec8-af6c-11ce-9f46-00aa00574a4f"))
		/* dispinterface */ MultiPageEvents;
	struct /* coclass */ MultiPage;
	struct /* coclass */ Page;
	enum fmListBoxStyles;
	enum fmRepeatDirection;
	enum fmEnAutoSize;
	struct /* coclass */ TextBox2;
	struct /* coclass */ CommandButton2;
	struct /* coclass */ Image2;
	struct /* coclass */ Label2;
	struct /* coclass */ ScrollBar2;
	struct /* coclass */ SpinButton2;
	struct /* coclass */ TabStrip2;
	struct /* coclass */ ListBox2;
	struct /* coclass */ ComboBox2;
	struct /* coclass */ CheckBox2;
	struct /* coclass */ OptionButton2;
	struct /* coclass */ ToggleButton2;
	struct /* coclass */ UserForm2;
	struct /* coclass */ Frame2;
	struct /* coclass */ DataObject2;
	struct /* coclass */ MultiPage2;
	struct /* coclass */ HTMLSubmit2;
	struct /* coclass */ HTMLImage2;
	struct /* coclass */ HTMLReset2;
	struct /* coclass */ HTMLCheckbox2;
	struct /* coclass */ HTMLOption2;
	struct /* coclass */ HTMLText2;
	struct /* coclass */ HTMLHidden2;
	struct /* coclass */ HTMLPassword2;
	struct /* coclass */ HTMLSelect2;
	struct /* coclass */ HTMLTextArea2;
	typedef long OLE_COLOR;
	typedef long OLE_HANDLE;
	typedef VARIANT_BOOL OLE_OPTEXCLUSIVE;
	typedef IUnknown * PIROWSET;

	//
	// Smart pointer typedef declarations
	//

	_COM_SMARTPTR_TYPEDEF(Font, __uuidof(Font));
	_COM_SMARTPTR_TYPEDEF(IDataAutoWrapper, __uuidof(IDataAutoWrapper));
	_COM_SMARTPTR_TYPEDEF(IReturnInteger, __uuidof(IReturnInteger));
	_COM_SMARTPTR_TYPEDEF(IReturnBoolean, __uuidof(IReturnBoolean));
	_COM_SMARTPTR_TYPEDEF(IReturnString, __uuidof(IReturnString));
	_COM_SMARTPTR_TYPEDEF(IReturnSingle, __uuidof(IReturnSingle));
	_COM_SMARTPTR_TYPEDEF(IReturnEffect, __uuidof(IReturnEffect));
	_COM_SMARTPTR_TYPEDEF(IControl, __uuidof(IControl));
	_COM_SMARTPTR_TYPEDEF(ControlEvents, __uuidof(ControlEvents));
	_COM_SMARTPTR_TYPEDEF(Controls, __uuidof(Controls));
	_COM_SMARTPTR_TYPEDEF(IOptionFrame, __uuidof(IOptionFrame));
	_COM_SMARTPTR_TYPEDEF(_UserForm, __uuidof(_UserForm));
	_COM_SMARTPTR_TYPEDEF(FormEvents, __uuidof(FormEvents));
	_COM_SMARTPTR_TYPEDEF(OptionFrameEvents, __uuidof(OptionFrameEvents));
	_COM_SMARTPTR_TYPEDEF(ILabelControl, __uuidof(ILabelControl));
	_COM_SMARTPTR_TYPEDEF(ICommandButton, __uuidof(ICommandButton));
	_COM_SMARTPTR_TYPEDEF(IMdcText, __uuidof(IMdcText));
	_COM_SMARTPTR_TYPEDEF(IMdcList, __uuidof(IMdcList));
	_COM_SMARTPTR_TYPEDEF(IMdcCombo, __uuidof(IMdcCombo));
	_COM_SMARTPTR_TYPEDEF(IMdcCheckBox, __uuidof(IMdcCheckBox));
	_COM_SMARTPTR_TYPEDEF(IMdcOptionButton, __uuidof(IMdcOptionButton));
	_COM_SMARTPTR_TYPEDEF(IMdcToggleButton, __uuidof(IMdcToggleButton));
	_COM_SMARTPTR_TYPEDEF(IScrollbar, __uuidof(IScrollbar));
	_COM_SMARTPTR_TYPEDEF(Tab, __uuidof(Tab));
	_COM_SMARTPTR_TYPEDEF(Tabs, __uuidof(Tabs));
	_COM_SMARTPTR_TYPEDEF(ITabStrip, __uuidof(ITabStrip));
	_COM_SMARTPTR_TYPEDEF(ISpinbutton, __uuidof(ISpinbutton));
	_COM_SMARTPTR_TYPEDEF(IImage, __uuidof(IImage));
	_COM_SMARTPTR_TYPEDEF(IWHTMLSubmitButton, __uuidof(IWHTMLSubmitButton));
	_COM_SMARTPTR_TYPEDEF(IWHTMLImage, __uuidof(IWHTMLImage));
	_COM_SMARTPTR_TYPEDEF(IWHTMLReset, __uuidof(IWHTMLReset));
	_COM_SMARTPTR_TYPEDEF(IWHTMLCheckbox, __uuidof(IWHTMLCheckbox));
	_COM_SMARTPTR_TYPEDEF(IWHTMLOption, __uuidof(IWHTMLOption));
	_COM_SMARTPTR_TYPEDEF(IWHTMLText, __uuidof(IWHTMLText));
	_COM_SMARTPTR_TYPEDEF(IWHTMLHidden, __uuidof(IWHTMLHidden));
	_COM_SMARTPTR_TYPEDEF(IWHTMLPassword, __uuidof(IWHTMLPassword));
	_COM_SMARTPTR_TYPEDEF(IWHTMLSelect, __uuidof(IWHTMLSelect));
	_COM_SMARTPTR_TYPEDEF(IWHTMLTextArea, __uuidof(IWHTMLTextArea));
	_COM_SMARTPTR_TYPEDEF(LabelControlEvents, __uuidof(LabelControlEvents));
	_COM_SMARTPTR_TYPEDEF(CommandButtonEvents, __uuidof(CommandButtonEvents));
	_COM_SMARTPTR_TYPEDEF(MdcTextEvents, __uuidof(MdcTextEvents));
	_COM_SMARTPTR_TYPEDEF(MdcListEvents, __uuidof(MdcListEvents));
	_COM_SMARTPTR_TYPEDEF(MdcComboEvents, __uuidof(MdcComboEvents));
	_COM_SMARTPTR_TYPEDEF(MdcCheckBoxEvents, __uuidof(MdcCheckBoxEvents));
	_COM_SMARTPTR_TYPEDEF(MdcOptionButtonEvents, __uuidof(MdcOptionButtonEvents));
	_COM_SMARTPTR_TYPEDEF(MdcToggleButtonEvents, __uuidof(MdcToggleButtonEvents));
	_COM_SMARTPTR_TYPEDEF(ScrollbarEvents, __uuidof(ScrollbarEvents));
	_COM_SMARTPTR_TYPEDEF(TabStripEvents, __uuidof(TabStripEvents));
	_COM_SMARTPTR_TYPEDEF(SpinbuttonEvents, __uuidof(SpinbuttonEvents));
	_COM_SMARTPTR_TYPEDEF(ImageEvents, __uuidof(ImageEvents));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents, __uuidof(WHTMLControlEvents));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents1, __uuidof(WHTMLControlEvents1));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents2, __uuidof(WHTMLControlEvents2));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents3, __uuidof(WHTMLControlEvents3));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents4, __uuidof(WHTMLControlEvents4));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents5, __uuidof(WHTMLControlEvents5));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents6, __uuidof(WHTMLControlEvents6));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents7, __uuidof(WHTMLControlEvents7));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents9, __uuidof(WHTMLControlEvents9));
	_COM_SMARTPTR_TYPEDEF(WHTMLControlEvents10, __uuidof(WHTMLControlEvents10));
	_COM_SMARTPTR_TYPEDEF(IPage, __uuidof(IPage));
	_COM_SMARTPTR_TYPEDEF(MultiPageEvents, __uuidof(MultiPageEvents));
	_COM_SMARTPTR_TYPEDEF(Pages, __uuidof(Pages));
	_COM_SMARTPTR_TYPEDEF(IMultiPage, __uuidof(IMultiPage));

	//
	// Type library items
	//

	struct __declspec(uuid("bef6e003-a874-101a-8bba-00aa00300cab"))
		Font : IDispatch
	{};

	enum __declspec(uuid("10bb4720-f797-11ce-b9ec-00aa006b1a69"))
		fmDropEffect
	{
		fmDropEffectNone = 0,
		fmDropEffectCopy = 1,
		fmDropEffectMove = 2,
		fmDropEffectCopyOrMove = 3
	};

	enum __declspec(uuid("570c03e0-f797-11ce-b9ec-00aa006b1a69"))
		fmAction
	{
		fmActionCut = 0,
		fmActionCopy = 1,
		fmActionPaste = 2,
		fmActionDragDrop = 3
	};

	struct __declspec(uuid("ec72f590-f375-11ce-b9e8-00aa006b1a69"))
		IDataAutoWrapper : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall Clear() = 0;
		virtual HRESULT __stdcall GetFormat(
			/*[in]*/ VARIANT Format,
			/*[out,retval]*/ VARIANT_BOOL * Support) = 0;
		virtual HRESULT __stdcall GetText(
			/*[in]*/ VARIANT Format,
			/*[out,retval]*/ BSTR * Text) = 0;
		virtual HRESULT __stdcall SetText(
			/*[in]*/ BSTR Text,
			/*[in]*/ VARIANT Format = vtMissing) = 0;
		virtual HRESULT __stdcall PutInClipboard() = 0;
		virtual HRESULT __stdcall GetFromClipboard() = 0;
		virtual HRESULT __stdcall StartDrag(
			/*[in]*/ VARIANT OKEffect,
		/*[out,retval]*/ enum fmDropEffect * Effect) = 0;
	};

	struct __declspec(uuid("82b02370-b5bc-11cf-810f-00a0c9030074"))
		IReturnInteger : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Value(
			/*[in]*/ int Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ int * Value) = 0;
	};

	struct __declspec(uuid("82b02371-b5bc-11cf-810f-00a0c9030074"))
		IReturnBoolean : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Value(
			/*[in]*/ VARIANT_BOOL Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ VARIANT_BOOL * Value) = 0;
	};

	struct __declspec(uuid("82b02372-b5bc-11cf-810f-00a0c9030074"))
		IReturnString : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Value(
			/*[in]*/ BSTR Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ BSTR * Value) = 0;
	};

	struct __declspec(uuid("8a683c90-ba84-11cf-8110-00a0c9030074"))
		IReturnSingle : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Value(
			/*[in]*/ float Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ float * Value) = 0;
	};

	struct __declspec(uuid("8a683c91-ba84-11cf-8110-00a0c9030074"))
		IReturnEffect : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Value(
		/*[in]*/ enum fmDropEffect Value) = 0;
		virtual HRESULT __stdcall get_Value(
		/*[out,retval]*/ enum fmDropEffect * Value) = 0;
	};

	struct __declspec(uuid("82b02373-b5bc-11cf-810f-00a0c9030074"))
		ReturnInteger;
	// [ default ] interface IReturnInteger

	struct __declspec(uuid("82b02374-b5bc-11cf-810f-00a0c9030074"))
		ReturnBoolean;
	// [ default ] interface IReturnBoolean

	struct __declspec(uuid("82b02375-b5bc-11cf-810f-00a0c9030074"))
		ReturnString;
	// [ default ] interface IReturnString

	struct __declspec(uuid("8a683c92-ba84-11cf-8110-00a0c9030074"))
		ReturnSingle;
	// [ default ] interface IReturnSingle

	struct __declspec(uuid("8a683c93-ba84-11cf-8110-00a0c9030074"))
		ReturnEffect;
	// [ default ] interface IReturnEffect

	struct __declspec(uuid("1c3b4210-f441-11ce-b9ea-00aa006b1a69"))
		DataObject;
	// [ default ] interface IDataAutoWrapper

	enum __declspec(uuid("c63bd250-bcaa-11ce-b64d-00aa004cd6d8"))
		fmMode
	{
		fmModeInherit = -2,
		fmModeOn = -1,
		fmModeOff = 0
	};

	enum __declspec(uuid("593104f8-16ba-101b-989c-00006b82871a"))
		fmMousePointer
	{
		fmMousePointerDefault = 0,
		fmMousePointerArrow = 1,
		fmMousePointerCross = 2,
		fmMousePointerIBeam = 3,
		fmMousePointerSizeNESW = 6,
		fmMousePointerSizeNS = 7,
		fmMousePointerSizeNWSE = 8,
		fmMousePointerSizeWE = 9,
		fmMousePointerUpArrow = 10,
		fmMousePointerHourGlass = 11,
		fmMousePointerNoDrop = 12,
		fmMousePointerAppStarting = 13,
		fmMousePointerHelp = 14,
		fmMousePointerSizeAll = 15,
		fmMousePointerCustom = 99
	};

	enum __declspec(uuid("5931055e-16ba-101b-989c-00006b82871a"))
		fmScrollBars
	{
		fmScrollBarsNone = 0,
		fmScrollBarsHorizontal = 1,
		fmScrollBarsVertical = 2,
		fmScrollBarsBoth = 3
	};

	enum __declspec(uuid("e0abc3c0-d199-11ce-8cce-00aa0044bb60"))
		fmScrollAction
	{
		fmScrollActionNoChange = 0,
		fmScrollActionLineUp = 1,
		fmScrollActionLineDown = 2,
		fmScrollActionPageUp = 3,
		fmScrollActionPageDown = 4,
		fmScrollActionBegin = 5,
		fmScrollActionEnd = 6,
		_fmScrollActionAbsoluteChange = 7,
		fmScrollActionPropertyChange = 8,
		fmScrollActionControlRequest = 9,
		fmScrollActionFocusRequest = 10
	};

	enum __declspec(uuid("3dbdd630-dd73-11ce-8cd1-00aa0044bb60"))
		fmCycle
	{
		fmCycleAllForms = 0,
		fmCycleCurrentForm = 2
	};

	enum __declspec(uuid("14c73c30-1612-11ce-9e98-00aa00574a4f"))
		fmZOrder
	{
		fmZOrderFront = 0,
		fmZOrderBack = 1
	};

	enum __declspec(uuid("5931055c-16ba-101b-989c-00006b82871a"))
		fmBorderStyle
	{
		fmBorderStyleNone = 0,
		fmBorderStyleSingle = 1
	};

	enum __declspec(uuid("66baac90-7c2a-11ce-b783-00aa004ba6ae"))
		fmTextAlign
	{
		fmTextAlignLeft = 1,
		fmTextAlignCenter = 2,
		fmTextAlignRight = 3
	};

	enum __declspec(uuid("cd474e84-a35f-101a-beb9-00006b827da8"))
		fmAlignment
	{
		fmAlignmentLeft = 0,
		fmAlignmentRight = 1
	};

	enum __declspec(uuid("e1fc1640-70df-101b-bc16-00aa003e3b29"))
		fmBorders
	{
		fmBordersNone = 0,
		fmBordersBox = 1,
		fmBordersLeft = 2,
		fmBordersTop = 3
	};

	enum __declspec(uuid("1afb3130-c129-11cd-a777-00dd01143c57"))
		fmBackStyle
	{
		fmBackStyleTransparent = 0,
		fmBackStyleOpaque = 1
	};

	enum __declspec(uuid("fde774c0-9aa8-11cd-84db-00006b82871a"))
		fmButtonStyle
	{
		fmButtonStylePushButton = 0,
		fmButtonStyleToggleButton = 1
	};

	enum __declspec(uuid("9011f7a0-c130-11cd-9be1-00006b82871a"))
		fmPicPosition
	{
		fmPicPositionCenter = 0,
		fmPicPositionTopLeft = 1,
		fmPicPositionTopCenter = 2,
		fmPicPositionTopRight = 3,
		fmPicPositionCenterLeft = 4,
		fmPicPositionCenterRight = 5,
		fmPicPositionBottomLeft = 6,
		fmPicPositionBottomCenter = 7,
		fmPicPositionBottomRight = 8
	};

	enum __declspec(uuid("d625ca10-cc59-11ce-b653-00aa004cd6d8"))
		fmVerticalScrollBarSide
	{
		fmVerticalScrollBarSideRight = 0,
		fmVerticalScrollBarSideLeft = 1
	};

	enum __declspec(uuid("02dfd4f0-ea2b-11ce-8043-00aa006009fa"))
		fmLayoutEffect
	{
		fmLayoutEffectNone = 0,
		fmLayoutEffectInitiate = 1,
		_fmLayoutEffectRespond = 2
	};

	enum __declspec(uuid("a7946240-ea45-11ce-8043-00aa006009fa"))
		fmSpecialEffect
	{
		fmSpecialEffectFlat = 0,
		fmSpecialEffectRaised = 1,
		fmSpecialEffectSunken = 2,
		fmSpecialEffectEtched = 3,
		fmSpecialEffectBump = 6
	};

	enum __declspec(uuid("82074c80-ea51-11ce-8043-00aa006009fa"))
		fmDragState
	{
		fmDragStateEnter = 0,
		fmDragStateLeave = 1,
		fmDragStateOver = 2
	};

	enum __declspec(uuid("53327010-e90b-11ce-9e0b-00aa006002f3"))
		fmPictureSizeMode
	{
		fmPictureSizeModeClip = 0,
		fmPictureSizeModeStretch = 1,
		fmPictureSizeModeZoom = 3
	};

	enum __declspec(uuid("3574bbe0-f520-11ce-83f6-00aa00479846"))
		fmPictureAlignment
	{
		fmPictureAlignmentTopLeft = 0,
		fmPictureAlignmentTopRight = 1,
		fmPictureAlignmentCenter = 2,
		fmPictureAlignmentBottomLeft = 3,
		fmPictureAlignmentBottomRight = 4
	};

	struct __declspec(uuid("04598fc6-866c-11cf-ab7c-00aa00c08fcf"))
		IControl : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Cancel(
			/*[in]*/ VARIANT_BOOL Cancel) = 0;
		virtual HRESULT __stdcall get_Cancel(
			/*[out,retval]*/ VARIANT_BOOL * Cancel) = 0;
		virtual HRESULT __stdcall put_ControlSource(
			/*[in]*/ BSTR ControlSource) = 0;
		virtual HRESULT __stdcall get_ControlSource(
			/*[out,retval]*/ BSTR * ControlSource) = 0;
		virtual HRESULT __stdcall put_ControlTipText(
			/*[in]*/ BSTR ControlTipText) = 0;
		virtual HRESULT __stdcall get_ControlTipText(
			/*[out,retval]*/ BSTR * ControlTipText) = 0;
		virtual HRESULT __stdcall put_Default(
			/*[in]*/ VARIANT_BOOL Default) = 0;
		virtual HRESULT __stdcall get_Default(
			/*[out,retval]*/ VARIANT_BOOL * Default) = 0;
		virtual HRESULT __stdcall _SetHeight(
			/*[in]*/ long Height) = 0;
		virtual HRESULT __stdcall _GetHeight(
			/*[out]*/ long * Height) = 0;
		virtual HRESULT __stdcall put_Height(
			/*[in]*/ float Height) = 0;
		virtual HRESULT __stdcall get_Height(
			/*[out,retval]*/ float * Height) = 0;
		virtual HRESULT __stdcall put_HelpContextID(
			/*[in]*/ long HelpContextID) = 0;
		virtual HRESULT __stdcall get_HelpContextID(
			/*[out,retval]*/ long * HelpContextID) = 0;
		virtual HRESULT __stdcall put_InSelection(
			/*[in]*/ VARIANT_BOOL InSelection) = 0;
		virtual HRESULT __stdcall get_InSelection(
			/*[out,retval]*/ VARIANT_BOOL * InSelection) = 0;
		virtual HRESULT __stdcall get_LayoutEffect(
		/*[out,retval]*/ enum fmLayoutEffect * LayoutEffect) = 0;
		virtual HRESULT __stdcall _SetLeft(
			/*[in]*/ long Left) = 0;
		virtual HRESULT __stdcall _GetLeft(
			/*[out]*/ long * Left) = 0;
		virtual HRESULT __stdcall put_Left(
			/*[in]*/ float Left) = 0;
		virtual HRESULT __stdcall get_Left(
			/*[out,retval]*/ float * Left) = 0;
		virtual HRESULT __stdcall put_Name(
			/*[in]*/ BSTR Name) = 0;
		virtual HRESULT __stdcall get_Name(
			/*[out,retval]*/ BSTR * Name) = 0;
		virtual HRESULT __stdcall _GetOldHeight(
			/*[out]*/ long * OldHeight) = 0;
		virtual HRESULT __stdcall get_OldHeight(
			/*[out,retval]*/ float * OldHeight) = 0;
		virtual HRESULT __stdcall _GetOldLeft(
			/*[out]*/ long * OldLeft) = 0;
		virtual HRESULT __stdcall get_OldLeft(
			/*[out,retval]*/ float * OldLeft) = 0;
		virtual HRESULT __stdcall _GetOldTop(
			/*[out]*/ long * OldTop) = 0;
		virtual HRESULT __stdcall get_OldTop(
			/*[out,retval]*/ float * OldTop) = 0;
		virtual HRESULT __stdcall _GetOldWidth(
			/*[out]*/ long * OldWidth) = 0;
		virtual HRESULT __stdcall get_OldWidth(
			/*[out,retval]*/ float * OldWidth) = 0;
		virtual HRESULT __stdcall get_Object(
			/*[out,retval]*/ IDispatch * * Object) = 0;
		virtual HRESULT __stdcall get_Parent(
			/*[out,retval]*/ IDispatch * * Parent) = 0;
		virtual HRESULT __stdcall put_RowSource(
			/*[in]*/ BSTR RowSource) = 0;
		virtual HRESULT __stdcall get_RowSource(
			/*[out,retval]*/ BSTR * RowSource) = 0;
		virtual HRESULT __stdcall put_RowSourceType(
			/*[in]*/ short RowSourceType) = 0;
		virtual HRESULT __stdcall get_RowSourceType(
			/*[out,retval]*/ short * RowSourceType) = 0;
		virtual HRESULT __stdcall put_TabIndex(
			/*[in]*/ short TabIndex) = 0;
		virtual HRESULT __stdcall get_TabIndex(
			/*[out,retval]*/ short * TabIndex) = 0;
		virtual HRESULT __stdcall put_TabStop(
			/*[in]*/ VARIANT_BOOL TabStop) = 0;
		virtual HRESULT __stdcall get_TabStop(
			/*[out,retval]*/ VARIANT_BOOL * TabStop) = 0;
		virtual HRESULT __stdcall put_Tag(
			/*[in]*/ BSTR Tag) = 0;
		virtual HRESULT __stdcall get_Tag(
			/*[out,retval]*/ BSTR * Tag) = 0;
		virtual HRESULT __stdcall _SetTop(
			/*[in]*/ long Top) = 0;
		virtual HRESULT __stdcall _GetTop(
			/*[out]*/ long * Top) = 0;
		virtual HRESULT __stdcall put_Top(
			/*[in]*/ float Top) = 0;
		virtual HRESULT __stdcall get_Top(
			/*[out,retval]*/ float * Top) = 0;
		virtual HRESULT __stdcall put_BoundValue(
			/*[in]*/ VARIANT * BoundValue) = 0;
		virtual HRESULT __stdcall get_BoundValue(
			/*[out,retval]*/ VARIANT * BoundValue) = 0;
		virtual HRESULT __stdcall put_Visible(
			/*[in]*/ VARIANT_BOOL Visible) = 0;
		virtual HRESULT __stdcall get_Visible(
			/*[out,retval]*/ VARIANT_BOOL * Visible) = 0;
		virtual HRESULT __stdcall _SetWidth(
			/*[in]*/ long Width) = 0;
		virtual HRESULT __stdcall _GetWidth(
			/*[out]*/ long * Width) = 0;
		virtual HRESULT __stdcall put_Width(
			/*[in]*/ float Width) = 0;
		virtual HRESULT __stdcall get_Width(
			/*[out,retval]*/ float * Width) = 0;
		virtual HRESULT __stdcall Move(
			/*[in]*/ VARIANT Left = vtMissing,
			/*[in]*/ VARIANT Top = vtMissing,
			/*[in]*/ VARIANT Width = vtMissing,
			/*[in]*/ VARIANT Height = vtMissing,
			/*[in]*/ VARIANT Layout = vtMissing) = 0;
		virtual HRESULT __stdcall ZOrder(
			/*[in]*/ VARIANT zPosition = vtMissing) = 0;
		virtual HRESULT __stdcall Select(
			/*[in]*/ VARIANT_BOOL SelectInGroup) = 0;
		virtual HRESULT __stdcall SetFocus() = 0;
		virtual HRESULT __stdcall _GethWnd(
			/*[out,retval]*/ int * hWnd) = 0;
		virtual HRESULT __stdcall _GetID(
			/*[out,retval]*/ long * ID) = 0;
		virtual HRESULT __stdcall _Move(
			/*[in]*/ long Left,
			/*[in]*/ long Top,
			/*[in]*/ long Width,
			/*[in]*/ long Height) = 0;
		virtual HRESULT __stdcall _ZOrder(
		/*[in]*/ enum fmZOrder zPosition) = 0;
	};

	struct __declspec(uuid("9a4bbf53-4e46-101b-8bbd-00aa003e3b29"))
		ControlEvents : IDispatch
	{};

	struct __declspec(uuid("909e0ae0-16dc-11ce-9e98-00aa00574a4f"))
		Control;
	// [ default ] interface IControl
	// [ default, source ] dispinterface ControlEvents

	struct __declspec(uuid("04598fc7-866c-11cf-ab7c-00aa00c08fcf"))
		Controls : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_Count(
			/*[out,retval]*/ long * Count) = 0;
		virtual HRESULT __stdcall get__NewEnum(
			/*[out,retval]*/ IUnknown * * _NewEnum) = 0;
		virtual HRESULT __stdcall Item(
			/*[in]*/ VARIANT varg,
			/*[out,retval]*/ IDispatch * * ppDispatch) = 0;
		virtual HRESULT __stdcall Clear() = 0;
		virtual HRESULT __stdcall _Move(
			/*[in]*/ long cx,
			/*[in]*/ long cy) = 0;
		virtual HRESULT __stdcall SelectAll() = 0;
		virtual HRESULT __stdcall _AddByClass(
			/*[in]*/ long * clsid,
		/*[out,retval]*/ struct IControl * * Control) = 0;
		virtual HRESULT __stdcall AlignToGrid() = 0;
		virtual HRESULT __stdcall BringForward() = 0;
		virtual HRESULT __stdcall BringToFront() = 0;
		virtual HRESULT __stdcall Copy() = 0;
		virtual HRESULT __stdcall Cut() = 0;
		virtual HRESULT __stdcall Enum(
			/*[out,retval]*/ IUnknown * * ppEnum) = 0;
		virtual HRESULT __stdcall _GetItemByIndex(
			/*[in]*/ long lIndex,
		/*[out,retval]*/ struct IControl * * Control) = 0;
		virtual HRESULT __stdcall _GetItemByName(
			/*[in]*/ BSTR pstr,
		/*[out,retval]*/ struct IControl * * Control) = 0;
		virtual HRESULT __stdcall _GetItemByID(
			/*[in]*/ long ID,
		/*[out,retval]*/ struct IControl * * Control) = 0;
		virtual HRESULT __stdcall SendBackward() = 0;
		virtual HRESULT __stdcall SendToBack() = 0;
		virtual HRESULT __stdcall Move(
			/*[in]*/ float cx,
			/*[in]*/ float cy) = 0;
		virtual HRESULT __stdcall Add(
			/*[in]*/ BSTR bstrProgID,
			/*[in]*/ VARIANT Name,
			/*[in]*/ VARIANT Visible,
		/*[out,retval]*/ struct IControl * * Control) = 0;
		virtual HRESULT __stdcall Remove(
			/*[in]*/ VARIANT varg) = 0;
	};

	struct __declspec(uuid("29b86a70-f52e-11ce-9bce-00aa00608e01"))
		IOptionFrame : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_ActiveControl(
		/*[out,retval]*/ struct IControl * * ActiveControl) = 0;
		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BorderColor(
			/*[in]*/ OLE_COLOR BorderColor) = 0;
		virtual HRESULT __stdcall get_BorderColor(
			/*[out,retval]*/ OLE_COLOR * BorderColor) = 0;
		virtual HRESULT __stdcall put_BorderStyle(
		/*[in]*/ enum fmBorderStyle BorderStyle) = 0;
		virtual HRESULT __stdcall get_BorderStyle(
		/*[out,retval]*/ enum fmBorderStyle * BorderStyle) = 0;
		virtual HRESULT __stdcall get_CanPaste(
			/*[out,retval]*/ VARIANT_BOOL * CanPaste) = 0;
		virtual HRESULT __stdcall get_CanRedo(
			/*[out,retval]*/ VARIANT_BOOL * CanRedo) = 0;
		virtual HRESULT __stdcall get_CanUndo(
			/*[out,retval]*/ VARIANT_BOOL * CanUndo) = 0;
		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR Caption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * Caption) = 0;
		virtual HRESULT __stdcall get_Controls(
		/*[out,retval]*/ struct Controls * * Controls) = 0;
		virtual HRESULT __stdcall put_Cycle(
		/*[in]*/ enum fmCycle Cycle) = 0;
		virtual HRESULT __stdcall get_Cycle(
		/*[out,retval]*/ enum fmCycle * Cycle) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall _GetInsideHeight(
			/*[out]*/ long * InsideHeight) = 0;
		virtual HRESULT __stdcall get_InsideHeight(
			/*[out,retval]*/ float * InsideHeight) = 0;
		virtual HRESULT __stdcall _GetInsideWidth(
			/*[out]*/ long * InsideWidth) = 0;
		virtual HRESULT __stdcall get_InsideWidth(
			/*[out,retval]*/ float * InsideWidth) = 0;
		virtual HRESULT __stdcall put_KeepScrollBarsVisible(
		/*[in]*/ enum fmScrollBars ScrollBars) = 0;
		virtual HRESULT __stdcall get_KeepScrollBarsVisible(
		/*[out,retval]*/ enum fmScrollBars * ScrollBars) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_PictureAlignment(
		/*[in]*/ enum fmPictureAlignment PictureAlignment) = 0;
		virtual HRESULT __stdcall get_PictureAlignment(
		/*[out,retval]*/ enum fmPictureAlignment * PictureAlignment) = 0;
		virtual HRESULT __stdcall put_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall putref_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall get_Picture(
		/*[out,retval]*/ struct Picture * * Picture) = 0;
		virtual HRESULT __stdcall put_PictureSizeMode(
		/*[in]*/ enum fmPictureSizeMode PictureSizeMode) = 0;
		virtual HRESULT __stdcall get_PictureSizeMode(
		/*[out,retval]*/ enum fmPictureSizeMode * PictureSizeMode) = 0;
		virtual HRESULT __stdcall put_PictureTiling(
			/*[in]*/ VARIANT_BOOL PictureTiling) = 0;
		virtual HRESULT __stdcall get_PictureTiling(
			/*[out,retval]*/ VARIANT_BOOL * PictureTiling) = 0;
		virtual HRESULT __stdcall put_ScrollBars(
		/*[in]*/ enum fmScrollBars ScrollBars) = 0;
		virtual HRESULT __stdcall get_ScrollBars(
		/*[out,retval]*/ enum fmScrollBars * ScrollBars) = 0;
		virtual HRESULT __stdcall _SetScrollHeight(
			/*[in]*/ long ScrollHeight) = 0;
		virtual HRESULT __stdcall _GetScrollHeight(
			/*[out]*/ long * ScrollHeight) = 0;
		virtual HRESULT __stdcall put_ScrollHeight(
			/*[in]*/ float ScrollHeight) = 0;
		virtual HRESULT __stdcall get_ScrollHeight(
			/*[out,retval]*/ float * ScrollHeight) = 0;
		virtual HRESULT __stdcall _SetScrollLeft(
			/*[in]*/ long ScrollLeft) = 0;
		virtual HRESULT __stdcall _GetScrollLeft(
			/*[out]*/ long * ScrollLeft) = 0;
		virtual HRESULT __stdcall put_ScrollLeft(
			/*[in]*/ float ScrollLeft) = 0;
		virtual HRESULT __stdcall get_ScrollLeft(
			/*[out,retval]*/ float * ScrollLeft) = 0;
		virtual HRESULT __stdcall _SetScrollTop(
			/*[in]*/ long ScrollTop) = 0;
		virtual HRESULT __stdcall _GetScrollTop(
			/*[out]*/ long * ScrollTop) = 0;
		virtual HRESULT __stdcall put_ScrollTop(
			/*[in]*/ float ScrollTop) = 0;
		virtual HRESULT __stdcall get_ScrollTop(
			/*[out,retval]*/ float * ScrollTop) = 0;
		virtual HRESULT __stdcall _SetScrollWidth(
			/*[in]*/ long ScrollWidth) = 0;
		virtual HRESULT __stdcall _GetScrollWidth(
			/*[out]*/ long * ScrollWidth) = 0;
		virtual HRESULT __stdcall put_ScrollWidth(
			/*[in]*/ float ScrollWidth) = 0;
		virtual HRESULT __stdcall get_ScrollWidth(
			/*[out,retval]*/ float * ScrollWidth) = 0;
		virtual HRESULT __stdcall get_Selected(
		/*[out,retval]*/ struct Controls * * Selected) = 0;
		virtual HRESULT __stdcall put_SpecialEffect(
		/*[in]*/ enum fmSpecialEffect SpecialEffect) = 0;
		virtual HRESULT __stdcall get_SpecialEffect(
		/*[out,retval]*/ enum fmSpecialEffect * SpecialEffect) = 0;
		virtual HRESULT __stdcall put_VerticalScrollBarSide(
		/*[in]*/ enum fmVerticalScrollBarSide side) = 0;
		virtual HRESULT __stdcall get_VerticalScrollBarSide(
		/*[out,retval]*/ enum fmVerticalScrollBarSide * side) = 0;
		virtual HRESULT __stdcall put_Zoom(
			/*[in]*/ short Zoom) = 0;
		virtual HRESULT __stdcall get_Zoom(
			/*[out,retval]*/ short * Zoom) = 0;
		virtual HRESULT __stdcall Copy() = 0;
		virtual HRESULT __stdcall Cut() = 0;
		virtual HRESULT __stdcall Paste() = 0;
		virtual HRESULT __stdcall RedoAction() = 0;
		virtual HRESULT __stdcall Repaint() = 0;
		virtual HRESULT __stdcall Scroll(
			/*[in]*/ VARIANT xAction = vtMissing,
			/*[in]*/ VARIANT yAction = vtMissing) = 0;
		virtual HRESULT __stdcall SetDefaultTabOrder() = 0;
		virtual HRESULT __stdcall UndoAction() = 0;
		virtual HRESULT __stdcall put_DesignMode(
		/*[in]*/ enum fmMode DesignMode) = 0;
		virtual HRESULT __stdcall get_DesignMode(
		/*[out,retval]*/ enum fmMode * DesignMode) = 0;
		virtual HRESULT __stdcall put_ShowToolbox(
		/*[in]*/ enum fmMode ShowToolbox) = 0;
		virtual HRESULT __stdcall get_ShowToolbox(
		/*[out,retval]*/ enum fmMode * ShowToolbox) = 0;
		virtual HRESULT __stdcall put_ShowGridDots(
		/*[in]*/ enum fmMode ShowGridDots) = 0;
		virtual HRESULT __stdcall get_ShowGridDots(
		/*[out,retval]*/ enum fmMode * ShowGridDots) = 0;
		virtual HRESULT __stdcall put_SnapToGrid(
		/*[in]*/ enum fmMode SnapToGrid) = 0;
		virtual HRESULT __stdcall get_SnapToGrid(
		/*[out,retval]*/ enum fmMode * SnapToGrid) = 0;
		virtual HRESULT __stdcall put_GridX(
			/*[in]*/ float GridX) = 0;
		virtual HRESULT __stdcall get_GridX(
			/*[out,retval]*/ float * GridX) = 0;
		virtual HRESULT __stdcall _SetGridX(
			/*[in]*/ long GridX) = 0;
		virtual HRESULT __stdcall _GetGridX(
			/*[out]*/ long * GridX) = 0;
		virtual HRESULT __stdcall put_GridY(
			/*[in]*/ float GridY) = 0;
		virtual HRESULT __stdcall get_GridY(
			/*[out,retval]*/ float * GridY) = 0;
		virtual HRESULT __stdcall _SetGridY(
			/*[in]*/ long GridY) = 0;
		virtual HRESULT __stdcall _GetGridY(
			/*[out]*/ long * GridY) = 0;
	};

	struct __declspec(uuid("04598fc8-866c-11cf-ab7c-00aa00c08fcf"))
		_UserForm : IOptionFrame
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_DrawBuffer(
			/*[in]*/ long DrawBuffer) = 0;
		virtual HRESULT __stdcall get_DrawBuffer(
			/*[out,retval]*/ long * DrawBuffer) = 0;
	};

	struct __declspec(uuid("5b9d8fc8-4a71-101b-97a6-00000b65c08b"))
		FormEvents : IDispatch
	{};

	struct __declspec(uuid("cf3f94a0-f546-11ce-9bce-00aa00608e01"))
		OptionFrameEvents : IDispatch
	{};

	struct __declspec(uuid("c62a69f0-16dc-11ce-9e98-00aa00574a4f"))
		UserForm;
	// [ default ] interface _UserForm
	// [ default, source ] dispinterface FormEvents

	struct __declspec(uuid("6e182020-f460-11ce-9bcd-00aa00608e01"))
		Frame;
	// [ default ] interface IOptionFrame
	// [ default, source ] dispinterface OptionFrameEvents

	enum __declspec(uuid("317a54c0-c7b1-11ce-9afd-00aa00600ab8"))
		fmButtonEffect
	{
		fmButtonEffectFlat = 0,
		fmButtonEffectSunken = 2
	};

	enum __declspec(uuid("16e571e0-040b-11cf-8283-00aa004ba6ae"))
		fmOrientation
	{
		fmOrientationAuto = -1,
		fmOrientationVertical = 0,
		fmOrientationHorizontal = 1
	};

	enum __declspec(uuid("317a54c1-c7b1-11ce-9afd-00aa00600ab8"))
		fmSnapPoint
	{
		fmSnapPointTopLeft = 0,
		fmSnapPointTopCenter = 1,
		fmSnapPointTopRight = 2,
		fmSnapPointCenterLeft = 3,
		fmSnapPointCenter = 4,
		fmSnapPointCenterRight = 5,
		fmSnapPointBottomLeft = 6,
		fmSnapPointBottomCenter = 7,
		fmSnapPointBottomRight = 8
	};

	enum __declspec(uuid("317a54c2-c7b1-11ce-9afd-00aa00600ab8"))
		fmPicturePosition
	{
		fmPicturePositionLeftTop = 0,
		fmPicturePositionLeftCenter = 1,
		fmPicturePositionLeftBottom = 2,
		fmPicturePositionRightTop = 3,
		fmPicturePositionRightCenter = 4,
		fmPicturePositionRightBottom = 5,
		fmPicturePositionAboveLeft = 6,
		fmPicturePositionAboveCenter = 7,
		fmPicturePositionAboveRight = 8,
		fmPicturePositionBelowLeft = 9,
		fmPicturePositionBelowCenter = 10,
		fmPicturePositionBelowRight = 11,
		fmPicturePositionCenter = 12
	};

	enum __declspec(uuid("a4069f25-4221-11ce-8ea0-00aa004ba6ae"))
		fmDisplayStyle
	{
		fmDisplayStyleText = 1,
		fmDisplayStyleList = 2,
		fmDisplayStyleCombo = 3,
		fmDisplayStyleCheckBox = 4,
		fmDisplayStyleOptionButton = 5,
		fmDisplayStyleToggle = 6,
		fmDisplayStyleDropList = 7
	};

	enum __declspec(uuid("a4069f24-4221-11ce-8ea0-00aa004ba6ae"))
		fmShowListWhen
	{
		fmShowListWhenNever = 0,
		fmShowListWhenButton = 1,
		fmShowListWhenFocus = 2,
		fmShowListWhenAlways = 3
	};

	enum __declspec(uuid("c5d98c41-4eb2-11ce-8ea0-00aa004ba6ae"))
		fmShowDropButtonWhen
	{
		fmShowDropButtonWhenNever = 0,
		fmShowDropButtonWhenFocus = 1,
		fmShowDropButtonWhenAlways = 2
	};

	enum __declspec(uuid("f00164c0-b17b-11ce-a95d-00aa006cb389"))
		fmMultiSelect
	{
		fmMultiSelectSingle = 0,
		fmMultiSelectMulti = 1,
		fmMultiSelectExtended = 2
	};

	enum __declspec(uuid("f00164c1-b17b-11ce-a95d-00aa006cb389"))
		fmListStyle
	{
		fmListStylePlain = 0,
		fmListStyleOption = 1
	};

	enum __declspec(uuid("6a7167f1-2432-11cf-956f-00aa004b9dfa"))
		fmEnterFieldBehavior
	{
		fmEnterFieldBehaviorSelectAll = 0,
		fmEnterFieldBehaviorRecallSelection = 1
	};

	enum __declspec(uuid("e25eb550-24f6-11cf-a6e2-00aa00c0098d"))
		fmDragBehavior
	{
		fmDragBehaviorDisabled = 0,
		fmDragBehaviorEnabled = 1
	};

	enum __declspec(uuid("8ccd0ac2-b1ad-11ce-8276-00aa004ba6ae"))
		fmMatchEntry
	{
		fmMatchEntryFirstLetter = 0,
		fmMatchEntryComplete = 1,
		fmMatchEntryNone = 2
	};

	enum __declspec(uuid("14d122b0-c6e7-11ce-827c-00aa004ba6ae"))
		fmDropButtonStyle
	{
		fmDropButtonStylePlain = 0,
		fmDropButtonStyleArrow = 1,
		fmDropButtonStyleEllipsis = 2,
		fmDropButtonStyleReduce = 3
	};

	enum __declspec(uuid("9c37f9d0-fde5-11ce-9560-00aa004b9dfa"))
		fmStyle
	{
		fmStyleDropDownCombo = 0,
		fmStyleDropDownList = 2
	};

	enum __declspec(uuid("ebc7fde1-6899-11ce-80c0-00aa00611080"))
		fmTabOrientation
	{
		fmTabOrientationTop = 0,
		fmTabOrientationBottom = 1,
		fmTabOrientationLeft = 2,
		fmTabOrientationRight = 3
	};

	enum __declspec(uuid("ebc7fde3-6899-11ce-80c0-00aa00611080"))
		fmTabStyle
	{
		fmTabStyleTabs = 0,
		fmTabStyleButtons = 1,
		fmTabStyleNone = 2
	};

	enum __declspec(uuid("4d067cd0-0d74-11cf-b474-00aa006eb734"))
		fmIMEMode
	{
		fmIMEModeNoControl = 0,
		fmIMEModeOn = 1,
		fmIMEModeOff = 2,
		fmIMEModeDisable = 3,
		fmIMEModeHiragana = 4,
		fmIMEModeKatakana = 5,
		fmIMEModeKatakanaHalf = 6,
		fmIMEModeAlphaFull = 7,
		fmIMEModeAlpha = 8,
		fmIMEModeHangulFull = 9,
		fmIMEModeHangul = 10,
		fmIMEModeHanziFull = 11,
		fmIMEModeHanzi = 12
	};

	struct __declspec(uuid("04598fc1-866c-11cf-ab7c-00aa00c08fcf"))
		ILabelControl : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_AutoSize(
			/*[in]*/ VARIANT_BOOL fvbAutoSize) = 0;
		virtual HRESULT __stdcall get_AutoSize(
			/*[out,retval]*/ VARIANT_BOOL * fvbAutoSize) = 0;
		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BackStyle(
		/*[in]*/ enum fmBackStyle BackStyle) = 0;
		virtual HRESULT __stdcall get_BackStyle(
		/*[out,retval]*/ enum fmBackStyle * BackStyle) = 0;
		virtual HRESULT __stdcall put_BorderColor(
			/*[in]*/ OLE_COLOR BorderColor) = 0;
		virtual HRESULT __stdcall get_BorderColor(
			/*[out,retval]*/ OLE_COLOR * BorderColor) = 0;
		virtual HRESULT __stdcall put_BorderStyle(
		/*[in]*/ enum fmBorderStyle BorderStyle) = 0;
		virtual HRESULT __stdcall get_BorderStyle(
		/*[out,retval]*/ enum fmBorderStyle * BorderStyle) = 0;
		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR bstrCaption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * bstrCaption) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL fEnabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * fEnabled) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL FontItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * FontItalic) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL FontBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * FontBold) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY FontSize) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * FontSize) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL FontStrikethru) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * FontStrikethru) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL FontUnderline) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * FontUnderline) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_Picture(
		/*[in]*/ struct Picture * pPicture) = 0;
		virtual HRESULT __stdcall putref_Picture(
		/*[in]*/ struct Picture * pPicture) = 0;
		virtual HRESULT __stdcall get_Picture(
		/*[out,retval]*/ struct Picture * * pPicture) = 0;
		virtual HRESULT __stdcall put_PicturePosition(
		/*[in]*/ enum fmPicturePosition PicPos) = 0;
		virtual HRESULT __stdcall get_PicturePosition(
		/*[out,retval]*/ enum fmPicturePosition * PicPos) = 0;
		virtual HRESULT __stdcall put_SpecialEffect(
		/*[in]*/ enum fmSpecialEffect SpecialEffect) = 0;
		virtual HRESULT __stdcall get_SpecialEffect(
		/*[out,retval]*/ enum fmSpecialEffect * SpecialEffect) = 0;
		virtual HRESULT __stdcall put_TextAlign(
		/*[in]*/ enum fmTextAlign TextAlign) = 0;
		virtual HRESULT __stdcall get_TextAlign(
		/*[out,retval]*/ enum fmTextAlign * TextAlign) = 0;
		virtual HRESULT __stdcall put_WordWrap(
			/*[in]*/ VARIANT_BOOL WordWrap) = 0;
		virtual HRESULT __stdcall get_WordWrap(
			/*[out,retval]*/ VARIANT_BOOL * WordWrap) = 0;
		virtual HRESULT __stdcall put_Accelerator(
			/*[in]*/ BSTR Accelerator) = 0;
		virtual HRESULT __stdcall get_Accelerator(
			/*[out,retval]*/ BSTR * Accelerator) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
		virtual HRESULT __stdcall put__Value(
			/*[in]*/ BSTR bstrCaption) = 0;
		virtual HRESULT __stdcall get__Value(
			/*[out,retval]*/ BSTR * bstrCaption) = 0;
	};

	struct __declspec(uuid("04598fc4-866c-11cf-ab7c-00aa00c08fcf"))
		ICommandButton : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_AutoSize(
			/*[in]*/ VARIANT_BOOL fvbAutoSize) = 0;
		virtual HRESULT __stdcall get_AutoSize(
			/*[out,retval]*/ VARIANT_BOOL * fvbAutoSize) = 0;
		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BackStyle(
		/*[in]*/ enum fmBackStyle BackStyle) = 0;
		virtual HRESULT __stdcall get_BackStyle(
		/*[out,retval]*/ enum fmBackStyle * BackStyle) = 0;
		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR bstrCaption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * bstrCaption) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL fEnabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * fEnabled) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL FontBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * FontBold) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL FontItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * FontItalic) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY FontSize) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * FontSize) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL FontStrikethru) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * FontStrikethru) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL FontUnderline) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * FontUnderline) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_TakeFocusOnClick(
			/*[in]*/ VARIANT_BOOL TakeFocusOnClick) = 0;
		virtual HRESULT __stdcall get_TakeFocusOnClick(
			/*[out,retval]*/ VARIANT_BOOL * TakeFocusOnClick) = 0;
		virtual HRESULT __stdcall put_Locked(
			/*[in]*/ VARIANT_BOOL fLocked) = 0;
		virtual HRESULT __stdcall get_Locked(
			/*[out,retval]*/ VARIANT_BOOL * fLocked) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer mouseptr) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * mouseptr) = 0;
		virtual HRESULT __stdcall put_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall putref_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall get_Picture(
		/*[out,retval]*/ struct Picture * * Picture) = 0;
		virtual HRESULT __stdcall put_PicturePosition(
		/*[in]*/ enum fmPicturePosition PicturePosition) = 0;
		virtual HRESULT __stdcall get_PicturePosition(
		/*[out,retval]*/ enum fmPicturePosition * PicturePosition) = 0;
		virtual HRESULT __stdcall put_Accelerator(
			/*[in]*/ BSTR Accelerator) = 0;
		virtual HRESULT __stdcall get_Accelerator(
			/*[out,retval]*/ BSTR * Accelerator) = 0;
		virtual HRESULT __stdcall put_WordWrap(
			/*[in]*/ VARIANT_BOOL WordWrap) = 0;
		virtual HRESULT __stdcall get_WordWrap(
			/*[out,retval]*/ VARIANT_BOOL * WordWrap) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ VARIANT_BOOL fValue) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ VARIANT_BOOL * fValue) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
	};

	struct __declspec(uuid("8bd21d13-ec42-11ce-9e0d-00aa006002f3"))
		IMdcText : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_AutoSize(
			/*[in]*/ VARIANT_BOOL AutoSize) = 0;
		virtual HRESULT __stdcall get_AutoSize(
			/*[out,retval]*/ VARIANT_BOOL * AutoSize) = 0;
		virtual HRESULT __stdcall put_AutoTab(
			/*[in]*/ VARIANT_BOOL AutoTab) = 0;
		virtual HRESULT __stdcall get_AutoTab(
			/*[out,retval]*/ VARIANT_BOOL * AutoTab) = 0;
		virtual HRESULT __stdcall put_AutoWordSelect(
			/*[in]*/ VARIANT_BOOL AutoWordSelect) = 0;
		virtual HRESULT __stdcall get_AutoWordSelect(
			/*[out,retval]*/ VARIANT_BOOL * AutoWordSelect) = 0;
		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BackStyle(
		/*[in]*/ enum fmBackStyle BackStyle) = 0;
		virtual HRESULT __stdcall get_BackStyle(
		/*[out,retval]*/ enum fmBackStyle * BackStyle) = 0;
		virtual HRESULT __stdcall put_BorderColor(
			/*[in]*/ OLE_COLOR BorderColor) = 0;
		virtual HRESULT __stdcall get_BorderColor(
			/*[out,retval]*/ OLE_COLOR * BorderColor) = 0;
		virtual HRESULT __stdcall put_BorderStyle(
		/*[in]*/ enum fmBorderStyle BorderStyle) = 0;
		virtual HRESULT __stdcall get_BorderStyle(
		/*[out,retval]*/ enum fmBorderStyle * BorderStyle) = 0;
		virtual HRESULT __stdcall put_BordersSuppress(
			/*[in]*/ VARIANT_BOOL BordersSuppress) = 0;
		virtual HRESULT __stdcall get_BordersSuppress(
			/*[out,retval]*/ VARIANT_BOOL * BordersSuppress) = 0;
		virtual HRESULT __stdcall get_CanPaste(
			/*[out,retval]*/ VARIANT_BOOL * CanPaste) = 0;
		virtual HRESULT __stdcall put_CurLine(
			/*[in]*/ long CurLine) = 0;
		virtual HRESULT __stdcall get_CurLine(
			/*[out,retval]*/ long * CurLine) = 0;
		virtual HRESULT __stdcall get_CurTargetX(
			/*[out,retval]*/ long * CurTargetX) = 0;
		virtual HRESULT __stdcall get_CurTargetY(
			/*[out,retval]*/ long * CurTargetY) = 0;
		virtual HRESULT __stdcall put_CurX(
			/*[in]*/ long CurX) = 0;
		virtual HRESULT __stdcall get_CurX(
			/*[out,retval]*/ long * CurX) = 0;
		virtual HRESULT __stdcall put_CurY(
			/*[in]*/ long CurY) = 0;
		virtual HRESULT __stdcall get_CurY(
			/*[out,retval]*/ long * CurY) = 0;
		virtual HRESULT __stdcall put_DropButtonStyle(
		/*[in]*/ enum fmDropButtonStyle DropButtonStyle) = 0;
		virtual HRESULT __stdcall get_DropButtonStyle(
		/*[out,retval]*/ enum fmDropButtonStyle * DropButtonStyle) = 0;
		virtual HRESULT __stdcall put_EnterKeyBehavior(
			/*[in]*/ VARIANT_BOOL EnterKeyBehavior) = 0;
		virtual HRESULT __stdcall get_EnterKeyBehavior(
			/*[out,retval]*/ VARIANT_BOOL * EnterKeyBehavior) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL FontBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * FontBold) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL FontItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * FontItalic) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY FontSize) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * FontSize) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL FontStrikethru) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * FontStrikethru) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL FontUnderline) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * FontUnderline) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_HideSelection(
			/*[in]*/ VARIANT_BOOL HideSelection) = 0;
		virtual HRESULT __stdcall get_HideSelection(
			/*[out,retval]*/ VARIANT_BOOL * HideSelection) = 0;
		virtual HRESULT __stdcall put_IntegralHeight(
			/*[in]*/ VARIANT_BOOL IntegralHeight) = 0;
		virtual HRESULT __stdcall get_IntegralHeight(
			/*[out,retval]*/ VARIANT_BOOL * IntegralHeight) = 0;
		virtual HRESULT __stdcall get_LineCount(
			/*[out,retval]*/ long * LineCount) = 0;
		virtual HRESULT __stdcall put_Locked(
			/*[in]*/ VARIANT_BOOL Locked) = 0;
		virtual HRESULT __stdcall get_Locked(
			/*[out,retval]*/ VARIANT_BOOL * Locked) = 0;
		virtual HRESULT __stdcall put_MaxLength(
			/*[in]*/ long MaxLength) = 0;
		virtual HRESULT __stdcall get_MaxLength(
			/*[out,retval]*/ long * MaxLength) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_MultiLine(
			/*[in]*/ VARIANT_BOOL MultiLine) = 0;
		virtual HRESULT __stdcall get_MultiLine(
			/*[out,retval]*/ VARIANT_BOOL * MultiLine) = 0;
		virtual HRESULT __stdcall put_PasswordChar(
			/*[in]*/ BSTR PasswordChar) = 0;
		virtual HRESULT __stdcall get_PasswordChar(
			/*[out,retval]*/ BSTR * PasswordChar) = 0;
		virtual HRESULT __stdcall put_ScrollBars(
		/*[in]*/ enum fmScrollBars ScrollBars) = 0;
		virtual HRESULT __stdcall get_ScrollBars(
		/*[out,retval]*/ enum fmScrollBars * ScrollBars) = 0;
		virtual HRESULT __stdcall put_SelectionMargin(
			/*[in]*/ VARIANT_BOOL SelectionMargin) = 0;
		virtual HRESULT __stdcall get_SelectionMargin(
			/*[out,retval]*/ VARIANT_BOOL * SelectionMargin) = 0;
		virtual HRESULT __stdcall put_SelLength(
			/*[in]*/ long SelLength) = 0;
		virtual HRESULT __stdcall get_SelLength(
			/*[out,retval]*/ long * SelLength) = 0;
		virtual HRESULT __stdcall put_SelStart(
			/*[in]*/ long SelStart) = 0;
		virtual HRESULT __stdcall get_SelStart(
			/*[out,retval]*/ long * SelStart) = 0;
		virtual HRESULT __stdcall put_SelText(
			/*[in]*/ BSTR SelText) = 0;
		virtual HRESULT __stdcall get_SelText(
			/*[out,retval]*/ BSTR * SelText) = 0;
		virtual HRESULT __stdcall put_ShowDropButtonWhen(
		/*[in]*/ enum fmShowDropButtonWhen ShowDropButtonWhen) = 0;
		virtual HRESULT __stdcall get_ShowDropButtonWhen(
		/*[out,retval]*/ enum fmShowDropButtonWhen * ShowDropButtonWhen) = 0;
		virtual HRESULT __stdcall put_SpecialEffect(
		/*[in]*/ enum fmSpecialEffect SpecialEffect) = 0;
		virtual HRESULT __stdcall get_SpecialEffect(
		/*[out,retval]*/ enum fmSpecialEffect * SpecialEffect) = 0;
		virtual HRESULT __stdcall put_TabKeyBehavior(
			/*[in]*/ VARIANT_BOOL TabKeyBehavior) = 0;
		virtual HRESULT __stdcall get_TabKeyBehavior(
			/*[out,retval]*/ VARIANT_BOOL * TabKeyBehavior) = 0;
		virtual HRESULT __stdcall put_Text(
			/*[in]*/ BSTR Text) = 0;
		virtual HRESULT __stdcall get_Text(
			/*[out,retval]*/ BSTR * Text) = 0;
		virtual HRESULT __stdcall put_TextAlign(
		/*[in]*/ enum fmTextAlign TextAlign) = 0;
		virtual HRESULT __stdcall get_TextAlign(
		/*[out,retval]*/ enum fmTextAlign * TextAlign) = 0;
		virtual HRESULT __stdcall get_TextLength(
			/*[out,retval]*/ long * TextLength) = 0;
		virtual HRESULT __stdcall get_Valid(
			/*[out,retval]*/ VARIANT_BOOL * Valid) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall put_WordWrap(
			/*[in]*/ VARIANT_BOOL WordWrap) = 0;
		virtual HRESULT __stdcall get_WordWrap(
			/*[out,retval]*/ VARIANT_BOOL * WordWrap) = 0;
		virtual HRESULT __stdcall Copy() = 0;
		virtual HRESULT __stdcall Cut() = 0;
		virtual HRESULT __stdcall Paste() = 0;
		virtual HRESULT __stdcall put_IMEMode(
		/*[in]*/ enum fmIMEMode IMEMode) = 0;
		virtual HRESULT __stdcall get_IMEMode(
		/*[out,retval]*/ enum fmIMEMode * IMEMode) = 0;
		virtual HRESULT __stdcall put_EnterFieldBehavior(
		/*[in]*/ enum fmEnterFieldBehavior EnterFieldBehavior) = 0;
		virtual HRESULT __stdcall get_EnterFieldBehavior(
		/*[out,retval]*/ enum fmEnterFieldBehavior * EnterFieldBehavior) = 0;
		virtual HRESULT __stdcall put_DragBehavior(
		/*[in]*/ enum fmDragBehavior DragBehavior) = 0;
		virtual HRESULT __stdcall get_DragBehavior(
		/*[out,retval]*/ enum fmDragBehavior * DragBehavior) = 0;
		virtual HRESULT __stdcall get_DisplayStyle(
		/*[out,retval]*/ enum fmDisplayStyle * DisplayStyle) = 0;
	};

	struct __declspec(uuid("8bd21d23-ec42-11ce-9e0d-00aa006002f3"))
		IMdcList : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BorderColor(
			/*[in]*/ OLE_COLOR BorderColor) = 0;
		virtual HRESULT __stdcall get_BorderColor(
			/*[out,retval]*/ OLE_COLOR * BorderColor) = 0;
		virtual HRESULT __stdcall put_BorderStyle(
		/*[in]*/ enum fmBorderStyle BorderStyle) = 0;
		virtual HRESULT __stdcall get_BorderStyle(
		/*[out,retval]*/ enum fmBorderStyle * BorderStyle) = 0;
		virtual HRESULT __stdcall put_BordersSuppress(
			/*[in]*/ VARIANT_BOOL BordersSuppress) = 0;
		virtual HRESULT __stdcall get_BordersSuppress(
			/*[out,retval]*/ VARIANT_BOOL * BordersSuppress) = 0;
		virtual HRESULT __stdcall put_BoundColumn(
			/*[in]*/ VARIANT * BoundColumn) = 0;
		virtual HRESULT __stdcall get_BoundColumn(
			/*[out,retval]*/ VARIANT * BoundColumn) = 0;
		virtual HRESULT __stdcall put_ColumnCount(
			/*[in]*/ long ColumnCount) = 0;
		virtual HRESULT __stdcall get_ColumnCount(
			/*[out,retval]*/ long * ColumnCount) = 0;
		virtual HRESULT __stdcall put_ColumnHeads(
			/*[in]*/ VARIANT_BOOL ColumnHeads) = 0;
		virtual HRESULT __stdcall get_ColumnHeads(
			/*[out,retval]*/ VARIANT_BOOL * ColumnHeads) = 0;
		virtual HRESULT __stdcall put_ColumnWidths(
			/*[in]*/ BSTR ColumnWidths) = 0;
		virtual HRESULT __stdcall get_ColumnWidths(
			/*[out,retval]*/ BSTR * ColumnWidths) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL FontBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * FontBold) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL FontItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * FontItalic) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY FontSize) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * FontSize) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL FontStrikethru) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * FontStrikethru) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL FontUnderline) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * FontUnderline) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_IntegralHeight(
			/*[in]*/ VARIANT_BOOL IntegralHeight) = 0;
		virtual HRESULT __stdcall get_IntegralHeight(
			/*[out,retval]*/ VARIANT_BOOL * IntegralHeight) = 0;
		virtual HRESULT __stdcall get_ListCount(
			/*[out,retval]*/ long * ListCount) = 0;
		virtual HRESULT __stdcall put_ListCursor(
			/*[in]*/ PIROWSET ListCursor) = 0;
		virtual HRESULT __stdcall get_ListCursor(
			/*[out,retval]*/ PIROWSET * ListCursor) = 0;
		virtual HRESULT __stdcall put_ListIndex(
			/*[in]*/ VARIANT * ListIndex) = 0;
		virtual HRESULT __stdcall get_ListIndex(
			/*[out,retval]*/ VARIANT * ListIndex) = 0;
		virtual HRESULT __stdcall put_ListStyle(
		/*[in]*/ enum fmListStyle ListStyle) = 0;
		virtual HRESULT __stdcall get_ListStyle(
		/*[out,retval]*/ enum fmListStyle * ListStyle) = 0;
		virtual HRESULT __stdcall put_ListWidth(
			/*[in]*/ VARIANT * ListWidth) = 0;
		virtual HRESULT __stdcall get_ListWidth(
			/*[out,retval]*/ VARIANT * ListWidth) = 0;
		virtual HRESULT __stdcall put_Locked(
			/*[in]*/ VARIANT_BOOL Locked) = 0;
		virtual HRESULT __stdcall get_Locked(
			/*[out,retval]*/ VARIANT_BOOL * Locked) = 0;
		virtual HRESULT __stdcall put_MatchEntry(
		/*[in]*/ enum fmMatchEntry MatchEntry) = 0;
		virtual HRESULT __stdcall get_MatchEntry(
		/*[out,retval]*/ enum fmMatchEntry * MatchEntry) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_MultiSelect(
		/*[in]*/ enum fmMultiSelect MultiSelect) = 0;
		virtual HRESULT __stdcall get_MultiSelect(
		/*[out,retval]*/ enum fmMultiSelect * MultiSelect) = 0;
		virtual HRESULT __stdcall put_SpecialEffect(
		/*[in]*/ enum fmSpecialEffect SpecialEffect) = 0;
		virtual HRESULT __stdcall get_SpecialEffect(
		/*[out,retval]*/ enum fmSpecialEffect * SpecialEffect) = 0;
		virtual HRESULT __stdcall put_Text(
			/*[in]*/ BSTR Text) = 0;
		virtual HRESULT __stdcall get_Text(
			/*[out,retval]*/ BSTR * Text) = 0;
		virtual HRESULT __stdcall put_TextColumn(
			/*[in]*/ VARIANT * TextColumn) = 0;
		virtual HRESULT __stdcall get_TextColumn(
			/*[out,retval]*/ VARIANT * TextColumn) = 0;
		virtual HRESULT __stdcall put_TopIndex(
			/*[in]*/ VARIANT * TopIndex) = 0;
		virtual HRESULT __stdcall get_TopIndex(
			/*[out,retval]*/ VARIANT * TopIndex) = 0;
		virtual HRESULT __stdcall get_Valid(
			/*[out,retval]*/ VARIANT_BOOL * Valid) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall get_Column(
			/*[in]*/ VARIANT * pvargColumn,
			/*[in]*/ VARIANT * pvargIndex,
			/*[out,retval]*/ VARIANT * pvargValue) = 0;
		virtual HRESULT __stdcall put_Column(
			/*[in]*/ VARIANT * pvargColumn,
			/*[in]*/ VARIANT * pvargIndex = &vtMissing,
			/*[in]*/ VARIANT * pvargValue = &vtMissing) = 0;
		virtual HRESULT __stdcall get_List(
			/*[in]*/ VARIANT * pvargIndex,
			/*[in]*/ VARIANT * pvargColumn,
			/*[out,retval]*/ VARIANT * pvargValue) = 0;
		virtual HRESULT __stdcall put_List(
			/*[in]*/ VARIANT * pvargIndex,
			/*[in]*/ VARIANT * pvargColumn = &vtMissing,
			/*[in]*/ VARIANT * pvargValue = &vtMissing) = 0;
		virtual HRESULT __stdcall get_Selected(
			/*[in]*/ VARIANT * pvargIndex,
			/*[out,retval]*/ VARIANT_BOOL * pfvb) = 0;
		virtual HRESULT __stdcall put_Selected(
			/*[in]*/ VARIANT * pvargIndex,
			/*[in]*/ VARIANT_BOOL pfvb) = 0;
		virtual HRESULT __stdcall AddItem(
			/*[in]*/ VARIANT * pvargItem = &vtMissing,
			/*[in]*/ VARIANT * pvargIndex = &vtMissing) = 0;
		virtual HRESULT __stdcall Clear() = 0;
		virtual HRESULT __stdcall RemoveItem(
			/*[in]*/ VARIANT * pvargIndex) = 0;
		virtual HRESULT __stdcall put_IMEMode(
		/*[in]*/ enum fmIMEMode IMEMode) = 0;
		virtual HRESULT __stdcall get_IMEMode(
		/*[out,retval]*/ enum fmIMEMode * IMEMode) = 0;
		virtual HRESULT __stdcall get_DisplayStyle(
		/*[out,retval]*/ enum fmDisplayStyle * DisplayStyle) = 0;
		virtual HRESULT __stdcall put_TextAlign(
		/*[in]*/ enum fmTextAlign TextAlign) = 0;
		virtual HRESULT __stdcall get_TextAlign(
		/*[out,retval]*/ enum fmTextAlign * TextAlign) = 0;
	};

	struct __declspec(uuid("8bd21d33-ec42-11ce-9e0d-00aa006002f3"))
		IMdcCombo : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_AutoSize(
			/*[in]*/ VARIANT_BOOL AutoSize) = 0;
		virtual HRESULT __stdcall get_AutoSize(
			/*[out,retval]*/ VARIANT_BOOL * AutoSize) = 0;
		virtual HRESULT __stdcall put_AutoTab(
			/*[in]*/ VARIANT_BOOL AutoTab) = 0;
		virtual HRESULT __stdcall get_AutoTab(
			/*[out,retval]*/ VARIANT_BOOL * AutoTab) = 0;
		virtual HRESULT __stdcall put_AutoWordSelect(
			/*[in]*/ VARIANT_BOOL AutoWordSelect) = 0;
		virtual HRESULT __stdcall get_AutoWordSelect(
			/*[out,retval]*/ VARIANT_BOOL * AutoWordSelect) = 0;
		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BackStyle(
		/*[in]*/ enum fmBackStyle BackStyle) = 0;
		virtual HRESULT __stdcall get_BackStyle(
		/*[out,retval]*/ enum fmBackStyle * BackStyle) = 0;
		virtual HRESULT __stdcall put_BorderColor(
			/*[in]*/ OLE_COLOR BorderColor) = 0;
		virtual HRESULT __stdcall get_BorderColor(
			/*[out,retval]*/ OLE_COLOR * BorderColor) = 0;
		virtual HRESULT __stdcall put_BorderStyle(
		/*[in]*/ enum fmBorderStyle BorderStyle) = 0;
		virtual HRESULT __stdcall get_BorderStyle(
		/*[out,retval]*/ enum fmBorderStyle * BorderStyle) = 0;
		virtual HRESULT __stdcall put_BordersSuppress(
			/*[in]*/ VARIANT_BOOL BordersSuppress) = 0;
		virtual HRESULT __stdcall get_BordersSuppress(
			/*[out,retval]*/ VARIANT_BOOL * BordersSuppress) = 0;
		virtual HRESULT __stdcall put_BoundColumn(
			/*[in]*/ VARIANT * BoundColumn) = 0;
		virtual HRESULT __stdcall get_BoundColumn(
			/*[out,retval]*/ VARIANT * BoundColumn) = 0;
		virtual HRESULT __stdcall get_CanPaste(
			/*[out,retval]*/ VARIANT_BOOL * CanPaste) = 0;
		virtual HRESULT __stdcall put_ColumnCount(
			/*[in]*/ long ColumnCount) = 0;
		virtual HRESULT __stdcall get_ColumnCount(
			/*[out,retval]*/ long * ColumnCount) = 0;
		virtual HRESULT __stdcall put_ColumnHeads(
			/*[in]*/ VARIANT_BOOL ColumnHeads) = 0;
		virtual HRESULT __stdcall get_ColumnHeads(
			/*[out,retval]*/ VARIANT_BOOL * ColumnHeads) = 0;
		virtual HRESULT __stdcall put_ColumnWidths(
			/*[in]*/ BSTR ColumnWidths) = 0;
		virtual HRESULT __stdcall get_ColumnWidths(
			/*[out,retval]*/ BSTR * ColumnWidths) = 0;
		virtual HRESULT __stdcall get_CurTargetX(
			/*[out,retval]*/ long * CurTargetX) = 0;
		virtual HRESULT __stdcall get_CurTargetY(
			/*[out,retval]*/ long * CurTargetY) = 0;
		virtual HRESULT __stdcall put_CurX(
			/*[in]*/ long CurX) = 0;
		virtual HRESULT __stdcall get_CurX(
			/*[out,retval]*/ long * CurX) = 0;
		virtual HRESULT __stdcall put_DropButtonStyle(
		/*[in]*/ enum fmDropButtonStyle DropButtonStyle) = 0;
		virtual HRESULT __stdcall get_DropButtonStyle(
		/*[out,retval]*/ enum fmDropButtonStyle * DropButtonStyle) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL FontBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * FontBold) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL FontItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * FontItalic) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY FontSize) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * FontSize) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL FontStrikethru) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * FontStrikethru) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL FontUnderline) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * FontUnderline) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_HideSelection(
			/*[in]*/ VARIANT_BOOL HideSelection) = 0;
		virtual HRESULT __stdcall get_HideSelection(
			/*[out,retval]*/ VARIANT_BOOL * HideSelection) = 0;
		virtual HRESULT __stdcall get_LineCount(
			/*[out,retval]*/ long * LineCount) = 0;
		virtual HRESULT __stdcall get_ListCount(
			/*[out,retval]*/ long * ListCount) = 0;
		virtual HRESULT __stdcall put_ListCursor(
			/*[in]*/ PIROWSET ListCursor) = 0;
		virtual HRESULT __stdcall get_ListCursor(
			/*[out,retval]*/ PIROWSET * ListCursor) = 0;
		virtual HRESULT __stdcall put_ListIndex(
			/*[in]*/ VARIANT * ListIndex) = 0;
		virtual HRESULT __stdcall get_ListIndex(
			/*[out,retval]*/ VARIANT * ListIndex) = 0;
		virtual HRESULT __stdcall put_ListRows(
			/*[in]*/ long ListRows) = 0;
		virtual HRESULT __stdcall get_ListRows(
			/*[out,retval]*/ long * ListRows) = 0;
		virtual HRESULT __stdcall put_ListStyle(
		/*[in]*/ enum fmListStyle ListStyle) = 0;
		virtual HRESULT __stdcall get_ListStyle(
		/*[out,retval]*/ enum fmListStyle * ListStyle) = 0;
		virtual HRESULT __stdcall put_ListWidth(
			/*[in]*/ VARIANT * ListWidth) = 0;
		virtual HRESULT __stdcall get_ListWidth(
			/*[out,retval]*/ VARIANT * ListWidth) = 0;
		virtual HRESULT __stdcall put_Locked(
			/*[in]*/ VARIANT_BOOL Locked) = 0;
		virtual HRESULT __stdcall get_Locked(
			/*[out,retval]*/ VARIANT_BOOL * Locked) = 0;
		virtual HRESULT __stdcall put_MatchEntry(
		/*[in]*/ enum fmMatchEntry MatchEntry) = 0;
		virtual HRESULT __stdcall get_MatchEntry(
		/*[out,retval]*/ enum fmMatchEntry * MatchEntry) = 0;
		virtual HRESULT __stdcall get_MatchFound(
			/*[out,retval]*/ VARIANT_BOOL * MatchFound) = 0;
		virtual HRESULT __stdcall put_MatchRequired(
			/*[in]*/ VARIANT_BOOL MatchRequired) = 0;
		virtual HRESULT __stdcall get_MatchRequired(
			/*[out,retval]*/ VARIANT_BOOL * MatchRequired) = 0;
		virtual HRESULT __stdcall put_MaxLength(
			/*[in]*/ long MaxLength) = 0;
		virtual HRESULT __stdcall get_MaxLength(
			/*[out,retval]*/ long * MaxLength) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_SelectionMargin(
			/*[in]*/ VARIANT_BOOL SelectionMargin) = 0;
		virtual HRESULT __stdcall get_SelectionMargin(
			/*[out,retval]*/ VARIANT_BOOL * SelectionMargin) = 0;
		virtual HRESULT __stdcall put_SelLength(
			/*[in]*/ long SelLength) = 0;
		virtual HRESULT __stdcall get_SelLength(
			/*[out,retval]*/ long * SelLength) = 0;
		virtual HRESULT __stdcall put_SelStart(
			/*[in]*/ long SelStart) = 0;
		virtual HRESULT __stdcall get_SelStart(
			/*[out,retval]*/ long * SelStart) = 0;
		virtual HRESULT __stdcall put_SelText(
			/*[in]*/ BSTR SelText) = 0;
		virtual HRESULT __stdcall get_SelText(
			/*[out,retval]*/ BSTR * SelText) = 0;
		virtual HRESULT __stdcall put_ShowDropButtonWhen(
		/*[in]*/ enum fmShowDropButtonWhen ShowDropButtonWhen) = 0;
		virtual HRESULT __stdcall get_ShowDropButtonWhen(
		/*[out,retval]*/ enum fmShowDropButtonWhen * ShowDropButtonWhen) = 0;
		virtual HRESULT __stdcall put_SpecialEffect(
		/*[in]*/ enum fmSpecialEffect SpecialEffect) = 0;
		virtual HRESULT __stdcall get_SpecialEffect(
		/*[out,retval]*/ enum fmSpecialEffect * SpecialEffect) = 0;
		virtual HRESULT __stdcall put_Style(
		/*[in]*/ enum fmStyle Style) = 0;
		virtual HRESULT __stdcall get_Style(
		/*[out,retval]*/ enum fmStyle * Style) = 0;
		virtual HRESULT __stdcall put_Text(
			/*[in]*/ BSTR Text) = 0;
		virtual HRESULT __stdcall get_Text(
			/*[out,retval]*/ BSTR * Text) = 0;
		virtual HRESULT __stdcall put_TextAlign(
		/*[in]*/ enum fmTextAlign TextAlign) = 0;
		virtual HRESULT __stdcall get_TextAlign(
		/*[out,retval]*/ enum fmTextAlign * TextAlign) = 0;
		virtual HRESULT __stdcall put_TextColumn(
			/*[in]*/ VARIANT * TextColumn) = 0;
		virtual HRESULT __stdcall get_TextColumn(
			/*[out,retval]*/ VARIANT * TextColumn) = 0;
		virtual HRESULT __stdcall get_TextLength(
			/*[out,retval]*/ long * TextLength) = 0;
		virtual HRESULT __stdcall put_TopIndex(
			/*[in]*/ VARIANT * TopIndex) = 0;
		virtual HRESULT __stdcall get_TopIndex(
			/*[out,retval]*/ VARIANT * TopIndex) = 0;
		virtual HRESULT __stdcall get_Valid(
			/*[out,retval]*/ VARIANT_BOOL * Valid) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall get_Column(
			/*[in]*/ VARIANT * pvargColumn,
			/*[in]*/ VARIANT * pvargIndex,
			/*[out,retval]*/ VARIANT * pvargValue) = 0;
		virtual HRESULT __stdcall put_Column(
			/*[in]*/ VARIANT * pvargColumn,
			/*[in]*/ VARIANT * pvargIndex = &vtMissing,
			/*[in]*/ VARIANT * pvargValue = &vtMissing) = 0;
		virtual HRESULT __stdcall get_List(
			/*[in]*/ VARIANT * pvargIndex,
			/*[in]*/ VARIANT * pvargColumn,
			/*[out,retval]*/ VARIANT * pvargValue) = 0;
		virtual HRESULT __stdcall put_List(
			/*[in]*/ VARIANT * pvargIndex,
			/*[in]*/ VARIANT * pvargColumn = &vtMissing,
			/*[in]*/ VARIANT * pvargValue = &vtMissing) = 0;
		virtual HRESULT __stdcall AddItem(
			/*[in]*/ VARIANT * pvargItem = &vtMissing,
			/*[in]*/ VARIANT * pvargIndex = &vtMissing) = 0;
		virtual HRESULT __stdcall Clear() = 0;
		virtual HRESULT __stdcall DropDown() = 0;
		virtual HRESULT __stdcall RemoveItem(
			/*[in]*/ VARIANT * pvargIndex) = 0;
		virtual HRESULT __stdcall Copy() = 0;
		virtual HRESULT __stdcall Cut() = 0;
		virtual HRESULT __stdcall Paste() = 0;
		virtual HRESULT __stdcall put_IMEMode(
		/*[in]*/ enum fmIMEMode IMEMode) = 0;
		virtual HRESULT __stdcall get_IMEMode(
		/*[out,retval]*/ enum fmIMEMode * IMEMode) = 0;
		virtual HRESULT __stdcall put_EnterFieldBehavior(
		/*[in]*/ enum fmEnterFieldBehavior EnterFieldBehavior) = 0;
		virtual HRESULT __stdcall get_EnterFieldBehavior(
		/*[out,retval]*/ enum fmEnterFieldBehavior * EnterFieldBehavior) = 0;
		virtual HRESULT __stdcall put_DragBehavior(
		/*[in]*/ enum fmDragBehavior DragBehavior) = 0;
		virtual HRESULT __stdcall get_DragBehavior(
		/*[out,retval]*/ enum fmDragBehavior * DragBehavior) = 0;
		virtual HRESULT __stdcall get_DisplayStyle(
		/*[out,retval]*/ enum fmDisplayStyle * DisplayStyle) = 0;
	};

	struct __declspec(uuid("8bd21d43-ec42-11ce-9e0d-00aa006002f3"))
		IMdcCheckBox : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Accelerator(
			/*[in]*/ BSTR Accelerator) = 0;
		virtual HRESULT __stdcall get_Accelerator(
			/*[out,retval]*/ BSTR * Accelerator) = 0;
		virtual HRESULT __stdcall put_Alignment(
		/*[in]*/ enum fmAlignment Alignment) = 0;
		virtual HRESULT __stdcall get_Alignment(
		/*[out,retval]*/ enum fmAlignment * Alignment) = 0;
		virtual HRESULT __stdcall put_AutoSize(
			/*[in]*/ VARIANT_BOOL AutoSize) = 0;
		virtual HRESULT __stdcall get_AutoSize(
			/*[out,retval]*/ VARIANT_BOOL * AutoSize) = 0;
		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BackStyle(
		/*[in]*/ enum fmBackStyle BackStyle) = 0;
		virtual HRESULT __stdcall get_BackStyle(
		/*[out,retval]*/ enum fmBackStyle * BackStyle) = 0;
		virtual HRESULT __stdcall put_BordersSuppress(
			/*[in]*/ VARIANT_BOOL BordersSuppress) = 0;
		virtual HRESULT __stdcall get_BordersSuppress(
			/*[out,retval]*/ VARIANT_BOOL * BordersSuppress) = 0;
		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR Caption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * Caption) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL FontBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * FontBold) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL FontItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * FontItalic) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY FontSize) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * FontSize) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL FontStrikethru) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * FontStrikethru) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL FontUnderline) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * FontUnderline) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_Locked(
			/*[in]*/ VARIANT_BOOL Locked) = 0;
		virtual HRESULT __stdcall get_Locked(
			/*[out,retval]*/ VARIANT_BOOL * Locked) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_MultiSelect(
		/*[in]*/ enum fmMultiSelect MultiSelect) = 0;
		virtual HRESULT __stdcall get_MultiSelect(
		/*[out,retval]*/ enum fmMultiSelect * MultiSelect) = 0;
		virtual HRESULT __stdcall put_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall putref_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall get_Picture(
		/*[out,retval]*/ struct Picture * * Picture) = 0;
		virtual HRESULT __stdcall put_PicturePosition(
		/*[in]*/ enum fmPicturePosition PicPos) = 0;
		virtual HRESULT __stdcall get_PicturePosition(
		/*[out,retval]*/ enum fmPicturePosition * PicPos) = 0;
		virtual HRESULT __stdcall put_SpecialEffect(
		/*[in]*/ enum fmButtonEffect SpecialEffect) = 0;
		virtual HRESULT __stdcall get_SpecialEffect(
		/*[out,retval]*/ enum fmButtonEffect * SpecialEffect) = 0;
		virtual HRESULT __stdcall put_TripleState(
			/*[in]*/ VARIANT_BOOL TripleState) = 0;
		virtual HRESULT __stdcall get_TripleState(
			/*[out,retval]*/ VARIANT_BOOL * TripleState) = 0;
		virtual HRESULT __stdcall get_Valid(
			/*[out,retval]*/ VARIANT_BOOL * Valid) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ VARIANT * Value) = 0;
		virtual HRESULT __stdcall put_WordWrap(
			/*[in]*/ VARIANT_BOOL WordWrap) = 0;
		virtual HRESULT __stdcall get_WordWrap(
			/*[out,retval]*/ VARIANT_BOOL * WordWrap) = 0;
		virtual HRESULT __stdcall get_DisplayStyle(
		/*[out,retval]*/ enum fmDisplayStyle * DisplayStyle) = 0;
		virtual HRESULT __stdcall put_GroupName(
			/*[in]*/ BSTR GroupName) = 0;
		virtual HRESULT __stdcall get_GroupName(
			/*[out,retval]*/ BSTR * GroupName) = 0;
		virtual HRESULT __stdcall put_TextAlign(
		/*[in]*/ enum fmTextAlign TextAlign) = 0;
		virtual HRESULT __stdcall get_TextAlign(
		/*[out,retval]*/ enum fmTextAlign * TextAlign) = 0;
	};

	struct __declspec(uuid("8bd21d53-ec42-11ce-9e0d-00aa006002f3"))
		IMdcOptionButton : IMdcCheckBox
	{};

	struct __declspec(uuid("8bd21d63-ec42-11ce-9e0d-00aa006002f3"))
		IMdcToggleButton : IMdcCheckBox
	{};

	struct __declspec(uuid("04598fc3-866c-11cf-ab7c-00aa00c08fcf"))
		IScrollbar : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ long Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ long * Value) = 0;
		virtual HRESULT __stdcall put_Min(
			/*[in]*/ long Min) = 0;
		virtual HRESULT __stdcall get_Min(
			/*[out,retval]*/ long * Min) = 0;
		virtual HRESULT __stdcall put_Max(
			/*[in]*/ long Max) = 0;
		virtual HRESULT __stdcall get_Max(
			/*[out,retval]*/ long * Max) = 0;
		virtual HRESULT __stdcall put_SmallChange(
			/*[in]*/ long SmallChange) = 0;
		virtual HRESULT __stdcall get_SmallChange(
			/*[out,retval]*/ long * SmallChange) = 0;
		virtual HRESULT __stdcall put_LargeChange(
			/*[in]*/ long LargeChange) = 0;
		virtual HRESULT __stdcall get_LargeChange(
			/*[out,retval]*/ long * LargeChange) = 0;
		virtual HRESULT __stdcall put_ProportionalThumb(
			/*[in]*/ VARIANT_BOOL ProportionalThumb) = 0;
		virtual HRESULT __stdcall get_ProportionalThumb(
			/*[out,retval]*/ VARIANT_BOOL * ProportionalThumb) = 0;
		virtual HRESULT __stdcall put_Orientation(
		/*[in]*/ enum fmOrientation Orientation) = 0;
		virtual HRESULT __stdcall get_Orientation(
		/*[out,retval]*/ enum fmOrientation * Orientation) = 0;
		virtual HRESULT __stdcall put_Delay(
			/*[in]*/ long Delay) = 0;
		virtual HRESULT __stdcall get_Delay(
			/*[out,retval]*/ long * Delay) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
	};

	struct __declspec(uuid("a38bffc3-a5a0-11ce-8107-00aa00611080"))
		Tab : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR Caption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * Caption) = 0;
		virtual HRESULT __stdcall put_ControlTipText(
			/*[in]*/ BSTR ControlTipText) = 0;
		virtual HRESULT __stdcall get_ControlTipText(
			/*[out,retval]*/ BSTR * ControlTipText) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL fEnabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * fEnabled) = 0;
		virtual HRESULT __stdcall put_Index(
			/*[in]*/ long Index) = 0;
		virtual HRESULT __stdcall get_Index(
			/*[out,retval]*/ long * Index) = 0;
		virtual HRESULT __stdcall put_Name(
			/*[in]*/ BSTR Name) = 0;
		virtual HRESULT __stdcall get_Name(
			/*[out,retval]*/ BSTR * Name) = 0;
		virtual HRESULT __stdcall put_Tag(
			/*[in]*/ BSTR Tag) = 0;
		virtual HRESULT __stdcall get_Tag(
			/*[out,retval]*/ BSTR * Tag) = 0;
		virtual HRESULT __stdcall put_Visible(
			/*[in]*/ VARIANT_BOOL Visible) = 0;
		virtual HRESULT __stdcall get_Visible(
			/*[out,retval]*/ VARIANT_BOOL * Visible) = 0;
		virtual HRESULT __stdcall put_Accelerator(
			/*[in]*/ BSTR Accelerator) = 0;
		virtual HRESULT __stdcall get_Accelerator(
			/*[out,retval]*/ BSTR * Accelerator) = 0;
	};

	struct __declspec(uuid("944acf93-a1e6-11ce-8104-00aa00611080"))
		Tabs : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_Count(
			/*[out,retval]*/ long * Count) = 0;
		virtual HRESULT __stdcall get__NewEnum(
			/*[out,retval]*/ IUnknown * * _NewEnum) = 0;
		virtual HRESULT __stdcall _GetItemByIndex(
			/*[in]*/ long lIndex,
		/*[out,retval]*/ struct Tab * * ppTab) = 0;
		virtual HRESULT __stdcall _GetItemByName(
			/*[in]*/ BSTR bstr,
		/*[out,retval]*/ struct Tab * * ppTab) = 0;
		virtual HRESULT __stdcall Item(
			/*[in]*/ VARIANT varg,
			/*[out,retval]*/ IDispatch * * ppDisp) = 0;
		virtual HRESULT __stdcall Enum(
			/*[out,retval]*/ IUnknown * * ppEnum) = 0;
		virtual HRESULT __stdcall Add(
			/*[in]*/ VARIANT bstrName,
			/*[in]*/ VARIANT bstrCaption,
			/*[in]*/ VARIANT lIndex,
		/*[out,retval]*/ struct Tab * * ppTab) = 0;
		virtual HRESULT __stdcall _Add(
			/*[in]*/ BSTR bstrName,
			/*[in]*/ BSTR bstrCaption,
		/*[out,retval]*/ struct Tab * * ppTab) = 0;
		virtual HRESULT __stdcall _Insert(
			/*[in]*/ BSTR bstrName,
			/*[in]*/ BSTR bstrCaption,
			/*[in]*/ long lIndex,
		/*[out,retval]*/ struct Tab * * ppTab) = 0;
		virtual HRESULT __stdcall Remove(
			/*[in]*/ VARIANT varg) = 0;
		virtual HRESULT __stdcall Clear() = 0;
	};

	struct __declspec(uuid("04598fc2-866c-11cf-ab7c-00aa00c08fcf"))
		ITabStrip : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL FontBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * FontBold) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL FontItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * FontItalic) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL FontUnder) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * FontUnder) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL FontStrike) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * FontStrike) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY FontSize) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * FontSize) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL fnabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * fnabled) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_MultiRow(
			/*[in]*/ VARIANT_BOOL MultiRow) = 0;
		virtual HRESULT __stdcall get_MultiRow(
			/*[out,retval]*/ VARIANT_BOOL * MultiRow) = 0;
		virtual HRESULT __stdcall put_Style(
		/*[in]*/ enum fmTabStyle TabStyle) = 0;
		virtual HRESULT __stdcall get_Style(
		/*[out,retval]*/ enum fmTabStyle * TabStyle) = 0;
		virtual HRESULT __stdcall put_TabOrientation(
		/*[in]*/ enum fmTabOrientation TabOrientation) = 0;
		virtual HRESULT __stdcall get_TabOrientation(
		/*[out,retval]*/ enum fmTabOrientation * TabOrientation) = 0;
		virtual HRESULT __stdcall _SetTabFixedWidth(
			/*[in]*/ long TabFixedWidth) = 0;
		virtual HRESULT __stdcall _GetTabFixedWidth(
			/*[out]*/ long * TabFixedWidth) = 0;
		virtual HRESULT __stdcall _SetTabFixedHeight(
			/*[in]*/ long TabFixedHeight) = 0;
		virtual HRESULT __stdcall _GetTabFixedHeight(
			/*[out]*/ long * TabFixedHeight) = 0;
		virtual HRESULT __stdcall _GetClientTop(
			/*[out]*/ long * ClientTop) = 0;
		virtual HRESULT __stdcall get_ClientTop(
			/*[out,retval]*/ float * ClientTop) = 0;
		virtual HRESULT __stdcall _GetClientLeft(
			/*[out]*/ long * ClientLeft) = 0;
		virtual HRESULT __stdcall get_ClientLeft(
			/*[out,retval]*/ float * ClientLeft) = 0;
		virtual HRESULT __stdcall _GetClientWidth(
			/*[out]*/ long * ClientWidth) = 0;
		virtual HRESULT __stdcall get_ClientWidth(
			/*[out,retval]*/ float * ClientWidth) = 0;
		virtual HRESULT __stdcall _GetClientHeight(
			/*[out]*/ long * ClientHeight) = 0;
		virtual HRESULT __stdcall get_ClientHeight(
			/*[out,retval]*/ float * ClientHeight) = 0;
		virtual HRESULT __stdcall get_Tabs(
		/*[out,retval]*/ struct Tabs * * Tabs) = 0;
		virtual HRESULT __stdcall get_SelectedItem(
		/*[out,retval]*/ struct Tab * * ActiveTab) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ long Index) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ long * Index) = 0;
		virtual HRESULT __stdcall put_TabFixedWidth(
			/*[in]*/ float TabFixedWidth) = 0;
		virtual HRESULT __stdcall get_TabFixedWidth(
			/*[out,retval]*/ float * TabFixedWidth) = 0;
		virtual HRESULT __stdcall put_TabFixedHeight(
			/*[in]*/ float TabFixedHeight) = 0;
		virtual HRESULT __stdcall get_TabFixedHeight(
			/*[out,retval]*/ float * TabFixedHeight) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
	};

	struct __declspec(uuid("79176fb3-b7f2-11ce-97ef-00aa006d2776"))
		ISpinbutton : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR ForeColor) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * ForeColor) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ long Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ long * Value) = 0;
		virtual HRESULT __stdcall put_Min(
			/*[in]*/ long Min) = 0;
		virtual HRESULT __stdcall get_Min(
			/*[out,retval]*/ long * Min) = 0;
		virtual HRESULT __stdcall put_Max(
			/*[in]*/ long Max) = 0;
		virtual HRESULT __stdcall get_Max(
			/*[out,retval]*/ long * Max) = 0;
		virtual HRESULT __stdcall put_SmallChange(
			/*[in]*/ long SmallChange) = 0;
		virtual HRESULT __stdcall get_SmallChange(
			/*[out,retval]*/ long * SmallChange) = 0;
		virtual HRESULT __stdcall put_Orientation(
		/*[in]*/ enum fmOrientation Orientation) = 0;
		virtual HRESULT __stdcall get_Orientation(
		/*[out,retval]*/ enum fmOrientation * Orientation) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_Delay(
			/*[in]*/ long Delay) = 0;
		virtual HRESULT __stdcall get_Delay(
			/*[out,retval]*/ long * Delay) = 0;
	};

	struct __declspec(uuid("4c599243-6926-101b-9992-00000b65c6f9"))
		IImage : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL fEnabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * fEnabled) = 0;
		virtual HRESULT __stdcall put_MousePointer(
		/*[in]*/ enum fmMousePointer MousePointer) = 0;
		virtual HRESULT __stdcall get_MousePointer(
		/*[out,retval]*/ enum fmMousePointer * MousePointer) = 0;
		virtual HRESULT __stdcall put_AutoSize(
			/*[in]*/ VARIANT_BOOL fAutoSize) = 0;
		virtual HRESULT __stdcall get_AutoSize(
			/*[out,retval]*/ VARIANT_BOOL * fAutoSize) = 0;
		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR BackColor) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * BackColor) = 0;
		virtual HRESULT __stdcall put_BackStyle(
		/*[in]*/ enum fmBackStyle BackStyle) = 0;
		virtual HRESULT __stdcall get_BackStyle(
		/*[out,retval]*/ enum fmBackStyle * BackStyle) = 0;
		virtual HRESULT __stdcall put_BorderColor(
			/*[in]*/ OLE_COLOR BorderColor) = 0;
		virtual HRESULT __stdcall get_BorderColor(
			/*[out,retval]*/ OLE_COLOR * BorderColor) = 0;
		virtual HRESULT __stdcall put_BorderStyle(
		/*[in]*/ enum fmBorderStyle Style) = 0;
		virtual HRESULT __stdcall get_BorderStyle(
		/*[out,retval]*/ enum fmBorderStyle * Style) = 0;
		virtual HRESULT __stdcall put_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall putref_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall get_Picture(
		/*[out,retval]*/ struct Picture * * Picture) = 0;
		virtual HRESULT __stdcall put_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall putref_MouseIcon(
		/*[in]*/ struct Picture * MouseIcon) = 0;
		virtual HRESULT __stdcall get_MouseIcon(
		/*[out,retval]*/ struct Picture * * MouseIcon) = 0;
		virtual HRESULT __stdcall put_PictureSizeMode(
		/*[in]*/ enum fmPictureSizeMode PictureSizeMode) = 0;
		virtual HRESULT __stdcall get_PictureSizeMode(
		/*[out,retval]*/ enum fmPictureSizeMode * PictureSizeMode) = 0;
		virtual HRESULT __stdcall put_PictureAlignment(
		/*[in]*/ enum fmPictureAlignment PictureAlignment) = 0;
		virtual HRESULT __stdcall get_PictureAlignment(
		/*[out,retval]*/ enum fmPictureAlignment * PictureAlignment) = 0;
		virtual HRESULT __stdcall put_PictureTiling(
			/*[in]*/ VARIANT_BOOL PictureTiling) = 0;
		virtual HRESULT __stdcall get_PictureTiling(
			/*[out,retval]*/ VARIANT_BOOL * PictureTiling) = 0;
		virtual HRESULT __stdcall put_SpecialEffect(
		/*[in]*/ enum fmSpecialEffect SpecialEffect) = 0;
		virtual HRESULT __stdcall get_SpecialEffect(
		/*[out,retval]*/ enum fmSpecialEffect * SpecialEffect) = 0;
	};

	struct __declspec(uuid("5512d111-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLSubmitButton : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Action(
			/*[in]*/ BSTR Action) = 0;
		virtual HRESULT __stdcall get_Action(
			/*[out,retval]*/ BSTR * Action) = 0;
		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR Caption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * Caption) = 0;
		virtual HRESULT __stdcall put_Encoding(
			/*[in]*/ BSTR Encoding) = 0;
		virtual HRESULT __stdcall get_Encoding(
			/*[out,retval]*/ BSTR * Encoding) = 0;
		virtual HRESULT __stdcall put_Method(
			/*[in]*/ BSTR Method) = 0;
		virtual HRESULT __stdcall get_Method(
			/*[out,retval]*/ BSTR * Method) = 0;
		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
	};

	struct __declspec(uuid("5512d113-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLImage : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Action(
			/*[in]*/ BSTR Action) = 0;
		virtual HRESULT __stdcall get_Action(
			/*[out,retval]*/ BSTR * Action) = 0;
		virtual HRESULT __stdcall put_Source(
			/*[in]*/ BSTR Source) = 0;
		virtual HRESULT __stdcall get_Source(
			/*[out,retval]*/ BSTR * Source) = 0;
		virtual HRESULT __stdcall put_Encoding(
			/*[in]*/ BSTR Encoding) = 0;
		virtual HRESULT __stdcall get_Encoding(
			/*[out,retval]*/ BSTR * Encoding) = 0;
		virtual HRESULT __stdcall put_Method(
			/*[in]*/ BSTR Method) = 0;
		virtual HRESULT __stdcall get_Method(
			/*[out,retval]*/ BSTR * Method) = 0;
		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
	};

	struct __declspec(uuid("5512d115-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLReset : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR Caption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * Caption) = 0;
		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
	};

	struct __declspec(uuid("5512d117-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLCheckbox : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ BSTR Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ BSTR * Value) = 0;
		virtual HRESULT __stdcall put_Checked(
			/*[in]*/ VARIANT_BOOL Checked) = 0;
		virtual HRESULT __stdcall get_Checked(
			/*[out,retval]*/ VARIANT_BOOL * Checked) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
	};

	struct __declspec(uuid("5512d119-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLOption : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ BSTR Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ BSTR * Value) = 0;
		virtual HRESULT __stdcall put_Checked(
			/*[in]*/ VARIANT_BOOL Checked) = 0;
		virtual HRESULT __stdcall get_Checked(
			/*[out,retval]*/ VARIANT_BOOL * Checked) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
		virtual HRESULT __stdcall get_DisplayStyle(
		/*[out,retval]*/ enum fmDisplayStyle * DisplayStyle) = 0;
	};

	struct __declspec(uuid("5512d11b-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLText : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ BSTR Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ BSTR * Value) = 0;
		virtual HRESULT __stdcall put_MaxLength(
			/*[in]*/ long MaxLength) = 0;
		virtual HRESULT __stdcall get_MaxLength(
			/*[out,retval]*/ long * MaxLength) = 0;
		virtual HRESULT __stdcall put_Width(
			/*[in]*/ long Width) = 0;
		virtual HRESULT __stdcall get_Width(
			/*[out,retval]*/ long * Width) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
	};

	struct __declspec(uuid("5512d11d-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLHidden : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ BSTR Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ BSTR * Value) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
	};

	struct __declspec(uuid("5512d11f-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLPassword : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ BSTR Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ BSTR * Value) = 0;
		virtual HRESULT __stdcall put_MaxLength(
			/*[in]*/ long MaxLength) = 0;
		virtual HRESULT __stdcall get_MaxLength(
			/*[out,retval]*/ long * MaxLength) = 0;
		virtual HRESULT __stdcall put_Width(
			/*[in]*/ long Width) = 0;
		virtual HRESULT __stdcall get_Width(
			/*[out,retval]*/ long * Width) = 0;
		virtual HRESULT __stdcall put_HTMLType(
			/*[in]*/ BSTR HTMLType) = 0;
		virtual HRESULT __stdcall get_HTMLType(
			/*[out,retval]*/ BSTR * HTMLType) = 0;
	};

	struct __declspec(uuid("5512d123-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLSelect : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_Values(
			/*[in]*/ VARIANT * Values) = 0;
		virtual HRESULT __stdcall get_Values(
			/*[out,retval]*/ VARIANT * Values) = 0;
		virtual HRESULT __stdcall put_DisplayValues(
			/*[in]*/ VARIANT * DisplayValues) = 0;
		virtual HRESULT __stdcall get_DisplayValues(
			/*[out,retval]*/ VARIANT * DisplayValues) = 0;
		virtual HRESULT __stdcall put_Selected(
			/*[in]*/ BSTR Selected) = 0;
		virtual HRESULT __stdcall get_Selected(
			/*[out,retval]*/ BSTR * Selected) = 0;
		virtual HRESULT __stdcall put_MultiSelect(
			/*[in]*/ VARIANT_BOOL MultiSelect) = 0;
		virtual HRESULT __stdcall get_MultiSelect(
			/*[out,retval]*/ VARIANT_BOOL * MultiSelect) = 0;
		virtual HRESULT __stdcall put_Size(
			/*[in]*/ long Size) = 0;
		virtual HRESULT __stdcall get_Size(
			/*[out,retval]*/ long * Size) = 0;
	};

	struct __declspec(uuid("5512d125-5cc6-11cf-8d67-00aa00bdce1d"))
		IWHTMLTextArea : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_HTMLName(
			/*[in]*/ BSTR HTMLName) = 0;
		virtual HRESULT __stdcall get_HTMLName(
			/*[out,retval]*/ BSTR * HTMLName) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ BSTR Value) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ BSTR * Value) = 0;
		virtual HRESULT __stdcall put_Rows(
			/*[in]*/ long Rows) = 0;
		virtual HRESULT __stdcall get_Rows(
			/*[out,retval]*/ long * Rows) = 0;
		virtual HRESULT __stdcall put_Columns(
			/*[in]*/ long Columns) = 0;
		virtual HRESULT __stdcall get_Columns(
			/*[out,retval]*/ long * Columns) = 0;
		virtual HRESULT __stdcall put_WordWrap(
			/*[in]*/ BSTR WordWrap) = 0;
		virtual HRESULT __stdcall get_WordWrap(
			/*[out,retval]*/ BSTR * WordWrap) = 0;
	};

	struct __declspec(uuid("978c9e22-d4b0-11ce-bf2d-00aa003f40d0"))
		LabelControlEvents : IDispatch
	{};

	struct __declspec(uuid("978c9e23-d4b0-11ce-bf2d-00aa003f40d0"))
		Label;
	// [ default ] interface ILabelControl
	// [ default, source ] dispinterface LabelControlEvents

	struct __declspec(uuid("7b020ec1-af6c-11ce-9f46-00aa00574a4f"))
		CommandButtonEvents : IDispatch
	{};

	struct __declspec(uuid("d7053240-ce69-11cd-a777-00dd01143c57"))
		CommandButton;
	// [ default ] interface ICommandButton
	// [ default, source ] dispinterface CommandButtonEvents

	struct __declspec(uuid("8bd21d12-ec42-11ce-9e0d-00aa006002f3"))
		MdcTextEvents : IDispatch
	{};

	struct __declspec(uuid("8bd21d10-ec42-11ce-9e0d-00aa006002f3"))
		TextBox;
	// [ default ] interface IMdcText
	// [ default, source ] dispinterface MdcTextEvents

	struct __declspec(uuid("8bd21d22-ec42-11ce-9e0d-00aa006002f3"))
		MdcListEvents : IDispatch
	{};

	struct __declspec(uuid("8bd21d20-ec42-11ce-9e0d-00aa006002f3"))
		ListBox;
	// [ default ] interface IMdcList
	// [ default, source ] dispinterface MdcListEvents

	struct __declspec(uuid("8bd21d32-ec42-11ce-9e0d-00aa006002f3"))
		MdcComboEvents : IDispatch
	{};

	struct __declspec(uuid("8bd21d30-ec42-11ce-9e0d-00aa006002f3"))
		ComboBox;
	// [ default ] interface IMdcCombo
	// [ default, source ] dispinterface MdcComboEvents

	struct __declspec(uuid("8bd21d42-ec42-11ce-9e0d-00aa006002f3"))
		MdcCheckBoxEvents : IDispatch
	{};

	struct __declspec(uuid("8bd21d52-ec42-11ce-9e0d-00aa006002f3"))
		MdcOptionButtonEvents : IDispatch
	{};

	struct __declspec(uuid("8bd21d62-ec42-11ce-9e0d-00aa006002f3"))
		MdcToggleButtonEvents : IDispatch
	{};

	struct __declspec(uuid("8bd21d40-ec42-11ce-9e0d-00aa006002f3"))
		CheckBox;
	// [ default ] interface IMdcCheckBox
	// [ default, source ] dispinterface MdcCheckBoxEvents

	struct __declspec(uuid("8bd21d50-ec42-11ce-9e0d-00aa006002f3"))
		OptionButton;
	// [ default ] interface IMdcOptionButton
	// [ default, source ] dispinterface MdcOptionButtonEvents

	struct __declspec(uuid("8bd21d60-ec42-11ce-9e0d-00aa006002f3"))
		ToggleButton;
	// [ default ] interface IMdcToggleButton
	// [ default, source ] dispinterface MdcToggleButtonEvents

	struct __declspec(uuid("afc20920-da4e-11ce-b943-00aa006887b4"))
		NewFont;
	// interface IUnknown
	// [ default ] dispinterface Font

	struct __declspec(uuid("7b020ec2-af6c-11ce-9f46-00aa00574a4f"))
		ScrollbarEvents : IDispatch
	{};

	struct __declspec(uuid("dfd181e0-5e2f-11ce-a449-00aa004a803d"))
		ScrollBar;
	// [ default ] interface IScrollbar
	// [ default, source ] dispinterface ScrollbarEvents

	struct __declspec(uuid("7b020ec7-af6c-11ce-9f46-00aa00574a4f"))
		TabStripEvents : IDispatch
	{};

	struct __declspec(uuid("eae50eb0-4a62-11ce-bed6-00aa00611080"))
		TabStrip;
	// [ default ] interface ITabStrip
	// [ default, source ] dispinterface TabStripEvents

	struct __declspec(uuid("79176fb2-b7f2-11ce-97ef-00aa006d2776"))
		SpinbuttonEvents : IDispatch
	{};

	struct __declspec(uuid("79176fb0-b7f2-11ce-97ef-00aa006d2776"))
		SpinButton;
	// [ default ] interface ISpinbutton
	// [ default, source ] dispinterface SpinbuttonEvents

	struct __declspec(uuid("4c5992a5-6926-101b-9992-00000b65c6f9"))
		ImageEvents : IDispatch
	{};

	struct __declspec(uuid("4c599241-6926-101b-9992-00000b65c6f9"))
		Image;
	// [ default ] interface IImage
	// [ default, source ] dispinterface ImageEvents

	struct __declspec(uuid("796ed650-5fe9-11cf-8d68-00aa00bdce1d"))
		WHTMLControlEvents : IDispatch
	{};

	struct __declspec(uuid("47ff8fe0-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents1 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe1-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents2 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe2-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents3 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe3-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents4 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe4-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents5 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe5-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents6 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe6-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents7 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe8-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents9 : IDispatch
	{};

	struct __declspec(uuid("47ff8fe9-6198-11cf-8ce8-00aa006cb389"))
		WHTMLControlEvents10 : IDispatch
	{};

	struct __declspec(uuid("5512d110-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLSubmit;
	// [ default ] interface IWHTMLSubmitButton
	// [ default, source ] dispinterface WHTMLControlEvents

	struct __declspec(uuid("5512d112-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLImage;
	// [ default ] interface IWHTMLImage
	// [ default, source ] dispinterface WHTMLControlEvents1

	struct __declspec(uuid("5512d114-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLReset;
	// [ default ] interface IWHTMLReset
	// [ default, source ] dispinterface WHTMLControlEvents2

	struct __declspec(uuid("5512d116-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLCheckbox;
	// [ default ] interface IWHTMLCheckbox
	// [ default, source ] dispinterface WHTMLControlEvents3

	struct __declspec(uuid("5512d118-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLOption;
	// [ default ] interface IWHTMLOption
	// [ default, source ] dispinterface WHTMLControlEvents4

	struct __declspec(uuid("5512d11a-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLText;
	// [ default ] interface IWHTMLText
	// [ default, source ] dispinterface WHTMLControlEvents5

	struct __declspec(uuid("5512d11c-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLHidden;
	// [ default ] interface IWHTMLHidden
	// [ default, source ] dispinterface WHTMLControlEvents6

	struct __declspec(uuid("5512d11e-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLPassword;
	// [ default ] interface IWHTMLPassword
	// [ default, source ] dispinterface WHTMLControlEvents7

	struct __declspec(uuid("5512d122-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLSelect;
	// [ default ] interface IWHTMLSelect
	// [ default, source ] dispinterface WHTMLControlEvents9

	struct __declspec(uuid("5512d124-5cc6-11cf-8d67-00aa00bdce1d"))
		HTMLTextArea;
	// [ default ] interface IWHTMLTextArea
	// [ default, source ] dispinterface WHTMLControlEvents10

	enum __declspec(uuid("0ee49f40-e956-11ce-8141-00aa00611080"))
		fmTransitionEffect
	{
		fmTransitionEffectNone = 0,
		fmTransitionEffectCoverUp = 1,
		fmTransitionEffectCoverRightUp = 2,
		fmTransitionEffectCoverRight = 3,
		fmTransitionEffectCoverRightDown = 4,
		fmTransitionEffectCoverDown = 5,
		fmTransitionEffectCoverLeftDown = 6,
		fmTransitionEffectCoverLeft = 7,
		fmTransitionEffectCoverLeftUp = 8,
		fmTransitionEffectPushUp = 9,
		fmTransitionEffectPushRight = 10,
		fmTransitionEffectPushDown = 11,
		fmTransitionEffectPushLeft = 12
	};

	struct __declspec(uuid("5cef5613-713d-11ce-80c9-00aa00611080"))
		IPage : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_Controls(
		/*[out,retval]*/ struct Controls * * Controls) = 0;
		virtual HRESULT __stdcall get_Selected(
		/*[out,retval]*/ struct Controls * * Selected) = 0;
		virtual HRESULT __stdcall get_ActiveControl(
		/*[out,retval]*/ struct IControl * * ActiveControl) = 0;
		virtual HRESULT __stdcall get_CanPaste(
			/*[out,retval]*/ VARIANT_BOOL * CanPaste) = 0;
		virtual HRESULT __stdcall get_CanRedo(
			/*[out,retval]*/ VARIANT_BOOL * CanRedo) = 0;
		virtual HRESULT __stdcall get_CanUndo(
			/*[out,retval]*/ VARIANT_BOOL * CanUndo) = 0;
		virtual HRESULT __stdcall put_Cycle(
		/*[in]*/ enum fmCycle Cycle) = 0;
		virtual HRESULT __stdcall get_Cycle(
		/*[out,retval]*/ enum fmCycle * Cycle) = 0;
		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR Caption) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR * Caption) = 0;
		virtual HRESULT __stdcall put_ControlTipText(
			/*[in]*/ BSTR tooltip) = 0;
		virtual HRESULT __stdcall get_ControlTipText(
			/*[out,retval]*/ BSTR * tooltip) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL fEnabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * fEnabled) = 0;
		virtual HRESULT __stdcall put_Index(
			/*[in]*/ long Index) = 0;
		virtual HRESULT __stdcall get_Index(
			/*[out,retval]*/ long * Index) = 0;
		virtual HRESULT __stdcall _GetInsideHeight(
			/*[out]*/ long * InsideHeight) = 0;
		virtual HRESULT __stdcall get_InsideHeight(
			/*[out,retval]*/ float * InsideHeight) = 0;
		virtual HRESULT __stdcall _GetInsideWidth(
			/*[out]*/ long * InsideWidth) = 0;
		virtual HRESULT __stdcall get_InsideWidth(
			/*[out,retval]*/ float * InsideWidth) = 0;
		virtual HRESULT __stdcall put_KeepScrollBarsVisible(
		/*[in]*/ enum fmScrollBars ScrollBars) = 0;
		virtual HRESULT __stdcall get_KeepScrollBarsVisible(
		/*[out,retval]*/ enum fmScrollBars * ScrollBars) = 0;
		virtual HRESULT __stdcall put_Name(
			/*[in]*/ BSTR Name) = 0;
		virtual HRESULT __stdcall get_Name(
			/*[out,retval]*/ BSTR * Name) = 0;
		virtual HRESULT __stdcall put_PictureAlignment(
		/*[in]*/ enum fmPictureAlignment PictureAlignment) = 0;
		virtual HRESULT __stdcall get_PictureAlignment(
		/*[out,retval]*/ enum fmPictureAlignment * PictureAlignment) = 0;
		virtual HRESULT __stdcall put_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall putref_Picture(
		/*[in]*/ struct Picture * Picture) = 0;
		virtual HRESULT __stdcall get_Picture(
		/*[out,retval]*/ struct Picture * * Picture) = 0;
		virtual HRESULT __stdcall put_PictureSizeMode(
		/*[in]*/ enum fmPictureSizeMode PictureSizeMode) = 0;
		virtual HRESULT __stdcall get_PictureSizeMode(
		/*[out,retval]*/ enum fmPictureSizeMode * PictureSizeMode) = 0;
		virtual HRESULT __stdcall put_PictureTiling(
			/*[in]*/ VARIANT_BOOL PictureTiling) = 0;
		virtual HRESULT __stdcall get_PictureTiling(
			/*[out,retval]*/ VARIANT_BOOL * PictureTiling) = 0;
		virtual HRESULT __stdcall put_ScrollBars(
		/*[in]*/ enum fmScrollBars ScrollBars) = 0;
		virtual HRESULT __stdcall get_ScrollBars(
		/*[out,retval]*/ enum fmScrollBars * ScrollBars) = 0;
		virtual HRESULT __stdcall _SetScrollHeight(
			/*[in]*/ long ScrollHeight) = 0;
		virtual HRESULT __stdcall _GetScrollHeight(
			/*[out]*/ long * ScrollHeight) = 0;
		virtual HRESULT __stdcall put_ScrollHeight(
			/*[in]*/ float ScrollHeight) = 0;
		virtual HRESULT __stdcall get_ScrollHeight(
			/*[out,retval]*/ float * ScrollHeight) = 0;
		virtual HRESULT __stdcall _SetScrollLeft(
			/*[in]*/ long ScrollLeft) = 0;
		virtual HRESULT __stdcall _GetScrollLeft(
			/*[out]*/ long * ScrollLeft) = 0;
		virtual HRESULT __stdcall put_ScrollLeft(
			/*[in]*/ float ScrollLeft) = 0;
		virtual HRESULT __stdcall get_ScrollLeft(
			/*[out,retval]*/ float * ScrollLeft) = 0;
		virtual HRESULT __stdcall _SetScrollTop(
			/*[in]*/ long ScrollTop) = 0;
		virtual HRESULT __stdcall _GetScrollTop(
			/*[out]*/ long * ScrollTop) = 0;
		virtual HRESULT __stdcall put_ScrollTop(
			/*[in]*/ float ScrollTop) = 0;
		virtual HRESULT __stdcall get_ScrollTop(
			/*[out,retval]*/ float * ScrollTop) = 0;
		virtual HRESULT __stdcall _SetScrollWidth(
			/*[in]*/ long ScrollWidth) = 0;
		virtual HRESULT __stdcall _GetScrollWidth(
			/*[out]*/ long * ScrollWidth) = 0;
		virtual HRESULT __stdcall put_ScrollWidth(
			/*[in]*/ float ScrollWidth) = 0;
		virtual HRESULT __stdcall get_ScrollWidth(
			/*[out,retval]*/ float * ScrollWidth) = 0;
		virtual HRESULT __stdcall put_Tag(
			/*[in]*/ BSTR Tag) = 0;
		virtual HRESULT __stdcall get_Tag(
			/*[out,retval]*/ BSTR * Tag) = 0;
		virtual HRESULT __stdcall put_TransitionEffect(
		/*[in]*/ enum fmTransitionEffect TransitionEffect) = 0;
		virtual HRESULT __stdcall get_TransitionEffect(
		/*[out,retval]*/ enum fmTransitionEffect * TransitionEffect) = 0;
		virtual HRESULT __stdcall put_TransitionPeriod(
			/*[in]*/ long TransitionPeriod) = 0;
		virtual HRESULT __stdcall get_TransitionPeriod(
			/*[out,retval]*/ long * TransitionPeriod) = 0;
		virtual HRESULT __stdcall put_VerticalScrollBarSide(
		/*[in]*/ enum fmVerticalScrollBarSide side) = 0;
		virtual HRESULT __stdcall get_VerticalScrollBarSide(
		/*[out,retval]*/ enum fmVerticalScrollBarSide * side) = 0;
		virtual HRESULT __stdcall put_Visible(
			/*[in]*/ VARIANT_BOOL fVisible) = 0;
		virtual HRESULT __stdcall get_Visible(
			/*[out,retval]*/ VARIANT_BOOL * fVisible) = 0;
		virtual HRESULT __stdcall put_Zoom(
			/*[in]*/ short Zoom) = 0;
		virtual HRESULT __stdcall get_Zoom(
			/*[out,retval]*/ short * Zoom) = 0;
		virtual HRESULT __stdcall put_DesignMode(
		/*[in]*/ enum fmMode DesignMode) = 0;
		virtual HRESULT __stdcall get_DesignMode(
		/*[out,retval]*/ enum fmMode * DesignMode) = 0;
		virtual HRESULT __stdcall put_ShowToolbox(
		/*[in]*/ enum fmMode ShowToolbox) = 0;
		virtual HRESULT __stdcall get_ShowToolbox(
		/*[out,retval]*/ enum fmMode * ShowToolbox) = 0;
		virtual HRESULT __stdcall put_ShowGridDots(
		/*[in]*/ enum fmMode ShowGridDots) = 0;
		virtual HRESULT __stdcall get_ShowGridDots(
		/*[out,retval]*/ enum fmMode * ShowGridDots) = 0;
		virtual HRESULT __stdcall put_SnapToGrid(
		/*[in]*/ enum fmMode SnapToGrid) = 0;
		virtual HRESULT __stdcall get_SnapToGrid(
		/*[out,retval]*/ enum fmMode * SnapToGrid) = 0;
		virtual HRESULT __stdcall put_GridX(
			/*[in]*/ float GridX) = 0;
		virtual HRESULT __stdcall get_GridX(
			/*[out,retval]*/ float * GridX) = 0;
		virtual HRESULT __stdcall _SetGridX(
			/*[in]*/ long GridX) = 0;
		virtual HRESULT __stdcall _GetGridX(
			/*[out]*/ long * GridX) = 0;
		virtual HRESULT __stdcall put_GridY(
			/*[in]*/ float GridY) = 0;
		virtual HRESULT __stdcall get_GridY(
			/*[out,retval]*/ float * GridY) = 0;
		virtual HRESULT __stdcall _SetGridY(
			/*[in]*/ long GridY) = 0;
		virtual HRESULT __stdcall _GetGridY(
			/*[out]*/ long * GridY) = 0;
		virtual HRESULT __stdcall Copy() = 0;
		virtual HRESULT __stdcall Cut() = 0;
		virtual HRESULT __stdcall Paste() = 0;
		virtual HRESULT __stdcall RedoAction() = 0;
		virtual HRESULT __stdcall Repaint() = 0;
		virtual HRESULT __stdcall Scroll(
			/*[in]*/ VARIANT xAction = vtMissing,
			/*[in]*/ VARIANT yAction = vtMissing) = 0;
		virtual HRESULT __stdcall SetDefaultTabOrder() = 0;
		virtual HRESULT __stdcall UndoAction() = 0;
		virtual HRESULT __stdcall put_Accelerator(
			/*[in]*/ BSTR Accelerator) = 0;
		virtual HRESULT __stdcall get_Accelerator(
			/*[out,retval]*/ BSTR * Accelerator) = 0;
		virtual HRESULT __stdcall get_Parent(
			/*[out,retval]*/ IDispatch * * Parent) = 0;
	};

	struct __declspec(uuid("7b020ec8-af6c-11ce-9f46-00aa00574a4f"))
		MultiPageEvents : IDispatch
	{};

	struct __declspec(uuid("46e31370-3f7a-11ce-bed6-00aa00611080"))
		MultiPage;
	// [ default ] interface IMultiPage
	// [ default, source ] dispinterface MultiPageEvents

	struct __declspec(uuid("5cef5610-713d-11ce-80c9-00aa00611080"))
		Page;
	// [ default ] interface IPage

	struct __declspec(uuid("92e11a03-7358-11ce-80cb-00aa00611080"))
		Pages : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_Count(
			/*[out,retval]*/ long * plCount) = 0;
		virtual HRESULT __stdcall get__NewEnum(
			/*[out,retval]*/ IUnknown * * ppEnum) = 0;
		virtual HRESULT __stdcall Item(
			/*[in]*/ VARIANT varg,
			/*[out,retval]*/ IDispatch * * ppDisap) = 0;
		virtual HRESULT __stdcall Enum(
			/*[out,retval]*/ IUnknown * * ppEnum) = 0;
		virtual HRESULT __stdcall Add(
			/*[in]*/ VARIANT bstrName,
			/*[in]*/ VARIANT bstrCaption,
			/*[in]*/ VARIANT lIndex,
		/*[out,retval]*/ struct IPage * * ppPage) = 0;
		virtual HRESULT __stdcall _AddCtrl(
			/*[in]*/ long * clsid,
			/*[in]*/ BSTR bstrName,
			/*[in]*/ BSTR bstrCaption,
		/*[out,retval]*/ struct IPage * * ppPage) = 0;
		virtual HRESULT __stdcall _InsertCtrl(
			/*[in]*/ long * clsid,
			/*[in]*/ BSTR bstrName,
			/*[in]*/ BSTR bstrCaption,
			/*[in]*/ long lIndex,
		/*[out,retval]*/ struct IPage * * ppCtrl) = 0;
		virtual HRESULT __stdcall _GetItemByIndex(
			/*[in]*/ long lIndex,
		/*[out,retval]*/ struct IControl * * ppCtrl) = 0;
		virtual HRESULT __stdcall _GetItemByName(
			/*[in]*/ BSTR pstrName,
		/*[out,retval]*/ struct IControl * * ppCtrl) = 0;
		virtual HRESULT __stdcall Remove(
			/*[in]*/ VARIANT varg) = 0;
		virtual HRESULT __stdcall Clear() = 0;
	};

	struct __declspec(uuid("04598fc9-866c-11cf-ab7c-00aa00c08fcf"))
		IMultiPage : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_BackColor(
			/*[in]*/ OLE_COLOR color) = 0;
		virtual HRESULT __stdcall get_BackColor(
			/*[out,retval]*/ OLE_COLOR * color) = 0;
		virtual HRESULT __stdcall put_ForeColor(
			/*[in]*/ OLE_COLOR color) = 0;
		virtual HRESULT __stdcall get_ForeColor(
			/*[out,retval]*/ OLE_COLOR * color) = 0;
		virtual HRESULT __stdcall put__Font_Reserved(
		/*[in]*/ struct Font * _arg1) = 0;
		virtual HRESULT __stdcall putref_Font(
		/*[in]*/ struct Font * Font) = 0;
		virtual HRESULT __stdcall get_Font(
		/*[out,retval]*/ struct Font * * Font) = 0;
		virtual HRESULT __stdcall put_FontName(
			/*[in]*/ BSTR FontName) = 0;
		virtual HRESULT __stdcall get_FontName(
			/*[out,retval]*/ BSTR * FontName) = 0;
		virtual HRESULT __stdcall put_FontBold(
			/*[in]*/ VARIANT_BOOL fBold) = 0;
		virtual HRESULT __stdcall get_FontBold(
			/*[out,retval]*/ VARIANT_BOOL * fBold) = 0;
		virtual HRESULT __stdcall put_FontItalic(
			/*[in]*/ VARIANT_BOOL fItalic) = 0;
		virtual HRESULT __stdcall get_FontItalic(
			/*[out,retval]*/ VARIANT_BOOL * fItalic) = 0;
		virtual HRESULT __stdcall put_FontUnderline(
			/*[in]*/ VARIANT_BOOL fUnder) = 0;
		virtual HRESULT __stdcall get_FontUnderline(
			/*[out,retval]*/ VARIANT_BOOL * fUnder) = 0;
		virtual HRESULT __stdcall put_FontStrikethru(
			/*[in]*/ VARIANT_BOOL fStrike) = 0;
		virtual HRESULT __stdcall get_FontStrikethru(
			/*[out,retval]*/ VARIANT_BOOL * fStrike) = 0;
		virtual HRESULT __stdcall put_FontSize(
			/*[in]*/ CURRENCY Size) = 0;
		virtual HRESULT __stdcall get_FontSize(
			/*[out,retval]*/ CURRENCY * Size) = 0;
		virtual HRESULT __stdcall put_MultiRow(
			/*[in]*/ VARIANT_BOOL fMultiRow) = 0;
		virtual HRESULT __stdcall get_MultiRow(
			/*[out,retval]*/ VARIANT_BOOL * fMultiRow) = 0;
		virtual HRESULT __stdcall put_Style(
		/*[in]*/ enum fmTabStyle Style) = 0;
		virtual HRESULT __stdcall get_Style(
		/*[out,retval]*/ enum fmTabStyle * Style) = 0;
		virtual HRESULT __stdcall put_TabOrientation(
		/*[in]*/ enum fmTabOrientation Layout) = 0;
		virtual HRESULT __stdcall get_TabOrientation(
		/*[out,retval]*/ enum fmTabOrientation * Layout) = 0;
		virtual HRESULT __stdcall _SetTabFixedWidth(
			/*[in]*/ long Width) = 0;
		virtual HRESULT __stdcall _GetTabFixedWidth(
			/*[out]*/ long * Width) = 0;
		virtual HRESULT __stdcall _SetTabFixedHeight(
			/*[in]*/ long Height) = 0;
		virtual HRESULT __stdcall _GetTabFixedHeight(
			/*[out]*/ long * Height) = 0;
		virtual HRESULT __stdcall put_Enabled(
			/*[in]*/ VARIANT_BOOL Enabled) = 0;
		virtual HRESULT __stdcall get_Enabled(
			/*[out,retval]*/ VARIANT_BOOL * Enabled) = 0;
		virtual HRESULT __stdcall get_SelectedItem(
		/*[out,retval]*/ struct IPage * * ppPage) = 0;
		virtual HRESULT __stdcall get_Pages(
		/*[out,retval]*/ struct Pages * * ppPages) = 0;
		virtual HRESULT __stdcall put_Value(
			/*[in]*/ long Index) = 0;
		virtual HRESULT __stdcall get_Value(
			/*[out,retval]*/ long * Index) = 0;
		virtual HRESULT __stdcall put_TabFixedWidth(
			/*[in]*/ float Width) = 0;
		virtual HRESULT __stdcall get_TabFixedWidth(
			/*[out,retval]*/ float * Width) = 0;
		virtual HRESULT __stdcall put_TabFixedHeight(
			/*[in]*/ float Height) = 0;
		virtual HRESULT __stdcall get_TabFixedHeight(
			/*[out,retval]*/ float * Height) = 0;
		virtual HRESULT __stdcall put_FontWeight(
			/*[in]*/ short FontWeight) = 0;
		virtual HRESULT __stdcall get_FontWeight(
			/*[out,retval]*/ short * FontWeight) = 0;
	};

	enum __declspec(uuid("f00164c2-b17b-11ce-a95d-00aa006cb389"))
		fmListBoxStyles
	{
		_fmListBoxStylesNone = 0,
		_fmListBoxStylesListBox = 1,
		_fmListBoxStylesComboBox = 2
	};

	enum __declspec(uuid("c3689f20-c231-11ce-a30c-00aa004a3d3c"))
		fmRepeatDirection
	{
		_fmRepeatDirectionHorizontal = 0,
		_fmRepeatDirectionVertical = 1
	};

	enum __declspec(uuid("c3689f20-c231-11ce-a30c-00aa004a3d3d"))
		fmEnAutoSize
	{
		_fmEnAutoSizeNone = 0,
		_fmEnAutoSizeHorizontal = 1,
		_fmEnAutoSizeVertical = 2,
		_fmEnAutoSizeBoth = 3
	};

	struct __declspec(uuid("dd4cb8c5-f540-47ff-84d7-67390d2743ca"))
		TextBox2;
	// [ default ] interface IMdcText
	// [ default, source ] dispinterface MdcTextEvents

	struct __declspec(uuid("86f56b7f-a81b-478d-b231-50fd37cbe761"))
		CommandButton2;
	// [ default ] interface ICommandButton
	// [ default, source ] dispinterface CommandButtonEvents

	struct __declspec(uuid("dca0ed3c-b95d-490f-9c60-0ff3726c789a"))
		Image2;
	// [ default ] interface IImage
	// [ default, source ] dispinterface ImageEvents

	struct __declspec(uuid("5052a832-2c0f-46c7-b67c-1f1fec37b280"))
		Label2;
	// [ default ] interface ILabelControl
	// [ default, source ] dispinterface LabelControlEvents

	struct __declspec(uuid("6240ef28-7eab-4dc7-a5e3-7cfb35efb34d"))
		ScrollBar2;
	// [ default ] interface IScrollbar
	// [ default, source ] dispinterface ScrollbarEvents

	struct __declspec(uuid("ea778db4-ce69-4da5-bc1d-34e2168d5eed"))
		SpinButton2;
	// [ default ] interface ISpinbutton
	// [ default, source ] dispinterface SpinbuttonEvents

	struct __declspec(uuid("fdea20db-ac7a-42f8-90ee-82208b9b4fc0"))
		TabStrip2;
	// [ default ] interface ITabStrip
	// [ default, source ] dispinterface TabStripEvents

	struct __declspec(uuid("19fed08e-efd1-45da-b524-7be4774a6aee"))
		ListBox2;
	// [ default ] interface IMdcList
	// [ default, source ] dispinterface MdcListEvents

	struct __declspec(uuid("6c177ebd-c42d-4728-a04b-4131892edbf6"))
		ComboBox2;
	// [ default ] interface IMdcCombo
	// [ default, source ] dispinterface MdcComboEvents

	struct __declspec(uuid("e9729012-8271-4e1f-bc56-cf85f914915a"))
		CheckBox2;
	// [ default ] interface IMdcCheckBox
	// [ default, source ] dispinterface MdcCheckBoxEvents

	struct __declspec(uuid("02af6dd2-77e6-44df-b3e1-57cf1476d8ea"))
		OptionButton2;
	// [ default ] interface IMdcOptionButton
	// [ default, source ] dispinterface MdcOptionButtonEvents

	struct __declspec(uuid("3d0fd779-0c2d-4708-a9ba-62f7458a5a53"))
		ToggleButton2;
	// [ default ] interface IMdcToggleButton
	// [ default, source ] dispinterface MdcToggleButtonEvents

	struct __declspec(uuid("4795051a-6429-4d63-bca0-d706532954ac"))
		UserForm2;
	// [ default ] interface _UserForm
	// [ default, source ] dispinterface FormEvents

	struct __declspec(uuid("7931f65c-2564-4c19-ae71-e7ddfa008f6a"))
		Frame2;
	// [ default ] interface IOptionFrame
	// [ default, source ] dispinterface OptionFrameEvents

	struct __declspec(uuid("646be917-efed-46c6-afc9-ca1fbd3c5100"))
		DataObject2;
	// [ default ] interface IDataAutoWrapper

	struct __declspec(uuid("6c1b3099-127a-4be1-93bc-dd4771eeef90"))
		MultiPage2;
	// [ default ] interface IMultiPage
	// [ default, source ] dispinterface MultiPageEvents

	struct __declspec(uuid("9432194c-df54-4824-8e24-b013bf2b90e3"))
		HTMLSubmit2;
	// [ default ] interface IWHTMLSubmitButton
	// [ default, source ] dispinterface WHTMLControlEvents

	struct __declspec(uuid("9bdac276-be24-4f04-bb22-11469b28a496"))
		HTMLImage2;
	// [ default ] interface IWHTMLImage
	// [ default, source ] dispinterface WHTMLControlEvents1

	struct __declspec(uuid("227b1f3b-c276-4de0-9faa-c0ad42addcf0"))
		HTMLReset2;
	// [ default ] interface IWHTMLReset
	// [ default, source ] dispinterface WHTMLControlEvents2

	struct __declspec(uuid("5cba34ae-e344-40cf-b61d-fba4d0d1ff54"))
		HTMLCheckbox2;
	// [ default ] interface IWHTMLCheckbox
	// [ default, source ] dispinterface WHTMLControlEvents3

	struct __declspec(uuid("5e90cc8b-e402-4350-82d7-996e92010608"))
		HTMLOption2;
	// [ default ] interface IWHTMLOption
	// [ default, source ] dispinterface WHTMLControlEvents4

	struct __declspec(uuid("04082fc6-e032-49f2-a263-fe64e9da1fa3"))
		HTMLText2;
	// [ default ] interface IWHTMLText
	// [ default, source ] dispinterface WHTMLControlEvents5

	struct __declspec(uuid("fb453ad8-2ef4-44d3-98a8-8c6474e63ce4"))
		HTMLHidden2;
	// [ default ] interface IWHTMLHidden
	// [ default, source ] dispinterface WHTMLControlEvents6

	struct __declspec(uuid("787a2d6b-ef66-488d-a303-513c9c75c344"))
		HTMLPassword2;
	// [ default ] interface IWHTMLPassword
	// [ default, source ] dispinterface WHTMLControlEvents7

	struct __declspec(uuid("f14e8b03-d080-4d3a-aeba-355e77b20f3d"))
		HTMLSelect2;
	// [ default ] interface IWHTMLSelect
	// [ default, source ] dispinterface WHTMLControlEvents9

	struct __declspec(uuid("13d557b6-a469-4362-beaf-52bfd0f180e2"))
		HTMLTextArea2;
	// [ default ] interface IWHTMLTextArea
	// [ default, source ] dispinterface WHTMLControlEvents10

//
// Named GUID constants initializations
//

	extern "C" const GUID __declspec(selectany) LIBID_MSForms =
	{ 0x0d452ee1,0xe08f,0x101a,{0x85,0x2e,0x02,0x60,0x8c,0x4d,0x0b,0xb4} };
	extern "C" const GUID __declspec(selectany) DIID_Font =
	{ 0xbef6e003,0xa874,0x101a,{0x8b,0xba,0x00,0xaa,0x00,0x30,0x0c,0xab} };
	extern "C" const GUID __declspec(selectany) IID_IDataAutoWrapper =
	{ 0xec72f590,0xf375,0x11ce,{0xb9,0xe8,0x00,0xaa,0x00,0x6b,0x1a,0x69} };
	extern "C" const GUID __declspec(selectany) IID_IReturnInteger =
	{ 0x82b02370,0xb5bc,0x11cf,{0x81,0x0f,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) IID_IReturnBoolean =
	{ 0x82b02371,0xb5bc,0x11cf,{0x81,0x0f,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) IID_IReturnString =
	{ 0x82b02372,0xb5bc,0x11cf,{0x81,0x0f,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) IID_IReturnSingle =
	{ 0x8a683c90,0xba84,0x11cf,{0x81,0x10,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) IID_IReturnEffect =
	{ 0x8a683c91,0xba84,0x11cf,{0x81,0x10,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) CLSID_ReturnInteger =
	{ 0x82b02373,0xb5bc,0x11cf,{0x81,0x0f,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) CLSID_ReturnBoolean =
	{ 0x82b02374,0xb5bc,0x11cf,{0x81,0x0f,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) CLSID_ReturnString =
	{ 0x82b02375,0xb5bc,0x11cf,{0x81,0x0f,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) CLSID_ReturnSingle =
	{ 0x8a683c92,0xba84,0x11cf,{0x81,0x10,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) CLSID_ReturnEffect =
	{ 0x8a683c93,0xba84,0x11cf,{0x81,0x10,0x00,0xa0,0xc9,0x03,0x00,0x74} };
	extern "C" const GUID __declspec(selectany) CLSID_DataObject =
	{ 0x1c3b4210,0xf441,0x11ce,{0xb9,0xea,0x00,0xaa,0x00,0x6b,0x1a,0x69} };
	extern "C" const GUID __declspec(selectany) IID_IControl =
	{ 0x04598fc6,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) DIID_ControlEvents =
	{ 0x9a4bbf53,0x4e46,0x101b,{0x8b,0xbd,0x00,0xaa,0x00,0x3e,0x3b,0x29} };
	extern "C" const GUID __declspec(selectany) CLSID_Control =
	{ 0x909e0ae0,0x16dc,0x11ce,{0x9e,0x98,0x00,0xaa,0x00,0x57,0x4a,0x4f} };
	extern "C" const GUID __declspec(selectany) IID_Controls =
	{ 0x04598fc7,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) IID_IOptionFrame =
	{ 0x29b86a70,0xf52e,0x11ce,{0x9b,0xce,0x00,0xaa,0x00,0x60,0x8e,0x01} };
	extern "C" const GUID __declspec(selectany) IID__UserForm =
	{ 0x04598fc8,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) DIID_FormEvents =
	{ 0x5b9d8fc8,0x4a71,0x101b,{0x97,0xa6,0x00,0x00,0x0b,0x65,0xc0,0x8b} };
	extern "C" const GUID __declspec(selectany) DIID_OptionFrameEvents =
	{ 0xcf3f94a0,0xf546,0x11ce,{0x9b,0xce,0x00,0xaa,0x00,0x60,0x8e,0x01} };
	extern "C" const GUID __declspec(selectany) CLSID_UserForm =
	{ 0xc62a69f0,0x16dc,0x11ce,{0x9e,0x98,0x00,0xaa,0x00,0x57,0x4a,0x4f} };
	extern "C" const GUID __declspec(selectany) CLSID_Frame =
	{ 0x6e182020,0xf460,0x11ce,{0x9b,0xcd,0x00,0xaa,0x00,0x60,0x8e,0x01} };
	extern "C" const GUID __declspec(selectany) IID_ILabelControl =
	{ 0x04598fc1,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) IID_ICommandButton =
	{ 0x04598fc4,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) IID_IMdcText =
	{ 0x8bd21d13,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) IID_IMdcList =
	{ 0x8bd21d23,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) IID_IMdcCombo =
	{ 0x8bd21d33,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) IID_IMdcCheckBox =
	{ 0x8bd21d43,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) IID_IMdcOptionButton =
	{ 0x8bd21d53,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) IID_IMdcToggleButton =
	{ 0x8bd21d63,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) IID_IScrollbar =
	{ 0x04598fc3,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) IID_Tab =
	{ 0xa38bffc3,0xa5a0,0x11ce,{0x81,0x07,0x00,0xaa,0x00,0x61,0x10,0x80} };
	extern "C" const GUID __declspec(selectany) IID_Tabs =
	{ 0x944acf93,0xa1e6,0x11ce,{0x81,0x04,0x00,0xaa,0x00,0x61,0x10,0x80} };
	extern "C" const GUID __declspec(selectany) IID_ITabStrip =
	{ 0x04598fc2,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) IID_ISpinbutton =
	{ 0x79176fb3,0xb7f2,0x11ce,{0x97,0xef,0x00,0xaa,0x00,0x6d,0x27,0x76} };
	extern "C" const GUID __declspec(selectany) IID_IImage =
	{ 0x4c599243,0x6926,0x101b,{0x99,0x92,0x00,0x00,0x0b,0x65,0xc6,0xf9} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLSubmitButton =
	{ 0x5512d111,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLImage =
	{ 0x5512d113,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLReset =
	{ 0x5512d115,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLCheckbox =
	{ 0x5512d117,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLOption =
	{ 0x5512d119,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLText =
	{ 0x5512d11b,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLHidden =
	{ 0x5512d11d,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLPassword =
	{ 0x5512d11f,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLSelect =
	{ 0x5512d123,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IWHTMLTextArea =
	{ 0x5512d125,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) DIID_LabelControlEvents =
	{ 0x978c9e22,0xd4b0,0x11ce,{0xbf,0x2d,0x00,0xaa,0x00,0x3f,0x40,0xd0} };
	extern "C" const GUID __declspec(selectany) CLSID_Label =
	{ 0x978c9e23,0xd4b0,0x11ce,{0xbf,0x2d,0x00,0xaa,0x00,0x3f,0x40,0xd0} };
	extern "C" const GUID __declspec(selectany) DIID_CommandButtonEvents =
	{ 0x7b020ec1,0xaf6c,0x11ce,{0x9f,0x46,0x00,0xaa,0x00,0x57,0x4a,0x4f} };
	extern "C" const GUID __declspec(selectany) CLSID_CommandButton =
	{ 0xd7053240,0xce69,0x11cd,{0xa7,0x77,0x00,0xdd,0x01,0x14,0x3c,0x57} };
	extern "C" const GUID __declspec(selectany) DIID_MdcTextEvents =
	{ 0x8bd21d12,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) CLSID_TextBox =
	{ 0x8bd21d10,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) DIID_MdcListEvents =
	{ 0x8bd21d22,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) CLSID_ListBox =
	{ 0x8bd21d20,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) DIID_MdcComboEvents =
	{ 0x8bd21d32,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) CLSID_ComboBox =
	{ 0x8bd21d30,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) DIID_MdcCheckBoxEvents =
	{ 0x8bd21d42,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) DIID_MdcOptionButtonEvents =
	{ 0x8bd21d52,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) DIID_MdcToggleButtonEvents =
	{ 0x8bd21d62,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) CLSID_CheckBox =
	{ 0x8bd21d40,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) CLSID_OptionButton =
	{ 0x8bd21d50,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) CLSID_ToggleButton =
	{ 0x8bd21d60,0xec42,0x11ce,{0x9e,0x0d,0x00,0xaa,0x00,0x60,0x02,0xf3} };
	extern "C" const GUID __declspec(selectany) CLSID_NewFont =
	{ 0xafc20920,0xda4e,0x11ce,{0xb9,0x43,0x00,0xaa,0x00,0x68,0x87,0xb4} };
	extern "C" const GUID __declspec(selectany) DIID_ScrollbarEvents =
	{ 0x7b020ec2,0xaf6c,0x11ce,{0x9f,0x46,0x00,0xaa,0x00,0x57,0x4a,0x4f} };
	extern "C" const GUID __declspec(selectany) CLSID_ScrollBar =
	{ 0xdfd181e0,0x5e2f,0x11ce,{0xa4,0x49,0x00,0xaa,0x00,0x4a,0x80,0x3d} };
	extern "C" const GUID __declspec(selectany) DIID_TabStripEvents =
	{ 0x7b020ec7,0xaf6c,0x11ce,{0x9f,0x46,0x00,0xaa,0x00,0x57,0x4a,0x4f} };
	extern "C" const GUID __declspec(selectany) CLSID_TabStrip =
	{ 0xeae50eb0,0x4a62,0x11ce,{0xbe,0xd6,0x00,0xaa,0x00,0x61,0x10,0x80} };
	extern "C" const GUID __declspec(selectany) DIID_SpinbuttonEvents =
	{ 0x79176fb2,0xb7f2,0x11ce,{0x97,0xef,0x00,0xaa,0x00,0x6d,0x27,0x76} };
	extern "C" const GUID __declspec(selectany) CLSID_SpinButton =
	{ 0x79176fb0,0xb7f2,0x11ce,{0x97,0xef,0x00,0xaa,0x00,0x6d,0x27,0x76} };
	extern "C" const GUID __declspec(selectany) DIID_ImageEvents =
	{ 0x4c5992a5,0x6926,0x101b,{0x99,0x92,0x00,0x00,0x0b,0x65,0xc6,0xf9} };
	extern "C" const GUID __declspec(selectany) CLSID_Image =
	{ 0x4c599241,0x6926,0x101b,{0x99,0x92,0x00,0x00,0x0b,0x65,0xc6,0xf9} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents =
	{ 0x796ed650,0x5fe9,0x11cf,{0x8d,0x68,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents1 =
	{ 0x47ff8fe0,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents2 =
	{ 0x47ff8fe1,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents3 =
	{ 0x47ff8fe2,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents4 =
	{ 0x47ff8fe3,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents5 =
	{ 0x47ff8fe4,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents6 =
	{ 0x47ff8fe5,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents7 =
	{ 0x47ff8fe6,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents9 =
	{ 0x47ff8fe8,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) DIID_WHTMLControlEvents10 =
	{ 0x47ff8fe9,0x6198,0x11cf,{0x8c,0xe8,0x00,0xaa,0x00,0x6c,0xb3,0x89} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLSubmit =
	{ 0x5512d110,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLImage =
	{ 0x5512d112,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLReset =
	{ 0x5512d114,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLCheckbox =
	{ 0x5512d116,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLOption =
	{ 0x5512d118,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLText =
	{ 0x5512d11a,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLHidden =
	{ 0x5512d11c,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLPassword =
	{ 0x5512d11e,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLSelect =
	{ 0x5512d122,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLTextArea =
	{ 0x5512d124,0x5cc6,0x11cf,{0x8d,0x67,0x00,0xaa,0x00,0xbd,0xce,0x1d} };
	extern "C" const GUID __declspec(selectany) IID_IPage =
	{ 0x5cef5613,0x713d,0x11ce,{0x80,0xc9,0x00,0xaa,0x00,0x61,0x10,0x80} };
	extern "C" const GUID __declspec(selectany) DIID_MultiPageEvents =
	{ 0x7b020ec8,0xaf6c,0x11ce,{0x9f,0x46,0x00,0xaa,0x00,0x57,0x4a,0x4f} };
	extern "C" const GUID __declspec(selectany) CLSID_MultiPage =
	{ 0x46e31370,0x3f7a,0x11ce,{0xbe,0xd6,0x00,0xaa,0x00,0x61,0x10,0x80} };
	extern "C" const GUID __declspec(selectany) CLSID_Page =
	{ 0x5cef5610,0x713d,0x11ce,{0x80,0xc9,0x00,0xaa,0x00,0x61,0x10,0x80} };
	extern "C" const GUID __declspec(selectany) IID_Pages =
	{ 0x92e11a03,0x7358,0x11ce,{0x80,0xcb,0x00,0xaa,0x00,0x61,0x10,0x80} };
	extern "C" const GUID __declspec(selectany) IID_IMultiPage =
	{ 0x04598fc9,0x866c,0x11cf,{0xab,0x7c,0x00,0xaa,0x00,0xc0,0x8f,0xcf} };
	extern "C" const GUID __declspec(selectany) CLSID_TextBox2 =
	{ 0xdd4cb8c5,0xf540,0x47ff,{0x84,0xd7,0x67,0x39,0x0d,0x27,0x43,0xca} };
	extern "C" const GUID __declspec(selectany) CLSID_CommandButton2 =
	{ 0x86f56b7f,0xa81b,0x478d,{0xb2,0x31,0x50,0xfd,0x37,0xcb,0xe7,0x61} };
	extern "C" const GUID __declspec(selectany) CLSID_Image2 =
	{ 0xdca0ed3c,0xb95d,0x490f,{0x9c,0x60,0x0f,0xf3,0x72,0x6c,0x78,0x9a} };
	extern "C" const GUID __declspec(selectany) CLSID_Label2 =
	{ 0x5052a832,0x2c0f,0x46c7,{0xb6,0x7c,0x1f,0x1f,0xec,0x37,0xb2,0x80} };
	extern "C" const GUID __declspec(selectany) CLSID_ScrollBar2 =
	{ 0x6240ef28,0x7eab,0x4dc7,{0xa5,0xe3,0x7c,0xfb,0x35,0xef,0xb3,0x4d} };
	extern "C" const GUID __declspec(selectany) CLSID_SpinButton2 =
	{ 0xea778db4,0xce69,0x4da5,{0xbc,0x1d,0x34,0xe2,0x16,0x8d,0x5e,0xed} };
	extern "C" const GUID __declspec(selectany) CLSID_TabStrip2 =
	{ 0xfdea20db,0xac7a,0x42f8,{0x90,0xee,0x82,0x20,0x8b,0x9b,0x4f,0xc0} };
	extern "C" const GUID __declspec(selectany) CLSID_ListBox2 =
	{ 0x19fed08e,0xefd1,0x45da,{0xb5,0x24,0x7b,0xe4,0x77,0x4a,0x6a,0xee} };
	extern "C" const GUID __declspec(selectany) CLSID_ComboBox2 =
	{ 0x6c177ebd,0xc42d,0x4728,{0xa0,0x4b,0x41,0x31,0x89,0x2e,0xdb,0xf6} };
	extern "C" const GUID __declspec(selectany) CLSID_CheckBox2 =
	{ 0xe9729012,0x8271,0x4e1f,{0xbc,0x56,0xcf,0x85,0xf9,0x14,0x91,0x5a} };
	extern "C" const GUID __declspec(selectany) CLSID_OptionButton2 =
	{ 0x02af6dd2,0x77e6,0x44df,{0xb3,0xe1,0x57,0xcf,0x14,0x76,0xd8,0xea} };
	extern "C" const GUID __declspec(selectany) CLSID_ToggleButton2 =
	{ 0x3d0fd779,0x0c2d,0x4708,{0xa9,0xba,0x62,0xf7,0x45,0x8a,0x5a,0x53} };
	extern "C" const GUID __declspec(selectany) CLSID_UserForm2 =
	{ 0x4795051a,0x6429,0x4d63,{0xbc,0xa0,0xd7,0x06,0x53,0x29,0x54,0xac} };
	extern "C" const GUID __declspec(selectany) CLSID_Frame2 =
	{ 0x7931f65c,0x2564,0x4c19,{0xae,0x71,0xe7,0xdd,0xfa,0x00,0x8f,0x6a} };
	extern "C" const GUID __declspec(selectany) CLSID_DataObject2 =
	{ 0x646be917,0xefed,0x46c6,{0xaf,0xc9,0xca,0x1f,0xbd,0x3c,0x51,0x00} };
	extern "C" const GUID __declspec(selectany) CLSID_MultiPage2 =
	{ 0x6c1b3099,0x127a,0x4be1,{0x93,0xbc,0xdd,0x47,0x71,0xee,0xef,0x90} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLSubmit2 =
	{ 0x9432194c,0xdf54,0x4824,{0x8e,0x24,0xb0,0x13,0xbf,0x2b,0x90,0xe3} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLImage2 =
	{ 0x9bdac276,0xbe24,0x4f04,{0xbb,0x22,0x11,0x46,0x9b,0x28,0xa4,0x96} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLReset2 =
	{ 0x227b1f3b,0xc276,0x4de0,{0x9f,0xaa,0xc0,0xad,0x42,0xad,0xdc,0xf0} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLCheckbox2 =
	{ 0x5cba34ae,0xe344,0x40cf,{0xb6,0x1d,0xfb,0xa4,0xd0,0xd1,0xff,0x54} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLOption2 =
	{ 0x5e90cc8b,0xe402,0x4350,{0x82,0xd7,0x99,0x6e,0x92,0x01,0x06,0x08} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLText2 =
	{ 0x04082fc6,0xe032,0x49f2,{0xa2,0x63,0xfe,0x64,0xe9,0xda,0x1f,0xa3} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLHidden2 =
	{ 0xfb453ad8,0x2ef4,0x44d3,{0x98,0xa8,0x8c,0x64,0x74,0xe6,0x3c,0xe4} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLPassword2 =
	{ 0x787a2d6b,0xef66,0x488d,{0xa3,0x03,0x51,0x3c,0x9c,0x75,0xc3,0x44} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLSelect2 =
	{ 0xf14e8b03,0xd080,0x4d3a,{0xae,0xba,0x35,0x5e,0x77,0xb2,0x0f,0x3d} };
	extern "C" const GUID __declspec(selectany) CLSID_HTMLTextArea2 =
	{ 0x13d557b6,0xa469,0x4362,{0xbe,0xaf,0x52,0xbf,0xd0,0xf1,0x80,0xe2} };
}
#pragma pack(pop)
