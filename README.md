# Conway's Game of Life (C + SDL3)

A personal open-source portfolio project based on an earlier coursework implementation of Conway's Game of Life.

This repository contains a native C implementation with:

- interactive visualization using SDL3
- keyboard and mouse controls for runtime editing and replay
- persistence via `Game.txt`
- unit tests using Unity

## Language Docs

- English (this file)
- Chinese: `docs/README.zh-CN.md`
- Japanese: `docs/README.ja.md`

## Features

- configurable board size, steps, and animation delay
- start from saved state or create a random state
- click to toggle cells during setup
- replay support and progress window (alive/dead counts, timestamp)

## Project Structure

- `src/`: application source code and runtime assets
- `test/`: unit tests and test runners
- `unity/`: Unity test framework source
- `docs/`: multilingual and maintenance documentation

## Build Requirements

- C compiler (`gcc` or `clang`)
- `make` (GNU Make compatible)
- SDL3 development libraries

Detailed setup instructions are in `docs/setup/windows.md`.

## Quick Start

Build and run the game:

```bash
cd src
mingw32-make
./game
```

Build and run tests:

```bash
cd test
mingw32-make
```

For CI-oriented local validation, run:

```bash
cd test
mingw32-make ci
```

## Controls

- `Backspace`: re-initialize the current board
- `Enter`: replay from current state
- `Esc`: quit current run
- Mouse click in setup mode: toggle cell state

## Notes

- The current implementation uses global state headers for simplicity and historical compatibility.
- The program writes/reads `src/Game.txt` as the state file.

## Contributing

Please read `CONTRIBUTING.md` before opening a pull request.

## Security

If you find a vulnerability, please follow `SECURITY.md`.

## CI/CD

GitHub Actions workflow is provided in `.github/workflows/ci.yml`:

- Linux job: build + run Unity test binaries
- Windows job: build + run Unity test binaries in MSYS2 UCRT64

## License

This project is licensed under the MIT License. See `LICENSE`.
