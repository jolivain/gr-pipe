<?php

while (true)
{
    $buf = fread(STDIN, 4);
    if (strlen($buf) == 0)
        break;
    if (strlen($buf) != 4)
        continue;

    $array = unpack("fval", $buf);
    $val = $array["val"];

    // fwrite(STDERR, $val . PHP_EOL);

    $res = $val * $val;

    $buf = pack("f", $res);
    fwrite(STDOUT, $buf);
}

?>
