[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/cI_ddl8M)
# Read Line from File and Count Word

### Due 02/18 at 11:59pm

Learning Goals 
==============

This assignment asks you to write a program that reads lines from a file,
counts how many times a word occurs, and report the result.

You will learn to
* Read lines and store as strings
* Detect whether one string is inside another string

Read Line from File and Count Words
===================================

This assignment uses `fgets` to read strings from a file, uses
`strstr` to find whehther a word is inside the string from the file.
This assignment is a simplified version of the `grep` command in
Linux.

What To Do
==========

You need to write a function called `countWord(char * filename, char * word, char * line, int size)` 
that opens a file named `filename`, counts the number of occurences of given word in the file,
and returns it. If `fopen()` fails, return -1, and **DO NOT** fclose.
Further instructions are in the comments in the function in file `filestr.c`.


Check Memory Leak
=================

Your program must not crash and must not leak memory.   The leaked bytes will
accumulate across all test cases in each assignment. If your program
leaks memory, it is very likely that you will receive zero.  Please
use `valgrind` to check memory errors. A program that leaks memory is
like an airplane that leaks fuel. Neither can be accepted.

WHAT TO SUBMIT
==============

Submit the following files to gradescope as a zip file: 'main.c', 'filestr.c', 'hw05.h'.

Test Inputs
===========

The test inputs are famous speeches
