# Every Desktop Application is a Super Web Browser for M132
## What Problem Do We Need to Solve?
The problem we need to solve is to enable existing or under developing 64-bit desktop applications, especially those applications developed with .NET, C++/MFC and Win32 SDK, to have their own "Super Web Content Ecosystem" that surpasses Current Web Browsers, and Native Desktop Window Objects becoming Extended Web DOM Elements comparable to "html div" elements, specifically:
	Allowing developers to directly view ordinary desktop applications as a "Super Web Browser" that surpasses standard web browsers, developers can write any number of webpages directly for ordinary desktop applications.
	Provide a "Dynamic Description Driven Mechanism based on Web DOM" to control "the UI Structure of Native Desktop Window Objects", developers can assemble "Composite Native Window Objects" in a way like "organizing HTML div elements within a webpage to express rich webpage content".
	All Large Language Model Techniques provide the friendliest support for Web Browsers, once desktop applications can be viewed as "Super Web Browser", this means that developers can deeply integrate LLM technology into the content ecosystem of ordinary desktop applications, even if they do not have the source code of the corresponding desktop application.  
## The Background and Vision of This Article
So far, developers have compiled countless 64-bit Desktop Applications based on .NET, C++/MFC and Win32 SDK, meanwhile there are countless Desktop Applications currently under development. When a desktop application completes native code compilation, its rigidity will dominate its runtime behavior. Specifically, the structure of the native desktop window is basically in a relatively fixed state at runtime, making it difficult for developers to reasonably adjust and extend it at runtime. When we face a compiled MFC Desktop Application or a compiled WinForm Desktop Application:

   ![image](https://github.com/user-attachments/assets/0a398eca-0e4a-4cdb-878d-a2cbced5bbed) ![image](https://github.com/user-attachments/assets/f43cbf8d-f306-45dc-bf5f-2da2c3e0a573)


If we wish to add a "Web Browser Tabs Group" to their Main Window Objects, or if we want to use Large Language Model Techniques such as ChatGPT to modify their Main Window Structures, as shown in the following figures: 

 ![image](https://github.com/user-attachments/assets/578aa446-58f5-42a1-88bf-417707691c06)

 ![image](https://github.com/user-attachments/assets/5413e8e7-f307-4cce-814e-18e3d72c33d1)


 
we will be powerless as we may not have the Source Code of these applications. 
If we have the possibility to discover the "dynamic description driven mechanism" that control the structure of native window objects, then for those desktop applications that already compiled or under development, whether it is based on Web technology or ChatGPT technology to adjust or modify the UI structure of native window objects, it will become the driving force for innovation in "dynamic application content", and we will enter a brand-new world of desktop applications. 
The vision of this article is to reveal that every 64-bit desktop application has webpage parsing capabilities beyond standard web browsers, thus having its own web content ecosystem, allowing developers to directly write any number of web pages for 64 bit desktop applications. All modern Large Language Model Techniques provide the friendliest support for Web Browsers, which undoubtedly lays an objective foundation for the deep integration of LLM technology into desktop applications. 
## AIGC Browser and Dynamically Integrate X Objects
AIGC Browser is an open-source Web Browser that views native window objects as "Description Driven Super HTML Elements", just like organizing sentences by using a group of tokens in NLP, AIGC Browser allows developers to assemble powerful "composite windows" based on Web DOM Technology starting from a "child window", this gives "Web DOM Technology" strong control force for the structure of native window objects, allowing Web Technology and Large Language Model Technology to be fully integrated into modern desktop software. 
If the executable file of your application is "exeName.exe", and the Initialize Webpage named "exeName.app.html" exists in the folder containing this executable file, then:
	For Desktop application that has been compiled, start "AIGC Browser" after this application is launched or start this application after "AIGC Browser" is launched.
	For Desktop application under development, add or modify no more than 5 lines of Native Code, allowing applications to directly activate their built-in AIGC Browser.
Regardless of which of the above two scenarios your application is in, AIGC browser will generate corresponding "Web DOM" elements for the native window objects of your application, and web technology will fully integrate into the content ecosystem of your application. your application will accommodate all the features of modern web browsers and will generate more and more web pages.
As shown in the following figure, with the help of hyperlinks in "exeName.app.html":

 ![image](https://github.com/user-attachments/assets/1f87d24e-b1f3-45aa-8424-116f6ce96018)

your desktop application will directly open any number of web pages, generating various browser windows:

 ![image](https://github.com/user-attachments/assets/175e2ca7-2979-4b8d-aa31-1b7b9b5a6f66)

This means that developers can directly write any number Webpages for 64-bit desktop applications, as if they were a modern browser themselves.
	When the "Whole Web Browser" directly becomes a part of the desktop application functional structure, UI components that comply with industry standards, such as .NET UI components, ActiveX Control, etc., will naturally become some kind of “Extended Web DOM elements”. Meanwhile, as all Large Language Model Technologies support Web Browsers, developers can directly use technologies such as ChatGPT in existing desktop applications. For example, ChatGPT's "multimodal input" technology can be used to directly manipulate native desktop windows and may add new UI elements to them.
	The "Composite Window" in desktop applications can treat the "Web Browser Window" as its "Dynamic Child Window", and further make this "Composite Window" a super web content portal. For example, an MFC Frame window as shown below 
 
 ![image](https://github.com/user-attachments/assets/8058e19c-7dca-47fb-89ea-d55502799263)

It can be used as a super browser window in a practical scenario:

 ![image](https://github.com/user-attachments/assets/a1218dd2-4f61-434f-9446-f4aff8bca5b6)

AIGC Browser provide a Highly Universal, Least Dependent and Source Code Independent Solution for Dynamically Integrating X objects into Ordinary 64-bit Desktop Applications, where "X objects" can be any one or a group of the following:
	Full-Function Chromium-Based Web Browser Subsystem.
	.NET Core/.NET Framework Engine.
	Any type of window object you are interested in, such as web pages, WinForms/User Control, MFC windows, or more general desktop window object types.
## Install and Build AIGC Browser
Developers can visit AIGCBrowser to obtain installation packages of AIGC Browser. After installation AIGC Browser, open "AIGCBrowser.sln" to obtain the Source Code of AIGC Browser and various examples: 

 ![image](https://github.com/user-attachments/assets/51142fe9-51da-4f38-b3da-58f260aa5c81)

After AIGC Browser is installed, developer will get a Visual Studio Solution "AIGCBrowser.sln", which includes the Source Code of AIGC Browser and various examples. 
If developers are familiar with C++, they can compile the "core components" of AIGC Browser directly. If developers need to have a deep understanding of the specific integration details of X-objects, they can refer to the "UniversePro" project. For the ".Net Part", they need to refer to the "CosmosPro" project. If you are a C# developer, you can ignore all the associated projects and use them directly. 
If developers are familiar with the Chromium Project and correctly installed the AIGC Browser installation package, they will obtain the "ChromiumSrcPatch" folder. Developers first need to obtain the Chromium Project Code Branch that matches AIGC Browser Version and ensure that this Branch is compiled properly. Then, they need to copy all subfolders contained in the ChromiumSrcPatch folder to this Code Branch and recompile the updated Chromium Code Branch to finish the compilation of the AIGC Browser Chromium subsystem. Due to the complexity of the code and the fact that compiling Chromium-Based C++ code typically takes 6-8 hours, most developers should not need to do this step and can directly focus on desktop application development.
## About manifest configuration
AIGC Browser may adjust the manifest configuration of the desktop applications to make them compatible with Win10, developers will see the following Messagebox : 
 ![image](https://github.com/user-attachments/assets/ee334d8e-90ff-4568-b8d3-b6397c98bda4)

The reason why this Messagebox appears is that there is no manifest configuration for "Win10 compatibility" in the desktop application source code. AIGC Browser will "fix" these missing configurations at the specific application startup stage.
## Using Visual Studio Wizard: 
Every desktop application generated by Visual Studio Wizard has a web development mechanism after compilation, although developers are completely unaware of its existence or have not deliberately prepared for its existence. For Desktop Applications generated by Visual Studio Wizards (WinForms, MFC Applications, etc.), developers can first provide a "Blank Initialization Page Without Any Content", and at runtime the AIGC Browser will generate an initialization page based on this page that matches the application type for developers to continue with subsequent work. 
We first use the "Visual Studio Wizard" to create a simplest "WinForm application WindowsFormsApp1", you need add a panel control with Dock property value "DockFill" on the WinForm object:

 ![image](https://github.com/user-attachments/assets/2c8b9a5e-136d-4290-b6cd-3071def92b9c)

Select 64-bit compilation, and all options are default. After compilation, we will obtain the executable file “WindowsFormsApp1.exe”. In the folder containing this executable file, provide a "blank" web page named "WindowsFormsApp1.app.html". Start AIGC Browser after starting this application, we will see the following runtime WinForm object, and a "Web Browser Window":

 ![image](https://github.com/user-attachments/assets/c01a3d95-c27c-4666-9c37-344bc47a1488)

We have noticed that the WinForm application here is just an ordinary desktop application, and its corresponding project does not contain any controls or code related to Web browser. However, in its runtime process, it does indeed create "Web Browser Window Objects". We see that "Web Browser Window Objects" can be a "component" of WinForm objects. If we replace the "C# Project" with the "MFC Project", we will obtain completely consistent experimental conclusions.
## Using Examples
All examples in "AIGCBrowser.sln" can directly activate the AIGC Browser based on native code, which means that after compiling these examples, once the developer provides the corresponding application's initialization web page, the relevant web development mechanism is also activated, and there is no need to launch the AIGC Browser separately. 
For .NET developers, they need to pay attention to 'AIGCBrowserSharedProject' Project Item in "AIGCBrowser.sln", it is a “Shared Project”, Once other .Net Projects reference this project, developers only need to replace 
Application.Run
with 
AIGC.AIGCApp.InitCosmos
to complete activating its web content ecosystem directly at runtime. 
For C++developers, we provide a pair of C++source files: 
aigc.h and aigc.cpp
these two files contain derived classes of the CWinApp(Ex) class for MFC applications and the CAtlExeModuleT class for ATL applications as well as necessary C++classes for Win32 SDK application. 
MFC developers only need to replace the base class of the Application class
from "CWinApp(Ex)" to "CAIGCApp(Ex)"
in their MFC applications, after recompiling the web content ecosystem of the application itself can be directly activate at runtime. For applications such as ATL and Win32 SDK, this solution provides a processing mechanism like MFC applications. For specific details, please refer to the specific examples in the solution. 
