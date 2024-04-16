@ECHO OFF
if not exist .\app\app.exe call .\scripts\compile.bat
cd app
call app.exe