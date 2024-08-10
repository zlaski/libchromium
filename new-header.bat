@echo off
pushd "%~dp0"

:: It appears that CMD.EXE automagically converts '/' to '\'
:: in path names!  Is nice!
set "HDR=%~f1"
set "HDR_DIR=%~dp1"
set "HDR_FNAME=%~nx1"

if "%HDR%" == "" (
    echo Error: header name must be specified
    exit /b 1
)

if exist "%HDR%" (
    echo Header "%HDR%" already exists
) else (
    mkdir "%HDR_DIR%" >nul 2>&1
    echo #pragma once >"%HDR_DIR%%HDR_FNAME%"
    if exist "%HDR_DIR%%HDR_FNAME%" (
        echo Header "%HDR%" created
    ) else (
        echo Header "%HDR%" could not be created
    )
)

popd