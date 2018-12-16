#ifndef CHALLENGE_H
#define CHALLENGE_H

/*
Evaluate an arithmetic expression.

expression: a string that contains integers, '+', '-' or '*'

return: the answer of the expression

example:
evaluate("1+2*5") -> 11
evaluate("1+-2*5") -> -10
evaluate("0-9") -> -9

hint:
You are not required to handle integer overflow.
An expression will not be an empty string. 
*/
int evaluate(char* expression);

#endif
