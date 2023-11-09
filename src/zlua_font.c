#include "zlua_font.h"

int font_number = 1;

// TODO
static int font_load(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    const char *s = luaL_checkstring(L, 2);
    int ret = font_number++;
    printf("\tcalled font.Load(%d, \"%s\") -> %d - UNIMPLEMENTED\n", i, s, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int font_free(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled font.Free(%d) - UNIMPLEMENTED\n", i);
    return 0;
}

// TODO
static int font_get_builting_font_id(lua_State *L)
{
    int ret = font_number++;
    printf("\tcalled font.GetBuiltinFontID() -> %d - UNIMPLEMENTED\n", ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

static const luaL_reg fontlib[] = {
    {"Load", font_load},
    {"Free", font_free},
    {"GetBuiltinFontID", font_get_builting_font_id},
    {NULL, NULL}};

int luaopen_font(lua_State *L)
{
    printf("loaded font\n");
    luaL_openlib(L, "font", fontlib, 0);
    return 1;
}
