@echo off
cls
REM scons platform=windows target=template_debug
scons platform=windows custom_api_file=../extension_api_4_3.json target=template_debug
REM scons platform=windows target=template_release
scons platform=windows custom_api_file=../extension_api_4_3.json target=template_release