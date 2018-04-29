#ifndef USER_H
#define USER_H

typedef enum ELevel
{
  NEWBIE,
  INTERMEDIATE,
  EXPERT
}ELevel_t;

typedef struct user
{
  ELevel_t level;

}user_t;

#endif
