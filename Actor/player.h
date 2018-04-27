#ifndef PLAYER_H
#define PLAYER_H

typedef enum ELevel
{
  NEWBIE,
  INTERMEDIATE,
  EXPERT
}ELevel_t;

typedef struct player
{
  ELevel_t level;
  
}player_t;

#endif
