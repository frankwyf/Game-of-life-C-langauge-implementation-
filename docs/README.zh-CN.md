# 康威生命游戏（C + SDL3）

这是一个个人开源作品集项目，基于早期课程作业重构而来。

## 项目简介

本项目使用 C 语言实现 Conway's Game of Life，并提供 SDL3 可视化界面。

核心能力：

- 支持从文件读取/保存棋盘状态
- 支持随机初始化和鼠标点击重建
- 支持设置行列、演化步数、动画延迟
- 支持游戏回放
- 使用 Unity 框架进行单元测试

## 目录结构

- `src/`: 主程序源码和运行资源
- `test/`: 单元测试与测试入口
- `unity/`: Unity 测试框架源码
- `docs/`: 文档（多语言）

## 快速开始

构建并运行主程序：

```bash
cd src
make
./game
```

运行测试：

```bash
cd test
make
```

## 系统依赖

- C 编译器（`gcc` 或 `clang`）
- `make`
- SDL3 开发库

Windows 详细安装步骤见：`docs/setup/windows.md`。

## 操作说明

- `Backspace`: 重新初始化当前棋盘
- `Enter`: 从当前状态回放
- `Esc`: 退出当前运行
- 设置模式中鼠标点击：切换细胞状态
