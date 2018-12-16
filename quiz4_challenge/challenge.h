#ifndef CHALLENGE_H
#define CHALLENGE_H

/*
Count the number of valid parentheses in a given string

parentheses: a string contains only '(' or ')'

return: the number of valid parentheses in a given string

example:
count_valid_parentheses("(())") -> 2
count_valid_parentheses("(") -> 0
count_valid_parentheses("(()") -> 1
*/
int count_valid_parentheses(char* parentheses);

#endif