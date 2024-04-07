@ECHO OFF
mkdir build
cd build
echo "compiling..."
g++ -c ../src/*.c
cd ..
g++ -o app.exe build/*.o
echo "operation completed!"