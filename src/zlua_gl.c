#include "zlua_gl.h"

// TODO
static int gl_select_osd_mode(lua_State *L)
{
    const char *mode = luaL_checkstring(L, 1);
    printf("\tcalled gl.SelectOSDMode(\"%s\") - UNIMPLEMENTED\n", mode);
    return 0;
}

static const luaL_reg gllib[] = {
    {"SelectOSDMode", gl_select_osd_mode},
    // {"BeginScene", gl_begin_scene},
    // {"EndScene", gl_},
    // {"CreateOverlayFromTexture", gl_},
    // {"FreeOverlay", gl_},
    // {"LoadTexture", gl_},
    // {"FreeTexture", gl_},
    // {"AddTextureToOverlay", gl_},
    // {"RemoveTextureFromOverlay", gl_},
    // {"SetTextureActiveFrame", gl_},
    // {"SetClipInfo", gl_},
    // {"SetParameters", gl_},
    // {"SetZorder", gl_},
    // {"SetVisibility", gl_},
    // {"SetPosition", gl_},
    // {"GetZorder", gl_},
    // {"GetVisibility", gl_},
    // {"GetPosition", gl_},
    // {"GetSize", gl_},
    // {"ClearOSD", gl_},
    // {"Show", gl_},
    // {"number HasAnimations", gl_},
    // {"DeleteAllAnimations", gl_},
    // {"AddPositionAnimation", gl_},
    // {"AddVisibilityAnimation", gl_},
    // {"AddParabolaAnimation", gl_},
    // {"AddBlinkingAnimation", gl_},
    // {"AddAlphaAnimation", gl_},
    // {"CreateTextureAnimation", gl_},
    // {"CreateEmptyTexture", gl_},
    // {"BlitOverlay", gl_},
    // {"BlitOverlayWithCR", gl_},
    // {"SetTextureAlphaLevel", gl_},
    {NULL, NULL}};

int luaopen_gl(lua_State *L)
{
    printf("loaded gl\n");
    luaL_openlib(L, "gl", gllib, 0);
    return 1;
}
