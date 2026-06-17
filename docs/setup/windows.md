# Windows Setup Guide

This document describes a reproducible setup for building and running this project on Windows.

## 1. Install Required Tools

1. Install MSYS2: https://www.msys2.org/
2. Open `MSYS2 UCRT64` terminal and run:

```bash
pacman -Syu
```

Close terminal if asked, reopen `MSYS2 UCRT64`, then run:

```bash
pacman -Su
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make mingw-w64-ucrt-x86_64-SDL2 mingw-w64-ucrt-x86_64-SDL2_ttf
```

3. Verify tools:

```bash
gcc --version
make --version
pkg-config --modversion sdl2
pkg-config --modversion SDL2_ttf
```

## 2. Build the App

From project root:

```bash
cd src
make
./game
```

## 3. Run Tests

From project root:

```bash
cd test
make
```

## 4. If You Prefer PowerShell

You can run builds from PowerShell, but you still need GNU toolchain and SDL2 dev libraries available in `PATH`.

Minimum requirements in `PATH`:

- `gcc`
- `make`
- SDL2 DLL search path (or copy DLLs next to executable)

## 5. Common Issues

- `make: command not found`: GNU Make is not installed or not in `PATH`.
- `SDL2/SDL.h: No such file or directory`: SDL2 development headers are missing.
- `cannot find -lSDL2_ttf`: SDL2_ttf development package is missing.
- Runtime DLL errors: ensure SDL2 runtime DLLs are discoverable.
