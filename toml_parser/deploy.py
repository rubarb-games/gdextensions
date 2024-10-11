#!/usr/bin/env python

import shutil
import platform
import os
from pathlib import Path

folder_src = 'bin/'
folder_target = '/Dev/share-wars/addons/toml_parser/'

def deploy_mac(folder_name):
    src = folder_src + folder_name
    target = os.path.expanduser('~') + folder_target + folder_name
    files = os.listdir(src)
    Path(target).mkdir(parents=True, exist_ok=True)
    print('Deploy ', src, ' to: ', target)

    for fname in files:
        shutil.copy2(os.path.join(src, fname), target)

def deploy_win(file_name):
    src = folder_src + file_name
    target = os.path.expanduser('~') + folder_target + file_name
    print('Deploy ', src, ' to: ', target)
    shutil.copy2(src, target)

def deploy_addon():
    print('Deploy addon files')
    target = os.path.expanduser('~') + folder_target
    shutil.copy2('toml_parser.gdextension', target + 'toml_parser.gdextension')
    shutil.copy2('toml_parser.svg', target + 'toml_parser.svg')

match platform.system():
    case 'Linux' | 'Darwin':
        deploy_mac('toml_parser.macos.debug.universal.framework')
        deploy_mac('toml_parser.macos.release.universal.framework')
        deploy_addon()

    case 'Windows' | _:
        deploy_win('toml_parser.windows.debug.x86_64.dll')
        deploy_win('toml_parser.windows.release.x86_64.dll')
        deploy_addon()

