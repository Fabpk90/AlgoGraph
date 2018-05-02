#include <stdlib.h>
#include <stdio.h>

#include "dijk.h"

void findShortestPath(user_t * user, graph_t * graph)
{
  int i;
  /*
    Alloue un tableau de tous les sommets, pour avoir les distances
    et les pères,
    à la fin, remonte depuis la destination jusqu'à la source
    la source a comme père NULL
  */

  /*
    Si le noeud analisé est la destination, on s'arrête
  */

  dijNode_t * tabNode = malloc(sizeof(dijNode_t) * graph->sizeTab);

  for(i = 0; i < graph->sizeTab; i++)
  {
    tabNode[i].cost = -1;
    tabNode[i].father = NULL;
  }


  free(tabNode);
}

int getMin(dijNode_t * tab, int size)
{
  int i = 0, min = CONST_INFINITY, indexMin = -1;

  for(i = 0; i < size; i++)
  {
    if(tab[i].cost != -1 && tab[i].cost < min)
    {
      min = tab[i].cost;
      indexMin = i;
    }
  }

  return indexMin;
}
