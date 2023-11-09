#include "zlua_audio.h"

int audio_number = 1;

// TODO
static int audio_load(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    const char *s = luaL_checkstring(L, 2);
    int ret = audio_number++;
    printf("\tcalled audio.Load(%d, \"%s\") -> %d - UNIMPLEMENTED\n", i, s, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int audio_unload(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled audio.Unload(%d) - UNIMPLEMENTED\n", i);
    return 0;
}

// TODO
static int audio_play(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    int j = luaL_checkint(L, 2);
    printf("\tcalled audio.Play(%d, %d) -> %d - UNIMPLEMENTED\n", i, j);
    return 0;
}

static const luaL_reg audiolib[] = {
    {"Load", audio_load},
    {"Unload", audio_unload},
    {"Play", audio_play},
    {NULL, NULL}};

int luaopen_audio(lua_State *L)
{
    printf("loaded audio\n");
    luaL_openlib(L, "audio", audiolib, 0);
    return 1;
}
