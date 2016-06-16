#include <iostream>
#include <string.h>

extern "C" {
#include "lua.h"
#include "lualib.h"   
#include "lauxlib.h"
}



using namespace std;

static int LuaFunc1(lua_State *L) {
	std::cout << "c1 func ok!" << std::endl;
	return 0;
}


static int LuaFunc2(lua_State *L) {
	std::cout <<"c2 func ok!"<< std::endl;
	return 0;
}


/*static luaL_Reg myfuncs[] = {
	{"func1", LuaFunc1},
	{"func2", LuaFunc2},
	{NULL, NULL}
};*/

int main()
{
	//1.创建一个state  
	lua_State *L = luaL_newstate();  
  luaL_openlibs(L);

	/*
	// 引用一般在注册表中进行，引用就是key  在注册表中一般不用整数做key
	//lua_pushstring(L, "TB");
	lua_newtable(L);

	lua_pushnumber(L,100);
	int handle = luaL_ref(L, -2);

	std::cout << handle << std::endl;

	std::cout << lua_gettop(L) << std::endl;

	lua_rawgeti(L, -1, handle); 
	int num = lua_tonumber(L, -1);

	std::cout << lua_gettop(L) << std::endl;

	std::cout << num << std::endl;
	lua_pop(L, 1);

	std::cout << lua_gettop(L) << std::endl;

	lua_pushnumber(L, handle);
	lua_gettable(L, -2);

	if (lua_isnumber(L,-1)) {
	int num1 = lua_tonumber(L, -1);
	std::cout << num1 << std::endl;
	lua_pop(L, 1);
	}*/

	/*
  // 注册表 全局环境，每个lua_State都不共享
	lua_State *LL = luaL_newstate();
	luaL_openlibs(LL);

   lua_pushstring(L, "1111111");
   lua_setglobal(L, "c_Mode");

	 //lua_pushstring(L,"Hello");
	 //lua_setfield(L,LUA_REGISTRYINDEX,"key1");
	 //lua_getfield(LL,LUA_REGISTRYINDEX,"key1");

	 lua_getglobal(LL, "c_Moddde");
	 if (lua_isstring(LL,1))
	 {
		 const char* str = lua_tostring(L,-1); 
		 std::cout << str << std::endl;
	 } */

	//2.入栈操作  
	/*lua_pushstring(L, "I am so cool~");   
	lua_pushnumber(L,20);  

	//3.取值操作  
	if( lua_isstring(L,1)){           //判断是否可以转为string  
		cout<<lua_tostring(L,1)<<endl;  //转为string并返回  
	}  
	if( lua_isnumber(L,2)){  
		cout<<lua_tonumber(L,2)<<endl;  
		}*/  

	//注册函数
	/*lua_register(L, "cfunc1", LuaFunc1);
	lua_register(L, "cfunc2", LuaFunc2);

  //执行lua文件
	if (luaL_dofile(L, "luat.lua")) {
		std::cout <<"加载脚本文件失败"<< lua_tostring(L, -1) << std::endl;
	}*/

	//4.关闭state  
	lua_close(L);  

	return 0;
}
