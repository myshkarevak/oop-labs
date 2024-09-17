@echo off

IF "%1"=="" (
    ECHO Please provide existing folder name! Aborting...
    exit /b 1
)

IF not exist %1 (
    ECHO Please provide existing folder name! Aborting...
    exit /b 1
)

ECHO Entering %1...

CALL compile.bat %1
