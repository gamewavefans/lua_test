#include "zlua_rm.h"

// TODO
static int zmath_mod(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    int j = luaL_checkint(L, 2);
    int ret = 0;
    printf("\tcalled zmath.Mod(%d, %d) -> %d - UNIMPLEMENTED\n", i, j, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int zmath_rand(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    int j = luaL_checkint(L, 2);
    int ret = 0;
    printf("\tcalled zmath.Rand(%d, %d) -> %d - UNIMPLEMENTED\n", i, j, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int zmath_rand_seed(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled zmath.RandSeed(%d) - UNIMPLEMENTED\n", i);
    return 0;
}

static const luaL_reg zmathlib[] = {
    {"Mod", zmath_mod},
    {"Rand", zmath_rand},
    {"RandSeed", zmath_rand_seed},
    {NULL, NULL}};

int luaopen_zmath(lua_State *L)
{
    printf("loaded zmath\n");
    luaL_openlib(L, "zmath", zmathlib, 0);
    return 1;
}
