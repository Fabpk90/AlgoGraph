#ifndef USER_H
#define USER_H

typedef enum ELevel
{
  NEWBIE = 0,
  INTERMEDIATE,
  EXPERT
}ELevel_t;

typedef struct user
{
  ELevel_t level;
  int startNode;
  int arrivalNode;
}user_t;

#endif
