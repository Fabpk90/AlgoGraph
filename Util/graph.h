#ifndef GRAPH_H
#define GRAPH_H

#include "../Actor/user.h"

typedef enum EDiff
{
  GREEN = 0,
  BLUE,
  RED,
  BLACK
} EDiff_t;

typedef struct arc
{
  EDiff_t diff; //stores the difficulty of the line
  unsigned int cost; //cost between this points
  char * name;
} arc_t;

typedef struct list
{
  arc_t * arc;
  arc_t * next;
}arclist_t

typedef struct node
{
  char * name;
  arclist_t arcs;
} node_t;

typedef struct graph
{
  node_t * matrixNode;
  int sizeMatrix;
}graph_t;

/*
  #nbNode
  #Node;#neighboor-#diff;
*/

//loads the graph struct from the specified file
graph_t * initGraph(char *filePath);

void freeGraph(graph_t * graph);
void freeNode(node_t * node);

unsigned int getTimeTo(arc_t * arc, user_t * user);

//vu que la mtrice est dans un tableau, ça permet l'accès direct
node_t * getNodeAt(graph_t * graph, int x, int y);

#endif
