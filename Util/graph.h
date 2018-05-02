#ifndef GRAPH_H
#define GRAPH_H

#include "../Actor/user.h"
#include "consts.h"

typedef struct arc
{
  EDiff_t diff; //stores the difficulty of the line
  unsigned int cost; //cost between this points
  char * name;
  int indexStart;
  int indexArrival; // the index of the destination

  struct arc * next;
} arc_t;

typedef struct node
{
  int index;
  char * name;
  arc_t * arcs;
  bool visited;
  int cost; // -1 == infinity
} node_t;

typedef struct graph
{
  node_t * tabNode;
  int sizeTab;
}graph_t;

/* #nbNode
#node;#namearc-#nodeArrival-#cost-#diff;
*/

//loads the graph struct from the specified file
graph_t * initGraph(const char *filePath);

void freeGraph(graph_t * graph);
void freeNode(node_t * node);

void addArc(node_t * node, arc_t * arc);

//vu que la matrice est dans un tableau, ça permet l'accès direct
//node_t * getNodeAt(graph_t * graph, int x, int y);

#endif
