/*
 * Copmiles with:
 *   cc -O2 -Wall -o square-c square-c.c
 * Run with:
 *   ./square-c
 */

#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
  float val;
  size_t sz;

  for ( ; ; ) {

    sz = fread(&val, sizeof (float), 1, stdin);
    if (sz == 0) {
      break ;
    }
    if (sz != 1) {
      perror("fread()");
      exit(EXIT_FAILURE);
    }

    /* fprintf(stderr, "%f\n", val); */

    val *= val;

    sz = fwrite(&val, sizeof (float), 1, stdout);
    if (sz != 1) {
      perror("fwrite()");
      exit(EXIT_FAILURE);
    }
  }

  return (0);
}
