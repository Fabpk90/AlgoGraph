#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "graph.h"
#include "fileHandler.h"


graph_t * initGraph(const char * filePath)
{
  FILE *finput = fopen(filePath, "r");
  int nbSommet = 0, i;
  graph_t * graph = NULL;
  arc_t * arcInit;
  bool end = 0;
  char read; //used to find end line
  char diff;

  if(finput != NULL)
  {
    if(fscanf(finput, "%d\n", &nbSommet))
    {
      graph = malloc(sizeof(graph_t));
      graph->tabNode = calloc(sizeof(node_t), nbSommet);
      graph->sizeTab = nbSommet;

      for(i = 0; i < nbSommet; i++)
      {
        graph->tabNode[i].arcs = NULL;
        graph->tabNode[i].cost = -1;
        graph->tabNode[i].visited = 0;
      }

      /*
        TODO: faire une fonction add arc pour les node_t, bien set les trucs à NULL
      */

      for(i = 0; i < nbSommet; i++)
      {
        end = 0;
        graph->tabNode[i].name = malloc(sizeof(char) * CONST_NAME_LENGTH);
        readName(finput, graph->tabNode[i].name);
        fseek(finput, -1, SEEK_CUR);//resets the cursor correctly

        while(!end)
        {
          //see if end of line
          fscanf(finput, "%c", &read);
          if(read != '\n')
          {
            arcInit = malloc(sizeof(arc_t));
            arcInit->name = malloc(sizeof(char) * CONST_NAME_LENGTH);
            arcInit->next = NULL;

            readName(finput, arcInit->name);
            fscanf(finput, "%d-%d-%c",
             &arcInit->arrival, &arcInit->cost, &diff);

            arcInit->diff = getDiffFromChar(diff);

            printf("name %s , arrival %d , cost %d , diff %d\n",
            arcInit->name,arcInit->arrival, arcInit->cost, arcInit->diff);

            addArc(&graph->tabNode[i], arcInit);
          }
          else //end of line
            end = 1;
        }

      }
    }
  }

  fclose(finput);
  return graph;
}


void addArc(node_t * node, arc_t * arc)
{
  arc_t * index;
  if(node->arcs == NULL)
    node->arcs = arc;
  else
  {
    index = node->arcs;

    //infs the next free place
    while(index->next != NULL)
    {
      index = index->next;
    }

    index->next = arc;

  }
}

/*node_t * getNodeAt(graph_t * graph, int x, int y)
{
 return &graph->matrixNode[x * graph->sizeMatrix + y];
}*/

void freeGraph(graph_t * graph)
{
  int i;

  for(i = 0; i < graph->sizeTab; i++)
  {
    freeNode(&graph->tabNode[i]);
  }

  free(graph->tabNode);
  free(graph);
}

void freeNode(node_t * node)
{
  arc_t * index;
  arc_t * next;

  next = node->arcs;

  while(next != NULL)
  {
    index = next;
    free(index->name);
    next = index->next;
    free(index);
  }

  free(node->name);
}
