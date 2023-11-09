EVERYTHING IS HARDCODED

```bash
git submodules init # once

# cmake -B build . && cmake --build build && ./build/zlua_test
cmake -B build . && cmake --build build --target really-clean && cmake --build build && ./build/zlua_test
```
