#include "fileHandler.h"

void readName(FILE* fin, char * str)
{
  int totalRead = 0;
  char read = 0;
  bool ok = 1;

  while(ok)
  {
    fscanf(fin, "%c", &read);
    if(read != ';' && read != '-')
    {
      str[totalRead] = read;
      totalRead++;
    }
    else
      ok = 0;
  }

  str[totalRead] = '\0';
}

EDiff_t getDiffFromChar(char ch)
{
  switch(ch)
  {
    case 'V':
      return GREEN;
    case 'B':
      return BLUE;
    case 'R':
      return RED;
    case 'N':
      return BLACK;
    case 'P':
      return MECHANIC;
  }

  return NONE;
}
