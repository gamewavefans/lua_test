#include "zlua_input.h"

// TODO - map this to keyboard
// f1- f4 abcd
// nimbers
// arrows
// select enter
static int input_get_key(lua_State *L)
{
    // timestamp, remote, keyid?
    int key_id = 0;    //(int)time(NULL);
    int remote_id = 1; // ?
    int timestamp_id = (int)time(NULL);

    printf("called input.GetKey() -> %d, %d, %d - UNIMPLEMENTED\n", key_id, remote_id, timestamp_id);
    lua_pushnumber(L, (lua_Number)key_id);
    lua_pushnumber(L, (lua_Number)remote_id);
    lua_pushnumber(L, (lua_Number)timestamp_id);
    // TODO we've reached interactive loop, I can't really mock much more
    // printf("we've reached interactive loop, I can't really mock much more code\n");
    // exit(1);
    // NO_REMOTE        - 255 / -1?
    // REMOTE_RED       - 1
    // REMOTE_YELLOW    - 2
    // REMOTE_BLUE      - 3
    // REMOTE_GREEN     - 4
    // REMOTE_PURPLE    - 5
    // REMOTE_ORANGE    - 6

    // NO_KEY           - 255
    // KEY_0            - 0
    // KEY_1            - 1
    // KEY_2            - 2
    // KEY_3            - 3
    // KEY_4            - 4
    // KEY_5            - 5
    // KEY_6            - 6
    // KEY_7            - 7
    // KEY_8            - 8
    // KEY_9            - 9
    // KEY_UP           - 10
    // KEY_DOWN         - 11
    // KEY_RIGHT        - 12
    // KEY_LEFT         - 13
    // KEY_SELECT       - 14
    // KEY_DVD_MENU     - 15
    // KEY_A            - 16
    // KEY_B            - 17
    // KEY_C            - 18
    // KEY_D            - 19
    // KEY_GAME_MENU    - 20

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
