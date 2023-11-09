#include "zlua_eeprom.h"

// {"SaveGameToNewSlot", eeprom_save_game_to_new_slot},
// {"GetSaveNameByID", eeprom_get_save_name_by_id},

// TODO this should return UserData of some kind
static int eeprom_load_save_by_id(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    int ret = 0;
    int retbool = 0;
    printf("\tcalled eeprom.LoadSaveByID(%d) -> %d, %s - UNIMPLEMENTED\n", i, ret, retbool ? "true" : "false");
    lua_pushnumber(L, ret);
    lua_pushboolean(L, retbool);
    return 2;
}

// {"UnloadData", eeprom_unload_data},
// {"SaveGameToExistingSlot", eeprom_save_game_to_existing_slot},

// TODO
static int eeprom_enumerate_game_saves_by_id(lua_State *L)
{
    int i = luaL_checkint(L, 1);
    int ret = 0;
    int retbool = 0;
    printf("\tcalled eeprom.EnumerateGameSavesByID(%d) -> %d, %s - UNIMPLEMENTED\n", i, ret, retbool ? "true" : "false");
    lua_pushnumber(L, ret);
    lua_pushboolean(L, retbool);
    return 2;
}

// TODO
static int eeprom_enumerate_game_saves_by_name(lua_State *L)
{
    const char *s = luaL_checkstring(L, 1);
    int ret = 0;
    int retbool = 0;
    printf("\tcalled eeprom.EnumerateGameSavesByName(\"%s\") -> %d, %s - UNIMPLEMENTED\n", s, ret, retbool ? "true" : "false");
    lua_pushnumber(L, ret);
    lua_pushboolean(L, retbool);
    return 2;
}

// {"Format", eeprom_format},
// {"CorruptFlash", eeprom_corrupt_flash},
// {"CheckFlashIntegrity", eeprom_check_flash_integrity},

static const luaL_reg eepromlib[] = {
    // {"SaveGameToNewSlot", eeprom_save_game_to_new_slot},
    // {"GetSaveNameByID", eeprom_get_save_name_by_id},
    {"LoadSaveByID", eeprom_load_save_by_id},
    // {"UnloadData", eeprom_unload_data},
    // {"SaveGameToExistingSlot", eeprom_save_game_to_existing_slot},
    // {"EnumerateGameSavesByID", eeprom_enumerate_game_saves_by_id},
    {"EnumerateGameSavesByName", eeprom_enumerate_game_saves_by_name},
    // {"Format", eeprom_format},
    // {"CorruptFlash", eeprom_corrupt_flash},
    // {"CheckFlashIntegrity", eeprom_check_flash_integrity},
    {NULL, NULL}};

int luaopen_eeprom(lua_State *L)
{
    printf("loaded eeprom\n");
    luaL_openlib(L, "eeprom", eepromlib, 0);
    return 1;
}
