@echo off

echo Compiling %1...
cd %1

if not exist build (
    mkdir build
)

if not exist app (
    mkdir app
)

cd build
del /q *.o

g++ -c ../source/*.cpp

cd ../app

if exist app del app

g++ -o app ../build/*.o

cd ..

rmdir /s /q build

echo Operation completed!
echo Starting th app...

cd app

start app.exe

cd ..






