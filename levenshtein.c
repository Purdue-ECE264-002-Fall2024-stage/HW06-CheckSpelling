#include <string.h>
#include <limits.h>
#include <stdlib.h>
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


static int min(int a, int b, int c)
{
  return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int Levenshtein_iterative(const char* word1, const char* word2) 
{
  int l1 = strlen(word1), l2 = strlen(word2);
  int* prev = calloc(l1 + 1, sizeof(*prev));
  int* curr = calloc(l1 + 1, sizeof(*curr));
  
  for (int j = 0; j <= l1; j++) prev[j] = j;

  for (int i = 1; i <= l2; i++)
  {
    curr[0] = i;
    for (int j = 1; j <= l1; j++)
    {
      if (word1[j-1] == word2[i-1]) curr[j] = prev[j - 1];
      else curr[j] = 1 + min(curr[j - 1], prev[j], prev[j - 1]);
    }
    
    // DP solution cares only about previous buffer so swapping buffers to avoid memcpy
    int* temp = prev;
    prev = curr;
    curr = temp;
  }

  int dist = prev[l1];
  free(prev);
  free(curr);
  return dist;
}