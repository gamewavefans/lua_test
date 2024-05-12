#include <stdlib.h>
#include <stdio.h>
// #include <stdbool.h>
#include <signal.h>
#include <pthread.h>

#include <sys/stat.h>

#include "../lua_gamewave/include/lauxlib.h"
#include "../lua_gamewave/include/lua.h"
#include "../lua_gamewave/include/lualib.h"

#include "zlua_gl.h"
#include "zlua_rm.h"
#include "zlua_time.h"
#include "zlua_log.h"
#include "zlua_pointer.h"
#include "zlua_zmath.h"
#include "zlua_input.h"
#include "zlua_iframe.h"
#include "zlua_engine.h"
#include "zlua_text.h"
#include "zlua_font.h"
#include "zlua_movie.h"
#include "zlua_audio.h"
// #include "zlua_spi.h"
// #include "zlua_uart.h"
#include "zlua_eeprom.h"
// #include "zlua_zfile.h"
// #include "zlua_exp_int.h"
#include "zlua_bit.h"

static const luaL_reg lualibs[] = {
    {"base", luaopen_base},
    {"table", luaopen_table},
    //{"io", luaopen_io},
    {"string", luaopen_string},
    //{"math", luaopen_math},
    {"debug", luaopen_debug},
    //{"loadlib", luaopen_loadlib},
    /* add your libraries here */
    {"gl", luaopen_gl},
    {"rm", luaopen_rm},
    {"time", luaopen_time},
    {"log", luaopen_log},
    {"pointer", luaopen_pointer},
    {"zmath", luaopen_zmath},
    {"input", luaopen_input},
    {"iframe", luaopen_iframe},
    {"engine", luaopen_engine},
    {"text", luaopen_text},
    {"font", luaopen_font},
    {"movie", luaopen_movie},
    {"audio", luaopen_audio},
    // {"spi", luaopen_spi},
    // {"uart", luaopen_uart},
    {"eeprom", luaopen_eeprom},
    // {"zfile", luaopen_zfile},
    // {"exp_int", luaopen_exp_int},
    {"bit", luaopen_bit},
    {NULL, NULL}};

static void openstdlibs(lua_State *l)
{
    const luaL_reg *lib = lualibs;
    for (; lib->func; lib++)
    {
        lib->func(l);     /* open library */
        lua_settop(l, 0); /* discard any results */
    }
}

// https://stackoverflow.com/questions/59091462/from-c-how-can-i-print-the-contents-of-the-lua-stack
static void dumpstack(lua_State *L)
{
    int top = lua_gettop(L);
    for (int i = 1; i <= top; i++)
    {
        printf("%d\t%s\t", i, lua_typename(L, lua_type(L, i)));
        switch (lua_type(L, i))
        {
        case LUA_TNUMBER:
            printf("%d\n", lua_tonumber(L, i));
            break;
        case LUA_TSTRING:
            printf("%s\n", lua_tostring(L, i));
            break;
        case LUA_TBOOLEAN:
            printf("%s\n", (lua_toboolean(L, i) ? "true" : "false"));
            break;
        case LUA_TNIL:
            printf("%s\n", "nil");
            break;
        default:
            printf("%p\n", lua_topointer(L, i));
            break;
        }
    }
}

_Atomic int sInterrupted = 0;
_Atomic bool shouldStop = false;
static void sSignalHandler(int signum)
{
    printf("\rInterrupt signal received. Please wait for graceful exit or press ctrl-c again to force kill\n");
    sInterrupted = 1;
    if (shouldStop)
    {
        exit(-1);
    }
    shouldStop = true;
}

void hook(lua_State *L, lua_Debug *ar)
{
    if (shouldStop)
    {
        lua_sethook(L, hook, LUA_MASKLINE, 0);
        luaL_error(L, "terminate");
    }
}

int main(int argc, char **argv)
{
    shouldStop = false;
    signal(SIGINT, sSignalHandler);
    signal(SIGTERM, sSignalHandler);

    if (argc != 2)
    {
        printf("Usage: zlua_test <filename.zbc>\n");
        exit(1);
    }
    const char *filename = argv[1];

    lua_State *L = lua_open(); /* opens Lua */
    openstdlibs(L);
    lua_sethook(L, hook, LUA_MASKCOUNT, 100);
    printf("Lua machine created\n");

    // lua_dofile(L, filename);

    // read game file
    struct stat info;
    if (stat(filename, &info) != 0)
    {
        printf("Can't access %s gamefile\n", filename);
        return -1;
    }

    char *content = malloc(info.st_size);
    if (content == NULL)
    {
        printf("Can't malloc space for %s gamefile\n", filename);
    }
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Can't open %s gamefile\n", filename);
    }
    /* Try to read a single block of info.st_size bytes */
    size_t blocks_read = fread(content, info.st_size, 1, fp);
    if (blocks_read != 1)
    {
        printf("Can't read %s gamefile\n", filename);
    }
    fclose(fp);

    // fun begins here
    int status = luaL_loadbuffer(L, content, info.st_size, filename);
    printf("%s loaded, status %d\n", filename, status);
    if (status == 0)
    {
        printf("running %s\n======\n\n", filename);
        status = lua_pcall(L, 0, -1, 0);
    }

    printf("\n======\npcall status %d\n", status);
    int err = lua_gettop(L);
    if (err != 0)
    {
        printf("Error %d during execution\n", err);
        printf("stacktrace:\n");
        dumpstack(L);
    }

    lua_close(L);
    return 0;
}
