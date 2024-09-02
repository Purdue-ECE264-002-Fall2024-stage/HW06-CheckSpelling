#include <string.h>
#include <limits.h>
#include <stdlib.h>
// algorithm described on
// https://en.wikipedia.org/wiki/Levenshtein_distance


static int min(int a, int b, int c)
{
  return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int Levenshtein(const char* word1, const char* word2) 
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