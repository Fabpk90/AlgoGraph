#ifndef DIJ_H
#define DIJ_H

#include "graph.h"

typedef struct dijNode
{
  int cost;// -1 == infinity
  node_t * father;
}dijNode_t;

void findShortestPath(user_t * user, graph_t * graph);

int getMin(dijNode_t * tab, int size);

#endif
