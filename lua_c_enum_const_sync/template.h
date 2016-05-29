/*
 // define const and enum
*/

#ifdef LUA_CONST_ENUM

  #undef  CONST_DEFINE
  #undef ENUM_DEFINE_BEGIN
  #undef ENUM_ENTRY
  #undef ENUM_ENTRYV
  #undef ENUM_DEFINE_END

  //常量定义
  #define CONST_DEFINE(constname, type, value)\
	  lua_getglobal(L, "Const"); \
    if (lua_istable(L, -1)) { \
       lua_pushstring(L, #constname); \
       lua_pushinteger(L, value);  \
       lua_settable(L, -3); \
    } \
    lua_pop(L, -1);
  
  //枚举开始
  #define ENUM_DEFINE_BEGIN(enumname) \
		lua_getglobal(L, "Const"); \
    if (lua_istable(L, -1)) { \
       int enumv = 0; \
			 lua_pushstring(L, #enumname); \
       lua_newtable(L); \
       lua_settable(L, -3); \
       \
       lua_pushstring(L, #enumname); \
		   lua_gettable(L, -2);
   

  //定义无值枚举条目
  #define ENUM_ENTRY(entryname) \
		   lua_pushstring(L, #entryname); \
       lua_pushinteger(L, enumv); \
       lua_settable(L, -3);\
       ++ enumv; \

  //定义有值枚举
  #define ENUM_ENTRYV(entryname, entryvalue) \
       lua_pushstring(L, #entryname); \
       lua_pushinteger(L, entryvalue); \
       lua_settable(L, -3);\

  #define ENUM_DEFINE_END()  \
       lua_pop(L, -1); \
    }

#else
  
  #define CONST_DEFINE(constname, type, value) \
	const type constname = value;

  #define ENUM_DEFINE_BEGIN(enumname) \
  enum enumname { \

  #define ENUM_ENTRY(entryname) \
  entryname, 

  #define ENUM_ENTRYV(entryname, entryvalue) \
  entryname = entryvalue,

  #define ENUM_DEFINE_END() };

#endif

CONST_DEFINE(consttest, int , 101)

ENUM_DEFINE_BEGIN(TestEnumV)
  ENUM_ENTRYV(test1, 1)
  ENUM_ENTRYV(test2, 2)
  ENUM_ENTRYV(test3, 3)
  ENUM_ENTRYV(test4, 4)
ENUM_DEFINE_END()

ENUM_DEFINE_BEGIN(TestEnum)
  ENUM_ENTRY(t1)
  ENUM_ENTRY(t2)
  ENUM_ENTRY(t3)
  ENUM_ENTRY(t4)
ENUM_DEFINE_END()
