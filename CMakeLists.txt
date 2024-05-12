cmake_minimum_required(VERSION 3.27)


file(GLOB SRCS "src/*.c")
file(GLOB INCLUDES "src/*.h")

project(zluaTest C)

message("${CMAKE_C_COMPILER_ID}")

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  message("gcc detected")
  add_compile_options("-Werror=implicit-function-declaration")
endif()

add_executable(zlua_test 
    lua_gamewave/include/lauxlib.h
    lua_gamewave/include/lua.h
    lua_gamewave/include/lualib.h

    ${SRCS}
    ${INCLUDES}
)
set_property(TARGET zlua_test PROPERTY C_STANDARD 23)



add_custom_target(
   zlua
   COMMAND make -j 32
   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lua_gamewave
)
add_dependencies(zlua_test zlua)

target_link_libraries(zlua_test  ${CMAKE_CURRENT_SOURCE_DIR}/lua_gamewave/lib/liblua.a  ${CMAKE_CURRENT_SOURCE_DIR}/lua_gamewave/lib/liblualib.a)
# set_target_properties(zlua_test PROPERTIES COMPILE_OPTIONS "-m32" LINK_FLAGS "-m32")
# set the same type for numbers as expected
target_compile_definitions(zlua_test PRIVATE LUA_NUMBER=int)

add_custom_target(really-clean
  COMMAND cmake --build "${CMAKE_CURRENT_BINARY_DIR}" --target clean
  COMMAND cd ${CMAKE_CURRENT_SOURCE_DIR}/lua_gamewave && make clean
)
