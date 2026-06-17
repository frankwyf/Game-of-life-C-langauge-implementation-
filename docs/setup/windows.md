# Windows Setup Guide

This document describes a reproducible setup for building and running this project on Windows with MinGW and SDL3.

## 1. Install Required Tools

1. Install MSYS2: https://www.msys2.org/
2. Open `MSYS2 UCRT64` terminal and run:

```bash
pacman -Syu
```

Close terminal if asked, reopen `MSYS2 UCRT64`, then run:

```bash
pacman -Su
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-SDL3 pkgconf
```

3. Verify tools:

```bash
gcc --version
mingw32-make --version
pkg-config --modversion sdl3
```

## 2. Build the App

From project root:

```bash
cd src
mingw32-make
./game
```

## 3. Run Tests

From project root:

```bash
cd test
mingw32-make
```

## 4. If You Prefer PowerShell

You can run builds from PowerShell, but you still need GNU toolchain and SDL3 dev libraries available in `PATH`.

Minimum requirements in `PATH`:

- `gcc`
- `mingw32-make`
- SDL3 DLL search path (or copy DLLs next to executable)

## 5. Common Issues

- `mingw32-make: command not found`: MinGW Make is not installed or not in `PATH`.
- `SDL3/SDL.h: No such file or directory`: SDL3 development headers are missing in the toolchain include path.
- `cannot find -lSDL3`: SDL3 import library is missing in the toolchain lib path.
- Runtime DLL errors: ensure SDL3 runtime DLLs are discoverable.
