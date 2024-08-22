# Read Check Spelling from Word

### Due 09/30 at 11:59pm

Learning Goals 
==============

This assignment asks you to write a program that checks the spelling of a word from a string.

You will learn to
* Read lines and store as strings
* Detect if spelling distance is off from normal

Read Word from String and Check Spelling
===================================

This assignment uses `fgets` to read strings from a file, uses
`strstr` to find whehther a word is inside the string from the file.
This assignment is a simplified version of the `grep` command in
Linux.

What To Do
==========

You need to write a function called `checkSpell(char * filename, char * word, char * line, int size)` 
that opens a file named `filename`, counts the number of occurences of given word in the file,
and returns it. If `fopen()` fails, return -1, and **DO NOT** fclose.
Further instructions are in the comments in the function in file `checkSpell.c`.


Check Memory Leak
=================

Your program must not crash and must not leak memory.   The leaked bytes will
accumulate across all test cases in each assignment. If your program
leaks memory, it is very likely that you will receive zero.  Please
use `valgrind` to check memory errors. A program that leaks memory is
like an airplane that leaks fuel. Neither can be accepted.

WHAT TO SUBMIT
==============

Submit the following files to gradescope as a zip file: 'main.c', 'checkSpell.c', 'hw06.h'.

Test Inputs
===========

The test inputs are famous speeches
