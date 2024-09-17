@echo off

ECHO Compiling %1...
CD %1

IF not EXIST source (
    ECHO Source folder is not present! Aborting...
    CD ..
    exit /b 1
)

CD source

IF not EXIST *.cpp (
    ECHO Source files are not present! Aborting...
    CD ../..
    exit /b 1
)

CD ..

IF not EXIST build (
    mkdir build
)

IF not EXIST app (
    mkdir app
)

CD build

IF EXIST *.o (
    DEL /q *.o
)

g++ -c ../source/*.cpp

CD ../app

IF EXIST app.exe DEL app.exe

g++ -o app ../build/*.o

CD ..

RMDIR /s /q build

ECHO Operation completed!
ECHO Starting %1...

CD app

start app.exe

CD ../..

ECHO DONE!