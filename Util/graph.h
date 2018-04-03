#ifndef GRAPH_H
#define GRAPH_H

typedef enum EDiff
{
  GREEN = 0,
  RED,
  BLACK
} EDiff_t;

typedef struct node
{
  int number; //id of the node
  struct node * neighboors;
  int numberNeighboors; //size of neighboors
} node_t;

typedef struct arc
{
  int nbStart; //number of the starting point
  int nbStop; //number of the stopping point

  EDiff_t diff; //stores the difficulty of the line

} arc_t;


/*
  #nbNode
  #Node;#neighboor-#diff;
*/

//loads the graph struct from the specified file
node_t * initGraph(char *filePath);

#endif
