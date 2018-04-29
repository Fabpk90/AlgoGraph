#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

graph_t * initGraph(char * filePath)
{
  FILE *finput = fopen(filePath, "r");
  int nbSommet = 0, x, y;
  graph_t * graph = NULL;
  node_t * nodeInit;

  if(finput != NULL)
  {
    if(fscanf(finput, "%d\n", &nbSommet))
    {
      graph = malloc(sizeof(graph_t));
      graph->matrixNode = malloc(nbSommet * nbSommet * sizeof(node_t));
      graph->sizeMatrix = nbSommet;


      /*
        TODO: faire une fonction add arc pour les node_t, bien set les trucs à NULL
      */

      for(x = 0; x < nbSommet; x++)
      {
        for(y = 0; y < nbSommet; y++)
        {
          nodeInit = getNodeAt(graph, x, y);
          nodeInit->number = x;
        }
      }
    }
  }

  fclose(finput);
  return graph;
}

void freeGraph(graph_t * graph)
{
  int i, j, arc, nbArcs;
  node_t * node;

  for(i = 0; i < graph->sizeMatrix; i++)
  {
    for(j = 0; j < graph->sizeMatrix; j++)
    {
      freeNode(getNodeAt(graph, i, j));
    }
  }

  free(graph->matrixNode);
  free(graph);
}

void freeNode(node_t * node)
{
  int nbArcs = node->nbArcs, arc;

  arc_t * index;
  arc_t * next;

  next = node->arcs.arc;

  while(next != NULL)
  {
    index = next;
    free(index->name);
    next = index->next;
    free(index);
  }
}

node_t * getNodeAt(graph_t * graph, int x, int y)
{
 return graph->matrixNode[x * graph->sizeMatrix + y];
}
