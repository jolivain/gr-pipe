#! /usr/bin/env -S ruby -w

while true do
  x = STDIN.read(4)
  if x == nil then
    break
  end
  if x.length != 4 then
    next
  end

  val = x.unpack('f')[0]

  # STDERR.puts(val)

  res = val * val

  STDOUT.write( [res].pack('f') )
  
end
