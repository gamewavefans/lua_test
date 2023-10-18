#include "zlua_iframe.h"

// TODO
static int iframe_load(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    const char *s = luaL_checkstring(L, 2);
    int ret = 1;
    printf("\tcalled iframe.Load(%d, \"%s\") -> %d - UNIMPLEMENTED\n", i, s, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int iframe_unload(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled iframe.Unload(%d) - UNIMPLEMENTED\n", i);
    return 1;
}

// TODO
static int iframe_show(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled iframe.Show(%d) - UNIMPLEMENTED\n", i);
    return 1;
}

// TODO
static int iframe_show_predefined(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled iframe.ShowPredefined(%d) - UNIMPLEMENTED\n", i);
    return 1;
}

// TODO
static int iframe_clear(lua_State *L)
{
    printf("\tcalled iframe.Clear() - UNIMPLEMENTED\n");
    return 1;
}

static const luaL_reg iframelib[] = {
    {"Load", iframe_load},
    {"Unload", iframe_unload},
    {"Show", iframe_show},
    {"ShowPredefined", iframe_show_predefined},
    {"Clear", iframe_clear},
    {NULL, NULL}};

int luaopen_iframe(lua_State *L)
{
    printf("loaded iframe\n");
    luaL_openlib(L, "iframe", iframelib, 0);
    return 1;
}
