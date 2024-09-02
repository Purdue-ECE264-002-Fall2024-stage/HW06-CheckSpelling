// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "checker.h"


int countWords(char* filename)
{
  FILE * fin = fopen(filename, "r"); 
  if (fin == NULL)
  {
    return 0;
  } 

  int count = 0;
  while (!feof(fin)) 
  {
    if (fgetc(fin) == 10) // Check for Line Feeds to indicate end of line
  	{
      count++;
    } 
  }

  fclose(fin);
  return count + 1; // +1 because the number of line feeds = number of lines in file - 1 
}


bool readWords(char* filename, WordDistance* wd, int numword)
{
  FILE * fin = fopen(filename, "r"); //open file
  if (fin == NULL)
  {
    return false;
  }

  int count = 0; //initalize counter
  int curr_c = 0; // Current character index
  
  while (!feof(fin))
  {
    int c = fgetc(fin);
    if (curr_c < (MAXLENGTH -1) && c != 10 && c != -1) // current character is not line feed
    {
      wd[count].word[curr_c] = c;
      curr_c++;
    }

    else if (c == 10 || c == -1)
    {
      wd[count].word[curr_c] = 0;
      curr_c = 0;
  	  wd[count].distance = 0; 
  	  count++; 
    }
	  
    if (count > numword)
    {
      fprintf(stderr, "ERROR, count: %d, numword: %d\n", count, numword); 
    }
	}

  fclose(fin);
  return true;
}


void calculateDistance(WordDistance* wd, int numword, const char* tocheck)
{
  for (int ind = 0; ind < numword; ind++)
  {
    wd[ind].distance = Levenshtein(wd[ind].word, tocheck);
  }
}


static int compareDistance(const void* ptr1, const void* ptr2) //what is the static type
{
  // ptr1 and ptr2 are WordDistance*
  const WordDistance* wd1 = (const WordDistance*) ptr1;
  const WordDistance* wd2 = (const WordDistance*) ptr2; 
  return ((wd1->distance) - (wd2->distance));
}


void sortDistance(WordDistance* wd, int numword)
{
  qsort(wd, numword, sizeof(WordDistance), compareDistance);
}


void printWord(WordDistance* wd, int numword)
{
  int limit = numword < 10 ? numword : 10; // Handle test cases with fewer than 10 words
  for (int ind = 0; ind < limit; ind++)
  {
    printf("%d, %s\n", wd[ind].distance, wd[ind].word);
  }
}
