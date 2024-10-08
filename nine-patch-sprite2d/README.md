**English(Current)** | [中文版](zh_cn.md)
# Godot 4 NinePatchSprite2D (v1.0)
A GDExtension that adds `NinePatchSprite2D` which works similarly to `NinePatch` while maintains some functions of `Sprite2D`.

# How to Install?
1. Clone the repo to any folders and copy the `gdextension` folder
2. Go into the directory of your project where a `project.godot` exists
3. Paste the folder you just copied to the directory

# What is `NinePatchSprite2D`?
A `NinePatchSprite2D` class is the class that mixed `NinePatch` with `Sprite2D` together, with critical features extracted from the two classes and arranged in this one. `NinePatchSprite2D` provides a `Sprite2D`-like implementation; however, it allows you to make the 2d sprite nine patches, or nine different tiles. You can set the stretch mode of both X-axis and Y-axis of a nine patch sprite, as well as its margin that defines which are border of the sprite patches.
Meanwhile, as a `Sprite2D`-alike class, `NinePatchSprite2D` also provides frames system that helps developers with animations, so that they don't need to take total care of the offset of the rect that samples the texture, which is more flexible and convenience than `NinePatch`, and useful out of the box.
 
# How to Use?
See the **Wiki** in this repo.

# Requirements
## Supported Godot Versions
4.2 or above
## Supported developing platforms
Windows 10, 11 x86-64
