#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

node_t * initGraph(char * filePath)
{
  FILE *finput = fopen(filePath, "r");
  int nbSommet = 0;
  node_t * nodes = NULL;


  if(finput != NULL)
  {
    if(fscanf(finput, "%d\n", &nbSommet))
    {
      nodes = malloc(sizeof(node_t) * nbSommet);

      printf("%d", nbSommet);
    }
  }

  fclose(finput);

  return nodes;
}
