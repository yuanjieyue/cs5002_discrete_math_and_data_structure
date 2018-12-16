#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "challenge.h"


/*
Evaluate an arithmetic expression.
expression: a string that contains only non-negative integers, '+', '-' and '*' operators
return: the answer of the expression
example:
evaluate("1+2*5") -> 11
evaluate("1-2*5") -> -9
evaluate("0-9") -> -9
hint:
You are not required to handle integer overflow.
An expression will not be an empty string. 
*/

int evaluate(char *expression)
{
  char *numbers;
  numbers = (char*)malloc(strlen(expression)*sizeof(char));
  char *operators;
  operators = (char*)malloc(strlen(expression)*sizeof(char));
  int i, j = 0, k = 0;
  for(i = 0; i < strlen(expression); i++){
    if(*(expression + i) >= '0' && *(expression + i) <= '9' ){
      *(numbers + j++) = *(expression + i) - '0';
    }
    else if(*(expression + i) == '+' || *(expression + i) == '-' || *(expression + i) == '*'){
	*(operators + k++) = *(expression + i);
      }
  }
    for(i = 0; i < strlen(operators); i++){
      if(*(operators + i) == '*'){
	*(numbers + i) = *(numbers + i) * *(numbers + i + 1);
	int m;
	for(m = i; m < strlen(operators); m++){
	  *(operators + m) = *(operators + m + 1);
	  *(numbers + m + 1) = *(numbers + m + 2);
	}
      }
    }
    for(i = 0; i < strlen(operators); i++){
      int m;
      if(*(operators + i) == '+'){
	*(numbers + i) = *(numbers + i) + *(numbers + i + 1);
	for(m = i; m < strlen(operators); m++){
	  *(operators + m) = *(operators + m + 1);
	  *(numbers + m + 1) = *(numbers + m + 2);
	}
      }
      else{
	*(numbers + i) = *(numbers + i) - *(numbers + i + 1);
	for(m = i; m < strlen(operators); m++){
	  *(operators + m) = *(operators + m + 1);
	  *(numbers + m + 1) = *(numbers + m + 2);
	}
      }
		
    }

    return *numbers;
}




