@echo off

cd "%~dp0.."

call "%~dp0build.bat"

set MOD_PATH=%USERPROFILE%\Documents\CnCRemastered\Mods\Tiberian_Dawn\nco
set CNC_PATH=C:\Program Files (x86)\Steam\steamapps\common\CnCRemastered

call "%~dp0lib\log.bat" "INFO" "Deploying mod files to path: %MOD_PATH%"

if exist "%MOD_PATH%" (
  rmdir /q /s "%MOD_PATH%"
)

mkdir "%MOD_PATH%"
mkdir "%MOD_PATH%\Data"

copy "game\ccmod.json" "%MOD_PATH%\ccmod.json"
copy "bin\Win32\TiberianDawn.dll" "%MOD_PATH%\Data"

call "%~dp0lib\log.bat" "INFO" "Deploying RULES.INI and tiberian_dawn.bat to path: %CNC_PATH%"

if exist "%CNC_PATH%\RULES.INI" (
  del "%CNC_PATH%\RULES.INI"
)

if exist "%CNC_PATH%\tiberian_dawn.bat" (
  del "%CNC_PATH%\tiberian_dawn.bat"
)

copy "game\cfg\RULES.INI" "%CNC_PATH%"
copy "game\scripts\tiberian_dawn.bat" "%CNC_PATH%"
