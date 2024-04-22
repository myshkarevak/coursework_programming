#!/bin/bash
[ -d build ] || mkdir build;
[ -d app ] || mkdir app
echo "compiling..."
cd build
rm -r -f *.o
g++ -c ../src/source/*.c
cd ../app
rm -r -f app
g++ -o app ../build/*.o
cd ..
rm -r -f build
echo "operation completed!"