#include "zlua_movie.h"

// TODO
static int movie_load(lua_State *L)
{
    const char *s = luaL_checkstring(L, 1);
    int ret = 0;
    printf("\tcalled movie.Load(\"%s\") -> %d - UNIMPLEMENTED\n", s, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int movie_set_loop(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled movie.SetLoop(%d) - UNIMPLEMENTED\n", i);
    return 0;
}

// TODO
static int movie_play(lua_State *L)
{
    printf("\tcalled movie.Play()- UNIMPLEMENTED\n");
    return 0;
}

// TODO
static int movie_stop(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled movie.Stop(%d) - UNIMPLEMENTED\n", i);
    return 0;
}

// TODO
static int movie_resume(lua_State *L)
{
    printf("\tcalled movie.Resume()- UNIMPLEMENTED\n");
    return 0;
}

// TODO
static int movie_get_state(lua_State *L)
{
    // 0 - not finished?
    // 1 - finished playing?
    int ret = 1;
    printf("\tcalled movie.GetState() -> %d - UNIMPLEMENTED\n", ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

static const luaL_reg movielib[] = {
    {"Load", movie_load},
    {"SetLoop", movie_set_loop},
    {"Play", movie_play},
    {"Stop", movie_stop},
    {"Resume", movie_resume},
    {"GetState", movie_get_state},
    {NULL, NULL}};

int luaopen_movie(lua_State *L)
{
    printf("loaded movie\n");
    luaL_openlib(L, "movie", movielib, 0);
    return 1;
}
