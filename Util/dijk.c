#include <stdlib.h>
#include <stdio.h>

#include "dijk.h"

void findShortestPath(user_t * user, graph_t * graph)
{
  int i, index;
  /*
    Alloue un tableau de tous les sommets, pour avoir les distances
    et les pères,
    à la fin, remonte depuis la destination jusqu'à la source
    la source a comme père NULL
  */

  /*
    Si le noeud analisé est la destination, on s'arrête, NON!
    l'algo doit faire tous les noeuds!
  */

  dijNode_t * tabNode = malloc(sizeof(dijNode_t) * graph->sizeTab);
  //used for knowing which nodes have been visited
  int * checked = calloc(sizeof(int), graph->sizeTab);

  for(i = 0; i < graph->sizeTab; i++)
  {
    tabNode[i].cost = -1;
    tabNode[i].father = NULL;
    tabNode[i].lineUsed = NULL;
  }

  printf("Visited %d", getVisited(checked, graph->sizeTab));

  tabNode[user->startNode].cost = 0;
  updateNeighboors(&graph->tabNode[user->startNode], tabNode, user);
  checked[user->startNode] = 1;

  while(getVisited(checked, graph->sizeTab) != graph->sizeTab)
  {
    index = getMin(tabNode, graph->sizeTab);
    updateNeighboors(&graph->tabNode[index], tabNode, user);
    checked[index] = 1;
  }

  printPath(tabNode,graph->sizeTab, user);


  free(tabNode);
  free(checked);
}

void printPath(dijNode_t * tabNode, int size, user_t * user)
{
  dijNode_t * index = &tabNode[user->startNode];

  while(index->father == NULL)
  {
    
  }
}


int getVisited(int * tab, int size)
{
  int i, visited = 0;

  for(i = 0; i < size; i++)
  {
    if(tab[i])
      visited++;
  }

  return visited;
}

void updateNeighboors(node_t * node, dijNode_t * tabNode, user_t * user)
{
  int cost;
  arc_t * arc = node->arcs;

  while(arc != NULL)
  {
    cost = getRealTime(user->level, arc);

    if(tabNode[arc->indexArrival].cost == -1
     || tabNode[node->index].cost + cost
     < tabNode[arc->indexArrival].cost)
    {
      tabNode[arc->indexArrival].father = node;
      tabNode[arc->indexArrival].lineUsed = arc;
      tabNode[arc->indexArrival].cost = cost;

      //to stop the loop
      arc = NULL;
    }
  }
}

int getMin(dijNode_t * tab, int size)
{
  int i = 0, min = CONST_INFINITY, indexMin = -1;

  for(i = 0; i < size; i++)
  {
    if(tab[i].cost != -1 && tab[i].cost != 0
      && tab[i].cost < min)
    {
      min = tab[i].cost;
      indexMin = i;
    }
  }

  return indexMin;
}

int getRealTime(ELevel_t level, arc_t * arc)
{
  if(arc->diff == MECHANIC)
    return arc->cost;

  return arc->cost * (level == NEWBIE ? 2 : 1);
}
