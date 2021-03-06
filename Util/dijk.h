#ifndef DIJ_H
#define DIJ_H

#include "graph.h"

typedef struct dijNode
{
  float cost;// -1 == infinity
  node_t * father;
  arc_t * lineUsed; // for printing the path
}dijNode_t;

typedef struct printStruct
{
  dijNode_t * node;
  struct printStruct * next;
}printStruct_t;

void findShortestPath(user_t * user, graph_t * graph);
void updateNeighboors(node_t * node, dijNode_t * tabNode, user_t * user);
void freePath(printStruct_t * pile);
void printPath(dijNode_t * tabNode, int size, user_t * user, graph_t * graph);

int getMin(dijNode_t * tab, int size, int * checked);
int getVisited(int * tab, int size);
float getRealTime(ELevel_t diff, arc_t * arc);

#endif
