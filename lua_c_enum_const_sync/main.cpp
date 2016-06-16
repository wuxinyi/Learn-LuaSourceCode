#include "template.h"
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>
#include <iostream>

using namespace std;

const int cst = consttest;

int main()
{
   lua_State *L = luaL_newstate();
   luaL_openlibs(L);

   lua_newtable(L);
   lua_setglobal(L, "Const");

   #define LUA_CONST_ENUM   
   #include "template.h"
   #undef  LUA_CONST_ENUM

   luaL_dofile(L, "./const_enum_test.lua");
   std::cout << consttest << std::endl;
   std::cout << cst << std::endl;
   std::cout << test1 << std::endl;
   std::cout << test2 << std::endl;
}
