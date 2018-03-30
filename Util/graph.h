#ifndef GRAPH_H
#define GRAPH_H

typedef struct node
{
  int number;
  struct node * neighboors;
  int numberNeighboors;
} node_t;


//loads the graph struct from the specified file
node_t * initGraph(char *filePath);

#endif
