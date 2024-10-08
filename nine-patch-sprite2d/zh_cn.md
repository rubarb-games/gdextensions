[English](README.md) | **中文版（当前页面）**
# Godot 4 NinePatchSprite2D (1.0版本)
适用于Godot 4的GDExtension，增添`NinePatchSprite2D`节点类，运作方式类似于`NinePatch`，同时保留了部分`Sprite2D`的功能在内。

# 安装
1. 将本工程克隆到任意文件夹下，复制其中的`gdextension`文件夹
2. 打开你的游戏工程文件所在目录（即project.godot文件所在目录）
3. 将已复制好的`gdextension`文件夹粘贴在该目录下

# 基本介绍
`NinePatchSprite2D`类结合了`NinePatch`和`Sprite2D`这两个类的特点，集二者之大成，同时也对来自这二者的一些特性进行了部分适应性修改。开发者可以在使用`NinePatchSprite2D`时体验到与使用`Sprite2D`时一样的操作体验，同时也支持开发者将贴图分成九块，通过设置X轴向和Y轴向的拉伸模式来设置图块的拉伸，还可以通过设置边距来确定边界图块。  
与此同时，作为一个类`Sprite2D`类型，`NinePatchSprite2D`也同样为开发者提供了帧系统，以帮助开发者们轻松制作逐帧动画，开发者们也无需完全将精力浪费在修改取样矩形区域的偏移上了，十分灵活方便，开箱即用。

# 使用说明
见本仓库**Wiki**页面

# 安装需求
## 支持的Godot版本
4.2及以上

## 支持的开发系统及平台
Windows 10, 11 x86-64
