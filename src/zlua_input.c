#include "zlua_input.h"

// TODO
static int input_get_key(lua_State *L)
{
    // timestamp, remote, keyid?
    int ret = (int)time(NULL);
    int ret2 = 1;
    int ret3 = 14;
    printf("called input.GetKey() -> %d, %d, %d - UNIMPLEMENTED\n", ret, ret2, ret3);
    lua_pushnumber(L, (lua_Number)ret);
    lua_pushnumber(L, (lua_Number)ret2);
    lua_pushnumber(L, (lua_Number)ret3);
    // TODO we've reached interactive loop, I can't really mock much more
    // printf("we've reached interactive loop, I can't really mock much more code\n");
    // exit(1);

    return 3;
}

static const luaL_reg inputlib[] = {
    // {"ClearKeyQueue", input_clear_key_queue},
    {"GetKey", input_get_key},
    // {"WaitForKey", input_wait_for_key},
    // {"EnableRemotes", input_enable_remotes},
    // {"DisableRemotes", input_disable_remotes},
    // {"SetMode", input_set_mode},
    // {"GetMode", input_get_mode},
    // {"SetQueueSize", input_set_queue_size},
    // {"SetRandomKeysTable", input_set_random_keys_table},
    {NULL, NULL}};

int luaopen_input(lua_State *L)
{
    printf("loaded input\n");
    luaL_openlib(L, "input", inputlib, 0);
    return 1;
}
