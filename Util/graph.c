#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

graph_t * initGraph(const char * filePath)
{
  FILE *finput = fopen(filePath, "r");
  int nbSommet = 0, x, y, iterSommet, sommetArr;
  char valRead = 0;
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

      for(iterSommet = 0; iterSommet < nbSommet; iterSommet++)
      {
        fscanf(finput, "%d;", NULL);
        while(valRead != '\n')
        {
          fscanf(finput, "%d-", &sommetArr);
          if(valRead != 0)

          nodeInit = getNodeAt(graph, iterSommet, sommetArr);
          fscanf(finput, "%d-%d;", nodeInit->diff)

          fscanf(finput, "%c", &valRead);
        }
      }


      for(x = 0; x < nbSommet; x++)
      {
        for(y = 0; y < nbSommet; y++)
        {

        }
      }
    }
  }

  fclose(finput);
  return graph;
}


//returns an adjacence matrix to apply djikstra on
matAdj_t * getAdjMat(graph_t * graph, user_t * user)
{

}



node_t * getNodeAt(graph_t * graph, int x, int y)
{
 return graph->matrixNode[x * graph->sizeMatrix + y];
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
