@echo off

set GAME_FILES_PATH=%~dp0..\game

set outDir=%~1

call "%~dp0lib\log.bat" "INFO" "Copying rules, lua scripts and creating log directory..."

:: rules files
if exist %outDir%RULES.INI del %outDir%RULES.INI
copy %GAME_FILES_PATH%\RULES.INI %outDir%

if exist %outDir%RULES-BASE.INI del %outDir%RULES-BASE.INI
copy %GAME_FILES_PATH%\RULES-BASE.INI %outDir%

:: test lua scripts
if exist %outDir%test.lua del %outDir%test.lua
copy %GAME_FILES_PATH%\lua\test.lua %outDir%

if exist %outDir%dump-rules.lua del %outDir%dump-rules.lua
copy %GAME_FILES_PATH%\lua\dump-rules.lua %outDir%

if exist %outDir%test-lua-rules.lua del %outDir%test-lua-rules.lua
copy %GAME_FILES_PATH%\lua\test-lua-rules.lua %outDir%

:: log folder
if exist %outDir%log rmdir /Q /S %outDir%log

mkdir %outDir%log

"%~dp0update-default-rules.bat"
