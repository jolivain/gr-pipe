#! /usr/bin/env node

const readable = process.stdin;

readable.on('readable', () => {
  let buf;
  while (null !== (buf = readable.read(4))) {
      val = buf.readFloatLE(0);
      //process.stderr.write("read value: " + val + "\n");
      res = val * val;
      buf.writeFloatLE(res);
      process.stdout.write(buf);
  }
});
