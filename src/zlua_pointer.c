#include "zlua_pointer.h"

// {"CreateUserData", pointer_create_user_data },
// {"DestroyUserData", pointer_destory_user_data },
// {"ToString", pointer_to_string },
// {"ToStringRange", pointer_to_string_range },
// {"FromString", pointer_from_string },
// {"GetIndex", pointer_get_index },
// {"GetU32MSB", pointer_get_u32_msb },

// TODO d should be UserData
static int pointer_get_u32_msb(lua_State *L)
{
    int d = luaL_checkint(L, 1);
    int i = luaL_checkint(L, 2);
    int ret = 4321;
    printf("\tcalled pointer.GetU32MSB(%d, %d) -> %d - UNIMPLEMENTED\n", d, i, ret);
    lua_pushnumber(L, (lua_Number)ret);
    return 1;
}

// {"SetU32MSB", pointer_set_u32_msb },
// {"GetU32LSB", pointer_get_u32_lsb },
// {"SetU32LSB", pointer_set_u32_lsb },
// {"ByteToAscii", pointer_byte_to_ascii },
// {"AsciiToByte", pointer_ascii_to_byte },

static const luaL_reg pointerlib[] = {
    // {"CreateUserData", pointer_create_user_data},
    // {"DestroyUserData", pointer_destory_user_data},
    // {"ToString", pointer_to_string},
    // {"ToStringRange", pointer_to_string_range},
    // {"FromString", pointer_from_string},
    // {"GetIndex", pointer_get_index},
    {"GetU32MSB", pointer_get_u32_msb},
    // {"SetU32MSB", pointer_set_u32_msb},
    // {"GetU32LSB", pointer_get_u32_lsb},
    // {"SetU32LSB", pointer_set_u32_lsb},
    // {"ByteToAscii", pointer_byte_to_ascii},
    // {"AsciiToByte", pointer_ascii_to_byte},
    {NULL, NULL}};

int luaopen_pointer(lua_State *L)
{
    printf("loaded pointer\n");
    luaL_openlib(L, "pointer", pointerlib, 0);
    return 1;
}
