# emu-6502

A MOS 6502 assembler and emulator

## How to build

```sh
autoreconf --install
mkdir build
cd build
../configure
make
```

It's useful to have a `compile_commands.json` for use with `clangd`, which can be generated by

```sh
make clean
bear -- make
```

## How to clean

```sh
# Clean the build directory
make clean
# Clean up the generated autotools files
git clean -f -X -d
```

## How to test

```sh
make check
# test output saved in tests/*.log for each test
```
