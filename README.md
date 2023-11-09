# Lua_test

Small mock test, this program loads mocked Gamewave Lua libraries and runs the bytecode, up to input loop.

Tested with "Click!".

## How to build

```bash
git submodules init # once

# cmake -B build . && cmake --build build && ./build/zlua_test
cmake -B build . && cmake --build build --target really-clean && cmake --build build && ./build/zlua_test
```
