@ECHO OFF
if not exist .\build mkdir build
cd build
echo "compiling..."
g++ -c ../src/*.c
cd ..
g++ -o app.exe build/*.o
echo "operation completed!"