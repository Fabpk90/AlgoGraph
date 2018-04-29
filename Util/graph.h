#ifndef GRAPH_H
#define GRAPH_H

#include "../Actor/user.h"
#include "consts.h"

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

typedef struct node
{
  char * name;
  arc_t arc;
} node_t;

typedef struct graph
{
  node_t * matrixNode;
  int sizeMatrix;
}graph_t;

typedef struct arcAdj
{
  uint cost;
  bool visited;
}arcAdj_t;

typedef struct matAdj
{
  EDiff_t matDiff;
  arcAdj_t * mat;
}matAdj_t;

/*
  #nbNode
  #node;#neighboor-#cost-#diff;
*/

//loads the graph struct from the specified file
graph_t * initGraph(const char *filePath);

matAdj_t * getAdjMat(graph_t * graph, user_t * user);

void freeGraph(graph_t * graph);
void freeNode(node_t * node);

unsigned int getTimeTo(arc_t * arc, user_t * user);

//vu que la mtrice est dans un tableau, ça permet l'accès direct
node_t * getNodeAt(graph_t * graph, int x, int y);

#endif
