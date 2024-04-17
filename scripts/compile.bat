@ECHO OFF
if not exist .\build mkdir build
if not exist .\app mkdir app
cd build
echo "compiling..."
g++ -c ../src/source/*.c
cd ../app
g++ -o app.exe ../build/*.o
echo "operation completed!"
cd ..