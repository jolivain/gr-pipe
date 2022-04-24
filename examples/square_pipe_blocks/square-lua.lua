#!/usr/bin/env lua

--
-- Execute with:
--   lua square-lua.lua
--
-- Note: string.pack function requires Lua 5.3 or greater

local fmt = "=f"
local float_size = 4

while true do
   local bytes = io.stdin:read(float_size)
   if not bytes then
      break
   end

   local val = string.unpack(fmt, bytes)

   -- io.stderr:write(val, '\n')

   res = val * val

   bytes = string.pack(fmt, res)

   io.stdout:write(bytes)

end
