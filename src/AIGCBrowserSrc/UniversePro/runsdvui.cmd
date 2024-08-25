cd /d "D:\WebRuntime\UniversePro" &msbuild "UniversePro.vcxproj" /t:sdvViewer /p:configuration="Release" /p:platform="x64" /p:SolutionDir="D:\Sample\Win32\BrowserApp" 
exit %errorlevel% 