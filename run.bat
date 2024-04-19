@ECHO OFF
if not exist .\app\app.exe call .\scripts\compile.bat
cd src/data
cls
type title.txt
@pause
cd ../../app
call app.exe
cd ..