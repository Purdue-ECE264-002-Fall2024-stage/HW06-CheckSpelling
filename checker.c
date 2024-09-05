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
//open "filename" for reading. if NULL, return 0.
//count the number of words in the file(hint, every word is a a singular line)
//close the file
// return the count of words in the file
}


bool readWords(char* filename, WordDistance* wd, int numword)
{
//open file for reading. if NULL, return false. 
//put each word in the list from the input into a wd[count].word element. 
//count the number of words that you've put in the list. if the number is more than numword(gotten from countWords),
//then use fprintf to print to stderr: "ERROR, count: %d, numword: %d\n", count, numword. 
//close file.
  return true;
}


void calculateDistance(WordDistance* wd, int numword, const char* tocheck)
{
//for each word in wd, use levenshtein to update its levenshtein distance in the distance element of the structure. tocheck is the word you will be checking the words in wd against.
}

//this function is provided as an argument to be used in qsort in the sortDistance function.
static int compareDistance(const void* ptr1, const void* ptr2) 
{
  const WordDistance* wd1 = (const WordDistance*) ptr1;
  const WordDistance* wd2 = (const WordDistance*) ptr2; 
  return ((wd1->distance) - (wd2->distance));
}


void sortDistance(WordDistance* wd, int numword)
{
 //use qsort to sort the wd array based on the value of distance elements. The lowest distances should be first. you can use compareDistance as a argument in qsort. 
//for words with the same distance, make sure that they are sorted in a alphabetical order. hint: use strcmp
}

//this function is provided to print the first 10 words closest to the input word, as well as their corresponding levenshtein distances. 
void printWord(WordDistance* wd, int numword)
{
  int limit = numword < 10 ? numword : 10;
  for (int ind = 0; ind < limit; ind++)
  {
    printf("%d, %s\n", wd[ind].distance, wd[ind].word);
  }
}
