@ECHO OFF
echo "hello"
g++ -c functions.c interface.c main.c
g++ -o output.exe functions.o interface.o main.o