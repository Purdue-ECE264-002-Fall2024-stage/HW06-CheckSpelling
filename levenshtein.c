#include <string.h>
#include <stdio.h>
// algorithm described on
// https://en.wikipedia.org/wiki/Levenshtein_distance
int Levenshtein(const char * str1, const char * str2, int* ct1, int* ct2)
{

  
int count1 = *ct1;
int count2 = *ct2;
int LargerCt;

if (count1 > count2)
{
  LargerCt = count1;
}
else
{
  LargerCt = count2;
}


if ((*str1) == (*str2)) //if equal 
{
  *ct1 = 0;
  *ct2 = 0;
  if((strlen(str1) == 1) | (strlen(str2) == 1)) //if either is last character
  {
    if(strlen(str1) == 1)
    {
      return LargerCt + (int)(strlen(str2) - 1);
    }
    else
    {
      return LargerCt + (int)(strlen(str1) - 1);
    }
  }
  else //if neither is last character
  {
    return LargerCt + Levenshtein(str1 + 1, str2 + 1, ct1, ct2);
  }
}
else //if not equal
{
  if((strlen(str1) == 1) | (strlen(str2) == 1)) //if last character
  {
    if ((strlen(str1) == 1)&(strlen(str2) == 1)) //if last character for both
    {
      *ct1 = 0;
      *ct2 = 0;      
      LargerCt++;
      return (LargerCt);
    }
    else if (strlen(str1) == 1)//if only str1 is last character
    {
      *ct1 = 0;
      *ct2 = count2 + 1;
      return Levenshtein((str1 - count1), str2 + 1, ct1, ct2);
    }
    else //if only str1 is last character
    {
      *ct1 = count1 + 1;
      return Levenshtein(str1 + 1, str2, ct1, ct2);
    }
  }
  else //if neither is last character
  {
    *ct1 = count1 + 1;
    return Levenshtein(str1 + 1, str2, ct1, ct2);
  }
}

}




  


//what does the strlen(str) == 0 symbolize? does it mean that the string ends here?
//so it adds on one if the two characters are different (spelling is dif)
//and just repeats until one string ends? what is the strlen(str) of a str if not 0
