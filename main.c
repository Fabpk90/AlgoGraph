#include <stdio.h>
#include <stdlib.h>

#include "Util/graph.h"

int main(int argc, char const *argv[])
{

  /*
  L'idée c'est donc de faire tourner djikstra et après de faire le chemin inverse du point d'arrivée
  jusqu'au point de départ
  */
  graph_t * graph = initGraph("data.dat");

  getNodeAt(graph, 1, 1);

  freeGraph(graph);
  return 0;
}
