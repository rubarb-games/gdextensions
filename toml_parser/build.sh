#!/bin/bash
scons platform=macos custom_api_file=../extension_api_4_3.json target=template_debug
scons platform=macos custom_api_file=../extension_api_4_3.json target=template_release