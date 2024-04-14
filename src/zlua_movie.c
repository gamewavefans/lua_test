#include "zlua_movie.h"

int states[2] = {1, 1, 0};
int counter = 0;
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
    // 0 - pause
    // 1 - unpause
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
    // 0 - not playing (finished/loading)
    // 1 - playing
    // Rand(1, 288) - huh?
    // Click - zapit_logo, nytric_logo, CLICK_TITLE_1-6 (rand), MAIN_MENU_LOOP
    // for the first 3 videos expects 1 -> 0 status change
    // for the loop only checks if it started playing

    int ret = states[counter];
    counter = (counter + 1) % (sizeof(states) / sizeof(int));
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
