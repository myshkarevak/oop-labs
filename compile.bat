@echo off

ECHO Compiling %1...
CD %1

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

@pause

g++ -o app ../build/*.o

CD ..

RMDIR /s /q build

ECHO Operation completed!
ECHO Starting the app...

CD app

start app.exe

CD ../..
