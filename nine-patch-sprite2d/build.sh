#!/bin/bash
scons platform=macos custom_api_file=extension_api.json target=template_debug
scons platform=macos custom_api_file=extension_api.json target=template_release