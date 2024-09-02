#include <string.h>
#include <limits.h>
// algorithm described on
// https://en.wikipedia.org/wiki/Levenshtein_distance

int Levenshtein(const char* str1, const char* str2)
{
  if (strlen(str1) == 0) 
  {
    return strlen(str2);
  }
  
  if (strlen(str2) == 0) 
  {
    return strlen(str1);
  }
  
  if ((*str1) == (*str2)) // first letter same
  {
    return Levenshtein(str1 + 1, str2 + 1);
  }

  int mindist = INT_MAX;
  int dist1 = Levenshtein(str1 + 1, str2);
  int dist2 = Levenshtein(str1, str2 + 1);
  int dist3 = Levenshtein(str1 + 1, str2 + 1); 

  if (mindist > dist1) 
  {
    mindist = dist1;
  }

  if (mindist > dist2) 
  {
    mindist = dist2;
  }
  
  if (mindist > dist3) 
  {
    mindist = dist3;
  }
  
  return 1 + mindist;
}