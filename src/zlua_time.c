#include "zlua_time.h"

// TODO, for now return unix time
static int time_get_real_time(lua_State *L)
{
    int ret = (int)time(NULL);
    printf("\tcalled time.GetRealTime() -> %d - UNIMPLEMENTED\n", ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// TODO
static int time_sleep(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    printf("\tcalled time.Sleep(%d) - UNIMPLEMENTED\n", i);
    usleep(i * 1000);
    return 0;
}

static const luaL_reg timelib[] = {
    {"GetRealTime", time_get_real_time},
    {"Sleep", time_sleep},
    {NULL, NULL}};

int luaopen_time(lua_State *L)
{
    printf("loaded time\n");
    luaL_openlib(L, "time", timelib, 0);
    return 1;
}
