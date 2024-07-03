# All Native Window Objects Are Super Web DHTML Elements
## Every 64-bit Desktop Application has its own Web Ecosystem
When developers face a Web Browser, they may be naturally writing many web pages for it. We must admit that a web browser is also a desktop application developed by native code, with its own executable file. Desktop Application Developers were completely unaware that once they finish to compile the "Native Code" of 64-bit desktop applications, they have also established a "Web Content Ecological Mechanism" similar to that of a web browser for the corresponding applications simultaneously, this means that even if you do not have the Source Code of the desktop application, or you do not need to recompile and adjust the native code of the application, you can completely regard this desktop application as a "Super Web Browser" and write any number of web pages directly for it.
AIGC Browser is a free Web Browser with a unique core feature of revealing the symbiotic effect and the interweaving effect between "Web Code" and "Native Code" in Desktop Applications. Each 64-bit Desktop Application Process has its own "Built-in Web Browser", if the executable file of a Desktop Application is "exeName.exe", once the Initialize web page named "exeName.app.html" exists in the folder containing this executable file, starting "AIGC Browser" after running this application, its "Built-in Web Browser" will be activated, and "Native Window Objects" in this application will become "Super Web DOM Elements".
## Browser Windows Are Everywhere
Any 64-bit desktop application can create an unlimited number of Web Browser Window Objects at runtime. We first use the "Visual Studio Wizard" to create a simplest "WinForm application WindowsFormsApp1":

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/5e66bda1-a348-4595-974d-f47129d55f9d)

Select 64-bit compilation, and all options are default. After compilation, we will obtain the executable file “WindowsFormsApp1.exe”. In the folder containing this executable file, provide a "blank" web page named "WindowsFormsApp1.app.html". Start AIGC Browser after starting this application, we will see the following runtime WinForm object, and a "Web Browser Window":

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/5cc72e33-1c9e-405d-bc61-47edf485375c)
  
If you click the web page button in the Browser Window, you will see a "significant" change occurring in the Browser Window:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/029dc1e6-2903-437b-ae9b-35c43247804a)
 
If further, assuming you can add a panel control with Dock property value "DockFill" on the WinForm object:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/77d9c2d8-ede7-409e-9ce1-f1f6da087350)
 
recompile this WinForm application, and run this WinForm Application, then you will see a new runtime WinForm object:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/937c3cc7-2e7d-4bc3-b29c-870707ed2a35)
 
We have noticed that the WinForm application here is just an ordinary desktop application, and its corresponding project does not contain any controls or code related to Web browser. However, in its runtime process, it does indeed create "Web Browser Window Objects". In particular, we see that "Web Browser Window Objects" can be a "component" of WinForm objects. If we replace the "C# Project" with the "MFC Project", we will obtain completely consistent experimental conclusions.
## Web Pages as "Native Window Objects Manufacturing Factories" 
So far, there is no good way to enable developers to dynamically and freely create native window objects using native code, as shown in the following figure, if developers attempt to dynamically create the window object seen here entirely based on native code technology, there is no doubt that they will face significant technical challenges:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/816f3fda-89bc-4a93-ab26-587dc0434324)
 
A key feature of "Visual Designers" is the ability to provide an intuitive creation mechanism for a class of expressive window objects. Because each Visual Designer is directly associated with a specific language environment, this determines that each Designer has its inherent limitations, such as the WinForm designer, which is basically limited to the category of components that .Net Controls belong to. 
	Once the built-in browser of the desktop application is activated, the desktop application will have a "Super Web DOM" structure, which brings about a "Super Native Window Manufacturing Engine" for desktop applications, this means that in desktop applications, developers can organize various types of "window objects" based on web technology to synthesize powerful "Native Desktop Windows", just like organizing "div" elements in standard web pages.
In fact, the mechanism of the "Web Content Ecological" is an inherent attribute of executable files in desktop application software. When developers develop executable files for desktop applications, it means the establishment of ecosystem mechanisms, which is largely reflected in the existence of a web-based "native window object super manufacturing engine" for desktop applications. the "Web Content Ecological Mechanism" should be a key feature of desktop application executable files, but due to a special historical stage, this feature first appeared in desktop web browsers. If we delve deeper into "native desktop window objects", we will find that in most cases, child windows in desktop window objects act as a type of "placeholder", because they are "placeholders", so they can be replaced by more expressive window objects at runtime. In fact, there has always been a lack of a "powerful desktop window description mechanism" in the Web DOM description rules. If Web DOM has such descriptive rules, then web pages become a powerful "creation mechanism" for desktop native window objects. Once such a web-based window manufacturing mechanism becomes an inherent feature of desktop applications, the web potential of desktop window objects will be fully unleashed. The desktop window we see below is actually the result of "Web DOM Description", which can be fully reflected in any web page:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/b15a9d61-193d-460f-a0aa-45f8d2bd4bf1)
 
Every software developer needs to face an unprecedented new mechanism, that is, every desktop application has a "native window super manufacturing engine", this engine enables the complete "Standard Web Browser UI System" and the complete ".NET Desktop UI System" become default parts of a desktop application, developer can provide any number of WinForm object descriptions and browser window object descriptions in web pages, at runtime, these description structures will act as "Independent UI Windows" or directly replace a "child window" of some native UI window, this replacement behavior is the "dynamic behavior" by using "Child Windows" as "Placeholders". Now, you can design a WinForm control as follows:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/79e3325b-eec6-4ae9-a8ed-5ef1ef5249e3)
 
then based on the web description rules, you can place this object at the center position of an “MFC MDI application” directly, and then dock the “Multi-Document Client Area” of this MFC application to the right of the sub-control of this User control designed here, as shown in the following figure:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/50cc2a31-10e9-454d-a760-56f277bfa95d)
 
## "Native Window Objects" as "Super Web DOM Elements".
With the help of Web description driven technology, Desktop software development is about to enter a brand-new stage soon: at different moments during runtime, any native window object may be surrounded by one or more different types of other native window objects, for example, we can design an MFC Form View as follows: 

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/121d97e4-4eeb-4786-b653-a79d0d73c0d4)
 
and then at runtime, we can allow a "Standard Web Browser Window" to be displayed on the periphery of this "MFC Form View":

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/abbd20d8-84b5-4d52-9d22-dd12fec76e19)
 
For developers, they need to clearly recognize that each native window object will generates a "Content Field" around it at runtime, which is very similar to electric fields, gravitational fields, and so on in the field of physics. The existence of the "Content Field" indicates that the periphery of each native window object is surrounded by an "infinite dimensional content structure" (the various window types we are familiar with, such as ActiveX Control, .Net Control, WinForm, MFC CWnd, and so on, are ordinary members of this structure), which poses a huge challenge to the cognitive system of desktop applications that developers have already established.
In the surrounding space of native window objects, developers can render one or more other types of window objects at different times based on completely different layout structures described by describable strategies (such as Web DOM descriptions). This means that the periphery of the native window object should be a "all encompassing" dynamic world composed of various types of window objects, just like in different situations, there may be different numbers of others around each person. When developers can perceive the "Content Field" of a native window, they will clearly see that around this window object is actually a new content world, and various types of other window objects will be presented in various states. In the WinForms Object shown below, its orange panel control is a typical .NET control, usually we cannot directly see the “Content Field” around this panel object:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/411e026c-4f0b-4038-b453-f177c60114bd)
 
When we provide the “Initialization Web Page” for this application and launch AIGC Browser, we will see a "wrap around structure" around this panel that cannot be presented during the design time of this WinForm object, as shown in the following figure:

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/ec2f1b95-c41d-4e37-9baa-716344d7d0a9)
 
the “Content Field” around this panel object enable developers to extract one or more objects from its "infinite dimensional content structure", and then generate a "layout structure" based on Web DOM descriptions, according to this layout description, the extracted objects will be presented around it.
In fact, the peripheral spatial structure of a native window object is controlled by web description rules, this determines that each native window object is a "Super DHTML element" of the built-in web browser of its application, at the same time, it also produce a huge impact on those well-known "Visual Designers" (such as WinForm Designer, MFC Dialog Designer, etc.). We take the WinForm Designer as an example，in the Visual Studio IDE, by using WinForm Designer, we can easily insert a control into a "WinForm" Object, we have shaped such a mindset: once application compiled, the design result produced by the "Visual Designers" will basically not change much at runtime. If we have understanded the symbiosis between Web technology and native code technology deeply, the situation will be completely different, in fact, the biggest limitation of WinForm Designer is that：1. it is only limited to design time; 2. only applicable to NET development. If developers recognize that desktop window objects themselves have a "content field," then they have the ability to view any WinForm object or DotNet control as a "web appendage" to a "normal window object" , this means that, with the help of Web DOM's descriptive rules, such DotNET UI objects can be presented inside or outside any window object at any time, the control in the traditional WinForm Designer may be just a "Placeholder", and its runtime state will be in great contrast with its design time state. 
## Using Visual Studio Wizard
For Desktop Applications generated by Visual Studio Wizards (WinForms, MFC Applications, etc.), developers can first provide a blank initialization page without any content, at runtime, the AIGC Browser will generate an initialization page based on this page that matches the application type for developers to continue with subsequent work.
The "MFC CWnd Class" and the ".NET Control Object" are the most classic objects in desktop applications. When the software architect knows that other types of native window objects are the "surrounding or decoration" of these two types of objects, the application can control a group of other types of windows around these two types of objects in a descriptive and Web driven way at any time during the software runtime, which will provide a new design pattern for the architecture designer from the perspective of design.
We know that in all standard web browsers, WebView is its unique content carrier, and all web content corresponding to URLs is displayed in WebView without exception. When we consider a standard web browser as a special type of desktop application and then discuss the "Built-in Web Browser" of General Desktop Applications in a broader sense, the privileged position of WebView may no longer exist, this means that for specific Desktop Applications, the Native Window Object Types included in the application can completely replace the privileges and central position of WebView in its built-in browser, for developers, once they realize that WebView is no longer the sole content carrier in browser windows, and other window objects are also content carriers, the privileged position of WebView will be completely shaken. In the browser window displayed below, ".NET controls" occupy the "central position" that WebView once had, and the content in WebView becomes "auxiliary content":

![image](https://github.com/AIGCEra/AIGCSDK/assets/26355688/63be233b-2a72-4b3e-ac73-445bad6b6fdb)
 
