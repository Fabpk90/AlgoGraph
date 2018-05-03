#ifndef USER_H
#define USER_H

typedef enum ELevel
{
  NEWBIE = 0,
  EXPERT
}ELevel_t;

typedef struct user
{
  ELevel_t level;
  int startNode;
  int arrivalNode;
}user_t;

#endif
