@echo off

IF "%1"=="" (
    echo Please provide existing folder name! Aborting...
    exit /b 1
)

IF not exist %1 (
    echo Please provide existing folder name! Aborting...
    exit /b 1
)

echo Running %1...

call compile.bat %1
