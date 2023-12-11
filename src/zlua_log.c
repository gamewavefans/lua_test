#include "zlua_log.h"

int current_level = 0;
const char *getLogLevelName(int level)
{
    static char buff[64];
    switch (level)
    {
    case 0:
        return "LOG_NONE";
    case 1:
        return "LOG_CRITICAL";
    case 2:
        return "LOG_IMPORTANT";
    case 3:
        return "LOG_NORMAL";
    case 4:
        return "LOG_VERBOSE";
    case 5:
        return "LOG_DEBUG";

    default:
        sprintf(buff, "LOG_UNKNOWN %d", level);
        return buff;
    }
}

static int log_log(lua_State *L)
{
    int level = luaL_checkint(L, 1);
    const char *line = luaL_checkstring(L, 2);
    // printf("\tcalled log.Log(%s, \"%s\") - UNIMPLEMENTED\n", getLogLevelName(level), line);

    if (level <= current_level)
    {
        printf("%s:\t%s", getLogLevelName(level), line);
    }
    else
    {
        printf("LOG_HIDDEN %s: %s", getLogLevelName(level), line);
    }
    return 0;
}

static int log_set_level(lua_State *L)
{
    int level = luaL_checkint(L, 1);
    current_level = level;
    printf("called log.SetLevel(%s) - UNIMPLEMENTED\n", getLogLevelName(level));
    return 0;
}

// TODO
static int log_set_module(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    int j = luaL_checkint(L, 2);
    printf("called log.SetModule(%d, %d) - UNIMPLEMENTED\n", i, j);
    return 0;
}

// TODO
static int log_print_raw(lua_State *L)
{
    const char *line = luaL_checkstring(L, 1);
    printf("called log.PrintRaw(\"%s\") - UNIMPLEMENTED\n", line);
    return 0;
}

// TODO
static int log_print_line(lua_State *L)
{
    const char *line = luaL_checkstring(L, 1);
    printf("called log.PrintLine(\"%s\") - UNIMPLEMENTED\n", line);
    return 0;
}

// TODO
static int log_debug_set_state(lua_State *L)
{
    int enabled = luaL_checkint(L, 1);
    printf("called log.DebugSetState(%d) - UNIMPLEMENTED\n", enabled);
    return 0;
}

static const luaL_reg loglib[] = {
    {"Log", log_log},
    {"SetLevel", log_set_level},
    {"SetModule", log_set_module},
    {"PrintRaw", log_print_raw},
    {"PrintLine", log_print_line},
    {"DebugSetState", log_debug_set_state},
    {NULL, NULL}};

int luaopen_log(lua_State *L)
{
    printf("loaded log\n");
    luaL_openlib(L, "log", loglib, 0);
    return 1;
}
