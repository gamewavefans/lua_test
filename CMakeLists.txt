cmake_minimum_required(VERSION 3.27)

project(zluaTest C)
add_executable(zlua_test 
    lua_gamewave/include/lauxlib.h
    lua_gamewave/include/lua.h
    lua_gamewave/include/lualib.h

    src/main.c

    src/zlua_gl.c
    src/zlua_gl.h
    src/zlua_rm.c
    src/zlua_rm.h
    src/zlua_time.c
    src/zlua_time.h
    src/zlua_log.c
    src/zlua_log.h
    src/zlua_pointer.c
    src/zlua_pointer.h
    src/zlua_zmath.c
    src/zlua_zmath.h
    src/zlua_input.c
    src/zlua_input.h
    src/zlua_iframe.c
    src/zlua_iframe.h
    src/zlua_engine.c
    src/zlua_engine.h
    src/zlua_text.c
    src/zlua_text.h
    src/zlua_font.c
    src/zlua_font.h
    src/zlua_movie.c
    src/zlua_movie.h
    src/zlua_audio.c
    src/zlua_audio.h
    src/zlua_spi.c
    src/zlua_spi.h
    src/zlua_uart.c
    src/zlua_uart.h
    src/zlua_eeprom.c
    src/zlua_eeprom.h
    src/zlua_zfile.c
    src/zlua_zfile.h
    src/zlua_exp_int.c
    src/zlua_exp_int.h
    src/zlua_bit.c
    src/zlua_bit.h
)

add_custom_target(
   zlua
   COMMAND make
   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lua_gamewave
)
add_dependencies(zlua_test zlua)

target_link_libraries(zlua_test  ${CMAKE_CURRENT_SOURCE_DIR}/lua_gamewave/lib/liblua.a  ${CMAKE_CURRENT_SOURCE_DIR}/lua_gamewave/lib/liblualib.a)
set_target_properties(zlua_test PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
# set the same type for numbers as expected
target_compile_definitions(zlua_test PRIVATE LUA_NUMBER=float)
