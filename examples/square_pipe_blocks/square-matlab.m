while ( ! feof(stdin) )
  val = fread(stdin, 1, "float32", 0, "native");
  % fprintf(stderr, "%f\n", val);
  fwrite(stdout, val * val, "float32", 0, "native");
end
