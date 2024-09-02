# Check Spelling (Structures + Sort)

Learning Goals
==============

* Understand how to calculate the distance of two words - https://en.wikipedia.org/wiki/Levenshtein_distance
* Understand structure
* Read data from a text file
* Calculate the distances between a word and all words in a file
* Sort the distances
* Print the words in the file with the smallest distance

Check Spelling Between two Words
==============
In this assignment, you will use a structure called "WordDistance" with an char array element and a integer element. The char array element will be used to store a word, and the corresponding integer will the the distance between this word and the input word.
Levenshtein distance is the amount of character changes you have to make to a word to turn it into another word, these changes include subtraction, addition, and subsitutions. an example of this can be seen between the word "purdue" and "pursue". there is only a levenshtein distance of 1, as you can just replace the s in pursue with d, or vice versa. If you look at the words "melt" and "sillow", there is a levenshtein distance of 5. the first two changes comes from repace "si" with "me" to form mellow, and then with subtracting the "ow" from the end of the string. That makes 4 changes. Then subsitute "l" with "t", and you get melt with a total of 5 changes. The formula for doing so is shown below: 
![image](https://github.com/user-attachments/assets/01aca60e-dba8-4b4f-9000-f0722bc44072)
More instructions on how to implement this can be accessed through the wikipedia link. You will implement this in levenshtein.c (hint: recursion is key). 

To generate the list of words used in testcases, usr/share/dict/words was used, which is a built-in linux file of a word list. You can even make your own testcases and play around with it if you like! To generate a random list of words (say 50 words), type into your terminal: "shuf -n 50 /usr/share/dict/words"

What to Do
==============
Complete the levenshtein function based on instructions above. 
In the checker.c function, you will open a file which consists of a list of words(1st input to main), which will be compared with a particular word(2nd input to main). You will first complete countWords(), the function to count how many words are in the list.

After that you will write readWords which read the words into a WordDistance array. During this step, you should keep in mind that there are testcases with over 41 characters, however MAXLENGTH, which is the length of the array, has a 41 character limit. Keep in mind that there might be a null terminating character '\0' at the end of your string, therefore you should only store the first 40 characters of the word to leave space for the null terminator at the end (will become relevant in test6).

Then, you will complete calculateDistance which will fill out the WordDistance array using all the words in the list. After that, you'll have to fill out compareDistance which will be used in sortDistance in order to sort, based on the value of the distance, the list of words that are closest in spelling to the input word. Lastly, printWord will print out the first 10 words closest to your input word, and their number.

Check Memory Leak
=================

Your program must not crash and must not leak memory.  Use Valgrind to check for leaks.

Functions Needed
================
In checker.c:
int countWords(char* filename)

bool readWords(char* filename, WordDistance* wd, int numword)

void calculateDistance(WordDistance* wd, int numword, const char* tocheck)

static int compareDistance(const void* ptr1, const void* ptr2)

void sortDistance(WordDistance* wd, int numword)

void printWord(WordDistance* wd, int numword)

In Levenshtein.c:
int Levenshtein(const char* str1, const char* str2)

	
Structure
=========
The structure looks like
``` 
typedef struct
{
  char word[MAXLENGTH]; 
  int distance;
} WordDistance;
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

