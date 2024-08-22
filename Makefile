WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

build: hw01-6.c
	$(GCC) hw01-6.c -o hw01-6

test1: build
	./hw01-6 4 5 > output1
	diff output1 expected/expected1

test2: build
	./hw01-6 987 321 > output2
	diff output2 expected/expected2

clean: # remove all machine generated files
	rm -f hw01-6 output? *~




