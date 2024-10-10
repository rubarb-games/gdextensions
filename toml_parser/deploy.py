#!/usr/bin/env python

import shutil

file_debug = 'toml_parser.windows.debug.x86_64.dll'
file_release = 'toml_parser.windows.release.x86_64.dll'
folder_target = '/Users/manda/Dev/share-wars/addons/toml_parser/'

shutil.copy2('bin/' + file_debug, folder_target + file_debug)
shutil.copy2('bin/' + file_release, folder_target + file_release)
