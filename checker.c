// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "checker.h"
int Levenshtein(const char * str1, const char * str2, int* ct1, int* ct2);

int countWords(char* filename)
{
  FILE * fin = fopen(filename, "r"); 
  if (fin == NULL)
    { return 0; } 
  int count = 0;
  char oneline[MAXLENGTH]; 
  while (! feof(fin)) 
    {
      if (fgets(oneline, MAXLENGTH, fin) != NULL) 
	{ count ++; } 

    }
  fclose(fin);
  return count; 
}



bool readWords(char* filename, WordDistance * wd, int numword)
{
  FILE * fin = fopen(filename, "r"); //open file
  if (fin == NULL)
    { return false; }

  int count = 0; //initalize counter
  char oneline[MAXLENGTH]; //initialize oneline
  while (! feof(fin))
    {
      if (fgets(oneline, MAXLENGTH, fin) != NULL) //same thing as before if there is 41 chars in file
	{
	  //strcpy(wd[count].word, oneline); //copy oneline into Worddistance wd
    //strncpy(wd[count].word, oneline, (strlen(oneline) - 1));
    for (int i = 0; (i < (int)(strlen(oneline)) && (oneline[i] != '\n') && (oneline[i] != '\0'))  ; i++)
    {
      wd[count].word[i] = oneline[i];
    }
	  wd[count].distance = 0; 
	  count ++; 
	  if (count > numword)
	    {
	      fprintf(stderr, "ERROR, count: %d, numword: %d\n",
		      count, numword); 
	    }
	}
    }
  fclose(fin);
  return true;
}


void calculateDistance(WordDistance * wd, int numword, const char * tocheck)
{
  int ind;
  int *ct1 = (int *)malloc(sizeof(int));
  int *ct2 = (int *)malloc(sizeof(int));
  *ct1 = 0;
  *ct2 = 0;

  for (ind = 0; ind < numword; ind ++)
    {
      int longer;
      if (strlen(wd[ind].word) > strlen(tocheck))
      {
        longer = (int)strlen(wd[ind].word);
      }
      else
      {
        longer = (int)strlen(tocheck);
      }
      if (Levenshtein(wd[ind].word, tocheck, ct1, ct2) > longer)
      {
        wd[ind].distance = longer;
      }
      else
      {
        wd[ind].distance = Levenshtein(wd[ind].word, tocheck, ct1, ct2);
      }

      //printf("%d\n", wd[ind].distance);
    }
  free(ct1);
  free(ct2);
}


static int compareDistance(const void * ptr1, const void * ptr2) //what is the static type
{
  // ptr1 and ptr2 are WordDistance *
  const WordDistance * wd1 = (const WordDistance *) ptr1;
  const WordDistance * wd2 = (const WordDistance *) ptr2; 
  return ((wd1 -> distance) - (wd2 -> distance));
}

void sortDistance(WordDistance * wd, int numword)
{
  qsort(wd, numword, sizeof(WordDistance), compareDistance);
}

void printWord(WordDistance * wd, int numword)
{
  // int shortest = wd[0].distance;
  int ind = 0;
  // while ((ind < numword) && (wd[ind].distance == shortest))
  while (ind < 10)
    {
      printf("%d, %s\n", wd[ind].distance, wd[ind].word);
      ind ++;
    }
}


