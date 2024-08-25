﻿/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202110220001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser;
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
#pragma pack(push, 8)

#include <comdef.h>

namespace Office {

//
// Forward references and typedefs
//

struct __declspec(uuid("2df8d04c-5bfa-101b-bde5-00aa0044de52"))
/* LIBID */ __Office;
enum MsoLineDashStyle;
enum MsoLineStyle;
enum MsoArrowheadStyle;
enum MsoArrowheadWidth;
enum MsoArrowheadLength;
enum MsoFillType;
enum MsoGradientStyle;
enum MsoGradientColorType;
enum MsoTextureType;
enum MsoPresetTexture;
enum MsoPatternType;
enum MsoPresetGradientType;
enum MsoShadowType;
enum MsoPresetTextEffect;
enum MsoPresetTextEffectShape;
enum MsoTextEffectAlignment;
enum MsoPresetLightingDirection;
enum MsoPresetLightingSoftness;
enum MsoPresetMaterial;
enum MsoPresetExtrusionDirection;
enum MsoPresetThreeDFormat;
enum MsoExtrusionColorType;
enum MsoAlignCmd;
enum MsoDistributeCmd;
enum MsoConnectorType;
enum MsoHorizontalAnchor;
enum MsoVerticalAnchor;
enum MsoOrientation;
enum MsoZOrderCmd;
enum MsoSegmentType;
enum MsoEditingType;
enum MsoAutoShapeType;
enum MsoShapeType;
enum MsoFlipCmd;
enum MsoTriState;
enum MsoColorType;
enum MsoPictureColorType;
enum MsoCalloutAngleType;
enum MsoCalloutDropType;
enum MsoCalloutType;
enum MsoBlackWhiteMode;
enum MsoMixedType;
enum MsoTextOrientation;
enum MsoScaleFrom;
enum MsoBarPosition;
enum MsoBarProtection;
enum MsoBarType;
enum MsoControlType;
enum MsoButtonState;
enum MsoControlOLEUsage;
enum MsoButtonStyleHidden;
enum MsoButtonStyle;
enum MsoComboStyle;
enum MsoOLEMenuGroup;
enum MsoMenuAnimation;
enum MsoBarRow;
enum MsoCommandBarButtonHyperlinkType;
enum MsoHyperlinkType;
enum MsoExtraInfoMethod;
enum MsoAnimationType;
enum MsoButtonSetType;
enum MsoIconType;
enum MsoBalloonType;
enum MsoModeType;
enum MsoBalloonErrorType;
enum MsoWizardActType;
enum MsoWizardMsgType;
enum MsoBalloonButtonType;
enum DocProperties;
enum MsoDocProperties;
enum MsoAppLanguageID;
enum MsoFarEastLineBreakLanguageID;
enum MsoFeatureInstall;
struct __declspec(uuid("618736e0-3c3d-11cf-810c-00aa00389b71"))
/* dual interface */ IAccessible;
struct __declspec(uuid("000c0300-0000-0000-c000-000000000046"))
/* dual interface */ _IMsoDispObj;
struct __declspec(uuid("000c0301-0000-0000-c000-000000000046"))
/* dual interface */ _IMsoOleAccDispObj;
struct __declspec(uuid("000c0302-0000-0000-c000-000000000046"))
/* dual interface */ _CommandBars;
struct __declspec(uuid("000c0304-0000-0000-c000-000000000046"))
/* dual interface */ CommandBar;
struct __declspec(uuid("000c0306-0000-0000-c000-000000000046"))
/* dual interface */ CommandBarControls;
struct __declspec(uuid("000c0308-0000-0000-c000-000000000046"))
/* dual interface */ CommandBarControl;
struct __declspec(uuid("000c030e-0000-0000-c000-000000000046"))
/* dual interface */ _CommandBarButton;
struct __declspec(uuid("000c030a-0000-0000-c000-000000000046"))
/* dual interface */ CommandBarPopup;
struct __declspec(uuid("000c030c-0000-0000-c000-000000000046"))
/* dual interface */ _CommandBarComboBox;
struct __declspec(uuid("000c030d-0000-0000-c000-000000000046"))
/* dual interface */ _CommandBarActiveX;
struct __declspec(uuid("000c0310-0000-0000-c000-000000000046"))
/* dual interface */ TangramAdjustments;
struct __declspec(uuid("000c0311-0000-0000-c000-000000000046"))
/* dual interface */ CalloutFormat;
struct __declspec(uuid("000c0312-0000-0000-c000-000000000046"))
/* dual interface */ ColorFormat;
struct __declspec(uuid("000c0313-0000-0000-c000-000000000046"))
/* dual interface */ ConnectorFormat;
struct __declspec(uuid("000c0314-0000-0000-c000-000000000046"))
/* dual interface */ FillFormat;
struct __declspec(uuid("000c0315-0000-0000-c000-000000000046"))
/* dual interface */ FreeformBuilder;
struct __declspec(uuid("000c0316-0000-0000-c000-000000000046"))
/* dual interface */ GroupShapes;
struct __declspec(uuid("000c0317-0000-0000-c000-000000000046"))
/* dual interface */ LineFormat;
struct __declspec(uuid("000c0318-0000-0000-c000-000000000046"))
/* dual interface */ ShapeNode;
struct __declspec(uuid("000c0319-0000-0000-c000-000000000046"))
/* dual interface */ ShapeNodes;
struct __declspec(uuid("000c031a-0000-0000-c000-000000000046"))
/* dual interface */ PictureFormat;
struct __declspec(uuid("000c031b-0000-0000-c000-000000000046"))
/* dual interface */ ShadowFormat;
enum MsoScriptLanguage;
enum MsoScriptLocation;
struct __declspec(uuid("000c0341-0000-0000-c000-000000000046"))
/* dual interface */ Script;
struct __declspec(uuid("000c0340-0000-0000-c000-000000000046"))
/* dual interface */ Scripts;
struct __declspec(uuid("000c031c-0000-0000-c000-000000000046"))
/* dual interface */ Shape;
struct __declspec(uuid("000c031d-0000-0000-c000-000000000046"))
/* dual interface */ ShapeRange;
struct __declspec(uuid("000c031e-0000-0000-c000-000000000046"))
/* dual interface */ Shapes;
struct __declspec(uuid("000c031f-0000-0000-c000-000000000046"))
/* dual interface */ TextEffectFormat;
struct __declspec(uuid("000c0320-0000-0000-c000-000000000046"))
/* dual interface */ TextFrame;
struct __declspec(uuid("000c0321-0000-0000-c000-000000000046"))
/* dual interface */ ThreeDFormat;
struct __declspec(uuid("000c0359-0000-0000-c000-000000000046"))
/* dual interface */ IMsoDispCagNotifySink;
struct __declspec(uuid("000c0324-0000-0000-c000-000000000046"))
/* dual interface */ Balloon;
struct __declspec(uuid("000c0326-0000-0000-c000-000000000046"))
/* dual interface */ BalloonCheckboxes;
struct __declspec(uuid("000c0328-0000-0000-c000-000000000046"))
/* dual interface */ BalloonCheckbox;
struct __declspec(uuid("000c032e-0000-0000-c000-000000000046"))
/* dual interface */ BalloonLabels;
struct __declspec(uuid("000c0330-0000-0000-c000-000000000046"))
/* dual interface */ BalloonLabel;
struct __declspec(uuid("000c0361-0000-0000-c000-000000000046"))
/* dual interface */ AnswerWizardFiles;
struct __declspec(uuid("000c0360-0000-0000-c000-000000000046"))
/* dual interface */ AnswerWizard;
struct __declspec(uuid("000c0322-0000-0000-c000-000000000046"))
/* dual interface */ Assistant;
struct __declspec(uuid("2df8d04e-5bfa-101b-bde5-00aa0044de52"))
/* interface */ DocumentProperty;
struct __declspec(uuid("2df8d04d-5bfa-101b-bde5-00aa0044de52"))
/* interface */ DocumentProperties;
enum MsoFileFindOptions;
enum MsoFileFindView;
enum MsoFileFindSortBy;
enum MsoFileFindListBy;
struct __declspec(uuid("000c0338-0000-0000-c000-000000000046"))
/* dual interface */ IFoundFiles;
struct __declspec(uuid("000c0337-0000-0000-c000-000000000046"))
/* dual interface */ IFind;
enum MsoLastModified;
enum MsoSortBy;
enum MsoSortOrder;
enum MsoConnector;
enum MsoCondition;
enum MsoFileType;
struct __declspec(uuid("000c0331-0000-0000-c000-000000000046"))
/* dual interface */ FoundFiles;
struct __declspec(uuid("000c0333-0000-0000-c000-000000000046"))
/* dual interface */ PropertyTest;
struct __declspec(uuid("000c0334-0000-0000-c000-000000000046"))
/* dual interface */ PropertyTests;
struct __declspec(uuid("000c0332-0000-0000-c000-000000000046"))
/* dual interface */ FileSearch;
struct __declspec(uuid("000c033a-0000-0000-c000-000000000046"))
/* dual interface */ COMAddIn;
struct __declspec(uuid("000c0339-0000-0000-c000-000000000046"))
/* dual interface */ COMAddIns;
enum MsoLanguageID;
struct __declspec(uuid("000c0353-0000-0000-c000-000000000046"))
/* dual interface */ LanguageSettings;
struct __declspec(uuid("55f88892-7708-11d1-aceb-006008961da5"))
/* dual interface */ ICommandBarsEvents;
struct __declspec(uuid("000c0352-0000-0000-c000-000000000046"))
/* dispinterface */ _CommandBarsEvents;
struct /* coclass */ CommandBars;
struct __declspec(uuid("55f88896-7708-11d1-aceb-006008961da5"))
/* dual interface */ ICommandBarComboBoxEvents;
struct __declspec(uuid("000c0354-0000-0000-c000-000000000046"))
/* dispinterface */ _CommandBarComboBoxEvents;
struct /* coclass */ CommandBarComboBox;
struct __declspec(uuid("55f88890-7708-11d1-aceb-006008961da5"))
/* dual interface */ ICommandBarButtonEvents;
struct __declspec(uuid("000c0351-0000-0000-c000-000000000046"))
/* dispinterface */ _CommandBarButtonEvents;
struct /* coclass */ CommandBarButton;
enum MsoScreenSize;
enum MsoCharacterSet;
enum MsoEncoding;
struct __declspec(uuid("000c0913-0000-0000-c000-000000000046"))
/* dual interface */ WebPageFont;
struct __declspec(uuid("000c0914-0000-0000-c000-000000000046"))
/* dual interface */ WebPageFonts;
enum MsoHTMLProjectOpen;
enum MsoHTMLProjectState;
struct __declspec(uuid("000c0358-0000-0000-c000-000000000046"))
/* dual interface */ HTMLProjectItem;
struct __declspec(uuid("000c0357-0000-0000-c000-000000000046"))
/* dual interface */ HTMLProjectItems;
struct __declspec(uuid("000c0356-0000-0000-c000-000000000046"))
/* dual interface */ HTMLProject;
struct __declspec(uuid("000c035a-0000-0000-c000-000000000046"))
/* dual interface */ MsoDebugOptions;
enum MsoFileDialogType;
enum MsoFileDialogView;
struct __declspec(uuid("000c0363-0000-0000-c000-000000000046"))
/* dual interface */ FileDialogSelectedItems;
struct __declspec(uuid("000c0364-0000-0000-c000-000000000046"))
/* dual interface */ FileDialogFilter;
struct __declspec(uuid("000c0365-0000-0000-c000-000000000046"))
/* dual interface */ FileDialogFilters;
struct __declspec(uuid("000c0362-0000-0000-c000-000000000046"))
/* dual interface */ FileDialog;
enum MsoAutomationSecurity;
struct __declspec(uuid("000c0410-0000-0000-c000-000000000046"))
/* dual interface */ SignatureSet;
struct __declspec(uuid("000c0411-0000-0000-c000-000000000046"))
/* dual interface */ Signature;
enum MailFormat;
struct __declspec(uuid("000672ac-0000-0000-c000-000000000046"))
/* dual interface */ IMsoEnvelopeVB;
struct __declspec(uuid("000672ad-0000-0000-c000-000000000046"))
/* dispinterface */ IMsoEnvelopeVBEvents;
struct /* coclass */ MsoEnvelope;
enum MsoAlertButtonType;
enum MsoAlertIconType;
enum MsoAlertDefaultType;
enum MsoAlertCancelType;
enum MsoSearchIn;
enum MsoTargetBrowser;
struct __declspec(uuid("000c036c-0000-0000-c000-000000000046"))
/* dual interface */ FileTypes;
struct __declspec(uuid("000c036a-0000-0000-c000-000000000046"))
/* dual interface */ SearchFolders;
struct __declspec(uuid("000c0369-0000-0000-c000-000000000046"))
/* dual interface */ ScopeFolders;
struct __declspec(uuid("000c0368-0000-0000-c000-000000000046"))
/* dual interface */ ScopeFolder;
struct __declspec(uuid("000c0367-0000-0000-c000-000000000046"))
/* dual interface */ SearchScope;
struct __declspec(uuid("000c0366-0000-0000-c000-000000000046"))
/* dual interface */ SearchScopes;
enum MsoOrgChartOrientation;
enum MsoOrgChartLayoutType;
enum MsoRelativeNodePosition;
enum MsoDiagramType;
enum MsoDiagramNodeType;
struct __declspec(uuid("000c036d-0000-0000-c000-000000000046"))
/* dual interface */ IMsoDiagram;
struct __declspec(uuid("000c036e-0000-0000-c000-000000000046"))
/* dual interface */ DiagramNodes;
struct __declspec(uuid("000c036f-0000-0000-c000-000000000046"))
/* dual interface */ DiagramNodeChildren;
struct __declspec(uuid("000c0370-0000-0000-c000-000000000046"))
/* dual interface */ DiagramNode;
struct __declspec(uuid("000c0371-0000-0000-c000-000000000046"))
/* dual interface */ CanvasShapes;
enum MsoMoveRow;
struct __declspec(uuid("000c1530-0000-0000-c000-000000000046"))
/* dual interface */ OfficeDataSourceObject;
struct __declspec(uuid("000c1531-0000-0000-c000-000000000046"))
/* dual interface */ ODSOColumn;
struct __declspec(uuid("000c1532-0000-0000-c000-000000000046"))
/* dual interface */ ODSOColumns;
enum MsoFilterComparison;
enum MsoFilterConjunction;
struct __declspec(uuid("000c1533-0000-0000-c000-000000000046"))
/* dual interface */ ODSOFilter;
struct __declspec(uuid("000c1534-0000-0000-c000-000000000046"))
/* dual interface */ ODSOFilters;
enum MsoFileNewSection;
enum MsoFileNewAction;
struct __declspec(uuid("000c0936-0000-0000-c000-000000000046"))
/* dual interface */ NewFile;
struct __declspec(uuid("000cd100-0000-0000-c000-000000000046"))
/* dual interface */ WebComponent;
struct __declspec(uuid("000cd101-0000-0000-c000-000000000046"))
/* dual interface */ WebComponentWindowExternal;
struct __declspec(uuid("000cd102-0000-0000-c000-000000000046"))
/* dual interface */ WebComponentFormat;
enum MsoLanguageIDHidden;
struct __declspec(uuid("4cac6328-b9b0-11d3-8d59-0050048384e3"))
/* dual interface */ ILicWizExternal;
struct __declspec(uuid("919aa22c-b9ad-11d3-8d59-0050048384e3"))
/* dual interface */ ILicValidator;
struct __declspec(uuid("00194002-d9c3-11d3-8d59-0050048384e3"))
/* dual interface */ ILicAgent;
struct __declspec(uuid("000c0372-0000-0000-c000-000000000046"))
/* dual interface */ IMsoEServicesDialog;
struct __declspec(uuid("000c0373-0000-0000-c000-000000000046"))
/* dual interface */ WebComponentProperties;
struct __declspec(uuid("000c0377-0000-0000-c000-000000000046"))
/* dual interface */ SmartDocument;
struct __declspec(uuid("000c0381-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceMember;
struct __declspec(uuid("000c0382-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceMembers;
enum MsoSharedWorkspaceTaskStatus;
enum MsoSharedWorkspaceTaskPriority;
struct __declspec(uuid("000c0379-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceTask;
struct __declspec(uuid("000c037a-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceTasks;
struct __declspec(uuid("000c037b-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceFile;
struct __declspec(uuid("000c037c-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceFiles;
struct __declspec(uuid("000c037d-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceFolder;
struct __declspec(uuid("000c037e-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceFolders;
struct __declspec(uuid("000c037f-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceLink;
struct __declspec(uuid("000c0380-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspaceLinks;
struct __declspec(uuid("000c0385-0000-0000-c000-000000000046"))
/* dual interface */ SharedWorkspace;
enum MsoSyncVersionType;
enum MsoSyncConflictResolutionType;
enum MsoSyncCompareType;
enum MsoSyncAvailableType;
enum MsoSyncEventType;
enum MsoSyncErrorType;
enum MsoSyncStatusType;
struct __declspec(uuid("000c0386-0000-0000-c000-000000000046"))
/* dual interface */ Sync;
struct __declspec(uuid("000c0387-0000-0000-c000-000000000046"))
/* dual interface */ DocumentLibraryVersion;
struct __declspec(uuid("000c0388-0000-0000-c000-000000000046"))
/* dual interface */ DocumentLibraryVersions;
enum MsoPermission;
struct __declspec(uuid("000c0375-0000-0000-c000-000000000046"))
/* dual interface */ UserPermission;
struct __declspec(uuid("000c0376-0000-0000-c000-000000000046"))
/* dual interface */ Permission;
struct __declspec(uuid("000c038c-0000-0000-c000-000000000046"))
/* dual interface */ MsoDebugOptions_UTRunResult;
struct __declspec(uuid("000c038b-0000-0000-c000-000000000046"))
/* dual interface */ MsoDebugOptions_UT;
struct __declspec(uuid("000c038a-0000-0000-c000-000000000046"))
/* dual interface */ MsoDebugOptions_UTs;
struct __declspec(uuid("000c0389-0000-0000-c000-000000000046"))
/* dual interface */ MsoDebugOptions_UTManager;
enum MsoMetaPropertyType;
struct __declspec(uuid("000c038f-0000-0000-c000-000000000046"))
/* dual interface */ MetaProperty;
struct __declspec(uuid("000c038e-0000-0000-c000-000000000046"))
/* dual interface */ MetaProperties;
enum MsoSignatureSubset;
struct __declspec(uuid("000c0391-0000-0000-c000-000000000046"))
/* dual interface */ PolicyItem;
struct __declspec(uuid("000c0390-0000-0000-c000-000000000046"))
/* dual interface */ ServerPolicy;
enum MsoDocInspectorStatus;
struct __declspec(uuid("000c0393-0000-0000-c000-000000000046"))
/* dual interface */ DocumentInspector;
struct __declspec(uuid("000c0392-0000-0000-c000-000000000046"))
/* dual interface */ DocumentInspectors;
struct __declspec(uuid("000cd900-0000-0000-c000-000000000046"))
/* dual interface */ WorkflowTask;
struct __declspec(uuid("000cd901-0000-0000-c000-000000000046"))
/* dual interface */ WorkflowTasks;
struct __declspec(uuid("000cd902-0000-0000-c000-000000000046"))
/* dual interface */ WorkflowTemplate;
struct __declspec(uuid("000cd903-0000-0000-c000-000000000046"))
/* dual interface */ WorkflowTemplates;
struct __declspec(uuid("000cd706-0000-0000-c000-000000000046"))
/* interface */ IDocumentInspector;
enum SignatureDetail;
enum CertificateDetail;
enum ContentVerificationResults;
enum CertificateVerificationResults;
enum SignatureLineImage;
enum SignatureProviderDetail;
enum SignatureType;
struct __declspec(uuid("000cd6a1-0000-0000-c000-000000000046"))
/* dual interface */ SignatureSetup;
struct __declspec(uuid("000cd6a2-0000-0000-c000-000000000046"))
/* dual interface */ SignatureInfo;
struct __declspec(uuid("000cd6a3-0000-0000-c000-000000000046"))
/* dual interface */ SignatureProvider;
enum MsoCustomXMLNodeType;
enum MsoCustomXMLValidationErrorType;
struct __declspec(uuid("000cdb10-0000-0000-c000-000000000046"))
/* dual interface */ CustomXMLPrefixMapping;
struct __declspec(uuid("000cdb00-0000-0000-c000-000000000046"))
/* dual interface */ CustomXMLPrefixMappings;
struct __declspec(uuid("000cdb01-0000-0000-c000-000000000046"))
/* dual interface */ CustomXMLSchema;
struct __declspec(uuid("000cdb02-0000-0000-c000-000000000046"))
/* dual interface */ _CustomXMLSchemaCollection;
struct /* coclass */ CustomXMLSchemaCollection;
struct __declspec(uuid("000cdb03-0000-0000-c000-000000000046"))
/* dual interface */ CustomXMLNodes;
struct __declspec(uuid("000cdb04-0000-0000-c000-000000000046"))
/* dual interface */ CustomXMLNode;
struct __declspec(uuid("000cdb0e-0000-0000-c000-000000000046"))
/* dual interface */ CustomXMLValidationError;
struct __declspec(uuid("000cdb0f-0000-0000-c000-000000000046"))
/* dual interface */ CustomXMLValidationErrors;
struct __declspec(uuid("000cdb05-0000-0000-c000-000000000046"))
/* dual interface */ _CustomXMLPart;
struct __declspec(uuid("000cdb06-0000-0000-c000-000000000046"))
/* dual interface */ ICustomXMLPartEvents;
struct __declspec(uuid("000cdb07-0000-0000-c000-000000000046"))
/* dispinterface */ _CustomXMLPartEvents;
struct /* coclass */ CustomXMLPart;
struct __declspec(uuid("000cdb09-0000-0000-c000-000000000046"))
/* dual interface */ _CustomXMLParts;
struct __declspec(uuid("000cdb0a-0000-0000-c000-000000000046"))
/* dual interface */ ICustomXMLPartsEvents;
struct __declspec(uuid("000cdb0b-0000-0000-c000-000000000046"))
/* dispinterface */ _CustomXMLPartsEvents;
struct /* coclass */ CustomXMLParts;
enum MsoTextureAlignment;
struct __declspec(uuid("000c03bf-0000-0000-c000-000000000046"))
/* dual interface */ GradientStop;
struct __declspec(uuid("000c03c0-0000-0000-c000-000000000046"))
/* dual interface */ GradientStops;
enum MsoSoftEdgeType;
enum MsoReflectionType;
struct __declspec(uuid("000c03bc-0000-0000-c000-000000000046"))
/* dual interface */ SoftEdgeFormat;
struct __declspec(uuid("000c03bd-0000-0000-c000-000000000046"))
/* dual interface */ GlowFormat;
struct __declspec(uuid("000c03be-0000-0000-c000-000000000046"))
/* dual interface */ ReflectionFormat;
struct __declspec(uuid("000c0399-0000-0000-c000-000000000046"))
/* dual interface */ ParagraphFormat2;
struct __declspec(uuid("000c039a-0000-0000-c000-000000000046"))
/* dual interface */ Font2;
struct __declspec(uuid("000c03b2-0000-0000-c000-000000000046"))
/* dual interface */ TextColumn2;
struct __declspec(uuid("000c0397-0000-0000-c000-000000000046"))
/* dual interface */ TextRange2;
struct __declspec(uuid("000c0398-0000-0000-c000-000000000046"))
/* dual interface */ TextFrame2;
enum MsoPresetCamera;
enum MsoBevelType;
enum MsoLightRigType;
enum MsoParagraphAlignment;
enum MsoTextStrike;
enum MsoTextCaps;
enum MsoTextUnderlineType;
enum MsoTextTabAlign;
enum MsoTextCharWrap;
enum MsoTextFontAlign;
enum MsoAutoSize;
enum MsoPathFormat;
enum MsoWarpFormat;
enum MsoTextChangeCase;
enum MsoDateTimeFormat;
enum MsoThemeColorSchemeIndex;
enum MsoThemeColorIndex;
enum MsoFontLanguageIndex;
enum MsoShapeStyleIndex;
enum MsoBackgroundStyleIndex;
struct __declspec(uuid("000c03a1-0000-0000-c000-000000000046"))
/* dual interface */ ThemeColor;
struct __declspec(uuid("000c03a2-0000-0000-c000-000000000046"))
/* dual interface */ ThemeColorScheme;
struct __declspec(uuid("000c03a3-0000-0000-c000-000000000046"))
/* dual interface */ ThemeFont;
struct __declspec(uuid("000c03a4-0000-0000-c000-000000000046"))
/* dual interface */ ThemeFonts;
struct __declspec(uuid("000c03a5-0000-0000-c000-000000000046"))
/* dual interface */ ThemeFontScheme;
struct __declspec(uuid("000c03a6-0000-0000-c000-000000000046"))
/* dual interface */ ThemeEffectScheme;
struct __declspec(uuid("000c03a0-0000-0000-c000-000000000046"))
/* dual interface */ OfficeTheme;
enum MsoCTPDockPosition;
enum MsoCTPDockPositionRestrict;
struct __declspec(uuid("000c033b-0000-0000-c000-000000000046"))
/* dual interface */ _CustomTaskPane;
struct __declspec(uuid("8a64a872-fc6b-4d4a-926e-3a3689562c1c"))
/* dual interface */ CustomTaskPaneEvents;
struct __declspec(uuid("000c033c-0000-0000-c000-000000000046"))
/* dispinterface */ _CustomTaskPaneEvents;
struct /* coclass */ CustomTaskPane;
struct __declspec(uuid("000c033d-0000-0000-c000-000000000046"))
/* dual interface */ ICTPFactory;
struct __declspec(uuid("000c033e-0000-0000-c000-000000000046"))
/* dual interface */ ICustomTaskPaneConsumer;
struct __declspec(uuid("000c03a7-0000-0000-c000-000000000046"))
/* dual interface */ IRibbonUI;
struct __declspec(uuid("000c0395-0000-0000-c000-000000000046"))
/* dual interface */ IRibbonControl;
struct __declspec(uuid("000c0396-0000-0000-c000-000000000046"))
/* dual interface */ IRibbonExtensibility;
enum RibbonControlSize;
enum MsoShadowStyle;
enum MsoTextDirection;
struct __declspec(uuid("4291224c-defe-485b-8e69-6cf8aa85cb76"))
/* dual interface */ IAssistance;
enum XlChartType;
enum XlChartSplitType;
enum XlSizeRepresents;
enum XlAxisGroup;
enum XlConstants;
enum XlReadingOrder;
enum XlBorderWeight;
enum XlLegendPosition;
enum XlUnderlineStyle;
enum XlColorIndex;
enum XlMarkerStyle;
enum XlRowCol;
enum XlDataLabelsType;
enum XlErrorBarInclude;
enum XlErrorBarType;
enum XlErrorBarDirection;
enum XlChartPictureType;
enum XlChartItem;
enum XlBarShape;
enum XlEndStyleCap;
enum XlTrendlineType;
enum XlAxisType;
enum XlAxisCrosses;
enum XlTickMark;
enum XlScaleType;
enum XlTickLabelPosition;
enum XlTimeUnit;
enum XlCategoryType;
enum XlDisplayUnit;
enum XlChartOrientation;
enum XlTickLabelOrientation;
enum XlDisplayBlanksAs;
enum XlDataLabelPosition;
enum XlPivotFieldOrientation;
enum XlHAlign;
enum XlVAlign;
enum XlChartElementPosition;
enum MsoChartElementType;
struct __declspec(uuid("000c172f-0000-0000-c000-000000000046"))
/* dual interface */ IMsoChartData;
struct __declspec(uuid("000c1709-0000-0000-c000-000000000046"))
/* dual interface */ IMsoChart;
struct __declspec(uuid("000c1714-0000-0000-c000-000000000046"))
/* dual interface */ IMsoCorners;
struct __declspec(uuid("000c1710-0000-0000-c000-000000000046"))
/* dual interface */ IMsoLegend;
struct __declspec(uuid("000c1717-0000-0000-c000-000000000046"))
/* dual interface */ IMsoBorder;
struct __declspec(uuid("000c1715-0000-0000-c000-000000000046"))
/* dual interface */ IMsoWalls;
struct __declspec(uuid("000c1716-0000-0000-c000-000000000046"))
/* dual interface */ IMsoFloor;
struct __declspec(uuid("000c1724-0000-0000-c000-000000000046"))
/* dual interface */ IMsoPlotArea;
struct __declspec(uuid("000c1728-0000-0000-c000-000000000046"))
/* dual interface */ IMsoChartArea;
struct __declspec(uuid("000c1729-0000-0000-c000-000000000046"))
/* dual interface */ IMsoSeriesLines;
struct __declspec(uuid("000c1723-0000-0000-c000-000000000046"))
/* dual interface */ IMsoLeaderLines;
struct __declspec(uuid("000c1725-0000-0000-c000-000000000046"))
/* dual interface */ GridLines;
struct __declspec(uuid("000c172a-0000-0000-c000-000000000046"))
/* dual interface */ IMsoUpBars;
struct __declspec(uuid("000c172d-0000-0000-c000-000000000046"))
/* dual interface */ IMsoDownBars;
struct __declspec(uuid("000c171b-0000-0000-c000-000000000046"))
/* dual interface */ IMsoInterior;
struct __declspec(uuid("000c171c-0000-0000-c000-000000000046"))
/* dual interface */ ChartFillFormat;
struct __declspec(uuid("000c1719-0000-0000-c000-000000000046"))
/* interface */ LegendEntries;
struct __declspec(uuid("000c1718-0000-0000-c000-000000000046"))
/* dual interface */ ChartFont;
struct __declspec(uuid("000c171d-0000-0000-c000-000000000046"))
/* interface */ ChartColorFormat;
struct __declspec(uuid("000c171a-0000-0000-c000-000000000046"))
/* interface */ LegendEntry;
struct __declspec(uuid("000c171e-0000-0000-c000-000000000046"))
/* interface */ IMsoLegendKey;
struct __declspec(uuid("000c170a-0000-0000-c000-000000000046"))
/* interface */ SeriesCollection;
struct __declspec(uuid("000c170b-0000-0000-c000-000000000046"))
/* interface */ IMsoSeries;
struct __declspec(uuid("000c1721-0000-0000-c000-000000000046"))
/* interface */ IMsoErrorBars;
struct __declspec(uuid("000c170e-0000-0000-c000-000000000046"))
/* interface */ IMsoTrendline;
struct __declspec(uuid("000c1722-0000-0000-c000-000000000046"))
/* interface */ Trendlines;
struct __declspec(uuid("000c171f-0000-0000-c000-000000000046"))
/* interface */ IMsoDataLabels;
struct __declspec(uuid("000c1720-0000-0000-c000-000000000046"))
/* interface */ IMsoDataLabel;
struct __declspec(uuid("000c170d-0000-0000-c000-000000000046"))
/* interface */ Points;
struct __declspec(uuid("000c170c-0000-0000-c000-000000000046"))
/* interface */ ChartPoint;
struct __declspec(uuid("000c1712-0000-0000-c000-000000000046"))
/* dual interface */ Axes;
struct __declspec(uuid("000c1713-0000-0000-c000-000000000046"))
/* dual interface */ IMsoAxis;
struct __declspec(uuid("000c1711-0000-0000-c000-000000000046"))
/* dual interface */ IMsoDataTable;
struct __declspec(uuid("000c170f-0000-0000-c000-000000000046"))
/* dual interface */ IMsoChartTitle;
struct __declspec(uuid("abfa087c-f703-4d53-946e-37ff82b2c994"))
/* dual interface */ IMsoAxisTitle;
struct __declspec(uuid("6ea00553-9439-4d5a-b1e6-dc15a54da8b2"))
/* dual interface */ IMsoDisplayUnitLabel;
struct __declspec(uuid("000c1726-0000-0000-c000-000000000046"))
/* dual interface */ IMsoTickLabels;
struct __declspec(uuid("a98639a1-cb0c-4a5c-a511-96547f752acd"))
/* dual interface */ IMsoHyperlinks;
struct __declspec(uuid("000c172c-0000-0000-c000-000000000046"))
/* dual interface */ IMsoDropLines;
struct __declspec(uuid("000c172e-0000-0000-c000-000000000046"))
/* dual interface */ IMsoHiLoLines;
struct __declspec(uuid("000c1727-0000-0000-c000-000000000046"))
/* dual interface */ IMsoChartGroup;
struct __declspec(uuid("000c172b-0000-0000-c000-000000000046"))
/* dual interface */ ChartGroups;
struct __declspec(uuid("000c1731-0000-0000-c000-000000000046"))
/* dual interface */ IMsoCharacters;
struct __declspec(uuid("000c1730-0000-0000-c000-000000000046"))
/* dual interface */ IMsoChartFormat;
enum MsoBulletType;
enum MsoNumberedBulletStyle;
struct __declspec(uuid("000c03b9-0000-0000-c000-000000000046"))
/* dual interface */ BulletFormat2;
enum MsoTabStopType;
struct __declspec(uuid("000c03ba-0000-0000-c000-000000000046"))
/* dual interface */ TabStops2;
struct __declspec(uuid("000c03bb-0000-0000-c000-000000000046"))
/* dual interface */ TabStop2;
enum MsoBaselineAlignment;
struct __declspec(uuid("000c03c1-0000-0000-c000-000000000046"))
/* dual interface */ Ruler2;
struct __declspec(uuid("000c03c2-0000-0000-c000-000000000046"))
/* dual interface */ RulerLevels2;
struct __declspec(uuid("000c03c3-0000-0000-c000-000000000046"))
/* dual interface */ RulerLevel2;
enum EncryptionProviderDetail;
enum EncryptionCipherMode;
struct __declspec(uuid("000cd809-0000-0000-c000-000000000046"))
/* dual interface */ EncryptionProvider;
enum MsoClipboardFormat;
enum MsoBlogCategorySupport;
enum MsoBlogImageType;
struct __declspec(uuid("000c03c4-0000-0000-c000-000000000046"))
/* dual interface */ IBlogExtensibility;
struct __declspec(uuid("000c03c5-0000-0000-c000-000000000046"))
/* dual interface */ IBlogPictureExtensibility;
struct __declspec(uuid("000c03d4-0000-0000-c000-000000000046"))
/* interface */ IConverterPreferences;
struct __declspec(uuid("000c03d5-0000-0000-c000-000000000046"))
/* interface */ IConverterApplicationPreferences;
struct __declspec(uuid("000c03d6-0000-0000-c000-000000000046"))
/* interface */ IConverterUICallback;
struct __declspec(uuid("000c03d7-0000-0000-c000-000000000046"))
/* interface */ IConverter;
enum XlPieSliceLocation;
enum XlPieSliceIndex;
enum MsoSmartArtNodePosition;
enum MsoSmartArtNodeType;
struct __declspec(uuid("000c03c6-0000-0000-c000-000000000046"))
/* dual interface */ SmartArt;
struct __declspec(uuid("000c03c7-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtNodes;
struct __declspec(uuid("000c03c8-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtNode;
struct __declspec(uuid("000c03c9-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtLayouts;
struct __declspec(uuid("000c03ca-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtLayout;
struct __declspec(uuid("000c03cb-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtQuickStyles;
struct __declspec(uuid("000c03cc-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtQuickStyle;
struct __declspec(uuid("000c03cd-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtColors;
struct __declspec(uuid("000c03ce-0000-0000-c000-000000000046"))
/* dual interface */ SmartArtColor;
enum MsoPickerField;
struct __declspec(uuid("000c03e0-0000-0000-c000-000000000046"))
/* dual interface */ PickerField;
struct __declspec(uuid("000c03e1-0000-0000-c000-000000000046"))
/* dual interface */ PickerFields;
struct __declspec(uuid("000c03e2-0000-0000-c000-000000000046"))
/* dual interface */ PickerProperty;
struct __declspec(uuid("000c03e3-0000-0000-c000-000000000046"))
/* dual interface */ PickerProperties;
struct __declspec(uuid("000c03e4-0000-0000-c000-000000000046"))
/* dual interface */ PickerResult;
struct __declspec(uuid("000c03e5-0000-0000-c000-000000000046"))
/* dual interface */ PickerResults;
struct __declspec(uuid("000c03e6-0000-0000-c000-000000000046"))
/* dual interface */ PickerDialog;
enum MsoContactCardAddressType;
enum MsoContactCardType;
struct __declspec(uuid("000c03f0-0000-0000-c000-000000000046"))
/* dual interface */ IMsoContactCard;
struct __declspec(uuid("000c03cf-0000-0000-c000-000000000046"))
/* dual interface */ EffectParameter;
struct __declspec(uuid("000c03d0-0000-0000-c000-000000000046"))
/* dual interface */ EffectParameters;
enum MsoPictureEffectType;
struct __declspec(uuid("000c03d1-0000-0000-c000-000000000046"))
/* dual interface */ PictureEffect;
struct __declspec(uuid("000c03d2-0000-0000-c000-000000000046"))
/* dual interface */ PictureEffects;
struct __declspec(uuid("000c03d3-0000-0000-c000-000000000046"))
/* dual interface */ Crop;
enum MsoIodGroup;
enum BackstageGroupStyle;
enum MsoFileValidationMode;
enum MsoContactCardStyle;
struct __declspec(uuid("000c03f1-0000-0000-c000-000000000046"))
/* dual interface */ ContactCard;
enum MsoMergeCmd;
enum MsoLineCapStyle;
enum MsoLineJoinStyle;
enum MsoLineFillType;
enum MsoChartFieldType;
enum MsoBroadcastState;
enum MsoBroadcastCapabilities;
enum MsoPictureCompress;
struct __declspec(uuid("000c1732-0000-0000-c000-000000000046"))
/* interface */ FullSeriesCollection;
struct __declspec(uuid("000c1733-0000-0000-c000-000000000046"))
/* interface */ IMsoCategory;
struct __declspec(uuid("000c1734-0000-0000-c000-000000000046"))
/* interface */ CategoryCollection;
enum XlCategoryLabelLevel;
enum XlSeriesNameLevel;
typedef long MsoRGBType;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(IAccessible, __uuidof(IAccessible));
_COM_SMARTPTR_TYPEDEF(_IMsoDispObj, __uuidof(_IMsoDispObj));
_COM_SMARTPTR_TYPEDEF(_IMsoOleAccDispObj, __uuidof(_IMsoOleAccDispObj));
_COM_SMARTPTR_TYPEDEF(TangramAdjustments, __uuidof(TangramAdjustments));
_COM_SMARTPTR_TYPEDEF(CalloutFormat, __uuidof(CalloutFormat));
_COM_SMARTPTR_TYPEDEF(ShapeNode, __uuidof(ShapeNode));
_COM_SMARTPTR_TYPEDEF(ShapeNodes, __uuidof(ShapeNodes));
_COM_SMARTPTR_TYPEDEF(Script, __uuidof(Script));
_COM_SMARTPTR_TYPEDEF(Scripts, __uuidof(Scripts));
_COM_SMARTPTR_TYPEDEF(TextEffectFormat, __uuidof(TextEffectFormat));
_COM_SMARTPTR_TYPEDEF(TextFrame, __uuidof(TextFrame));
_COM_SMARTPTR_TYPEDEF(IMsoDispCagNotifySink, __uuidof(IMsoDispCagNotifySink));
_COM_SMARTPTR_TYPEDEF(Balloon, __uuidof(Balloon));
_COM_SMARTPTR_TYPEDEF(BalloonCheckboxes, __uuidof(BalloonCheckboxes));
_COM_SMARTPTR_TYPEDEF(BalloonCheckbox, __uuidof(BalloonCheckbox));
_COM_SMARTPTR_TYPEDEF(BalloonLabels, __uuidof(BalloonLabels));
_COM_SMARTPTR_TYPEDEF(BalloonLabel, __uuidof(BalloonLabel));
_COM_SMARTPTR_TYPEDEF(AnswerWizardFiles, __uuidof(AnswerWizardFiles));
_COM_SMARTPTR_TYPEDEF(AnswerWizard, __uuidof(AnswerWizard));
_COM_SMARTPTR_TYPEDEF(DocumentProperty, __uuidof(DocumentProperty));
_COM_SMARTPTR_TYPEDEF(DocumentProperties, __uuidof(DocumentProperties));
_COM_SMARTPTR_TYPEDEF(IFoundFiles, __uuidof(IFoundFiles));
_COM_SMARTPTR_TYPEDEF(IFind, __uuidof(IFind));
_COM_SMARTPTR_TYPEDEF(FoundFiles, __uuidof(FoundFiles));
_COM_SMARTPTR_TYPEDEF(PropertyTest, __uuidof(PropertyTest));
_COM_SMARTPTR_TYPEDEF(PropertyTests, __uuidof(PropertyTests));
_COM_SMARTPTR_TYPEDEF(COMAddIn, __uuidof(COMAddIn));
_COM_SMARTPTR_TYPEDEF(COMAddIns, __uuidof(COMAddIns));
_COM_SMARTPTR_TYPEDEF(LanguageSettings, __uuidof(LanguageSettings));
_COM_SMARTPTR_TYPEDEF(ICommandBarsEvents, __uuidof(ICommandBarsEvents));
_COM_SMARTPTR_TYPEDEF(_CommandBarsEvents, __uuidof(_CommandBarsEvents));
_COM_SMARTPTR_TYPEDEF(_CommandBarComboBoxEvents, __uuidof(_CommandBarComboBoxEvents));
_COM_SMARTPTR_TYPEDEF(ICommandBarComboBoxEvents, __uuidof(ICommandBarComboBoxEvents));
_COM_SMARTPTR_TYPEDEF(_CommandBarButtonEvents, __uuidof(_CommandBarButtonEvents));
_COM_SMARTPTR_TYPEDEF(ICommandBarButtonEvents, __uuidof(ICommandBarButtonEvents));
_COM_SMARTPTR_TYPEDEF(WebPageFont, __uuidof(WebPageFont));
_COM_SMARTPTR_TYPEDEF(WebPageFonts, __uuidof(WebPageFonts));
_COM_SMARTPTR_TYPEDEF(HTMLProjectItem, __uuidof(HTMLProjectItem));
_COM_SMARTPTR_TYPEDEF(HTMLProjectItems, __uuidof(HTMLProjectItems));
_COM_SMARTPTR_TYPEDEF(HTMLProject, __uuidof(HTMLProject));
_COM_SMARTPTR_TYPEDEF(MsoDebugOptions, __uuidof(MsoDebugOptions));
_COM_SMARTPTR_TYPEDEF(FileDialogSelectedItems, __uuidof(FileDialogSelectedItems));
_COM_SMARTPTR_TYPEDEF(FileDialogFilter, __uuidof(FileDialogFilter));
_COM_SMARTPTR_TYPEDEF(FileDialogFilters, __uuidof(FileDialogFilters));
_COM_SMARTPTR_TYPEDEF(FileDialog, __uuidof(FileDialog));
_COM_SMARTPTR_TYPEDEF(IMsoEnvelopeVB, __uuidof(IMsoEnvelopeVB));
_COM_SMARTPTR_TYPEDEF(IMsoEnvelopeVBEvents, __uuidof(IMsoEnvelopeVBEvents));
_COM_SMARTPTR_TYPEDEF(Assistant, __uuidof(Assistant));
_COM_SMARTPTR_TYPEDEF(FileTypes, __uuidof(FileTypes));
_COM_SMARTPTR_TYPEDEF(OfficeDataSourceObject, __uuidof(OfficeDataSourceObject));
_COM_SMARTPTR_TYPEDEF(ODSOColumn, __uuidof(ODSOColumn));
_COM_SMARTPTR_TYPEDEF(ODSOColumns, __uuidof(ODSOColumns));
_COM_SMARTPTR_TYPEDEF(ODSOFilter, __uuidof(ODSOFilter));
_COM_SMARTPTR_TYPEDEF(ODSOFilters, __uuidof(ODSOFilters));
_COM_SMARTPTR_TYPEDEF(NewFile, __uuidof(NewFile));
_COM_SMARTPTR_TYPEDEF(WebComponent, __uuidof(WebComponent));
_COM_SMARTPTR_TYPEDEF(WebComponentWindowExternal, __uuidof(WebComponentWindowExternal));
_COM_SMARTPTR_TYPEDEF(WebComponentFormat, __uuidof(WebComponentFormat));
_COM_SMARTPTR_TYPEDEF(ILicWizExternal, __uuidof(ILicWizExternal));
_COM_SMARTPTR_TYPEDEF(ILicValidator, __uuidof(ILicValidator));
_COM_SMARTPTR_TYPEDEF(ILicAgent, __uuidof(ILicAgent));
_COM_SMARTPTR_TYPEDEF(IMsoEServicesDialog, __uuidof(IMsoEServicesDialog));
_COM_SMARTPTR_TYPEDEF(WebComponentProperties, __uuidof(WebComponentProperties));
_COM_SMARTPTR_TYPEDEF(SmartDocument, __uuidof(SmartDocument));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceMember, __uuidof(SharedWorkspaceMember));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceMembers, __uuidof(SharedWorkspaceMembers));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceTask, __uuidof(SharedWorkspaceTask));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceTasks, __uuidof(SharedWorkspaceTasks));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceFile, __uuidof(SharedWorkspaceFile));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceFiles, __uuidof(SharedWorkspaceFiles));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceFolder, __uuidof(SharedWorkspaceFolder));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceFolders, __uuidof(SharedWorkspaceFolders));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceLink, __uuidof(SharedWorkspaceLink));
_COM_SMARTPTR_TYPEDEF(SharedWorkspaceLinks, __uuidof(SharedWorkspaceLinks));
_COM_SMARTPTR_TYPEDEF(SharedWorkspace, __uuidof(SharedWorkspace));
_COM_SMARTPTR_TYPEDEF(Sync, __uuidof(Sync));
_COM_SMARTPTR_TYPEDEF(DocumentLibraryVersion, __uuidof(DocumentLibraryVersion));
_COM_SMARTPTR_TYPEDEF(DocumentLibraryVersions, __uuidof(DocumentLibraryVersions));
_COM_SMARTPTR_TYPEDEF(UserPermission, __uuidof(UserPermission));
_COM_SMARTPTR_TYPEDEF(Permission, __uuidof(Permission));
_COM_SMARTPTR_TYPEDEF(MsoDebugOptions_UTRunResult, __uuidof(MsoDebugOptions_UTRunResult));
_COM_SMARTPTR_TYPEDEF(MsoDebugOptions_UT, __uuidof(MsoDebugOptions_UT));
_COM_SMARTPTR_TYPEDEF(MsoDebugOptions_UTs, __uuidof(MsoDebugOptions_UTs));
_COM_SMARTPTR_TYPEDEF(MsoDebugOptions_UTManager, __uuidof(MsoDebugOptions_UTManager));
_COM_SMARTPTR_TYPEDEF(MetaProperty, __uuidof(MetaProperty));
_COM_SMARTPTR_TYPEDEF(MetaProperties, __uuidof(MetaProperties));
_COM_SMARTPTR_TYPEDEF(PolicyItem, __uuidof(PolicyItem));
_COM_SMARTPTR_TYPEDEF(ServerPolicy, __uuidof(ServerPolicy));
_COM_SMARTPTR_TYPEDEF(DocumentInspector, __uuidof(DocumentInspector));
_COM_SMARTPTR_TYPEDEF(DocumentInspectors, __uuidof(DocumentInspectors));
_COM_SMARTPTR_TYPEDEF(WorkflowTask, __uuidof(WorkflowTask));
_COM_SMARTPTR_TYPEDEF(WorkflowTasks, __uuidof(WorkflowTasks));
_COM_SMARTPTR_TYPEDEF(WorkflowTemplate, __uuidof(WorkflowTemplate));
_COM_SMARTPTR_TYPEDEF(WorkflowTemplates, __uuidof(WorkflowTemplates));
_COM_SMARTPTR_TYPEDEF(IDocumentInspector, __uuidof(IDocumentInspector));
_COM_SMARTPTR_TYPEDEF(SignatureSetup, __uuidof(SignatureSetup));
_COM_SMARTPTR_TYPEDEF(SignatureInfo, __uuidof(SignatureInfo));
_COM_SMARTPTR_TYPEDEF(Signature, __uuidof(Signature));
_COM_SMARTPTR_TYPEDEF(SignatureSet, __uuidof(SignatureSet));
_COM_SMARTPTR_TYPEDEF(SignatureProvider, __uuidof(SignatureProvider));
_COM_SMARTPTR_TYPEDEF(CustomXMLPrefixMapping, __uuidof(CustomXMLPrefixMapping));
_COM_SMARTPTR_TYPEDEF(CustomXMLPrefixMappings, __uuidof(CustomXMLPrefixMappings));
_COM_SMARTPTR_TYPEDEF(CustomXMLSchema, __uuidof(CustomXMLSchema));
_COM_SMARTPTR_TYPEDEF(_CustomXMLSchemaCollection, __uuidof(_CustomXMLSchemaCollection));
_COM_SMARTPTR_TYPEDEF(_CustomXMLPartEvents, __uuidof(_CustomXMLPartEvents));
_COM_SMARTPTR_TYPEDEF(ICustomXMLPartsEvents, __uuidof(ICustomXMLPartsEvents));
_COM_SMARTPTR_TYPEDEF(_CustomXMLPartsEvents, __uuidof(_CustomXMLPartsEvents));
_COM_SMARTPTR_TYPEDEF(_CustomXMLParts, __uuidof(_CustomXMLParts));
_COM_SMARTPTR_TYPEDEF(SoftEdgeFormat, __uuidof(SoftEdgeFormat));
_COM_SMARTPTR_TYPEDEF(ReflectionFormat, __uuidof(ReflectionFormat));
_COM_SMARTPTR_TYPEDEF(ColorFormat, __uuidof(ColorFormat));
_COM_SMARTPTR_TYPEDEF(LineFormat, __uuidof(LineFormat));
_COM_SMARTPTR_TYPEDEF(ThreeDFormat, __uuidof(ThreeDFormat));
_COM_SMARTPTR_TYPEDEF(GradientStop, __uuidof(GradientStop));
_COM_SMARTPTR_TYPEDEF(GradientStops, __uuidof(GradientStops));
_COM_SMARTPTR_TYPEDEF(GlowFormat, __uuidof(GlowFormat));
_COM_SMARTPTR_TYPEDEF(ThemeColor, __uuidof(ThemeColor));
_COM_SMARTPTR_TYPEDEF(ThemeColorScheme, __uuidof(ThemeColorScheme));
_COM_SMARTPTR_TYPEDEF(ThemeFont, __uuidof(ThemeFont));
_COM_SMARTPTR_TYPEDEF(ThemeFonts, __uuidof(ThemeFonts));
_COM_SMARTPTR_TYPEDEF(ThemeFontScheme, __uuidof(ThemeFontScheme));
_COM_SMARTPTR_TYPEDEF(ThemeEffectScheme, __uuidof(ThemeEffectScheme));
_COM_SMARTPTR_TYPEDEF(OfficeTheme, __uuidof(OfficeTheme));
_COM_SMARTPTR_TYPEDEF(_CustomTaskPane, __uuidof(_CustomTaskPane));
_COM_SMARTPTR_TYPEDEF(CustomTaskPaneEvents, __uuidof(CustomTaskPaneEvents));
_COM_SMARTPTR_TYPEDEF(_CustomTaskPaneEvents, __uuidof(_CustomTaskPaneEvents));
_COM_SMARTPTR_TYPEDEF(ICTPFactory, __uuidof(ICTPFactory));
_COM_SMARTPTR_TYPEDEF(ICustomTaskPaneConsumer, __uuidof(ICustomTaskPaneConsumer));
_COM_SMARTPTR_TYPEDEF(IRibbonUI, __uuidof(IRibbonUI));
_COM_SMARTPTR_TYPEDEF(IRibbonControl, __uuidof(IRibbonControl));
_COM_SMARTPTR_TYPEDEF(IRibbonExtensibility, __uuidof(IRibbonExtensibility));
_COM_SMARTPTR_TYPEDEF(ShadowFormat, __uuidof(ShadowFormat));
_COM_SMARTPTR_TYPEDEF(TextColumn2, __uuidof(TextColumn2));
_COM_SMARTPTR_TYPEDEF(IAssistance, __uuidof(IAssistance));
_COM_SMARTPTR_TYPEDEF(IMsoChartData, __uuidof(IMsoChartData));
_COM_SMARTPTR_TYPEDEF(IMsoCorners, __uuidof(IMsoCorners));
_COM_SMARTPTR_TYPEDEF(IMsoBorder, __uuidof(IMsoBorder));
_COM_SMARTPTR_TYPEDEF(IMsoInterior, __uuidof(IMsoInterior));
_COM_SMARTPTR_TYPEDEF(ChartFont, __uuidof(ChartFont));
_COM_SMARTPTR_TYPEDEF(ChartColorFormat, __uuidof(ChartColorFormat));
_COM_SMARTPTR_TYPEDEF(ChartFillFormat, __uuidof(ChartFillFormat));
_COM_SMARTPTR_TYPEDEF(IMsoHyperlinks, __uuidof(IMsoHyperlinks));
_COM_SMARTPTR_TYPEDEF(IMsoCharacters, __uuidof(IMsoCharacters));
_COM_SMARTPTR_TYPEDEF(TabStop2, __uuidof(TabStop2));
_COM_SMARTPTR_TYPEDEF(TabStops2, __uuidof(TabStops2));
_COM_SMARTPTR_TYPEDEF(RulerLevel2, __uuidof(RulerLevel2));
_COM_SMARTPTR_TYPEDEF(RulerLevels2, __uuidof(RulerLevels2));
_COM_SMARTPTR_TYPEDEF(Ruler2, __uuidof(Ruler2));
_COM_SMARTPTR_TYPEDEF(EncryptionProvider, __uuidof(EncryptionProvider));
_COM_SMARTPTR_TYPEDEF(IBlogExtensibility, __uuidof(IBlogExtensibility));
_COM_SMARTPTR_TYPEDEF(IBlogPictureExtensibility, __uuidof(IBlogPictureExtensibility));
_COM_SMARTPTR_TYPEDEF(IConverterPreferences, __uuidof(IConverterPreferences));
_COM_SMARTPTR_TYPEDEF(IConverterApplicationPreferences, __uuidof(IConverterApplicationPreferences));
_COM_SMARTPTR_TYPEDEF(IConverterUICallback, __uuidof(IConverterUICallback));
_COM_SMARTPTR_TYPEDEF(IConverter, __uuidof(IConverter));
_COM_SMARTPTR_TYPEDEF(SmartArtLayout, __uuidof(SmartArtLayout));
_COM_SMARTPTR_TYPEDEF(SmartArtLayouts, __uuidof(SmartArtLayouts));
_COM_SMARTPTR_TYPEDEF(SmartArtQuickStyle, __uuidof(SmartArtQuickStyle));
_COM_SMARTPTR_TYPEDEF(SmartArtQuickStyles, __uuidof(SmartArtQuickStyles));
_COM_SMARTPTR_TYPEDEF(SmartArtColor, __uuidof(SmartArtColor));
_COM_SMARTPTR_TYPEDEF(SmartArtColors, __uuidof(SmartArtColors));
_COM_SMARTPTR_TYPEDEF(PickerField, __uuidof(PickerField));
_COM_SMARTPTR_TYPEDEF(PickerFields, __uuidof(PickerFields));
_COM_SMARTPTR_TYPEDEF(PickerProperty, __uuidof(PickerProperty));
_COM_SMARTPTR_TYPEDEF(PickerProperties, __uuidof(PickerProperties));
_COM_SMARTPTR_TYPEDEF(PickerResult, __uuidof(PickerResult));
_COM_SMARTPTR_TYPEDEF(PickerResults, __uuidof(PickerResults));
_COM_SMARTPTR_TYPEDEF(PickerDialog, __uuidof(PickerDialog));
_COM_SMARTPTR_TYPEDEF(IMsoContactCard, __uuidof(IMsoContactCard));
_COM_SMARTPTR_TYPEDEF(EffectParameter, __uuidof(EffectParameter));
_COM_SMARTPTR_TYPEDEF(EffectParameters, __uuidof(EffectParameters));
_COM_SMARTPTR_TYPEDEF(PictureEffect, __uuidof(PictureEffect));
_COM_SMARTPTR_TYPEDEF(PictureEffects, __uuidof(PictureEffects));
_COM_SMARTPTR_TYPEDEF(FillFormat, __uuidof(FillFormat));
_COM_SMARTPTR_TYPEDEF(Font2, __uuidof(Font2));
_COM_SMARTPTR_TYPEDEF(BulletFormat2, __uuidof(BulletFormat2));
_COM_SMARTPTR_TYPEDEF(ParagraphFormat2, __uuidof(ParagraphFormat2));
_COM_SMARTPTR_TYPEDEF(Crop, __uuidof(Crop));
_COM_SMARTPTR_TYPEDEF(PictureFormat, __uuidof(PictureFormat));
_COM_SMARTPTR_TYPEDEF(ContactCard, __uuidof(ContactCard));
_COM_SMARTPTR_TYPEDEF(TextRange2, __uuidof(TextRange2));
_COM_SMARTPTR_TYPEDEF(TextFrame2, __uuidof(TextFrame2));
_COM_SMARTPTR_TYPEDEF(IMsoChartFormat, __uuidof(IMsoChartFormat));
_COM_SMARTPTR_TYPEDEF(IMsoLegend, __uuidof(IMsoLegend));
_COM_SMARTPTR_TYPEDEF(IMsoWalls, __uuidof(IMsoWalls));
_COM_SMARTPTR_TYPEDEF(IMsoFloor, __uuidof(IMsoFloor));
_COM_SMARTPTR_TYPEDEF(IMsoPlotArea, __uuidof(IMsoPlotArea));
_COM_SMARTPTR_TYPEDEF(IMsoChartArea, __uuidof(IMsoChartArea));
_COM_SMARTPTR_TYPEDEF(IMsoSeriesLines, __uuidof(IMsoSeriesLines));
_COM_SMARTPTR_TYPEDEF(IMsoLeaderLines, __uuidof(IMsoLeaderLines));
_COM_SMARTPTR_TYPEDEF(GridLines, __uuidof(GridLines));
_COM_SMARTPTR_TYPEDEF(IMsoUpBars, __uuidof(IMsoUpBars));
_COM_SMARTPTR_TYPEDEF(IMsoDownBars, __uuidof(IMsoDownBars));
_COM_SMARTPTR_TYPEDEF(IMsoLegendKey, __uuidof(IMsoLegendKey));
_COM_SMARTPTR_TYPEDEF(LegendEntry, __uuidof(LegendEntry));
_COM_SMARTPTR_TYPEDEF(LegendEntries, __uuidof(LegendEntries));
_COM_SMARTPTR_TYPEDEF(IMsoErrorBars, __uuidof(IMsoErrorBars));
_COM_SMARTPTR_TYPEDEF(IMsoSeries, __uuidof(IMsoSeries));
_COM_SMARTPTR_TYPEDEF(SeriesCollection, __uuidof(SeriesCollection));
_COM_SMARTPTR_TYPEDEF(IMsoDataLabel, __uuidof(IMsoDataLabel));
_COM_SMARTPTR_TYPEDEF(IMsoTrendline, __uuidof(IMsoTrendline));
_COM_SMARTPTR_TYPEDEF(Trendlines, __uuidof(Trendlines));
_COM_SMARTPTR_TYPEDEF(IMsoDataLabels, __uuidof(IMsoDataLabels));
_COM_SMARTPTR_TYPEDEF(ChartPoint, __uuidof(ChartPoint));
_COM_SMARTPTR_TYPEDEF(Points, __uuidof(Points));
_COM_SMARTPTR_TYPEDEF(IMsoDataTable, __uuidof(IMsoDataTable));
_COM_SMARTPTR_TYPEDEF(IMsoChartTitle, __uuidof(IMsoChartTitle));
_COM_SMARTPTR_TYPEDEF(IMsoAxisTitle, __uuidof(IMsoAxisTitle));
_COM_SMARTPTR_TYPEDEF(IMsoDisplayUnitLabel, __uuidof(IMsoDisplayUnitLabel));
_COM_SMARTPTR_TYPEDEF(IMsoTickLabels, __uuidof(IMsoTickLabels));
_COM_SMARTPTR_TYPEDEF(IMsoAxis, __uuidof(IMsoAxis));
_COM_SMARTPTR_TYPEDEF(Axes, __uuidof(Axes));
_COM_SMARTPTR_TYPEDEF(IMsoDropLines, __uuidof(IMsoDropLines));
_COM_SMARTPTR_TYPEDEF(IMsoHiLoLines, __uuidof(IMsoHiLoLines));
_COM_SMARTPTR_TYPEDEF(IMsoChartGroup, __uuidof(IMsoChartGroup));
_COM_SMARTPTR_TYPEDEF(ChartGroups, __uuidof(ChartGroups));
_COM_SMARTPTR_TYPEDEF(FullSeriesCollection, __uuidof(FullSeriesCollection));
_COM_SMARTPTR_TYPEDEF(IMsoCategory, __uuidof(IMsoCategory));
_COM_SMARTPTR_TYPEDEF(CategoryCollection, __uuidof(CategoryCollection));
_COM_SMARTPTR_TYPEDEF(_CommandBars, __uuidof(_CommandBars));
_COM_SMARTPTR_TYPEDEF(CommandBar, __uuidof(CommandBar));
_COM_SMARTPTR_TYPEDEF(CommandBarControl, __uuidof(CommandBarControl));
_COM_SMARTPTR_TYPEDEF(CommandBarControls, __uuidof(CommandBarControls));
_COM_SMARTPTR_TYPEDEF(_CommandBarButton, __uuidof(_CommandBarButton));
_COM_SMARTPTR_TYPEDEF(CommandBarPopup, __uuidof(CommandBarPopup));
_COM_SMARTPTR_TYPEDEF(_CommandBarComboBox, __uuidof(_CommandBarComboBox));
_COM_SMARTPTR_TYPEDEF(_CommandBarActiveX, __uuidof(_CommandBarActiveX));
_COM_SMARTPTR_TYPEDEF(ConnectorFormat, __uuidof(ConnectorFormat));
_COM_SMARTPTR_TYPEDEF(FreeformBuilder, __uuidof(FreeformBuilder));
_COM_SMARTPTR_TYPEDEF(GroupShapes, __uuidof(GroupShapes));
_COM_SMARTPTR_TYPEDEF(Shape, __uuidof(Shape));
_COM_SMARTPTR_TYPEDEF(ShapeRange, __uuidof(ShapeRange));
_COM_SMARTPTR_TYPEDEF(Shapes, __uuidof(Shapes));
_COM_SMARTPTR_TYPEDEF(CanvasShapes, __uuidof(CanvasShapes));
_COM_SMARTPTR_TYPEDEF(IMsoChart, __uuidof(IMsoChart));
_COM_SMARTPTR_TYPEDEF(FileSearch, __uuidof(FileSearch));
_COM_SMARTPTR_TYPEDEF(SearchFolders, __uuidof(SearchFolders));
_COM_SMARTPTR_TYPEDEF(ScopeFolders, __uuidof(ScopeFolders));
_COM_SMARTPTR_TYPEDEF(ScopeFolder, __uuidof(ScopeFolder));
_COM_SMARTPTR_TYPEDEF(SearchScope, __uuidof(SearchScope));
_COM_SMARTPTR_TYPEDEF(SearchScopes, __uuidof(SearchScopes));
_COM_SMARTPTR_TYPEDEF(IMsoDiagram, __uuidof(IMsoDiagram));
_COM_SMARTPTR_TYPEDEF(DiagramNodes, __uuidof(DiagramNodes));
_COM_SMARTPTR_TYPEDEF(DiagramNodeChildren, __uuidof(DiagramNodeChildren));
_COM_SMARTPTR_TYPEDEF(DiagramNode, __uuidof(DiagramNode));
_COM_SMARTPTR_TYPEDEF(CustomXMLNodes, __uuidof(CustomXMLNodes));
_COM_SMARTPTR_TYPEDEF(CustomXMLNode, __uuidof(CustomXMLNode));
_COM_SMARTPTR_TYPEDEF(CustomXMLValidationError, __uuidof(CustomXMLValidationError));
_COM_SMARTPTR_TYPEDEF(CustomXMLValidationErrors, __uuidof(CustomXMLValidationErrors));
_COM_SMARTPTR_TYPEDEF(_CustomXMLPart, __uuidof(_CustomXMLPart));
_COM_SMARTPTR_TYPEDEF(ICustomXMLPartEvents, __uuidof(ICustomXMLPartEvents));
_COM_SMARTPTR_TYPEDEF(SmartArt, __uuidof(SmartArt));
_COM_SMARTPTR_TYPEDEF(SmartArtNodes, __uuidof(SmartArtNodes));
_COM_SMARTPTR_TYPEDEF(SmartArtNode, __uuidof(SmartArtNode));

//
// Type library items
//

enum MsoLineDashStyle
{
    msoLineDashStyleMixed = -2,
    msoLineSolid = 1,
    msoLineSquareDot = 2,
    msoLineRoundDot = 3,
    msoLineDash = 4,
    msoLineDashDot = 5,
    msoLineDashDotDot = 6,
    msoLineLongDash = 7,
    msoLineLongDashDot = 8,
    msoLineLongDashDotDot = 9,
    msoLineSysDash = 10,
    msoLineSysDot = 11,
    msoLineSysDashDot = 12
};

enum MsoLineStyle
{
    msoLineStyleMixed = -2,
    msoLineSingle = 1,
    msoLineThinThin = 2,
    msoLineThinThick = 3,
    msoLineThickThin = 4,
    msoLineThickBetweenThin = 5
};

enum MsoArrowheadStyle
{
    msoArrowheadStyleMixed = -2,
    msoArrowheadNone = 1,
    msoArrowheadTriangle = 2,
    msoArrowheadOpen = 3,
    msoArrowheadStealth = 4,
    msoArrowheadDiamond = 5,
    msoArrowheadOval = 6
};

enum MsoArrowheadWidth
{
    msoArrowheadWidthMixed = -2,
    msoArrowheadNarrow = 1,
    msoArrowheadWidthMedium = 2,
    msoArrowheadWide = 3
};

enum MsoArrowheadLength
{
    msoArrowheadLengthMixed = -2,
    msoArrowheadShort = 1,
    msoArrowheadLengthMedium = 2,
    msoArrowheadLong = 3
};

enum MsoFillType
{
    msoFillMixed = -2,
    msoFillSolid = 1,
    msoFillPatterned = 2,
    msoFillGradient = 3,
    msoFillTextured = 4,
    msoFillBackground = 5,
    msoFillPicture = 6
};

enum MsoGradientStyle
{
    msoGradientMixed = -2,
    msoGradientHorizontal = 1,
    msoGradientVertical = 2,
    msoGradientDiagonalUp = 3,
    msoGradientDiagonalDown = 4,
    msoGradientFromCorner = 5,
    msoGradientFromTitle = 6,
    msoGradientFromCenter = 7
};

enum MsoGradientColorType
{
    msoGradientColorMixed = -2,
    msoGradientOneColor = 1,
    msoGradientTwoColors = 2,
    msoGradientPresetColors = 3,
    msoGradientMultiColor = 4
};

enum MsoTextureType
{
    msoTextureTypeMixed = -2,
    msoTexturePreset = 1,
    msoTextureUserDefined = 2
};

enum MsoPresetTexture
{
    msoPresetTextureMixed = -2,
    msoTexturePapyrus = 1,
    msoTextureCanvas = 2,
    msoTextureDenim = 3,
    msoTextureWovenMat = 4,
    msoTextureWaterDroplets = 5,
    msoTexturePaperBag = 6,
    msoTextureFishFossil = 7,
    msoTextureSand = 8,
    msoTextureGreenMarble = 9,
    msoTextureWhiteMarble = 10,
    msoTextureBrownMarble = 11,
    msoTextureGranite = 12,
    msoTextureNewsprint = 13,
    msoTextureRecycledPaper = 14,
    msoTextureParchment = 15,
    msoTextureStationery = 16,
    msoTextureBlueTissuePaper = 17,
    msoTexturePinkTissuePaper = 18,
    msoTexturePurpleMesh = 19,
    msoTextureBouquet = 20,
    msoTextureCork = 21,
    msoTextureWalnut = 22,
    msoTextureOak = 23,
    msoTextureMediumWood = 24
};

enum MsoPatternType
{
    msoPatternMixed = -2,
    msoPattern5Percent = 1,
    msoPattern10Percent = 2,
    msoPattern20Percent = 3,
    msoPattern25Percent = 4,
    msoPattern30Percent = 5,
    msoPattern40Percent = 6,
    msoPattern50Percent = 7,
    msoPattern60Percent = 8,
    msoPattern70Percent = 9,
    msoPattern75Percent = 10,
    msoPattern80Percent = 11,
    msoPattern90Percent = 12,
    msoPatternDarkHorizontal = 13,
    msoPatternDarkVertical = 14,
    msoPatternDarkDownwardDiagonal = 15,
    msoPatternDarkUpwardDiagonal = 16,
    msoPatternSmallCheckerBoard = 17,
    msoPatternTrellis = 18,
    msoPatternLightHorizontal = 19,
    msoPatternLightVertical = 20,
    msoPatternLightDownwardDiagonal = 21,
    msoPatternLightUpwardDiagonal = 22,
    msoPatternSmallGrid = 23,
    msoPatternDottedDiamond = 24,
    msoPatternWideDownwardDiagonal = 25,
    msoPatternWideUpwardDiagonal = 26,
    msoPatternDashedUpwardDiagonal = 27,
    msoPatternDashedDownwardDiagonal = 28,
    msoPatternNarrowVertical = 29,
    msoPatternNarrowHorizontal = 30,
    msoPatternDashedVertical = 31,
    msoPatternDashedHorizontal = 32,
    msoPatternLargeConfetti = 33,
    msoPatternLargeGrid = 34,
    msoPatternHorizontalBrick = 35,
    msoPatternLargeCheckerBoard = 36,
    msoPatternSmallConfetti = 37,
    msoPatternZigZag = 38,
    msoPatternSolidDiamond = 39,
    msoPatternDiagonalBrick = 40,
    msoPatternOutlinedDiamond = 41,
    msoPatternPlaid = 42,
    msoPatternSphere = 43,
    msoPatternWeave = 44,
    msoPatternDottedGrid = 45,
    msoPatternDivot = 46,
    msoPatternShingle = 47,
    msoPatternWave = 48,
    msoPatternHorizontal = 49,
    msoPatternVertical = 50,
    msoPatternCross = 51,
    msoPatternDownwardDiagonal = 52,
    msoPatternUpwardDiagonal = 53,
    msoPatternDiagonalCross = 54
};

enum MsoPresetGradientType
{
    msoPresetGradientMixed = -2,
    msoGradientEarlySunset = 1,
    msoGradientLateSunset = 2,
    msoGradientNightfall = 3,
    msoGradientDaybreak = 4,
    msoGradientHorizon = 5,
    msoGradientDesert = 6,
    msoGradientOcean = 7,
    msoGradientCalmWater = 8,
    msoGradientFire = 9,
    msoGradientFog = 10,
    msoGradientMoss = 11,
    msoGradientPeacock = 12,
    msoGradientWheat = 13,
    msoGradientParchment = 14,
    msoGradientMahogany = 15,
    msoGradientRainbow = 16,
    msoGradientRainbowII = 17,
    msoGradientGold = 18,
    msoGradientGoldII = 19,
    msoGradientBrass = 20,
    msoGradientChrome = 21,
    msoGradientChromeII = 22,
    msoGradientSilver = 23,
    msoGradientSapphire = 24
};

enum MsoShadowType
{
    msoShadowMixed = -2,
    msoShadow1 = 1,
    msoShadow2 = 2,
    msoShadow3 = 3,
    msoShadow4 = 4,
    msoShadow5 = 5,
    msoShadow6 = 6,
    msoShadow7 = 7,
    msoShadow8 = 8,
    msoShadow9 = 9,
    msoShadow10 = 10,
    msoShadow11 = 11,
    msoShadow12 = 12,
    msoShadow13 = 13,
    msoShadow14 = 14,
    msoShadow15 = 15,
    msoShadow16 = 16,
    msoShadow17 = 17,
    msoShadow18 = 18,
    msoShadow19 = 19,
    msoShadow20 = 20,
    msoShadow21 = 21,
    msoShadow22 = 22,
    msoShadow23 = 23,
    msoShadow24 = 24,
    msoShadow25 = 25,
    msoShadow26 = 26,
    msoShadow27 = 27,
    msoShadow28 = 28,
    msoShadow29 = 29,
    msoShadow30 = 30,
    msoShadow31 = 31,
    msoShadow32 = 32,
    msoShadow33 = 33,
    msoShadow34 = 34,
    msoShadow35 = 35,
    msoShadow36 = 36,
    msoShadow37 = 37,
    msoShadow38 = 38,
    msoShadow39 = 39,
    msoShadow40 = 40,
    msoShadow41 = 41,
    msoShadow42 = 42,
    msoShadow43 = 43
};

enum MsoPresetTextEffect
{
    msoTextEffectMixed = -2,
    msoTextEffect1 = 0,
    msoTextEffect2 = 1,
    msoTextEffect3 = 2,
    msoTextEffect4 = 3,
    msoTextEffect5 = 4,
    msoTextEffect6 = 5,
    msoTextEffect7 = 6,
    msoTextEffect8 = 7,
    msoTextEffect9 = 8,
    msoTextEffect10 = 9,
    msoTextEffect11 = 10,
    msoTextEffect12 = 11,
    msoTextEffect13 = 12,
    msoTextEffect14 = 13,
    msoTextEffect15 = 14,
    msoTextEffect16 = 15,
    msoTextEffect17 = 16,
    msoTextEffect18 = 17,
    msoTextEffect19 = 18,
    msoTextEffect20 = 19,
    msoTextEffect21 = 20,
    msoTextEffect22 = 21,
    msoTextEffect23 = 22,
    msoTextEffect24 = 23,
    msoTextEffect25 = 24,
    msoTextEffect26 = 25,
    msoTextEffect27 = 26,
    msoTextEffect28 = 27,
    msoTextEffect29 = 28,
    msoTextEffect30 = 29,
    msoTextEffect31 = 30,
    msoTextEffect32 = 31,
    msoTextEffect33 = 32,
    msoTextEffect34 = 33,
    msoTextEffect35 = 34,
    msoTextEffect36 = 35,
    msoTextEffect37 = 36,
    msoTextEffect38 = 37,
    msoTextEffect39 = 38,
    msoTextEffect40 = 39,
    msoTextEffect41 = 40,
    msoTextEffect42 = 41,
    msoTextEffect43 = 42,
    msoTextEffect44 = 43,
    msoTextEffect45 = 44,
    msoTextEffect46 = 45,
    msoTextEffect47 = 46,
    msoTextEffect48 = 47,
    msoTextEffect49 = 48,
    msoTextEffect50 = 49
};

enum MsoPresetTextEffectShape
{
    msoTextEffectShapeMixed = -2,
    msoTextEffectShapePlainText = 1,
    msoTextEffectShapeStop = 2,
    msoTextEffectShapeTriangleUp = 3,
    msoTextEffectShapeTriangleDown = 4,
    msoTextEffectShapeChevronUp = 5,
    msoTextEffectShapeChevronDown = 6,
    msoTextEffectShapeRingInside = 7,
    msoTextEffectShapeRingOutside = 8,
    msoTextEffectShapeArchUpCurve = 9,
    msoTextEffectShapeArchDownCurve = 10,
    msoTextEffectShapeCircleCurve = 11,
    msoTextEffectShapeButtonCurve = 12,
    msoTextEffectShapeArchUpPour = 13,
    msoTextEffectShapeArchDownPour = 14,
    msoTextEffectShapeCirclePour = 15,
    msoTextEffectShapeButtonPour = 16,
    msoTextEffectShapeCurveUp = 17,
    msoTextEffectShapeCurveDown = 18,
    msoTextEffectShapeCanUp = 19,
    msoTextEffectShapeCanDown = 20,
    msoTextEffectShapeWave1 = 21,
    msoTextEffectShapeWave2 = 22,
    msoTextEffectShapeDoubleWave1 = 23,
    msoTextEffectShapeDoubleWave2 = 24,
    msoTextEffectShapeInflate = 25,
    msoTextEffectShapeDeflate = 26,
    msoTextEffectShapeInflateBottom = 27,
    msoTextEffectShapeDeflateBottom = 28,
    msoTextEffectShapeInflateTop = 29,
    msoTextEffectShapeDeflateTop = 30,
    msoTextEffectShapeDeflateInflate = 31,
    msoTextEffectShapeDeflateInflateDeflate = 32,
    msoTextEffectShapeFadeRight = 33,
    msoTextEffectShapeFadeLeft = 34,
    msoTextEffectShapeFadeUp = 35,
    msoTextEffectShapeFadeDown = 36,
    msoTextEffectShapeSlantUp = 37,
    msoTextEffectShapeSlantDown = 38,
    msoTextEffectShapeCascadeUp = 39,
    msoTextEffectShapeCascadeDown = 40
};

enum MsoTextEffectAlignment
{
    msoTextEffectAlignmentMixed = -2,
    msoTextEffectAlignmentLeft = 1,
    msoTextEffectAlignmentCentered = 2,
    msoTextEffectAlignmentRight = 3,
    msoTextEffectAlignmentLetterJustify = 4,
    msoTextEffectAlignmentWordJustify = 5,
    msoTextEffectAlignmentStretchJustify = 6
};

enum MsoPresetLightingDirection
{
    msoPresetLightingDirectionMixed = -2,
    msoLightingTopLeft = 1,
    msoLightingTop = 2,
    msoLightingTopRight = 3,
    msoLightingLeft = 4,
    msoLightingNone = 5,
    msoLightingRight = 6,
    msoLightingBottomLeft = 7,
    msoLightingBottom = 8,
    msoLightingBottomRight = 9
};

enum MsoPresetLightingSoftness
{
    msoPresetLightingSoftnessMixed = -2,
    msoLightingDim = 1,
    msoLightingNormal = 2,
    msoLightingBright = 3
};

enum MsoPresetMaterial
{
    msoPresetMaterialMixed = -2,
    msoMaterialMatte = 1,
    msoMaterialPlastic = 2,
    msoMaterialMetal = 3,
    msoMaterialWireFrame = 4,
    msoMaterialMatte2 = 5,
    msoMaterialPlastic2 = 6,
    msoMaterialMetal2 = 7,
    msoMaterialWarmMatte = 8,
    msoMaterialTranslucentPowder = 9,
    msoMaterialPowder = 10,
    msoMaterialDarkEdge = 11,
    msoMaterialSoftEdge = 12,
    msoMaterialClear = 13,
    msoMaterialFlat = 14,
    msoMaterialSoftMetal = 15
};

enum MsoPresetExtrusionDirection
{
    msoPresetExtrusionDirectionMixed = -2,
    msoExtrusionBottomRight = 1,
    msoExtrusionBottom = 2,
    msoExtrusionBottomLeft = 3,
    msoExtrusionRight = 4,
    msoExtrusionNone = 5,
    msoExtrusionLeft = 6,
    msoExtrusionTopRight = 7,
    msoExtrusionTop = 8,
    msoExtrusionTopLeft = 9
};

enum MsoPresetThreeDFormat
{
    msoPresetThreeDFormatMixed = -2,
    msoThreeD1 = 1,
    msoThreeD2 = 2,
    msoThreeD3 = 3,
    msoThreeD4 = 4,
    msoThreeD5 = 5,
    msoThreeD6 = 6,
    msoThreeD7 = 7,
    msoThreeD8 = 8,
    msoThreeD9 = 9,
    msoThreeD10 = 10,
    msoThreeD11 = 11,
    msoThreeD12 = 12,
    msoThreeD13 = 13,
    msoThreeD14 = 14,
    msoThreeD15 = 15,
    msoThreeD16 = 16,
    msoThreeD17 = 17,
    msoThreeD18 = 18,
    msoThreeD19 = 19,
    msoThreeD20 = 20
};

enum MsoExtrusionColorType
{
    msoExtrusionColorTypeMixed = -2,
    msoExtrusionColorAutomatic = 1,
    msoExtrusionColorCustom = 2
};

enum MsoAlignCmd
{
    msoAlignLefts = 0,
    msoAlignCenters = 1,
    msoAlignRights = 2,
    msoAlignTops = 3,
    msoAlignMiddles = 4,
    msoAlignBottoms = 5
};

enum MsoDistributeCmd
{
    msoDistributeHorizontally = 0,
    msoDistributeVertically = 1
};

enum MsoConnectorType
{
    msoConnectorTypeMixed = -2,
    msoConnectorStraight = 1,
    msoConnectorElbow = 2,
    msoConnectorCurve = 3
};

enum MsoHorizontalAnchor
{
    msoHorizontalAnchorMixed = -2,
    msoAnchorNone = 1,
    msoAnchorCenter = 2
};

enum MsoVerticalAnchor
{
    msoVerticalAnchorMixed = -2,
    msoAnchorTop = 1,
    msoAnchorTopBaseline = 2,
    msoAnchorMiddle = 3,
    msoAnchorBottom = 4,
    msoAnchorBottomBaseLine = 5
};

enum MsoOrientation
{
    msoOrientationMixed = -2,
    msoOrientationHorizontal = 1,
    msoOrientationVertical = 2
};

enum MsoZOrderCmd
{
    msoBringToFront = 0,
    msoSendToBack = 1,
    msoBringForward = 2,
    msoSendBackward = 3,
    msoBringInFrontOfText = 4,
    msoSendBehindText = 5
};

enum MsoSegmentType
{
    msoSegmentLine = 0,
    msoSegmentCurve = 1
};

enum MsoEditingType
{
    msoEditingAuto = 0,
    msoEditingCorner = 1,
    msoEditingSmooth = 2,
    msoEditingSymmetric = 3
};

enum MsoAutoShapeType
{
    msoShapeMixed = -2,
    msoShapeRectangle = 1,
    msoShapeParallelogram = 2,
    msoShapeTrapezoid = 3,
    msoShapeDiamond = 4,
    msoShapeRoundedRectangle = 5,
    msoShapeOctagon = 6,
    msoShapeIsoscelesTriangle = 7,
    msoShapeRightTriangle = 8,
    msoShapeOval = 9,
    msoShapeHexagon = 10,
    msoShapeCross = 11,
    msoShapeRegularPentagon = 12,
    msoShapeCan = 13,
    msoShapeCube = 14,
    msoShapeBevel = 15,
    msoShapeFoldedCorner = 16,
    msoShapeSmileyFace = 17,
    msoShapeDonut = 18,
    msoShapeNoSymbol = 19,
    msoShapeBlockArc = 20,
    msoShapeHeart = 21,
    msoShapeLightningBolt = 22,
    msoShapeSun = 23,
    msoShapeMoon = 24,
    msoShapeArc = 25,
    msoShapeDoubleBracket = 26,
    msoShapeDoubleBrace = 27,
    msoShapePlaque = 28,
    msoShapeLeftBracket = 29,
    msoShapeRightBracket = 30,
    msoShapeLeftBrace = 31,
    msoShapeRightBrace = 32,
    msoShapeRightArrow = 33,
    msoShapeLeftArrow = 34,
    msoShapeUpArrow = 35,
    msoShapeDownArrow = 36,
    msoShapeLeftRightArrow = 37,
    msoShapeUpDownArrow = 38,
    msoShapeQuadArrow = 39,
    msoShapeLeftRightUpArrow = 40,
    msoShapeBentArrow = 41,
    msoShapeUTurnArrow = 42,
    msoShapeLeftUpArrow = 43,
    msoShapeBentUpArrow = 44,
    msoShapeCurvedRightArrow = 45,
    msoShapeCurvedLeftArrow = 46,
    msoShapeCurvedUpArrow = 47,
    msoShapeCurvedDownArrow = 48,
    msoShapeStripedRightArrow = 49,
    msoShapeNotchedRightArrow = 50,
    msoShapePentagon = 51,
    msoShapeChevron = 52,
    msoShapeRightArrowCallout = 53,
    msoShapeLeftArrowCallout = 54,
    msoShapeUpArrowCallout = 55,
    msoShapeDownArrowCallout = 56,
    msoShapeLeftRightArrowCallout = 57,
    msoShapeUpDownArrowCallout = 58,
    msoShapeQuadArrowCallout = 59,
    msoShapeCircularArrow = 60,
    msoShapeFlowchartProcess = 61,
    msoShapeFlowchartAlternateProcess = 62,
    msoShapeFlowchartDecision = 63,
    msoShapeFlowchartData = 64,
    msoShapeFlowchartPredefinedProcess = 65,
    msoShapeFlowchartInternalStorage = 66,
    msoShapeFlowchartDocument = 67,
    msoShapeFlowchartMultidocument = 68,
    msoShapeFlowchartTerminator = 69,
    msoShapeFlowchartPreparation = 70,
    msoShapeFlowchartManualInput = 71,
    msoShapeFlowchartManualOperation = 72,
    msoShapeFlowchartConnector = 73,
    msoShapeFlowchartOffpageConnector = 74,
    msoShapeFlowchartCard = 75,
    msoShapeFlowchartPunchedTape = 76,
    msoShapeFlowchartSummingJunction = 77,
    msoShapeFlowchartOr = 78,
    msoShapeFlowchartCollate = 79,
    msoShapeFlowchartSort = 80,
    msoShapeFlowchartExtract = 81,
    msoShapeFlowchartMerge = 82,
    msoShapeFlowchartStoredData = 83,
    msoShapeFlowchartDelay = 84,
    msoShapeFlowchartSequentialAccessStorage = 85,
    msoShapeFlowchartMagneticDisk = 86,
    msoShapeFlowchartDirectAccessStorage = 87,
    msoShapeFlowchartDisplay = 88,
    msoShapeExplosion1 = 89,
    msoShapeExplosion2 = 90,
    msoShape4pointStar = 91,
    msoShape5pointStar = 92,
    msoShape8pointStar = 93,
    msoShape16pointStar = 94,
    msoShape24pointStar = 95,
    msoShape32pointStar = 96,
    msoShapeUpRibbon = 97,
    msoShapeDownRibbon = 98,
    msoShapeCurvedUpRibbon = 99,
    msoShapeCurvedDownRibbon = 100,
    msoShapeVerticalScroll = 101,
    msoShapeHorizontalScroll = 102,
    msoShapeWave = 103,
    msoShapeDoubleWave = 104,
    msoShapeRectangularCallout = 105,
    msoShapeRoundedRectangularCallout = 106,
    msoShapeOvalCallout = 107,
    msoShapeCloudCallout = 108,
    msoShapeLineCallout1 = 109,
    msoShapeLineCallout2 = 110,
    msoShapeLineCallout3 = 111,
    msoShapeLineCallout4 = 112,
    msoShapeLineCallout1AccentBar = 113,
    msoShapeLineCallout2AccentBar = 114,
    msoShapeLineCallout3AccentBar = 115,
    msoShapeLineCallout4AccentBar = 116,
    msoShapeLineCallout1NoBorder = 117,
    msoShapeLineCallout2NoBorder = 118,
    msoShapeLineCallout3NoBorder = 119,
    msoShapeLineCallout4NoBorder = 120,
    msoShapeLineCallout1BorderandAccentBar = 121,
    msoShapeLineCallout2BorderandAccentBar = 122,
    msoShapeLineCallout3BorderandAccentBar = 123,
    msoShapeLineCallout4BorderandAccentBar = 124,
    msoShapeActionButtonCustom = 125,
    msoShapeActionButtonHome = 126,
    msoShapeActionButtonHelp = 127,
    msoShapeActionButtonInformation = 128,
    msoShapeActionButtonBackorPrevious = 129,
    msoShapeActionButtonForwardorNext = 130,
    msoShapeActionButtonBeginning = 131,
    msoShapeActionButtonEnd = 132,
    msoShapeActionButtonReturn = 133,
    msoShapeActionButtonDocument = 134,
    msoShapeActionButtonSound = 135,
    msoShapeActionButtonMovie = 136,
    msoShapeBalloon = 137,
    msoShapeNotPrimitive = 138,
    msoShapeFlowchartOfflineStorage = 139,
    msoShapeLeftRightRibbon = 140,
    msoShapeDiagonalStripe = 141,
    msoShapePie = 142,
    msoShapeNonIsoscelesTrapezoid = 143,
    msoShapeDecagon = 144,
    msoShapeHeptagon = 145,
    msoShapeDodecagon = 146,
    msoShape6pointStar = 147,
    msoShape7pointStar = 148,
    msoShape10pointStar = 149,
    msoShape12pointStar = 150,
    msoShapeRound1Rectangle = 151,
    msoShapeRound2SameRectangle = 152,
    msoShapeRound2DiagRectangle = 153,
    msoShapeSnipRoundRectangle = 154,
    msoShapeSnip1Rectangle = 155,
    msoShapeSnip2SameRectangle = 156,
    msoShapeSnip2DiagRectangle = 157,
    msoShapeFrame = 158,
    msoShapeHalfFrame = 159,
    msoShapeTear = 160,
    msoShapeChord = 161,
    msoShapeCorner = 162,
    msoShapeMathPlus = 163,
    msoShapeMathMinus = 164,
    msoShapeMathMultiply = 165,
    msoShapeMathDivide = 166,
    msoShapeMathEqual = 167,
    msoShapeMathNotEqual = 168,
    msoShapeCornerTabs = 169,
    msoShapeSquareTabs = 170,
    msoShapePlaqueTabs = 171,
    msoShapeGear6 = 172,
    msoShapeGear9 = 173,
    msoShapeFunnel = 174,
    msoShapePieWedge = 175,
    msoShapeLeftCircularArrow = 176,
    msoShapeLeftRightCircularArrow = 177,
    msoShapeSwooshArrow = 178,
    msoShapeCloud = 179,
    msoShapeChartX = 180,
    msoShapeChartStar = 181,
    msoShapeChartPlus = 182,
    msoShapeLineInverse = 183
};

enum MsoShapeType
{
    msoShapeTypeMixed = -2,
    msoAutoShape = 1,
    msoCallout = 2,
    msoChart = 3,
    msoComment = 4,
    msoFreeform = 5,
    msoGroup = 6,
    msoEmbeddedOLEObject = 7,
    msoFormControl = 8,
    msoLine = 9,
    msoLinkedOLEObject = 10,
    msoLinkedPicture = 11,
    msoOLEControlObject = 12,
    msoPicture = 13,
    msoPlaceholder = 14,
    msoTextEffect = 15,
    msoMedia = 16,
    msoTextBox = 17,
    msoScriptAnchor = 18,
    msoTable = 19,
    msoCanvas = 20,
    msoDiagram = 21,
    msoInk = 22,
    msoInkComment = 23,
    msoSmartArt = 24,
    msoSlicer = 25,
    msoWebVideo = 26
};

enum MsoFlipCmd
{
    msoFlipHorizontal = 0,
    msoFlipVertical = 1
};

enum MsoTriState
{
    msoTrue = -1,
    msoFalse = 0,
    msoCTrue = 1,
    msoTriStateToggle = -3,
    msoTriStateMixed = -2
};

enum MsoColorType
{
    msoColorTypeMixed = -2,
    msoColorTypeRGB = 1,
    msoColorTypeScheme = 2,
    msoColorTypeCMYK = 3,
    msoColorTypeCMS = 4,
    msoColorTypeInk = 5
};

enum MsoPictureColorType
{
    msoPictureMixed = -2,
    msoPictureAutomatic = 1,
    msoPictureGrayscale = 2,
    msoPictureBlackAndWhite = 3,
    msoPictureWatermark = 4
};

enum MsoCalloutAngleType
{
    msoCalloutAngleMixed = -2,
    msoCalloutAngleAutomatic = 1,
    msoCalloutAngle30 = 2,
    msoCalloutAngle45 = 3,
    msoCalloutAngle60 = 4,
    msoCalloutAngle90 = 5
};

enum MsoCalloutDropType
{
    msoCalloutDropMixed = -2,
    msoCalloutDropCustom = 1,
    msoCalloutDropTop = 2,
    msoCalloutDropCenter = 3,
    msoCalloutDropBottom = 4
};

enum MsoCalloutType
{
    msoCalloutMixed = -2,
    msoCalloutOne = 1,
    msoCalloutTwo = 2,
    msoCalloutThree = 3,
    msoCalloutFour = 4
};

enum MsoBlackWhiteMode
{
    msoBlackWhiteMixed = -2,
    msoBlackWhiteAutomatic = 1,
    msoBlackWhiteGrayScale = 2,
    msoBlackWhiteLightGrayScale = 3,
    msoBlackWhiteInverseGrayScale = 4,
    msoBlackWhiteGrayOutline = 5,
    msoBlackWhiteBlackTextAndLine = 6,
    msoBlackWhiteHighContrast = 7,
    msoBlackWhiteBlack = 8,
    msoBlackWhiteWhite = 9,
    msoBlackWhiteDontShow = 10
};

enum MsoMixedType
{
    msoIntegerMixed = 32768,
    msoSingleMixed = 0x80000000
};

enum MsoTextOrientation
{
    msoTextOrientationMixed = -2,
    msoTextOrientationHorizontal = 1,
    msoTextOrientationUpward = 2,
    msoTextOrientationDownward = 3,
    msoTextOrientationVerticalFarEast = 4,
    msoTextOrientationVertical = 5,
    msoTextOrientationHorizontalRotatedFarEast = 6
};

enum MsoScaleFrom
{
    msoScaleFromTopLeft = 0,
    msoScaleFromMiddle = 1,
    msoScaleFromBottomRight = 2
};

enum MsoBarPosition
{
    msoBarLeft = 0,
    msoBarTop = 1,
    msoBarRight = 2,
    msoBarBottom = 3,
    msoBarFloating = 4,
    msoBarPopup = 5,
    msoBarMenuBar = 6
};

enum MsoBarProtection
{
    msoBarNoProtection = 0,
    msoBarNoCustomize = 1,
    msoBarNoResize = 2,
    msoBarNoMove = 4,
    msoBarNoChangeVisible = 8,
    msoBarNoChangeDock = 16,
    msoBarNoVerticalDock = 32,
    msoBarNoHorizontalDock = 64
};

enum MsoBarType
{
    msoBarTypeNormal = 0,
    msoBarTypeMenuBar = 1,
    msoBarTypePopup = 2
};

enum MsoControlType
{
    msoControlCustom = 0,
    msoControlButton = 1,
    msoControlEdit = 2,
    msoControlDropdown = 3,
    msoControlComboBox = 4,
    msoControlButtonDropdown = 5,
    msoControlSplitDropdown = 6,
    msoControlOCXDropdown = 7,
    msoControlGenericDropdown = 8,
    msoControlGraphicDropdown = 9,
    msoControlPopup = 10,
    msoControlGraphicPopup = 11,
    msoControlButtonPopup = 12,
    msoControlSplitButtonPopup = 13,
    msoControlSplitButtonMRUPopup = 14,
    msoControlLabel = 15,
    msoControlExpandingGrid = 16,
    msoControlSplitExpandingGrid = 17,
    msoControlGrid = 18,
    msoControlGauge = 19,
    msoControlGraphicCombo = 20,
    msoControlPane = 21,
    msoControlActiveX = 22,
    msoControlSpinner = 23,
    msoControlLabelEx = 24,
    msoControlWorkPane = 25,
    msoControlAutoCompleteCombo = 26
};

enum MsoButtonState
{
    msoButtonUp = 0,
    msoButtonDown = -1,
    msoButtonMixed = 2
};

enum MsoControlOLEUsage
{
    msoControlOLEUsageNeither = 0,
    msoControlOLEUsageServer = 1,
    msoControlOLEUsageClient = 2,
    msoControlOLEUsageBoth = 3
};

enum MsoButtonStyleHidden
{
    msoButtonWrapText = 4,
    msoButtonTextBelow = 8
};

enum MsoButtonStyle
{
    msoButtonAutomatic = 0,
    msoButtonIcon = 1,
    msoButtonCaption = 2,
    msoButtonIconAndCaption = 3,
    msoButtonIconAndWrapCaption = 7,
    msoButtonIconAndCaptionBelow = 11,
    msoButtonWrapCaption = 14,
    msoButtonIconAndWrapCaptionBelow = 15
};

enum MsoComboStyle
{
    msoComboNormal = 0,
    msoComboLabel = 1
};

enum MsoOLEMenuGroup
{
    msoOLEMenuGroupNone = -1,
    msoOLEMenuGroupFile = 0,
    msoOLEMenuGroupEdit = 1,
    msoOLEMenuGroupContainer = 2,
    msoOLEMenuGroupObject = 3,
    msoOLEMenuGroupWindow = 4,
    msoOLEMenuGroupHelp = 5
};

enum MsoMenuAnimation
{
    msoMenuAnimationNone = 0,
    msoMenuAnimationRandom = 1,
    msoMenuAnimationUnfold = 2,
    msoMenuAnimationSlide = 3
};

enum MsoBarRow
{
    msoBarRowFirst = 0,
    msoBarRowLast = -1
};

enum MsoCommandBarButtonHyperlinkType
{
    msoCommandBarButtonHyperlinkNone = 0,
    msoCommandBarButtonHyperlinkOpen = 1,
    msoCommandBarButtonHyperlinkInsertPicture = 2
};

enum MsoHyperlinkType
{
    msoHyperlinkRange = 0,
    msoHyperlinkShape = 1,
    msoHyperlinkInlineShape = 2
};

enum MsoExtraInfoMethod
{
    msoMethodGet = 0,
    msoMethodPost = 1
};

enum MsoAnimationType
{
    msoAnimationIdle = 1,
    msoAnimationGreeting = 2,
    msoAnimationGoodbye = 3,
    msoAnimationBeginSpeaking = 4,
    msoAnimationRestPose = 5,
    msoAnimationCharacterSuccessMajor = 6,
    msoAnimationGetAttentionMajor = 11,
    msoAnimationGetAttentionMinor = 12,
    msoAnimationSearching = 13,
    msoAnimationPrinting = 18,
    msoAnimationGestureRight = 19,
    msoAnimationWritingNotingSomething = 22,
    msoAnimationWorkingAtSomething = 23,
    msoAnimationThinking = 24,
    msoAnimationSendingMail = 25,
    msoAnimationListensToComputer = 26,
    msoAnimationDisappear = 31,
    msoAnimationAppear = 32,
    msoAnimationGetArtsy = 100,
    msoAnimationGetTechy = 101,
    msoAnimationGetWizardy = 102,
    msoAnimationCheckingSomething = 103,
    msoAnimationLookDown = 104,
    msoAnimationLookDownLeft = 105,
    msoAnimationLookDownRight = 106,
    msoAnimationLookLeft = 107,
    msoAnimationLookRight = 108,
    msoAnimationLookUp = 109,
    msoAnimationLookUpLeft = 110,
    msoAnimationLookUpRight = 111,
    msoAnimationSaving = 112,
    msoAnimationGestureDown = 113,
    msoAnimationGestureLeft = 114,
    msoAnimationGestureUp = 115,
    msoAnimationEmptyTrash = 116
};

enum MsoButtonSetType
{
    msoButtonSetNone = 0,
    msoButtonSetOK = 1,
    msoButtonSetCancel = 2,
    msoButtonSetOkCancel = 3,
    msoButtonSetYesNo = 4,
    msoButtonSetYesNoCancel = 5,
    msoButtonSetBackClose = 6,
    msoButtonSetNextClose = 7,
    msoButtonSetBackNextClose = 8,
    msoButtonSetRetryCancel = 9,
    msoButtonSetAbortRetryIgnore = 10,
    msoButtonSetSearchClose = 11,
    msoButtonSetBackNextSnooze = 12,
    msoButtonSetTipsOptionsClose = 13,
    msoButtonSetYesAllNoCancel = 14
};

enum MsoIconType
{
    msoIconNone = 0,
    msoIconAlert = 2,
    msoIconTip = 3,
    msoIconAlertInfo = 4,
    msoIconAlertWarning = 5,
    msoIconAlertQuery = 6,
    msoIconAlertCritical = 7
};

enum MsoBalloonType
{
    msoBalloonTypeButtons = 0,
    msoBalloonTypeBullets = 1,
    msoBalloonTypeNumbers = 2
};

enum MsoModeType
{
    msoModeModal = 0,
    msoModeAutoDown = 1,
    msoModeModeless = 2
};

enum MsoBalloonErrorType
{
    msoBalloonErrorNone = 0,
    msoBalloonErrorOther = 1,
    msoBalloonErrorTooBig = 2,
    msoBalloonErrorOutOfMemory = 3,
    msoBalloonErrorBadPictureRef = 4,
    msoBalloonErrorBadReference = 5,
    msoBalloonErrorButtonlessModal = 6,
    msoBalloonErrorButtonModeless = 7,
    msoBalloonErrorBadCharacter = 8,
    msoBalloonErrorCOMFailure = 9,
    msoBalloonErrorCharNotTopmostForModal = 10,
    msoBalloonErrorTooManyControls = 11
};

enum MsoWizardActType
{
    msoWizardActInactive = 0,
    msoWizardActActive = 1,
    msoWizardActSuspend = 2,
    msoWizardActResume = 3
};

enum MsoWizardMsgType
{
    msoWizardMsgLocalStateOn = 1,
    msoWizardMsgLocalStateOff = 2,
    msoWizardMsgShowHelp = 3,
    msoWizardMsgSuspending = 4,
    msoWizardMsgResuming = 5
};

enum MsoBalloonButtonType
{
    msoBalloonButtonYesToAll = -15,
    msoBalloonButtonOptions = -14,
    msoBalloonButtonTips = -13,
    msoBalloonButtonClose = -12,
    msoBalloonButtonSnooze = -11,
    msoBalloonButtonSearch = -10,
    msoBalloonButtonIgnore = -9,
    msoBalloonButtonAbort = -8,
    msoBalloonButtonRetry = -7,
    msoBalloonButtonNext = -6,
    msoBalloonButtonBack = -5,
    msoBalloonButtonNo = -4,
    msoBalloonButtonYes = -3,
    msoBalloonButtonCancel = -2,
    msoBalloonButtonOK = -1,
    msoBalloonButtonNull = 0
};

enum DocProperties
{
    offPropertyTypeNumber = 1,
    offPropertyTypeBoolean = 2,
    offPropertyTypeDate = 3,
    offPropertyTypeString = 4,
    offPropertyTypeFloat = 5
};

enum MsoDocProperties
{
    msoPropertyTypeNumber = 1,
    msoPropertyTypeBoolean = 2,
    msoPropertyTypeDate = 3,
    msoPropertyTypeString = 4,
    msoPropertyTypeFloat = 5
};

enum MsoAppLanguageID
{
    msoLanguageIDInstall = 1,
    msoLanguageIDUI = 2,
    msoLanguageIDHelp = 3,
    msoLanguageIDExeMode = 4,
    msoLanguageIDUIPrevious = 5
};

enum MsoFarEastLineBreakLanguageID
{
    MsoFarEastLineBreakLanguageJapanese = 1041,
    MsoFarEastLineBreakLanguageKorean = 1042,
    MsoFarEastLineBreakLanguageSimplifiedChinese = 2052,
    MsoFarEastLineBreakLanguageTraditionalChinese = 1028
};

enum MsoFeatureInstall
{
    msoFeatureInstallNone = 0,
    msoFeatureInstallOnDemand = 1,
    msoFeatureInstallOnDemandWithUI = 2
};

struct __declspec(uuid("618736e0-3c3d-11cf-810c-00aa00389b71"))
IMsoAccessible : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_accParent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_accChildCount (
        /*[out,retval]*/ long * pcountChildren ) = 0;
      virtual HRESULT __stdcall get_accChild (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ IDispatch * * ppdispChild ) = 0;
      virtual HRESULT __stdcall get_accName (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ BSTR * pszName ) = 0;
      virtual HRESULT __stdcall get_accValue (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ BSTR * pszValue ) = 0;
      virtual HRESULT __stdcall get_accDescription (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ BSTR * pszDescription ) = 0;
      virtual HRESULT __stdcall get_accRole (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ VARIANT * pvarRole ) = 0;
      virtual HRESULT __stdcall get_accState (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ VARIANT * pvarState ) = 0;
      virtual HRESULT __stdcall get_accHelp (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ BSTR * pszHelp ) = 0;
      virtual HRESULT __stdcall get_accHelpTopic (
        /*[out]*/ BSTR * pszHelpFile,
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ long * pidTopic ) = 0;
      virtual HRESULT __stdcall get_accKeyboardShortcut (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ BSTR * pszKeyboardShortcut ) = 0;
      virtual HRESULT __stdcall get_accFocus (
        /*[out,retval]*/ VARIANT * pvarChild ) = 0;
      virtual HRESULT __stdcall get_accSelection (
        /*[out,retval]*/ VARIANT * pvarChildren ) = 0;
      virtual HRESULT __stdcall get_accDefaultAction (
        /*[in]*/ VARIANT varChild,
        /*[out,retval]*/ BSTR * pszDefaultAction ) = 0;
      virtual HRESULT __stdcall accSelect (
        /*[in]*/ long flagsSelect,
        /*[in]*/ VARIANT varChild = vtMissing ) = 0;
      virtual HRESULT __stdcall accLocation (
        /*[out]*/ long * pxLeft,
        /*[out]*/ long * pyTop,
        /*[out]*/ long * pcxWidth,
        /*[out]*/ long * pcyHeight,
        /*[in]*/ VARIANT varChild = vtMissing ) = 0;
      virtual HRESULT __stdcall accNavigate (
        /*[in]*/ long navDir,
        /*[in]*/ VARIANT varStart,
        /*[out,retval]*/ VARIANT * pvarEndUpAt ) = 0;
      virtual HRESULT __stdcall accHitTest (
        /*[in]*/ long xLeft,
        /*[in]*/ long yTop,
        /*[out,retval]*/ VARIANT * pvarChild ) = 0;
      virtual HRESULT __stdcall accDoDefaultAction (
        /*[in]*/ VARIANT varChild = vtMissing ) = 0;
      virtual HRESULT __stdcall put_accName (
        /*[in]*/ VARIANT varChild,
        /*[in]*/ BSTR pszName ) = 0;
      virtual HRESULT __stdcall put_accValue (
        /*[in]*/ VARIANT varChild,
        /*[in]*/ BSTR pszValue ) = 0;
};

struct __declspec(uuid("000c0300-0000-0000-c000-000000000046"))
_IMsoDispObj : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * plCreator ) = 0;
};

struct __declspec(uuid("000c0301-0000-0000-c000-000000000046"))
_IMsoOleAccDispObj : IMsoAccessible
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * plCreator ) = 0;
};

struct __declspec(uuid("000c0310-0000-0000-c000-000000000046"))
TangramAdjustments : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ float * Val ) = 0;
      virtual HRESULT __stdcall put_Item (
        /*[in]*/ int Index,
        /*[in]*/ float Val ) = 0;
};

struct __declspec(uuid("000c0311-0000-0000-c000-000000000046"))
CalloutFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall AutomaticLength ( ) = 0;
      virtual HRESULT __stdcall CustomDrop (
        /*[in]*/ float Drop ) = 0;
      virtual HRESULT __stdcall CustomLength (
        /*[in]*/ float Length ) = 0;
      virtual HRESULT __stdcall PresetDrop (
        /*[in]*/ enum MsoCalloutDropType DropType ) = 0;
      virtual HRESULT __stdcall get_Accent (
        /*[out,retval]*/ enum MsoTriState * Accent ) = 0;
      virtual HRESULT __stdcall put_Accent (
        /*[in]*/ enum MsoTriState Accent ) = 0;
      virtual HRESULT __stdcall get_Angle (
        /*[out,retval]*/ enum MsoCalloutAngleType * Angle ) = 0;
      virtual HRESULT __stdcall put_Angle (
        /*[in]*/ enum MsoCalloutAngleType Angle ) = 0;
      virtual HRESULT __stdcall get_AutoAttach (
        /*[out,retval]*/ enum MsoTriState * AutoAttach ) = 0;
      virtual HRESULT __stdcall put_AutoAttach (
        /*[in]*/ enum MsoTriState AutoAttach ) = 0;
      virtual HRESULT __stdcall get_AutoLength (
        /*[out,retval]*/ enum MsoTriState * AutoLength ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ enum MsoTriState * Border ) = 0;
      virtual HRESULT __stdcall put_Border (
        /*[in]*/ enum MsoTriState Border ) = 0;
      virtual HRESULT __stdcall get_Drop (
        /*[out,retval]*/ float * Drop ) = 0;
      virtual HRESULT __stdcall get_DropType (
        /*[out,retval]*/ enum MsoCalloutDropType * DropType ) = 0;
      virtual HRESULT __stdcall get_Gap (
        /*[out,retval]*/ float * Gap ) = 0;
      virtual HRESULT __stdcall put_Gap (
        /*[in]*/ float Gap ) = 0;
      virtual HRESULT __stdcall get_Length (
        /*[out,retval]*/ float * Length ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoCalloutType * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum MsoCalloutType Type ) = 0;
};

struct __declspec(uuid("000c0318-0000-0000-c000-000000000046"))
ShapeNode : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_EditingType (
        /*[out,retval]*/ enum MsoEditingType * EditingType ) = 0;
      virtual HRESULT __stdcall get_Points (
        /*[out,retval]*/ VARIANT * Points ) = 0;
      virtual HRESULT __stdcall get_SegmentType (
        /*[out,retval]*/ enum MsoSegmentType * SegmentType ) = 0;
};

struct __declspec(uuid("000c0319-0000-0000-c000-000000000046"))
ShapeNodes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct ShapeNode * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ int Index ) = 0;
      virtual HRESULT __stdcall Insert (
        /*[in]*/ int Index,
        /*[in]*/ enum MsoSegmentType SegmentType,
        /*[in]*/ enum MsoEditingType EditingType,
        /*[in]*/ float X1,
        /*[in]*/ float Y1,
        /*[in]*/ float X2,
        /*[in]*/ float Y2,
        /*[in]*/ float X3,
        /*[in]*/ float Y3 ) = 0;
      virtual HRESULT __stdcall SetEditingType (
        /*[in]*/ int Index,
        /*[in]*/ enum MsoEditingType EditingType ) = 0;
      virtual HRESULT __stdcall SetPosition (
        /*[in]*/ int Index,
        /*[in]*/ float X1,
        /*[in]*/ float Y1 ) = 0;
      virtual HRESULT __stdcall SetSegmentType (
        /*[in]*/ int Index,
        /*[in]*/ enum MsoSegmentType SegmentType ) = 0;
};

enum MsoScriptLanguage
{
    msoScriptLanguageJava = 1,
    msoScriptLanguageVisualBasic = 2,
    msoScriptLanguageASP = 3,
    msoScriptLanguageOther = 4
};

enum MsoScriptLocation
{
    msoScriptLocationInHead = 1,
    msoScriptLocationInBody = 2
};

struct __declspec(uuid("000c0341-0000-0000-c000-000000000046"))
Script : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Extended (
        /*[out,retval]*/ BSTR * Extended ) = 0;
      virtual HRESULT __stdcall put_Extended (
        /*[in]*/ BSTR Extended ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * Id ) = 0;
      virtual HRESULT __stdcall put_Id (
        /*[in]*/ BSTR Id ) = 0;
      virtual HRESULT __stdcall get_Language (
        /*[out,retval]*/ enum MsoScriptLanguage * Language ) = 0;
      virtual HRESULT __stdcall put_Language (
        /*[in]*/ enum MsoScriptLanguage Language ) = 0;
      virtual HRESULT __stdcall get_Location (
        /*[out,retval]*/ enum MsoScriptLocation * Location ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Shape (
        /*[out,retval]*/ IDispatch * * Object ) = 0;
      virtual HRESULT __stdcall get_ScriptText (
        /*[out,retval]*/ BSTR * Script ) = 0;
      virtual HRESULT __stdcall put_ScriptText (
        /*[in]*/ BSTR Script ) = 0;
};

struct __declspec(uuid("000c0340-0000-0000-c000-000000000046"))
Scripts : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Script * * Item ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ IDispatch * Anchor,
        /*[in]*/ enum MsoScriptLocation Location,
        /*[in]*/ enum MsoScriptLanguage Language,
        /*[in]*/ BSTR Id,
        /*[in]*/ BSTR Extended,
        /*[in]*/ BSTR ScriptText,
        /*[out,retval]*/ struct Script * * Add ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
};

struct __declspec(uuid("000c031f-0000-0000-c000-000000000046"))
TextEffectFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall ToggleVerticalText ( ) = 0;
      virtual HRESULT __stdcall get_Alignment (
        /*[out,retval]*/ enum MsoTextEffectAlignment * Alignment ) = 0;
      virtual HRESULT __stdcall put_Alignment (
        /*[in]*/ enum MsoTextEffectAlignment Alignment ) = 0;
      virtual HRESULT __stdcall get_FontBold (
        /*[out,retval]*/ enum MsoTriState * FontBold ) = 0;
      virtual HRESULT __stdcall put_FontBold (
        /*[in]*/ enum MsoTriState FontBold ) = 0;
      virtual HRESULT __stdcall get_FontItalic (
        /*[out,retval]*/ enum MsoTriState * FontItalic ) = 0;
      virtual HRESULT __stdcall put_FontItalic (
        /*[in]*/ enum MsoTriState FontItalic ) = 0;
      virtual HRESULT __stdcall get_FontName (
        /*[out,retval]*/ BSTR * FontName ) = 0;
      virtual HRESULT __stdcall put_FontName (
        /*[in]*/ BSTR FontName ) = 0;
      virtual HRESULT __stdcall get_FontSize (
        /*[out,retval]*/ float * FontSize ) = 0;
      virtual HRESULT __stdcall put_FontSize (
        /*[in]*/ float FontSize ) = 0;
      virtual HRESULT __stdcall get_KernedPairs (
        /*[out,retval]*/ enum MsoTriState * KernedPairs ) = 0;
      virtual HRESULT __stdcall put_KernedPairs (
        /*[in]*/ enum MsoTriState KernedPairs ) = 0;
      virtual HRESULT __stdcall get_NormalizedHeight (
        /*[out,retval]*/ enum MsoTriState * NormalizedHeight ) = 0;
      virtual HRESULT __stdcall put_NormalizedHeight (
        /*[in]*/ enum MsoTriState NormalizedHeight ) = 0;
      virtual HRESULT __stdcall get_PresetShape (
        /*[out,retval]*/ enum MsoPresetTextEffectShape * PresetShape ) = 0;
      virtual HRESULT __stdcall put_PresetShape (
        /*[in]*/ enum MsoPresetTextEffectShape PresetShape ) = 0;
      virtual HRESULT __stdcall get_PresetTextEffect (
        /*[out,retval]*/ enum MsoPresetTextEffect * Preset ) = 0;
      virtual HRESULT __stdcall put_PresetTextEffect (
        /*[in]*/ enum MsoPresetTextEffect Preset ) = 0;
      virtual HRESULT __stdcall get_RotatedChars (
        /*[out,retval]*/ enum MsoTriState * RotatedChars ) = 0;
      virtual HRESULT __stdcall put_RotatedChars (
        /*[in]*/ enum MsoTriState RotatedChars ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * Text ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR Text ) = 0;
      virtual HRESULT __stdcall get_Tracking (
        /*[out,retval]*/ float * Tracking ) = 0;
      virtual HRESULT __stdcall put_Tracking (
        /*[in]*/ float Tracking ) = 0;
};

struct __declspec(uuid("000c0320-0000-0000-c000-000000000046"))
TextFrame : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_MarginBottom (
        /*[out,retval]*/ float * MarginBottom ) = 0;
      virtual HRESULT __stdcall put_MarginBottom (
        /*[in]*/ float MarginBottom ) = 0;
      virtual HRESULT __stdcall get_MarginLeft (
        /*[out,retval]*/ float * MarginLeft ) = 0;
      virtual HRESULT __stdcall put_MarginLeft (
        /*[in]*/ float MarginLeft ) = 0;
      virtual HRESULT __stdcall get_MarginRight (
        /*[out,retval]*/ float * MarginRight ) = 0;
      virtual HRESULT __stdcall put_MarginRight (
        /*[in]*/ float MarginRight ) = 0;
      virtual HRESULT __stdcall get_MarginTop (
        /*[out,retval]*/ float * MarginTop ) = 0;
      virtual HRESULT __stdcall put_MarginTop (
        /*[in]*/ float MarginTop ) = 0;
      virtual HRESULT __stdcall get_Orientation (
        /*[out,retval]*/ enum MsoTextOrientation * Orientation ) = 0;
      virtual HRESULT __stdcall put_Orientation (
        /*[in]*/ enum MsoTextOrientation Orientation ) = 0;
};

struct __declspec(uuid("000c0359-0000-0000-c000-000000000046"))
IMsoDispCagNotifySink : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall InsertClip (
        /*[in]*/ IUnknown * pClipMoniker,
        /*[in]*/ IUnknown * pItemMoniker ) = 0;
      virtual HRESULT __stdcall WindowIsClosing ( ) = 0;
};

struct __declspec(uuid("000c0324-0000-0000-c000-000000000046"))
Balloon : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Checkboxes (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Labels (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall put_BalloonType (
        /*[in]*/ enum MsoBalloonType pbty ) = 0;
      virtual HRESULT __stdcall get_BalloonType (
        /*[out,retval]*/ enum MsoBalloonType * pbty ) = 0;
      virtual HRESULT __stdcall put_Icon (
        /*[in]*/ enum MsoIconType picn ) = 0;
      virtual HRESULT __stdcall get_Icon (
        /*[out,retval]*/ enum MsoIconType * picn ) = 0;
      virtual HRESULT __stdcall put_Heading (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Heading (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Mode (
        /*[in]*/ enum MsoModeType pmd ) = 0;
      virtual HRESULT __stdcall get_Mode (
        /*[out,retval]*/ enum MsoModeType * pmd ) = 0;
      virtual HRESULT __stdcall put_Animation (
        /*[in]*/ enum MsoAnimationType pfca ) = 0;
      virtual HRESULT __stdcall get_Animation (
        /*[out,retval]*/ enum MsoAnimationType * pfca ) = 0;
      virtual HRESULT __stdcall put_Button (
        /*[in]*/ enum MsoButtonSetType psbs ) = 0;
      virtual HRESULT __stdcall get_Button (
        /*[out,retval]*/ enum MsoButtonSetType * psbs ) = 0;
      virtual HRESULT __stdcall put_Callback (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Callback (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_Private (
        /*[in]*/ long plPrivate ) = 0;
      virtual HRESULT __stdcall get_Private (
        /*[out,retval]*/ long * plPrivate ) = 0;
      virtual HRESULT __stdcall SetAvoidRectangle (
        /*[in]*/ int Left,
        /*[in]*/ int Top,
        /*[in]*/ int Right,
        /*[in]*/ int Bottom ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall Show (
        /*[out,retval]*/ enum MsoBalloonButtonType * pibtn ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
};

struct __declspec(uuid("000c0326-0000-0000-c000-000000000046"))
BalloonCheckboxes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pccbx ) = 0;
      virtual HRESULT __stdcall put_Count (
        /*[in]*/ int pccbx ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
};

struct __declspec(uuid("000c0328-0000-0000-c000-000000000046"))
BalloonCheckbox : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall put_Checked (
        /*[in]*/ VARIANT_BOOL pvarfChecked ) = 0;
      virtual HRESULT __stdcall get_Checked (
        /*[out,retval]*/ VARIANT_BOOL * pvarfChecked ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
};

struct __declspec(uuid("000c032e-0000-0000-c000-000000000046"))
BalloonLabels : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcwz ) = 0;
      virtual HRESULT __stdcall put_Count (
        /*[in]*/ int pcwz ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
};

struct __declspec(uuid("000c0330-0000-0000-c000-000000000046"))
BalloonLabel : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
};

struct __declspec(uuid("000c0361-0000-0000-c000-000000000046"))
AnswerWizardFiles : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pCount ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ BSTR FileName ) = 0;
};

struct __declspec(uuid("000c0360-0000-0000-c000-000000000046"))
AnswerWizard : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Files (
        /*[out,retval]*/ struct AnswerWizardFiles * * Files ) = 0;
      virtual HRESULT __stdcall ClearFileList ( ) = 0;
      virtual HRESULT __stdcall ResetFileList ( ) = 0;
};

struct __declspec(uuid("2df8d04e-5bfa-101b-bde5-00aa0044de52"))
DocumentProperty : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual IDispatch * __stdcall get_Parent ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ BSTR * pbstrRetVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in,lcid]*/ long lcid,
        /*[in]*/ BSTR pbstrRetVal ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ VARIANT * pvargRetVal ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in,lcid]*/ long lcid,
        /*[in]*/ VARIANT pvargRetVal ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ enum MsoDocProperties * ptypeRetVal ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in,lcid]*/ long lcid,
        /*[in]*/ enum MsoDocProperties ptypeRetVal ) = 0;
      virtual HRESULT __stdcall get_LinkToContent (
        /*[out,retval]*/ VARIANT_BOOL * pfLinkRetVal ) = 0;
      virtual HRESULT __stdcall put_LinkToContent (
        /*[in]*/ VARIANT_BOOL pfLinkRetVal ) = 0;
      virtual HRESULT __stdcall get_LinkSource (
        /*[out,retval]*/ BSTR * pbstrSourceRetVal ) = 0;
      virtual HRESULT __stdcall put_LinkSource (
        /*[in]*/ BSTR pbstrSourceRetVal ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * plCreator ) = 0;
};

struct __declspec(uuid("2df8d04d-5bfa-101b-bde5-00aa0044de52"))
DocumentProperties : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual IDispatch * __stdcall get_Parent ( ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct DocumentProperty * * ppIDocProp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pc ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT_BOOL LinkToContent,
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT LinkSource,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct DocumentProperty * * ppIDocProp ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * plCreator ) = 0;
};

enum MsoFileFindOptions
{
    msoOptionsNew = 1,
    msoOptionsAdd = 2,
    msoOptionsWithin = 3
};

enum MsoFileFindView
{
    msoViewFileInfo = 1,
    msoViewPreview = 2,
    msoViewSummaryInfo = 3
};

enum MsoFileFindSortBy
{
    msoFileFindSortbyAuthor = 1,
    msoFileFindSortbyDateCreated = 2,
    msoFileFindSortbyLastSavedBy = 3,
    msoFileFindSortbyDateSaved = 4,
    msoFileFindSortbyFileName = 5,
    msoFileFindSortbySize = 6,
    msoFileFindSortbyTitle = 7
};

enum MsoFileFindListBy
{
    msoListbyName = 1,
    msoListbyTitle = 2
};

struct __declspec(uuid("000c0338-0000-0000-c000-000000000046"))
IFoundFiles : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pCount ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000c0337-0000-0000-c000-000000000046"))
IFind : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_SearchPath (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_SubDir (
        /*[out,retval]*/ VARIANT_BOOL * retval ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Author (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Keywords (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Subject (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Options (
        /*[out,retval]*/ enum MsoFileFindOptions * penmOptions ) = 0;
      virtual HRESULT __stdcall get_MatchCase (
        /*[out,retval]*/ VARIANT_BOOL * retval ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_PatternMatch (
        /*[out,retval]*/ VARIANT_BOOL * retval ) = 0;
      virtual HRESULT __stdcall get_DateSavedFrom (
        /*[out,retval]*/ VARIANT * pdatSavedFrom ) = 0;
      virtual HRESULT __stdcall get_DateSavedTo (
        /*[out,retval]*/ VARIANT * pdatSavedTo ) = 0;
      virtual HRESULT __stdcall get_SavedBy (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_DateCreatedFrom (
        /*[out,retval]*/ VARIANT * pdatCreatedFrom ) = 0;
      virtual HRESULT __stdcall get_DateCreatedTo (
        /*[out,retval]*/ VARIANT * pdatCreatedTo ) = 0;
      virtual HRESULT __stdcall get_View (
        /*[out,retval]*/ enum MsoFileFindView * penmView ) = 0;
      virtual HRESULT __stdcall get_SortBy (
        /*[out,retval]*/ enum MsoFileFindSortBy * penmSortBy ) = 0;
      virtual HRESULT __stdcall get_ListBy (
        /*[out,retval]*/ enum MsoFileFindListBy * penmListBy ) = 0;
      virtual HRESULT __stdcall get_SelectedFile (
        /*[out,retval]*/ int * pintSelectedFile ) = 0;
      virtual HRESULT __stdcall get_Results (
        /*[out,retval]*/ struct IFoundFiles * * pdisp ) = 0;
      virtual HRESULT __stdcall Show (
        /*[out,retval]*/ int * pRows ) = 0;
      virtual HRESULT __stdcall put_SearchPath (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_SubDir (
        /*[in]*/ VARIANT_BOOL retval ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_Author (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_Keywords (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_Subject (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_Options (
        /*[in]*/ enum MsoFileFindOptions penmOptions ) = 0;
      virtual HRESULT __stdcall put_MatchCase (
        /*[in]*/ VARIANT_BOOL retval ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_PatternMatch (
        /*[in]*/ VARIANT_BOOL retval ) = 0;
      virtual HRESULT __stdcall put_DateSavedFrom (
        /*[in]*/ VARIANT pdatSavedFrom ) = 0;
      virtual HRESULT __stdcall put_DateSavedTo (
        /*[in]*/ VARIANT pdatSavedTo ) = 0;
      virtual HRESULT __stdcall put_SavedBy (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall put_DateCreatedFrom (
        /*[in]*/ VARIANT pdatCreatedFrom ) = 0;
      virtual HRESULT __stdcall put_DateCreatedTo (
        /*[in]*/ VARIANT pdatCreatedTo ) = 0;
      virtual HRESULT __stdcall put_View (
        /*[in]*/ enum MsoFileFindView penmView ) = 0;
      virtual HRESULT __stdcall put_SortBy (
        /*[in]*/ enum MsoFileFindSortBy penmSortBy ) = 0;
      virtual HRESULT __stdcall put_ListBy (
        /*[in]*/ enum MsoFileFindListBy penmListBy ) = 0;
      virtual HRESULT __stdcall put_SelectedFile (
        /*[in]*/ int pintSelectedFile ) = 0;
      virtual HRESULT __stdcall Execute ( ) = 0;
      virtual HRESULT __stdcall Load (
        /*[in]*/ BSTR bstrQueryName ) = 0;
      virtual HRESULT __stdcall Save (
        /*[in]*/ BSTR bstrQueryName ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ BSTR bstrQueryName ) = 0;
      virtual HRESULT __stdcall get_FileType (
        /*[out,retval]*/ long * plFileType ) = 0;
      virtual HRESULT __stdcall put_FileType (
        /*[in]*/ long plFileType ) = 0;
};

enum MsoLastModified
{
    msoLastModifiedYesterday = 1,
    msoLastModifiedToday = 2,
    msoLastModifiedLastWeek = 3,
    msoLastModifiedThisWeek = 4,
    msoLastModifiedLastMonth = 5,
    msoLastModifiedThisMonth = 6,
    msoLastModifiedAnyTime = 7
};

enum MsoSortBy
{
    msoSortByFileName = 1,
    msoSortBySize = 2,
    msoSortByFileType = 3,
    msoSortByLastModified = 4,
    msoSortByNone = 5
};

enum MsoSortOrder
{
    msoSortOrderAscending = 1,
    msoSortOrderDescending = 2
};

enum MsoConnector
{
    msoConnectorAnd = 1,
    msoConnectorOr = 2
};

enum MsoCondition
{
    msoConditionFileTypeAllFiles = 1,
    msoConditionFileTypeOfficeFiles = 2,
    msoConditionFileTypeWordDocuments = 3,
    msoConditionFileTypeExcelWorkbooks = 4,
    msoConditionFileTypePowerPointPresentations = 5,
    msoConditionFileTypeBinders = 6,
    msoConditionFileTypeDatabases = 7,
    msoConditionFileTypeTemplates = 8,
    msoConditionIncludes = 9,
    msoConditionIncludesPhrase = 10,
    msoConditionBeginsWith = 11,
    msoConditionEndsWith = 12,
    msoConditionIncludesNearEachOther = 13,
    msoConditionIsExactly = 14,
    msoConditionIsNot = 15,
    msoConditionYesterday = 16,
    msoConditionToday = 17,
    msoConditionTomorrow = 18,
    msoConditionLastWeek = 19,
    msoConditionThisWeek = 20,
    msoConditionNextWeek = 21,
    msoConditionLastMonth = 22,
    msoConditionThisMonth = 23,
    msoConditionNextMonth = 24,
    msoConditionAnytime = 25,
    msoConditionAnytimeBetween = 26,
    msoConditionOn = 27,
    msoConditionOnOrAfter = 28,
    msoConditionOnOrBefore = 29,
    msoConditionInTheNext = 30,
    msoConditionInTheLast = 31,
    msoConditionEquals = 32,
    msoConditionDoesNotEqual = 33,
    msoConditionAnyNumberBetween = 34,
    msoConditionAtMost = 35,
    msoConditionAtLeast = 36,
    msoConditionMoreThan = 37,
    msoConditionLessThan = 38,
    msoConditionIsYes = 39,
    msoConditionIsNo = 40,
    msoConditionIncludesFormsOf = 41,
    msoConditionFreeText = 42,
    msoConditionFileTypeOutlookItems = 43,
    msoConditionFileTypeMailItem = 44,
    msoConditionFileTypeCalendarItem = 45,
    msoConditionFileTypeContactItem = 46,
    msoConditionFileTypeNoteItem = 47,
    msoConditionFileTypeJournalItem = 48,
    msoConditionFileTypeTaskItem = 49,
    msoConditionFileTypePhotoDrawFiles = 50,
    msoConditionFileTypeDataConnectionFiles = 51,
    msoConditionFileTypePublisherFiles = 52,
    msoConditionFileTypeProjectFiles = 53,
    msoConditionFileTypeDocumentImagingFiles = 54,
    msoConditionFileTypeVisioFiles = 55,
    msoConditionFileTypeDesignerFiles = 56,
    msoConditionFileTypeWebPages = 57,
    msoConditionEqualsLow = 58,
    msoConditionEqualsNormal = 59,
    msoConditionEqualsHigh = 60,
    msoConditionNotEqualToLow = 61,
    msoConditionNotEqualToNormal = 62,
    msoConditionNotEqualToHigh = 63,
    msoConditionEqualsNotStarted = 64,
    msoConditionEqualsInProgress = 65,
    msoConditionEqualsCompleted = 66,
    msoConditionEqualsWaitingForSomeoneElse = 67,
    msoConditionEqualsDeferred = 68,
    msoConditionNotEqualToNotStarted = 69,
    msoConditionNotEqualToInProgress = 70,
    msoConditionNotEqualToCompleted = 71,
    msoConditionNotEqualToWaitingForSomeoneElse = 72,
    msoConditionNotEqualToDeferred = 73
};

enum MsoFileType
{
    msoFileTypeAllFiles = 1,
    msoFileTypeOfficeFiles = 2,
    msoFileTypeWordDocuments = 3,
    msoFileTypeExcelWorkbooks = 4,
    msoFileTypePowerPointPresentations = 5,
    msoFileTypeBinders = 6,
    msoFileTypeDatabases = 7,
    msoFileTypeTemplates = 8,
    msoFileTypeOutlookItems = 9,
    msoFileTypeMailItem = 10,
    msoFileTypeCalendarItem = 11,
    msoFileTypeContactItem = 12,
    msoFileTypeNoteItem = 13,
    msoFileTypeJournalItem = 14,
    msoFileTypeTaskItem = 15,
    msoFileTypePhotoDrawFiles = 16,
    msoFileTypeDataConnectionFiles = 17,
    msoFileTypePublisherFiles = 18,
    msoFileTypeProjectFiles = 19,
    msoFileTypeDocumentImagingFiles = 20,
    msoFileTypeVisioFiles = 21,
    msoFileTypeDesignerFiles = 22,
    msoFileTypeWebPages = 23
};

struct __declspec(uuid("000c0331-0000-0000-c000-000000000046"))
FoundFiles : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ BSTR * pbstrFile ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pc ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000c0333-0000-0000-c000-000000000046"))
PropertyTest : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrRetVal ) = 0;
      virtual HRESULT __stdcall get_Condition (
        /*[out,retval]*/ enum MsoCondition * pConditionRetVal ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvargRetVal ) = 0;
      virtual HRESULT __stdcall get_SecondValue (
        /*[out,retval]*/ VARIANT * pvargRetVal2 ) = 0;
      virtual HRESULT __stdcall get_Connector (
        /*[out,retval]*/ enum MsoConnector * pConnector ) = 0;
};

struct __declspec(uuid("000c0334-0000-0000-c000-000000000046"))
PropertyTests : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct PropertyTest * * ppIDocProp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pc ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Name,
        /*[in]*/ enum MsoCondition Condition,
        /*[in]*/ VARIANT Value,
        /*[in]*/ VARIANT SecondValue,
        /*[in]*/ enum MsoConnector Connector ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ int Index ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000c033a-0000-0000-c000-000000000046"))
COMAddIn : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_ProgId (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall get_Connect (
        /*[out,retval]*/ VARIANT_BOOL * RetValue ) = 0;
      virtual HRESULT __stdcall put_Connect (
        /*[in]*/ VARIANT_BOOL RetValue ) = 0;
      virtual HRESULT __stdcall get_Object (
        /*[out,retval]*/ IDispatch * * RetValue ) = 0;
      virtual HRESULT __stdcall put_Object (
        /*[in]*/ IDispatch * RetValue ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * retval ) = 0;
};

struct __declspec(uuid("000c0339-0000-0000-c000-000000000046"))
COMAddIns : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT * Index,
        /*[out,retval]*/ struct COMAddIn * * RetValue ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * RetValue ) = 0;
      virtual HRESULT __stdcall Update ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall SetAppModal (
        /*[in]*/ VARIANT_BOOL varfModal ) = 0;
};

enum MsoLanguageID
{
    msoLanguageIDMixed = -2,
    msoLanguageIDNone = 0,
    msoLanguageIDNoProofing = 1024,
    msoLanguageIDAfrikaans = 1078,
    msoLanguageIDAlbanian = 1052,
    msoLanguageIDAmharic = 1118,
    msoLanguageIDArabicAlgeria = 5121,
    msoLanguageIDArabicBahrain = 15361,
    msoLanguageIDArabicEgypt = 3073,
    msoLanguageIDArabicIraq = 2049,
    msoLanguageIDArabicJordan = 11265,
    msoLanguageIDArabicKuwait = 13313,
    msoLanguageIDArabicLebanon = 12289,
    msoLanguageIDArabicLibya = 4097,
    msoLanguageIDArabicMorocco = 6145,
    msoLanguageIDArabicOman = 8193,
    msoLanguageIDArabicQatar = 16385,
    msoLanguageIDArabic = 1025,
    msoLanguageIDArabicSyria = 10241,
    msoLanguageIDArabicTunisia = 7169,
    msoLanguageIDArabicUAE = 14337,
    msoLanguageIDArabicYemen = 9217,
    msoLanguageIDArmenian = 1067,
    msoLanguageIDAssamese = 1101,
    msoLanguageIDAzeriCyrillic = 2092,
    msoLanguageIDAzeriLatin = 1068,
    msoLanguageIDBasque = 1069,
    msoLanguageIDByelorussian = 1059,
    msoLanguageIDBengali = 1093,
    msoLanguageIDBosnian = 4122,
    msoLanguageIDBosnianBosniaHerzegovinaCyrillic = 8218,
    msoLanguageIDBosnianBosniaHerzegovinaLatin = 5146,
    msoLanguageIDBulgarian = 1026,
    msoLanguageIDBurmese = 1109,
    msoLanguageIDCatalan = 1027,
    msoLanguageIDChineseHongKongSAR = 3076,
    msoLanguageIDChineseMacaoSAR = 5124,
    msoLanguageIDSimplifiedChinese = 2052,
    msoLanguageIDChineseSingapore = 4100,
    msoLanguageIDTraditionalChinese = 1028,
    msoLanguageIDCherokee = 1116,
    msoLanguageIDCroatian = 1050,
    msoLanguageIDCzech = 1029,
    msoLanguageIDDanish = 1030,
    msoLanguageIDDivehi = 1125,
    msoLanguageIDBelgianDutch = 2067,
    msoLanguageIDDutch = 1043,
    msoLanguageIDDzongkhaBhutan = 2129,
    msoLanguageIDEdo = 1126,
    msoLanguageIDEnglishAUS = 3081,
    msoLanguageIDEnglishBelize = 10249,
    msoLanguageIDEnglishCanadian = 4105,
    msoLanguageIDEnglishCaribbean = 9225,
    msoLanguageIDEnglishIndonesia = 14345,
    msoLanguageIDEnglishIreland = 6153,
    msoLanguageIDEnglishJamaica = 8201,
    msoLanguageIDEnglishNewZealand = 5129,
    msoLanguageIDEnglishPhilippines = 13321,
    msoLanguageIDEnglishSouthAfrica = 7177,
    msoLanguageIDEnglishTrinidadTobago = 11273,
    msoLanguageIDEnglishUK = 2057,
    msoLanguageIDEnglishUS = 1033,
    msoLanguageIDEnglishZimbabwe = 12297,
    msoLanguageIDEstonian = 1061,
    msoLanguageIDFaeroese = 1080,
    msoLanguageIDFarsi = 1065,
    msoLanguageIDFilipino = 1124,
    msoLanguageIDFinnish = 1035,
    msoLanguageIDBelgianFrench = 2060,
    msoLanguageIDFrenchCameroon = 11276,
    msoLanguageIDFrenchCanadian = 3084,
    msoLanguageIDFrenchCotedIvoire = 12300,
    msoLanguageIDFrench = 1036,
    msoLanguageIDFrenchHaiti = 15372,
    msoLanguageIDFrenchLuxembourg = 5132,
    msoLanguageIDFrenchMali = 13324,
    msoLanguageIDFrenchMonaco = 6156,
    msoLanguageIDFrenchMorocco = 14348,
    msoLanguageIDFrenchReunion = 8204,
    msoLanguageIDFrenchSenegal = 10252,
    msoLanguageIDSwissFrench = 4108,
    msoLanguageIDFrenchWestIndies = 7180,
    msoLanguageIDFrenchZaire = 9228,
    msoLanguageIDFrenchCongoDRC = 9228,
    msoLanguageIDFrisianNetherlands = 1122,
    msoLanguageIDFulfulde = 1127,
    msoLanguageIDGaelicIreland = 2108,
    msoLanguageIDGaelicScotland = 1084,
    msoLanguageIDGalician = 1110,
    msoLanguageIDGeorgian = 1079,
    msoLanguageIDGermanAustria = 3079,
    msoLanguageIDGerman = 1031,
    msoLanguageIDGermanLiechtenstein = 5127,
    msoLanguageIDGermanLuxembourg = 4103,
    msoLanguageIDSwissGerman = 2055,
    msoLanguageIDGreek = 1032,
    msoLanguageIDGuarani = 1140,
    msoLanguageIDGujarati = 1095,
    msoLanguageIDHausa = 1128,
    msoLanguageIDHawaiian = 1141,
    msoLanguageIDHebrew = 1037,
    msoLanguageIDHindi = 1081,
    msoLanguageIDHungarian = 1038,
    msoLanguageIDIbibio = 1129,
    msoLanguageIDIcelandic = 1039,
    msoLanguageIDIgbo = 1136,
    msoLanguageIDIndonesian = 1057,
    msoLanguageIDInuktitut = 1117,
    msoLanguageIDItalian = 1040,
    msoLanguageIDSwissItalian = 2064,
    msoLanguageIDJapanese = 1041,
    msoLanguageIDKannada = 1099,
    msoLanguageIDKanuri = 1137,
    msoLanguageIDKashmiri = 1120,
    msoLanguageIDKashmiriDevanagari = 2144,
    msoLanguageIDKazakh = 1087,
    msoLanguageIDKhmer = 1107,
    msoLanguageIDKirghiz = 1088,
    msoLanguageIDKonkani = 1111,
    msoLanguageIDKorean = 1042,
    msoLanguageIDKyrgyz = 1088,
    msoLanguageIDLatin = 1142,
    msoLanguageIDLao = 1108,
    msoLanguageIDLatvian = 1062,
    msoLanguageIDLithuanian = 1063,
    msoLanguageIDMacedonian = 1071,
    msoLanguageIDMacedonianFYROM = 1071,
    msoLanguageIDMalaysian = 1086,
    msoLanguageIDMalayBruneiDarussalam = 2110,
    msoLanguageIDMalayalam = 1100,
    msoLanguageIDMaltese = 1082,
    msoLanguageIDManipuri = 1112,
    msoLanguageIDMaori = 1153,
    msoLanguageIDMarathi = 1102,
    msoLanguageIDMongolian = 1104,
    msoLanguageIDNepali = 1121,
    msoLanguageIDNorwegianBokmol = 1044,
    msoLanguageIDNorwegianNynorsk = 2068,
    msoLanguageIDOriya = 1096,
    msoLanguageIDOromo = 1138,
    msoLanguageIDPashto = 1123,
    msoLanguageIDPolish = 1045,
    msoLanguageIDBrazilianPortuguese = 1046,
    msoLanguageIDPortuguese = 2070,
    msoLanguageIDPunjabi = 1094,
    msoLanguageIDQuechuaBolivia = 1131,
    msoLanguageIDQuechuaEcuador = 2155,
    msoLanguageIDQuechuaPeru = 3179,
    msoLanguageIDRhaetoRomanic = 1047,
    msoLanguageIDRomanianMoldova = 2072,
    msoLanguageIDRomanian = 1048,
    msoLanguageIDRussianMoldova = 2073,
    msoLanguageIDRussian = 1049,
    msoLanguageIDSamiLappish = 1083,
    msoLanguageIDSanskrit = 1103,
    msoLanguageIDSepedi = 1132,
    msoLanguageIDSerbianBosniaHerzegovinaCyrillic = 7194,
    msoLanguageIDSerbianBosniaHerzegovinaLatin = 6170,
    msoLanguageIDSerbianCyrillic = 3098,
    msoLanguageIDSerbianLatin = 2074,
    msoLanguageIDSesotho = 1072,
    msoLanguageIDSindhi = 1113,
    msoLanguageIDSindhiPakistan = 2137,
    msoLanguageIDSinhalese = 1115,
    msoLanguageIDSlovak = 1051,
    msoLanguageIDSlovenian = 1060,
    msoLanguageIDSomali = 1143,
    msoLanguageIDSorbian = 1070,
    msoLanguageIDSpanishArgentina = 11274,
    msoLanguageIDSpanishBolivia = 16394,
    msoLanguageIDSpanishChile = 13322,
    msoLanguageIDSpanishColombia = 9226,
    msoLanguageIDSpanishCostaRica = 5130,
    msoLanguageIDSpanishDominicanRepublic = 7178,
    msoLanguageIDSpanishEcuador = 12298,
    msoLanguageIDSpanishElSalvador = 17418,
    msoLanguageIDSpanishGuatemala = 4106,
    msoLanguageIDSpanishHonduras = 18442,
    msoLanguageIDMexicanSpanish = 2058,
    msoLanguageIDSpanishNicaragua = 19466,
    msoLanguageIDSpanishPanama = 6154,
    msoLanguageIDSpanishParaguay = 15370,
    msoLanguageIDSpanishPeru = 10250,
    msoLanguageIDSpanishPuertoRico = 20490,
    msoLanguageIDSpanishModernSort = 3082,
    msoLanguageIDSpanish = 1034,
    msoLanguageIDSpanishUruguay = 14346,
    msoLanguageIDSpanishVenezuela = 8202,
    msoLanguageIDSutu = 1072,
    msoLanguageIDSwahili = 1089,
    msoLanguageIDSwedishFinland = 2077,
    msoLanguageIDSwedish = 1053,
    msoLanguageIDSyriac = 1114,
    msoLanguageIDTajik = 1064,
    msoLanguageIDTamil = 1097,
    msoLanguageIDTamazight = 1119,
    msoLanguageIDTamazightLatin = 2143,
    msoLanguageIDTatar = 1092,
    msoLanguageIDTelugu = 1098,
    msoLanguageIDThai = 1054,
    msoLanguageIDTibetan = 1105,
    msoLanguageIDTigrignaEthiopic = 1139,
    msoLanguageIDTigrignaEritrea = 2163,
    msoLanguageIDTsonga = 1073,
    msoLanguageIDTswana = 1074,
    msoLanguageIDTurkish = 1055,
    msoLanguageIDTurkmen = 1090,
    msoLanguageIDUkrainian = 1058,
    msoLanguageIDUrdu = 1056,
    msoLanguageIDUzbekCyrillic = 2115,
    msoLanguageIDUzbekLatin = 1091,
    msoLanguageIDVenda = 1075,
    msoLanguageIDVietnamese = 1066,
    msoLanguageIDWelsh = 1106,
    msoLanguageIDXhosa = 1076,
    msoLanguageIDYi = 1144,
    msoLanguageIDYiddish = 1085,
    msoLanguageIDYoruba = 1130,
    msoLanguageIDZulu = 1077
};

struct __declspec(uuid("000c0353-0000-0000-c000-000000000046"))
LanguageSettings : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_LanguageID (
        /*[in]*/ enum MsoAppLanguageID Id,
        /*[out,retval]*/ int * plid ) = 0;
      virtual HRESULT __stdcall get_LanguagePreferredForEditing (
        /*[in]*/ enum MsoLanguageID lid,
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("55f88892-7708-11d1-aceb-006008961da5"))
ICommandBarsEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual void __stdcall OnUpdate ( ) = 0;
};

struct __declspec(uuid("000c0352-0000-0000-c000-000000000046"))
_CommandBarsEvents : IDispatch
{};

struct __declspec(uuid("55f88893-7708-11d1-aceb-006008961da5"))
CommandBars;
    // [ default ] interface _CommandBars
    // [ default, source ] dispinterface _CommandBarsEvents

struct __declspec(uuid("000c0354-0000-0000-c000-000000000046"))
_CommandBarComboBoxEvents : IDispatch
{};

struct __declspec(uuid("55f88897-7708-11d1-aceb-006008961da5"))
CommandBarComboBox;
    // [ default ] interface _CommandBarComboBox
    // [ default, source ] dispinterface _CommandBarComboBoxEvents

struct __declspec(uuid("55f88896-7708-11d1-aceb-006008961da5"))
ICommandBarComboBoxEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual void __stdcall Change (
        /*[in]*/ struct _CommandBarComboBox * Ctrl ) = 0;
};

struct __declspec(uuid("000c0351-0000-0000-c000-000000000046"))
_CommandBarButtonEvents : IDispatch
{};

struct __declspec(uuid("55f88891-7708-11d1-aceb-006008961da5"))
CommandBarButton;
    // [ default ] interface _CommandBarButton
    // [ default, source ] dispinterface _CommandBarButtonEvents

struct __declspec(uuid("55f88890-7708-11d1-aceb-006008961da5"))
ICommandBarButtonEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual void __stdcall Click (
        /*[in]*/ struct _CommandBarButton * Ctrl,
        /*[in,out]*/ VARIANT_BOOL * CancelDefault ) = 0;
};

enum MsoScreenSize
{
    msoScreenSize544x376 = 0,
    msoScreenSize640x480 = 1,
    msoScreenSize720x512 = 2,
    msoScreenSize800x600 = 3,
    msoScreenSize1024x768 = 4,
    msoScreenSize1152x882 = 5,
    msoScreenSize1152x900 = 6,
    msoScreenSize1280x1024 = 7,
    msoScreenSize1600x1200 = 8,
    msoScreenSize1800x1440 = 9,
    msoScreenSize1920x1200 = 10
};

enum MsoCharacterSet
{
    msoCharacterSetArabic = 1,
    msoCharacterSetCyrillic = 2,
    msoCharacterSetEnglishWesternEuropeanOtherLatinScript = 3,
    msoCharacterSetGreek = 4,
    msoCharacterSetHebrew = 5,
    msoCharacterSetJapanese = 6,
    msoCharacterSetKorean = 7,
    msoCharacterSetMultilingualUnicode = 8,
    msoCharacterSetSimplifiedChinese = 9,
    msoCharacterSetThai = 10,
    msoCharacterSetTraditionalChinese = 11,
    msoCharacterSetVietnamese = 12
};

enum MsoEncoding
{
    msoEncodingThai = 874,
    msoEncodingJapaneseShiftJIS = 932,
    msoEncodingSimplifiedChineseGBK = 936,
    msoEncodingKorean = 949,
    msoEncodingTraditionalChineseBig5 = 950,
    msoEncodingUnicodeLittleEndian = 1200,
    msoEncodingUnicodeBigEndian = 1201,
    msoEncodingCentralEuropean = 1250,
    msoEncodingCyrillic = 1251,
    msoEncodingWestern = 1252,
    msoEncodingGreek = 1253,
    msoEncodingTurkish = 1254,
    msoEncodingHebrew = 1255,
    msoEncodingArabic = 1256,
    msoEncodingBaltic = 1257,
    msoEncodingVietnamese = 1258,
    msoEncodingAutoDetect = 50001,
    msoEncodingJapaneseAutoDetect = 50932,
    msoEncodingSimplifiedChineseAutoDetect = 50936,
    msoEncodingKoreanAutoDetect = 50949,
    msoEncodingTraditionalChineseAutoDetect = 50950,
    msoEncodingCyrillicAutoDetect = 51251,
    msoEncodingGreekAutoDetect = 51253,
    msoEncodingArabicAutoDetect = 51256,
    msoEncodingISO88591Latin1 = 28591,
    msoEncodingISO88592CentralEurope = 28592,
    msoEncodingISO88593Latin3 = 28593,
    msoEncodingISO88594Baltic = 28594,
    msoEncodingISO88595Cyrillic = 28595,
    msoEncodingISO88596Arabic = 28596,
    msoEncodingISO88597Greek = 28597,
    msoEncodingISO88598Hebrew = 28598,
    msoEncodingISO88599Turkish = 28599,
    msoEncodingISO885915Latin9 = 28605,
    msoEncodingISO88598HebrewLogical = 38598,
    msoEncodingISO2022JPNoHalfwidthKatakana = 50220,
    msoEncodingISO2022JPJISX02021984 = 50221,
    msoEncodingISO2022JPJISX02011989 = 50222,
    msoEncodingISO2022KR = 50225,
    msoEncodingISO2022CNTraditionalChinese = 50227,
    msoEncodingISO2022CNSimplifiedChinese = 50229,
    msoEncodingMacRoman = 10000,
    msoEncodingMacJapanese = 10001,
    msoEncodingMacTraditionalChineseBig5 = 10002,
    msoEncodingMacKorean = 10003,
    msoEncodingMacArabic = 10004,
    msoEncodingMacHebrew = 10005,
    msoEncodingMacGreek1 = 10006,
    msoEncodingMacCyrillic = 10007,
    msoEncodingMacSimplifiedChineseGB2312 = 10008,
    msoEncodingMacRomania = 10010,
    msoEncodingMacUkraine = 10017,
    msoEncodingMacLatin2 = 10029,
    msoEncodingMacIcelandic = 10079,
    msoEncodingMacTurkish = 10081,
    msoEncodingMacCroatia = 10082,
    msoEncodingEBCDICUSCanada = 37,
    msoEncodingEBCDICInternational = 500,
    msoEncodingEBCDICMultilingualROECELatin2 = 870,
    msoEncodingEBCDICGreekModern = 875,
    msoEncodingEBCDICTurkishLatin5 = 1026,
    msoEncodingEBCDICGermany = 20273,
    msoEncodingEBCDICDenmarkNorway = 20277,
    msoEncodingEBCDICFinlandSweden = 20278,
    msoEncodingEBCDICItaly = 20280,
    msoEncodingEBCDICLatinAmericaSpain = 20284,
    msoEncodingEBCDICUnitedKingdom = 20285,
    msoEncodingEBCDICJapaneseKatakanaExtended = 20290,
    msoEncodingEBCDICFrance = 20297,
    msoEncodingEBCDICArabic = 20420,
    msoEncodingEBCDICGreek = 20423,
    msoEncodingEBCDICHebrew = 20424,
    msoEncodingEBCDICKoreanExtended = 20833,
    msoEncodingEBCDICThai = 20838,
    msoEncodingEBCDICIcelandic = 20871,
    msoEncodingEBCDICTurkish = 20905,
    msoEncodingEBCDICRussian = 20880,
    msoEncodingEBCDICSerbianBulgarian = 21025,
    msoEncodingEBCDICJapaneseKatakanaExtendedAndJapanese = 50930,
    msoEncodingEBCDICUSCanadaAndJapanese = 50931,
    msoEncodingEBCDICKoreanExtendedAndKorean = 50933,
    msoEncodingEBCDICSimplifiedChineseExtendedAndSimplifiedChinese = 50935,
    msoEncodingEBCDICUSCanadaAndTraditionalChinese = 50937,
    msoEncodingEBCDICJapaneseLatinExtendedAndJapanese = 50939,
    msoEncodingOEMUnitedStates = 437,
    msoEncodingOEMGreek437G = 737,
    msoEncodingOEMBaltic = 775,
    msoEncodingOEMMultilingualLatinI = 850,
    msoEncodingOEMMultilingualLatinII = 852,
    msoEncodingOEMCyrillic = 855,
    msoEncodingOEMTurkish = 857,
    msoEncodingOEMPortuguese = 860,
    msoEncodingOEMIcelandic = 861,
    msoEncodingOEMHebrew = 862,
    msoEncodingOEMCanadianFrench = 863,
    msoEncodingOEMArabic = 864,
    msoEncodingOEMNordic = 865,
    msoEncodingOEMCyrillicII = 866,
    msoEncodingOEMModernGreek = 869,
    msoEncodingEUCJapanese = 51932,
    msoEncodingEUCChineseSimplifiedChinese = 51936,
    msoEncodingEUCKorean = 51949,
    msoEncodingEUCTaiwaneseTraditionalChinese = 51950,
    msoEncodingISCIIDevanagari = 57002,
    msoEncodingISCIIBengali = 57003,
    msoEncodingISCIITamil = 57004,
    msoEncodingISCIITelugu = 57005,
    msoEncodingISCIIAssamese = 57006,
    msoEncodingISCIIOriya = 57007,
    msoEncodingISCIIKannada = 57008,
    msoEncodingISCIIMalayalam = 57009,
    msoEncodingISCIIGujarati = 57010,
    msoEncodingISCIIPunjabi = 57011,
    msoEncodingArabicASMO = 708,
    msoEncodingArabicTransparentASMO = 720,
    msoEncodingKoreanJohab = 1361,
    msoEncodingTaiwanCNS = 20000,
    msoEncodingTaiwanTCA = 20001,
    msoEncodingTaiwanEten = 20002,
    msoEncodingTaiwanIBM5550 = 20003,
    msoEncodingTaiwanTeleText = 20004,
    msoEncodingTaiwanWang = 20005,
    msoEncodingIA5IRV = 20105,
    msoEncodingIA5German = 20106,
    msoEncodingIA5Swedish = 20107,
    msoEncodingIA5Norwegian = 20108,
    msoEncodingUSASCII = 20127,
    msoEncodingT61 = 20261,
    msoEncodingISO6937NonSpacingAccent = 20269,
    msoEncodingKOI8R = 20866,
    msoEncodingExtAlphaLowercase = 21027,
    msoEncodingKOI8U = 21866,
    msoEncodingEuropa3 = 29001,
    msoEncodingHZGBSimplifiedChinese = 52936,
    msoEncodingSimplifiedChineseGB18030 = 54936,
    msoEncodingUTF7 = 65000,
    msoEncodingUTF8 = 65001
};

struct __declspec(uuid("000c0913-0000-0000-c000-000000000046"))
WebPageFont : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ProportionalFont (
        /*[out,retval]*/ BSTR * pstr ) = 0;
      virtual HRESULT __stdcall put_ProportionalFont (
        /*[in]*/ BSTR pstr ) = 0;
      virtual HRESULT __stdcall get_ProportionalFontSize (
        /*[out,retval]*/ float * pf ) = 0;
      virtual HRESULT __stdcall put_ProportionalFontSize (
        /*[in]*/ float pf ) = 0;
      virtual HRESULT __stdcall get_FixedWidthFont (
        /*[out,retval]*/ BSTR * pstr ) = 0;
      virtual HRESULT __stdcall put_FixedWidthFont (
        /*[in]*/ BSTR pstr ) = 0;
      virtual HRESULT __stdcall get_FixedWidthFontSize (
        /*[out,retval]*/ float * pf ) = 0;
      virtual HRESULT __stdcall put_FixedWidthFontSize (
        /*[in]*/ float pf ) = 0;
};

struct __declspec(uuid("000c0914-0000-0000-c000-000000000046"))
WebPageFonts : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ enum MsoCharacterSet Index,
        /*[out,retval]*/ struct WebPageFont * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
};

enum MsoHTMLProjectOpen
{
    msoHTMLProjectOpenSourceView = 1,
    msoHTMLProjectOpenTextView = 2
};

enum MsoHTMLProjectState
{
    msoHTMLProjectStateDocumentLocked = 1,
    msoHTMLProjectStateProjectLocked = 2,
    msoHTMLProjectStateDocumentProjectUnlocked = 3
};

struct __declspec(uuid("000c0358-0000-0000-c000-000000000046"))
HTMLProjectItem : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall get_IsOpen (
        /*[out,retval]*/ VARIANT_BOOL * RetValue ) = 0;
      virtual HRESULT __stdcall LoadFromFile (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall Open (
        /*[in]*/ enum MsoHTMLProjectOpen OpenKind ) = 0;
      virtual HRESULT __stdcall SaveCopyAs (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * Text ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR Text ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c0357-0000-0000-c000-000000000046"))
HTMLProjectItems : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT * Index,
        /*[out,retval]*/ struct HTMLProjectItem * * RetValue ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * RetValue ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c0356-0000-0000-c000-000000000046"))
HTMLProject : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_State (
        /*[out,retval]*/ enum MsoHTMLProjectState * State ) = 0;
      virtual HRESULT __stdcall RefreshProject (
        /*[in]*/ VARIANT_BOOL Refresh ) = 0;
      virtual HRESULT __stdcall RefreshDocument (
        /*[in]*/ VARIANT_BOOL Refresh ) = 0;
      virtual HRESULT __stdcall get_HTMLProjectItems (
        /*[out,retval]*/ struct HTMLProjectItems * * HTMLProjectItems ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall Open (
        /*[in]*/ enum MsoHTMLProjectOpen OpenKind ) = 0;
};

struct __declspec(uuid("000c035a-0000-0000-c000-000000000046"))
MsoDebugOptions : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_FeatureReports (
        /*[out,retval]*/ int * puintFeatureReports ) = 0;
      virtual HRESULT __stdcall put_FeatureReports (
        /*[in]*/ int puintFeatureReports ) = 0;
      virtual HRESULT __stdcall get_OutputToDebugger (
        /*[out,retval]*/ VARIANT_BOOL * pvarfOutputToDebugger ) = 0;
      virtual HRESULT __stdcall put_OutputToDebugger (
        /*[in]*/ VARIANT_BOOL pvarfOutputToDebugger ) = 0;
      virtual HRESULT __stdcall get_OutputToFile (
        /*[out,retval]*/ VARIANT_BOOL * pvarfOutputToFile ) = 0;
      virtual HRESULT __stdcall put_OutputToFile (
        /*[in]*/ VARIANT_BOOL pvarfOutputToFile ) = 0;
      virtual HRESULT __stdcall get_OutputToMessageBox (
        /*[out,retval]*/ VARIANT_BOOL * pvarfOutputToMessageBox ) = 0;
      virtual HRESULT __stdcall put_OutputToMessageBox (
        /*[in]*/ VARIANT_BOOL pvarfOutputToMessageBox ) = 0;
      virtual HRESULT __stdcall get_UnitTestManager (
        /*[out,retval]*/ IUnknown * * ppMsoUnitTestManager ) = 0;
      virtual HRESULT __stdcall AddIgnoredAssertTag (
        /*[in]*/ BSTR bstrTagToIgnore ) = 0;
      virtual HRESULT __stdcall RemoveIgnoredAssertTag (
        /*[in]*/ BSTR bstrTagToIgnore ) = 0;
};

enum MsoFileDialogType
{
    msoFileDialogOpen = 1,
    msoFileDialogSaveAs = 2,
    msoFileDialogFilePicker = 3,
    msoFileDialogFolderPicker = 4
};

enum MsoFileDialogView
{
    msoFileDialogViewList = 1,
    msoFileDialogViewDetails = 2,
    msoFileDialogViewProperties = 3,
    msoFileDialogViewPreview = 4,
    msoFileDialogViewThumbnail = 5,
    msoFileDialogViewLargeIcons = 6,
    msoFileDialogViewSmallIcons = 7,
    msoFileDialogViewWebView = 8,
    msoFileDialogViewTiles = 9
};

struct __declspec(uuid("000c0363-0000-0000-c000-000000000046"))
FileDialogSelectedItems : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pcFiles ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ BSTR * Item ) = 0;
};

struct __declspec(uuid("000c0364-0000-0000-c000-000000000046"))
FileDialogFilter : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Extensions (
        /*[out,retval]*/ BSTR * Extensions ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
};

struct __declspec(uuid("000c0365-0000-0000-c000-000000000046"))
FileDialogFilters : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pcFilters ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct FileDialogFilter * * Item ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ VARIANT filter = vtMissing ) = 0;
      virtual HRESULT __stdcall Clear ( ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Description,
        /*[in]*/ BSTR Extensions,
        /*[in]*/ VARIANT Position,
        /*[out,retval]*/ struct FileDialogFilter * * Add ) = 0;
};

struct __declspec(uuid("000c0362-0000-0000-c000-000000000046"))
FileDialog : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Filters (
        /*[out,retval]*/ struct FileDialogFilters * * Filters ) = 0;
      virtual HRESULT __stdcall get_FilterIndex (
        /*[out,retval]*/ int * FilterIndex ) = 0;
      virtual HRESULT __stdcall put_FilterIndex (
        /*[in]*/ int FilterIndex ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
      virtual HRESULT __stdcall get_ButtonName (
        /*[out,retval]*/ BSTR * ButtonName ) = 0;
      virtual HRESULT __stdcall put_ButtonName (
        /*[in]*/ BSTR ButtonName ) = 0;
      virtual HRESULT __stdcall get_AllowMultiSelect (
        /*[out,retval]*/ VARIANT_BOOL * pvarfAllowMultiSelect ) = 0;
      virtual HRESULT __stdcall put_AllowMultiSelect (
        /*[in]*/ VARIANT_BOOL pvarfAllowMultiSelect ) = 0;
      virtual HRESULT __stdcall get_InitialView (
        /*[out,retval]*/ enum MsoFileDialogView * pinitialview ) = 0;
      virtual HRESULT __stdcall put_InitialView (
        /*[in]*/ enum MsoFileDialogView pinitialview ) = 0;
      virtual HRESULT __stdcall get_InitialFileName (
        /*[out,retval]*/ BSTR * InitialFileName ) = 0;
      virtual HRESULT __stdcall put_InitialFileName (
        /*[in]*/ BSTR InitialFileName ) = 0;
      virtual HRESULT __stdcall get_SelectedItems (
        /*[out,retval]*/ struct FileDialogSelectedItems * * Files ) = 0;
      virtual HRESULT __stdcall get_DialogType (
        /*[out,retval]*/ enum MsoFileDialogType * pdialogtype ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall Show (
        /*[out,retval]*/ int * rval ) = 0;
      virtual HRESULT __stdcall Execute ( ) = 0;
};

enum MsoAutomationSecurity
{
    msoAutomationSecurityLow = 1,
    msoAutomationSecurityByUI = 2,
    msoAutomationSecurityForceDisable = 3
};

enum MailFormat
{
    mfPlainText = 1,
    mfHTML = 2,
    mfRTF = 3
};

struct __declspec(uuid("000672ac-0000-0000-c000-000000000046"))
IMsoEnvelopeVB : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Introduction (
        /*[out,retval]*/ BSTR * pbstrIntro ) = 0;
      virtual HRESULT __stdcall put_Introduction (
        /*[in]*/ BSTR pbstrIntro ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[out,retval]*/ IDispatch * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_CommandBars (
        /*[out,retval]*/ IDispatch * * ppdisp ) = 0;
};

struct __declspec(uuid("000672ad-0000-0000-c000-000000000046"))
IMsoEnvelopeVBEvents : IDispatch
{};

struct __declspec(uuid("0006f01a-0000-0000-c000-000000000046"))
MsoEnvelope;
    // [ default ] interface IMsoEnvelopeVB
    // [ default, source ] dispinterface IMsoEnvelopeVBEvents

enum MsoAlertButtonType
{
    msoAlertButtonOK = 0,
    msoAlertButtonOKCancel = 1,
    msoAlertButtonAbortRetryIgnore = 2,
    msoAlertButtonYesNoCancel = 3,
    msoAlertButtonYesNo = 4,
    msoAlertButtonRetryCancel = 5,
    msoAlertButtonYesAllNoCancel = 6
};

enum MsoAlertIconType
{
    msoAlertIconNoIcon = 0,
    msoAlertIconCritical = 1,
    msoAlertIconQuery = 2,
    msoAlertIconWarning = 3,
    msoAlertIconInfo = 4
};

enum MsoAlertDefaultType
{
    msoAlertDefaultFirst = 0,
    msoAlertDefaultSecond = 1,
    msoAlertDefaultThird = 2,
    msoAlertDefaultFourth = 3,
    msoAlertDefaultFifth = 4
};

enum MsoAlertCancelType
{
    msoAlertCancelDefault = -1,
    msoAlertCancelFirst = 0,
    msoAlertCancelSecond = 1,
    msoAlertCancelThird = 2,
    msoAlertCancelFourth = 3,
    msoAlertCancelFifth = 4
};

struct __declspec(uuid("000c0322-0000-0000-c000-000000000046"))
Assistant : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall Move (
        /*[in]*/ int xLeft,
        /*[in]*/ int yTop ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ int pyTop ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ int * pyTop ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ int pxLeft ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ int * pxLeft ) = 0;
      virtual HRESULT __stdcall Help ( ) = 0;
      virtual HRESULT __stdcall StartWizard (
        /*[in]*/ VARIANT_BOOL On,
        /*[in]*/ BSTR Callback,
        /*[in]*/ long PrivateX,
        /*[in]*/ VARIANT Animation,
        /*[in]*/ VARIANT CustomTeaser,
        /*[in]*/ VARIANT Top,
        /*[in]*/ VARIANT Left,
        /*[in]*/ VARIANT Bottom,
        /*[in]*/ VARIANT Right,
        /*[out,retval]*/ long * plWizID ) = 0;
      virtual HRESULT __stdcall EndWizard (
        /*[in]*/ long WizardID,
        /*[in]*/ VARIANT_BOOL varfSuccess,
        /*[in]*/ VARIANT Animation = vtMissing ) = 0;
      virtual HRESULT __stdcall ActivateWizard (
        /*[in]*/ long WizardID,
        /*[in]*/ enum MsoWizardActType act,
        /*[in]*/ VARIANT Animation = vtMissing ) = 0;
      virtual HRESULT __stdcall ResetTips ( ) = 0;
      virtual HRESULT __stdcall get_NewBalloon (
        /*[out,retval]*/ struct Balloon * * ppibal ) = 0;
      virtual HRESULT __stdcall get_BalloonError (
        /*[out,retval]*/ enum MsoBalloonErrorType * pbne ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ VARIANT_BOOL * pvarfVisible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ VARIANT_BOOL pvarfVisible ) = 0;
      virtual HRESULT __stdcall get_Animation (
        /*[out,retval]*/ enum MsoAnimationType * pfca ) = 0;
      virtual HRESULT __stdcall put_Animation (
        /*[in]*/ enum MsoAnimationType pfca ) = 0;
      virtual HRESULT __stdcall get_Reduced (
        /*[out,retval]*/ VARIANT_BOOL * pvarfReduced ) = 0;
      virtual HRESULT __stdcall put_Reduced (
        /*[in]*/ VARIANT_BOOL pvarfReduced ) = 0;
      virtual HRESULT __stdcall put_AssistWithHelp (
        /*[in]*/ VARIANT_BOOL pvarfAssistWithHelp ) = 0;
      virtual HRESULT __stdcall get_AssistWithHelp (
        /*[out,retval]*/ VARIANT_BOOL * pvarfAssistWithHelp ) = 0;
      virtual HRESULT __stdcall put_AssistWithWizards (
        /*[in]*/ VARIANT_BOOL pvarfAssistWithWizards ) = 0;
      virtual HRESULT __stdcall get_AssistWithWizards (
        /*[out,retval]*/ VARIANT_BOOL * pvarfAssistWithWizards ) = 0;
      virtual HRESULT __stdcall put_AssistWithAlerts (
        /*[in]*/ VARIANT_BOOL pvarfAssistWithAlerts ) = 0;
      virtual HRESULT __stdcall get_AssistWithAlerts (
        /*[out,retval]*/ VARIANT_BOOL * pvarfAssistWithAlerts ) = 0;
      virtual HRESULT __stdcall put_MoveWhenInTheWay (
        /*[in]*/ VARIANT_BOOL pvarfMove ) = 0;
      virtual HRESULT __stdcall get_MoveWhenInTheWay (
        /*[out,retval]*/ VARIANT_BOOL * pvarfMove ) = 0;
      virtual HRESULT __stdcall put_Sounds (
        /*[in]*/ VARIANT_BOOL pvarfSounds ) = 0;
      virtual HRESULT __stdcall get_Sounds (
        /*[out,retval]*/ VARIANT_BOOL * pvarfSounds ) = 0;
      virtual HRESULT __stdcall put_FeatureTips (
        /*[in]*/ VARIANT_BOOL pvarfFeatures ) = 0;
      virtual HRESULT __stdcall get_FeatureTips (
        /*[out,retval]*/ VARIANT_BOOL * pvarfFeatures ) = 0;
      virtual HRESULT __stdcall put_MouseTips (
        /*[in]*/ VARIANT_BOOL pvarfMouse ) = 0;
      virtual HRESULT __stdcall get_MouseTips (
        /*[out,retval]*/ VARIANT_BOOL * pvarfMouse ) = 0;
      virtual HRESULT __stdcall put_KeyboardShortcutTips (
        /*[in]*/ VARIANT_BOOL pvarfKeyboardShortcuts ) = 0;
      virtual HRESULT __stdcall get_KeyboardShortcutTips (
        /*[out,retval]*/ VARIANT_BOOL * pvarfKeyboardShortcuts ) = 0;
      virtual HRESULT __stdcall put_HighPriorityTips (
        /*[in]*/ VARIANT_BOOL pvarfHighPriorityTips ) = 0;
      virtual HRESULT __stdcall get_HighPriorityTips (
        /*[out,retval]*/ VARIANT_BOOL * pvarfHighPriorityTips ) = 0;
      virtual HRESULT __stdcall put_TipOfDay (
        /*[in]*/ VARIANT_BOOL pvarfTipOfDay ) = 0;
      virtual HRESULT __stdcall get_TipOfDay (
        /*[out,retval]*/ VARIANT_BOOL * pvarfTipOfDay ) = 0;
      virtual HRESULT __stdcall put_GuessHelp (
        /*[in]*/ VARIANT_BOOL pvarfGuessHelp ) = 0;
      virtual HRESULT __stdcall get_GuessHelp (
        /*[out,retval]*/ VARIANT_BOOL * pvarfGuessHelp ) = 0;
      virtual HRESULT __stdcall put_SearchWhenProgramming (
        /*[in]*/ VARIANT_BOOL pvarfSearchInProgram ) = 0;
      virtual HRESULT __stdcall get_SearchWhenProgramming (
        /*[out,retval]*/ VARIANT_BOOL * pvarfSearchInProgram ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_FileName (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_FileName (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_On (
        /*[out,retval]*/ VARIANT_BOOL * pvarfOn ) = 0;
      virtual HRESULT __stdcall put_On (
        /*[in]*/ VARIANT_BOOL pvarfOn ) = 0;
      virtual HRESULT __stdcall DoAlert (
        /*[in]*/ BSTR bstrAlertTitle,
        /*[in]*/ BSTR bstrAlertText,
        /*[in]*/ enum MsoAlertButtonType alb,
        /*[in]*/ enum MsoAlertIconType alc,
        /*[in]*/ enum MsoAlertDefaultType ald,
        /*[in]*/ enum MsoAlertCancelType alq,
        /*[in]*/ VARIANT_BOOL varfSysAlert,
        /*[out,retval]*/ int * pibtn ) = 0;
};

enum MsoSearchIn
{
    msoSearchInMyComputer = 0,
    msoSearchInOutlook = 1,
    msoSearchInMyNetworkPlaces = 2,
    msoSearchInCustom = 3
};

enum MsoTargetBrowser
{
    msoTargetBrowserV3 = 0,
    msoTargetBrowserV4 = 1,
    msoTargetBrowserIE4 = 2,
    msoTargetBrowserIE5 = 3,
    msoTargetBrowserIE6 = 4
};

struct __declspec(uuid("000c036c-0000-0000-c000-000000000046"))
FileTypes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ enum MsoFileType * MsoFileTypeRet ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * iCountRetVal ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum MsoFileType FileType ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ int Index ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

enum MsoOrgChartOrientation
{
    msoOrgChartOrientationMixed = -2,
    msoOrgChartOrientationVertical = 1
};

enum MsoOrgChartLayoutType
{
    msoOrgChartLayoutMixed = -2,
    msoOrgChartLayoutStandard = 1,
    msoOrgChartLayoutBothHanging = 2,
    msoOrgChartLayoutLeftHanging = 3,
    msoOrgChartLayoutRightHanging = 4,
    msoOrgChartLayoutDefault = 5
};

enum MsoRelativeNodePosition
{
    msoBeforeNode = 1,
    msoAfterNode = 2,
    msoBeforeFirstSibling = 3,
    msoAfterLastSibling = 4
};

enum MsoDiagramType
{
    msoDiagramMixed = -2,
    msoDiagramOrgChart = 1,
    msoDiagramCycle = 2,
    msoDiagramRadial = 3,
    msoDiagramPyramid = 4,
    msoDiagramVenn = 5,
    msoDiagramTarget = 6
};

enum MsoDiagramNodeType
{
    msoDiagramNode = 1,
    msoDiagramAssistant = 2
};

enum MsoMoveRow
{
    msoMoveRowFirst = -4,
    msoMoveRowPrev = -3,
    msoMoveRowNext = -2,
    msoMoveRowNbr = -1
};

struct __declspec(uuid("000c1530-0000-0000-c000-000000000046"))
OfficeDataSourceObject : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ConnectString (
        /*[out,retval]*/ BSTR * pbstrConnect ) = 0;
      virtual HRESULT __stdcall put_ConnectString (
        /*[in]*/ BSTR pbstrConnect ) = 0;
      virtual HRESULT __stdcall get_Table (
        /*[out,retval]*/ BSTR * pbstrTable ) = 0;
      virtual HRESULT __stdcall put_Table (
        /*[in]*/ BSTR pbstrTable ) = 0;
      virtual HRESULT __stdcall get_DataSource (
        /*[out,retval]*/ BSTR * pbstrSrc ) = 0;
      virtual HRESULT __stdcall put_DataSource (
        /*[in]*/ BSTR pbstrSrc ) = 0;
      virtual HRESULT __stdcall get_Columns (
        /*[out,retval]*/ IDispatch * * ppColumns ) = 0;
      virtual HRESULT __stdcall get_RowCount (
        /*[out,retval]*/ long * pcRows ) = 0;
      virtual HRESULT __stdcall get_Filters (
        /*[out,retval]*/ IDispatch * * ppFilters ) = 0;
      virtual HRESULT __stdcall Move (
        /*[in]*/ enum MsoMoveRow MsoMoveRow,
        /*[in]*/ int RowNbr,
        /*[out,retval]*/ int * rval ) = 0;
      virtual HRESULT __stdcall Open (
        /*[in]*/ BSTR bstrSrc,
        /*[in]*/ BSTR bstrConnect,
        /*[in]*/ BSTR bstrTable,
        /*[in]*/ long fOpenExclusive,
        /*[in]*/ long fNeverPrompt ) = 0;
      virtual HRESULT __stdcall SetSortOrder (
        /*[in]*/ BSTR SortField1,
        /*[in]*/ VARIANT_BOOL SortAscending1,
        /*[in]*/ BSTR SortField2,
        /*[in]*/ VARIANT_BOOL SortAscending2,
        /*[in]*/ BSTR SortField3,
        /*[in]*/ VARIANT_BOOL SortAscending3 ) = 0;
      virtual HRESULT __stdcall ApplyFilter ( ) = 0;
};

struct __declspec(uuid("000c1531-0000-0000-c000-000000000046"))
ODSOColumn : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * plIndex ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ BSTR * pbstrValue ) = 0;
};

struct __declspec(uuid("000c1532-0000-0000-c000-000000000046"))
ODSOColumns : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParentOdso ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT varIndex,
        /*[out,retval]*/ IDispatch * * ppColumn ) = 0;
};

enum MsoFilterComparison
{
    msoFilterComparisonEqual = 0,
    msoFilterComparisonNotEqual = 1,
    msoFilterComparisonLessThan = 2,
    msoFilterComparisonGreaterThan = 3,
    msoFilterComparisonLessThanEqual = 4,
    msoFilterComparisonGreaterThanEqual = 5,
    msoFilterComparisonIsBlank = 6,
    msoFilterComparisonIsNotBlank = 7,
    msoFilterComparisonContains = 8,
    msoFilterComparisonNotContains = 9
};

enum MsoFilterConjunction
{
    msoFilterConjunctionAnd = 0,
    msoFilterConjunctionOr = 1
};

struct __declspec(uuid("000c1533-0000-0000-c000-000000000046"))
ODSOFilter : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * plIndex ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Column (
        /*[out,retval]*/ BSTR * pbstrCol ) = 0;
      virtual HRESULT __stdcall put_Column (
        /*[in]*/ BSTR pbstrCol ) = 0;
      virtual HRESULT __stdcall get_Comparison (
        /*[out,retval]*/ enum MsoFilterComparison * pComparison ) = 0;
      virtual HRESULT __stdcall put_Comparison (
        /*[in]*/ enum MsoFilterComparison pComparison ) = 0;
      virtual HRESULT __stdcall get_CompareTo (
        /*[out,retval]*/ BSTR * pbstrCompareTo ) = 0;
      virtual HRESULT __stdcall put_CompareTo (
        /*[in]*/ BSTR pbstrCompareTo ) = 0;
      virtual HRESULT __stdcall get_Conjunction (
        /*[out,retval]*/ enum MsoFilterConjunction * pConjunction ) = 0;
      virtual HRESULT __stdcall put_Conjunction (
        /*[in]*/ enum MsoFilterConjunction pConjunction ) = 0;
};

struct __declspec(uuid("000c1534-0000-0000-c000-000000000046"))
ODSOFilters : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParentOdso ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ IDispatch * * ppColumn ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Column,
        /*[in]*/ enum MsoFilterComparison Comparison,
        /*[in]*/ enum MsoFilterConjunction Conjunction,
        /*[in]*/ BSTR bstrCompareTo,
        /*[in]*/ VARIANT_BOOL DeferUpdate ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ long Index,
        /*[in]*/ VARIANT_BOOL DeferUpdate ) = 0;
};

enum MsoFileNewSection
{
    msoOpenDocument = 0,
    msoNew = 1,
    msoNewfromExistingFile = 2,
    msoNewfromTemplate = 3,
    msoBottomSection = 4
};

enum MsoFileNewAction
{
    msoEditFile = 0,
    msoCreateNewFile = 1,
    msoOpenFile = 2
};

struct __declspec(uuid("000c0936-0000-0000-c000-000000000046"))
NewFile : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR FileName,
        /*[in]*/ VARIANT Section,
        /*[in]*/ VARIANT DisplayName,
        /*[in]*/ VARIANT Action,
        /*[out,retval]*/ VARIANT_BOOL * pvarf ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ BSTR FileName,
        /*[in]*/ VARIANT Section,
        /*[in]*/ VARIANT DisplayName,
        /*[in]*/ VARIANT Action,
        /*[out,retval]*/ VARIANT_BOOL * pvarf ) = 0;
};

struct __declspec(uuid("000cd100-0000-0000-c000-000000000046"))
WebComponent : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Shape (
        /*[out,retval]*/ IDispatch * * RetValue ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_URL (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_HTML (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_HTML (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long RetValue ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ long RetValue ) = 0;
      virtual HRESULT __stdcall SetPlaceHolderGraphic (
        /*[in]*/ BSTR PlaceHolderGraphic ) = 0;
      virtual HRESULT __stdcall Commit ( ) = 0;
      virtual HRESULT __stdcall Revert ( ) = 0;
};

struct __declspec(uuid("000cd101-0000-0000-c000-000000000046"))
WebComponentWindowExternal : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_InterfaceVersion (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall get_ApplicationName (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall get_ApplicationVersion (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * RetValue ) = 0;
      virtual HRESULT __stdcall CloseWindow ( ) = 0;
      virtual HRESULT __stdcall get_WebComponent (
        /*[out,retval]*/ struct WebComponent * * RetValue ) = 0;
};

struct __declspec(uuid("000cd102-0000-0000-c000-000000000046"))
WebComponentFormat : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * RetValue ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_URL (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_HTML (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_HTML (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long RetValue ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ long RetValue ) = 0;
      virtual HRESULT __stdcall get_PreviewGraphic (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall put_PreviewGraphic (
        /*[in]*/ BSTR retval ) = 0;
      virtual HRESULT __stdcall LaunchPropertiesWindow ( ) = 0;
};

enum MsoLanguageIDHidden
{
    msoLanguageIDChineseHongKong = 3076,
    msoLanguageIDChineseMacao = 5124,
    msoLanguageIDEnglishTrinidad = 11273
};

struct __declspec(uuid("4cac6328-b9b0-11d3-8d59-0050048384e3"))
ILicWizExternal : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall PrintHtmlDocument (
        /*[in]*/ IUnknown * punkHtmlDoc ) = 0;
      virtual HRESULT __stdcall InvokeDateTimeApplet ( ) = 0;
      virtual HRESULT __stdcall FormatDate (
        /*[in]*/ DATE date,
        /*[in]*/ BSTR pFormat,
        /*[out,retval]*/ BSTR * pDateString ) = 0;
      virtual HRESULT __stdcall ShowHelp (
        /*[in]*/ VARIANT * pvarId = &vtMissing ) = 0;
      virtual HRESULT __stdcall Terminate ( ) = 0;
      virtual HRESULT __stdcall DisableVORWReminder (
        /*[in]*/ long BPC ) = 0;
      virtual HRESULT __stdcall SaveReceipt (
        /*[in]*/ BSTR bstrReceipt,
        /*[out,retval]*/ BSTR * pbstrPath ) = 0;
      virtual HRESULT __stdcall OpenInDefaultBrowser (
        /*[in]*/ BSTR bstrUrl ) = 0;
      virtual HRESULT __stdcall MsoAlert (
        /*[in]*/ BSTR bstrText,
        /*[in]*/ BSTR bstrButtons,
        /*[in]*/ BSTR bstrIcon,
        /*[out,retval]*/ long * plRet ) = 0;
      virtual HRESULT __stdcall DepositPidKey (
        /*[in]*/ BSTR bstrKey,
        /*[in]*/ int fMORW,
        /*[out,retval]*/ long * plRet ) = 0;
      virtual HRESULT __stdcall WriteLog (
        /*[in]*/ BSTR bstrMessage ) = 0;
      virtual HRESULT __stdcall ResignDpc (
        /*[in]*/ BSTR bstrProductCode ) = 0;
      virtual HRESULT __stdcall ResetPID ( ) = 0;
      virtual HRESULT __stdcall SetDialogSize (
        /*[in]*/ long dx,
        /*[in]*/ long dy ) = 0;
      virtual HRESULT __stdcall VerifyClock (
        /*[in]*/ long lMode,
        /*[out,retval]*/ long * plRet ) = 0;
      virtual HRESULT __stdcall SortSelectOptions (
        /*[in]*/ IDispatch * pdispSelect ) = 0;
      virtual HRESULT __stdcall InternetDisconnect ( ) = 0;
      virtual HRESULT __stdcall GetConnectedState (
        /*[out,retval]*/ int * pfConnected ) = 0;
      virtual HRESULT __stdcall get_Context (
        /*[out,retval]*/ long * plwctx ) = 0;
      virtual HRESULT __stdcall get_Validator (
        /*[out,retval]*/ IDispatch * * ppdispValidator ) = 0;
      virtual HRESULT __stdcall get_LicAgent (
        /*[out,retval]*/ IDispatch * * ppdispLicAgent ) = 0;
      virtual HRESULT __stdcall get_CountryInfo (
        /*[out,retval]*/ BSTR * pbstrUrl ) = 0;
      virtual HRESULT __stdcall put_WizardVisible (
        /*[in]*/ int _arg1 ) = 0;
      virtual HRESULT __stdcall put_WizardTitle (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_AnimationEnabled (
        /*[out,retval]*/ int * fEnabled ) = 0;
      virtual HRESULT __stdcall put_CurrentHelpId (
        /*[in]*/ long _arg1 ) = 0;
      virtual HRESULT __stdcall get_OfficeOnTheWebUrl (
        /*[out,retval]*/ BSTR * bstrUrl ) = 0;
};

struct __declspec(uuid("919aa22c-b9ad-11d3-8d59-0050048384e3"))
ILicValidator : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Products (
        /*[out,retval]*/ VARIANT * pVariant ) = 0;
      virtual HRESULT __stdcall get_Selection (
        /*[out,retval]*/ int * piSel ) = 0;
      virtual HRESULT __stdcall put_Selection (
        /*[in]*/ int piSel ) = 0;
};

struct __declspec(uuid("00194002-d9c3-11d3-8d59-0050048384e3"))
ILicAgent : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Initialize (
        /*[in]*/ unsigned long dwBPC,
        /*[in]*/ unsigned long dwMode,
        /*[in]*/ BSTR bstrLicSource,
        /*[out,retval]*/ unsigned long * pdwRetCode ) = 0;
      virtual HRESULT __stdcall GetFirstName (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetFirstName (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetLastName (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetLastName (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetOrgName (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetOrgName (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetEmail (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetEmail (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetPhone (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetPhone (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetAddress1 (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetAddress1 (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetCity (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetCity (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetState (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetState (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetCountryCode (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetCountryCode (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetCountryDesc (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetCountryDesc (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetZip (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetZip (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetIsoLanguage (
        /*[out,retval]*/ unsigned long * pdwVal ) = 0;
      virtual HRESULT __stdcall SetIsoLanguage (
        /*[in]*/ unsigned long dwNewVal ) = 0;
      virtual HRESULT __stdcall GetMSUpdate (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetMSUpdate (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetMSOffer (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetMSOffer (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetOtherOffer (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetOtherOffer (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetAddress2 (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetAddress2 (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall CheckSystemClock (
        /*[out,retval]*/ unsigned long * pdwRetCode ) = 0;
      virtual HRESULT __stdcall GetExistingExpiryDate (
        /*[out,retval]*/ DATE * pDateVal ) = 0;
      virtual HRESULT __stdcall GetNewExpiryDate (
        /*[out,retval]*/ DATE * pDateVal ) = 0;
      virtual HRESULT __stdcall GetBillingFirstName (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingFirstName (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingLastName (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingLastName (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingPhone (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingPhone (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingAddress1 (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingAddress1 (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingAddress2 (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingAddress2 (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingCity (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingCity (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingState (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingState (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingCountryCode (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingCountryCode (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall GetBillingZip (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall SetBillingZip (
        /*[in]*/ BSTR bstrNewVal ) = 0;
      virtual HRESULT __stdcall SaveBillingInfo (
        /*[in]*/ int bSave,
        /*[out,retval]*/ unsigned long * pdwRetVal ) = 0;
      virtual HRESULT __stdcall IsCCRenewalCountry (
        /*[in]*/ BSTR bstrCountryCode,
        /*[out,retval]*/ int * pbRetVal ) = 0;
      virtual HRESULT __stdcall GetVATLabel (
        /*[in]*/ BSTR bstrCountryCode,
        /*[out,retval]*/ BSTR * pbstrVATLabel ) = 0;
      virtual HRESULT __stdcall GetCCRenewalExpiryDate (
        /*[out,retval]*/ DATE * pDateVal ) = 0;
      virtual HRESULT __stdcall SetVATNumber (
        /*[in]*/ BSTR bstrVATNumber ) = 0;
      virtual HRESULT __stdcall SetCreditCardType (
        /*[in]*/ BSTR bstrCCCode ) = 0;
      virtual HRESULT __stdcall SetCreditCardNumber (
        /*[in]*/ BSTR bstrCCNumber ) = 0;
      virtual HRESULT __stdcall SetCreditCardExpiryYear (
        /*[in]*/ unsigned long dwCCYear ) = 0;
      virtual HRESULT __stdcall SetCreditCardExpiryMonth (
        /*[in]*/ unsigned long dwCCMonth ) = 0;
      virtual HRESULT __stdcall GetCreditCardCount (
        /*[out,retval]*/ unsigned long * pdwCount ) = 0;
      virtual HRESULT __stdcall GetCreditCardCode (
        /*[in]*/ unsigned long dwIndex,
        /*[out,retval]*/ BSTR * pbstrCode ) = 0;
      virtual HRESULT __stdcall GetCreditCardName (
        /*[in]*/ unsigned long dwIndex,
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall GetVATNumber (
        /*[out,retval]*/ BSTR * pbstrVATNumber ) = 0;
      virtual HRESULT __stdcall GetCreditCardType (
        /*[out,retval]*/ BSTR * pbstrCCCode ) = 0;
      virtual HRESULT __stdcall GetCreditCardNumber (
        /*[out,retval]*/ BSTR * pbstrCCNumber ) = 0;
      virtual HRESULT __stdcall GetCreditCardExpiryYear (
        /*[out,retval]*/ unsigned long * pdwCCYear ) = 0;
      virtual HRESULT __stdcall GetCreditCardExpiryMonth (
        /*[out,retval]*/ unsigned long * pdwCCMonth ) = 0;
      virtual HRESULT __stdcall GetDisconnectOption (
        /*[out,retval]*/ int * pbRetVal ) = 0;
      virtual HRESULT __stdcall SetDisconnectOption (
        /*[in]*/ int bNewVal ) = 0;
      virtual HRESULT __stdcall AsyncProcessHandshakeRequest (
        /*[in]*/ int bReviseCustInfo ) = 0;
      virtual HRESULT __stdcall AsyncProcessNewLicenseRequest ( ) = 0;
      virtual HRESULT __stdcall AsyncProcessReissueLicenseRequest ( ) = 0;
      virtual HRESULT __stdcall AsyncProcessRetailRenewalLicenseRequest ( ) = 0;
      virtual HRESULT __stdcall AsyncProcessReviseCustInfoRequest ( ) = 0;
      virtual HRESULT __stdcall AsyncProcessCCRenewalPriceRequest ( ) = 0;
      virtual HRESULT __stdcall AsyncProcessCCRenewalLicenseRequest ( ) = 0;
      virtual HRESULT __stdcall GetAsyncProcessReturnCode (
        /*[out,retval]*/ unsigned long * pdwRetCode ) = 0;
      virtual HRESULT __stdcall IsUpgradeAvailable (
        /*[out,retval]*/ int * pbUpgradeAvailable ) = 0;
      virtual HRESULT __stdcall WantUpgrade (
        /*[in]*/ int bWantUpgrade ) = 0;
      virtual HRESULT __stdcall AsyncProcessDroppedLicenseRequest ( ) = 0;
      virtual HRESULT __stdcall GenerateInstallationId (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall DepositConfirmationId (
        /*[in]*/ BSTR bstrVal,
        /*[out,retval]*/ unsigned long * pdwRetCode ) = 0;
      virtual HRESULT __stdcall VerifyCheckDigits (
        /*[in]*/ BSTR bstrCIDIID,
        /*[out,retval]*/ int * pbValue ) = 0;
      virtual HRESULT __stdcall GetCurrentExpiryDate (
        /*[out,retval]*/ DATE * pDateVal ) = 0;
      virtual HRESULT __stdcall CancelAsyncProcessRequest (
        /*[in]*/ int bIsLicenseRequest ) = 0;
      virtual HRESULT __stdcall GetCurrencyDescription (
        /*[in]*/ unsigned long dwCurrencyIndex,
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall GetPriceItemCount (
        /*[out,retval]*/ unsigned long * pdwCount ) = 0;
      virtual HRESULT __stdcall GetPriceItemLabel (
        /*[in]*/ unsigned long dwIndex,
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall GetPriceItemValue (
        /*[in]*/ unsigned long dwCurrencyIndex,
        /*[in]*/ unsigned long dwIndex,
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall GetInvoiceText (
        /*[out,retval]*/ BSTR * pNewVal ) = 0;
      virtual HRESULT __stdcall GetBackendErrorMsg (
        /*[out,retval]*/ BSTR * pbstrErrMsg ) = 0;
      virtual HRESULT __stdcall GetCurrencyOption (
        /*[out,retval]*/ unsigned long * dwCurrencyOption ) = 0;
      virtual HRESULT __stdcall SetCurrencyOption (
        /*[in]*/ unsigned long dwCurrencyOption ) = 0;
      virtual HRESULT __stdcall GetEndOfLifeHtmlText (
        /*[out,retval]*/ BSTR * pbstrHtmlText ) = 0;
      virtual HRESULT __stdcall DisplaySSLCert (
        /*[out,retval]*/ unsigned long * dwRetCode ) = 0;
};

struct __declspec(uuid("000c0372-0000-0000-c000-000000000046"))
IMsoEServicesDialog : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Close (
        /*[in]*/ VARIANT_BOOL ApplyWebComponentChanges ) = 0;
      virtual HRESULT __stdcall AddTrustedDomain (
        /*[in]*/ BSTR Domain ) = 0;
      virtual HRESULT __stdcall get_ApplicationName (
        /*[out,retval]*/ BSTR * retval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_WebComponent (
        /*[out,retval]*/ IDispatch * * ppdisp ) = 0;
      virtual HRESULT __stdcall get_ClipArt (
        /*[out,retval]*/ IDispatch * * ppdisp ) = 0;
};

struct __declspec(uuid("000c0373-0000-0000-c000-000000000046"))
WebComponentProperties : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Shape (
        /*[out,retval]*/ IDispatch * * RetValue ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_URL (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_HTML (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_HTML (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_PreviewGraphic (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_PreviewGraphic (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_PreviewHTML (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_PreviewHTML (
        /*[in]*/ BSTR RetValue ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long RetValue ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * RetValue ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ long RetValue ) = 0;
      virtual HRESULT __stdcall get_Tag (
        /*[out,retval]*/ BSTR * RetValue ) = 0;
      virtual HRESULT __stdcall put_Tag (
        /*[in]*/ BSTR RetValue ) = 0;
};

struct __declspec(uuid("000c0377-0000-0000-c000-000000000046"))
SmartDocument : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_SolutionID (
        /*[out,retval]*/ BSTR * pbstrID ) = 0;
      virtual HRESULT __stdcall put_SolutionID (
        /*[in]*/ BSTR pbstrID ) = 0;
      virtual HRESULT __stdcall get_SolutionURL (
        /*[out,retval]*/ BSTR * pbstrUrl ) = 0;
      virtual HRESULT __stdcall put_SolutionURL (
        /*[in]*/ BSTR pbstrUrl ) = 0;
      virtual HRESULT __stdcall PickSolution (
        /*[in]*/ VARIANT_BOOL ConsiderAllSchemas ) = 0;
      virtual HRESULT __stdcall RefreshPane ( ) = 0;
};

struct __declspec(uuid("000c0381-0000-0000-c000-000000000046"))
SharedWorkspaceMember : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DomainName (
        /*[out,retval]*/ BSTR * pbstrDomainName ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Email (
        /*[out,retval]*/ BSTR * pbstrEmail ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * Id ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c0382-0000-0000-c000-000000000046"))
SharedWorkspaceMembers : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct SharedWorkspaceMember * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Email,
        /*[in]*/ BSTR DomainName,
        /*[in]*/ BSTR DisplayName,
        /*[in]*/ VARIANT Role,
        /*[out,retval]*/ struct SharedWorkspaceMember * * ppMember ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_ItemCountExceeded (
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
};

enum MsoSharedWorkspaceTaskStatus
{
    msoSharedWorkspaceTaskStatusNotStarted = 1,
    msoSharedWorkspaceTaskStatusInProgress = 2,
    msoSharedWorkspaceTaskStatusCompleted = 3,
    msoSharedWorkspaceTaskStatusDeferred = 4,
    msoSharedWorkspaceTaskStatusWaiting = 5
};

enum MsoSharedWorkspaceTaskPriority
{
    msoSharedWorkspaceTaskPriorityHigh = 1,
    msoSharedWorkspaceTaskPriorityNormal = 2,
    msoSharedWorkspaceTaskPriorityLow = 3
};

struct __declspec(uuid("000c0379-0000-0000-c000-000000000046"))
SharedWorkspaceTask : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
      virtual HRESULT __stdcall get_AssignedTo (
        /*[out,retval]*/ BSTR * AssignedTo ) = 0;
      virtual HRESULT __stdcall put_AssignedTo (
        /*[in]*/ BSTR AssignedTo ) = 0;
      virtual HRESULT __stdcall get_Status (
        /*[out,retval]*/ enum MsoSharedWorkspaceTaskStatus * Status ) = 0;
      virtual HRESULT __stdcall put_Status (
        /*[in]*/ enum MsoSharedWorkspaceTaskStatus Status ) = 0;
      virtual HRESULT __stdcall get_Priority (
        /*[out,retval]*/ enum MsoSharedWorkspaceTaskPriority * Priority ) = 0;
      virtual HRESULT __stdcall put_Priority (
        /*[in]*/ enum MsoSharedWorkspaceTaskPriority Priority ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR Description ) = 0;
      virtual HRESULT __stdcall get_DueDate (
        /*[out,retval]*/ VARIANT * DueDate ) = 0;
      virtual HRESULT __stdcall put_DueDate (
        /*[in]*/ VARIANT DueDate ) = 0;
      virtual HRESULT __stdcall get_CreatedBy (
        /*[out,retval]*/ BSTR * CreatedBy ) = 0;
      virtual HRESULT __stdcall get_CreatedDate (
        /*[out,retval]*/ VARIANT * CreatedDate ) = 0;
      virtual HRESULT __stdcall get_ModifiedBy (
        /*[out,retval]*/ BSTR * ModifiedBy ) = 0;
      virtual HRESULT __stdcall get_ModifiedDate (
        /*[out,retval]*/ VARIANT * ModifiedDate ) = 0;
      virtual HRESULT __stdcall Save ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c037a-0000-0000-c000-000000000046"))
SharedWorkspaceTasks : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct SharedWorkspaceTask * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Title,
        /*[in]*/ VARIANT Status,
        /*[in]*/ VARIANT Priority,
        /*[in]*/ VARIANT Assignee,
        /*[in]*/ VARIANT Description,
        /*[in]*/ VARIANT DueDate,
        /*[out,retval]*/ struct SharedWorkspaceTask * * ppTask ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_ItemCountExceeded (
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
};

struct __declspec(uuid("000c037b-0000-0000-c000-000000000046"))
SharedWorkspaceFile : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * pbstrFilename ) = 0;
      virtual HRESULT __stdcall get_CreatedBy (
        /*[out,retval]*/ BSTR * pbstrCreatedBy ) = 0;
      virtual HRESULT __stdcall get_CreatedDate (
        /*[out,retval]*/ VARIANT * CreatedDate ) = 0;
      virtual HRESULT __stdcall get_ModifiedBy (
        /*[out,retval]*/ BSTR * pbstrModifiedBy ) = 0;
      virtual HRESULT __stdcall get_ModifiedDate (
        /*[out,retval]*/ VARIANT * ModifiedDate ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c037c-0000-0000-c000-000000000046"))
SharedWorkspaceFiles : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct SharedWorkspaceFile * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR FileName,
        /*[in]*/ VARIANT ParentFolder,
        /*[in]*/ VARIANT OverwriteIfFileAlreadyExists,
        /*[in]*/ VARIANT KeepInSync,
        /*[out,retval]*/ struct SharedWorkspaceFile * * ppFile ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_ItemCountExceeded (
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
};

struct __declspec(uuid("000c037d-0000-0000-c000-000000000046"))
SharedWorkspaceFolder : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_FolderName (
        /*[out,retval]*/ BSTR * FolderName ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ VARIANT DeleteEventIfFolderContainsFiles = vtMissing ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c037e-0000-0000-c000-000000000046"))
SharedWorkspaceFolders : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct SharedWorkspaceFolder * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR FolderName,
        /*[in]*/ VARIANT ParentFolder,
        /*[out,retval]*/ struct SharedWorkspaceFolder * * ppFolder ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_ItemCountExceeded (
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
};

struct __declspec(uuid("000c037f-0000-0000-c000-000000000046"))
SharedWorkspaceLink : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * URL ) = 0;
      virtual HRESULT __stdcall put_URL (
        /*[in]*/ BSTR URL ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR Description ) = 0;
      virtual HRESULT __stdcall get_Notes (
        /*[out,retval]*/ BSTR * Notes ) = 0;
      virtual HRESULT __stdcall put_Notes (
        /*[in]*/ BSTR Notes ) = 0;
      virtual HRESULT __stdcall get_CreatedBy (
        /*[out,retval]*/ BSTR * CreatedBy ) = 0;
      virtual HRESULT __stdcall get_CreatedDate (
        /*[out,retval]*/ VARIANT * CreatedDate ) = 0;
      virtual HRESULT __stdcall get_ModifiedBy (
        /*[out,retval]*/ BSTR * ModifiedBy ) = 0;
      virtual HRESULT __stdcall get_ModifiedDate (
        /*[out,retval]*/ VARIANT * ModifiedDate ) = 0;
      virtual HRESULT __stdcall Save ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c0380-0000-0000-c000-000000000046"))
SharedWorkspaceLinks : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct SharedWorkspaceLink * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR URL,
        /*[in]*/ VARIANT Description,
        /*[in]*/ VARIANT Notes,
        /*[out,retval]*/ struct SharedWorkspaceLink * * ppLink ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_ItemCountExceeded (
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
};

struct __declspec(uuid("000c0385-0000-0000-c000-000000000046"))
SharedWorkspace : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Members (
        /*[out,retval]*/ struct SharedWorkspaceMembers * * ppMembers ) = 0;
      virtual HRESULT __stdcall get_Tasks (
        /*[out,retval]*/ struct SharedWorkspaceTasks * * ppTasks ) = 0;
      virtual HRESULT __stdcall get_Files (
        /*[out,retval]*/ struct SharedWorkspaceFiles * * ppFiles ) = 0;
      virtual HRESULT __stdcall get_Folders (
        /*[out,retval]*/ struct SharedWorkspaceFolders * * ppFolders ) = 0;
      virtual HRESULT __stdcall get_Links (
        /*[out,retval]*/ struct SharedWorkspaceLinks * * ppLinks ) = 0;
      virtual HRESULT __stdcall Refresh ( ) = 0;
      virtual HRESULT __stdcall CreateNew (
        /*[in]*/ VARIANT URL = vtMissing,
        /*[in]*/ VARIANT Name = vtMissing ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * pbstrUrl ) = 0;
      virtual HRESULT __stdcall get_Connected (
        /*[out,retval]*/ VARIANT_BOOL * pfConnected ) = 0;
      virtual HRESULT __stdcall get_LastRefreshed (
        /*[out,retval]*/ VARIANT * pvarLastRefreshed ) = 0;
      virtual HRESULT __stdcall get_SourceURL (
        /*[out,retval]*/ BSTR * pbstrSourceURL ) = 0;
      virtual HRESULT __stdcall put_SourceURL (
        /*[in]*/ BSTR pbstrSourceURL ) = 0;
      virtual HRESULT __stdcall RemoveDocument ( ) = 0;
      virtual HRESULT __stdcall Disconnect ( ) = 0;
};

enum MsoSyncVersionType
{
    msoSyncVersionLastViewed = 0,
    msoSyncVersionServer = 1
};

enum MsoSyncConflictResolutionType
{
    msoSyncConflictClientWins = 0,
    msoSyncConflictServerWins = 1,
    msoSyncConflictMerge = 2
};

enum MsoSyncCompareType
{
    msoSyncCompareAndMerge = 0,
    msoSyncCompareSideBySide = 1
};

enum MsoSyncAvailableType
{
    msoSyncAvailableNone = 0,
    msoSyncAvailableOffline = 1,
    msoSyncAvailableAnywhere = 2
};

enum MsoSyncEventType
{
    msoSyncEventDownloadInitiated = 0,
    msoSyncEventDownloadSucceeded = 1,
    msoSyncEventDownloadFailed = 2,
    msoSyncEventUploadInitiated = 3,
    msoSyncEventUploadSucceeded = 4,
    msoSyncEventUploadFailed = 5,
    msoSyncEventDownloadNoChange = 6,
    msoSyncEventOffline = 7
};

enum MsoSyncErrorType
{
    msoSyncErrorNone = 0,
    msoSyncErrorUnauthorizedUser = 1,
    msoSyncErrorCouldNotConnect = 2,
    msoSyncErrorOutOfSpace = 3,
    msoSyncErrorFileNotFound = 4,
    msoSyncErrorFileTooLarge = 5,
    msoSyncErrorFileInUse = 6,
    msoSyncErrorVirusUpload = 7,
    msoSyncErrorVirusDownload = 8,
    msoSyncErrorUnknownUpload = 9,
    msoSyncErrorUnknownDownload = 10,
    msoSyncErrorCouldNotOpen = 11,
    msoSyncErrorCouldNotUpdate = 12,
    msoSyncErrorCouldNotCompare = 13,
    msoSyncErrorCouldNotResolve = 14,
    msoSyncErrorNoNetwork = 15,
    msoSyncErrorUnknown = 16
};

enum MsoSyncStatusType
{
    msoSyncStatusNoSharedWorkspace = 0,
    msoSyncStatusNotRoaming = 0,
    msoSyncStatusLatest = 1,
    msoSyncStatusNewerAvailable = 2,
    msoSyncStatusLocalChanges = 3,
    msoSyncStatusConflict = 4,
    msoSyncStatusSuspended = 5,
    msoSyncStatusError = 6
};

struct __declspec(uuid("000c0386-0000-0000-c000-000000000046"))
Sync : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Status (
        /*[out,retval]*/ enum MsoSyncStatusType * pStatusType ) = 0;
      virtual HRESULT __stdcall get_WorkspaceLastChangedBy (
        /*[out,retval]*/ BSTR * pbstrWorkspaceLastChangedBy ) = 0;
      virtual HRESULT __stdcall get_LastSyncTime (
        /*[out,retval]*/ VARIANT * pdatSavedTo ) = 0;
      virtual HRESULT __stdcall get_ErrorType (
        /*[out,retval]*/ enum MsoSyncErrorType * pErrorType ) = 0;
      virtual HRESULT __stdcall GetUpdate ( ) = 0;
      virtual HRESULT __stdcall PutUpdate ( ) = 0;
      virtual HRESULT __stdcall OpenVersion (
        /*[in]*/ enum MsoSyncVersionType SyncVersionType ) = 0;
      virtual HRESULT __stdcall ResolveConflict (
        /*[in]*/ enum MsoSyncConflictResolutionType SyncConflictResolution ) = 0;
      virtual HRESULT __stdcall Unsuspend ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c0387-0000-0000-c000-000000000046"))
DocumentLibraryVersion : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Modified (
        /*[out,retval]*/ VARIANT * pvarDate ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * lIndex ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_ModifiedBy (
        /*[out,retval]*/ BSTR * userName ) = 0;
      virtual HRESULT __stdcall get_Comments (
        /*[out,retval]*/ BSTR * Comments ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Open (
        /*[out,retval]*/ IDispatch * * ppdispOpened ) = 0;
      virtual HRESULT __stdcall Restore (
        /*[out,retval]*/ IDispatch * * ppdispOpened ) = 0;
};

struct __declspec(uuid("000c0388-0000-0000-c000-000000000046"))
DocumentLibraryVersions : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long lIndex,
        /*[out,retval]*/ struct DocumentLibraryVersion * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lCount ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_IsVersioningEnabled (
        /*[out,retval]*/ VARIANT_BOOL * pvarfVersioningOn ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
};

enum MsoPermission
{
    msoPermissionView = 1,
    msoPermissionRead = 1,
    msoPermissionEdit = 2,
    msoPermissionSave = 4,
    msoPermissionExtract = 8,
    msoPermissionChange = 15,
    msoPermissionPrint = 16,
    msoPermissionObjModel = 32,
    msoPermissionFullControl = 64,
    msoPermissionAllCommon = 127
};

struct __declspec(uuid("000c0375-0000-0000-c000-000000000046"))
UserPermission : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_UserId (
        /*[out,retval]*/ BSTR * UserId ) = 0;
      virtual HRESULT __stdcall get_Permission (
        /*[out,retval]*/ long * Permission ) = 0;
      virtual HRESULT __stdcall put_Permission (
        /*[in]*/ long Permission ) = 0;
      virtual HRESULT __stdcall get_ExpirationDate (
        /*[out,retval]*/ VARIANT * ExpirationDate ) = 0;
      virtual HRESULT __stdcall put_ExpirationDate (
        /*[in]*/ VARIANT ExpirationDate ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall Remove ( ) = 0;
};

struct __declspec(uuid("000c0376-0000-0000-c000-000000000046"))
Permission : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct UserPermission * * UserPerm ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get_EnableTrustedBrowser (
        /*[out,retval]*/ VARIANT_BOOL * Enable ) = 0;
      virtual HRESULT __stdcall put_EnableTrustedBrowser (
        /*[in]*/ VARIANT_BOOL Enable ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR UserId,
        /*[in]*/ VARIANT Permission,
        /*[in]*/ VARIANT ExpirationDate,
        /*[out,retval]*/ struct UserPermission * * UserPerm ) = 0;
      virtual HRESULT __stdcall ApplyPolicy (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall RemoveAll ( ) = 0;
      virtual HRESULT __stdcall get_Enabled (
        /*[out,retval]*/ VARIANT_BOOL * Enabled ) = 0;
      virtual HRESULT __stdcall put_Enabled (
        /*[in]*/ VARIANT_BOOL Enabled ) = 0;
      virtual HRESULT __stdcall get_RequestPermissionURL (
        /*[out,retval]*/ BSTR * Contact ) = 0;
      virtual HRESULT __stdcall put_RequestPermissionURL (
        /*[in]*/ BSTR Contact ) = 0;
      virtual HRESULT __stdcall get_PolicyName (
        /*[out,retval]*/ BSTR * PolicyName ) = 0;
      virtual HRESULT __stdcall get_PolicyDescription (
        /*[out,retval]*/ BSTR * PolicyDescription ) = 0;
      virtual HRESULT __stdcall get_StoreLicenses (
        /*[out,retval]*/ VARIANT_BOOL * Enabled ) = 0;
      virtual HRESULT __stdcall put_StoreLicenses (
        /*[in]*/ VARIANT_BOOL Enabled ) = 0;
      virtual HRESULT __stdcall get_DocumentAuthor (
        /*[out,retval]*/ BSTR * Author ) = 0;
      virtual HRESULT __stdcall put_DocumentAuthor (
        /*[in]*/ BSTR Author ) = 0;
      virtual HRESULT __stdcall get_PermissionFromPolicy (
        /*[out,retval]*/ VARIANT_BOOL * FromPolicy ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000c038c-0000-0000-c000-000000000046"))
MsoDebugOptions_UTRunResult : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Passed (
        /*[out,retval]*/ VARIANT_BOOL * Passed ) = 0;
      virtual HRESULT __stdcall get_ErrorString (
        /*[out,retval]*/ BSTR * Error ) = 0;
};

struct __declspec(uuid("000c038b-0000-0000-c000-000000000046"))
MsoDebugOptions_UT : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_CollectionName (
        /*[out,retval]*/ BSTR * pbstrColName ) = 0;
      virtual HRESULT __stdcall Run (
        /*[out,retval]*/ struct MsoDebugOptions_UTRunResult * * ppRunResult ) = 0;
};

struct __declspec(uuid("000c038a-0000-0000-c000-000000000046"))
MsoDebugOptions_UTs : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct MsoDebugOptions_UT * * ppUnitTest ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * iCountRetVal ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
      virtual HRESULT __stdcall GetUnitTestsInCollection (
        /*[in]*/ BSTR bstrCollectionName,
        /*[out,retval]*/ struct MsoDebugOptions_UTs * * MsoDebugOptions_UTs ) = 0;
      virtual HRESULT __stdcall GetUnitTest (
        /*[in]*/ BSTR bstrCollectionName,
        /*[in]*/ BSTR bstrUnitTestName,
        /*[out,retval]*/ struct MsoDebugOptions_UT * * MsoDebugOptions_UT ) = 0;
      virtual HRESULT __stdcall GetMatchingUnitTestsInCollection (
        /*[in]*/ BSTR bstrCollectionName,
        /*[in]*/ BSTR bstrUnitTestNameFilter,
        /*[out,retval]*/ struct MsoDebugOptions_UTs * * MsoDebugOptions_UTs ) = 0;
};

struct __declspec(uuid("000c0389-0000-0000-c000-000000000046"))
MsoDebugOptions_UTManager : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_UnitTests (
        /*[out,retval]*/ struct MsoDebugOptions_UTs * * ppMsoUnitTests ) = 0;
      virtual HRESULT __stdcall NotifyStartOfTestSuiteRun ( ) = 0;
      virtual HRESULT __stdcall NotifyEndOfTestSuiteRun ( ) = 0;
      virtual HRESULT __stdcall get_ReportErrors (
        /*[out,retval]*/ VARIANT_BOOL * pfReportErrors ) = 0;
      virtual HRESULT __stdcall put_ReportErrors (
        /*[in]*/ VARIANT_BOOL pfReportErrors ) = 0;
};

enum MsoMetaPropertyType
{
    msoMetaPropertyTypeUnknown = 0,
    msoMetaPropertyTypeBoolean = 1,
    msoMetaPropertyTypeChoice = 2,
    msoMetaPropertyTypeCalculated = 3,
    msoMetaPropertyTypeComputed = 4,
    msoMetaPropertyTypeCurrency = 5,
    msoMetaPropertyTypeDateTime = 6,
    msoMetaPropertyTypeFillInChoice = 7,
    msoMetaPropertyTypeGuid = 8,
    msoMetaPropertyTypeInteger = 9,
    msoMetaPropertyTypeLookup = 10,
    msoMetaPropertyTypeMultiChoiceLookup = 11,
    msoMetaPropertyTypeMultiChoice = 12,
    msoMetaPropertyTypeMultiChoiceFillIn = 13,
    msoMetaPropertyTypeNote = 14,
    msoMetaPropertyTypeNumber = 15,
    msoMetaPropertyTypeText = 16,
    msoMetaPropertyTypeUrl = 17,
    msoMetaPropertyTypeUser = 18,
    msoMetaPropertyTypeUserMulti = 19,
    msoMetaPropertyTypeBusinessData = 20,
    msoMetaPropertyTypeBusinessDataSecondary = 21,
    msoMetaPropertyTypeMax = 22
};

struct __declspec(uuid("000c038f-0000-0000-c000-000000000046"))
MetaProperty : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * pvarValue ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT pvarValue ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * pbstrID ) = 0;
      virtual HRESULT __stdcall get_IsReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * pfReadOnly ) = 0;
      virtual HRESULT __stdcall get_IsRequired (
        /*[out,retval]*/ VARIANT_BOOL * pfRequired ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoMetaPropertyType * ptype ) = 0;
      virtual HRESULT __stdcall Validate (
        /*[out,retval]*/ BSTR * pbstrError ) = 0;
      virtual HRESULT __stdcall get_ValidationError (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c038e-0000-0000-c000-000000000046"))
MetaProperties : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct MetaProperty * * ppmp ) = 0;
      virtual HRESULT __stdcall GetItemByInternalName (
        /*[in]*/ BSTR InternalName,
        /*[out,retval]*/ struct MetaProperty * * ppmp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pc ) = 0;
      virtual HRESULT __stdcall Validate (
        /*[out,retval]*/ BSTR * pbstrError ) = 0;
      virtual HRESULT __stdcall get_ValidationError (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_SchemaXml (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

enum MsoSignatureSubset
{
    msoSignatureSubsetSignaturesAllSigs = 0,
    msoSignatureSubsetSignaturesNonVisible = 1,
    msoSignatureSubsetSignatureLines = 2,
    msoSignatureSubsetSignatureLinesSigned = 3,
    msoSignatureSubsetSignatureLinesUnsigned = 4,
    msoSignatureSubsetAll = 5
};

struct __declspec(uuid("000c0391-0000-0000-c000-000000000046"))
PolicyItem : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * pbstrID ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstrDescription ) = 0;
      virtual HRESULT __stdcall get_Data (
        /*[out,retval]*/ BSTR * pbstrStatement ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c0390-0000-0000-c000-000000000046"))
ServerPolicy : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct PolicyItem * * pppi ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * pbstrID ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstrDescription ) = 0;
      virtual HRESULT __stdcall get_Statement (
        /*[out,retval]*/ BSTR * pbstrStatement ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pc ) = 0;
      virtual HRESULT __stdcall get_BlockPreview (
        /*[out,retval]*/ VARIANT_BOOL * pfBlockPreview ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

enum MsoDocInspectorStatus
{
    msoDocInspectorStatusDocOk = 0,
    msoDocInspectorStatusIssueFound = 1,
    msoDocInspectorStatusError = 2
};

struct __declspec(uuid("000c0393-0000-0000-c000-000000000046"))
DocumentInspector : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall Inspect (
        /*[out]*/ enum MsoDocInspectorStatus * Status,
        /*[out]*/ BSTR * Results ) = 0;
      virtual HRESULT __stdcall Fix (
        /*[out]*/ enum MsoDocInspectorStatus * Status,
        /*[out]*/ BSTR * Results ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000c0392-0000-0000-c000-000000000046"))
DocumentInspectors : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct DocumentInspector * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
};

struct __declspec(uuid("000cd900-0000-0000-c000-000000000046"))
WorkflowTask : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_ListID (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_WorkflowID (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_AssignedTo (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_CreatedBy (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_DueDate (
        /*[out,retval]*/ DATE * pdate ) = 0;
      virtual HRESULT __stdcall get_CreatedDate (
        /*[out,retval]*/ DATE * pdate ) = 0;
      virtual HRESULT __stdcall Show (
        /*[out,retval]*/ int * pRet ) = 0;
};

struct __declspec(uuid("000cd901-0000-0000-c000-000000000046"))
WorkflowTasks : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct WorkflowTask * * ppret ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pCount ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000cd902-0000-0000-c000-000000000046"))
WorkflowTemplate : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_DocumentLibraryName (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_DocumentLibraryURL (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall Show (
        /*[out,retval]*/ int * pRet ) = 0;
};

struct __declspec(uuid("000cd903-0000-0000-c000-000000000046"))
WorkflowTemplates : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct WorkflowTemplate * * ppret ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pCount ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000cd706-0000-0000-c000-000000000046"))
IDocumentInspector : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetInfo (
        /*[out]*/ BSTR * Name,
        /*[out]*/ BSTR * Desc ) = 0;
      virtual HRESULT __stdcall Inspect (
        /*[in]*/ IDispatch * Doc,
        /*[out]*/ enum MsoDocInspectorStatus * Status,
        /*[out]*/ BSTR * Result,
        /*[out]*/ BSTR * Action ) = 0;
      virtual HRESULT __stdcall Fix (
        /*[in]*/ IDispatch * Doc,
        /*[in]*/ long hwnd,
        /*[out]*/ enum MsoDocInspectorStatus * Status,
        /*[out]*/ BSTR * Result ) = 0;
};

enum SignatureDetail
{
    sigdetLocalSigningTime = 0,
    sigdetApplicationName = 1,
    sigdetApplicationVersion = 2,
    sigdetOfficeVersion = 3,
    sigdetWindowsVersion = 4,
    sigdetNumberOfMonitors = 5,
    sigdetHorizResolution = 6,
    sigdetVertResolution = 7,
    sigdetColorDepth = 8,
    sigdetSignedData = 9,
    sigdetDocPreviewImg = 10,
    sigdetIPFormHash = 11,
    sigdetIPCurrentView = 12,
    sigdetSignatureType = 13,
    sigdetHashAlgorithm = 14,
    sigdetShouldShowViewWarning = 15,
    sigdetDelSuggSigner = 16,
    sigdetDelSuggSignerSet = 17,
    sigdetDelSuggSignerLine2 = 18,
    sigdetDelSuggSignerLine2Set = 19,
    sigdetDelSuggSignerEmail = 20,
    sigdetDelSuggSignerEmailSet = 21
};

enum CertificateDetail
{
    certdetAvailable = 0,
    certdetSubject = 1,
    certdetIssuer = 2,
    certdetExpirationDate = 3,
    certdetThumbprint = 4
};

enum ContentVerificationResults
{
    contverresError = 0,
    contverresVerifying = 1,
    contverresUnverified = 2,
    contverresValid = 3,
    contverresModified = 4
};

enum CertificateVerificationResults
{
    certverresError = 0,
    certverresVerifying = 1,
    certverresUnverified = 2,
    certverresValid = 3,
    certverresInvalid = 4,
    certverresExpired = 5,
    certverresRevoked = 6,
    certverresUntrusted = 7
};

enum SignatureLineImage
{
    siglnimgSoftwareRequired = 0,
    siglnimgUnsigned = 1,
    siglnimgSignedValid = 2,
    siglnimgSignedInvalid = 3,
    siglnimgSigned = 4
};

enum SignatureProviderDetail
{
    sigprovdetUrl = 0,
    sigprovdetHashAlgorithm = 1,
    sigprovdetUIOnly = 2,
    sigprovdetUseOfficeUI = 3,
    sigprovdetUseOfficeStampUI = 4
};

enum SignatureType
{
    sigtypeUnknown = 0,
    sigtypeNonVisible = 1,
    sigtypeSignatureLine = 2,
    sigtypeMax = 3
};

struct __declspec(uuid("000cd6a1-0000-0000-c000-000000000046"))
SignatureSetup : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * pvarf ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_SignatureProvider (
        /*[out,retval]*/ BSTR * pbstrSigProv ) = 0;
      virtual HRESULT __stdcall get_SuggestedSigner (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SuggestedSigner (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_SuggestedSignerLine2 (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SuggestedSignerLine2 (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_SuggestedSignerEmail (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SuggestedSignerEmail (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_SigningInstructions (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SigningInstructions (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_AllowComments (
        /*[out,retval]*/ VARIANT_BOOL * pvarf ) = 0;
      virtual HRESULT __stdcall put_AllowComments (
        /*[in]*/ VARIANT_BOOL pvarf ) = 0;
      virtual HRESULT __stdcall get_ShowSignDate (
        /*[out,retval]*/ VARIANT_BOOL * pvarf ) = 0;
      virtual HRESULT __stdcall put_ShowSignDate (
        /*[in]*/ VARIANT_BOOL pvarf ) = 0;
      virtual HRESULT __stdcall get_AdditionalXml (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_AdditionalXml (
        /*[in]*/ BSTR pbstr ) = 0;
};

struct __declspec(uuid("000cd6a2-0000-0000-c000-000000000046"))
SignatureInfo : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * pvarf ) = 0;
      virtual HRESULT __stdcall get_SignatureProvider (
        /*[out,retval]*/ BSTR * pbstrSigProv ) = 0;
      virtual HRESULT __stdcall get_SignatureText (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SignatureText (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_SignatureImage (
        /*[out,retval]*/ IPictureDisp * * ppipictdisp ) = 0;
      virtual HRESULT __stdcall put_SignatureImage (
        /*[in]*/ IPictureDisp * ppipictdisp ) = 0;
      virtual HRESULT __stdcall get_SignatureComment (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_SignatureComment (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall GetSignatureDetail (
        /*[in]*/ enum SignatureDetail sigdet,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall GetCertificateDetail (
        /*[in]*/ enum CertificateDetail certdet,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_ContentVerificationResults (
        /*[out,retval]*/ enum ContentVerificationResults * pcontverres ) = 0;
      virtual HRESULT __stdcall get_CertificateVerificationResults (
        /*[out,retval]*/ enum CertificateVerificationResults * pcertverres ) = 0;
      virtual HRESULT __stdcall get_IsValid (
        /*[out,retval]*/ VARIANT_BOOL * pvarfValid ) = 0;
      virtual HRESULT __stdcall get_IsCertificateExpired (
        /*[out,retval]*/ VARIANT_BOOL * pvarfExpired ) = 0;
      virtual HRESULT __stdcall get_IsCertificateRevoked (
        /*[out,retval]*/ VARIANT_BOOL * pvarfRevoked ) = 0;
      virtual HRESULT __stdcall get_IsCertificateUntrusted (
        /*[out,retval]*/ VARIANT_BOOL * pvarfUntrusted ) = 0;
      virtual HRESULT __stdcall ShowSignatureCertificate (
        /*[in]*/ IUnknown * ParentWindow ) = 0;
      virtual HRESULT __stdcall SelectSignatureCertificate (
        /*[in]*/ IUnknown * ParentWindow ) = 0;
      virtual HRESULT __stdcall SelectCertificateDetailByThumbprint (
        /*[in]*/ BSTR bstrThumbprint ) = 0;
};

struct __declspec(uuid("000c0411-0000-0000-c000-000000000046"))
Signature : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Signer (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Issuer (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_ExpireDate (
        /*[out,retval]*/ VARIANT * pvarDate ) = 0;
      virtual HRESULT __stdcall get_IsValid (
        /*[out,retval]*/ VARIANT_BOOL * pvarfValid ) = 0;
      virtual HRESULT __stdcall get_AttachCertificate (
        /*[out,retval]*/ VARIANT_BOOL * pvarfAttach ) = 0;
      virtual HRESULT __stdcall put_AttachCertificate (
        /*[in]*/ VARIANT_BOOL pvarfAttach ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_IsCertificateExpired (
        /*[out,retval]*/ VARIANT_BOOL * pvarfExpired ) = 0;
      virtual HRESULT __stdcall get_IsCertificateRevoked (
        /*[out,retval]*/ VARIANT_BOOL * pvarfRevoked ) = 0;
      virtual HRESULT __stdcall get_SignDate (
        /*[out,retval]*/ VARIANT * pvarDate ) = 0;
      virtual HRESULT __stdcall get_IsSigned (
        /*[out,retval]*/ VARIANT_BOOL * pvarfSigned ) = 0;
      virtual HRESULT __stdcall Sign (
        /*[in]*/ VARIANT varSigImg = vtMissing,
        /*[in]*/ VARIANT varDelSuggSigner = vtMissing,
        /*[in]*/ VARIANT varDelSuggSignerLine2 = vtMissing,
        /*[in]*/ VARIANT varDelSuggSignerEmail = vtMissing ) = 0;
      virtual HRESULT __stdcall get_Details (
        /*[out,retval]*/ struct SignatureInfo * * ppsiginfo ) = 0;
      virtual HRESULT __stdcall ShowDetails ( ) = 0;
      virtual HRESULT __stdcall get_CanSetup (
        /*[out,retval]*/ VARIANT_BOOL * pvarfCanSetup ) = 0;
      virtual HRESULT __stdcall get_Setup (
        /*[out,retval]*/ struct SignatureSetup * * ppsigsetup ) = 0;
      virtual HRESULT __stdcall get_IsSignatureLine (
        /*[out,retval]*/ VARIANT_BOOL * pvarfSignatureLine ) = 0;
      virtual HRESULT __stdcall get_SignatureLineShape (
        /*[out,retval]*/ IDispatch * * ppidispShape ) = 0;
      virtual HRESULT __stdcall get_SortHint (
        /*[out,retval]*/ long * plSortHint ) = 0;
};

struct __declspec(uuid("000c0410-0000-0000-c000-000000000046"))
SignatureSet : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcSig ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int iSig,
        /*[out,retval]*/ struct Signature * * ppidisp ) = 0;
      virtual HRESULT __stdcall Add (
        /*[out,retval]*/ struct Signature * * ppidisp ) = 0;
      virtual HRESULT __stdcall Commit ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall AddNonVisibleSignature (
        /*[in]*/ VARIANT varSigProv,
        /*[out,retval]*/ struct Signature * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_CanAddSignatureLine (
        /*[out,retval]*/ VARIANT_BOOL * pvarfCanAddSigLine ) = 0;
      virtual HRESULT __stdcall AddSignatureLine (
        /*[in]*/ VARIANT varSigProv,
        /*[out,retval]*/ struct Signature * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Subset (
        /*[out,retval]*/ enum MsoSignatureSubset * psubset ) = 0;
      virtual HRESULT __stdcall put_Subset (
        /*[in]*/ enum MsoSignatureSubset psubset ) = 0;
      virtual HRESULT __stdcall put_ShowSignaturesPane (
        /*[in]*/ VARIANT_BOOL _arg1 ) = 0;
};

struct __declspec(uuid("000cd6a3-0000-0000-c000-000000000046"))
SignatureProvider : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GenerateSignatureLineImage (
        /*[in]*/ enum SignatureLineImage siglnimg,
        /*[in]*/ struct SignatureSetup * psigsetup,
        /*[in]*/ struct SignatureInfo * psiginfo,
        /*[in]*/ IUnknown * XmlDsigStream,
        /*[out,retval]*/ IPictureDisp * * ppipictdisp ) = 0;
      virtual HRESULT __stdcall ShowSignatureSetup (
        /*[in]*/ IUnknown * ParentWindow,
        /*[in]*/ struct SignatureSetup * psigsetup ) = 0;
      virtual HRESULT __stdcall ShowSigningCeremony (
        /*[in]*/ IUnknown * ParentWindow,
        /*[in]*/ struct SignatureSetup * psigsetup,
        /*[in]*/ struct SignatureInfo * psiginfo ) = 0;
      virtual HRESULT __stdcall SignXmlDsig (
        /*[in]*/ IUnknown * QueryContinue,
        /*[in]*/ struct SignatureSetup * psigsetup,
        /*[in]*/ struct SignatureInfo * psiginfo,
        /*[in]*/ IUnknown * XmlDsigStream ) = 0;
      virtual HRESULT __stdcall NotifySignatureAdded (
        /*[in]*/ IUnknown * ParentWindow,
        /*[in]*/ struct SignatureSetup * psigsetup,
        /*[in]*/ struct SignatureInfo * psiginfo ) = 0;
      virtual HRESULT __stdcall VerifyXmlDsig (
        /*[in]*/ IUnknown * QueryContinue,
        /*[in]*/ struct SignatureSetup * psigsetup,
        /*[in]*/ struct SignatureInfo * psiginfo,
        /*[in]*/ IUnknown * XmlDsigStream,
        /*[in,out]*/ enum ContentVerificationResults * pcontverres,
        /*[in,out]*/ enum CertificateVerificationResults * pcertverres ) = 0;
      virtual HRESULT __stdcall ShowSignatureDetails (
        /*[in]*/ IUnknown * ParentWindow,
        /*[in]*/ struct SignatureSetup * psigsetup,
        /*[in]*/ struct SignatureInfo * psiginfo,
        /*[in]*/ IUnknown * XmlDsigStream,
        /*[in,out]*/ enum ContentVerificationResults * pcontverres,
        /*[in,out]*/ enum CertificateVerificationResults * pcertverres ) = 0;
      virtual HRESULT __stdcall GetProviderDetail (
        /*[in]*/ enum SignatureProviderDetail sigprovdet,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall HashStream (
        /*[in]*/ IUnknown * QueryContinue,
        /*[in]*/ IUnknown * Stream,
        /*[out,retval]*/ SAFEARRAY * * ppsargb ) = 0;
};

enum MsoCustomXMLNodeType
{
    msoCustomXMLNodeElement = 1,
    msoCustomXMLNodeAttribute = 2,
    msoCustomXMLNodeText = 3,
    msoCustomXMLNodeCData = 4,
    msoCustomXMLNodeProcessingInstruction = 7,
    msoCustomXMLNodeComment = 8,
    msoCustomXMLNodeDocument = 9
};

enum MsoCustomXMLValidationErrorType
{
    msoCustomXMLValidationErrorSchemaGenerated = 0,
    msoCustomXMLValidationErrorAutomaticallyCleared = 1,
    msoCustomXMLValidationErrorManual = 2
};

struct __declspec(uuid("000cdb10-0000-0000-c000-000000000046"))
CustomXMLPrefixMapping : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Prefix (
        /*[out,retval]*/ BSTR * pbstrPrefix ) = 0;
      virtual HRESULT __stdcall get_NamespaceURI (
        /*[out,retval]*/ BSTR * pbstrNamespaceURI ) = 0;
};

struct __declspec(uuid("000cdb00-0000-0000-c000-000000000046"))
CustomXMLPrefixMappings : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct CustomXMLPrefixMapping * * ppPrefixMapping ) = 0;
      virtual HRESULT __stdcall AddNamespace (
        /*[in]*/ BSTR Prefix,
        /*[in]*/ BSTR NamespaceURI ) = 0;
      virtual HRESULT __stdcall LookupNamespace (
        /*[in]*/ BSTR Prefix,
        /*[out,retval]*/ BSTR * pbstrNamespaceURI ) = 0;
      virtual HRESULT __stdcall LookupPrefix (
        /*[in]*/ BSTR NamespaceURI,
        /*[out,retval]*/ BSTR * pbstrPrefix ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000cdb01-0000-0000-c000-000000000046"))
CustomXMLSchema : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Location (
        /*[out,retval]*/ BSTR * pbstrLocation ) = 0;
      virtual HRESULT __stdcall get_NamespaceURI (
        /*[out,retval]*/ BSTR * pbstrNamespaceURI ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Reload ( ) = 0;
};

struct __declspec(uuid("000cdb0d-0000-0000-c000-000000000046"))
CustomXMLSchemaCollection;
    // [ default ] interface _CustomXMLSchemaCollection

struct __declspec(uuid("000cdb02-0000-0000-c000-000000000046"))
_CustomXMLSchemaCollection : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct CustomXMLSchema * * ppSchema ) = 0;
      virtual HRESULT __stdcall get_NamespaceURI (
        /*[in]*/ long Index,
        /*[out,retval]*/ BSTR * pbstrNamespaceURI ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR NamespaceURI,
        /*[in]*/ BSTR Alias,
        /*[in]*/ BSTR FileName,
        /*[in]*/ VARIANT_BOOL InstallForAllUsers,
        /*[out,retval]*/ struct CustomXMLSchema * * ppSchema ) = 0;
      virtual HRESULT __stdcall AddCollection (
        /*[in]*/ struct _CustomXMLSchemaCollection * SchemaCollection ) = 0;
      virtual HRESULT __stdcall Validate (
        /*[out,retval]*/ VARIANT_BOOL * pfResult ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000cdb07-0000-0000-c000-000000000046"))
_CustomXMLPartEvents : IDispatch
{};

struct __declspec(uuid("000cdb08-0000-0000-c000-000000000046"))
CustomXMLPart;
    // [ default ] interface _CustomXMLPart
    // [ default, source ] dispinterface _CustomXMLPartEvents

struct __declspec(uuid("000cdb0a-0000-0000-c000-000000000046"))
ICustomXMLPartsEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual void __stdcall PartAfterAdd (
        /*[in]*/ struct _CustomXMLPart * NewPart ) = 0;
      virtual void __stdcall PartBeforeDelete (
        /*[in]*/ struct _CustomXMLPart * OldPart ) = 0;
      virtual void __stdcall PartAfterLoad (
        /*[in]*/ struct _CustomXMLPart * Part ) = 0;
};

struct __declspec(uuid("000cdb0b-0000-0000-c000-000000000046"))
_CustomXMLPartsEvents : IDispatch
{};

struct __declspec(uuid("000cdb0c-0000-0000-c000-000000000046"))
CustomXMLParts;
    // [ default ] interface _CustomXMLParts
    // [ default, source ] dispinterface _CustomXMLPartsEvents

struct __declspec(uuid("000cdb09-0000-0000-c000-000000000046"))
_CustomXMLParts : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct _CustomXMLPart * * ppPart ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR XML,
        /*[in]*/ VARIANT SchemaCollection,
        /*[out,retval]*/ struct _CustomXMLPart * * ppPart ) = 0;
      virtual HRESULT __stdcall SelectByID (
        /*[in]*/ BSTR Id,
        /*[out,retval]*/ struct _CustomXMLPart * * ppPart ) = 0;
      virtual HRESULT __stdcall SelectByNamespace (
        /*[in]*/ BSTR NamespaceURI,
        /*[out,retval]*/ struct _CustomXMLParts * * ppParts ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

enum MsoTextureAlignment
{
    msoTextureAlignmentMixed = -2,
    msoTextureTopLeft = 0,
    msoTextureTop = 1,
    msoTextureTopRight = 2,
    msoTextureLeft = 3,
    msoTextureCenter = 4,
    msoTextureRight = 5,
    msoTextureBottomLeft = 6,
    msoTextureBottom = 7,
    msoTextureBottomRight = 8
};

enum MsoSoftEdgeType
{
    msoSoftEdgeTypeMixed = -2,
    msoSoftEdgeTypeNone = 0,
    msoSoftEdgeType1 = 1,
    msoSoftEdgeType2 = 2,
    msoSoftEdgeType3 = 3,
    msoSoftEdgeType4 = 4,
    msoSoftEdgeType5 = 5,
    msoSoftEdgeType6 = 6
};

enum MsoReflectionType
{
    msoReflectionTypeMixed = -2,
    msoReflectionTypeNone = 0,
    msoReflectionType1 = 1,
    msoReflectionType2 = 2,
    msoReflectionType3 = 3,
    msoReflectionType4 = 4,
    msoReflectionType5 = 5,
    msoReflectionType6 = 6,
    msoReflectionType7 = 7,
    msoReflectionType8 = 8,
    msoReflectionType9 = 9
};

struct __declspec(uuid("000c03bc-0000-0000-c000-000000000046"))
SoftEdgeFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoSoftEdgeType * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum MsoSoftEdgeType Type ) = 0;
      virtual HRESULT __stdcall get_Radius (
        /*[out,retval]*/ float * Radius ) = 0;
      virtual HRESULT __stdcall put_Radius (
        /*[in]*/ float Radius ) = 0;
};

struct __declspec(uuid("000c03be-0000-0000-c000-000000000046"))
ReflectionFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoReflectionType * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum MsoReflectionType Type ) = 0;
      virtual HRESULT __stdcall get_Transparency (
        /*[out,retval]*/ float * Transparency ) = 0;
      virtual HRESULT __stdcall put_Transparency (
        /*[in]*/ float Transparency ) = 0;
      virtual HRESULT __stdcall get_Size (
        /*[out,retval]*/ float * Size ) = 0;
      virtual HRESULT __stdcall put_Size (
        /*[in]*/ float Size ) = 0;
      virtual HRESULT __stdcall get_Offset (
        /*[out,retval]*/ float * Offset ) = 0;
      virtual HRESULT __stdcall put_Offset (
        /*[in]*/ float Offset ) = 0;
      virtual HRESULT __stdcall get_Blur (
        /*[out,retval]*/ float * Blur ) = 0;
      virtual HRESULT __stdcall put_Blur (
        /*[in]*/ float Blur ) = 0;
};

enum MsoPresetCamera
{
    msoPresetCameraMixed = -2,
    msoCameraLegacyObliqueTopLeft = 1,
    msoCameraLegacyObliqueTop = 2,
    msoCameraLegacyObliqueTopRight = 3,
    msoCameraLegacyObliqueLeft = 4,
    msoCameraLegacyObliqueFront = 5,
    msoCameraLegacyObliqueRight = 6,
    msoCameraLegacyObliqueBottomLeft = 7,
    msoCameraLegacyObliqueBottom = 8,
    msoCameraLegacyObliqueBottomRight = 9,
    msoCameraLegacyPerspectiveTopLeft = 10,
    msoCameraLegacyPerspectiveTop = 11,
    msoCameraLegacyPerspectiveTopRight = 12,
    msoCameraLegacyPerspectiveLeft = 13,
    msoCameraLegacyPerspectiveFront = 14,
    msoCameraLegacyPerspectiveRight = 15,
    msoCameraLegacyPerspectiveBottomLeft = 16,
    msoCameraLegacyPerspectiveBottom = 17,
    msoCameraLegacyPerspectiveBottomRight = 18,
    msoCameraOrthographicFront = 19,
    msoCameraIsometricTopUp = 20,
    msoCameraIsometricTopDown = 21,
    msoCameraIsometricBottomUp = 22,
    msoCameraIsometricBottomDown = 23,
    msoCameraIsometricLeftUp = 24,
    msoCameraIsometricLeftDown = 25,
    msoCameraIsometricRightUp = 26,
    msoCameraIsometricRightDown = 27,
    msoCameraIsometricOffAxis1Left = 28,
    msoCameraIsometricOffAxis1Right = 29,
    msoCameraIsometricOffAxis1Top = 30,
    msoCameraIsometricOffAxis2Left = 31,
    msoCameraIsometricOffAxis2Right = 32,
    msoCameraIsometricOffAxis2Top = 33,
    msoCameraIsometricOffAxis3Left = 34,
    msoCameraIsometricOffAxis3Right = 35,
    msoCameraIsometricOffAxis3Bottom = 36,
    msoCameraIsometricOffAxis4Left = 37,
    msoCameraIsometricOffAxis4Right = 38,
    msoCameraIsometricOffAxis4Bottom = 39,
    msoCameraObliqueTopLeft = 40,
    msoCameraObliqueTop = 41,
    msoCameraObliqueTopRight = 42,
    msoCameraObliqueLeft = 43,
    msoCameraObliqueRight = 44,
    msoCameraObliqueBottomLeft = 45,
    msoCameraObliqueBottom = 46,
    msoCameraObliqueBottomRight = 47,
    msoCameraPerspectiveFront = 48,
    msoCameraPerspectiveLeft = 49,
    msoCameraPerspectiveRight = 50,
    msoCameraPerspectiveAbove = 51,
    msoCameraPerspectiveBelow = 52,
    msoCameraPerspectiveAboveLeftFacing = 53,
    msoCameraPerspectiveAboveRightFacing = 54,
    msoCameraPerspectiveContrastingLeftFacing = 55,
    msoCameraPerspectiveContrastingRightFacing = 56,
    msoCameraPerspectiveHeroicLeftFacing = 57,
    msoCameraPerspectiveHeroicRightFacing = 58,
    msoCameraPerspectiveHeroicExtremeLeftFacing = 59,
    msoCameraPerspectiveHeroicExtremeRightFacing = 60,
    msoCameraPerspectiveRelaxed = 61,
    msoCameraPerspectiveRelaxedModerately = 62
};

enum MsoBevelType
{
    msoBevelTypeMixed = -2,
    msoBevelNone = 1,
    msoBevelRelaxedInset = 2,
    msoBevelCircle = 3,
    msoBevelSlope = 4,
    msoBevelCross = 5,
    msoBevelAngle = 6,
    msoBevelSoftRound = 7,
    msoBevelConvex = 8,
    msoBevelCoolSlant = 9,
    msoBevelDivot = 10,
    msoBevelRiblet = 11,
    msoBevelHardEdge = 12,
    msoBevelArtDeco = 13
};

enum MsoLightRigType
{
    msoLightRigMixed = -2,
    msoLightRigLegacyFlat1 = 1,
    msoLightRigLegacyFlat2 = 2,
    msoLightRigLegacyFlat3 = 3,
    msoLightRigLegacyFlat4 = 4,
    msoLightRigLegacyNormal1 = 5,
    msoLightRigLegacyNormal2 = 6,
    msoLightRigLegacyNormal3 = 7,
    msoLightRigLegacyNormal4 = 8,
    msoLightRigLegacyHarsh1 = 9,
    msoLightRigLegacyHarsh2 = 10,
    msoLightRigLegacyHarsh3 = 11,
    msoLightRigLegacyHarsh4 = 12,
    msoLightRigThreePoint = 13,
    msoLightRigBalanced = 14,
    msoLightRigSoft = 15,
    msoLightRigHarsh = 16,
    msoLightRigFlood = 17,
    msoLightRigContrasting = 18,
    msoLightRigMorning = 19,
    msoLightRigSunrise = 20,
    msoLightRigSunset = 21,
    msoLightRigChilly = 22,
    msoLightRigFreezing = 23,
    msoLightRigFlat = 24,
    msoLightRigTwoPoint = 25,
    msoLightRigGlow = 26,
    msoLightRigBrightRoom = 27
};

enum MsoParagraphAlignment
{
    msoAlignMixed = -2,
    msoAlignLeft = 1,
    msoAlignCenter = 2,
    msoAlignRight = 3,
    msoAlignJustify = 4,
    msoAlignDistribute = 5,
    msoAlignThaiDistribute = 6,
    msoAlignJustifyLow = 7
};

enum MsoTextStrike
{
    msoStrikeMixed = -2,
    msoNoStrike = 0,
    msoSingleStrike = 1,
    msoDoubleStrike = 2
};

enum MsoTextCaps
{
    msoCapsMixed = -2,
    msoNoCaps = 0,
    msoSmallCaps = 1,
    msoAllCaps = 2
};

enum MsoTextUnderlineType
{
    msoUnderlineMixed = -2,
    msoNoUnderline = 0,
    msoUnderlineWords = 1,
    msoUnderlineSingleLine = 2,
    msoUnderlineDoubleLine = 3,
    msoUnderlineHeavyLine = 4,
    msoUnderlineDottedLine = 5,
    msoUnderlineDottedHeavyLine = 6,
    msoUnderlineDashLine = 7,
    msoUnderlineDashHeavyLine = 8,
    msoUnderlineDashLongLine = 9,
    msoUnderlineDashLongHeavyLine = 10,
    msoUnderlineDotDashLine = 11,
    msoUnderlineDotDashHeavyLine = 12,
    msoUnderlineDotDotDashLine = 13,
    msoUnderlineDotDotDashHeavyLine = 14,
    msoUnderlineWavyLine = 15,
    msoUnderlineWavyHeavyLine = 16,
    msoUnderlineWavyDoubleLine = 17
};

enum MsoTextTabAlign
{
    msoTabAlignMixed = -2,
    msoTabAlignLeft = 0,
    msoTabAlignCenter = 1,
    msoTabAlignRight = 2,
    msoTabAlignDecimal = 3
};

enum MsoTextCharWrap
{
    msoCharWrapMixed = -2,
    msoNoCharWrap = 0,
    msoStandardCharWrap = 1,
    msoStrictCharWrap = 2,
    msoCustomCharWrap = 3
};

enum MsoTextFontAlign
{
    msoFontAlignMixed = -2,
    msoFontAlignAuto = 0,
    msoFontAlignTop = 1,
    msoFontAlignCenter = 2,
    msoFontAlignBaseline = 3,
    msoFontAlignBottom = 4
};

enum MsoAutoSize
{
    msoAutoSizeMixed = -2,
    msoAutoSizeNone = 0,
    msoAutoSizeShapeToFitText = 1,
    msoAutoSizeTextToFitShape = 2
};

enum MsoPathFormat
{
    msoPathTypeMixed = -2,
    msoPathTypeNone = 0,
    msoPathType1 = 1,
    msoPathType2 = 2,
    msoPathType3 = 3,
    msoPathType4 = 4
};

enum MsoWarpFormat
{
    msoWarpFormatMixed = -2,
    msoWarpFormat1 = 0,
    msoWarpFormat2 = 1,
    msoWarpFormat3 = 2,
    msoWarpFormat4 = 3,
    msoWarpFormat5 = 4,
    msoWarpFormat6 = 5,
    msoWarpFormat7 = 6,
    msoWarpFormat8 = 7,
    msoWarpFormat9 = 8,
    msoWarpFormat10 = 9,
    msoWarpFormat11 = 10,
    msoWarpFormat12 = 11,
    msoWarpFormat13 = 12,
    msoWarpFormat14 = 13,
    msoWarpFormat15 = 14,
    msoWarpFormat16 = 15,
    msoWarpFormat17 = 16,
    msoWarpFormat18 = 17,
    msoWarpFormat19 = 18,
    msoWarpFormat20 = 19,
    msoWarpFormat21 = 20,
    msoWarpFormat22 = 21,
    msoWarpFormat23 = 22,
    msoWarpFormat24 = 23,
    msoWarpFormat25 = 24,
    msoWarpFormat26 = 25,
    msoWarpFormat27 = 26,
    msoWarpFormat28 = 27,
    msoWarpFormat29 = 28,
    msoWarpFormat30 = 29,
    msoWarpFormat31 = 30,
    msoWarpFormat32 = 31,
    msoWarpFormat33 = 32,
    msoWarpFormat34 = 33,
    msoWarpFormat35 = 34,
    msoWarpFormat36 = 35,
    msoWarpFormat37 = 36
};

enum MsoTextChangeCase
{
    msoCaseSentence = 1,
    msoCaseLower = 2,
    msoCaseUpper = 3,
    msoCaseTitle = 4,
    msoCaseToggle = 5
};

enum MsoDateTimeFormat
{
    msoDateTimeFormatMixed = -2,
    msoDateTimeMdyy = 1,
    msoDateTimeddddMMMMddyyyy = 2,
    msoDateTimedMMMMyyyy = 3,
    msoDateTimeMMMMdyyyy = 4,
    msoDateTimedMMMyy = 5,
    msoDateTimeMMMMyy = 6,
    msoDateTimeMMyy = 7,
    msoDateTimeMMddyyHmm = 8,
    msoDateTimeMMddyyhmmAMPM = 9,
    msoDateTimeHmm = 10,
    msoDateTimeHmmss = 11,
    msoDateTimehmmAMPM = 12,
    msoDateTimehmmssAMPM = 13,
    msoDateTimeFigureOut = 14
};

enum MsoThemeColorSchemeIndex
{
    msoThemeDark1 = 1,
    msoThemeLight1 = 2,
    msoThemeDark2 = 3,
    msoThemeLight2 = 4,
    msoThemeAccent1 = 5,
    msoThemeAccent2 = 6,
    msoThemeAccent3 = 7,
    msoThemeAccent4 = 8,
    msoThemeAccent5 = 9,
    msoThemeAccent6 = 10,
    msoThemeHyperlink = 11,
    msoThemeFollowedHyperlink = 12
};

enum MsoThemeColorIndex
{
    msoThemeColorMixed = -2,
    msoNotThemeColor = 0,
    msoThemeColorDark1 = 1,
    msoThemeColorLight1 = 2,
    msoThemeColorDark2 = 3,
    msoThemeColorLight2 = 4,
    msoThemeColorAccent1 = 5,
    msoThemeColorAccent2 = 6,
    msoThemeColorAccent3 = 7,
    msoThemeColorAccent4 = 8,
    msoThemeColorAccent5 = 9,
    msoThemeColorAccent6 = 10,
    msoThemeColorHyperlink = 11,
    msoThemeColorFollowedHyperlink = 12,
    msoThemeColorText1 = 13,
    msoThemeColorBackground1 = 14,
    msoThemeColorText2 = 15,
    msoThemeColorBackground2 = 16
};

struct __declspec(uuid("000c0312-0000-0000-c000-000000000046"))
ColorFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_RGB (
        /*[out,retval]*/ MsoRGBType * RGB ) = 0;
      virtual HRESULT __stdcall put_RGB (
        /*[in]*/ MsoRGBType RGB ) = 0;
      virtual HRESULT __stdcall get_SchemeColor (
        /*[out,retval]*/ int * SchemeColor ) = 0;
      virtual HRESULT __stdcall put_SchemeColor (
        /*[in]*/ int SchemeColor ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoColorType * Type ) = 0;
      virtual HRESULT __stdcall get_TintAndShade (
        /*[out,retval]*/ float * pValue ) = 0;
      virtual HRESULT __stdcall put_TintAndShade (
        /*[in]*/ float pValue ) = 0;
      virtual HRESULT __stdcall get_ObjectThemeColor (
        /*[out,retval]*/ enum MsoThemeColorIndex * ObjectThemeColor ) = 0;
      virtual HRESULT __stdcall put_ObjectThemeColor (
        /*[in]*/ enum MsoThemeColorIndex ObjectThemeColor ) = 0;
      virtual HRESULT __stdcall get_Brightness (
        /*[out,retval]*/ float * Brightness ) = 0;
      virtual HRESULT __stdcall put_Brightness (
        /*[in]*/ float Brightness ) = 0;
};

struct __declspec(uuid("000c0317-0000-0000-c000-000000000046"))
LineFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_BackColor (
        /*[out,retval]*/ struct ColorFormat * * BackColor ) = 0;
      virtual HRESULT __stdcall put_BackColor (
        /*[in]*/ struct ColorFormat * BackColor ) = 0;
      virtual HRESULT __stdcall get_BeginArrowheadLength (
        /*[out,retval]*/ enum MsoArrowheadLength * BeginArrowheadLength ) = 0;
      virtual HRESULT __stdcall put_BeginArrowheadLength (
        /*[in]*/ enum MsoArrowheadLength BeginArrowheadLength ) = 0;
      virtual HRESULT __stdcall get_BeginArrowheadStyle (
        /*[out,retval]*/ enum MsoArrowheadStyle * BeginArrowheadStyle ) = 0;
      virtual HRESULT __stdcall put_BeginArrowheadStyle (
        /*[in]*/ enum MsoArrowheadStyle BeginArrowheadStyle ) = 0;
      virtual HRESULT __stdcall get_BeginArrowheadWidth (
        /*[out,retval]*/ enum MsoArrowheadWidth * BeginArrowheadWidth ) = 0;
      virtual HRESULT __stdcall put_BeginArrowheadWidth (
        /*[in]*/ enum MsoArrowheadWidth BeginArrowheadWidth ) = 0;
      virtual HRESULT __stdcall get_DashStyle (
        /*[out,retval]*/ enum MsoLineDashStyle * DashStyle ) = 0;
      virtual HRESULT __stdcall put_DashStyle (
        /*[in]*/ enum MsoLineDashStyle DashStyle ) = 0;
      virtual HRESULT __stdcall get_EndArrowheadLength (
        /*[out,retval]*/ enum MsoArrowheadLength * EndArrowheadLength ) = 0;
      virtual HRESULT __stdcall put_EndArrowheadLength (
        /*[in]*/ enum MsoArrowheadLength EndArrowheadLength ) = 0;
      virtual HRESULT __stdcall get_EndArrowheadStyle (
        /*[out,retval]*/ enum MsoArrowheadStyle * EndArrowheadStyle ) = 0;
      virtual HRESULT __stdcall put_EndArrowheadStyle (
        /*[in]*/ enum MsoArrowheadStyle EndArrowheadStyle ) = 0;
      virtual HRESULT __stdcall get_EndArrowheadWidth (
        /*[out,retval]*/ enum MsoArrowheadWidth * EndArrowheadWidth ) = 0;
      virtual HRESULT __stdcall put_EndArrowheadWidth (
        /*[in]*/ enum MsoArrowheadWidth EndArrowheadWidth ) = 0;
      virtual HRESULT __stdcall get_ForeColor (
        /*[out,retval]*/ struct ColorFormat * * ForeColor ) = 0;
      virtual HRESULT __stdcall put_ForeColor (
        /*[in]*/ struct ColorFormat * ForeColor ) = 0;
      virtual HRESULT __stdcall get_Pattern (
        /*[out,retval]*/ enum MsoPatternType * Pattern ) = 0;
      virtual HRESULT __stdcall put_Pattern (
        /*[in]*/ enum MsoPatternType Pattern ) = 0;
      virtual HRESULT __stdcall get_Style (
        /*[out,retval]*/ enum MsoLineStyle * Style ) = 0;
      virtual HRESULT __stdcall put_Style (
        /*[in]*/ enum MsoLineStyle Style ) = 0;
      virtual HRESULT __stdcall get_Transparency (
        /*[out,retval]*/ float * Transparency ) = 0;
      virtual HRESULT __stdcall put_Transparency (
        /*[in]*/ float Transparency ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_Weight (
        /*[out,retval]*/ float * Weight ) = 0;
      virtual HRESULT __stdcall put_Weight (
        /*[in]*/ float Weight ) = 0;
      virtual HRESULT __stdcall get_InsetPen (
        /*[out,retval]*/ enum MsoTriState * InsetPen ) = 0;
      virtual HRESULT __stdcall put_InsetPen (
        /*[in]*/ enum MsoTriState InsetPen ) = 0;
};

struct __declspec(uuid("000c0321-0000-0000-c000-000000000046"))
ThreeDFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall IncrementRotationX (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementRotationY (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall ResetRotation ( ) = 0;
      virtual HRESULT __stdcall SetThreeDFormat (
        /*[in]*/ enum MsoPresetThreeDFormat PresetThreeDFormat ) = 0;
      virtual HRESULT __stdcall SetExtrusionDirection (
        /*[in]*/ enum MsoPresetExtrusionDirection PresetExtrusionDirection ) = 0;
      virtual HRESULT __stdcall get_Depth (
        /*[out,retval]*/ float * Depth ) = 0;
      virtual HRESULT __stdcall put_Depth (
        /*[in]*/ float Depth ) = 0;
      virtual HRESULT __stdcall get_ExtrusionColor (
        /*[out,retval]*/ struct ColorFormat * * ExtrusionColor ) = 0;
      virtual HRESULT __stdcall get_ExtrusionColorType (
        /*[out,retval]*/ enum MsoExtrusionColorType * ExtrusionColorType ) = 0;
      virtual HRESULT __stdcall put_ExtrusionColorType (
        /*[in]*/ enum MsoExtrusionColorType ExtrusionColorType ) = 0;
      virtual HRESULT __stdcall get_Perspective (
        /*[out,retval]*/ enum MsoTriState * Perspective ) = 0;
      virtual HRESULT __stdcall put_Perspective (
        /*[in]*/ enum MsoTriState Perspective ) = 0;
      virtual HRESULT __stdcall get_PresetExtrusionDirection (
        /*[out,retval]*/ enum MsoPresetExtrusionDirection * PresetExtrusionDirection ) = 0;
      virtual HRESULT __stdcall get_PresetLightingDirection (
        /*[out,retval]*/ enum MsoPresetLightingDirection * PresetLightingDirection ) = 0;
      virtual HRESULT __stdcall put_PresetLightingDirection (
        /*[in]*/ enum MsoPresetLightingDirection PresetLightingDirection ) = 0;
      virtual HRESULT __stdcall get_PresetLightingSoftness (
        /*[out,retval]*/ enum MsoPresetLightingSoftness * PresetLightingSoftness ) = 0;
      virtual HRESULT __stdcall put_PresetLightingSoftness (
        /*[in]*/ enum MsoPresetLightingSoftness PresetLightingSoftness ) = 0;
      virtual HRESULT __stdcall get_PresetMaterial (
        /*[out,retval]*/ enum MsoPresetMaterial * PresetMaterial ) = 0;
      virtual HRESULT __stdcall put_PresetMaterial (
        /*[in]*/ enum MsoPresetMaterial PresetMaterial ) = 0;
      virtual HRESULT __stdcall get_PresetThreeDFormat (
        /*[out,retval]*/ enum MsoPresetThreeDFormat * PresetThreeDFormat ) = 0;
      virtual HRESULT __stdcall get_RotationX (
        /*[out,retval]*/ float * RotationX ) = 0;
      virtual HRESULT __stdcall put_RotationX (
        /*[in]*/ float RotationX ) = 0;
      virtual HRESULT __stdcall get_RotationY (
        /*[out,retval]*/ float * RotationY ) = 0;
      virtual HRESULT __stdcall put_RotationY (
        /*[in]*/ float RotationY ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall SetPresetCamera (
        /*[in]*/ enum MsoPresetCamera PresetCamera ) = 0;
      virtual HRESULT __stdcall IncrementRotationZ (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementRotationHorizontal (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementRotationVertical (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall get_PresetLighting (
        /*[out,retval]*/ enum MsoLightRigType * PresetLightRigType ) = 0;
      virtual HRESULT __stdcall put_PresetLighting (
        /*[in]*/ enum MsoLightRigType PresetLightRigType ) = 0;
      virtual HRESULT __stdcall get_Z (
        /*[out,retval]*/ float * Z ) = 0;
      virtual HRESULT __stdcall put_Z (
        /*[in]*/ float Z ) = 0;
      virtual HRESULT __stdcall get_BevelTopType (
        /*[out,retval]*/ enum MsoBevelType * BevelTopType ) = 0;
      virtual HRESULT __stdcall put_BevelTopType (
        /*[in]*/ enum MsoBevelType BevelTopType ) = 0;
      virtual HRESULT __stdcall get_BevelTopInset (
        /*[out,retval]*/ float * BevelTopInset ) = 0;
      virtual HRESULT __stdcall put_BevelTopInset (
        /*[in]*/ float BevelTopInset ) = 0;
      virtual HRESULT __stdcall get_BevelTopDepth (
        /*[out,retval]*/ float * BevelTopDepth ) = 0;
      virtual HRESULT __stdcall put_BevelTopDepth (
        /*[in]*/ float BevelTopDepth ) = 0;
      virtual HRESULT __stdcall get_BevelBottomType (
        /*[out,retval]*/ enum MsoBevelType * BevelBottomType ) = 0;
      virtual HRESULT __stdcall put_BevelBottomType (
        /*[in]*/ enum MsoBevelType BevelBottomType ) = 0;
      virtual HRESULT __stdcall get_BevelBottomInset (
        /*[out,retval]*/ float * BevelBottomInset ) = 0;
      virtual HRESULT __stdcall put_BevelBottomInset (
        /*[in]*/ float BevelBottomInset ) = 0;
      virtual HRESULT __stdcall get_BevelBottomDepth (
        /*[out,retval]*/ float * BevelBottomDepth ) = 0;
      virtual HRESULT __stdcall put_BevelBottomDepth (
        /*[in]*/ float BevelBottomDepth ) = 0;
      virtual HRESULT __stdcall get_PresetCamera (
        /*[out,retval]*/ enum MsoPresetCamera * PresetCamera ) = 0;
      virtual HRESULT __stdcall get_RotationZ (
        /*[out,retval]*/ float * RotationZ ) = 0;
      virtual HRESULT __stdcall put_RotationZ (
        /*[in]*/ float RotationZ ) = 0;
      virtual HRESULT __stdcall get_ContourWidth (
        /*[out,retval]*/ float * Width ) = 0;
      virtual HRESULT __stdcall put_ContourWidth (
        /*[in]*/ float Width ) = 0;
      virtual HRESULT __stdcall get_ContourColor (
        /*[out,retval]*/ struct ColorFormat * * ContourColor ) = 0;
      virtual HRESULT __stdcall get_FieldOfView (
        /*[out,retval]*/ float * FOV ) = 0;
      virtual HRESULT __stdcall put_FieldOfView (
        /*[in]*/ float FOV ) = 0;
      virtual HRESULT __stdcall get_ProjectText (
        /*[out,retval]*/ enum MsoTriState * ProjectText ) = 0;
      virtual HRESULT __stdcall put_ProjectText (
        /*[in]*/ enum MsoTriState ProjectText ) = 0;
      virtual HRESULT __stdcall get_LightAngle (
        /*[out,retval]*/ float * LightAngle ) = 0;
      virtual HRESULT __stdcall put_LightAngle (
        /*[in]*/ float LightAngle ) = 0;
};

struct __declspec(uuid("000c03bf-0000-0000-c000-000000000046"))
GradientStop : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Color (
        /*[out,retval]*/ struct ColorFormat * * Color ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ float * Position ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ float Position ) = 0;
      virtual HRESULT __stdcall get_Transparency (
        /*[out,retval]*/ float * Transparency ) = 0;
      virtual HRESULT __stdcall put_Transparency (
        /*[in]*/ float Transparency ) = 0;
};

struct __declspec(uuid("000c03c0-0000-0000-c000-000000000046"))
GradientStops : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct GradientStop * * Item ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ int Index ) = 0;
      virtual HRESULT __stdcall Insert (
        /*[in]*/ MsoRGBType RGB,
        /*[in]*/ float Position,
        /*[in]*/ float Transparency,
        /*[in]*/ int Index ) = 0;
      virtual HRESULT __stdcall Insert2 (
        /*[in]*/ MsoRGBType RGB,
        /*[in]*/ float Position,
        /*[in]*/ float Transparency,
        /*[in]*/ int Index,
        /*[in]*/ float Brightness ) = 0;
};

struct __declspec(uuid("000c03bd-0000-0000-c000-000000000046"))
GlowFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Radius (
        /*[out,retval]*/ float * Radius ) = 0;
      virtual HRESULT __stdcall put_Radius (
        /*[in]*/ float Radius ) = 0;
      virtual HRESULT __stdcall get_Color (
        /*[out,retval]*/ struct ColorFormat * * Color ) = 0;
      virtual HRESULT __stdcall get_Transparency (
        /*[out,retval]*/ float * Transparency ) = 0;
      virtual HRESULT __stdcall put_Transparency (
        /*[in]*/ float Transparency ) = 0;
};

enum MsoFontLanguageIndex
{
    msoThemeLatin = 1,
    msoThemeComplexScript = 2,
    msoThemeEastAsian = 3
};

enum MsoShapeStyleIndex
{
    msoShapeStyleMixed = -2,
    msoShapeStyleNotAPreset = 0,
    msoShapeStylePreset1 = 1,
    msoShapeStylePreset2 = 2,
    msoShapeStylePreset3 = 3,
    msoShapeStylePreset4 = 4,
    msoShapeStylePreset5 = 5,
    msoShapeStylePreset6 = 6,
    msoShapeStylePreset7 = 7,
    msoShapeStylePreset8 = 8,
    msoShapeStylePreset9 = 9,
    msoShapeStylePreset10 = 10,
    msoShapeStylePreset11 = 11,
    msoShapeStylePreset12 = 12,
    msoShapeStylePreset13 = 13,
    msoShapeStylePreset14 = 14,
    msoShapeStylePreset15 = 15,
    msoShapeStylePreset16 = 16,
    msoShapeStylePreset17 = 17,
    msoShapeStylePreset18 = 18,
    msoShapeStylePreset19 = 19,
    msoShapeStylePreset20 = 20,
    msoShapeStylePreset21 = 21,
    msoShapeStylePreset22 = 22,
    msoShapeStylePreset23 = 23,
    msoShapeStylePreset24 = 24,
    msoShapeStylePreset25 = 25,
    msoShapeStylePreset26 = 26,
    msoShapeStylePreset27 = 27,
    msoShapeStylePreset28 = 28,
    msoShapeStylePreset29 = 29,
    msoShapeStylePreset30 = 30,
    msoShapeStylePreset31 = 31,
    msoShapeStylePreset32 = 32,
    msoShapeStylePreset33 = 33,
    msoShapeStylePreset34 = 34,
    msoShapeStylePreset35 = 35,
    msoShapeStylePreset36 = 36,
    msoShapeStylePreset37 = 37,
    msoShapeStylePreset38 = 38,
    msoShapeStylePreset39 = 39,
    msoShapeStylePreset40 = 40,
    msoShapeStylePreset41 = 41,
    msoShapeStylePreset42 = 42,
    msoLineStylePreset1 = 10001,
    msoLineStylePreset2 = 10002,
    msoLineStylePreset3 = 10003,
    msoLineStylePreset4 = 10004,
    msoLineStylePreset5 = 10005,
    msoLineStylePreset6 = 10006,
    msoLineStylePreset7 = 10007,
    msoLineStylePreset8 = 10008,
    msoLineStylePreset9 = 10009,
    msoLineStylePreset10 = 10010,
    msoLineStylePreset11 = 10011,
    msoLineStylePreset12 = 10012,
    msoLineStylePreset13 = 10013,
    msoLineStylePreset14 = 10014,
    msoLineStylePreset15 = 10015,
    msoLineStylePreset16 = 10016,
    msoLineStylePreset17 = 10017,
    msoLineStylePreset18 = 10018,
    msoLineStylePreset19 = 10019,
    msoLineStylePreset20 = 10020,
    msoLineStylePreset21 = 10021
};

enum MsoBackgroundStyleIndex
{
    msoBackgroundStyleMixed = -2,
    msoBackgroundStyleNotAPreset = 0,
    msoBackgroundStylePreset1 = 1,
    msoBackgroundStylePreset2 = 2,
    msoBackgroundStylePreset3 = 3,
    msoBackgroundStylePreset4 = 4,
    msoBackgroundStylePreset5 = 5,
    msoBackgroundStylePreset6 = 6,
    msoBackgroundStylePreset7 = 7,
    msoBackgroundStylePreset8 = 8,
    msoBackgroundStylePreset9 = 9,
    msoBackgroundStylePreset10 = 10,
    msoBackgroundStylePreset11 = 11,
    msoBackgroundStylePreset12 = 12
};

struct __declspec(uuid("000c03a1-0000-0000-c000-000000000046"))
ThemeColor : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_RGB (
        /*[out,retval]*/ MsoRGBType * RGB ) = 0;
      virtual HRESULT __stdcall put_RGB (
        /*[in]*/ MsoRGBType RGB ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_ThemeColorSchemeIndex (
        /*[out,retval]*/ enum MsoThemeColorSchemeIndex * pValue ) = 0;
};

struct __declspec(uuid("000c03a2-0000-0000-c000-000000000046"))
ThemeColorScheme : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Colors (
        /*[in]*/ enum MsoThemeColorSchemeIndex Index,
        /*[out,retval]*/ struct ThemeColor * * Color ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall Load (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall Save (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall GetCustomColor (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ MsoRGBType * CustomColor ) = 0;
};

struct __declspec(uuid("000c03a3-0000-0000-c000-000000000046"))
ThemeFont : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
};

struct __declspec(uuid("000c03a4-0000-0000-c000-000000000046"))
ThemeFonts : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ enum MsoFontLanguageIndex Index,
        /*[out,retval]*/ struct ThemeFont * * Val ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
};

struct __declspec(uuid("000c03a5-0000-0000-c000-000000000046"))
ThemeFontScheme : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall Load (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall Save (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_MinorFont (
        /*[out,retval]*/ struct ThemeFonts * * MinorFont ) = 0;
      virtual HRESULT __stdcall get_MajorFont (
        /*[out,retval]*/ struct ThemeFonts * * MajorFont ) = 0;
};

struct __declspec(uuid("000c03a6-0000-0000-c000-000000000046"))
ThemeEffectScheme : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall Load (
        /*[in]*/ BSTR FileName ) = 0;
};

struct __declspec(uuid("000c03a0-0000-0000-c000-000000000046"))
OfficeTheme : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_ThemeColorScheme (
        /*[out,retval]*/ struct ThemeColorScheme * * ThemeColorScheme ) = 0;
      virtual HRESULT __stdcall get_ThemeFontScheme (
        /*[out,retval]*/ struct ThemeFontScheme * * ThemeFontScheme ) = 0;
      virtual HRESULT __stdcall get_ThemeEffectScheme (
        /*[out,retval]*/ struct ThemeEffectScheme * * ThemeEffectScheme ) = 0;
};

enum MsoCTPDockPosition
{
    msoCTPDockPositionLeft = 0,
    msoCTPDockPositionTop = 1,
    msoCTPDockPositionRight = 2,
    msoCTPDockPositionBottom = 3,
    msoCTPDockPositionFloating = 4
};

enum MsoCTPDockPositionRestrict
{
    msoCTPDockPositionRestrictNone = 0,
    msoCTPDockPositionRestrictNoChange = 1,
    msoCTPDockPositionRestrictNoHorizontal = 2,
    msoCTPDockPositionRestrictNoVertical = 3
};

struct __declspec(uuid("000c033b-0000-0000-c000-000000000046"))
_CustomTaskPane : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * prop ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * prop ) = 0;
      virtual HRESULT __stdcall get_Window (
        /*[out,retval]*/ IDispatch * * prop ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ VARIANT_BOOL * prop ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ VARIANT_BOOL prop ) = 0;
      virtual HRESULT __stdcall get_ContentControl (
        /*[out,retval]*/ IDispatch * * prop ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ int * prop ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ int prop ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ int * prop ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ int prop ) = 0;
      virtual HRESULT __stdcall get_DockPosition (
        /*[out,retval]*/ enum MsoCTPDockPosition * prop ) = 0;
      virtual HRESULT __stdcall put_DockPosition (
        /*[in]*/ enum MsoCTPDockPosition prop ) = 0;
      virtual HRESULT __stdcall get_DockPositionRestrict (
        /*[out,retval]*/ enum MsoCTPDockPositionRestrict * prop ) = 0;
      virtual HRESULT __stdcall put_DockPositionRestrict (
        /*[in]*/ enum MsoCTPDockPositionRestrict prop ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
};

struct __declspec(uuid("8a64a872-fc6b-4d4a-926e-3a3689562c1c"))
CustomTaskPaneEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual void __stdcall VisibleStateChange (
        /*[in]*/ struct _CustomTaskPane * CustomTaskPaneInst ) = 0;
      virtual void __stdcall DockPositionStateChange (
        /*[in]*/ struct _CustomTaskPane * CustomTaskPaneInst ) = 0;
};

struct __declspec(uuid("000c033c-0000-0000-c000-000000000046"))
_CustomTaskPaneEvents : IDispatch
{};

struct __declspec(uuid("c5771be5-a188-466b-ab31-00a6a32b1b1c"))
CustomTaskPane;
    // [ default ] interface _CustomTaskPane
    // [ default, source ] dispinterface _CustomTaskPaneEvents

struct __declspec(uuid("000c033d-0000-0000-c000-000000000046"))
ICTPFactory : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CreateCTP (
        /*[in]*/ BSTR CTPAxID,
        /*[in]*/ BSTR CTPTitle,
        /*[in]*/ VARIANT CTPParentWindow,
        /*[out,retval]*/ struct _CustomTaskPane * * CTPInst ) = 0;
};

struct __declspec(uuid("000c033e-0000-0000-c000-000000000046"))
ICustomTaskPaneConsumer : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CTPFactoryAvailable (
        /*[in]*/ struct ICTPFactory * CTPFactoryInst ) = 0;
};

struct __declspec(uuid("000c03a7-0000-0000-c000-000000000046"))
IRibbonUI : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Invalidate ( ) = 0;
      virtual HRESULT __stdcall InvalidateControl (
        /*[in]*/ BSTR ControlID ) = 0;
      virtual HRESULT __stdcall InvalidateControlMso (
        /*[in]*/ BSTR ControlID ) = 0;
      virtual HRESULT __stdcall ActivateTab (
        /*[in]*/ BSTR ControlID ) = 0;
      virtual HRESULT __stdcall ActivateTabMso (
        /*[in]*/ BSTR ControlID ) = 0;
      virtual HRESULT __stdcall ActivateTabQ (
        /*[in]*/ BSTR ControlID,
        /*[in]*/ BSTR Namespace ) = 0;
};

struct __declspec(uuid("000c0395-0000-0000-c000-000000000046"))
IRibbonControl : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * Id ) = 0;
      virtual HRESULT __stdcall get_Context (
        /*[out,retval]*/ IDispatch * * Context ) = 0;
      virtual HRESULT __stdcall get_Tag (
        /*[out,retval]*/ BSTR * Tag ) = 0;
};

struct __declspec(uuid("000c0396-0000-0000-c000-000000000046"))
IRibbonExtensibility : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetCustomUI (
        /*[in]*/ BSTR RibbonID,
        /*[out,retval]*/ BSTR * RibbonXml ) = 0;
};

enum RibbonControlSize
{
    RibbonControlSizeRegular = 0,
    RibbonControlSizeLarge = 1
};

enum MsoShadowStyle
{
    msoShadowStyleMixed = -2,
    msoShadowStyleInnerShadow = 1,
    msoShadowStyleOuterShadow = 2
};

struct __declspec(uuid("000c031b-0000-0000-c000-000000000046"))
ShadowFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall IncrementOffsetX (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementOffsetY (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall get_ForeColor (
        /*[out,retval]*/ struct ColorFormat * * ForeColor ) = 0;
      virtual HRESULT __stdcall put_ForeColor (
        /*[in]*/ struct ColorFormat * ForeColor ) = 0;
      virtual HRESULT __stdcall get_Obscured (
        /*[out,retval]*/ enum MsoTriState * Obscured ) = 0;
      virtual HRESULT __stdcall put_Obscured (
        /*[in]*/ enum MsoTriState Obscured ) = 0;
      virtual HRESULT __stdcall get_OffsetX (
        /*[out,retval]*/ float * OffsetX ) = 0;
      virtual HRESULT __stdcall put_OffsetX (
        /*[in]*/ float OffsetX ) = 0;
      virtual HRESULT __stdcall get_OffsetY (
        /*[out,retval]*/ float * OffsetY ) = 0;
      virtual HRESULT __stdcall put_OffsetY (
        /*[in]*/ float OffsetY ) = 0;
      virtual HRESULT __stdcall get_Transparency (
        /*[out,retval]*/ float * Transparency ) = 0;
      virtual HRESULT __stdcall put_Transparency (
        /*[in]*/ float Transparency ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoShadowType * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum MsoShadowType Type ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_Style (
        /*[out,retval]*/ enum MsoShadowStyle * ShadowStyle ) = 0;
      virtual HRESULT __stdcall put_Style (
        /*[in]*/ enum MsoShadowStyle ShadowStyle ) = 0;
      virtual HRESULT __stdcall get_Blur (
        /*[out,retval]*/ float * Blur ) = 0;
      virtual HRESULT __stdcall put_Blur (
        /*[in]*/ float Blur ) = 0;
      virtual HRESULT __stdcall get_Size (
        /*[out,retval]*/ float * Size ) = 0;
      virtual HRESULT __stdcall put_Size (
        /*[in]*/ float Size ) = 0;
      virtual HRESULT __stdcall get_RotateWithShape (
        /*[out,retval]*/ enum MsoTriState * RotateWithShape ) = 0;
      virtual HRESULT __stdcall put_RotateWithShape (
        /*[in]*/ enum MsoTriState RotateWithShape ) = 0;
};

enum MsoTextDirection
{
    msoTextDirectionMixed = -2,
    msoTextDirectionLeftToRight = 1,
    msoTextDirectionRightToLeft = 2
};

struct __declspec(uuid("000c03b2-0000-0000-c000-000000000046"))
TextColumn2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Number (
        /*[out,retval]*/ int * Number ) = 0;
      virtual HRESULT __stdcall put_Number (
        /*[in]*/ int Number ) = 0;
      virtual HRESULT __stdcall get_Spacing (
        /*[out,retval]*/ float * Spacing ) = 0;
      virtual HRESULT __stdcall put_Spacing (
        /*[in]*/ float Spacing ) = 0;
      virtual HRESULT __stdcall get_TextDirection (
        /*[out,retval]*/ enum MsoTextDirection * Direction ) = 0;
      virtual HRESULT __stdcall put_TextDirection (
        /*[in]*/ enum MsoTextDirection Direction ) = 0;
};

struct __declspec(uuid("4291224c-defe-485b-8e69-6cf8aa85cb76"))
IAssistance : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ShowHelp (
        /*[in]*/ BSTR HelpId,
        /*[in]*/ BSTR Scope ) = 0;
      virtual HRESULT __stdcall SearchHelp (
        /*[in]*/ BSTR Query,
        /*[in]*/ BSTR Scope ) = 0;
      virtual HRESULT __stdcall SetDefaultContext (
        /*[in]*/ BSTR HelpId ) = 0;
      virtual HRESULT __stdcall ClearDefaultContext (
        /*[in]*/ BSTR HelpId ) = 0;
};

enum XlChartType
{
    xlColumnClustered = 51,
    xlColumnStacked = 52,
    xlColumnStacked100 = 53,
    xl3DColumnClustered = 54,
    xl3DColumnStacked = 55,
    xl3DColumnStacked100 = 56,
    xlBarClustered = 57,
    xlBarStacked = 58,
    xlBarStacked100 = 59,
    xl3DBarClustered = 60,
    xl3DBarStacked = 61,
    xl3DBarStacked100 = 62,
    xlLineStacked = 63,
    xlLineStacked100 = 64,
    xlLineMarkers = 65,
    xlLineMarkersStacked = 66,
    xlLineMarkersStacked100 = 67,
    xlPieOfPie = 68,
    xlPieExploded = 69,
    xl3DPieExploded = 70,
    xlBarOfPie = 71,
    xlXYScatterSmooth = 72,
    xlXYScatterSmoothNoMarkers = 73,
    xlXYScatterLines = 74,
    xlXYScatterLinesNoMarkers = 75,
    xlAreaStacked = 76,
    xlAreaStacked100 = 77,
    xl3DAreaStacked = 78,
    xl3DAreaStacked100 = 79,
    xlDoughnutExploded = 80,
    xlRadarMarkers = 81,
    xlRadarFilled = 82,
    xlSurface = 83,
    xlSurfaceWireframe = 84,
    xlSurfaceTopView = 85,
    xlSurfaceTopViewWireframe = 86,
    xlBubble = 15,
    xlBubble3DEffect = 87,
    xlStockHLC = 88,
    xlStockOHLC = 89,
    xlStockVHLC = 90,
    xlStockVOHLC = 91,
    xlCylinderColClustered = 92,
    xlCylinderColStacked = 93,
    xlCylinderColStacked100 = 94,
    xlCylinderBarClustered = 95,
    xlCylinderBarStacked = 96,
    xlCylinderBarStacked100 = 97,
    xlCylinderCol = 98,
    xlConeColClustered = 99,
    xlConeColStacked = 100,
    xlConeColStacked100 = 101,
    xlConeBarClustered = 102,
    xlConeBarStacked = 103,
    xlConeBarStacked100 = 104,
    xlConeCol = 105,
    xlPyramidColClustered = 106,
    xlPyramidColStacked = 107,
    xlPyramidColStacked100 = 108,
    xlPyramidBarClustered = 109,
    xlPyramidBarStacked = 110,
    xlPyramidBarStacked100 = 111,
    xlPyramidCol = 112,
    xl3DColumn = -4100,
    xlLine = 4,
    xl3DLine = -4101,
    xl3DPie = -4102,
    xlPie = 5,
    xlXYScatter = -4169,
    xl3DArea = -4098,
    xlArea = 1,
    xlDoughnut = -4120,
    xlRadar = -4151,
    xlCombo = -4152,
    xlComboColumnClusteredLine = 113,
    xlComboColumnClusteredLineSecondaryAxis = 114,
    xlComboAreaStackedColumnClustered = 115,
    xlOtherCombinations = 116,
    xlSuggestedChart = -2
};

enum __declspec(uuid("732091cb-0a8d-44bc-b977-418ccb37b552"))
XlChartSplitType
{
    xlSplitByPosition = 1,
    xlSplitByPercentValue = 3,
    xlSplitByCustomSplit = 4,
    xlSplitByValue = 2
};

enum __declspec(uuid("8b544093-ecc1-43e3-80ef-25d6fbcc7540"))
XlSizeRepresents
{
    xlSizeIsWidth = 2,
    xlSizeIsArea = 1
};

enum __declspec(uuid("7d8d95f5-efe7-4189-8d68-0b3bccea097a"))
XlAxisGroup
{
    xlPrimary = 1,
    xlSecondary = 2
};

enum XlConstants
{
    xlAutomatic = -4105,
    xlCombination = -4111,
    xlCustom = -4114,
    xlBar = 2,
    xlColumn = 3,
    xl3DBar = -4099,
    xl3DSurface = -4103,
    xlDefaultAutoFormat = -1,
    xlNone = -4142,
    xlAbove = 0,
    xlBelow = 1,
    xlBoth = 1,
    xlBottom = -4107,
    xlCenter = -4108,
    xlChecker = 9,
    xlCircle = 8,
    xlCorner = 2,
    xlCrissCross = 16,
    xlCross = 4,
    xlDiamond = 2,
    xlDistributed = -4117,
    xlFill = 5,
    xlFixedValue = 1,
    xlGeneral = 1,
    xlGray16 = 17,
    xlGray25 = -4124,
    xlGray50 = -4125,
    xlGray75 = -4126,
    xlGray8 = 18,
    xlGrid = 15,
    xlHigh = -4127,
    xlInside = 2,
    xlJustify = -4130,
    xlLeft = -4131,
    xlLightDown = 13,
    xlLightHorizontal = 11,
    xlLightUp = 14,
    xlLightVertical = 12,
    xlLow = -4134,
    xlMaximum = 2,
    xlMinimum = 4,
    xlMinusValues = 3,
    xlNextToAxis = 4,
    xlOpaque = 3,
    xlOutside = 3,
    xlPercent = 2,
    xlPlus = 9,
    xlPlusValues = 2,
    xlRight = -4152,
    xlScale = 3,
    xlSemiGray75 = 10,
    xlShowLabel = 4,
    xlShowLabelAndPercent = 5,
    xlShowPercent = 3,
    xlShowValue = 2,
    xlSingle = 2,
    xlSolid = 1,
    xlSquare = 1,
    xlStar = 5,
    xlStError = 4,
    xlTop = -4160,
    xlTransparent = 2,
    xlTriangle = 3
};

enum XlReadingOrder
{
    xlContext = -5002,
    xlLTR = -5003,
    xlRTL = -5004
};

enum XlBorderWeight
{
    xlHairline = 1,
    xlMedium = -4138,
    xlThick = 4,
    xlThin = 2
};

enum __declspec(uuid("04d217cd-1859-4786-b583-07ba2092a552"))
XlLegendPosition
{
    xlLegendPositionBottom = -4107,
    xlLegendPositionCorner = 2,
    xlLegendPositionLeft = -4131,
    xlLegendPositionRight = -4152,
    xlLegendPositionTop = -4160,
    xlLegendPositionCustom = -4161
};

enum __declspec(uuid("9b1665ea-5ea9-4d9b-9b61-d6d1e7c087e2"))
XlUnderlineStyle
{
    xlUnderlineStyleDouble = -4119,
    xlUnderlineStyleDoubleAccounting = 5,
    xlUnderlineStyleNone = -4142,
    xlUnderlineStyleSingle = 2,
    xlUnderlineStyleSingleAccounting = 4
};

enum __declspec(uuid("f6ba0ed9-b530-466e-83d5-325653cc1068"))
XlColorIndex
{
    xlColorIndexAutomatic = -4105,
    xlColorIndexNone = -4142
};

enum __declspec(uuid("7cc8c2d6-8f8a-490b-b6f8-3c410554f9e4"))
XlMarkerStyle
{
    xlMarkerStyleAutomatic = -4105,
    xlMarkerStyleCircle = 8,
    xlMarkerStyleDash = -4115,
    xlMarkerStyleDiamond = 2,
    xlMarkerStyleDot = -4118,
    xlMarkerStyleNone = -4142,
    xlMarkerStylePicture = -4147,
    xlMarkerStylePlus = 9,
    xlMarkerStyleSquare = 1,
    xlMarkerStyleStar = 5,
    xlMarkerStyleTriangle = 3,
    xlMarkerStyleX = -4168
};

enum XlRowCol
{
    xlColumns = 2,
    xlRows = 1
};

enum XlDataLabelsType
{
    xlDataLabelsShowNone = -4142,
    xlDataLabelsShowValue = 2,
    xlDataLabelsShowPercent = 3,
    xlDataLabelsShowLabel = 4,
    xlDataLabelsShowLabelAndPercent = 5,
    xlDataLabelsShowBubbleSizes = 6
};

enum XlErrorBarInclude
{
    xlErrorBarIncludeBoth = 1,
    xlErrorBarIncludeMinusValues = 3,
    xlErrorBarIncludeNone = -4142,
    xlErrorBarIncludePlusValues = 2
};

enum XlErrorBarType
{
    xlErrorBarTypeCustom = -4114,
    xlErrorBarTypeFixedValue = 1,
    xlErrorBarTypePercent = 2,
    xlErrorBarTypeStDev = -4155,
    xlErrorBarTypeStError = 4
};

enum XlErrorBarDirection
{
    xlChartX = -4168,
    xlChartY = 1
};

enum XlChartPictureType
{
    xlStackScale = 3,
    xlStack = 2,
    xlStretch = 1
};

enum XlChartItem
{
    xlDataLabel = 0,
    xlChartArea = 2,
    xlSeries = 3,
    xlChartTitle = 4,
    xlWalls = 5,
    xlCorners = 6,
    xlDataTable = 7,
    xlTrendline = 8,
    xlErrorBars = 9,
    xlXErrorBars = 10,
    xlYErrorBars = 11,
    xlLegendEntry = 12,
    xlLegendKey = 13,
    xlShape = 14,
    xlMajorGridlines = 15,
    xlMinorGridlines = 16,
    xlAxisTitle = 17,
    xlUpBars = 18,
    xlPlotArea = 19,
    xlDownBars = 20,
    xlAxis = 21,
    xlSeriesLines = 22,
    xlFloor = 23,
    xlLegend = 24,
    xlHiLoLines = 25,
    xlDropLines = 26,
    xlRadarAxisLabels = 27,
    xlNothing = 28,
    xlLeaderLines = 29,
    xlDisplayUnitLabel = 30,
    xlPivotChartFieldButton = 31,
    xlPivotChartDropZone = 32
};

enum XlBarShape
{
    xlBox = 0,
    xlPyramidToPoint = 1,
    xlPyramidToMax = 2,
    xlCylinder = 3,
    xlConeToPoint = 4,
    xlConeToMax = 5
};

enum XlEndStyleCap
{
    xlCap = 1,
    xlNoCap = 2
};

enum XlTrendlineType
{
    xlExponential = 5,
    xlLinear = -4132,
    xlLogarithmic = -4133,
    xlMovingAvg = 6,
    xlPolynomial = 3,
    xlPower = 4
};

enum __declspec(uuid("23d8fdaa-abf3-4735-99b8-f234ea2be64c"))
XlAxisType
{
    xlCategory = 1,
    xlSeriesAxis = 3,
    xlValue = 2
};

enum __declspec(uuid("89ff0bfe-5e70-4183-88c8-5ef4b213451f"))
XlAxisCrosses
{
    xlAxisCrossesAutomatic = -4105,
    xlAxisCrossesCustom = -4114,
    xlAxisCrossesMaximum = 2,
    xlAxisCrossesMinimum = 4
};

enum __declspec(uuid("e5ead0bb-3a16-48f3-becd-5839f6b552ca"))
XlTickMark
{
    xlTickMarkCross = 4,
    xlTickMarkInside = 2,
    xlTickMarkNone = -4142,
    xlTickMarkOutside = 3
};

enum __declspec(uuid("6a0d7e5c-f9ad-4927-a850-5638891724b2"))
XlScaleType
{
    xlScaleLinear = -4132,
    xlScaleLogarithmic = -4133
};

enum __declspec(uuid("964562fd-22b1-4e15-9931-c555434e6538"))
XlTickLabelPosition
{
    xlTickLabelPositionHigh = -4127,
    xlTickLabelPositionLow = -4134,
    xlTickLabelPositionNextToAxis = 4,
    xlTickLabelPositionNone = -4142
};

enum __declspec(uuid("14710a1d-071f-4bff-b1c2-4bef5e8b2cea"))
XlTimeUnit
{
    xlDays = 0,
    xlMonths = 1,
    xlYears = 2
};

enum __declspec(uuid("78f07e6c-4bc5-41b8-8fe1-f1643184ba3f"))
XlCategoryType
{
    xlCategoryScale = 2,
    xlTimeScale = 3,
    xlAutomaticScale = -4105
};

enum __declspec(uuid("bf78d790-8dcf-4cf1-9cd4-4fceb78ebe14"))
XlDisplayUnit
{
    xlHundreds = -2,
    xlThousands = -3,
    xlTenThousands = -4,
    xlHundredThousands = -5,
    xlMillions = -6,
    xlTenMillions = -7,
    xlHundredMillions = -8,
    xlThousandMillions = -9,
    xlMillionMillions = -10,
    xlDisplayUnitCustom = -4114,
    xlDisplayUnitNone = -4142
};

enum __declspec(uuid("94e08815-49e8-45bb-9bc2-8972405756cf"))
XlChartOrientation
{
    xlDownward = -4170,
    xlHorizontal = -4128,
    xlUpward = -4171,
    xlVertical = -4166
};

enum __declspec(uuid("3a6700b4-6bc6-4848-aaa4-d360573f448c"))
XlTickLabelOrientation
{
    xlTickLabelOrientationAutomatic = -4105,
    xlTickLabelOrientationDownward = -4170,
    xlTickLabelOrientationHorizontal = -4128,
    xlTickLabelOrientationUpward = -4171,
    xlTickLabelOrientationVertical = -4166
};

enum __declspec(uuid("3439ea79-5069-4404-a6e3-8ee3a1b9bd0e"))
XlDisplayBlanksAs
{
    xlInterpolated = 3,
    xlNotPlotted = 1,
    xlZero = 2
};

enum XlDataLabelPosition
{
    xlLabelPositionCenter = -4108,
    xlLabelPositionAbove = 0,
    xlLabelPositionBelow = 1,
    xlLabelPositionLeft = -4131,
    xlLabelPositionRight = -4152,
    xlLabelPositionOutsideEnd = 2,
    xlLabelPositionInsideEnd = 3,
    xlLabelPositionInsideBase = 4,
    xlLabelPositionBestFit = 5,
    xlLabelPositionMixed = 6,
    xlLabelPositionCustom = 7
};

enum XlPivotFieldOrientation
{
    xlColumnField = 2,
    xlDataField = 4,
    xlHidden = 0,
    xlPageField = 3,
    xlRowField = 1
};

enum XlHAlign
{
    xlHAlignCenter = -4108,
    xlHAlignCenterAcrossSelection = 7,
    xlHAlignDistributed = -4117,
    xlHAlignFill = 5,
    xlHAlignGeneral = 1,
    xlHAlignJustify = -4130,
    xlHAlignLeft = -4131,
    xlHAlignRight = -4152
};

enum XlVAlign
{
    xlVAlignBottom = -4107,
    xlVAlignCenter = -4108,
    xlVAlignDistributed = -4117,
    xlVAlignJustify = -4130,
    xlVAlignTop = -4160
};

enum __declspec(uuid("05b0478c-9cd6-4f60-b113-a55e6a6cb1dc"))
XlChartElementPosition
{
    xlChartElementPositionAutomatic = -4105,
    xlChartElementPositionCustom = -4114
};

enum MsoChartElementType
{
    msoElementChartTitleNone = 0,
    msoElementChartTitleCenteredOverlay = 1,
    msoElementChartTitleAboveChart = 2,
    msoElementLegendNone = 100,
    msoElementLegendRight = 101,
    msoElementLegendTop = 102,
    msoElementLegendLeft = 103,
    msoElementLegendBottom = 104,
    msoElementLegendRightOverlay = 105,
    msoElementLegendLeftOverlay = 106,
    msoElementDataLabelNone = 200,
    msoElementDataLabelShow = 201,
    msoElementDataLabelCenter = 202,
    msoElementDataLabelInsideEnd = 203,
    msoElementDataLabelInsideBase = 204,
    msoElementDataLabelOutSideEnd = 205,
    msoElementDataLabelLeft = 206,
    msoElementDataLabelRight = 207,
    msoElementDataLabelTop = 208,
    msoElementDataLabelBottom = 209,
    msoElementDataLabelBestFit = 210,
    msoElementDataLabelCallout = 211,
    msoElementPrimaryCategoryAxisTitleNone = 300,
    msoElementPrimaryCategoryAxisTitleAdjacentToAxis = 301,
    msoElementPrimaryCategoryAxisTitleBelowAxis = 302,
    msoElementPrimaryCategoryAxisTitleRotated = 303,
    msoElementPrimaryCategoryAxisTitleVertical = 304,
    msoElementPrimaryCategoryAxisTitleHorizontal = 305,
    msoElementPrimaryValueAxisTitleNone = 306,
    msoElementPrimaryValueAxisTitleAdjacentToAxis = 306,
    msoElementPrimaryValueAxisTitleBelowAxis = 308,
    msoElementPrimaryValueAxisTitleRotated = 309,
    msoElementPrimaryValueAxisTitleVertical = 310,
    msoElementPrimaryValueAxisTitleHorizontal = 311,
    msoElementSecondaryCategoryAxisTitleNone = 312,
    msoElementSecondaryCategoryAxisTitleAdjacentToAxis = 313,
    msoElementSecondaryCategoryAxisTitleBelowAxis = 314,
    msoElementSecondaryCategoryAxisTitleRotated = 315,
    msoElementSecondaryCategoryAxisTitleVertical = 316,
    msoElementSecondaryCategoryAxisTitleHorizontal = 317,
    msoElementSecondaryValueAxisTitleNone = 318,
    msoElementSecondaryValueAxisTitleAdjacentToAxis = 319,
    msoElementSecondaryValueAxisTitleBelowAxis = 320,
    msoElementSecondaryValueAxisTitleRotated = 321,
    msoElementSecondaryValueAxisTitleVertical = 322,
    msoElementSecondaryValueAxisTitleHorizontal = 323,
    msoElementSeriesAxisTitleNone = 324,
    msoElementSeriesAxisTitleRotated = 325,
    msoElementSeriesAxisTitleVertical = 326,
    msoElementSeriesAxisTitleHorizontal = 327,
    msoElementPrimaryValueGridLinesNone = 328,
    msoElementPrimaryValueGridLinesMinor = 329,
    msoElementPrimaryValueGridLinesMajor = 330,
    msoElementPrimaryValueGridLinesMinorMajor = 331,
    msoElementPrimaryCategoryGridLinesNone = 332,
    msoElementPrimaryCategoryGridLinesMinor = 333,
    msoElementPrimaryCategoryGridLinesMajor = 334,
    msoElementPrimaryCategoryGridLinesMinorMajor = 335,
    msoElementSecondaryValueGridLinesNone = 336,
    msoElementSecondaryValueGridLinesMinor = 337,
    msoElementSecondaryValueGridLinesMajor = 338,
    msoElementSecondaryValueGridLinesMinorMajor = 339,
    msoElementSecondaryCategoryGridLinesNone = 340,
    msoElementSecondaryCategoryGridLinesMinor = 341,
    msoElementSecondaryCategoryGridLinesMajor = 342,
    msoElementSecondaryCategoryGridLinesMinorMajor = 343,
    msoElementSeriesAxisGridLinesNone = 344,
    msoElementSeriesAxisGridLinesMinor = 345,
    msoElementSeriesAxisGridLinesMajor = 346,
    msoElementSeriesAxisGridLinesMinorMajor = 347,
    msoElementPrimaryCategoryAxisNone = 348,
    msoElementPrimaryCategoryAxisShow = 349,
    msoElementPrimaryCategoryAxisWithoutLabels = 350,
    msoElementPrimaryCategoryAxisReverse = 351,
    msoElementPrimaryValueAxisNone = 352,
    msoElementPrimaryValueAxisShow = 353,
    msoElementPrimaryValueAxisThousands = 354,
    msoElementPrimaryValueAxisMillions = 355,
    msoElementPrimaryValueAxisBillions = 356,
    msoElementPrimaryValueAxisLogScale = 357,
    msoElementSecondaryCategoryAxisNone = 358,
    msoElementSecondaryCategoryAxisShow = 359,
    msoElementSecondaryCategoryAxisWithoutLabels = 360,
    msoElementSecondaryCategoryAxisReverse = 361,
    msoElementSecondaryValueAxisNone = 362,
    msoElementSecondaryValueAxisShow = 363,
    msoElementSecondaryValueAxisThousands = 364,
    msoElementSecondaryValueAxisMillions = 365,
    msoElementSecondaryValueAxisBillions = 366,
    msoElementSecondaryValueAxisLogScale = 367,
    msoElementSeriesAxisNone = 368,
    msoElementSeriesAxisShow = 369,
    msoElementSeriesAxisWithoutLabeling = 370,
    msoElementSeriesAxisReverse = 371,
    msoElementPrimaryCategoryAxisThousands = 372,
    msoElementPrimaryCategoryAxisMillions = 373,
    msoElementPrimaryCategoryAxisBillions = 374,
    msoElementPrimaryCategoryAxisLogScale = 375,
    msoElementSecondaryCategoryAxisThousands = 376,
    msoElementSecondaryCategoryAxisMillions = 377,
    msoElementSecondaryCategoryAxisBillions = 378,
    msoElementSecondaryCategoryAxisLogScale = 379,
    msoElementDataTableNone = 500,
    msoElementDataTableShow = 501,
    msoElementDataTableWithLegendKeys = 502,
    msoElementTrendlineNone = 600,
    msoElementTrendlineAddLinear = 601,
    msoElementTrendlineAddExponential = 602,
    msoElementTrendlineAddLinearForecast = 603,
    msoElementTrendlineAddTwoPeriodMovingAverage = 604,
    msoElementErrorBarNone = 700,
    msoElementErrorBarStandardError = 701,
    msoElementErrorBarPercentage = 702,
    msoElementErrorBarStandardDeviation = 703,
    msoElementLineNone = 800,
    msoElementLineDropLine = 801,
    msoElementLineHiLoLine = 802,
    msoElementLineSeriesLine = 803,
    msoElementLineDropHiLoLine = 804,
    msoElementUpDownBarsNone = 900,
    msoElementUpDownBarsShow = 901,
    msoElementPlotAreaNone = 1000,
    msoElementPlotAreaShow = 1001,
    msoElementChartWallNone = 1100,
    msoElementChartWallShow = 1101,
    msoElementChartFloorNone = 1200,
    msoElementChartFloorShow = 1201
};

struct __declspec(uuid("000c172f-0000-0000-c000-000000000046"))
IMsoChartData : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Workbook (
        /*[out,retval]*/ IDispatch * * ppdispWorkbook ) = 0;
      virtual HRESULT __stdcall Activate ( ) = 0;
      virtual HRESULT __stdcall get_IsLinked (
        /*[out,retval]*/ VARIANT_BOOL * pfIsLinked ) = 0;
      virtual HRESULT __stdcall BreakLink ( ) = 0;
      virtual HRESULT __stdcall ActivateChartDataWindow ( ) = 0;
};

struct __declspec(uuid("000c1714-0000-0000-c000-000000000046"))
IMsoCorners : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1717-0000-0000-c000-000000000046"))
IMsoBorder : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_Color (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Color (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_ColorIndex (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_ColorIndex (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_LineStyle (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_LineStyle (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Weight (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Weight (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
};

struct __declspec(uuid("000c171b-0000-0000-c000-000000000046"))
IMsoInterior : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_Color (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Color (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_ColorIndex (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_ColorIndex (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_InvertIfNegative (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_InvertIfNegative (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Pattern (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Pattern (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_PatternColor (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_PatternColor (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_PatternColorIndex (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_PatternColorIndex (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
};

struct __declspec(uuid("000c1718-0000-0000-c000-000000000046"))
ChartFont : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_Background (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Background (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Bold (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Bold (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Color (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Color (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_ColorIndex (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_ColorIndex (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_FontStyle (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_FontStyle (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Italic (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Italic (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_OutlineFont (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_OutlineFont (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Size (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Size (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_StrikeThrough (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_StrikeThrough (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Subscript (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Subscript (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Superscript (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Superscript (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_Underline (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Underline (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
};

struct __declspec(uuid("000c171d-0000-0000-c000-000000000046"))
ChartColorFormat : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_SchemeColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_SchemeColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_RGB (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_RGB (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c171c-0000-0000-c000-000000000046"))
ChartFillFormat : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall OneColorGradient (
        /*[in]*/ int Style,
        /*[in]*/ int Variant,
        /*[in]*/ float Degree ) = 0;
      virtual HRESULT __stdcall TwoColorGradient (
        /*[in]*/ int Style,
        /*[in]*/ int Variant ) = 0;
      virtual HRESULT __stdcall PresetTextured (
        /*[in]*/ int PresetTexture ) = 0;
      virtual HRESULT __stdcall Solid ( ) = 0;
      virtual HRESULT __stdcall Patterned (
        /*[in]*/ int Pattern ) = 0;
      virtual HRESULT __stdcall UserPicture (
        /*[in]*/ VARIANT PictureFile,
        /*[in]*/ VARIANT PictureFormat,
        /*[in]*/ VARIANT PictureStackUnit,
        /*[in]*/ VARIANT PicturePlacement ) = 0;
      virtual HRESULT __stdcall UserTextured (
        /*[in]*/ BSTR TextureFile ) = 0;
      virtual HRESULT __stdcall PresetGradient (
        /*[in]*/ int Style,
        /*[in]*/ int Variant,
        /*[in]*/ int PresetGradientType ) = 0;
      virtual HRESULT __stdcall get_BackColor (
        /*[out,retval]*/ struct ChartColorFormat * * pval ) = 0;
      virtual HRESULT __stdcall get_ForeColor (
        /*[out,retval]*/ struct ChartColorFormat * * pval ) = 0;
      virtual HRESULT __stdcall get_GradientColorType (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_GradientDegree (
        /*[out,retval]*/ float * pval ) = 0;
      virtual HRESULT __stdcall get_GradientStyle (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_GradientVariant (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_Pattern (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_PresetGradientType (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_PresetTexture (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_TextureName (
        /*[out,retval]*/ BSTR * pval ) = 0;
      virtual HRESULT __stdcall get_TextureType (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ int pval ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
};

struct __declspec(uuid("a98639a1-cb0c-4a5c-a511-96547f752acd"))
IMsoHyperlinks : IDispatch
{};

struct __declspec(uuid("000c1731-0000-0000-c000-000000000046"))
IMsoCharacters : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Caption (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_Caption (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * RHS ) = 0;
      virtual HRESULT __stdcall Insert (
        /*[in]*/ BSTR bstr,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_PhoneticCharacters (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_PhoneticCharacters (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

enum MsoBulletType
{
    msoBulletMixed = -2,
    msoBulletNone = 0,
    msoBulletUnnumbered = 1,
    msoBulletNumbered = 2,
    msoBulletPicture = 3
};

enum MsoNumberedBulletStyle
{
    msoBulletStyleMixed = -2,
    msoBulletAlphaLCPeriod = 0,
    msoBulletAlphaUCPeriod = 1,
    msoBulletArabicParenRight = 2,
    msoBulletArabicPeriod = 3,
    msoBulletRomanLCParenBoth = 4,
    msoBulletRomanLCParenRight = 5,
    msoBulletRomanLCPeriod = 6,
    msoBulletRomanUCPeriod = 7,
    msoBulletAlphaLCParenBoth = 8,
    msoBulletAlphaLCParenRight = 9,
    msoBulletAlphaUCParenBoth = 10,
    msoBulletAlphaUCParenRight = 11,
    msoBulletArabicParenBoth = 12,
    msoBulletArabicPlain = 13,
    msoBulletRomanUCParenBoth = 14,
    msoBulletRomanUCParenRight = 15,
    msoBulletSimpChinPlain = 16,
    msoBulletSimpChinPeriod = 17,
    msoBulletCircleNumDBPlain = 18,
    msoBulletCircleNumWDWhitePlain = 19,
    msoBulletCircleNumWDBlackPlain = 20,
    msoBulletTradChinPlain = 21,
    msoBulletTradChinPeriod = 22,
    msoBulletArabicAlphaDash = 23,
    msoBulletArabicAbjadDash = 24,
    msoBulletHebrewAlphaDash = 25,
    msoBulletKanjiKoreanPlain = 26,
    msoBulletKanjiKoreanPeriod = 27,
    msoBulletArabicDBPlain = 28,
    msoBulletArabicDBPeriod = 29,
    msoBulletThaiAlphaPeriod = 30,
    msoBulletThaiAlphaParenRight = 31,
    msoBulletThaiAlphaParenBoth = 32,
    msoBulletThaiNumPeriod = 33,
    msoBulletThaiNumParenRight = 34,
    msoBulletThaiNumParenBoth = 35,
    msoBulletHindiAlphaPeriod = 36,
    msoBulletHindiNumPeriod = 37,
    msoBulletKanjiSimpChinDBPeriod = 38,
    msoBulletHindiNumParenRight = 39,
    msoBulletHindiAlpha1Period = 40
};

enum MsoTabStopType
{
    msoTabStopMixed = -2,
    msoTabStopLeft = 1,
    msoTabStopCenter = 2,
    msoTabStopRight = 3,
    msoTabStopDecimal = 4
};

struct __declspec(uuid("000c03bb-0000-0000-c000-000000000046"))
TabStop2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall Clear ( ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ float * Position ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ float Position ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoTabStopType * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum MsoTabStopType Type ) = 0;
};

struct __declspec(uuid("000c03ba-0000-0000-c000-000000000046"))
TabStops2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct TabStop2 * * TabStop ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum MsoTabStopType Type,
        /*[in]*/ float Position,
        /*[out,retval]*/ struct TabStop2 * * TabStop ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall get_DefaultSpacing (
        /*[out,retval]*/ float * Spacing ) = 0;
      virtual HRESULT __stdcall put_DefaultSpacing (
        /*[in]*/ float Spacing ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
};

enum MsoBaselineAlignment
{
    msoBaselineAlignMixed = -2,
    msoBaselineAlignBaseline = 1,
    msoBaselineAlignTop = 2,
    msoBaselineAlignCenter = 3,
    msoBaselineAlignFarEast50 = 4,
    msoBaselineAlignAuto = 5
};

struct __declspec(uuid("000c03c3-0000-0000-c000-000000000046"))
RulerLevel2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_FirstMargin (
        /*[out,retval]*/ float * FirstMargin ) = 0;
      virtual HRESULT __stdcall put_FirstMargin (
        /*[in]*/ float FirstMargin ) = 0;
      virtual HRESULT __stdcall get_LeftMargin (
        /*[out,retval]*/ float * LeftMargin ) = 0;
      virtual HRESULT __stdcall put_LeftMargin (
        /*[in]*/ float LeftMargin ) = 0;
};

struct __declspec(uuid("000c03c2-0000-0000-c000-000000000046"))
RulerLevels2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct RulerLevel2 * * RulerLevel ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
};

struct __declspec(uuid("000c03c1-0000-0000-c000-000000000046"))
Ruler2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Levels (
        /*[out,retval]*/ struct RulerLevels2 * * RulerLevels ) = 0;
      virtual HRESULT __stdcall get_TabStops (
        /*[out,retval]*/ struct TabStops2 * * TabStops ) = 0;
};

enum EncryptionProviderDetail
{
    encprovdetUrl = 0,
    encprovdetAlgorithm = 1,
    encprovdetBlockCipher = 2,
    encprovdetCipherBlockSize = 3,
    encprovdetCipherMode = 4
};

enum EncryptionCipherMode
{
    cipherModeECB = 0,
    cipherModeCBC = 1
};

struct __declspec(uuid("000cd809-0000-0000-c000-000000000046"))
EncryptionProvider : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetProviderDetail (
        /*[in]*/ enum EncryptionProviderDetail encprovdet,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall NewSession (
        /*[in]*/ IUnknown * ParentWindow,
        /*[out,retval]*/ int * SessionHandle ) = 0;
      virtual HRESULT __stdcall Authenticate (
        /*[in]*/ IUnknown * ParentWindow,
        /*[in]*/ IUnknown * EncryptionData,
        /*[out]*/ unsigned int * PermissionsMask,
        /*[out,retval]*/ int * SessionHandle ) = 0;
      virtual HRESULT __stdcall CloneSession (
        /*[in]*/ int SessionHandle,
        /*[out,retval]*/ int * SessionHandleClone ) = 0;
      virtual HRESULT __stdcall EndSession (
        /*[in]*/ int SessionHandle ) = 0;
      virtual HRESULT __stdcall Save (
        /*[in]*/ int SessionHandle,
        /*[in]*/ IUnknown * EncryptionData,
        /*[out,retval]*/ int * EncryptionDataSize ) = 0;
      virtual HRESULT __stdcall EncryptStream (
        /*[in]*/ int SessionHandle,
        /*[in]*/ BSTR StreamName,
        /*[in]*/ IUnknown * UnencryptedStream,
        /*[in]*/ IUnknown * EncryptedStream ) = 0;
      virtual HRESULT __stdcall DecryptStream (
        /*[in]*/ int SessionHandle,
        /*[in]*/ BSTR StreamName,
        /*[in]*/ IUnknown * EncryptedStream,
        /*[in]*/ IUnknown * UnencryptedStream ) = 0;
      virtual HRESULT __stdcall ShowSettings (
        /*[in]*/ int SessionHandle,
        /*[in]*/ IUnknown * ParentWindow,
        /*[in]*/ VARIANT_BOOL ReadOnly,
        /*[out]*/ VARIANT_BOOL * Remove ) = 0;
};

enum MsoClipboardFormat
{
    msoClipboardFormatMixed = -2,
    msoClipboardFormatNative = 1,
    msoClipboardFormatHTML = 2,
    msoClipboardFormatRTF = 3,
    msoClipboardFormatPlainText = 4
};

enum MsoBlogCategorySupport
{
    msoBlogNoCategories = 0,
    msoBlogOneCategory = 1,
    msoBlogMultipleCategories = 2
};

enum MsoBlogImageType
{
    msoblogImageTypeJPEG = 1,
    msoblogImageTypeGIF = 2,
    msoblogImageTypePNG = 3
};

struct __declspec(uuid("000c03c4-0000-0000-c000-000000000046"))
IBlogExtensibility : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall BlogProviderProperties (
        /*[out]*/ BSTR * BlogProvider,
        /*[out]*/ BSTR * FriendlyName,
        /*[out]*/ enum MsoBlogCategorySupport * CategorySupport,
        /*[out]*/ VARIANT_BOOL * Padding ) = 0;
      virtual HRESULT __stdcall SetupBlogAccount (
        /*[in]*/ BSTR Account,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document,
        /*[in]*/ VARIANT_BOOL NewAccount,
        /*[out]*/ VARIANT_BOOL * ShowPictureUI ) = 0;
      virtual HRESULT __stdcall GetUserBlogs (
        /*[in]*/ BSTR Account,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document,
        /*[out]*/ SAFEARRAY * * BlogNames,
        /*[out]*/ SAFEARRAY * * BlogIDs,
        /*[out]*/ SAFEARRAY * * BlogURLs ) = 0;
      virtual HRESULT __stdcall GetRecentPosts (
        /*[in]*/ BSTR Account,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document,
        /*[out]*/ SAFEARRAY * * PostTitles,
        /*[out]*/ SAFEARRAY * * PostDates,
        /*[out]*/ SAFEARRAY * * PostIDs ) = 0;
      virtual HRESULT __stdcall Open (
        /*[in]*/ BSTR Account,
        /*[in]*/ BSTR PostID,
        /*[in]*/ long ParentWindow,
        /*[out]*/ BSTR * xHTML,
        /*[out]*/ BSTR * Title,
        /*[out]*/ BSTR * DatePosted,
        /*[out]*/ SAFEARRAY * * Categories ) = 0;
      virtual HRESULT __stdcall PublishPost (
        /*[in]*/ BSTR Account,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document,
        /*[in]*/ BSTR xHTML,
        /*[in]*/ BSTR Title,
        /*[in]*/ BSTR DateTime,
        /*[in]*/ SAFEARRAY * Categories,
        /*[in]*/ VARIANT_BOOL Draft,
        /*[out]*/ BSTR * PostID,
        /*[out]*/ BSTR * PublishMessage ) = 0;
      virtual HRESULT __stdcall RepublishPost (
        /*[in]*/ BSTR Account,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document,
        /*[in]*/ BSTR PostID,
        /*[in]*/ BSTR xHTML,
        /*[in]*/ BSTR Title,
        /*[in]*/ BSTR DateTime,
        /*[in]*/ SAFEARRAY * Categories,
        /*[in]*/ VARIANT_BOOL Draft,
        /*[out]*/ BSTR * PublishMessage ) = 0;
      virtual HRESULT __stdcall GetCategories (
        /*[in]*/ BSTR Account,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document,
        /*[out]*/ SAFEARRAY * * Categories ) = 0;
};

struct __declspec(uuid("000c03c5-0000-0000-c000-000000000046"))
IBlogPictureExtensibility : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall BlogPictureProviderProperties (
        /*[out]*/ BSTR * BlogPictureProvider,
        /*[out]*/ BSTR * FriendlyName ) = 0;
      virtual HRESULT __stdcall CreatePictureAccount (
        /*[in]*/ BSTR Account,
        /*[in]*/ BSTR BlogProvider,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document ) = 0;
      virtual HRESULT __stdcall PublishPicture (
        /*[in]*/ BSTR Account,
        /*[in]*/ long ParentWindow,
        /*[in]*/ IDispatch * Document,
        /*[in]*/ IUnknown * Image,
        /*[out]*/ BSTR * PictureURI,
        /*[in]*/ long ImageType ) = 0;
};

struct __declspec(uuid("000c03d4-0000-0000-c000-000000000046"))
IConverterPreferences : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall HrGetMacroEnabled (
        /*[out]*/ int * pfMacroEnabled ) = 0;
      virtual HRESULT __stdcall HrCheckFormat (
        /*[out]*/ int * pFormat ) = 0;
      virtual HRESULT __stdcall HrGetLossySave (
        /*[out]*/ int * pfLossySave ) = 0;
};

struct __declspec(uuid("000c03d5-0000-0000-c000-000000000046"))
IConverterApplicationPreferences : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall HrGetLcid (
        /*[out]*/ unsigned long * plcid ) = 0;
      virtual HRESULT __stdcall HrGetHwnd (
        /*[out]*/ long * phwnd ) = 0;
      virtual HRESULT __stdcall HrGetApplication (
        /*[out]*/ BSTR * pbstrApplication ) = 0;
      virtual HRESULT __stdcall HrCheckFormat (
        /*[out]*/ int * pFormat ) = 0;
};

struct __declspec(uuid("000c03d6-0000-0000-c000-000000000046"))
IConverterUICallback : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall HrReportProgress (
        /*[in]*/ unsigned int uPercentComplete ) = 0;
      virtual HRESULT __stdcall HrMessageBox (
        /*[in]*/ BSTR bstrText,
        /*[in]*/ BSTR bstrCaption,
        /*[in]*/ unsigned int uType,
        /*[out]*/ int * pidResult ) = 0;
      virtual HRESULT __stdcall HrInputBox (
        /*[in]*/ BSTR bstrText,
        /*[in]*/ BSTR bstrCaption,
        /*[out]*/ BSTR * pbstrInput,
        /*[in]*/ int fPassword ) = 0;
};

struct __declspec(uuid("000c03d7-0000-0000-c000-000000000046"))
IConverter : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall HrInitConverter (
        /*[in]*/ struct IConverterApplicationPreferences * pcap,
        /*[out]*/ struct IConverterPreferences * * ppcp,
        /*[in]*/ struct IConverterUICallback * pcuic ) = 0;
      virtual HRESULT __stdcall HrUninitConverter (
        /*[in]*/ struct IConverterUICallback * pcuic ) = 0;
      virtual HRESULT __stdcall HrImport (
        /*[in]*/ BSTR bstrSourcePath,
        /*[in]*/ BSTR bstrDestPath,
        /*[in]*/ struct IConverterApplicationPreferences * pcap,
        /*[out]*/ struct IConverterPreferences * * ppcp,
        /*[in]*/ struct IConverterUICallback * pcuic ) = 0;
      virtual HRESULT __stdcall HrExport (
        /*[in]*/ BSTR bstrSourcePath,
        /*[in]*/ BSTR bstrDestPath,
        /*[in]*/ BSTR bstrClass,
        /*[in]*/ struct IConverterApplicationPreferences * pcap,
        /*[out]*/ struct IConverterPreferences * * ppcp,
        /*[in]*/ struct IConverterUICallback * pcuic ) = 0;
      virtual HRESULT __stdcall HrGetFormat (
        /*[in]*/ BSTR bstrPath,
        /*[out]*/ BSTR * pbstrClass,
        /*[in]*/ struct IConverterApplicationPreferences * pcap,
        /*[out]*/ struct IConverterPreferences * * ppcp,
        /*[in]*/ struct IConverterUICallback * pcuic ) = 0;
      virtual HRESULT __stdcall HrGetErrorString (
        /*[in]*/ long hrErr,
        /*[out]*/ BSTR * pbstrErrorMsg,
        /*[in]*/ struct IConverterApplicationPreferences * pcap ) = 0;
};

enum __declspec(uuid("b270c821-56a3-4f6d-9274-74e6cdf4d10c"))
XlPieSliceLocation
{
    xlHorizontalCoordinate = 1,
    xlVerticalCoordinate = 2
};

enum __declspec(uuid("2b4c8ab7-6e70-422a-b7cc-206452289f16"))
XlPieSliceIndex
{
    xlOuterCounterClockwisePoint = 1,
    xlOuterCenterPoint = 2,
    xlOuterClockwisePoint = 3,
    xlMidClockwiseRadiusPoint = 4,
    xlCenterPoint = 5,
    xlMidCounterClockwiseRadiusPoint = 6,
    xlInnerClockwisePoint = 7,
    xlInnerCenterPoint = 8,
    xlInnerCounterClockwisePoint = 9
};

enum MsoSmartArtNodePosition
{
    msoSmartArtNodeDefault = 1,
    msoSmartArtNodeAfter = 2,
    msoSmartArtNodeBefore = 3,
    msoSmartArtNodeAbove = 4,
    msoSmartArtNodeBelow = 5
};

enum MsoSmartArtNodeType
{
    msoSmartArtNodeTypeDefault = 1,
    msoSmartArtNodeTypeAssistant = 2
};

struct __declspec(uuid("000c03ca-0000-0000-c000-000000000046"))
SmartArtLayout : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * LayoutId ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall get_Category (
        /*[out,retval]*/ BSTR * Category ) = 0;
};

struct __declspec(uuid("000c03c9-0000-0000-c000-000000000046"))
SmartArtLayouts : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct SmartArtLayout * * SmartArtLayout ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
};

struct __declspec(uuid("000c03cc-0000-0000-c000-000000000046"))
SmartArtQuickStyle : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * StyleId ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall get_Category (
        /*[out,retval]*/ BSTR * Category ) = 0;
};

struct __declspec(uuid("000c03cb-0000-0000-c000-000000000046"))
SmartArtQuickStyles : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct SmartArtQuickStyle * * Style ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
};

struct __declspec(uuid("000c03ce-0000-0000-c000-000000000046"))
SmartArtColor : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * ColorStyleId ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall get_Category (
        /*[out,retval]*/ BSTR * Category ) = 0;
};

struct __declspec(uuid("000c03cd-0000-0000-c000-000000000046"))
SmartArtColors : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct SmartArtColor * * SmartArtColor ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
};

enum __declspec(uuid("c4b07795-ae88-400c-af72-6f7f75a3ec0b"))
MsoPickerField
{
    msoPickerFieldUnknown = 0,
    msoPickerFieldDateTime = 1,
    msoPickerFieldNumber = 2,
    msoPickerFieldText = 3,
    msoPickerFieldUser = 4,
    msoPickerFieldMax = 5
};

struct __declspec(uuid("000c03e0-0000-0000-c000-000000000046"))
PickerField : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoPickerField * Type ) = 0;
      virtual HRESULT __stdcall get_IsHidden (
        /*[out,retval]*/ VARIANT_BOOL * IsHidden ) = 0;
};

struct __declspec(uuid("000c03e1-0000-0000-c000-000000000046"))
PickerFields : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct PickerField * * Field ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
};

struct __declspec(uuid("000c03e2-0000-0000-c000-000000000046"))
PickerProperty : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * Id ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * Value ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoPickerField * Type ) = 0;
};

struct __declspec(uuid("000c03e3-0000-0000-c000-000000000046"))
PickerProperties : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct PickerProperty * * prop ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Id,
        /*[in]*/ BSTR Value,
        /*[in]*/ enum MsoPickerField Type,
        /*[out,retval]*/ struct PickerProperty * * prop ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ BSTR Id ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
};

struct __declspec(uuid("000c03e4-0000-0000-c000-000000000046"))
PickerResult : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * Id ) = 0;
      virtual HRESULT __stdcall get_DisplayName (
        /*[out,retval]*/ BSTR * DisplayName ) = 0;
      virtual HRESULT __stdcall put_DisplayName (
        /*[in]*/ BSTR DisplayName ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ BSTR * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ BSTR Type ) = 0;
      virtual HRESULT __stdcall get_SIPId (
        /*[out,retval]*/ BSTR * SIPId ) = 0;
      virtual HRESULT __stdcall put_SIPId (
        /*[in]*/ BSTR SIPId ) = 0;
      virtual HRESULT __stdcall get_ItemData (
        /*[out,retval]*/ VARIANT * ItemData ) = 0;
      virtual HRESULT __stdcall put_ItemData (
        /*[in]*/ VARIANT ItemData ) = 0;
      virtual HRESULT __stdcall get_SubItems (
        /*[out,retval]*/ VARIANT * SubItems ) = 0;
      virtual HRESULT __stdcall put_SubItems (
        /*[in]*/ VARIANT SubItems ) = 0;
      virtual HRESULT __stdcall get_DuplicateResults (
        /*[out,retval]*/ VARIANT * DuplicateResults ) = 0;
      virtual HRESULT __stdcall get_Fields (
        /*[out,retval]*/ struct PickerFields * * Fields ) = 0;
      virtual HRESULT __stdcall put_Fields (
        /*[in]*/ struct PickerFields * Fields ) = 0;
};

struct __declspec(uuid("000c03e5-0000-0000-c000-000000000046"))
PickerResults : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct PickerResult * * Result ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR Id,
        /*[in]*/ BSTR DisplayName,
        /*[in]*/ BSTR Type,
        /*[in]*/ BSTR SIPId,
        /*[in]*/ VARIANT ItemData,
        /*[in]*/ VARIANT SubItems,
        /*[out,retval]*/ struct PickerResult * * Result ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
};

struct __declspec(uuid("000c03e6-0000-0000-c000-000000000046"))
PickerDialog : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DataHandlerId (
        /*[out,retval]*/ BSTR * Id ) = 0;
      virtual HRESULT __stdcall put_DataHandlerId (
        /*[in]*/ BSTR Id ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
      virtual HRESULT __stdcall get_Properties (
        /*[out,retval]*/ struct PickerProperties * * Props ) = 0;
      virtual HRESULT __stdcall CreatePickerResults (
        /*[out,retval]*/ struct PickerResults * * Results ) = 0;
      virtual HRESULT __stdcall Show (
        /*[in]*/ VARIANT_BOOL IsMultiSelect,
        /*[in]*/ struct PickerResults * ExistingResults,
        /*[out,retval]*/ struct PickerResults * * Results ) = 0;
      virtual HRESULT __stdcall Resolve (
        /*[in]*/ BSTR TokenText,
        /*[in]*/ int duplicateDlgMode,
        /*[out,retval]*/ struct PickerResults * * Results ) = 0;
};

enum __declspec(uuid("ec67af3b-f2df-4a52-9b85-e06a7ff28db7"))
MsoContactCardAddressType
{
    msoContactCardAddressTypeUnknown = 0,
    msoContactCardAddressTypeOutlook = 1,
    msoContactCardAddressTypeSMTP = 2,
    msoContactCardAddressTypeIM = 3
};

enum __declspec(uuid("310803cd-c69d-4371-98c9-40ce4e9bfd5a"))
MsoContactCardType
{
    msoContactCardTypeEnterpriseContact = 0,
    msoContactCardTypePersonalContact = 1,
    msoContactCardTypeUnknownContact = 2,
    msoContactCardTypeEnterpriseGroup = 3,
    msoContactCardTypePersonalDistributionList = 4
};

struct __declspec(uuid("000c03f0-0000-0000-c000-000000000046"))
IMsoContactCard : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Address (
        /*[out,retval]*/ BSTR * pAddress ) = 0;
      virtual HRESULT __stdcall get_AddressType (
        /*[out,retval]*/ enum MsoContactCardAddressType * pAddressType ) = 0;
      virtual HRESULT __stdcall get_CardType (
        /*[out,retval]*/ enum MsoContactCardType * pCardType ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
};

struct __declspec(uuid("000c03cf-0000-0000-c000-000000000046"))
EffectParameter : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * Value ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT Value ) = 0;
};

struct __declspec(uuid("000c03d0-0000-0000-c000-000000000046"))
EffectParameters : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct EffectParameter * * EffectParameter ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
};

enum MsoPictureEffectType
{
    msoEffectNone = 0,
    msoEffectBackgroundRemoval = 1,
    msoEffectBlur = 2,
    msoEffectBrightnessContrast = 3,
    msoEffectCement = 4,
    msoEffectCrisscrossEtching = 5,
    msoEffectChalkSketch = 6,
    msoEffectColorTemperature = 7,
    msoEffectCutout = 8,
    msoEffectFilmGrain = 9,
    msoEffectGlass = 10,
    msoEffectGlowDiffused = 11,
    msoEffectGlowEdges = 12,
    msoEffectLightScreen = 13,
    msoEffectLineDrawing = 14,
    msoEffectMarker = 15,
    msoEffectMosiaicBubbles = 16,
    msoEffectPaintBrush = 17,
    msoEffectPaintStrokes = 18,
    msoEffectPastelsSmooth = 19,
    msoEffectPencilGrayscale = 20,
    msoEffectPencilSketch = 21,
    msoEffectPhotocopy = 22,
    msoEffectPlasticWrap = 23,
    msoEffectSaturation = 24,
    msoEffectSharpenSoften = 25,
    msoEffectTexturizer = 26,
    msoEffectWatercolorSponge = 27
};

struct __declspec(uuid("000c03d1-0000-0000-c000-000000000046"))
PictureEffect : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoPictureEffectType * EffectType ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ int Position ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ int * Position ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_EffectParameters (
        /*[out,retval]*/ struct EffectParameters * * EffectParameters ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
};

struct __declspec(uuid("000c03d2-0000-0000-c000-000000000046"))
PictureEffects : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct PictureEffect * * Item ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Insert (
        /*[in]*/ enum MsoPictureEffectType EffectType,
        /*[in]*/ int Position,
        /*[out,retval]*/ struct PictureEffect * * Effect ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ int Index ) = 0;
};

struct __declspec(uuid("000c0314-0000-0000-c000-000000000046"))
FillFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall Background ( ) = 0;
      virtual HRESULT __stdcall OneColorGradient (
        /*[in]*/ enum MsoGradientStyle Style,
        /*[in]*/ int Variant,
        /*[in]*/ float Degree ) = 0;
      virtual HRESULT __stdcall Patterned (
        /*[in]*/ enum MsoPatternType Pattern ) = 0;
      virtual HRESULT __stdcall PresetGradient (
        /*[in]*/ enum MsoGradientStyle Style,
        /*[in]*/ int Variant,
        /*[in]*/ enum MsoPresetGradientType PresetGradientType ) = 0;
      virtual HRESULT __stdcall PresetTextured (
        /*[in]*/ enum MsoPresetTexture PresetTexture ) = 0;
      virtual HRESULT __stdcall Solid ( ) = 0;
      virtual HRESULT __stdcall TwoColorGradient (
        /*[in]*/ enum MsoGradientStyle Style,
        /*[in]*/ int Variant ) = 0;
      virtual HRESULT __stdcall UserPicture (
        /*[in]*/ BSTR PictureFile ) = 0;
      virtual HRESULT __stdcall UserTextured (
        /*[in]*/ BSTR TextureFile ) = 0;
      virtual HRESULT __stdcall get_BackColor (
        /*[out,retval]*/ struct ColorFormat * * BackColor ) = 0;
      virtual HRESULT __stdcall put_BackColor (
        /*[in]*/ struct ColorFormat * BackColor ) = 0;
      virtual HRESULT __stdcall get_ForeColor (
        /*[out,retval]*/ struct ColorFormat * * ForeColor ) = 0;
      virtual HRESULT __stdcall put_ForeColor (
        /*[in]*/ struct ColorFormat * ForeColor ) = 0;
      virtual HRESULT __stdcall get_GradientColorType (
        /*[out,retval]*/ enum MsoGradientColorType * GradientColorType ) = 0;
      virtual HRESULT __stdcall get_GradientDegree (
        /*[out,retval]*/ float * GradientDegree ) = 0;
      virtual HRESULT __stdcall get_GradientStyle (
        /*[out,retval]*/ enum MsoGradientStyle * GradientStyle ) = 0;
      virtual HRESULT __stdcall get_GradientVariant (
        /*[out,retval]*/ int * GradientVariant ) = 0;
      virtual HRESULT __stdcall get_Pattern (
        /*[out,retval]*/ enum MsoPatternType * Pattern ) = 0;
      virtual HRESULT __stdcall get_PresetGradientType (
        /*[out,retval]*/ enum MsoPresetGradientType * PresetGradientType ) = 0;
      virtual HRESULT __stdcall get_PresetTexture (
        /*[out,retval]*/ enum MsoPresetTexture * PresetTexture ) = 0;
      virtual HRESULT __stdcall get_TextureName (
        /*[out,retval]*/ BSTR * TextureName ) = 0;
      virtual HRESULT __stdcall get_TextureType (
        /*[out,retval]*/ enum MsoTextureType * TextureType ) = 0;
      virtual HRESULT __stdcall get_Transparency (
        /*[out,retval]*/ float * Transparency ) = 0;
      virtual HRESULT __stdcall put_Transparency (
        /*[in]*/ float Transparency ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoFillType * Type ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_GradientStops (
        /*[out,retval]*/ struct GradientStops * * GradientStops ) = 0;
      virtual HRESULT __stdcall get_TextureOffsetX (
        /*[out,retval]*/ float * TextureOffsetX ) = 0;
      virtual HRESULT __stdcall put_TextureOffsetX (
        /*[in]*/ float TextureOffsetX ) = 0;
      virtual HRESULT __stdcall get_TextureOffsetY (
        /*[out,retval]*/ float * TextureOffsetY ) = 0;
      virtual HRESULT __stdcall put_TextureOffsetY (
        /*[in]*/ float TextureOffsetY ) = 0;
      virtual HRESULT __stdcall get_TextureAlignment (
        /*[out,retval]*/ enum MsoTextureAlignment * TextureAlignment ) = 0;
      virtual HRESULT __stdcall put_TextureAlignment (
        /*[in]*/ enum MsoTextureAlignment TextureAlignment ) = 0;
      virtual HRESULT __stdcall get_TextureHorizontalScale (
        /*[out,retval]*/ float * HorizontalScale ) = 0;
      virtual HRESULT __stdcall put_TextureHorizontalScale (
        /*[in]*/ float HorizontalScale ) = 0;
      virtual HRESULT __stdcall get_TextureVerticalScale (
        /*[out,retval]*/ float * VerticalScale ) = 0;
      virtual HRESULT __stdcall put_TextureVerticalScale (
        /*[in]*/ float VerticalScale ) = 0;
      virtual HRESULT __stdcall get_TextureTile (
        /*[out,retval]*/ enum MsoTriState * TextureTile ) = 0;
      virtual HRESULT __stdcall put_TextureTile (
        /*[in]*/ enum MsoTriState TextureTile ) = 0;
      virtual HRESULT __stdcall get_RotateWithObject (
        /*[out,retval]*/ enum MsoTriState * RotateWithObject ) = 0;
      virtual HRESULT __stdcall put_RotateWithObject (
        /*[in]*/ enum MsoTriState RotateWithObject ) = 0;
      virtual HRESULT __stdcall get_PictureEffects (
        /*[out,retval]*/ struct PictureEffects * * PictureEffects ) = 0;
      virtual HRESULT __stdcall get_GradientAngle (
        /*[out,retval]*/ float * GradientAngle ) = 0;
      virtual HRESULT __stdcall put_GradientAngle (
        /*[in]*/ float GradientAngle ) = 0;
};

struct __declspec(uuid("000c039a-0000-0000-c000-000000000046"))
Font2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Bold (
        /*[out,retval]*/ enum MsoTriState * Bold ) = 0;
      virtual HRESULT __stdcall put_Bold (
        /*[in]*/ enum MsoTriState Bold ) = 0;
      virtual HRESULT __stdcall get_Italic (
        /*[out,retval]*/ enum MsoTriState * Italic ) = 0;
      virtual HRESULT __stdcall put_Italic (
        /*[in]*/ enum MsoTriState Italic ) = 0;
      virtual HRESULT __stdcall get_Strike (
        /*[out,retval]*/ enum MsoTextStrike * Strike ) = 0;
      virtual HRESULT __stdcall put_Strike (
        /*[in]*/ enum MsoTextStrike Strike ) = 0;
      virtual HRESULT __stdcall get_Caps (
        /*[out,retval]*/ enum MsoTextCaps * Caps ) = 0;
      virtual HRESULT __stdcall put_Caps (
        /*[in]*/ enum MsoTextCaps Caps ) = 0;
      virtual HRESULT __stdcall get_AutorotateNumbers (
        /*[out,retval]*/ enum MsoTriState * RotateNumbers ) = 0;
      virtual HRESULT __stdcall put_AutorotateNumbers (
        /*[in]*/ enum MsoTriState RotateNumbers ) = 0;
      virtual HRESULT __stdcall get_BaselineOffset (
        /*[out,retval]*/ float * Offset ) = 0;
      virtual HRESULT __stdcall put_BaselineOffset (
        /*[in]*/ float Offset ) = 0;
      virtual HRESULT __stdcall get_Kerning (
        /*[out,retval]*/ float * KerningSize ) = 0;
      virtual HRESULT __stdcall put_Kerning (
        /*[in]*/ float KerningSize ) = 0;
      virtual HRESULT __stdcall get_Size (
        /*[out,retval]*/ float * Size ) = 0;
      virtual HRESULT __stdcall put_Size (
        /*[in]*/ float Size ) = 0;
      virtual HRESULT __stdcall get_Spacing (
        /*[out,retval]*/ float * Spacing ) = 0;
      virtual HRESULT __stdcall put_Spacing (
        /*[in]*/ float Spacing ) = 0;
      virtual HRESULT __stdcall get_UnderlineStyle (
        /*[out,retval]*/ enum MsoTextUnderlineType * Style ) = 0;
      virtual HRESULT __stdcall put_UnderlineStyle (
        /*[in]*/ enum MsoTextUnderlineType Style ) = 0;
      virtual HRESULT __stdcall get_Allcaps (
        /*[out,retval]*/ enum MsoTriState * Allcaps ) = 0;
      virtual HRESULT __stdcall put_Allcaps (
        /*[in]*/ enum MsoTriState Allcaps ) = 0;
      virtual HRESULT __stdcall get_DoubleStrikeThrough (
        /*[out,retval]*/ enum MsoTriState * DoubleStrikeThrough ) = 0;
      virtual HRESULT __stdcall put_DoubleStrikeThrough (
        /*[in]*/ enum MsoTriState DoubleStrikeThrough ) = 0;
      virtual HRESULT __stdcall get_Equalize (
        /*[out,retval]*/ enum MsoTriState * Equalize ) = 0;
      virtual HRESULT __stdcall put_Equalize (
        /*[in]*/ enum MsoTriState Equalize ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct FillFormat * * Fill ) = 0;
      virtual HRESULT __stdcall get_Glow (
        /*[out,retval]*/ struct GlowFormat * * Glow ) = 0;
      virtual HRESULT __stdcall get_Reflection (
        /*[out,retval]*/ struct ReflectionFormat * * Reflection ) = 0;
      virtual HRESULT __stdcall get_Line (
        /*[out,retval]*/ struct LineFormat * * Line ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ struct ShadowFormat * * Shadow ) = 0;
      virtual HRESULT __stdcall get_Highlight (
        /*[out,retval]*/ struct ColorFormat * * Highlight ) = 0;
      virtual HRESULT __stdcall get_UnderlineColor (
        /*[out,retval]*/ struct ColorFormat * * UnderlineColor ) = 0;
      virtual HRESULT __stdcall get_Smallcaps (
        /*[out,retval]*/ enum MsoTriState * Smallcaps ) = 0;
      virtual HRESULT __stdcall put_Smallcaps (
        /*[in]*/ enum MsoTriState Smallcaps ) = 0;
      virtual HRESULT __stdcall get_SoftEdgeFormat (
        /*[out,retval]*/ enum MsoSoftEdgeType * SoftEdgeFormat ) = 0;
      virtual HRESULT __stdcall put_SoftEdgeFormat (
        /*[in]*/ enum MsoSoftEdgeType SoftEdgeFormat ) = 0;
      virtual HRESULT __stdcall get_StrikeThrough (
        /*[out,retval]*/ enum MsoTriState * StrikeThrough ) = 0;
      virtual HRESULT __stdcall put_StrikeThrough (
        /*[in]*/ enum MsoTriState StrikeThrough ) = 0;
      virtual HRESULT __stdcall get_Subscript (
        /*[out,retval]*/ enum MsoTriState * Subscript ) = 0;
      virtual HRESULT __stdcall put_Subscript (
        /*[in]*/ enum MsoTriState Subscript ) = 0;
      virtual HRESULT __stdcall get_Superscript (
        /*[out,retval]*/ enum MsoTriState * Superscript ) = 0;
      virtual HRESULT __stdcall put_Superscript (
        /*[in]*/ enum MsoTriState Superscript ) = 0;
      virtual HRESULT __stdcall get_WordArtformat (
        /*[out,retval]*/ enum MsoPresetTextEffect * WordArtformat ) = 0;
      virtual HRESULT __stdcall put_WordArtformat (
        /*[in]*/ enum MsoPresetTextEffect WordArtformat ) = 0;
      virtual HRESULT __stdcall get_Embeddable (
        /*[out,retval]*/ enum MsoTriState * Embeddable ) = 0;
      virtual HRESULT __stdcall get_Embedded (
        /*[out,retval]*/ enum MsoTriState * Embedded ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_NameAscii (
        /*[out,retval]*/ BSTR * NameAscii ) = 0;
      virtual HRESULT __stdcall put_NameAscii (
        /*[in]*/ BSTR NameAscii ) = 0;
      virtual HRESULT __stdcall get_NameComplexScript (
        /*[out,retval]*/ BSTR * NameComplexScript ) = 0;
      virtual HRESULT __stdcall put_NameComplexScript (
        /*[in]*/ BSTR NameComplexScript ) = 0;
      virtual HRESULT __stdcall get_NameFarEast (
        /*[out,retval]*/ BSTR * NameFarEast ) = 0;
      virtual HRESULT __stdcall put_NameFarEast (
        /*[in]*/ BSTR NameFarEast ) = 0;
      virtual HRESULT __stdcall get_NameOther (
        /*[out,retval]*/ BSTR * NameOther ) = 0;
      virtual HRESULT __stdcall put_NameOther (
        /*[in]*/ BSTR NameOther ) = 0;
};

struct __declspec(uuid("000c03b9-0000-0000-c000-000000000046"))
BulletFormat2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Character (
        /*[out,retval]*/ int * Character ) = 0;
      virtual HRESULT __stdcall put_Character (
        /*[in]*/ int Character ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct Font2 * * Font ) = 0;
      virtual HRESULT __stdcall get_Number (
        /*[out,retval]*/ int * Number ) = 0;
      virtual HRESULT __stdcall Picture (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_RelativeSize (
        /*[out,retval]*/ float * Size ) = 0;
      virtual HRESULT __stdcall put_RelativeSize (
        /*[in]*/ float Size ) = 0;
      virtual HRESULT __stdcall get_StartValue (
        /*[out,retval]*/ int * Start ) = 0;
      virtual HRESULT __stdcall put_StartValue (
        /*[in]*/ int Start ) = 0;
      virtual HRESULT __stdcall get_Style (
        /*[out,retval]*/ enum MsoNumberedBulletStyle * Style ) = 0;
      virtual HRESULT __stdcall put_Style (
        /*[in]*/ enum MsoNumberedBulletStyle Style ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoBulletType * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum MsoBulletType Type ) = 0;
      virtual HRESULT __stdcall get_UseTextColor (
        /*[out,retval]*/ enum MsoTriState * UseTextColor ) = 0;
      virtual HRESULT __stdcall put_UseTextColor (
        /*[in]*/ enum MsoTriState UseTextColor ) = 0;
      virtual HRESULT __stdcall get_UseTextFont (
        /*[out,retval]*/ enum MsoTriState * UseTextFont ) = 0;
      virtual HRESULT __stdcall put_UseTextFont (
        /*[in]*/ enum MsoTriState UseTextFont ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
};

struct __declspec(uuid("000c0399-0000-0000-c000-000000000046"))
ParagraphFormat2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Alignment (
        /*[out,retval]*/ enum MsoParagraphAlignment * Alignment ) = 0;
      virtual HRESULT __stdcall put_Alignment (
        /*[in]*/ enum MsoParagraphAlignment Alignment ) = 0;
      virtual HRESULT __stdcall get_BaselineAlignment (
        /*[out,retval]*/ enum MsoBaselineAlignment * BaselineAlignment ) = 0;
      virtual HRESULT __stdcall put_BaselineAlignment (
        /*[in]*/ enum MsoBaselineAlignment BaselineAlignment ) = 0;
      virtual HRESULT __stdcall get_Bullet (
        /*[out,retval]*/ struct BulletFormat2 * * Bullet ) = 0;
      virtual HRESULT __stdcall get_FarEastLineBreakLevel (
        /*[out,retval]*/ enum MsoTriState * Break ) = 0;
      virtual HRESULT __stdcall put_FarEastLineBreakLevel (
        /*[in]*/ enum MsoTriState Break ) = 0;
      virtual HRESULT __stdcall get_FirstLineIndent (
        /*[out,retval]*/ float * Indent ) = 0;
      virtual HRESULT __stdcall put_FirstLineIndent (
        /*[in]*/ float Indent ) = 0;
      virtual HRESULT __stdcall get_HangingPunctuation (
        /*[out,retval]*/ enum MsoTriState * Hanging ) = 0;
      virtual HRESULT __stdcall put_HangingPunctuation (
        /*[in]*/ enum MsoTriState Hanging ) = 0;
      virtual HRESULT __stdcall get_IndentLevel (
        /*[out,retval]*/ int * Level ) = 0;
      virtual HRESULT __stdcall put_IndentLevel (
        /*[in]*/ int Level ) = 0;
      virtual HRESULT __stdcall get_LeftIndent (
        /*[out,retval]*/ float * Indent ) = 0;
      virtual HRESULT __stdcall put_LeftIndent (
        /*[in]*/ float Indent ) = 0;
      virtual HRESULT __stdcall get_LineRuleAfter (
        /*[out,retval]*/ enum MsoTriState * LineRule ) = 0;
      virtual HRESULT __stdcall put_LineRuleAfter (
        /*[in]*/ enum MsoTriState LineRule ) = 0;
      virtual HRESULT __stdcall get_LineRuleBefore (
        /*[out,retval]*/ enum MsoTriState * LineRule ) = 0;
      virtual HRESULT __stdcall put_LineRuleBefore (
        /*[in]*/ enum MsoTriState LineRule ) = 0;
      virtual HRESULT __stdcall get_LineRuleWithin (
        /*[out,retval]*/ enum MsoTriState * LineRule ) = 0;
      virtual HRESULT __stdcall put_LineRuleWithin (
        /*[in]*/ enum MsoTriState LineRule ) = 0;
      virtual HRESULT __stdcall get_RightIndent (
        /*[out,retval]*/ float * Indent ) = 0;
      virtual HRESULT __stdcall put_RightIndent (
        /*[in]*/ float Indent ) = 0;
      virtual HRESULT __stdcall get_SpaceAfter (
        /*[out,retval]*/ float * Space ) = 0;
      virtual HRESULT __stdcall put_SpaceAfter (
        /*[in]*/ float Space ) = 0;
      virtual HRESULT __stdcall get_SpaceBefore (
        /*[out,retval]*/ float * Space ) = 0;
      virtual HRESULT __stdcall put_SpaceBefore (
        /*[in]*/ float Space ) = 0;
      virtual HRESULT __stdcall get_SpaceWithin (
        /*[out,retval]*/ float * Space ) = 0;
      virtual HRESULT __stdcall put_SpaceWithin (
        /*[in]*/ float Space ) = 0;
      virtual HRESULT __stdcall get_TabStops (
        /*[out,retval]*/ struct TabStops2 * * TabStops ) = 0;
      virtual HRESULT __stdcall get_TextDirection (
        /*[out,retval]*/ enum MsoTextDirection * Direction ) = 0;
      virtual HRESULT __stdcall put_TextDirection (
        /*[in]*/ enum MsoTextDirection Direction ) = 0;
      virtual HRESULT __stdcall get_WordWrap (
        /*[out,retval]*/ enum MsoTriState * WordWrap ) = 0;
      virtual HRESULT __stdcall put_WordWrap (
        /*[in]*/ enum MsoTriState WordWrap ) = 0;
};

struct __declspec(uuid("000c03d3-0000-0000-c000-000000000046"))
Crop : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_PictureOffsetX (
        /*[out,retval]*/ float * PictureOffsetX ) = 0;
      virtual HRESULT __stdcall put_PictureOffsetX (
        /*[in]*/ float PictureOffsetX ) = 0;
      virtual HRESULT __stdcall get_PictureOffsetY (
        /*[out,retval]*/ float * PictureOffsetY ) = 0;
      virtual HRESULT __stdcall put_PictureOffsetY (
        /*[in]*/ float PictureOffsetY ) = 0;
      virtual HRESULT __stdcall get_PictureWidth (
        /*[out,retval]*/ float * PictureWidth ) = 0;
      virtual HRESULT __stdcall put_PictureWidth (
        /*[in]*/ float PictureWidth ) = 0;
      virtual HRESULT __stdcall get_PictureHeight (
        /*[out,retval]*/ float * PictureHeight ) = 0;
      virtual HRESULT __stdcall put_PictureHeight (
        /*[in]*/ float PictureHeight ) = 0;
      virtual HRESULT __stdcall get_ShapeLeft (
        /*[out,retval]*/ float * ShapeLeft ) = 0;
      virtual HRESULT __stdcall put_ShapeLeft (
        /*[in]*/ float ShapeLeft ) = 0;
      virtual HRESULT __stdcall get_ShapeTop (
        /*[out,retval]*/ float * ShapeTop ) = 0;
      virtual HRESULT __stdcall put_ShapeTop (
        /*[in]*/ float ShapeTop ) = 0;
      virtual HRESULT __stdcall get_ShapeWidth (
        /*[out,retval]*/ float * ShapeWidth ) = 0;
      virtual HRESULT __stdcall put_ShapeWidth (
        /*[in]*/ float ShapeWidth ) = 0;
      virtual HRESULT __stdcall get_ShapeHeight (
        /*[out,retval]*/ float * ShapeHeight ) = 0;
      virtual HRESULT __stdcall put_ShapeHeight (
        /*[in]*/ float ShapeHeight ) = 0;
};

struct __declspec(uuid("000c031a-0000-0000-c000-000000000046"))
PictureFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall IncrementBrightness (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementContrast (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall get_Brightness (
        /*[out,retval]*/ float * Brightness ) = 0;
      virtual HRESULT __stdcall put_Brightness (
        /*[in]*/ float Brightness ) = 0;
      virtual HRESULT __stdcall get_ColorType (
        /*[out,retval]*/ enum MsoPictureColorType * ColorType ) = 0;
      virtual HRESULT __stdcall put_ColorType (
        /*[in]*/ enum MsoPictureColorType ColorType ) = 0;
      virtual HRESULT __stdcall get_Contrast (
        /*[out,retval]*/ float * Contrast ) = 0;
      virtual HRESULT __stdcall put_Contrast (
        /*[in]*/ float Contrast ) = 0;
      virtual HRESULT __stdcall get_CropBottom (
        /*[out,retval]*/ float * CropBottom ) = 0;
      virtual HRESULT __stdcall put_CropBottom (
        /*[in]*/ float CropBottom ) = 0;
      virtual HRESULT __stdcall get_CropLeft (
        /*[out,retval]*/ float * CropLeft ) = 0;
      virtual HRESULT __stdcall put_CropLeft (
        /*[in]*/ float CropLeft ) = 0;
      virtual HRESULT __stdcall get_CropRight (
        /*[out,retval]*/ float * CropRight ) = 0;
      virtual HRESULT __stdcall put_CropRight (
        /*[in]*/ float CropRight ) = 0;
      virtual HRESULT __stdcall get_CropTop (
        /*[out,retval]*/ float * CropTop ) = 0;
      virtual HRESULT __stdcall put_CropTop (
        /*[in]*/ float CropTop ) = 0;
      virtual HRESULT __stdcall get_TransparencyColor (
        /*[out,retval]*/ MsoRGBType * TransparencyColor ) = 0;
      virtual HRESULT __stdcall put_TransparencyColor (
        /*[in]*/ MsoRGBType TransparencyColor ) = 0;
      virtual HRESULT __stdcall get_TransparentBackground (
        /*[out,retval]*/ enum MsoTriState * TransparentBackground ) = 0;
      virtual HRESULT __stdcall put_TransparentBackground (
        /*[in]*/ enum MsoTriState TransparentBackground ) = 0;
      virtual HRESULT __stdcall get_Crop (
        /*[out,retval]*/ struct Crop * * Crop ) = 0;
};

enum __declspec(uuid("750d0562-9930-40dd-9da7-887b50f2111f"))
MsoIodGroup
{
    msoIodGroupPIAs = 0,
    msoIodGroupVSTOR35Mgd = 1,
    msoIodGroupVSTOR40Mgd = 2
};

enum BackstageGroupStyle
{
    BackstageGroupStyleNormal = 0,
    BackstageGroupStyleWarning = 1,
    BackstageGroupStyleError = 2
};

enum MsoFileValidationMode
{
    msoFileValidationDefault = 0,
    msoFileValidationSkip = 1
};

enum __declspec(uuid("0739eeef-d856-414c-9494-f2f791fd1f22"))
MsoContactCardStyle
{
    msoContactCardHover = 0,
    msoContactCardFull = 1
};

struct __declspec(uuid("000c03f1-0000-0000-c000-000000000046"))
ContactCard : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall Show (
        /*[in]*/ enum MsoContactCardStyle CardStyle,
        /*[in]*/ long RectangleLeft,
        /*[in]*/ long RectangleRight,
        /*[in]*/ long RectangleTop,
        /*[in]*/ long RectangleBottom,
        /*[in]*/ long HorizontalPosition,
        /*[in]*/ VARIANT_BOOL ShowWithDelay ) = 0;
};

enum MsoMergeCmd
{
    msoMergeUnion = 1,
    msoMergeCombine = 2,
    msoMergeIntersect = 3,
    msoMergeSubtract = 4,
    msoMergeFragment = 5
};

enum MsoLineCapStyle
{
    msoLineCapMixed = -2,
    msoLineCapSquare = 1,
    msoLineCapRound = 2,
    msoLineCapFlat = 3
};

enum MsoLineJoinStyle
{
    msoLineJoinMixed = -2,
    msoLineJoinRound = 1,
    msoLineJoinBevel = 2,
    msoLineJoinMiter = 3
};

enum MsoLineFillType
{
    msoLineFillMixed = -2,
    msoLineFillNone = 0,
    msoLineFillSolid = 1,
    msoLineFillPatterned = 2,
    msoLineFillGradient = 3,
    msoLineFillTextured = 4,
    msoLineFillBackground = 5,
    msoLineFillPicture = 6
};

enum MsoChartFieldType
{
    msoChartFieldBubbleSize = 1,
    msoChartFieldCategoryName = 2,
    msoChartFieldPercentage = 3,
    msoChartFieldSeriesName = 4,
    msoChartFieldValue = 5,
    msoChartFieldFormula = 6,
    msoChartFieldRange = 7
};

struct __declspec(uuid("000c0397-0000-0000-c000-000000000046"))
TextRange2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstrText ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstrText ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct TextRange2 * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Paragraphs (
        /*[in]*/ int Start,
        /*[in]*/ int Length,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall get_Sentences (
        /*[in]*/ int Start,
        /*[in]*/ int Length,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall get_Words (
        /*[in]*/ int Start,
        /*[in]*/ int Length,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall get_Characters (
        /*[in]*/ int Start,
        /*[in]*/ int Length,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall get_Lines (
        /*[in]*/ int Start,
        /*[in]*/ int Length,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall get_Runs (
        /*[in]*/ int Start,
        /*[in]*/ int Length,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall get_ParagraphFormat (
        /*[out,retval]*/ struct ParagraphFormat2 * * Format ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct Font2 * * Font ) = 0;
      virtual HRESULT __stdcall get_Length (
        /*[out,retval]*/ int * Length ) = 0;
      virtual HRESULT __stdcall get_Start (
        /*[out,retval]*/ int * Start ) = 0;
      virtual HRESULT __stdcall get_BoundLeft (
        /*[out,retval]*/ float * BoundLeft ) = 0;
      virtual HRESULT __stdcall get_BoundTop (
        /*[out,retval]*/ float * BoundTop ) = 0;
      virtual HRESULT __stdcall get_BoundWidth (
        /*[out,retval]*/ float * BoundWidth ) = 0;
      virtual HRESULT __stdcall get_BoundHeight (
        /*[out,retval]*/ float * BoundHeight ) = 0;
      virtual HRESULT __stdcall TrimText (
        /*[out,retval]*/ struct TextRange2 * * TrimText ) = 0;
      virtual HRESULT __stdcall InsertAfter (
        /*[in]*/ BSTR NewText,
        /*[out,retval]*/ struct TextRange2 * * TextRange ) = 0;
      virtual HRESULT __stdcall InsertBefore (
        /*[in]*/ BSTR NewText,
        /*[out,retval]*/ struct TextRange2 * * TextRange ) = 0;
      virtual HRESULT __stdcall InsertSymbol (
        /*[in]*/ BSTR FontName,
        /*[in]*/ int CharNumber,
        /*[in]*/ enum MsoTriState Unicode,
        /*[out,retval]*/ struct TextRange2 * * TextRange ) = 0;
      virtual HRESULT __stdcall Select ( ) = 0;
      virtual HRESULT __stdcall Cut ( ) = 0;
      virtual HRESULT __stdcall Copy ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Paste (
        /*[out,retval]*/ struct TextRange2 * * TextRange ) = 0;
      virtual HRESULT __stdcall PasteSpecial (
        /*[in]*/ enum MsoClipboardFormat Format,
        /*[out,retval]*/ struct TextRange2 * * TextRange ) = 0;
      virtual HRESULT __stdcall ChangeCase (
        /*[in]*/ enum MsoTextChangeCase Type ) = 0;
      virtual HRESULT __stdcall AddPeriods ( ) = 0;
      virtual HRESULT __stdcall RemovePeriods ( ) = 0;
      virtual HRESULT __stdcall Find (
        /*[in]*/ BSTR FindWhat,
        /*[in]*/ int After,
        /*[in]*/ enum MsoTriState MatchCase,
        /*[in]*/ enum MsoTriState WholeWords,
        /*[out,retval]*/ struct TextRange2 * * TextRange ) = 0;
      virtual HRESULT __stdcall Replace (
        /*[in]*/ BSTR FindWhat,
        /*[in]*/ BSTR ReplaceWhat,
        /*[in]*/ int After,
        /*[in]*/ enum MsoTriState MatchCase,
        /*[in]*/ enum MsoTriState WholeWords,
        /*[out,retval]*/ struct TextRange2 * * TextRange ) = 0;
      virtual HRESULT __stdcall RotatedBounds (
        /*[out]*/ float * X1,
        /*[out]*/ float * Y1,
        /*[out]*/ float * X2,
        /*[out]*/ float * Y2,
        /*[out]*/ float * X3,
        /*[out]*/ float * Y3,
        /*[out]*/ float * x4,
        /*[out]*/ float * y4 ) = 0;
      virtual HRESULT __stdcall get_LanguageID (
        /*[out,retval]*/ enum MsoLanguageID * LanguageID ) = 0;
      virtual HRESULT __stdcall put_LanguageID (
        /*[in]*/ enum MsoLanguageID LanguageID ) = 0;
      virtual HRESULT __stdcall RtlRun ( ) = 0;
      virtual HRESULT __stdcall LtrRun ( ) = 0;
      virtual HRESULT __stdcall get_MathZones (
        /*[in]*/ int Start,
        /*[in]*/ int Length,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall InsertChartField (
        /*[in]*/ enum MsoChartFieldType ChartFieldType,
        /*[in]*/ BSTR Formula,
        /*[in]*/ int Position,
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
};

struct __declspec(uuid("000c0398-0000-0000-c000-000000000046"))
TextFrame2 : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_MarginBottom (
        /*[out,retval]*/ float * MarginBottom ) = 0;
      virtual HRESULT __stdcall put_MarginBottom (
        /*[in]*/ float MarginBottom ) = 0;
      virtual HRESULT __stdcall get_MarginLeft (
        /*[out,retval]*/ float * MarginLeft ) = 0;
      virtual HRESULT __stdcall put_MarginLeft (
        /*[in]*/ float MarginLeft ) = 0;
      virtual HRESULT __stdcall get_MarginRight (
        /*[out,retval]*/ float * MarginRight ) = 0;
      virtual HRESULT __stdcall put_MarginRight (
        /*[in]*/ float MarginRight ) = 0;
      virtual HRESULT __stdcall get_MarginTop (
        /*[out,retval]*/ float * MarginTop ) = 0;
      virtual HRESULT __stdcall put_MarginTop (
        /*[in]*/ float MarginTop ) = 0;
      virtual HRESULT __stdcall get_Orientation (
        /*[out,retval]*/ enum MsoTextOrientation * Orientation ) = 0;
      virtual HRESULT __stdcall put_Orientation (
        /*[in]*/ enum MsoTextOrientation Orientation ) = 0;
      virtual HRESULT __stdcall get_HorizontalAnchor (
        /*[out,retval]*/ enum MsoHorizontalAnchor * HorizontalAnchor ) = 0;
      virtual HRESULT __stdcall put_HorizontalAnchor (
        /*[in]*/ enum MsoHorizontalAnchor HorizontalAnchor ) = 0;
      virtual HRESULT __stdcall get_VerticalAnchor (
        /*[out,retval]*/ enum MsoVerticalAnchor * VerticalAnchor ) = 0;
      virtual HRESULT __stdcall put_VerticalAnchor (
        /*[in]*/ enum MsoVerticalAnchor VerticalAnchor ) = 0;
      virtual HRESULT __stdcall get_PathFormat (
        /*[out,retval]*/ enum MsoPathFormat * PathFormat ) = 0;
      virtual HRESULT __stdcall put_PathFormat (
        /*[in]*/ enum MsoPathFormat PathFormat ) = 0;
      virtual HRESULT __stdcall get_WarpFormat (
        /*[out,retval]*/ enum MsoWarpFormat * WarpFormat ) = 0;
      virtual HRESULT __stdcall put_WarpFormat (
        /*[in]*/ enum MsoWarpFormat WarpFormat ) = 0;
      virtual HRESULT __stdcall get_WordArtformat (
        /*[out,retval]*/ enum MsoPresetTextEffect * WordArtformat ) = 0;
      virtual HRESULT __stdcall put_WordArtformat (
        /*[in]*/ enum MsoPresetTextEffect WordArtformat ) = 0;
      virtual HRESULT __stdcall get_WordWrap (
        /*[out,retval]*/ enum MsoTriState * WordWrap ) = 0;
      virtual HRESULT __stdcall put_WordWrap (
        /*[in]*/ enum MsoTriState WordWrap ) = 0;
      virtual HRESULT __stdcall get_AutoSize (
        /*[out,retval]*/ enum MsoAutoSize * AutoSize ) = 0;
      virtual HRESULT __stdcall put_AutoSize (
        /*[in]*/ enum MsoAutoSize AutoSize ) = 0;
      virtual HRESULT __stdcall get_ThreeD (
        /*[out,retval]*/ struct ThreeDFormat * * ThreeD ) = 0;
      virtual HRESULT __stdcall get_HasText (
        /*[out,retval]*/ enum MsoTriState * pHasText ) = 0;
      virtual HRESULT __stdcall get_TextRange (
        /*[out,retval]*/ struct TextRange2 * * Range ) = 0;
      virtual HRESULT __stdcall get_Column (
        /*[out,retval]*/ struct TextColumn2 * * Column ) = 0;
      virtual HRESULT __stdcall get_Ruler (
        /*[out,retval]*/ struct Ruler2 * * Ruler ) = 0;
      virtual HRESULT __stdcall DeleteText ( ) = 0;
      virtual HRESULT __stdcall get_NoTextRotation (
        /*[out,retval]*/ enum MsoTriState * NoTextRotation ) = 0;
      virtual HRESULT __stdcall put_NoTextRotation (
        /*[in]*/ enum MsoTriState NoTextRotation ) = 0;
};

struct __declspec(uuid("000c1730-0000-0000-c000-000000000046"))
IMsoChartFormat : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct FillFormat * * ppfill ) = 0;
      virtual HRESULT __stdcall get_Glow (
        /*[out,retval]*/ struct GlowFormat * * ppGlow ) = 0;
      virtual HRESULT __stdcall get_Line (
        /*[out,retval]*/ struct LineFormat * * ppline ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_PictureFormat (
        /*[out,retval]*/ struct PictureFormat * * ppPictureFormat ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ struct ShadowFormat * * ppShadow ) = 0;
      virtual HRESULT __stdcall get_SoftEdge (
        /*[out,retval]*/ struct SoftEdgeFormat * * ppSoftEdge ) = 0;
      virtual HRESULT __stdcall get_TextFrame2 (
        /*[out,retval]*/ struct TextFrame2 * * ppTextFrame ) = 0;
      virtual HRESULT __stdcall get_ThreeD (
        /*[out,retval]*/ struct ThreeDFormat * * ppThreeD ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Adjustments (
        /*[out,retval]*/ struct TangramAdjustments * * ppAdjustments ) = 0;
      virtual HRESULT __stdcall get_AutoShapeType (
        /*[out,retval]*/ enum MsoAutoShapeType * AutoShapeType ) = 0;
      virtual HRESULT __stdcall put_AutoShapeType (
        /*[in]*/ enum MsoAutoShapeType AutoShapeType ) = 0;
};

struct __declspec(uuid("000c1710-0000-0000-c000-000000000046"))
IMsoLegend : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * RHS ) = 0;
      virtual HRESULT __stdcall LegendEntries (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ enum XlLegendPosition * RHS ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ enum XlLegendPosition RHS ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall Clear (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * RHS ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * RHS ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_IncludeInLayout (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_IncludeInLayout (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1715-0000-0000-c000-000000000046"))
IMsoWalls : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * ppinterior ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * ppfill ) = 0;
      virtual HRESULT __stdcall get_PictureType (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_PictureType (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall Paste ( ) = 0;
      virtual HRESULT __stdcall get_PictureUnit (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_PictureUnit (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Thickness (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Thickness (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1716-0000-0000-c000-000000000046"))
IMsoFloor : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * ppinterior ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * ppfill ) = 0;
      virtual HRESULT __stdcall get_PictureType (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_PictureType (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall Paste ( ) = 0;
      virtual HRESULT __stdcall get_Thickness (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Thickness (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1724-0000-0000-c000-000000000046"))
IMsoPlotArea : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * ppinterior ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * ppfill ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_InsideLeft (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_InsideLeft (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_InsideTop (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_InsideTop (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_InsideWidth (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_InsideWidth (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_InsideHeight (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_InsideHeight (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ enum XlChartElementPosition * pval ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ enum XlChartElementPosition pval ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1728-0000-0000-c000-000000000046"))
IMsoChartArea : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall Clear (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall ClearContents (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * ppfont ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * pf ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL pf ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * ppinterior ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * ppfill ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * pd ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ double pd ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT pvar ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_RoundedCorners (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_RoundedCorners (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1729-0000-0000-c000-000000000046"))
IMsoSeriesLines : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1723-0000-0000-c000-000000000046"))
IMsoLeaderLines : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Select ( ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
};

struct __declspec(uuid("000c1725-0000-0000-c000-000000000046"))
GridLines : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c172a-0000-0000-c000-000000000046"))
IMsoUpBars : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * ppinterior ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * ppfill ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c172d-0000-0000-c000-000000000046"))
IMsoDownBars : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * bstr ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * ppinterior ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * ppfill ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c171e-0000-0000-c000-000000000046"))
IMsoLegendKey : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * RHS ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * RHS ) = 0;
      virtual HRESULT __stdcall get_InvertIfNegative (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_InvertIfNegative (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerBackgroundColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerBackgroundColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerBackgroundColorIndex (
        /*[out,retval]*/ enum XlColorIndex * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerBackgroundColorIndex (
        /*[in]*/ enum XlColorIndex RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerForegroundColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerForegroundColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerForegroundColorIndex (
        /*[out,retval]*/ enum XlColorIndex * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerForegroundColorIndex (
        /*[in]*/ enum XlColorIndex RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerSize (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerSize (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerStyle (
        /*[out,retval]*/ enum XlMarkerStyle * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerStyle (
        /*[in]*/ enum XlMarkerStyle RHS ) = 0;
      virtual HRESULT __stdcall get_PictureType (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureType (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_PictureUnit (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureUnit (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Smooth (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Smooth (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_PictureUnit2 (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureUnit2 (
        /*[in]*/ double RHS ) = 0;
};

struct __declspec(uuid("000c171a-0000-0000-c000-000000000046"))
LegendEntry : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * RHS ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall get_LegendKey (
        /*[out,retval]*/ struct IMsoLegendKey * * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1719-0000-0000-c000-000000000046"))
LegendEntries : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct LegendEntry * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct LegendEntry * * RHS ) = 0;
};

struct __declspec(uuid("000c1721-0000-0000-c000-000000000046"))
IMsoErrorBars : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_EndStyle (
        /*[out,retval]*/ enum XlEndStyleCap * RHS ) = 0;
      virtual HRESULT __stdcall put_EndStyle (
        /*[in]*/ enum XlEndStyleCap RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c170b-0000-0000-c000-000000000046"))
IMsoSeries : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall _ApplyDataLabels (
        /*[in]*/ enum XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey,
        /*[in]*/ VARIANT AutoText,
        /*[in]*/ VARIANT HasLeaderLines,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_AxisGroup (
        /*[out,retval]*/ enum XlAxisGroup * RHS ) = 0;
      virtual HRESULT __stdcall put_AxisGroup (
        /*[in]*/ enum XlAxisGroup RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall DataLabels (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall ErrorBar (
        /*[in]*/ enum XlErrorBarDirection Direction,
        /*[in]*/ enum XlErrorBarInclude Include,
        /*[in]*/ enum XlErrorBarType Type,
        /*[in]*/ VARIANT Amount,
        /*[in]*/ VARIANT MinusValues,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_ErrorBars (
        /*[out,retval]*/ struct IMsoErrorBars * * RHS ) = 0;
      virtual HRESULT __stdcall get_Explosion (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Explosion (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Formula (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_Formula (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_FormulaLocal (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_FormulaLocal (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_FormulaR1C1 (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_FormulaR1C1 (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_FormulaR1C1Local (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_FormulaR1C1Local (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_HasDataLabels (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasDataLabels (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_HasErrorBars (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasErrorBars (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * RHS ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * RHS ) = 0;
      virtual HRESULT __stdcall get_InvertIfNegative (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_InvertIfNegative (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerBackgroundColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerBackgroundColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerBackgroundColorIndex (
        /*[out,retval]*/ enum XlColorIndex * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerBackgroundColorIndex (
        /*[in]*/ enum XlColorIndex RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerForegroundColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerForegroundColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerForegroundColorIndex (
        /*[out,retval]*/ enum XlColorIndex * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerForegroundColorIndex (
        /*[in]*/ enum XlColorIndex RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerSize (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerSize (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerStyle (
        /*[out,retval]*/ enum XlMarkerStyle * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerStyle (
        /*[in]*/ enum XlMarkerStyle RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall Paste (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_PictureType (
        /*[out,retval]*/ enum XlChartPictureType * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureType (
        /*[in]*/ enum XlChartPictureType RHS ) = 0;
      virtual HRESULT __stdcall get_PictureUnit (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureUnit (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_PlotOrder (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_PlotOrder (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall Points (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Smooth (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Smooth (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall Trendlines (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_ChartType (
        /*[out,retval]*/ enum XlChartType * RHS ) = 0;
      virtual HRESULT __stdcall put_ChartType (
        /*[in]*/ enum XlChartType RHS ) = 0;
      virtual HRESULT __stdcall ApplyCustomType (
        /*[in]*/ enum XlChartType ChartType ) = 0;
      virtual HRESULT __stdcall get_Values (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_Values (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_XValues (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_XValues (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_BubbleSizes (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_BubbleSizes (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_BarShape (
        /*[out,retval]*/ enum XlBarShape * RHS ) = 0;
      virtual HRESULT __stdcall put_BarShape (
        /*[in]*/ enum XlBarShape RHS ) = 0;
      virtual HRESULT __stdcall get_ApplyPictToSides (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ApplyPictToSides (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ApplyPictToFront (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ApplyPictToFront (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ApplyPictToEnd (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ApplyPictToEnd (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Has3DEffect (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Has3DEffect (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_HasLeaderLines (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasLeaderLines (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_LeaderLines (
        /*[out,retval]*/ struct IMsoLeaderLines * * RHS ) = 0;
      virtual HRESULT __stdcall ApplyDataLabels (
        /*[in]*/ enum XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey,
        /*[in]*/ VARIANT AutoText,
        /*[in]*/ VARIANT HasLeaderLines,
        /*[in]*/ VARIANT ShowSeriesName,
        /*[in]*/ VARIANT ShowCategoryName,
        /*[in]*/ VARIANT ShowValue,
        /*[in]*/ VARIANT ShowPercentage,
        /*[in]*/ VARIANT ShowBubbleSize,
        /*[in]*/ VARIANT Separator,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_PictureUnit2 (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureUnit2 (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_PlotColorIndex (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall get_InvertColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_InvertColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_InvertColorIndex (
        /*[out,retval]*/ enum XlColorIndex * RHS ) = 0;
      virtual HRESULT __stdcall put_InvertColorIndex (
        /*[in]*/ enum XlColorIndex RHS ) = 0;
      virtual HRESULT __stdcall get_IsFiltered (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_IsFiltered (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
};

struct __declspec(uuid("000c170a-0000-0000-c000-000000000046"))
SeriesCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT Source,
        /*[in]*/ enum XlRowCol Rowcol,
        /*[in]*/ VARIANT SeriesLabels,
        /*[in]*/ VARIANT CategoryLabels,
        /*[in]*/ VARIANT Replace,
        /*[out,retval]*/ struct IMsoSeries * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Extend (
        /*[in]*/ VARIANT Source,
        /*[in]*/ VARIANT Rowcol,
        /*[in]*/ VARIANT CategoryLabels,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoSeries * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall Paste (
        /*[in]*/ enum XlRowCol Rowcol,
        /*[in]*/ VARIANT SeriesLabels,
        /*[in]*/ VARIANT CategoryLabels,
        /*[in]*/ VARIANT Replace,
        /*[in]*/ VARIANT NewSeries,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall NewSeries (
        /*[out,retval]*/ struct IMsoSeries * * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoSeries * * RHS ) = 0;
};

struct __declspec(uuid("000c1720-0000-0000-c000-000000000046"))
IMsoDataLabel : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * RHS ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * RHS ) = 0;
      virtual HRESULT __stdcall get_Caption (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_Caption (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_Characters (
        /*[in]*/ VARIANT Start,
        /*[in]*/ VARIANT Length,
        /*[out,retval]*/ struct IMsoCharacters * * RHS ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * RHS ) = 0;
      virtual HRESULT __stdcall get_HorizontalAlignment (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_HorizontalAlignment (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Orientation (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_Orientation (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_VerticalAlignment (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_VerticalAlignment (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_ReadingOrder (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_ReadingOrder (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_AutoText (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_AutoText (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_NumberFormat (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_NumberFormat (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_NumberFormatLinked (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_NumberFormatLinked (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_NumberFormatLocal (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_NumberFormatLocal (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_ShowLegendKey (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowLegendKey (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ enum XlDataLabelPosition * RHS ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ enum XlDataLabelPosition RHS ) = 0;
      virtual HRESULT __stdcall get_ShowSeriesName (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowSeriesName (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowCategoryName (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowCategoryName (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowValue (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowValue (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowPercentage (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowPercentage (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowBubbleSize (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowBubbleSize (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Separator (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_Separator (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get__Height (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Width (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_Formula (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Formula (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_FormulaR1C1 (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_FormulaR1C1 (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_FormulaLocal (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_FormulaLocal (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_FormulaR1C1Local (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_FormulaR1C1Local (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_ShowRange (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowRange (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * pHeight ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ double pHeight ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * pWidth ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ double pWidth ) = 0;
};

struct __declspec(uuid("000c170e-0000-0000-c000-000000000046"))
IMsoTrendline : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Backward (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Backward (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_DataLabel (
        /*[out,retval]*/ struct IMsoDataLabel * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_DisplayEquation (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_DisplayEquation (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_DisplayRSquared (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_DisplayRSquared (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Forward (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Forward (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall get_Intercept (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Intercept (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_InterceptIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_InterceptIsAuto (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_NameIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_NameIsAuto (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Order (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Order (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Period (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Period (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum XlTrendlineType * RHS ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum XlTrendlineType RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Backward2 (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Backward2 (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Forward2 (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_Forward2 (
        /*[in]*/ double RHS ) = 0;
};

struct __declspec(uuid("000c1722-0000-0000-c000-000000000046"))
Trendlines : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum XlTrendlineType Type,
        /*[in]*/ VARIANT Order,
        /*[in]*/ VARIANT Period,
        /*[in]*/ VARIANT Forward,
        /*[in]*/ VARIANT Backward,
        /*[in]*/ VARIANT Intercept,
        /*[in]*/ VARIANT DisplayEquation,
        /*[in]*/ VARIANT DisplayRSquared,
        /*[in]*/ VARIANT Name,
        /*[out,retval]*/ struct IMsoTrendline * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoTrendline * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoTrendline * * RHS ) = 0;
};

struct __declspec(uuid("000c171f-0000-0000-c000-000000000046"))
IMsoDataLabels : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * RHS ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * RHS ) = 0;
      virtual HRESULT __stdcall get_Characters (
        /*[in]*/ VARIANT Start,
        /*[in]*/ VARIANT Length,
        /*[out,retval]*/ struct IMsoCharacters * * RHS ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * RHS ) = 0;
      virtual HRESULT __stdcall get_HorizontalAlignment (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_HorizontalAlignment (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Orientation (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_Orientation (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_VerticalAlignment (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_VerticalAlignment (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_ReadingOrder (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_ReadingOrder (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_AutoText (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_AutoText (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_NumberFormat (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall put_NumberFormat (
        /*[in]*/ BSTR RHS ) = 0;
      virtual HRESULT __stdcall get_NumberFormatLinked (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_NumberFormatLinked (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_NumberFormatLocal (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_NumberFormatLocal (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_ShowLegendKey (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowLegendKey (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ enum XlDataLabelPosition * RHS ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ enum XlDataLabelPosition RHS ) = 0;
      virtual HRESULT __stdcall get_ShowSeriesName (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowSeriesName (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowCategoryName (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowCategoryName (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowValue (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowValue (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowPercentage (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowPercentage (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ShowBubbleSize (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowBubbleSize (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Separator (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_Separator (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoDataLabel * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoDataLabel * * RHS ) = 0;
      virtual HRESULT __stdcall Propagate (
        /*[in]*/ VARIANT Index ) = 0;
      virtual HRESULT __stdcall get_ShowRange (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ShowRange (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
};

struct __declspec(uuid("000c170c-0000-0000-c000-000000000046"))
ChartPoint : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall _ApplyDataLabels (
        /*[in]*/ enum XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey,
        /*[in]*/ VARIANT AutoText,
        /*[in]*/ VARIANT HasLeaderLines,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall ClearFormats (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_DataLabel (
        /*[out,retval]*/ struct IMsoDataLabel * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Explosion (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Explosion (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_HasDataLabel (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasDataLabel (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * RHS ) = 0;
      virtual HRESULT __stdcall get_InvertIfNegative (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_InvertIfNegative (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerBackgroundColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerBackgroundColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerBackgroundColorIndex (
        /*[out,retval]*/ enum XlColorIndex * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerBackgroundColorIndex (
        /*[in]*/ enum XlColorIndex RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerForegroundColor (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerForegroundColor (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerForegroundColorIndex (
        /*[out,retval]*/ enum XlColorIndex * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerForegroundColorIndex (
        /*[in]*/ enum XlColorIndex RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerSize (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerSize (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_MarkerStyle (
        /*[out,retval]*/ enum XlMarkerStyle * RHS ) = 0;
      virtual HRESULT __stdcall put_MarkerStyle (
        /*[in]*/ enum XlMarkerStyle RHS ) = 0;
      virtual HRESULT __stdcall Paste (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_PictureType (
        /*[out,retval]*/ enum XlChartPictureType * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureType (
        /*[in]*/ enum XlChartPictureType RHS ) = 0;
      virtual HRESULT __stdcall get_PictureUnit (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureUnit (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_ApplyPictToSides (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ApplyPictToSides (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ApplyPictToFront (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ApplyPictToFront (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ApplyPictToEnd (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_ApplyPictToEnd (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_SecondaryPlot (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_SecondaryPlot (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * RHS ) = 0;
      virtual HRESULT __stdcall ApplyDataLabels (
        /*[in]*/ enum XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey,
        /*[in]*/ VARIANT AutoText,
        /*[in]*/ VARIANT HasLeaderLines,
        /*[in]*/ VARIANT ShowSeriesName,
        /*[in]*/ VARIANT ShowCategoryName,
        /*[in]*/ VARIANT ShowValue,
        /*[in]*/ VARIANT ShowPercentage,
        /*[in]*/ VARIANT ShowBubbleSize,
        /*[in]*/ VARIANT Separator,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_Has3DEffect (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Has3DEffect (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_PictureUnit2 (
        /*[out,retval]*/ double * RHS ) = 0;
      virtual HRESULT __stdcall put_PictureUnit2 (
        /*[in]*/ double RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall PieSliceLocation (
        /*[in]*/ enum XlPieSliceLocation loc,
        /*[in]*/ enum XlPieSliceIndex Index,
        /*[out,retval]*/ double * pval ) = 0;
};

struct __declspec(uuid("000c170d-0000-0000-c000-000000000046"))
Points : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct ChartPoint * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct ChartPoint * * RHS ) = 0;
};

struct __declspec(uuid("000c1711-0000-0000-c000-000000000046"))
IMsoDataTable : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_ShowLegendKey (
        /*[in]*/ VARIANT_BOOL pfVisible ) = 0;
      virtual HRESULT __stdcall get_ShowLegendKey (
        /*[out,retval]*/ VARIANT_BOOL * pfVisible ) = 0;
      virtual HRESULT __stdcall put_HasBorderHorizontal (
        /*[in]*/ VARIANT_BOOL pfVisible ) = 0;
      virtual HRESULT __stdcall get_HasBorderHorizontal (
        /*[out,retval]*/ VARIANT_BOOL * pfVisible ) = 0;
      virtual HRESULT __stdcall put_HasBorderVertical (
        /*[in]*/ VARIANT_BOOL pfVisible ) = 0;
      virtual HRESULT __stdcall get_HasBorderVertical (
        /*[out,retval]*/ VARIANT_BOOL * pfVisible ) = 0;
      virtual HRESULT __stdcall put_HasBorderOutline (
        /*[in]*/ VARIANT_BOOL pfVisible ) = 0;
      virtual HRESULT __stdcall get_HasBorderOutline (
        /*[out,retval]*/ VARIANT_BOOL * pfVisible ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppline ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * pfont ) = 0;
      virtual HRESULT __stdcall Select ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c170f-0000-0000-c000-000000000046"))
IMsoChartTitle : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_Caption (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Caption (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Characters (
        /*[in]*/ VARIANT Start,
        /*[in]*/ VARIANT Length,
        /*[out,retval]*/ struct IMsoCharacters * * RHS ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * ppfont ) = 0;
      virtual HRESULT __stdcall put_HorizontalAlignment (
        /*[in]*/ VARIANT Val ) = 0;
      virtual HRESULT __stdcall get_HorizontalAlignment (
        /*[out,retval]*/ VARIANT * Val ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall put_Orientation (
        /*[in]*/ VARIANT Val ) = 0;
      virtual HRESULT __stdcall get_Orientation (
        /*[out,retval]*/ VARIANT * Val ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_Shadow (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall put_VerticalAlignment (
        /*[in]*/ VARIANT Val ) = 0;
      virtual HRESULT __stdcall get_VerticalAlignment (
        /*[out,retval]*/ VARIANT * Val ) = 0;
      virtual HRESULT __stdcall get_ReadingOrder (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall put_ReadingOrder (
        /*[in]*/ int pval ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT Val ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * Val ) = 0;
      virtual HRESULT __stdcall get_Interior (
        /*[out,retval]*/ struct IMsoInterior * * ppinterior ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct ChartFillFormat * * ppinterior ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_IncludeInLayout (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_IncludeInLayout (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ enum XlChartElementPosition * pval ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ enum XlChartElementPosition pval ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppval ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_Formula (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_Formula (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_FormulaR1C1 (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_FormulaR1C1 (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_FormulaLocal (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_FormulaLocal (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall put_FormulaR1C1Local (
        /*[in]*/ BSTR pbstr ) = 0;
      virtual HRESULT __stdcall get_FormulaR1C1Local (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
};

struct __declspec(uuid("abfa087c-f703-4d53-946e-37ff82b2c994"))
IMsoAxisTitle : IMsoChartTitle
{};

struct __declspec(uuid("6ea00553-9439-4d5a-b1e6-dc15a54da8b2"))
IMsoDisplayUnitLabel : IMsoChartTitle
{};

struct __declspec(uuid("000c1726-0000-0000-c000-000000000046"))
IMsoTickLabels : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_Font (
        /*[out,retval]*/ struct ChartFont * * ppval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pval ) = 0;
      virtual HRESULT __stdcall get_NumberFormat (
        /*[out,retval]*/ BSTR * pval ) = 0;
      virtual HRESULT __stdcall put_NumberFormat (
        /*[in]*/ BSTR pval ) = 0;
      virtual HRESULT __stdcall get_NumberFormatLinked (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_NumberFormatLinked (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_NumberFormatLocal (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_NumberFormatLocal (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Orientation (
        /*[out,retval]*/ enum XlTickLabelOrientation * pval ) = 0;
      virtual HRESULT __stdcall put_Orientation (
        /*[in]*/ enum XlTickLabelOrientation pval ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_ReadingOrder (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall put_ReadingOrder (
        /*[in]*/ int pval ) = 0;
      virtual HRESULT __stdcall get_AutoScaleFont (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_AutoScaleFont (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Depth (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall get_Offset (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall put_Offset (
        /*[in]*/ int pval ) = 0;
      virtual HRESULT __stdcall get_Alignment (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall put_Alignment (
        /*[in]*/ int pval ) = 0;
      virtual HRESULT __stdcall get_MultiLevel (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_MultiLevel (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1713-0000-0000-c000-000000000046"))
IMsoAxis : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_AxisBetweenCategories (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_AxisBetweenCategories (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_AxisGroup (
        /*[out,retval]*/ enum XlAxisGroup * pval ) = 0;
      virtual HRESULT __stdcall get_AxisTitle (
        /*[out,retval]*/ struct IMsoAxisTitle * * pval ) = 0;
      virtual HRESULT __stdcall get_CategoryNames (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall put_CategoryNames (
        /*[in]*/ VARIANT pval ) = 0;
      virtual HRESULT __stdcall get_Crosses (
        /*[out,retval]*/ enum XlAxisCrosses * pval ) = 0;
      virtual HRESULT __stdcall put_Crosses (
        /*[in]*/ enum XlAxisCrosses pval ) = 0;
      virtual HRESULT __stdcall get_CrossesAt (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_CrossesAt (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_HasMajorGridlines (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_HasMajorGridlines (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_HasMinorGridlines (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_HasMinorGridlines (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_HasTitle (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_HasTitle (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_MajorGridlines (
        /*[out,retval]*/ struct GridLines * * ppval ) = 0;
      virtual HRESULT __stdcall get_MajorTickMark (
        /*[out,retval]*/ enum XlTickMark * pval ) = 0;
      virtual HRESULT __stdcall put_MajorTickMark (
        /*[in]*/ enum XlTickMark pval ) = 0;
      virtual HRESULT __stdcall get_MajorUnit (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_MajorUnit (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall get_LogBase (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_LogBase (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall get_TickLabelSpacingIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_TickLabelSpacingIsAuto (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_MajorUnitIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_MajorUnitIsAuto (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_MaximumScale (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_MaximumScale (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall get_MaximumScaleIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_MaximumScaleIsAuto (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_MinimumScale (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_MinimumScale (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall get_MinimumScaleIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_MinimumScaleIsAuto (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_MinorGridlines (
        /*[out,retval]*/ struct GridLines * * ppval ) = 0;
      virtual HRESULT __stdcall get_MinorTickMark (
        /*[out,retval]*/ enum XlTickMark * pval ) = 0;
      virtual HRESULT __stdcall put_MinorTickMark (
        /*[in]*/ enum XlTickMark pval ) = 0;
      virtual HRESULT __stdcall get_MinorUnit (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_MinorUnit (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall get_MinorUnitIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_MinorUnitIsAuto (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_ReversePlotOrder (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_ReversePlotOrder (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_ScaleType (
        /*[out,retval]*/ enum XlScaleType * pval ) = 0;
      virtual HRESULT __stdcall put_ScaleType (
        /*[in]*/ enum XlScaleType pval ) = 0;
      virtual HRESULT __stdcall Select (
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_TickLabelPosition (
        /*[out,retval]*/ enum XlTickLabelPosition * pval ) = 0;
      virtual HRESULT __stdcall put_TickLabelPosition (
        /*[in]*/ enum XlTickLabelPosition pval ) = 0;
      virtual HRESULT __stdcall get_TickLabels (
        /*[out,retval]*/ struct IMsoTickLabels * * pval ) = 0;
      virtual HRESULT __stdcall get_TickLabelSpacing (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall put_TickLabelSpacing (
        /*[in]*/ int pval ) = 0;
      virtual HRESULT __stdcall get_TickMarkSpacing (
        /*[out,retval]*/ int * pval ) = 0;
      virtual HRESULT __stdcall put_TickMarkSpacing (
        /*[in]*/ int pval ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum XlAxisType * pval ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum XlAxisType pval ) = 0;
      virtual HRESULT __stdcall get_BaseUnit (
        /*[out,retval]*/ enum XlTimeUnit * pval ) = 0;
      virtual HRESULT __stdcall put_BaseUnit (
        /*[in]*/ enum XlTimeUnit pval ) = 0;
      virtual HRESULT __stdcall get_BaseUnitIsAuto (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_BaseUnitIsAuto (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_MajorUnitScale (
        /*[out,retval]*/ enum XlTimeUnit * pval ) = 0;
      virtual HRESULT __stdcall put_MajorUnitScale (
        /*[in]*/ enum XlTimeUnit pval ) = 0;
      virtual HRESULT __stdcall get_MinorUnitScale (
        /*[out,retval]*/ enum XlTimeUnit * pval ) = 0;
      virtual HRESULT __stdcall put_MinorUnitScale (
        /*[in]*/ enum XlTimeUnit pval ) = 0;
      virtual HRESULT __stdcall get_CategoryType (
        /*[out,retval]*/ enum XlCategoryType * pval ) = 0;
      virtual HRESULT __stdcall put_CategoryType (
        /*[in]*/ enum XlCategoryType pval ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall get_DisplayUnit (
        /*[out,retval]*/ enum XlDisplayUnit * pval ) = 0;
      virtual HRESULT __stdcall put_DisplayUnit (
        /*[in]*/ enum XlDisplayUnit pval ) = 0;
      virtual HRESULT __stdcall get_DisplayUnitCustom (
        /*[out,retval]*/ double * pval ) = 0;
      virtual HRESULT __stdcall put_DisplayUnitCustom (
        /*[in]*/ double pval ) = 0;
      virtual HRESULT __stdcall get_HasDisplayUnitLabel (
        /*[out,retval]*/ VARIANT_BOOL * pval ) = 0;
      virtual HRESULT __stdcall put_HasDisplayUnitLabel (
        /*[in]*/ VARIANT_BOOL pval ) = 0;
      virtual HRESULT __stdcall get_DisplayUnitLabel (
        /*[out,retval]*/ struct IMsoDisplayUnitLabel * * pval ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * ppborder ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
};

struct __declspec(uuid("000c1712-0000-0000-c000-000000000046"))
Axes : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ enum XlAxisType Type,
        /*[in]*/ enum XlAxisGroup AxisGroup,
        /*[out,retval]*/ struct IMsoAxis * * RHS ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * pval ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ enum XlAxisType Type,
        /*[in]*/ enum XlAxisGroup AxisGroup,
        /*[out,retval]*/ struct IMsoAxis * * RHS ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
};

struct __declspec(uuid("000c172c-0000-0000-c000-000000000046"))
IMsoDropLines : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall Select ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c172e-0000-0000-c000-000000000046"))
IMsoHiLoLines : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * RHS ) = 0;
      virtual HRESULT __stdcall Select ( ) = 0;
      virtual HRESULT __stdcall get_Border (
        /*[out,retval]*/ struct IMsoBorder * * RHS ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

struct __declspec(uuid("000c1727-0000-0000-c000-000000000046"))
IMsoChartGroup : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_AxisGroup (
        /*[in]*/ int piGroup ) = 0;
      virtual HRESULT __stdcall get_AxisGroup (
        /*[out,retval]*/ int * piGroup ) = 0;
      virtual HRESULT __stdcall put_DoughnutHoleSize (
        /*[in]*/ int pDoughnutHoleSize ) = 0;
      virtual HRESULT __stdcall get_DoughnutHoleSize (
        /*[out,retval]*/ int * pDoughnutHoleSize ) = 0;
      virtual HRESULT __stdcall get_DownBars (
        /*[out,retval]*/ struct IMsoDownBars * * ppdownbars ) = 0;
      virtual HRESULT __stdcall get_DropLines (
        /*[out,retval]*/ struct IMsoDropLines * * ppdroplines ) = 0;
      virtual HRESULT __stdcall put_FirstSliceAngle (
        /*[in]*/ int pFirstSliceAngle ) = 0;
      virtual HRESULT __stdcall get_FirstSliceAngle (
        /*[out,retval]*/ int * pFirstSliceAngle ) = 0;
      virtual HRESULT __stdcall put_GapWidth (
        /*[in]*/ int pGapWidth ) = 0;
      virtual HRESULT __stdcall get_GapWidth (
        /*[out,retval]*/ int * pGapWidth ) = 0;
      virtual HRESULT __stdcall put_HasDropLines (
        /*[in]*/ VARIANT_BOOL pfHasDropLines ) = 0;
      virtual HRESULT __stdcall get_HasDropLines (
        /*[out,retval]*/ VARIANT_BOOL * pfHasDropLines ) = 0;
      virtual HRESULT __stdcall put_HasHiLoLines (
        /*[in]*/ VARIANT_BOOL pfHasHiLoLines ) = 0;
      virtual HRESULT __stdcall get_HasHiLoLines (
        /*[out,retval]*/ VARIANT_BOOL * pfHasHiLoLines ) = 0;
      virtual HRESULT __stdcall put_HasRadarAxisLabels (
        /*[in]*/ VARIANT_BOOL pfHasRadarAxisLabels ) = 0;
      virtual HRESULT __stdcall get_HasRadarAxisLabels (
        /*[out,retval]*/ VARIANT_BOOL * pfHasRadarAxisLabels ) = 0;
      virtual HRESULT __stdcall put_HasSeriesLines (
        /*[in]*/ VARIANT_BOOL pfHasSeriesLines ) = 0;
      virtual HRESULT __stdcall get_HasSeriesLines (
        /*[out,retval]*/ VARIANT_BOOL * pfHasSeriesLines ) = 0;
      virtual HRESULT __stdcall put_HasUpDownBars (
        /*[in]*/ VARIANT_BOOL pfHasUpDownBars ) = 0;
      virtual HRESULT __stdcall get_HasUpDownBars (
        /*[out,retval]*/ VARIANT_BOOL * pfHasUpDownBars ) = 0;
      virtual HRESULT __stdcall get_HiLoLines (
        /*[out,retval]*/ struct IMsoHiLoLines * * ppHiLoLines ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ int * pIndex ) = 0;
      virtual HRESULT __stdcall put_Overlap (
        /*[in]*/ int pOverlap ) = 0;
      virtual HRESULT __stdcall get_Overlap (
        /*[out,retval]*/ int * pOverlap ) = 0;
      virtual HRESULT __stdcall get_RadarAxisLabels (
        /*[out,retval]*/ IDispatch * * ppRadarAxisLabels ) = 0;
      virtual HRESULT __stdcall SeriesCollection (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * ppSeriesCollection ) = 0;
      virtual HRESULT __stdcall get_SeriesLines (
        /*[out,retval]*/ struct IMsoSeriesLines * * ppSeriesLines ) = 0;
      virtual HRESULT __stdcall put_SubType (
        /*[in]*/ int pSubType ) = 0;
      virtual HRESULT __stdcall get_SubType (
        /*[out,retval]*/ int * pSubType ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ int ptype ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ int * ptype ) = 0;
      virtual HRESULT __stdcall get_UpBars (
        /*[out,retval]*/ struct IMsoUpBars * * ppUpBars ) = 0;
      virtual HRESULT __stdcall put_VaryByCategories (
        /*[in]*/ VARIANT_BOOL pfVaryByCategories ) = 0;
      virtual HRESULT __stdcall get_VaryByCategories (
        /*[out,retval]*/ VARIANT_BOOL * pfVaryByCategories ) = 0;
      virtual HRESULT __stdcall get_SizeRepresents (
        /*[out,retval]*/ enum XlSizeRepresents * pXlSizeRepresents ) = 0;
      virtual HRESULT __stdcall put_SizeRepresents (
        /*[in]*/ enum XlSizeRepresents pXlSizeRepresents ) = 0;
      virtual HRESULT __stdcall put_BubbleScale (
        /*[in]*/ int pbubblescale ) = 0;
      virtual HRESULT __stdcall get_BubbleScale (
        /*[out,retval]*/ int * pbubblescale ) = 0;
      virtual HRESULT __stdcall put_ShowNegativeBubbles (
        /*[in]*/ VARIANT_BOOL pfShowNegativeBubbles ) = 0;
      virtual HRESULT __stdcall get_ShowNegativeBubbles (
        /*[out,retval]*/ VARIANT_BOOL * pfShowNegativeBubbles ) = 0;
      virtual HRESULT __stdcall put_SplitType (
        /*[in]*/ enum XlChartSplitType pChartSplitType ) = 0;
      virtual HRESULT __stdcall get_SplitType (
        /*[out,retval]*/ enum XlChartSplitType * pChartSplitType ) = 0;
      virtual HRESULT __stdcall get_SplitValue (
        /*[out,retval]*/ VARIANT * pSplitValue ) = 0;
      virtual HRESULT __stdcall put_SplitValue (
        /*[in]*/ VARIANT pSplitValue ) = 0;
      virtual HRESULT __stdcall get_SecondPlotSize (
        /*[out,retval]*/ int * pSecondPlotSize ) = 0;
      virtual HRESULT __stdcall put_SecondPlotSize (
        /*[in]*/ int pSecondPlotSize ) = 0;
      virtual HRESULT __stdcall get_Has3DShading (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_Has3DShading (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall CategoryCollection (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * ppcatcollection ) = 0;
      virtual HRESULT __stdcall FullCategoryCollection (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * ppcatcollection ) = 0;
};

struct __declspec(uuid("000c172b-0000-0000-c000-000000000046"))
ChartGroups : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
};

enum MsoBroadcastState
{
    NoBroadcast = 0,
    BroadcastStarted = 1,
    BroadcastPaused = 2
};

enum MsoBroadcastCapabilities
{
    BroadcastCapFileSizeLimited = 1,
    BroadcastCapSupportsMeetingNotes = 2,
    BroadcastCapSupportsUpdateDoc = 4
};

enum MsoPictureCompress
{
    msoPictureCompressDocDefault = -1,
    msoPictureCompressFalse = 0,
    msoPictureCompressTrue = 1
};

struct __declspec(uuid("000c1732-0000-0000-c000-000000000046"))
FullSeriesCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoSeries * * RHS ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * RHS ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoSeries * * RHS ) = 0;
};

struct __declspec(uuid("000c1733-0000-0000-c000-000000000046"))
IMsoCategory : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstr ) = 0;
      virtual HRESULT __stdcall get_IsFiltered (
        /*[out,retval]*/ VARIANT_BOOL * pfIsFiltered ) = 0;
      virtual HRESULT __stdcall put_IsFiltered (
        /*[in]*/ VARIANT_BOOL pfIsFiltered ) = 0;
};

struct __declspec(uuid("000c1734-0000-0000-c000-000000000046"))
CategoryCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * cCategory ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoCategory * * ppcategory ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get__Default (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IMsoCategory * * RHS ) = 0;
};

enum __declspec(uuid("bffe8f80-6a67-4b7a-aeaa-8823e7932c87"))
XlCategoryLabelLevel
{
    xlCategoryLabelLevelNone = -3,
    xlCategoryLabelLevelCustom = -2,
    xlCategoryLabelLevelAll = -1
};

enum __declspec(uuid("76d9466c-84c2-4355-81fe-cb1b9cb03c19"))
XlSeriesNameLevel
{
    xlSeriesNameLevelNone = -3,
    xlSeriesNameLevelCustom = -2,
    xlSeriesNameLevelAll = -1
};

struct __declspec(uuid("000c0302-0000-0000-c000-000000000046"))
_CommandBars : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ActionControl (
        /*[out,retval]*/ struct CommandBarControl * * ppcbc ) = 0;
      virtual HRESULT __stdcall get_ActiveMenuBar (
        /*[out,retval]*/ struct CommandBar * * ppcb ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT Name,
        /*[in]*/ VARIANT Position,
        /*[in]*/ VARIANT MenuBar,
        /*[in]*/ VARIANT Temporary,
        /*[out,retval]*/ struct CommandBar * * ppcb ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcToolbars ) = 0;
      virtual HRESULT __stdcall get_DisplayTooltips (
        /*[out,retval]*/ VARIANT_BOOL * pvarfDisplayTooltips ) = 0;
      virtual HRESULT __stdcall put_DisplayTooltips (
        /*[in]*/ VARIANT_BOOL pvarfDisplayTooltips ) = 0;
      virtual HRESULT __stdcall get_DisplayKeysInTooltips (
        /*[out,retval]*/ VARIANT_BOOL * pvarfDisplayKeys ) = 0;
      virtual HRESULT __stdcall put_DisplayKeysInTooltips (
        /*[in]*/ VARIANT_BOOL pvarfDisplayKeys ) = 0;
      virtual HRESULT __stdcall FindControl (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Id,
        /*[in]*/ VARIANT Tag,
        /*[in]*/ VARIANT Visible,
        /*[out,retval]*/ struct CommandBarControl * * ppcbc ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct CommandBar * * ppcb ) = 0;
      virtual HRESULT __stdcall get_LargeButtons (
        /*[out,retval]*/ VARIANT_BOOL * pvarfLargeButtons ) = 0;
      virtual HRESULT __stdcall put_LargeButtons (
        /*[in]*/ VARIANT_BOOL pvarfLargeButtons ) = 0;
      virtual HRESULT __stdcall get_MenuAnimationStyle (
        /*[out,retval]*/ enum MsoMenuAnimation * pma ) = 0;
      virtual HRESULT __stdcall put_MenuAnimationStyle (
        /*[in]*/ enum MsoMenuAnimation pma ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall ReleaseFocus ( ) = 0;
      virtual HRESULT __stdcall get_IdsString (
        /*[in]*/ int ids,
        /*[out]*/ BSTR * pbstrName,
        /*[out,retval]*/ int * pcch ) = 0;
      virtual HRESULT __stdcall get_TmcGetName (
        /*[in]*/ int tmc,
        /*[out]*/ BSTR * pbstrName,
        /*[out,retval]*/ int * pcch ) = 0;
      virtual HRESULT __stdcall get_AdaptiveMenus (
        /*[out,retval]*/ VARIANT_BOOL * pvarfAdaptiveMenus ) = 0;
      virtual HRESULT __stdcall put_AdaptiveMenus (
        /*[in]*/ VARIANT_BOOL pvarfAdaptiveMenus ) = 0;
      virtual HRESULT __stdcall FindControls (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Id,
        /*[in]*/ VARIANT Tag,
        /*[in]*/ VARIANT Visible,
        /*[out,retval]*/ struct CommandBarControls * * ppcbcs ) = 0;
      virtual HRESULT __stdcall AddEx (
        /*[in]*/ VARIANT TbidOrName,
        /*[in]*/ VARIANT Position,
        /*[in]*/ VARIANT MenuBar,
        /*[in]*/ VARIANT Temporary,
        /*[in]*/ VARIANT TbtrProtection,
        /*[out,retval]*/ struct CommandBar * * ppcb ) = 0;
      virtual HRESULT __stdcall get_DisplayFonts (
        /*[out,retval]*/ VARIANT_BOOL * pvarfDisplayFonts ) = 0;
      virtual HRESULT __stdcall put_DisplayFonts (
        /*[in]*/ VARIANT_BOOL pvarfDisplayFonts ) = 0;
      virtual HRESULT __stdcall get_DisableCustomize (
        /*[out,retval]*/ VARIANT_BOOL * pvarfDisableCustomize ) = 0;
      virtual HRESULT __stdcall put_DisableCustomize (
        /*[in]*/ VARIANT_BOOL pvarfDisableCustomize ) = 0;
      virtual HRESULT __stdcall get_DisableAskAQuestionDropdown (
        /*[out,retval]*/ VARIANT_BOOL * pvarfDisableAskAQuestionDropdown ) = 0;
      virtual HRESULT __stdcall put_DisableAskAQuestionDropdown (
        /*[in]*/ VARIANT_BOOL pvarfDisableAskAQuestionDropdown ) = 0;
      virtual HRESULT __stdcall ExecuteMso (
        /*[in]*/ BSTR idMso ) = 0;
      virtual HRESULT __stdcall GetEnabledMso (
        /*[in]*/ BSTR idMso,
        /*[out,retval]*/ VARIANT_BOOL * Enabled ) = 0;
      virtual HRESULT __stdcall GetVisibleMso (
        /*[in]*/ BSTR idMso,
        /*[out,retval]*/ VARIANT_BOOL * Visible ) = 0;
      virtual HRESULT __stdcall GetPressedMso (
        /*[in]*/ BSTR idMso,
        /*[out,retval]*/ VARIANT_BOOL * Pressed ) = 0;
      virtual HRESULT __stdcall GetLabelMso (
        /*[in]*/ BSTR idMso,
        /*[out,retval]*/ BSTR * Label ) = 0;
      virtual HRESULT __stdcall GetScreentipMso (
        /*[in]*/ BSTR idMso,
        /*[out,retval]*/ BSTR * Screentip ) = 0;
      virtual HRESULT __stdcall GetSupertipMso (
        /*[in]*/ BSTR idMso,
        /*[out,retval]*/ BSTR * Supertip ) = 0;
      virtual HRESULT __stdcall GetImageMso (
        /*[in]*/ BSTR idMso,
        /*[in]*/ int Width,
        /*[in]*/ int Height,
        /*[out,retval]*/ IPictureDisp * * Image ) = 0;
      virtual HRESULT __stdcall CommitRenderingTransaction (
        /*[in]*/ long hwnd ) = 0;
};

struct __declspec(uuid("000c0304-0000-0000-c000-000000000046"))
CommandBar : _IMsoOleAccDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_BuiltIn (
        /*[out,retval]*/ VARIANT_BOOL * pvarfBuiltIn ) = 0;
      virtual HRESULT __stdcall get_Context (
        /*[out,retval]*/ BSTR * pbstrContext ) = 0;
      virtual HRESULT __stdcall put_Context (
        /*[in]*/ BSTR pbstrContext ) = 0;
      virtual HRESULT __stdcall get_Controls (
        /*[out,retval]*/ struct CommandBarControls * * ppcbcs ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_Enabled (
        /*[out,retval]*/ VARIANT_BOOL * pvarfEnabled ) = 0;
      virtual HRESULT __stdcall put_Enabled (
        /*[in]*/ VARIANT_BOOL pvarfEnabled ) = 0;
      virtual HRESULT __stdcall FindControl (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Id,
        /*[in]*/ VARIANT Tag,
        /*[in]*/ VARIANT Visible,
        /*[in]*/ VARIANT Recursive,
        /*[out,retval]*/ struct CommandBarControl * * ppcbc ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ int * pdy ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ int pdy ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ int * pi ) = 0;
      virtual HRESULT __stdcall get_InstanceId (
        /*[out,retval]*/ long * pid ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ int * pxpLeft ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ int pxpLeft ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstrName ) = 0;
      virtual HRESULT __stdcall get_NameLocal (
        /*[out,retval]*/ BSTR * pbstrNameLocal ) = 0;
      virtual HRESULT __stdcall put_NameLocal (
        /*[in]*/ BSTR pbstrNameLocal ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Position (
        /*[out,retval]*/ enum MsoBarPosition * ppos ) = 0;
      virtual HRESULT __stdcall put_Position (
        /*[in]*/ enum MsoBarPosition ppos ) = 0;
      virtual HRESULT __stdcall get_RowIndex (
        /*[out,retval]*/ int * piRow ) = 0;
      virtual HRESULT __stdcall put_RowIndex (
        /*[in]*/ int piRow ) = 0;
      virtual HRESULT __stdcall get_Protection (
        /*[out,retval]*/ enum MsoBarProtection * pprot ) = 0;
      virtual HRESULT __stdcall put_Protection (
        /*[in]*/ enum MsoBarProtection pprot ) = 0;
      virtual HRESULT __stdcall Reset ( ) = 0;
      virtual HRESULT __stdcall ShowPopup (
        /*[in]*/ VARIANT x = vtMissing,
        /*[in]*/ VARIANT y = vtMissing ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ int * pypTop ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ int pypTop ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoBarType * ptype ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ VARIANT_BOOL * pvarfVisible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ VARIANT_BOOL pvarfVisible ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ int * pdx ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ int pdx ) = 0;
      virtual HRESULT __stdcall get_AdaptiveMenu (
        /*[out,retval]*/ VARIANT_BOOL * pvarfAdaptiveMenu ) = 0;
      virtual HRESULT __stdcall put_AdaptiveMenu (
        /*[in]*/ VARIANT_BOOL pvarfAdaptiveMenu ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall get_InstanceIdPtr (
        /*[out,retval]*/ VARIANT * pvarPitb ) = 0;
};

struct __declspec(uuid("000c0308-0000-0000-c000-000000000046"))
CommandBarControl : _IMsoOleAccDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_BeginGroup (
        /*[out,retval]*/ VARIANT_BOOL * pvarfBeginGroup ) = 0;
      virtual HRESULT __stdcall put_BeginGroup (
        /*[in]*/ VARIANT_BOOL pvarfBeginGroup ) = 0;
      virtual HRESULT __stdcall get_BuiltIn (
        /*[out,retval]*/ VARIANT_BOOL * pvarfBuiltIn ) = 0;
      virtual HRESULT __stdcall get_Caption (
        /*[out,retval]*/ BSTR * pbstrCaption ) = 0;
      virtual HRESULT __stdcall put_Caption (
        /*[in]*/ BSTR pbstrCaption ) = 0;
      virtual HRESULT __stdcall get_Control (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[in]*/ VARIANT Bar,
        /*[in]*/ VARIANT Before,
        /*[out,retval]*/ struct CommandBarControl * * ppcbc ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[in]*/ VARIANT Temporary = vtMissing ) = 0;
      virtual HRESULT __stdcall get_DescriptionText (
        /*[out,retval]*/ BSTR * pbstrText ) = 0;
      virtual HRESULT __stdcall put_DescriptionText (
        /*[in]*/ BSTR pbstrText ) = 0;
      virtual HRESULT __stdcall get_Enabled (
        /*[out,retval]*/ VARIANT_BOOL * pvarfEnabled ) = 0;
      virtual HRESULT __stdcall put_Enabled (
        /*[in]*/ VARIANT_BOOL pvarfEnabled ) = 0;
      virtual HRESULT __stdcall Execute ( ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ int * pdy ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ int pdy ) = 0;
      virtual HRESULT __stdcall get_HelpContextId (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall put_HelpContextId (
        /*[in]*/ int pid ) = 0;
      virtual HRESULT __stdcall get_HelpFile (
        /*[out,retval]*/ BSTR * pbstrFilename ) = 0;
      virtual HRESULT __stdcall put_HelpFile (
        /*[in]*/ BSTR pbstrFilename ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ int * pi ) = 0;
      virtual HRESULT __stdcall get_InstanceId (
        /*[out,retval]*/ long * pid ) = 0;
      virtual HRESULT __stdcall Move (
        /*[in]*/ VARIANT Bar,
        /*[in]*/ VARIANT Before,
        /*[out,retval]*/ struct CommandBarControl * * ppcbc ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ int * px ) = 0;
      virtual HRESULT __stdcall get_OLEUsage (
        /*[out,retval]*/ enum MsoControlOLEUsage * pcou ) = 0;
      virtual HRESULT __stdcall put_OLEUsage (
        /*[in]*/ enum MsoControlOLEUsage pcou ) = 0;
      virtual HRESULT __stdcall get_OnAction (
        /*[out,retval]*/ BSTR * pbstrOnAction ) = 0;
      virtual HRESULT __stdcall put_OnAction (
        /*[in]*/ BSTR pbstrOnAction ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct CommandBar * * ppcb ) = 0;
      virtual HRESULT __stdcall get_Parameter (
        /*[out,retval]*/ BSTR * pbstrParam ) = 0;
      virtual HRESULT __stdcall put_Parameter (
        /*[in]*/ BSTR pbstrParam ) = 0;
      virtual HRESULT __stdcall get_Priority (
        /*[out,retval]*/ int * pnPri ) = 0;
      virtual HRESULT __stdcall put_Priority (
        /*[in]*/ int pnPri ) = 0;
      virtual HRESULT __stdcall Reset ( ) = 0;
      virtual HRESULT __stdcall SetFocus ( ) = 0;
      virtual HRESULT __stdcall get_Tag (
        /*[out,retval]*/ BSTR * pbstrTag ) = 0;
      virtual HRESULT __stdcall put_Tag (
        /*[in]*/ BSTR pbstrTag ) = 0;
      virtual HRESULT __stdcall get_TooltipText (
        /*[out,retval]*/ BSTR * pbstrTooltip ) = 0;
      virtual HRESULT __stdcall put_TooltipText (
        /*[in]*/ BSTR pbstrTooltip ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ int * py ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoControlType * ptype ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ VARIANT_BOOL * pvarfVisible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ VARIANT_BOOL pvarfVisible ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ int * pdx ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ int pdx ) = 0;
      virtual HRESULT __stdcall get_IsPriorityDropped (
        /*[out,retval]*/ VARIANT_BOOL * pvarfDropped ) = 0;
      virtual HRESULT __stdcall Reserved1 ( ) = 0;
      virtual HRESULT __stdcall Reserved2 ( ) = 0;
      virtual HRESULT __stdcall Reserved3 ( ) = 0;
      virtual HRESULT __stdcall Reserved4 ( ) = 0;
      virtual HRESULT __stdcall Reserved5 ( ) = 0;
      virtual HRESULT __stdcall Reserved6 ( ) = 0;
      virtual HRESULT __stdcall Reserved7 ( ) = 0;
};

struct __declspec(uuid("000c0306-0000-0000-c000-000000000046"))
CommandBarControls : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Add (
        /*[in]*/ VARIANT Type,
        /*[in]*/ VARIANT Id,
        /*[in]*/ VARIANT Parameter,
        /*[in]*/ VARIANT Before,
        /*[in]*/ VARIANT Temporary,
        /*[out,retval]*/ struct CommandBarControl * * ppcbc ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pcToolbarControls ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct CommandBarControl * * ppcbc ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct CommandBar * * ppcb ) = 0;
};

struct __declspec(uuid("000c030e-0000-0000-c000-000000000046"))
_CommandBarButton : CommandBarControl
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_BuiltInFace (
        /*[out,retval]*/ VARIANT_BOOL * pvarfBuiltIn ) = 0;
      virtual HRESULT __stdcall put_BuiltInFace (
        /*[in]*/ VARIANT_BOOL pvarfBuiltIn ) = 0;
      virtual HRESULT __stdcall CopyFace ( ) = 0;
      virtual HRESULT __stdcall get_FaceId (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall put_FaceId (
        /*[in]*/ int pid ) = 0;
      virtual HRESULT __stdcall PasteFace ( ) = 0;
      virtual HRESULT __stdcall get_ShortcutText (
        /*[out,retval]*/ BSTR * pbstrText ) = 0;
      virtual HRESULT __stdcall put_ShortcutText (
        /*[in]*/ BSTR pbstrText ) = 0;
      virtual HRESULT __stdcall get_State (
        /*[out,retval]*/ enum MsoButtonState * pstate ) = 0;
      virtual HRESULT __stdcall put_State (
        /*[in]*/ enum MsoButtonState pstate ) = 0;
      virtual HRESULT __stdcall get_Style (
        /*[out,retval]*/ enum MsoButtonStyle * pstyle ) = 0;
      virtual HRESULT __stdcall put_Style (
        /*[in]*/ enum MsoButtonStyle pstyle ) = 0;
      virtual HRESULT __stdcall get_HyperlinkType (
        /*[out,retval]*/ enum MsoCommandBarButtonHyperlinkType * phlType ) = 0;
      virtual HRESULT __stdcall put_HyperlinkType (
        /*[in]*/ enum MsoCommandBarButtonHyperlinkType phlType ) = 0;
      virtual HRESULT __stdcall get_Picture (
        /*[out,retval]*/ IPictureDisp * * ppdispPicture ) = 0;
      virtual HRESULT __stdcall put_Picture (
        /*[in]*/ IPictureDisp * ppdispPicture ) = 0;
      virtual HRESULT __stdcall get_Mask (
        /*[out,retval]*/ IPictureDisp * * ppipictdispMask ) = 0;
      virtual HRESULT __stdcall put_Mask (
        /*[in]*/ IPictureDisp * ppipictdispMask ) = 0;
      virtual HRESULT __stdcall get_InstanceIdPtr (
        /*[out,retval]*/ VARIANT * pvarPic ) = 0;
};

struct __declspec(uuid("000c030a-0000-0000-c000-000000000046"))
CommandBarPopup : CommandBarControl
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_CommandBar (
        /*[out,retval]*/ struct CommandBar * * ppcb ) = 0;
      virtual HRESULT __stdcall get_Controls (
        /*[out,retval]*/ struct CommandBarControls * * ppcbcs ) = 0;
      virtual HRESULT __stdcall get_OLEMenuGroup (
        /*[out,retval]*/ enum MsoOLEMenuGroup * pomg ) = 0;
      virtual HRESULT __stdcall put_OLEMenuGroup (
        /*[in]*/ enum MsoOLEMenuGroup pomg ) = 0;
      virtual HRESULT __stdcall get_InstanceIdPtr (
        /*[out,retval]*/ VARIANT * pvarPic ) = 0;
};

struct __declspec(uuid("000c030c-0000-0000-c000-000000000046"))
_CommandBarComboBox : CommandBarControl
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddItem (
        /*[in]*/ BSTR Text,
        /*[in]*/ VARIANT Index = vtMissing ) = 0;
      virtual HRESULT __stdcall Clear ( ) = 0;
      virtual HRESULT __stdcall get_DropDownLines (
        /*[out,retval]*/ int * pcLines ) = 0;
      virtual HRESULT __stdcall put_DropDownLines (
        /*[in]*/ int pcLines ) = 0;
      virtual HRESULT __stdcall get_DropDownWidth (
        /*[out,retval]*/ int * pdx ) = 0;
      virtual HRESULT __stdcall put_DropDownWidth (
        /*[in]*/ int pdx ) = 0;
      virtual HRESULT __stdcall get_List (
        /*[in]*/ int Index,
        /*[out,retval]*/ BSTR * pbstrItem ) = 0;
      virtual HRESULT __stdcall put_List (
        /*[in]*/ int Index,
        /*[in]*/ BSTR pbstrItem ) = 0;
      virtual HRESULT __stdcall get_ListCount (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall get_ListHeaderCount (
        /*[out,retval]*/ int * pcItems ) = 0;
      virtual HRESULT __stdcall put_ListHeaderCount (
        /*[in]*/ int pcItems ) = 0;
      virtual HRESULT __stdcall get_ListIndex (
        /*[out,retval]*/ int * pi ) = 0;
      virtual HRESULT __stdcall put_ListIndex (
        /*[in]*/ int pi ) = 0;
      virtual HRESULT __stdcall RemoveItem (
        /*[in]*/ int Index ) = 0;
      virtual HRESULT __stdcall get_Style (
        /*[out,retval]*/ enum MsoComboStyle * pstyle ) = 0;
      virtual HRESULT __stdcall put_Style (
        /*[in]*/ enum MsoComboStyle pstyle ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstrText ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstrText ) = 0;
      virtual HRESULT __stdcall get_InstanceIdPtr (
        /*[out,retval]*/ VARIANT * pvarPic ) = 0;
};

struct __declspec(uuid("000c030d-0000-0000-c000-000000000046"))
_CommandBarActiveX : CommandBarControl
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ControlCLSID (
        /*[out,retval]*/ BSTR * pbstrClsid ) = 0;
      virtual HRESULT __stdcall put_ControlCLSID (
        /*[in]*/ BSTR pbstrClsid ) = 0;
      virtual HRESULT __stdcall get_QueryControlInterface (
        /*[in]*/ BSTR bstrIid,
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
      virtual HRESULT __stdcall SetInnerObjectFactory (
        /*[in]*/ IUnknown * pUnk ) = 0;
      virtual HRESULT __stdcall EnsureControl ( ) = 0;
      virtual HRESULT __stdcall put_InitWith (
        /*[in]*/ IUnknown * _arg1 ) = 0;
      virtual HRESULT __stdcall get_InstanceIdPtr (
        /*[out,retval]*/ VARIANT * pvarPic ) = 0;
};

struct __declspec(uuid("000c0313-0000-0000-c000-000000000046"))
ConnectorFormat : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall BeginConnect (
        /*[in]*/ struct Shape * ConnectedShape,
        /*[in]*/ int ConnectionSite ) = 0;
      virtual HRESULT __stdcall BeginDisconnect ( ) = 0;
      virtual HRESULT __stdcall EndConnect (
        /*[in]*/ struct Shape * ConnectedShape,
        /*[in]*/ int ConnectionSite ) = 0;
      virtual HRESULT __stdcall EndDisconnect ( ) = 0;
      virtual HRESULT __stdcall get_BeginConnected (
        /*[out,retval]*/ enum MsoTriState * BeginConnected ) = 0;
      virtual HRESULT __stdcall get_BeginConnectedShape (
        /*[out,retval]*/ struct Shape * * BeginConnectedShape ) = 0;
      virtual HRESULT __stdcall get_BeginConnectionSite (
        /*[out,retval]*/ int * BeginConnectionSite ) = 0;
      virtual HRESULT __stdcall get_EndConnected (
        /*[out,retval]*/ enum MsoTriState * EndConnected ) = 0;
      virtual HRESULT __stdcall get_EndConnectedShape (
        /*[out,retval]*/ struct Shape * * EndConnectedShape ) = 0;
      virtual HRESULT __stdcall get_EndConnectionSite (
        /*[out,retval]*/ int * EndConnectionSite ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoConnectorType * Type ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ enum MsoConnectorType Type ) = 0;
};

struct __declspec(uuid("000c0315-0000-0000-c000-000000000046"))
FreeformBuilder : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall AddNodes (
        /*[in]*/ enum MsoSegmentType SegmentType,
        /*[in]*/ enum MsoEditingType EditingType,
        /*[in]*/ float X1,
        /*[in]*/ float Y1,
        /*[in]*/ float X2,
        /*[in]*/ float Y2,
        /*[in]*/ float X3,
        /*[in]*/ float Y3 ) = 0;
      virtual HRESULT __stdcall ConvertToShape (
        /*[out,retval]*/ struct Shape * * Freeform ) = 0;
};

struct __declspec(uuid("000c0316-0000-0000-c000-000000000046"))
GroupShapes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppidisp ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * pnShapes ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppienum ) = 0;
      virtual HRESULT __stdcall Range (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct ShapeRange * * Range ) = 0;
};

struct __declspec(uuid("000c031c-0000-0000-c000-000000000046"))
Shape : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall Apply ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Duplicate (
        /*[out,retval]*/ struct Shape * * Duplicate ) = 0;
      virtual HRESULT __stdcall Flip (
        /*[in]*/ enum MsoFlipCmd FlipCmd ) = 0;
      virtual HRESULT __stdcall IncrementLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementRotation (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall PickUp ( ) = 0;
      virtual HRESULT __stdcall RerouteConnections ( ) = 0;
      virtual HRESULT __stdcall ScaleHeight (
        /*[in]*/ float Factor,
        /*[in]*/ enum MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall ScaleWidth (
        /*[in]*/ float Factor,
        /*[in]*/ enum MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall Select (
        /*[in]*/ VARIANT Replace = vtMissing ) = 0;
      virtual HRESULT __stdcall SetShapesDefaultProperties ( ) = 0;
      virtual HRESULT __stdcall Ungroup (
        /*[out,retval]*/ struct ShapeRange * * Ungroup ) = 0;
      virtual HRESULT __stdcall ZOrder (
        /*[in]*/ enum MsoZOrderCmd ZOrderCmd ) = 0;
      virtual HRESULT __stdcall get_Adjustments (
        /*[out,retval]*/ struct TangramAdjustments * * Adjustments ) = 0;
      virtual HRESULT __stdcall get_AutoShapeType (
        /*[out,retval]*/ enum MsoAutoShapeType * AutoShapeType ) = 0;
      virtual HRESULT __stdcall put_AutoShapeType (
        /*[in]*/ enum MsoAutoShapeType AutoShapeType ) = 0;
      virtual HRESULT __stdcall get_BlackWhiteMode (
        /*[out,retval]*/ enum MsoBlackWhiteMode * BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall put_BlackWhiteMode (
        /*[in]*/ enum MsoBlackWhiteMode BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall get_Callout (
        /*[out,retval]*/ struct CalloutFormat * * Callout ) = 0;
      virtual HRESULT __stdcall get_ConnectionSiteCount (
        /*[out,retval]*/ int * ConnectionSiteCount ) = 0;
      virtual HRESULT __stdcall get_Connector (
        /*[out,retval]*/ enum MsoTriState * Connector ) = 0;
      virtual HRESULT __stdcall get_ConnectorFormat (
        /*[out,retval]*/ struct ConnectorFormat * * ConnectorFormat ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct FillFormat * * Fill ) = 0;
      virtual HRESULT __stdcall get_GroupItems (
        /*[out,retval]*/ struct GroupShapes * * GroupItems ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ float * Height ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ float Height ) = 0;
      virtual HRESULT __stdcall get_HorizontalFlip (
        /*[out,retval]*/ enum MsoTriState * HorizontalFlip ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ float * Left ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ float Left ) = 0;
      virtual HRESULT __stdcall get_Line (
        /*[out,retval]*/ struct LineFormat * * Line ) = 0;
      virtual HRESULT __stdcall get_LockAspectRatio (
        /*[out,retval]*/ enum MsoTriState * LockAspectRatio ) = 0;
      virtual HRESULT __stdcall put_LockAspectRatio (
        /*[in]*/ enum MsoTriState LockAspectRatio ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Nodes (
        /*[out,retval]*/ struct ShapeNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_Rotation (
        /*[out,retval]*/ float * Rotation ) = 0;
      virtual HRESULT __stdcall put_Rotation (
        /*[in]*/ float Rotation ) = 0;
      virtual HRESULT __stdcall get_PictureFormat (
        /*[out,retval]*/ struct PictureFormat * * Picture ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ struct ShadowFormat * * Shadow ) = 0;
      virtual HRESULT __stdcall get_TextEffect (
        /*[out,retval]*/ struct TextEffectFormat * * TextEffect ) = 0;
      virtual HRESULT __stdcall get_TextFrame (
        /*[out,retval]*/ struct TextFrame * * TextFrame ) = 0;
      virtual HRESULT __stdcall get_ThreeD (
        /*[out,retval]*/ struct ThreeDFormat * * ThreeD ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ float * Top ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ float Top ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoShapeType * Type ) = 0;
      virtual HRESULT __stdcall get_VerticalFlip (
        /*[out,retval]*/ enum MsoTriState * VerticalFlip ) = 0;
      virtual HRESULT __stdcall get_Vertices (
        /*[out,retval]*/ VARIANT * Vertices ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ float * Width ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ float Width ) = 0;
      virtual HRESULT __stdcall get_ZOrderPosition (
        /*[out,retval]*/ int * ZOrderPosition ) = 0;
      virtual HRESULT __stdcall get_Script (
        /*[out,retval]*/ struct Script * * Script ) = 0;
      virtual HRESULT __stdcall get_AlternativeText (
        /*[out,retval]*/ BSTR * AlternativeText ) = 0;
      virtual HRESULT __stdcall put_AlternativeText (
        /*[in]*/ BSTR AlternativeText ) = 0;
      virtual HRESULT __stdcall get_HasDiagram (
        /*[out,retval]*/ enum MsoTriState * pHasDiagram ) = 0;
      virtual HRESULT __stdcall get_Diagram (
        /*[out,retval]*/ struct IMsoDiagram * * Diagram ) = 0;
      virtual HRESULT __stdcall get_HasDiagramNode (
        /*[out,retval]*/ enum MsoTriState * pHasDiagram ) = 0;
      virtual HRESULT __stdcall get_DiagramNode (
        /*[out,retval]*/ struct DiagramNode * * DiagramNode ) = 0;
      virtual HRESULT __stdcall get_Child (
        /*[out,retval]*/ enum MsoTriState * Child ) = 0;
      virtual HRESULT __stdcall get_ParentGroup (
        /*[out,retval]*/ struct Shape * * Parent ) = 0;
      virtual HRESULT __stdcall get_CanvasItems (
        /*[out,retval]*/ struct CanvasShapes * * CanvasShapes ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall CanvasCropLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropRight (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropBottom (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall put_RTF (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_TextFrame2 (
        /*[out,retval]*/ struct TextFrame2 * * Frame ) = 0;
      virtual HRESULT __stdcall Cut ( ) = 0;
      virtual HRESULT __stdcall Copy ( ) = 0;
      virtual HRESULT __stdcall get_HasChart (
        /*[out,retval]*/ enum MsoTriState * pHasChart ) = 0;
      virtual HRESULT __stdcall get_Chart (
        /*[out,retval]*/ struct IMsoChart * * Chart ) = 0;
      virtual HRESULT __stdcall get_ShapeStyle (
        /*[out,retval]*/ enum MsoShapeStyleIndex * ShapeStyle ) = 0;
      virtual HRESULT __stdcall put_ShapeStyle (
        /*[in]*/ enum MsoShapeStyleIndex ShapeStyle ) = 0;
      virtual HRESULT __stdcall get_BackgroundStyle (
        /*[out,retval]*/ enum MsoBackgroundStyleIndex * BackgroundStyle ) = 0;
      virtual HRESULT __stdcall put_BackgroundStyle (
        /*[in]*/ enum MsoBackgroundStyleIndex BackgroundStyle ) = 0;
      virtual HRESULT __stdcall get_SoftEdge (
        /*[out,retval]*/ struct SoftEdgeFormat * * SoftEdge ) = 0;
      virtual HRESULT __stdcall get_Glow (
        /*[out,retval]*/ struct GlowFormat * * Glow ) = 0;
      virtual HRESULT __stdcall get_Reflection (
        /*[out,retval]*/ struct ReflectionFormat * * Reflection ) = 0;
      virtual HRESULT __stdcall get_HasSmartArt (
        /*[out,retval]*/ enum MsoTriState * HasSmartArt ) = 0;
      virtual HRESULT __stdcall get_SmartArt (
        /*[out,retval]*/ struct SmartArt * * SmartArt ) = 0;
      virtual HRESULT __stdcall ConvertTextToSmartArt (
        /*[in]*/ struct SmartArtLayout * Layout ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
};

struct __declspec(uuid("000c031d-0000-0000-c000-000000000046"))
ShapeRange : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Align (
        /*[in]*/ enum MsoAlignCmd AlignCmd,
        /*[in]*/ enum MsoTriState RelativeTo ) = 0;
      virtual HRESULT __stdcall Apply ( ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Distribute (
        /*[in]*/ enum MsoDistributeCmd DistributeCmd,
        /*[in]*/ enum MsoTriState RelativeTo ) = 0;
      virtual HRESULT __stdcall Duplicate (
        /*[out,retval]*/ struct ShapeRange * * Duplicate ) = 0;
      virtual HRESULT __stdcall Flip (
        /*[in]*/ enum MsoFlipCmd FlipCmd ) = 0;
      virtual HRESULT __stdcall IncrementLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementRotation (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall IncrementTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall Group (
        /*[out,retval]*/ struct Shape * * Group ) = 0;
      virtual HRESULT __stdcall PickUp ( ) = 0;
      virtual HRESULT __stdcall Regroup (
        /*[out,retval]*/ struct Shape * * Regroup ) = 0;
      virtual HRESULT __stdcall RerouteConnections ( ) = 0;
      virtual HRESULT __stdcall ScaleHeight (
        /*[in]*/ float Factor,
        /*[in]*/ enum MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall ScaleWidth (
        /*[in]*/ float Factor,
        /*[in]*/ enum MsoTriState RelativeToOriginalSize,
        /*[in]*/ enum MsoScaleFrom fScale ) = 0;
      virtual HRESULT __stdcall Select (
        /*[in]*/ VARIANT Replace = vtMissing ) = 0;
      virtual HRESULT __stdcall SetShapesDefaultProperties ( ) = 0;
      virtual HRESULT __stdcall Ungroup (
        /*[out,retval]*/ struct ShapeRange * * Ungroup ) = 0;
      virtual HRESULT __stdcall ZOrder (
        /*[in]*/ enum MsoZOrderCmd ZOrderCmd ) = 0;
      virtual HRESULT __stdcall get_Adjustments (
        /*[out,retval]*/ struct TangramAdjustments * * Adjustments ) = 0;
      virtual HRESULT __stdcall get_AutoShapeType (
        /*[out,retval]*/ enum MsoAutoShapeType * AutoShapeType ) = 0;
      virtual HRESULT __stdcall put_AutoShapeType (
        /*[in]*/ enum MsoAutoShapeType AutoShapeType ) = 0;
      virtual HRESULT __stdcall get_BlackWhiteMode (
        /*[out,retval]*/ enum MsoBlackWhiteMode * BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall put_BlackWhiteMode (
        /*[in]*/ enum MsoBlackWhiteMode BlackWhiteMode ) = 0;
      virtual HRESULT __stdcall get_Callout (
        /*[out,retval]*/ struct CalloutFormat * * Callout ) = 0;
      virtual HRESULT __stdcall get_ConnectionSiteCount (
        /*[out,retval]*/ int * ConnectionSiteCount ) = 0;
      virtual HRESULT __stdcall get_Connector (
        /*[out,retval]*/ enum MsoTriState * Connector ) = 0;
      virtual HRESULT __stdcall get_ConnectorFormat (
        /*[out,retval]*/ struct ConnectorFormat * * ConnectorFormat ) = 0;
      virtual HRESULT __stdcall get_Fill (
        /*[out,retval]*/ struct FillFormat * * Fill ) = 0;
      virtual HRESULT __stdcall get_GroupItems (
        /*[out,retval]*/ struct GroupShapes * * GroupItems ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ float * Height ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ float Height ) = 0;
      virtual HRESULT __stdcall get_HorizontalFlip (
        /*[out,retval]*/ enum MsoTriState * HorizontalFlip ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ float * Left ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ float Left ) = 0;
      virtual HRESULT __stdcall get_Line (
        /*[out,retval]*/ struct LineFormat * * Line ) = 0;
      virtual HRESULT __stdcall get_LockAspectRatio (
        /*[out,retval]*/ enum MsoTriState * LockAspectRatio ) = 0;
      virtual HRESULT __stdcall put_LockAspectRatio (
        /*[in]*/ enum MsoTriState LockAspectRatio ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Nodes (
        /*[out,retval]*/ struct ShapeNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_Rotation (
        /*[out,retval]*/ float * Rotation ) = 0;
      virtual HRESULT __stdcall put_Rotation (
        /*[in]*/ float Rotation ) = 0;
      virtual HRESULT __stdcall get_PictureFormat (
        /*[out,retval]*/ struct PictureFormat * * Picture ) = 0;
      virtual HRESULT __stdcall get_Shadow (
        /*[out,retval]*/ struct ShadowFormat * * Shadow ) = 0;
      virtual HRESULT __stdcall get_TextEffect (
        /*[out,retval]*/ struct TextEffectFormat * * TextEffect ) = 0;
      virtual HRESULT __stdcall get_TextFrame (
        /*[out,retval]*/ struct TextFrame * * TextFrame ) = 0;
      virtual HRESULT __stdcall get_ThreeD (
        /*[out,retval]*/ struct ThreeDFormat * * ThreeD ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ float * Top ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ float Top ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoShapeType * Type ) = 0;
      virtual HRESULT __stdcall get_VerticalFlip (
        /*[out,retval]*/ enum MsoTriState * VerticalFlip ) = 0;
      virtual HRESULT __stdcall get_Vertices (
        /*[out,retval]*/ VARIANT * Vertices ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ enum MsoTriState * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ enum MsoTriState Visible ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ float * Width ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ float Width ) = 0;
      virtual HRESULT __stdcall get_ZOrderPosition (
        /*[out,retval]*/ int * ZOrderPosition ) = 0;
      virtual HRESULT __stdcall get_Script (
        /*[out,retval]*/ struct Script * * Script ) = 0;
      virtual HRESULT __stdcall get_AlternativeText (
        /*[out,retval]*/ BSTR * AlternativeText ) = 0;
      virtual HRESULT __stdcall put_AlternativeText (
        /*[in]*/ BSTR AlternativeText ) = 0;
      virtual HRESULT __stdcall get_HasDiagram (
        /*[out,retval]*/ enum MsoTriState * pHasDiagram ) = 0;
      virtual HRESULT __stdcall get_Diagram (
        /*[out,retval]*/ struct IMsoDiagram * * Diagram ) = 0;
      virtual HRESULT __stdcall get_HasDiagramNode (
        /*[out,retval]*/ enum MsoTriState * pHasDiagram ) = 0;
      virtual HRESULT __stdcall get_DiagramNode (
        /*[out,retval]*/ struct DiagramNode * * DiagramNode ) = 0;
      virtual HRESULT __stdcall get_Child (
        /*[out,retval]*/ enum MsoTriState * Child ) = 0;
      virtual HRESULT __stdcall get_ParentGroup (
        /*[out,retval]*/ struct Shape * * Parent ) = 0;
      virtual HRESULT __stdcall get_CanvasItems (
        /*[out,retval]*/ struct CanvasShapes * * CanvasShapes ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ int * pid ) = 0;
      virtual HRESULT __stdcall CanvasCropLeft (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropTop (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropRight (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall CanvasCropBottom (
        /*[in]*/ float Increment ) = 0;
      virtual HRESULT __stdcall put_RTF (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_TextFrame2 (
        /*[out,retval]*/ struct TextFrame2 * * Frame ) = 0;
      virtual HRESULT __stdcall Cut ( ) = 0;
      virtual HRESULT __stdcall Copy ( ) = 0;
      virtual HRESULT __stdcall get_HasChart (
        /*[out,retval]*/ enum MsoTriState * pHasChart ) = 0;
      virtual HRESULT __stdcall get_Chart (
        /*[out,retval]*/ struct IMsoChart * * Chart ) = 0;
      virtual HRESULT __stdcall get_ShapeStyle (
        /*[out,retval]*/ enum MsoShapeStyleIndex * ShapeStyle ) = 0;
      virtual HRESULT __stdcall put_ShapeStyle (
        /*[in]*/ enum MsoShapeStyleIndex ShapeStyle ) = 0;
      virtual HRESULT __stdcall get_BackgroundStyle (
        /*[out,retval]*/ enum MsoBackgroundStyleIndex * BackgroundStyle ) = 0;
      virtual HRESULT __stdcall put_BackgroundStyle (
        /*[in]*/ enum MsoBackgroundStyleIndex BackgroundStyle ) = 0;
      virtual HRESULT __stdcall get_SoftEdge (
        /*[out,retval]*/ struct SoftEdgeFormat * * SoftEdge ) = 0;
      virtual HRESULT __stdcall get_Glow (
        /*[out,retval]*/ struct GlowFormat * * Glow ) = 0;
      virtual HRESULT __stdcall get_Reflection (
        /*[out,retval]*/ struct ReflectionFormat * * Reflection ) = 0;
      virtual HRESULT __stdcall get_Title (
        /*[out,retval]*/ BSTR * Title ) = 0;
      virtual HRESULT __stdcall put_Title (
        /*[in]*/ BSTR Title ) = 0;
      virtual HRESULT __stdcall MergeShapes (
        /*[in]*/ enum MsoMergeCmd MergeCmd,
        /*[in]*/ struct Shape * PrimaryShape ) = 0;
};

struct __declspec(uuid("000c031e-0000-0000-c000-000000000046"))
Shapes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall AddCallout (
        /*[in]*/ enum MsoCalloutType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Callout ) = 0;
      virtual HRESULT __stdcall AddConnector (
        /*[in]*/ enum MsoConnectorType Type,
        /*[in]*/ float BeginX,
        /*[in]*/ float BeginY,
        /*[in]*/ float EndX,
        /*[in]*/ float EndY,
        /*[out,retval]*/ struct Shape * * Connector ) = 0;
      virtual HRESULT __stdcall AddCurve (
        /*[in]*/ VARIANT SafeArrayOfPoints,
        /*[out,retval]*/ struct Shape * * Curve ) = 0;
      virtual HRESULT __stdcall AddLabel (
        /*[in]*/ enum MsoTextOrientation Orientation,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Label ) = 0;
      virtual HRESULT __stdcall AddLine (
        /*[in]*/ float BeginX,
        /*[in]*/ float BeginY,
        /*[in]*/ float EndX,
        /*[in]*/ float EndY,
        /*[out,retval]*/ struct Shape * * Line ) = 0;
      virtual HRESULT __stdcall AddPicture (
        /*[in]*/ BSTR FileName,
        /*[in]*/ enum MsoTriState LinkToFile,
        /*[in]*/ enum MsoTriState SaveWithDocument,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Picture ) = 0;
      virtual HRESULT __stdcall AddPolyline (
        /*[in]*/ VARIANT SafeArrayOfPoints,
        /*[out,retval]*/ struct Shape * * Polyline ) = 0;
      virtual HRESULT __stdcall AddShape (
        /*[in]*/ enum MsoAutoShapeType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Shape ) = 0;
      virtual HRESULT __stdcall AddTextEffect (
        /*[in]*/ enum MsoPresetTextEffect PresetTextEffect,
        /*[in]*/ BSTR Text,
        /*[in]*/ BSTR FontName,
        /*[in]*/ float FontSize,
        /*[in]*/ enum MsoTriState FontBold,
        /*[in]*/ enum MsoTriState FontItalic,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[out,retval]*/ struct Shape * * TextEffect ) = 0;
      virtual HRESULT __stdcall AddTextbox (
        /*[in]*/ enum MsoTextOrientation Orientation,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Textbox ) = 0;
      virtual HRESULT __stdcall BuildFreeform (
        /*[in]*/ enum MsoEditingType EditingType,
        /*[in]*/ float X1,
        /*[in]*/ float Y1,
        /*[out,retval]*/ struct FreeformBuilder * * FreeformBuilder ) = 0;
      virtual HRESULT __stdcall Range (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct ShapeRange * * Range ) = 0;
      virtual HRESULT __stdcall SelectAll ( ) = 0;
      virtual HRESULT __stdcall get_Background (
        /*[out,retval]*/ struct Shape * * Background ) = 0;
      virtual HRESULT __stdcall get_Default (
        /*[out,retval]*/ struct Shape * * Default ) = 0;
      virtual HRESULT __stdcall AddDiagram (
        /*[in]*/ enum MsoDiagramType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Diagram ) = 0;
      virtual HRESULT __stdcall AddCanvas (
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Shape ) = 0;
      virtual HRESULT __stdcall AddChart (
        /*[in]*/ enum XlChartType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Chart ) = 0;
      virtual HRESULT __stdcall AddTable (
        /*[in]*/ int NumRows,
        /*[in]*/ int NumColumns,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Table ) = 0;
      virtual HRESULT __stdcall AddSmartArt (
        /*[in]*/ struct SmartArtLayout * Layout,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * SmartArt ) = 0;
      virtual HRESULT __stdcall AddChart2 (
        /*[in]*/ int Style,
        /*[in]*/ enum XlChartType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[in]*/ VARIANT_BOOL NewLayout,
        /*[out,retval]*/ struct Shape * * Chart ) = 0;
      virtual HRESULT __stdcall AddPicture2 (
        /*[in]*/ BSTR FileName,
        /*[in]*/ enum MsoTriState LinkToFile,
        /*[in]*/ enum MsoTriState SaveWithDocument,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[in]*/ enum MsoPictureCompress Compress,
        /*[out,retval]*/ struct Shape * * Picture ) = 0;
};

struct __declspec(uuid("000c0371-0000-0000-c000-000000000046"))
CanvasShapes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct Shape * * Item ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall AddCallout (
        /*[in]*/ enum MsoCalloutType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Callout ) = 0;
      virtual HRESULT __stdcall AddConnector (
        /*[in]*/ enum MsoConnectorType Type,
        /*[in]*/ float BeginX,
        /*[in]*/ float BeginY,
        /*[in]*/ float EndX,
        /*[in]*/ float EndY,
        /*[out,retval]*/ struct Shape * * Connector ) = 0;
      virtual HRESULT __stdcall AddCurve (
        /*[in]*/ VARIANT SafeArrayOfPoints,
        /*[out,retval]*/ struct Shape * * Curve ) = 0;
      virtual HRESULT __stdcall AddLabel (
        /*[in]*/ enum MsoTextOrientation Orientation,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Label ) = 0;
      virtual HRESULT __stdcall AddLine (
        /*[in]*/ float BeginX,
        /*[in]*/ float BeginY,
        /*[in]*/ float EndX,
        /*[in]*/ float EndY,
        /*[out,retval]*/ struct Shape * * Line ) = 0;
      virtual HRESULT __stdcall AddPicture (
        /*[in]*/ BSTR FileName,
        /*[in]*/ enum MsoTriState LinkToFile,
        /*[in]*/ enum MsoTriState SaveWithDocument,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Picture ) = 0;
      virtual HRESULT __stdcall AddPolyline (
        /*[in]*/ VARIANT SafeArrayOfPoints,
        /*[out,retval]*/ struct Shape * * Polyline ) = 0;
      virtual HRESULT __stdcall AddShape (
        /*[in]*/ enum MsoAutoShapeType Type,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Shape ) = 0;
      virtual HRESULT __stdcall AddTextEffect (
        /*[in]*/ enum MsoPresetTextEffect PresetTextEffect,
        /*[in]*/ BSTR Text,
        /*[in]*/ BSTR FontName,
        /*[in]*/ float FontSize,
        /*[in]*/ enum MsoTriState FontBold,
        /*[in]*/ enum MsoTriState FontItalic,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[out,retval]*/ struct Shape * * TextEffect ) = 0;
      virtual HRESULT __stdcall AddTextbox (
        /*[in]*/ enum MsoTextOrientation Orientation,
        /*[in]*/ float Left,
        /*[in]*/ float Top,
        /*[in]*/ float Width,
        /*[in]*/ float Height,
        /*[out,retval]*/ struct Shape * * Textbox ) = 0;
      virtual HRESULT __stdcall BuildFreeform (
        /*[in]*/ enum MsoEditingType EditingType,
        /*[in]*/ float X1,
        /*[in]*/ float Y1,
        /*[out,retval]*/ struct FreeformBuilder * * FreeformBuilder ) = 0;
      virtual HRESULT __stdcall Range (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct ShapeRange * * Range ) = 0;
      virtual HRESULT __stdcall SelectAll ( ) = 0;
      virtual HRESULT __stdcall get_Background (
        /*[out,retval]*/ struct Shape * * Background ) = 0;
};

struct __declspec(uuid("000c1709-0000-0000-c000-000000000046"))
IMsoChart : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall put_HasTitle (
        /*[in]*/ VARIANT_BOOL fTitle ) = 0;
      virtual HRESULT __stdcall get_HasTitle (
        /*[out,retval]*/ VARIANT_BOOL * fTitle ) = 0;
      virtual HRESULT __stdcall get_ChartTitle (
        /*[out,retval]*/ struct IMsoChartTitle * * pval ) = 0;
      virtual HRESULT __stdcall get_DepthPercent (
        /*[out,retval]*/ int * pwDepthPercent ) = 0;
      virtual HRESULT __stdcall put_DepthPercent (
        /*[in]*/ int pwDepthPercent ) = 0;
      virtual HRESULT __stdcall get_Elevation (
        /*[out,retval]*/ int * pwElevation ) = 0;
      virtual HRESULT __stdcall put_Elevation (
        /*[in]*/ int pwElevation ) = 0;
      virtual HRESULT __stdcall get_GapDepth (
        /*[out,retval]*/ int * pwGapDepth ) = 0;
      virtual HRESULT __stdcall put_GapDepth (
        /*[in]*/ int pwGapDepth ) = 0;
      virtual HRESULT __stdcall get_HeightPercent (
        /*[out,retval]*/ int * pwHeightPercent ) = 0;
      virtual HRESULT __stdcall put_HeightPercent (
        /*[in]*/ int pwHeightPercent ) = 0;
      virtual HRESULT __stdcall get_Perspective (
        /*[out,retval]*/ int * pwPerspective ) = 0;
      virtual HRESULT __stdcall put_Perspective (
        /*[in]*/ int pwPerspective ) = 0;
      virtual HRESULT __stdcall get_RightAngleAxes (
        /*[out,retval]*/ VARIANT * pvarRightAngleAxes ) = 0;
      virtual HRESULT __stdcall put_RightAngleAxes (
        /*[in]*/ VARIANT pvarRightAngleAxes ) = 0;
      virtual HRESULT __stdcall get_Rotation (
        /*[out,retval]*/ VARIANT * pvarRotation ) = 0;
      virtual HRESULT __stdcall put_Rotation (
        /*[in]*/ VARIANT pvarRotation ) = 0;
      virtual HRESULT __stdcall put_DisplayBlanksAs (
        /*[in]*/ enum XlDisplayBlanksAs pres ) = 0;
      virtual HRESULT __stdcall get_DisplayBlanksAs (
        /*[out,retval]*/ enum XlDisplayBlanksAs * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectData (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectData (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectFormatting (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectFormatting (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectGoalSeek (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectGoalSeek (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectSelection (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectSelection (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall put_ProtectChartObjects (
        /*[in]*/ VARIANT_BOOL pres ) = 0;
      virtual HRESULT __stdcall get_ProtectChartObjects (
        /*[out,retval]*/ VARIANT_BOOL * pres ) = 0;
      virtual HRESULT __stdcall UnProtect (
        /*[in]*/ VARIANT Password = vtMissing ) = 0;
      virtual HRESULT __stdcall Protect (
        /*[in]*/ VARIANT Password = vtMissing,
        /*[in]*/ VARIANT DrawingObjects = vtMissing,
        /*[in]*/ VARIANT Contents = vtMissing,
        /*[in]*/ VARIANT Scenarios = vtMissing,
        /*[in]*/ VARIANT UserInterfaceOnly = vtMissing ) = 0;
      virtual HRESULT __stdcall get_ChartGroups (
        /*[in]*/ VARIANT * pvarIndex,
        /*[in]*/ VARIANT varIgallery,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall SeriesCollection (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall _ApplyDataLabels (
        /*[in]*/ enum XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey = vtMissing,
        /*[in]*/ VARIANT AutoText = vtMissing,
        /*[in]*/ VARIANT HasLeaderLines = vtMissing ) = 0;
      virtual HRESULT __stdcall get_SubType (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_SubType (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ long * RHS ) = 0;
      virtual HRESULT __stdcall put_Type (
        /*[in]*/ long RHS ) = 0;
      virtual HRESULT __stdcall get_Corners (
        /*[out,retval]*/ struct IMsoCorners * * RHS ) = 0;
      virtual HRESULT __stdcall ApplyDataLabels (
        /*[in]*/ enum XlDataLabelsType Type,
        /*[in]*/ VARIANT IMsoLegendKey = vtMissing,
        /*[in]*/ VARIANT AutoText = vtMissing,
        /*[in]*/ VARIANT HasLeaderLines = vtMissing,
        /*[in]*/ VARIANT ShowSeriesName = vtMissing,
        /*[in]*/ VARIANT ShowCategoryName = vtMissing,
        /*[in]*/ VARIANT ShowValue = vtMissing,
        /*[in]*/ VARIANT ShowPercentage = vtMissing,
        /*[in]*/ VARIANT ShowBubbleSize = vtMissing,
        /*[in]*/ VARIANT Separator = vtMissing ) = 0;
      virtual HRESULT __stdcall get_ChartType (
        /*[out,retval]*/ enum XlChartType * RHS ) = 0;
      virtual HRESULT __stdcall put_ChartType (
        /*[in]*/ enum XlChartType RHS ) = 0;
      virtual HRESULT __stdcall get_HasDataTable (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasDataTable (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall ApplyCustomType (
        /*[in]*/ enum XlChartType ChartType,
        /*[in]*/ VARIANT TypeName = vtMissing ) = 0;
      virtual HRESULT __stdcall GetChartElement (
        /*[in]*/ long x,
        /*[in]*/ long y,
        /*[in,out]*/ long * ElementID,
        /*[in,out]*/ long * Arg1,
        /*[in,out]*/ long * Arg2 ) = 0;
      virtual HRESULT __stdcall SetSourceData (
        /*[in]*/ BSTR Source,
        /*[in]*/ VARIANT PlotBy = vtMissing ) = 0;
      virtual HRESULT __stdcall get_PlotBy (
        /*[out,retval]*/ enum XlRowCol * PlotBy ) = 0;
      virtual HRESULT __stdcall put_PlotBy (
        /*[in]*/ enum XlRowCol PlotBy ) = 0;
      virtual HRESULT __stdcall get_HasLegend (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasLegend (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_Legend (
        /*[out,retval]*/ struct IMsoLegend * * RHS ) = 0;
      virtual HRESULT __stdcall Axes (
        /*[in]*/ VARIANT Type,
        /*[in]*/ enum XlAxisGroup AxisGroup,
        /*[out,retval]*/ IDispatch * * ppAxes ) = 0;
      virtual HRESULT __stdcall put_HasAxis (
        /*[in]*/ VARIANT axisType,
        /*[in]*/ VARIANT AxisGroup = vtMissing,
        /*[in]*/ VARIANT pval = vtMissing ) = 0;
      virtual HRESULT __stdcall get_HasAxis (
        /*[in]*/ VARIANT axisType,
        /*[in]*/ VARIANT AxisGroup,
        /*[out,retval]*/ VARIANT * pval ) = 0;
      virtual HRESULT __stdcall get_Walls (
        /*[in]*/ VARIANT_BOOL fBackWall,
        /*[out,retval]*/ struct IMsoWalls * * ppwalls ) = 0;
      virtual HRESULT __stdcall get_Floor (
        /*[out,retval]*/ struct IMsoFloor * * ppfloor ) = 0;
      virtual HRESULT __stdcall get_PlotArea (
        /*[out,retval]*/ struct IMsoPlotArea * * ppplotarea ) = 0;
      virtual HRESULT __stdcall get_PlotVisibleOnly (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_PlotVisibleOnly (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall get_ChartArea (
        /*[out,retval]*/ struct IMsoChartArea * * ppchartarea ) = 0;
      virtual HRESULT __stdcall AutoFormat (
        /*[in]*/ long rGallery,
        /*[in]*/ VARIANT varFormat = vtMissing ) = 0;
      virtual HRESULT __stdcall get_AutoScaling (
        /*[out,retval]*/ VARIANT_BOOL * f ) = 0;
      virtual HRESULT __stdcall put_AutoScaling (
        /*[in]*/ VARIANT_BOOL f ) = 0;
      virtual HRESULT __stdcall SetBackgroundPicture (
        /*[in]*/ BSTR bstr ) = 0;
      virtual HRESULT __stdcall ChartWizard (
        /*[in]*/ VARIANT varSource = vtMissing,
        /*[in]*/ VARIANT varGallery = vtMissing,
        /*[in]*/ VARIANT varFormat = vtMissing,
        /*[in]*/ VARIANT varPlotBy = vtMissing,
        /*[in]*/ VARIANT varCategoryLabels = vtMissing,
        /*[in]*/ VARIANT varSeriesLabels = vtMissing,
        /*[in]*/ VARIANT varHasLegend = vtMissing,
        /*[in]*/ VARIANT varTitle = vtMissing,
        /*[in]*/ VARIANT varCategoryTitle = vtMissing,
        /*[in]*/ VARIANT varValueTitle = vtMissing,
        /*[in]*/ VARIANT varExtraTitle = vtMissing,
        /*[in,lcid]*/ long LocaleID = 0 ) = 0;
      virtual HRESULT __stdcall CopyPicture (
        /*[in]*/ int Appearance,
        /*[in]*/ int Format,
        /*[in]*/ int Size,
        /*[in,lcid]*/ long LocaleID = 0 ) = 0;
      virtual HRESULT __stdcall get_DataTable (
        /*[out,retval]*/ struct IMsoDataTable * * RHS ) = 0;
      virtual HRESULT __stdcall Evaluate (
        /*[in]*/ VARIANT varName,
        /*[in]*/ long LocaleID,
        /*[out]*/ long * ObjType,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall _Evaluate (
        /*[in]*/ VARIANT varName,
        /*[in]*/ long LocaleID,
        /*[out,retval]*/ VARIANT * pvar ) = 0;
      virtual HRESULT __stdcall Paste (
        /*[in]*/ VARIANT varType = vtMissing,
        /*[in,lcid]*/ long LocaleID = 0 ) = 0;
      virtual HRESULT __stdcall get_BarShape (
        /*[out,retval]*/ enum XlBarShape * pShape ) = 0;
      virtual HRESULT __stdcall put_BarShape (
        /*[in]*/ enum XlBarShape pShape ) = 0;
      virtual HRESULT __stdcall Export (
        /*[in]*/ BSTR bstr,
        /*[in]*/ VARIANT varFilterName,
        /*[in]*/ VARIANT varInteractive,
        /*[out,retval]*/ VARIANT_BOOL * f ) = 0;
      virtual HRESULT __stdcall SetDefaultChart (
        /*[in]*/ VARIANT varName ) = 0;
      virtual HRESULT __stdcall ApplyChartTemplate (
        /*[in]*/ BSTR bstrFileName ) = 0;
      virtual HRESULT __stdcall SaveChartTemplate (
        /*[in]*/ BSTR bstrFileName ) = 0;
      virtual HRESULT __stdcall get_SideWall (
        /*[out,retval]*/ struct IMsoWalls * * RHS ) = 0;
      virtual HRESULT __stdcall get_BackWall (
        /*[out,retval]*/ struct IMsoWalls * * RHS ) = 0;
      virtual HRESULT __stdcall get_ChartStyle (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_ChartStyle (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall ClearToMatchStyle ( ) = 0;
      virtual HRESULT __stdcall get_PivotLayout (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_HasPivotFields (
        /*[out,retval]*/ VARIANT_BOOL * RHS ) = 0;
      virtual HRESULT __stdcall put_HasPivotFields (
        /*[in]*/ VARIANT_BOOL RHS ) = 0;
      virtual HRESULT __stdcall RefreshPivotTable ( ) = 0;
      virtual HRESULT __stdcall put_ShowDataLabelsOverMaximum (
        /*[in]*/ VARIANT_BOOL pRHS ) = 0;
      virtual HRESULT __stdcall get_ShowDataLabelsOverMaximum (
        /*[out,retval]*/ VARIANT_BOOL * pRHS ) = 0;
      virtual HRESULT __stdcall ApplyLayout (
        /*[in]*/ long Layout,
        /*[in]*/ VARIANT varChartType = vtMissing ) = 0;
      virtual HRESULT __stdcall get_Selection (
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Refresh ( ) = 0;
      virtual HRESULT __stdcall SetElement (
        /*[in]*/ enum MsoChartElementType RHS ) = 0;
      virtual HRESULT __stdcall get_ChartData (
        /*[out,retval]*/ struct IMsoChartData * * ppchartdata ) = 0;
      virtual HRESULT __stdcall get_Format (
        /*[out,retval]*/ struct IMsoChartFormat * * ppChartFormat ) = 0;
      virtual HRESULT __stdcall get_Shapes (
        /*[out,retval]*/ struct Shapes * * ppShapes ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppval ) = 0;
      virtual HRESULT __stdcall get_Creator (
        /*[out,retval]*/ long * pval ) = 0;
      virtual HRESULT __stdcall get_Area3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall AreaGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Bar3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall BarGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Column3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall ColumnGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Line3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall LineGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_Pie3DGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall PieGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall DoughnutGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall RadarGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall get_SurfaceGroup (
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ struct IMsoChartGroup * * RHS ) = 0;
      virtual HRESULT __stdcall XYGroups (
        /*[in]*/ VARIANT Index,
        /*[in,lcid]*/ long lcid,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall Delete (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Copy (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall Select (
        /*[in]*/ VARIANT Replace,
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall get_ShowReportFilterFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowReportFilterFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowLegendFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowLegendFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowAxisFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowAxisFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowValueFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowValueFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall get_ShowAllFieldButtons (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall put_ShowAllFieldButtons (
        /*[in]*/ VARIANT_BOOL res ) = 0;
      virtual HRESULT __stdcall put_ProtectChartSheetFormatting (
        /*[in]*/ VARIANT_BOOL _arg1 ) = 0;
      virtual HRESULT __stdcall FullSeriesCollection (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * RHS ) = 0;
      virtual HRESULT __stdcall put_CategoryLabelLevel (
        /*[in]*/ enum XlCategoryLabelLevel plevel ) = 0;
      virtual HRESULT __stdcall get_CategoryLabelLevel (
        /*[out,retval]*/ enum XlCategoryLabelLevel * plevel ) = 0;
      virtual HRESULT __stdcall put_SeriesNameLevel (
        /*[in]*/ enum XlSeriesNameLevel plevel ) = 0;
      virtual HRESULT __stdcall get_SeriesNameLevel (
        /*[out,retval]*/ enum XlSeriesNameLevel * plevel ) = 0;
      virtual HRESULT __stdcall get_HasHiddenContent (
        /*[out,retval]*/ VARIANT_BOOL * res ) = 0;
      virtual HRESULT __stdcall DeleteHiddenContent ( ) = 0;
      virtual HRESULT __stdcall get_ChartColor (
        /*[out,retval]*/ VARIANT * RHS ) = 0;
      virtual HRESULT __stdcall put_ChartColor (
        /*[in]*/ VARIANT RHS ) = 0;
      virtual HRESULT __stdcall ClearToMatchColorStyle ( ) = 0;
};

struct __declspec(uuid("000c0332-0000-0000-c000-000000000046"))
FileSearch : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_SearchSubFolders (
        /*[out,retval]*/ VARIANT_BOOL * SearchSubFoldersRetVal ) = 0;
      virtual HRESULT __stdcall put_SearchSubFolders (
        /*[in]*/ VARIANT_BOOL SearchSubFoldersRetVal ) = 0;
      virtual HRESULT __stdcall get_MatchTextExactly (
        /*[out,retval]*/ VARIANT_BOOL * MatchTextRetVal ) = 0;
      virtual HRESULT __stdcall put_MatchTextExactly (
        /*[in]*/ VARIANT_BOOL MatchTextRetVal ) = 0;
      virtual HRESULT __stdcall get_MatchAllWordForms (
        /*[out,retval]*/ VARIANT_BOOL * MatchAllWordFormsRetVal ) = 0;
      virtual HRESULT __stdcall put_MatchAllWordForms (
        /*[in]*/ VARIANT_BOOL MatchAllWordFormsRetVal ) = 0;
      virtual HRESULT __stdcall get_FileName (
        /*[out,retval]*/ BSTR * FileNameRetVal ) = 0;
      virtual HRESULT __stdcall put_FileName (
        /*[in]*/ BSTR FileNameRetVal ) = 0;
      virtual HRESULT __stdcall get_FileType (
        /*[out,retval]*/ enum MsoFileType * FileTypeRetVal ) = 0;
      virtual HRESULT __stdcall put_FileType (
        /*[in]*/ enum MsoFileType FileTypeRetVal ) = 0;
      virtual HRESULT __stdcall get_LastModified (
        /*[out,retval]*/ enum MsoLastModified * LastModifiedRetVal ) = 0;
      virtual HRESULT __stdcall put_LastModified (
        /*[in]*/ enum MsoLastModified LastModifiedRetVal ) = 0;
      virtual HRESULT __stdcall get_TextOrProperty (
        /*[out,retval]*/ BSTR * TextOrProperty ) = 0;
      virtual HRESULT __stdcall put_TextOrProperty (
        /*[in]*/ BSTR TextOrProperty ) = 0;
      virtual HRESULT __stdcall get_LookIn (
        /*[out,retval]*/ BSTR * LookInRetVal ) = 0;
      virtual HRESULT __stdcall put_LookIn (
        /*[in]*/ BSTR LookInRetVal ) = 0;
      virtual HRESULT __stdcall Execute (
        /*[in]*/ enum MsoSortBy SortBy,
        /*[in]*/ enum MsoSortOrder SortOrder,
        /*[in]*/ VARIANT_BOOL AlwaysAccurate,
        /*[out,retval]*/ int * pRet ) = 0;
      virtual HRESULT __stdcall NewSearch ( ) = 0;
      virtual HRESULT __stdcall get_FoundFiles (
        /*[out,retval]*/ struct FoundFiles * * FoundFilesRet ) = 0;
      virtual HRESULT __stdcall get_PropertyTests (
        /*[out,retval]*/ struct PropertyTests * * PropTestsRet ) = 0;
      virtual HRESULT __stdcall get_SearchScopes (
        /*[out,retval]*/ struct SearchScopes * * SearchScopesRet ) = 0;
      virtual HRESULT __stdcall get_SearchFolders (
        /*[out,retval]*/ struct SearchFolders * * SearchFoldersRet ) = 0;
      virtual HRESULT __stdcall get_FileTypes (
        /*[out,retval]*/ struct FileTypes * * FileTypesRet ) = 0;
      virtual HRESULT __stdcall RefreshScopes ( ) = 0;
};

struct __declspec(uuid("000c036a-0000-0000-c000-000000000046"))
SearchFolders : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct ScopeFolder * * ScopeFolderRet ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * iCountRetVal ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ struct ScopeFolder * ScopeFolder ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ int Index ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000c0369-0000-0000-c000-000000000046"))
ScopeFolders : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct ScopeFolder * * ScopeFolderRet ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * iCountRetVal ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000c0368-0000-0000-c000-000000000046"))
ScopeFolder : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Path (
        /*[out,retval]*/ BSTR * pbstrPath ) = 0;
      virtual HRESULT __stdcall get_ScopeFolders (
        /*[out,retval]*/ struct ScopeFolders * * ScopeFoldersRet ) = 0;
      virtual HRESULT __stdcall AddToSearchFolders ( ) = 0;
};

struct __declspec(uuid("000c0367-0000-0000-c000-000000000046"))
SearchScope : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoSearchIn * MsoSearchInRetVal ) = 0;
      virtual HRESULT __stdcall get_ScopeFolder (
        /*[out,retval]*/ struct ScopeFolder * * ScopeFolderRet ) = 0;
};

struct __declspec(uuid("000c0366-0000-0000-c000-000000000046"))
SearchScopes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Item (
        /*[in]*/ int Index,
        /*[out,retval]*/ struct SearchScope * * SearchScopeRet ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * iCountRetVal ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000c036d-0000-0000-c000-000000000046"))
IMsoDiagram : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Nodes (
        /*[out,retval]*/ struct DiagramNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoDiagramType * Type ) = 0;
      virtual HRESULT __stdcall get_AutoLayout (
        /*[out,retval]*/ enum MsoTriState * AutoLayout ) = 0;
      virtual HRESULT __stdcall put_AutoLayout (
        /*[in]*/ enum MsoTriState AutoLayout ) = 0;
      virtual HRESULT __stdcall get_Reverse (
        /*[out,retval]*/ enum MsoTriState * Reverse ) = 0;
      virtual HRESULT __stdcall put_Reverse (
        /*[in]*/ enum MsoTriState Reverse ) = 0;
      virtual HRESULT __stdcall get_AutoFormat (
        /*[out,retval]*/ enum MsoTriState * AutoFormat ) = 0;
      virtual HRESULT __stdcall put_AutoFormat (
        /*[in]*/ enum MsoTriState AutoFormat ) = 0;
      virtual HRESULT __stdcall Convert (
        /*[in]*/ enum MsoDiagramType Type ) = 0;
      virtual HRESULT __stdcall FitText ( ) = 0;
};

struct __declspec(uuid("000c036e-0000-0000-c000-000000000046"))
DiagramNodes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct DiagramNode * * ppdn ) = 0;
      virtual HRESULT __stdcall SelectAll ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * iDiagramNodes ) = 0;
};

struct __declspec(uuid("000c036f-0000-0000-c000-000000000046"))
DiagramNodeChildren : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct DiagramNode * * Node ) = 0;
      virtual HRESULT __stdcall AddNode (
        /*[in]*/ VARIANT Index,
        /*[in]*/ enum MsoDiagramNodeType NodeType,
        /*[out,retval]*/ struct DiagramNode * * NewNode ) = 0;
      virtual HRESULT __stdcall SelectAll ( ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * iDiagramNodes ) = 0;
      virtual HRESULT __stdcall get_FirstChild (
        /*[out,retval]*/ struct DiagramNode * * First ) = 0;
      virtual HRESULT __stdcall get_LastChild (
        /*[out,retval]*/ struct DiagramNode * * Last ) = 0;
};

struct __declspec(uuid("000c0370-0000-0000-c000-000000000046"))
DiagramNode : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddNode (
        /*[in]*/ enum MsoRelativeNodePosition Pos,
        /*[in]*/ enum MsoDiagramNodeType NodeType,
        /*[out,retval]*/ struct DiagramNode * * NewNode ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall MoveNode (
        /*[in]*/ struct DiagramNode * TargetNode,
        /*[in]*/ enum MsoRelativeNodePosition Pos ) = 0;
      virtual HRESULT __stdcall ReplaceNode (
        /*[in]*/ struct DiagramNode * TargetNode ) = 0;
      virtual HRESULT __stdcall SwapNode (
        /*[in]*/ struct DiagramNode * TargetNode,
        /*[in]*/ VARIANT_BOOL SwapChildren ) = 0;
      virtual HRESULT __stdcall CloneNode (
        /*[in]*/ VARIANT_BOOL CopyChildren,
        /*[in]*/ struct DiagramNode * TargetNode,
        /*[in]*/ enum MsoRelativeNodePosition Pos,
        /*[out,retval]*/ struct DiagramNode * * Node ) = 0;
      virtual HRESULT __stdcall TransferChildren (
        /*[in]*/ struct DiagramNode * ReceivingNode ) = 0;
      virtual HRESULT __stdcall NextNode (
        /*[out,retval]*/ struct DiagramNode * * NextNode ) = 0;
      virtual HRESULT __stdcall PrevNode (
        /*[out,retval]*/ struct DiagramNode * * PrevNode ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Children (
        /*[out,retval]*/ struct DiagramNodeChildren * * Children ) = 0;
      virtual HRESULT __stdcall get_Shape (
        /*[out,retval]*/ struct Shape * * Shape ) = 0;
      virtual HRESULT __stdcall get_Root (
        /*[out,retval]*/ struct DiagramNode * * Root ) = 0;
      virtual HRESULT __stdcall get_Diagram (
        /*[out,retval]*/ struct IMsoDiagram * * Diagram ) = 0;
      virtual HRESULT __stdcall get_Layout (
        /*[out,retval]*/ enum MsoOrgChartLayoutType * Type ) = 0;
      virtual HRESULT __stdcall put_Layout (
        /*[in]*/ enum MsoOrgChartLayoutType Type ) = 0;
      virtual HRESULT __stdcall get_TextShape (
        /*[out,retval]*/ struct Shape * * Shape ) = 0;
};

struct __declspec(uuid("000cdb03-0000-0000-c000-000000000046"))
CustomXMLNodes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct CustomXMLNode * * ppNode ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000cdb04-0000-0000-c000-000000000046"))
CustomXMLNode : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Attributes (
        /*[out,retval]*/ struct CustomXMLNodes * * ppAttributes ) = 0;
      virtual HRESULT __stdcall get_BaseName (
        /*[out,retval]*/ BSTR * pbstrBaseName ) = 0;
      virtual HRESULT __stdcall get_ChildNodes (
        /*[out,retval]*/ struct CustomXMLNodes * * ppChildNodes ) = 0;
      virtual HRESULT __stdcall get_FirstChild (
        /*[out,retval]*/ struct CustomXMLNode * * ppFirstChild ) = 0;
      virtual HRESULT __stdcall get_LastChild (
        /*[out,retval]*/ struct CustomXMLNode * * ppLastChild ) = 0;
      virtual HRESULT __stdcall get_NamespaceURI (
        /*[out,retval]*/ BSTR * pbstrNamespaceURI ) = 0;
      virtual HRESULT __stdcall get_NextSibling (
        /*[out,retval]*/ struct CustomXMLNode * * ppNextSibling ) = 0;
      virtual HRESULT __stdcall get_NodeType (
        /*[out,retval]*/ enum MsoCustomXMLNodeType * pNodeType ) = 0;
      virtual HRESULT __stdcall get_NodeValue (
        /*[out,retval]*/ BSTR * pbstrNodeValue ) = 0;
      virtual HRESULT __stdcall put_NodeValue (
        /*[in]*/ BSTR pbstrNodeValue ) = 0;
      virtual HRESULT __stdcall get_OwnerDocument (
        /*[out,retval]*/ IDispatch * * ppdispDoc ) = 0;
      virtual HRESULT __stdcall get_OwnerPart (
        /*[out,retval]*/ struct _CustomXMLPart * * ppOwnerPart ) = 0;
      virtual HRESULT __stdcall get_PreviousSibling (
        /*[out,retval]*/ struct CustomXMLNode * * ppPreviousSibling ) = 0;
      virtual HRESULT __stdcall get_ParentNode (
        /*[out,retval]*/ struct CustomXMLNode * * ppParentNode ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstrText ) = 0;
      virtual HRESULT __stdcall put_Text (
        /*[in]*/ BSTR pbstrText ) = 0;
      virtual HRESULT __stdcall get_XPath (
        /*[out,retval]*/ BSTR * pbstrXPath ) = 0;
      virtual HRESULT __stdcall get_XML (
        /*[out,retval]*/ BSTR * pbstrXML ) = 0;
      virtual HRESULT __stdcall AppendChildNode (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NamespaceURI,
        /*[in]*/ enum MsoCustomXMLNodeType NodeType,
        /*[in]*/ BSTR NodeValue ) = 0;
      virtual HRESULT __stdcall AppendChildSubtree (
        /*[in]*/ BSTR XML ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall HasChildNodes (
        /*[out,retval]*/ VARIANT_BOOL * pfHasChildNodes ) = 0;
      virtual HRESULT __stdcall InsertNodeBefore (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NamespaceURI,
        /*[in]*/ enum MsoCustomXMLNodeType NodeType,
        /*[in]*/ BSTR NodeValue,
        /*[in]*/ struct CustomXMLNode * NextSibling ) = 0;
      virtual HRESULT __stdcall InsertSubtreeBefore (
        /*[in]*/ BSTR XML,
        /*[in]*/ struct CustomXMLNode * NextSibling ) = 0;
      virtual HRESULT __stdcall RemoveChild (
        /*[in]*/ struct CustomXMLNode * Child ) = 0;
      virtual HRESULT __stdcall ReplaceChildNode (
        /*[in]*/ struct CustomXMLNode * OldNode,
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NamespaceURI,
        /*[in]*/ enum MsoCustomXMLNodeType NodeType,
        /*[in]*/ BSTR NodeValue ) = 0;
      virtual HRESULT __stdcall ReplaceChildSubtree (
        /*[in]*/ BSTR XML,
        /*[in]*/ struct CustomXMLNode * OldNode ) = 0;
      virtual HRESULT __stdcall SelectNodes (
        /*[in]*/ BSTR XPath,
        /*[out,retval]*/ struct CustomXMLNodes * * ppNodes ) = 0;
      virtual HRESULT __stdcall SelectSingleNode (
        /*[in]*/ BSTR XPath,
        /*[out,retval]*/ struct CustomXMLNode * * ppNode ) = 0;
};

struct __declspec(uuid("000cdb0e-0000-0000-c000-000000000046"))
CustomXMLValidationError : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Star (
        /*[out,retval]*/ struct CustomXMLNode * * ppNode ) = 0;
      virtual HRESULT __stdcall get_Text (
        /*[out,retval]*/ BSTR * pbstrText ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoCustomXMLValidationErrorType * pErrorType ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall get_ErrorCode (
        /*[out,retval]*/ long * plErrorCode ) = 0;
};

struct __declspec(uuid("000cdb0f-0000-0000-c000-000000000046"))
CustomXMLValidationErrors : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long Index,
        /*[out,retval]*/ struct CustomXMLValidationError * * ppError ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ struct CustomXMLNode * Node,
        /*[in]*/ BSTR ErrorName,
        /*[in]*/ BSTR ErrorText,
        /*[in]*/ VARIANT_BOOL ClearedOnUpdate ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppunkEnum ) = 0;
};

struct __declspec(uuid("000cdb05-0000-0000-c000-000000000046"))
_CustomXMLPart : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_DocumentElement (
        /*[out,retval]*/ struct CustomXMLNode * * ppDocumentElement ) = 0;
      virtual HRESULT __stdcall get_Id (
        /*[out,retval]*/ BSTR * pbstrID ) = 0;
      virtual HRESULT __stdcall get_NamespaceURI (
        /*[out,retval]*/ BSTR * pbstrNamespaceURI ) = 0;
      virtual HRESULT __stdcall get_SchemaCollection (
        /*[out,retval]*/ struct _CustomXMLSchemaCollection * * ppSchemaCollection ) = 0;
      virtual HRESULT __stdcall put_SchemaCollection (
        /*[in]*/ struct _CustomXMLSchemaCollection * ppSchemaCollection ) = 0;
      virtual HRESULT __stdcall get_NamespaceManager (
        /*[out,retval]*/ struct CustomXMLPrefixMappings * * ppPrefixMappings ) = 0;
      virtual HRESULT __stdcall get_XML (
        /*[out,retval]*/ BSTR * pbstrXML ) = 0;
      virtual HRESULT __stdcall AddNode (
        /*[in]*/ struct CustomXMLNode * Parent,
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR NamespaceURI,
        /*[in]*/ struct CustomXMLNode * NextSibling,
        /*[in]*/ enum MsoCustomXMLNodeType NodeType,
        /*[in]*/ BSTR NodeValue ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Load (
        /*[in]*/ BSTR FilePath,
        /*[out,retval]*/ VARIANT_BOOL * pfRet ) = 0;
      virtual HRESULT __stdcall LoadXML (
        /*[in]*/ BSTR XML,
        /*[out,retval]*/ VARIANT_BOOL * pfRet ) = 0;
      virtual HRESULT __stdcall SelectNodes (
        /*[in]*/ BSTR XPath,
        /*[out,retval]*/ struct CustomXMLNodes * * ppNodes ) = 0;
      virtual HRESULT __stdcall SelectSingleNode (
        /*[in]*/ BSTR XPath,
        /*[out,retval]*/ struct CustomXMLNode * * ppNode ) = 0;
      virtual HRESULT __stdcall get_Errors (
        /*[out,retval]*/ struct CustomXMLValidationErrors * * ppErrors ) = 0;
      virtual HRESULT __stdcall get_BuiltIn (
        /*[out,retval]*/ VARIANT_BOOL * pfRet ) = 0;
};

struct __declspec(uuid("000cdb06-0000-0000-c000-000000000046"))
ICustomXMLPartEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual void __stdcall NodeAfterInsert (
        /*[in]*/ struct CustomXMLNode * NewNode,
        /*[in]*/ VARIANT_BOOL InUndoRedo ) = 0;
      virtual void __stdcall NodeAfterDelete (
        /*[in]*/ struct CustomXMLNode * OldNode,
        /*[in]*/ struct CustomXMLNode * OldParentNode,
        /*[in]*/ struct CustomXMLNode * OldNextSibling,
        /*[in]*/ VARIANT_BOOL InUndoRedo ) = 0;
      virtual void __stdcall NodeAfterReplace (
        /*[in]*/ struct CustomXMLNode * OldNode,
        /*[in]*/ struct CustomXMLNode * NewNode,
        /*[in]*/ VARIANT_BOOL InUndoRedo ) = 0;
};

struct __declspec(uuid("000c03c6-0000-0000-c000-000000000046"))
SmartArt : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_AllNodes (
        /*[out,retval]*/ struct SmartArtNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_Nodes (
        /*[out,retval]*/ struct SmartArtNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_Layout (
        /*[out,retval]*/ struct SmartArtLayout * * Layout ) = 0;
      virtual HRESULT __stdcall put_Layout (
        /*[in]*/ struct SmartArtLayout * Layout ) = 0;
      virtual HRESULT __stdcall get_QuickStyle (
        /*[out,retval]*/ struct SmartArtQuickStyle * * Style ) = 0;
      virtual HRESULT __stdcall put_QuickStyle (
        /*[in]*/ struct SmartArtQuickStyle * Style ) = 0;
      virtual HRESULT __stdcall get_Color (
        /*[out,retval]*/ struct SmartArtColor * * ColorStyle ) = 0;
      virtual HRESULT __stdcall put_Color (
        /*[in]*/ struct SmartArtColor * ColorStyle ) = 0;
      virtual HRESULT __stdcall get_Reverse (
        /*[out,retval]*/ enum MsoTriState * Reverse ) = 0;
      virtual HRESULT __stdcall put_Reverse (
        /*[in]*/ enum MsoTriState Reverse ) = 0;
      virtual HRESULT __stdcall Reset ( ) = 0;
};

struct __declspec(uuid("000c03c7-0000-0000-c000-000000000046"))
SmartArtNodes : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct SmartArtNode * * SmartArtNode ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ int * Count ) = 0;
      virtual HRESULT __stdcall Add (
        /*[out,retval]*/ struct SmartArtNode * * NewNode ) = 0;
};

struct __declspec(uuid("000c03c8-0000-0000-c000-000000000046"))
SmartArtNode : _IMsoDispObj
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall AddNode (
        /*[in]*/ enum MsoSmartArtNodePosition Position,
        /*[in]*/ enum MsoSmartArtNodeType Type,
        /*[out,retval]*/ struct SmartArtNode * * NewNode ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Promote ( ) = 0;
      virtual HRESULT __stdcall Demote ( ) = 0;
      virtual HRESULT __stdcall get_OrgChartLayout (
        /*[out,retval]*/ enum MsoOrgChartLayoutType * Type ) = 0;
      virtual HRESULT __stdcall put_OrgChartLayout (
        /*[in]*/ enum MsoOrgChartLayoutType Type ) = 0;
      virtual HRESULT __stdcall get_Shapes (
        /*[out,retval]*/ struct ShapeRange * * Shape ) = 0;
      virtual HRESULT __stdcall get_TextFrame2 (
        /*[out,retval]*/ struct TextFrame2 * * Frame ) = 0;
      virtual HRESULT __stdcall Larger ( ) = 0;
      virtual HRESULT __stdcall Smaller ( ) = 0;
      virtual HRESULT __stdcall get_Level (
        /*[out,retval]*/ int * Level ) = 0;
      virtual HRESULT __stdcall get_Hidden (
        /*[out,retval]*/ enum MsoTriState * Hidden ) = 0;
      virtual HRESULT __stdcall get_Nodes (
        /*[out,retval]*/ struct SmartArtNodes * * Nodes ) = 0;
      virtual HRESULT __stdcall get_ParentNode (
        /*[out,retval]*/ struct SmartArtNode * * Node ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum MsoSmartArtNodeType * Type ) = 0;
      virtual HRESULT __stdcall ReorderUp ( ) = 0;
      virtual HRESULT __stdcall ReorderDown ( ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_Office =
    {0x2df8d04c,0x5bfa,0x101b,{0xbd,0xe5,0x00,0xaa,0x00,0x44,0xde,0x52}};
extern "C" const GUID __declspec(selectany) IID_IAccessible =
    {0x618736e0,0x3c3d,0x11cf,{0x81,0x0c,0x00,0xaa,0x00,0x38,0x9b,0x71}};
extern "C" const GUID __declspec(selectany) IID__IMsoDispObj =
    {0x000c0300,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__IMsoOleAccDispObj =
    {0x000c0301,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TangramAdjustments =
    {0x000c0310,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CalloutFormat =
    {0x000c0311,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ShapeNode =
    {0x000c0318,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ShapeNodes =
    {0x000c0319,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Script =
    {0x000c0341,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Scripts =
    {0x000c0340,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TextEffectFormat =
    {0x000c031f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TextFrame =
    {0x000c0320,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoDispCagNotifySink =
    {0x000c0359,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Balloon =
    {0x000c0324,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_BalloonCheckboxes =
    {0x000c0326,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_BalloonCheckbox =
    {0x000c0328,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_BalloonLabels =
    {0x000c032e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_BalloonLabel =
    {0x000c0330,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_AnswerWizardFiles =
    {0x000c0361,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_AnswerWizard =
    {0x000c0360,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DocumentProperty =
    {0x2df8d04e,0x5bfa,0x101b,{0xbd,0xe5,0x00,0xaa,0x00,0x44,0xde,0x52}};
extern "C" const GUID __declspec(selectany) IID_DocumentProperties =
    {0x2df8d04d,0x5bfa,0x101b,{0xbd,0xe5,0x00,0xaa,0x00,0x44,0xde,0x52}};
extern "C" const GUID __declspec(selectany) IID_IFoundFiles =
    {0x000c0338,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IFind =
    {0x000c0337,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FoundFiles =
    {0x000c0331,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PropertyTest =
    {0x000c0333,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PropertyTests =
    {0x000c0334,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_COMAddIn =
    {0x000c033a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_COMAddIns =
    {0x000c0339,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_LanguageSettings =
    {0x000c0353,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ICommandBarsEvents =
    {0x55f88892,0x7708,0x11d1,{0xac,0xeb,0x00,0x60,0x08,0x96,0x1d,0xa5}};
extern "C" const GUID __declspec(selectany) DIID__CommandBarsEvents =
    {0x000c0352,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CommandBars =
    {0x55f88893,0x7708,0x11d1,{0xac,0xeb,0x00,0x60,0x08,0x96,0x1d,0xa5}};
extern "C" const GUID __declspec(selectany) DIID__CommandBarComboBoxEvents =
    {0x000c0354,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CommandBarComboBox =
    {0x55f88897,0x7708,0x11d1,{0xac,0xeb,0x00,0x60,0x08,0x96,0x1d,0xa5}};
extern "C" const GUID __declspec(selectany) IID_ICommandBarComboBoxEvents =
    {0x55f88896,0x7708,0x11d1,{0xac,0xeb,0x00,0x60,0x08,0x96,0x1d,0xa5}};
extern "C" const GUID __declspec(selectany) DIID__CommandBarButtonEvents =
    {0x000c0351,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CommandBarButton =
    {0x55f88891,0x7708,0x11d1,{0xac,0xeb,0x00,0x60,0x08,0x96,0x1d,0xa5}};
extern "C" const GUID __declspec(selectany) IID_ICommandBarButtonEvents =
    {0x55f88890,0x7708,0x11d1,{0xac,0xeb,0x00,0x60,0x08,0x96,0x1d,0xa5}};
extern "C" const GUID __declspec(selectany) IID_WebPageFont =
    {0x000c0913,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WebPageFonts =
    {0x000c0914,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_HTMLProjectItem =
    {0x000c0358,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_HTMLProjectItems =
    {0x000c0357,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_HTMLProject =
    {0x000c0356,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_MsoDebugOptions =
    {0x000c035a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FileDialogSelectedItems =
    {0x000c0363,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FileDialogFilter =
    {0x000c0364,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FileDialogFilters =
    {0x000c0365,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FileDialog =
    {0x000c0362,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoEnvelopeVB =
    {0x000672ac,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID_IMsoEnvelopeVBEvents =
    {0x000672ad,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_MsoEnvelope =
    {0x0006f01a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Assistant =
    {0x000c0322,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FileTypes =
    {0x000c036c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_OfficeDataSourceObject =
    {0x000c1530,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ODSOColumn =
    {0x000c1531,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ODSOColumns =
    {0x000c1532,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ODSOFilter =
    {0x000c1533,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ODSOFilters =
    {0x000c1534,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_NewFile =
    {0x000c0936,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WebComponent =
    {0x000cd100,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WebComponentWindowExternal =
    {0x000cd101,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WebComponentFormat =
    {0x000cd102,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ILicWizExternal =
    {0x4cac6328,0xb9b0,0x11d3,{0x8d,0x59,0x00,0x50,0x04,0x83,0x84,0xe3}};
extern "C" const GUID __declspec(selectany) IID_ILicValidator =
    {0x919aa22c,0xb9ad,0x11d3,{0x8d,0x59,0x00,0x50,0x04,0x83,0x84,0xe3}};
extern "C" const GUID __declspec(selectany) IID_ILicAgent =
    {0x00194002,0xd9c3,0x11d3,{0x8d,0x59,0x00,0x50,0x04,0x83,0x84,0xe3}};
extern "C" const GUID __declspec(selectany) IID_IMsoEServicesDialog =
    {0x000c0372,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WebComponentProperties =
    {0x000c0373,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartDocument =
    {0x000c0377,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceMember =
    {0x000c0381,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceMembers =
    {0x000c0382,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceTask =
    {0x000c0379,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceTasks =
    {0x000c037a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceFile =
    {0x000c037b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceFiles =
    {0x000c037c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceFolder =
    {0x000c037d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceFolders =
    {0x000c037e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceLink =
    {0x000c037f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspaceLinks =
    {0x000c0380,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SharedWorkspace =
    {0x000c0385,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Sync =
    {0x000c0386,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DocumentLibraryVersion =
    {0x000c0387,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DocumentLibraryVersions =
    {0x000c0388,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_UserPermission =
    {0x000c0375,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Permission =
    {0x000c0376,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_MsoDebugOptions_UTRunResult =
    {0x000c038c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_MsoDebugOptions_UT =
    {0x000c038b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_MsoDebugOptions_UTs =
    {0x000c038a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_MsoDebugOptions_UTManager =
    {0x000c0389,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_MetaProperty =
    {0x000c038f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_MetaProperties =
    {0x000c038e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PolicyItem =
    {0x000c0391,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ServerPolicy =
    {0x000c0390,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DocumentInspector =
    {0x000c0393,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DocumentInspectors =
    {0x000c0392,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WorkflowTask =
    {0x000cd900,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WorkflowTasks =
    {0x000cd901,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WorkflowTemplate =
    {0x000cd902,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_WorkflowTemplates =
    {0x000cd903,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IDocumentInspector =
    {0x000cd706,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SignatureSetup =
    {0x000cd6a1,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SignatureInfo =
    {0x000cd6a2,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Signature =
    {0x000c0411,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SignatureSet =
    {0x000c0410,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SignatureProvider =
    {0x000cd6a3,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomXMLPrefixMapping =
    {0x000cdb10,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomXMLPrefixMappings =
    {0x000cdb00,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomXMLSchema =
    {0x000cdb01,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CustomXMLSchemaCollection =
    {0x000cdb0d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CustomXMLSchemaCollection =
    {0x000cdb02,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__CustomXMLPartEvents =
    {0x000cdb07,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CustomXMLPart =
    {0x000cdb08,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ICustomXMLPartsEvents =
    {0x000cdb0a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__CustomXMLPartsEvents =
    {0x000cdb0b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CustomXMLParts =
    {0x000cdb0c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CustomXMLParts =
    {0x000cdb09,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SoftEdgeFormat =
    {0x000c03bc,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ReflectionFormat =
    {0x000c03be,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ColorFormat =
    {0x000c0312,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_LineFormat =
    {0x000c0317,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ThreeDFormat =
    {0x000c0321,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_GradientStop =
    {0x000c03bf,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_GradientStops =
    {0x000c03c0,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_GlowFormat =
    {0x000c03bd,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ThemeColor =
    {0x000c03a1,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ThemeColorScheme =
    {0x000c03a2,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ThemeFont =
    {0x000c03a3,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ThemeFonts =
    {0x000c03a4,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ThemeFontScheme =
    {0x000c03a5,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ThemeEffectScheme =
    {0x000c03a6,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_OfficeTheme =
    {0x000c03a0,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CustomTaskPane =
    {0x000c033b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomTaskPaneEvents =
    {0x8a64a872,0xfc6b,0x4d4a,{0x92,0x6e,0x3a,0x36,0x89,0x56,0x2c,0x1c}};
extern "C" const GUID __declspec(selectany) DIID__CustomTaskPaneEvents =
    {0x000c033c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CustomTaskPane =
    {0xc5771be5,0xa188,0x466b,{0xab,0x31,0x00,0xa6,0xa3,0x2b,0x1b,0x1c}};
extern "C" const GUID __declspec(selectany) IID_ICTPFactory =
    {0x000c033d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ICustomTaskPaneConsumer =
    {0x000c033e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IRibbonUI =
    {0x000c03a7,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IRibbonControl =
    {0x000c0395,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IRibbonExtensibility =
    {0x000c0396,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ShadowFormat =
    {0x000c031b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TextColumn2 =
    {0x000c03b2,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IAssistance =
    {0x4291224c,0xdefe,0x485b,{0x8e,0x69,0x6c,0xf8,0xaa,0x85,0xcb,0x76}};
extern "C" const GUID __declspec(selectany) IID_IMsoChartData =
    {0x000c172f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoCorners =
    {0x000c1714,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoBorder =
    {0x000c1717,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoInterior =
    {0x000c171b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ChartFont =
    {0x000c1718,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ChartColorFormat =
    {0x000c171d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ChartFillFormat =
    {0x000c171c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoHyperlinks =
    {0xa98639a1,0xcb0c,0x4a5c,{0xa5,0x11,0x96,0x54,0x7f,0x75,0x2a,0xcd}};
extern "C" const GUID __declspec(selectany) IID_IMsoCharacters =
    {0x000c1731,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TabStop2 =
    {0x000c03bb,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TabStops2 =
    {0x000c03ba,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_RulerLevel2 =
    {0x000c03c3,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_RulerLevels2 =
    {0x000c03c2,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Ruler2 =
    {0x000c03c1,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_EncryptionProvider =
    {0x000cd809,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IBlogExtensibility =
    {0x000c03c4,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IBlogPictureExtensibility =
    {0x000c03c5,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IConverterPreferences =
    {0x000c03d4,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IConverterApplicationPreferences =
    {0x000c03d5,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IConverterUICallback =
    {0x000c03d6,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IConverter =
    {0x000c03d7,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtLayout =
    {0x000c03ca,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtLayouts =
    {0x000c03c9,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtQuickStyle =
    {0x000c03cc,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtQuickStyles =
    {0x000c03cb,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtColor =
    {0x000c03ce,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtColors =
    {0x000c03cd,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PickerField =
    {0x000c03e0,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PickerFields =
    {0x000c03e1,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PickerProperty =
    {0x000c03e2,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PickerProperties =
    {0x000c03e3,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PickerResult =
    {0x000c03e4,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PickerResults =
    {0x000c03e5,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PickerDialog =
    {0x000c03e6,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoContactCard =
    {0x000c03f0,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_EffectParameter =
    {0x000c03cf,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_EffectParameters =
    {0x000c03d0,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PictureEffect =
    {0x000c03d1,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PictureEffects =
    {0x000c03d2,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FillFormat =
    {0x000c0314,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Font2 =
    {0x000c039a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_BulletFormat2 =
    {0x000c03b9,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ParagraphFormat2 =
    {0x000c0399,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Crop =
    {0x000c03d3,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_PictureFormat =
    {0x000c031a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ContactCard =
    {0x000c03f1,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TextRange2 =
    {0x000c0397,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_TextFrame2 =
    {0x000c0398,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoChartFormat =
    {0x000c1730,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoLegend =
    {0x000c1710,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoWalls =
    {0x000c1715,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoFloor =
    {0x000c1716,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoPlotArea =
    {0x000c1724,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoChartArea =
    {0x000c1728,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoSeriesLines =
    {0x000c1729,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoLeaderLines =
    {0x000c1723,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_GridLines =
    {0x000c1725,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoUpBars =
    {0x000c172a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoDownBars =
    {0x000c172d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoLegendKey =
    {0x000c171e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_LegendEntry =
    {0x000c171a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_LegendEntries =
    {0x000c1719,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoErrorBars =
    {0x000c1721,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoSeries =
    {0x000c170b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SeriesCollection =
    {0x000c170a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoDataLabel =
    {0x000c1720,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoTrendline =
    {0x000c170e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Trendlines =
    {0x000c1722,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoDataLabels =
    {0x000c171f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ChartPoint =
    {0x000c170c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Points =
    {0x000c170d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoDataTable =
    {0x000c1711,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoChartTitle =
    {0x000c170f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoAxisTitle =
    {0xabfa087c,0xf703,0x4d53,{0x94,0x6e,0x37,0xff,0x82,0xb2,0xc9,0x94}};
extern "C" const GUID __declspec(selectany) IID_IMsoDisplayUnitLabel =
    {0x6ea00553,0x9439,0x4d5a,{0xb1,0xe6,0xdc,0x15,0xa5,0x4d,0xa8,0xb2}};
extern "C" const GUID __declspec(selectany) IID_IMsoTickLabels =
    {0x000c1726,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoAxis =
    {0x000c1713,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Axes =
    {0x000c1712,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoDropLines =
    {0x000c172c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoHiLoLines =
    {0x000c172e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoChartGroup =
    {0x000c1727,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ChartGroups =
    {0x000c172b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FullSeriesCollection =
    {0x000c1732,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoCategory =
    {0x000c1733,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CategoryCollection =
    {0x000c1734,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CommandBars =
    {0x000c0302,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CommandBar =
    {0x000c0304,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CommandBarControl =
    {0x000c0308,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CommandBarControls =
    {0x000c0306,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CommandBarButton =
    {0x000c030e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CommandBarPopup =
    {0x000c030a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CommandBarComboBox =
    {0x000c030c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CommandBarActiveX =
    {0x000c030d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ConnectorFormat =
    {0x000c0313,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FreeformBuilder =
    {0x000c0315,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_GroupShapes =
    {0x000c0316,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Shape =
    {0x000c031c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ShapeRange =
    {0x000c031d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Shapes =
    {0x000c031e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CanvasShapes =
    {0x000c0371,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoChart =
    {0x000c1709,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_FileSearch =
    {0x000c0332,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SearchFolders =
    {0x000c036a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ScopeFolders =
    {0x000c0369,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ScopeFolder =
    {0x000c0368,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SearchScope =
    {0x000c0367,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SearchScopes =
    {0x000c0366,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_IMsoDiagram =
    {0x000c036d,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DiagramNodes =
    {0x000c036e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DiagramNodeChildren =
    {0x000c036f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_DiagramNode =
    {0x000c0370,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomXMLNodes =
    {0x000cdb03,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomXMLNode =
    {0x000cdb04,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomXMLValidationError =
    {0x000cdb0e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_CustomXMLValidationErrors =
    {0x000cdb0f,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CustomXMLPart =
    {0x000cdb05,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_ICustomXMLPartEvents =
    {0x000cdb06,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArt =
    {0x000c03c6,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtNodes =
    {0x000c03c7,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_SmartArtNode =
    {0x000c03c8,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

} // namespace Office

#pragma pack(pop)
