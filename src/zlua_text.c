#include "zlua_text.h"

int overlay_id = 1;

static int text_render_simple(lua_State *L)
{
    const char *s = luaL_checkstring(L, 2);
    int font_id = luaL_checkint(L, 1);

    int ret = overlay_id++;
    printf("\tcalled text.RenderSimple(%d, %s)\n", font_id, s);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

static int text_render(lua_State *L)
{
    int top = lua_gettop(L);
    printf("Top: %d\n", top);
    const char *s = luaL_checkstring(L, 1);
    int font_id = luaL_checkint(L, 2);
    int k = luaL_checkint(L, 3);
    int l = luaL_checkint(L, 4);
    char buff[255] = "";
    for (int loop = 5; loop <= top; loop++)
    {
        int val = luaL_checkint(L, loop);
        char tmp[64] = "";
        sprintf(tmp, ", %d", val);
        strcat(buff, tmp);
    }
    int u = luaL_checkint(L, 5);
    int n = luaL_checkint(L, 6);
    int ret = overlay_id++;
    printf("\tcalled text.Render(%s, %d, %d, %d%s) -> %d\n", s, font_id, k, l, buff, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

static int text_get_overlay_id(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    int texture_id = overlay_id;
    printf("\tcalled text.GetOverlayId(%d) -> %d\n", i, texture_id);
    lua_pushnumber(L, (lua_Number)texture_id);
    return 1;
}

static int text_remove(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled text.Remove(%d)\n", i);
    return 0;
}

static const luaL_reg textlib[] = {
    {"RenderSimple", text_render_simple},
    {"Render", text_render},
    {"Remove", text_remove},
    {"GetOverlayId", text_get_overlay_id},

    {NULL, NULL}};

int luaopen_text(lua_State *L)
{
    printf("loaded text\n");
    luaL_openlib(L, "text", textlib, 0);
    return 1;
}
