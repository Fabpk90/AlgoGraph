#include "fileHandler.h"
#include "consts.h"


void readName(FILE* fin, char * str)
{
  int totalRead = 0;
  char read = 0;
  bool ok = 1;

  while(ok)
  {
    fscanf(fin, "%c", &read);
    //printf("%c ", read);
    if(read != ';' && read != '-')
    {
      str[totalRead] = read;
      totalRead++;
    }
    else
      ok = 0;
  }
}
