@ECHO OFF
cd ..
mkdir build
cd build
echo "compiling..."
g++ -c ../src/*.c
cd ..
g++ -o app.exe build/*.o
cd ..
echo "operation completed!"