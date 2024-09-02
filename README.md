# Check Spelling (Structures + Sort)

Learning Goals
==============

* Understand how to calculate the distance of two words - https://en.wikipedia.org/wiki/Levenshtein_distance
* Understand structure
* Read data from a text file
* Calculate the distances between a word and all words in a file
* Sort the distances
* Print the words in the file with the smallest distance

Check Memory Leak
=================

Your program must not crash and must not leak memory.  Use Valgrind to check for leaks.

Functions Needed
================
In checker.c:
int countWords(char* filename);
bool readWords(char* filename, WordDistance* wd, int numword);
void calculateDistance(WordDistance* wd, int numword, const char* tocheck);
static int compareDistance(const void* ptr1, const void* ptr2);
void sortDistance(WordDistance* wd, int numword);
void printWord(WordDistance* wd, int numword);
In Levenshtein.c:
int Levenshtein(const char* str1, const char* str2)

	
Structure
=========
The structure looks like
``` 
    	#typedef struct
	{
	} 
```

WHAT TO SUBMIT
==============

You **must** follow the instructions precisely. Failing to follow
these instructions will likely make you receive zero in this
assignment.  Your score **is determined by your submission**, nothing
else.  The teaching staff is strictly prohibited seeing anything on
your computer for grading.

```
levenshtein.c, checker.c
```

Upload `hw06.zip`.

