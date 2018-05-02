#include <stdio.h>
#include <stdlib.h>

#include "Util/graph.h"

void initLevel(user_t * user)
{
  int level;
  char ok = 0;

  while(!ok)
  {
    printf("Welcome mon ptit gars!\n c'est quoi ton niveau mon beau?\n(0 = Debutant, 1 = intermediaire, 3 = expert)\n");

    scanf("%d", &level);

    switch (level)
    {
      case 0:
        user->level = NEWBIE;
        ok = 1;
      break;

      case 1:
        user->level = INTERMEDIATE;
        ok = 1;
      break;

      case 2:
        user->level = EXPERT;
        ok = 1;
      break;
    }
  }

  system("clear");
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

  freeGraph(graph);
  free(user);
  return 0;
}
