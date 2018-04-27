#ifndef GRAPH_H
#define GRAPH_H

typedef enum EDiff
{
  GREEN = 0,
  BLUE,
  RED,
  BLACK
} EDiff_t;


typedef struct node
{
  int number; //id of the node
  char * name;
  struct node * neighboors;
  int numberNeighboors; //size of neighboors
} node_t;

typedef struct arc
{
  EDiff_t diff; //stores the difficulty of the line
  unsigned int cost; //cost between this points
} arc_t;

typedef struct graph
{
  node_t ** matrixNode;
  int sizeMatrix;
}graph_t;

/*
  #nbNode
  #Node;#neighboor-#diff;
*/

//loads the graph struct from the specified file
graph_t * initGraph(char *filePath);

void freeGraph(graph_t * graph);

node_t * getNodeAt(graph_t * graph, int x, int y);

#endif
