@echo off

IF "%1"=="" (
    echo Please provide existing folder name! Aborting...
    exit /b 1
)

IF not exist %1 (
    echo Please provide existing folder name! Aborting...
    exit /b 1
)

ECHO Running %1...

CALL compile.bat %1
