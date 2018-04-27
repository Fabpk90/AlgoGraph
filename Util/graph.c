#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

graph_t * initGraph(char * filePath)
{
  FILE *finput = fopen(filePath, "r");
  int nbSommet = 0;
  graph_t * graph = NULL;

  if(finput != NULL)
  {
    if(fscanf(finput, "%d\n", &nbSommet))
    {
      graph = malloc(sizeof(graph_t));
      graph->matrixNode = malloc(nbSommet * nbSommet * sizeof(node_t));
      graph->sizeMatrix = nbSommet;
    }
  }

  fclose(finput);
  return graph;
}

void freeGraph(graph_t * graph)
{
  free(graph->matrixNode);
  free(graph);
}

node_t * getNodeAt(graph_t * graph, int x, int y)
{
 return graph->matrixNode[x * graph->sizeMatrix + y];
}
