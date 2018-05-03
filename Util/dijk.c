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
  char ok = 0;

  for(i = 0; i < graph->sizeTab; i++)
  {
    tabNode[i].cost = -1;
    tabNode[i].father = NULL;
    tabNode[i].lineUsed = NULL;
  }

  //visite le premier d'abord
  printf("Visited %d", getVisited(checked, graph->sizeTab));

  tabNode[user->startNode].cost = 0;
  updateNeighboors(&graph->tabNode[user->startNode], tabNode, user);
  checked[user->startNode] = 1;

  //boucle, qui simule vraiment dijkstra
  while(!ok && getVisited(checked, graph->sizeTab) != graph->sizeTab)
  {
    index = getMin(tabNode, graph->sizeTab, checked);
    if(index != -1)
    {
      printf("test %d\n", index);
      updateNeighboors(&graph->tabNode[index], tabNode, user);
      checked[index] = 1;
    }
    else
      ok = 1;
  }

  //affiche le parcours
  printPath(tabNode,graph->sizeTab, user, graph);

  free(tabNode);
  free(checked);
}

void printPath(dijNode_t * tabNode, int size, user_t * user, graph_t * graph)
{
  dijNode_t * index = &tabNode[user->arrivalNode];
  printStruct_t * pile = malloc(sizeof(printStruct_t));
  printStruct_t * pileNext = NULL;
  float totalTime = 0;

  pile->node = index;
  pile->next = NULL;

  printf("Vous partez de %s\n", graph->tabNode[user->startNode].name);

  index = &tabNode[index->father->index];

  while(index->father != NULL)
  {
    pileNext = malloc(sizeof(printStruct_t));

    pileNext->node = index;
    pileNext->next = pile;
    pile = pileNext;

    index = &tabNode[index->father->index];
  }

  pileNext = pile;

  while(pileNext != NULL)
  {
    totalTime += pileNext->node->cost;
    printf("Tu passera par %s en %f mins\n"
    , pileNext->node->lineUsed->name, pileNext->node->cost);

    pileNext = pileNext->next;
  }

  printf("Vous arrivez %s\n", graph->tabNode[user->arrivalNode].name);


  printf("Temps total estime: %f\n", totalTime);

  freePath(pile);

}

void freePath(printStruct_t * pile)
{
  printStruct_t * index = pile;
  printStruct_t * next = pile->next;

  while (next != NULL)
  {
    free(index);
    index = next;
    next = index->next;
  }

  free(index);
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
  float cost;
  arc_t * arc = node->arcs;

  while(arc != NULL)
  {
    cost = getRealTime(user->level, arc);

    //printf("index: %d, costnodearr: %f , cost: %f, costSommet: %f\n",
    //node->index, tabNode[arc->indexArrival].cost, cost, tabNode[node->index].cost);

    if(tabNode[arc->indexArrival].cost == -1
     || tabNode[node->index].cost + cost
     < tabNode[arc->indexArrival].cost)
    {
      tabNode[arc->indexArrival].father = node;
      tabNode[arc->indexArrival].lineUsed = arc;
      tabNode[arc->indexArrival].cost = cost;
    }
    else
      arc = arc->next;
  }
}

int getMin(dijNode_t * tab, int size, int * checked)
{
  int i = 0, min = CONST_INFINITY, indexMin = -1;

  for(i = 0; i < size; i++)
  {
    if(!checked[i] && tab[i].cost > 0
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
