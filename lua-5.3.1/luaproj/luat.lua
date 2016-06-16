-- lua协程

-- 关于resume的行为：
-- 第一次resume只是唤醒协程，将其参数作为协程的参数传入，本身不返回任何值
-- 中间n次resume将唤醒最近一次的yield操作，并将yield的参数作为返回值 第一个返回值表示    调用是否成功
-- 最后一次resume直接返回整个协程的最终返回值


-- 关于yield的行为：
-- 每一次的yield都是返回值都是其后最近一次resume传入的参数，每次yield的参数都作为其后    最近一次resume的返回值
require 'string'
require 'utf8'
require 'math'
require 'io'

co=coroutine.create(
function()
 print("co ", coroutine.yield(1,2,3))
end)

xxx = '222'

local myfunc = (function(var) 
                 print(var)
               end)


function func()
  print('1122334455')
end


-- how to use ':' to define a function of a table
local TB = {{1,2},{3,4}}
function TB:func()
  print(TB[1][1])
end

-- change _ENV
function Test(env)
  local  _ENV = env
  local ret = {}
  function ret.fun1(self)
      _ENV.func()
  end  
  return ret
end


do
  print("resume", coroutine.resume(co))
  print("resume", coroutine.resume(co, 1,2,3,4))
  print(_ENV.xxx)
  myfunc(3)

  -- how to use a function
  local l = Test(TB)
  local f = l.fun1
  f()

  -- how to use load
  local p = load('return 4')  --load(func)
  print(p())

  -- how to use pcall
  pcall(func)

  -- how to use rawget, ignore metatable
  local metatest = {1,2,3,4}
  local meta_ = {5,6,7,8,10}
  setmetatable(metatest, {__index = meta_})
  print(metatest[4])
  print(rawget(metatest, 5))

  -- how to use string.pack
  local str = 'aasdd111122'
  local db = '3.1415'
  local strbin = string.pack('z', str)
  local dbb  = string.pack('d', db)
  print(dbb)
  print(strbin)
  print(string.len(strbin))

  -- how to use utf8 package
  print(utf8.char(50,51,52,53))
 
  -- how to open and read a file
  local fhandle = io.open('test.txt', 'r')
  if fhandle ~= nil then 
    local str = fhandle:read("a")
    print(str)
  end


end
