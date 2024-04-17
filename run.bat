@ECHO OFF
if not exist .\app\app.exe call .\scripts\compile.bat
cd src/data
type title.txt
@pause
cd ../../app
call app.exe
cd ..