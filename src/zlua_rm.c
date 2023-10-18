#include "zlua_rm.h"

int global = 1;
// TODO
static int rm_open_resource(lua_State *L)
{
    const char *s = luaL_checkstring(L, 1);
    int ret = global;
    global++;
    printf("\tcalled rm.OpenResource(\"%s\") -> %i - UNIMPLEMENTED\n", s, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int rm_close_resource(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled rm.CloseResource(%d) - UNIMPLEMENTED\n", i);
    return 1;
}

// TODO
static int rm_load_file(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    const char *s = luaL_checkstring(L, 2);
    int ret = 0;
    printf("\tcalled rm.LoadFile(%d, %s) -> %i, userData - UNIMPLEMENTED\n", i, s, ret);
    lua_pushnumber(L, (lua_Number)ret);
    // TODO push userdata
    return 1;
}

// TODO
static int rm_unload_file(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    // int j = luaL_checkint(L, 2);
    printf("\tcalled rm.UnloadFile(%d, userData) - UNIMPLEMENTED\n", i);
    return 1;
}

static const luaL_reg rmlib[] = {
    {"OpenResource", rm_open_resource},
    {"CloseResource", rm_close_resource},
    {"LoadFile", rm_load_file},
    {"UnloadFile", rm_unload_file},
    {NULL, NULL}};

int luaopen_rm(lua_State *L)
{
    printf("loaded rm\n");
    luaL_openlib(L, "rm", rmlib, 0);
    return 1;
}
