all: clean challenge

challenge: challenge.h challenge.c challenge_test.c
	gcc -std=c99 -Wall -Werror -pedantic -o challenge challenge.c challenge_test.c

clean:
	rm -f challenge
