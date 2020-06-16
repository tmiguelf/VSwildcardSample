@echo off
::Don't have the patient to setup CI on this project
::so just run this script on the console manually and pretend its automated

set "PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin;%PATH%"
msbuild.exe /t:Build /p:Configuration=Release "%~dp0/Projects/Solution.sln" -maxcpucount
%~dp0/Runtime/x64_Release/SampleProjectTest.exe