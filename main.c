#include <stdio.h>
#include <stdlib.h>

#include "Util/graph.h"
#include "Util/dijk.h"

void initLevel(user_t * user)
{
  int level;
  char ok = 0;

  while(!ok)
  {
    printf("Welcome mon ptit gars!\n c'est quoi ton niveau mon beau?\n(0 = Debutant, 1 = Expert)\n");

    scanf("%d", &level);

    switch (level)
    {
      case 0:
        user->level = NEWBIE;
        ok = 1;
      break;

      case 1:
        user->level = EXPERT;
        ok = 1;
      break;
    }
  }

  system("clear");
}

int initTravel(user_t * user, graph_t * graph)
{
  int i;

  for(i = 0; i < graph->sizeTab; i++)
  {
    printf("%d %s\n", i, graph->tabNode[i].name);
  }
  printf("Maintenant choisi ton point de depart\n");

  scanf("%d", &user->startNode);

  if(user->startNode >= 0 && user->startNode < graph->sizeTab)
  {
    printf("Maintenant le point d'arrivee\n");

    scanf("%d", &user->arrivalNode);

    if(user->arrivalNode >= 0 && user->arrivalNode < graph->sizeTab
    && user->arrivalNode != user->startNode)
    {
      return 1;
    }
    else
    {
      printf("Tu a choisi les memes sommet!\n");
      return 0;
    }
  }
  else
  {
    printf("Mais non, tu fais n'importe quoi!\n");
    return 0;
  }
}


int main(int argc, char const *argv[])
{
  /*
  L'idée c'est donc de faire tourner djikstra et après de faire le chemin inverse du point d'arrivée
  jusqu'au point de départ
  Avant tout ça il faut créer une matrice d'adjacence avant, en fonction du niveau de l'utilisateur
  */
  graph_t * graph = initGraph("data.dat");
  user_t * user = malloc(sizeof(user_t));

  initLevel(user);

  if(initTravel(user, graph))
  {
    findShortestPath(user, graph);
  }
  else
  {
    printf("Ba alors, on a bu trop de vin au resto?\n");
  }

  freeGraph(graph);
  free(user);
  return 0;
}
