#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "challenge.h"
 
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0

struct Stack
{
  int top;
  char stack[MAXSIZE];
}st;

void initialize(){
  st.top = -1;  
}

int isFull(){
  if(st.top >= MAXSIZE - 1)
    return TRUE;
  else
    return FALSE;
}

int isEmpty(){
  if(st.top == -1)
    return TRUE;
  else
    return FALSE;
}

void push(char c){
  if(isFull())
    printf("The stack is overflow....\n");
  else{
    st.stack[st.top + 1] = c;
    st.top++;
  }
}

char pop(){
  if(isEmpty()){
    printf("The stack is empty...");
  }
  else{
    st.top--;
    return st.stack[st.top + 1];
  }
  return 0;
}


int count_valid_parentheses(char *parentheses){
  int count = 0, i;
  int if_push = 0;
  initialize();
  for(i = 0; i < sizeof(parentheses) / sizeof(char); i++){
    if(parentheses[i] == '('){
      push(parentheses[i]);
      if_push++;
    }
    else if(if_push && parentheses[i] == ')'){
      pop();
      count++;
      if_push--;
    }  
  }  
  return count;
}

