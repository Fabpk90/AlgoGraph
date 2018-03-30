#include <stdio.h>
#include <stdlib.h>

#include "Util/graph.h"

int main(int argc, char const *argv[])
{
  node_t * nodes = initGraph("data.dat");

  free(nodes);
  return 0;
}
