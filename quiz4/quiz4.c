#include <stdio.h>
#include <stdlib.h>
#include "quiz4.h"

#define TRUE 1
#define FALSE 0

// This time around, you will be required to fill this file out entirely by yourself.
// Make sure that function signature match the ones defined in the header file.
// Look at the how the previous quiz was set up if you have trouble doing this.

/*
 * Write a function to swap two strings stored pointed to by a and b. 
 * After executing this funciton, a should point at the string b is 
 * originally pointing to, and b should point at the string a is pointing to. 
 * 
 * Think about why this function can't be be implemented without pointers. 
 * 
 * a: A pointer to a string
 * b: A pointer to a string
 */

 void swap(char **a, char **b)
{
  char *temp;
  temp = *a;
  *a = *b;
  *b = temp;
}     


/*
 * Given two strings s1 & s2, return:
 * -1 if s1 occurs before s2 in lexicographical order
 * 0 if they are equal
 * 1 if s1 occurs after s2 in lexicographical order
 *
 * If the two strings begin the same, but have different lengths, 
 * the shorter one is first in lexicographical order. 
 *
 * Assume both inputs are a string of length 1 or greater. 
 * 
 * Example: 
 * strcmp("butter", "butterfly") = -1
 * strcmp("caterpillar", "cat") = 1
 * strcmp("apple", "banana") = -1
 * strcmp("table", "table") = 0
 * 
 * Note: Do NOT use functions declared in string.h
 */

int strcmp(char *s1, char *s2){
  while(*s1 == *s2){
    if(*s1 == '\0'){
      return 0;
    }
    s1++;
    s2++;
  }
  if(*s1 < *s2)
    return -1;
  else
    return 1;
}

/*
 * Given an array of strings, return the index of the string with the *smallest*. 
 * value as defined by your previous function - strcmp.
 *
 * If there is a duplicate word that is the smallest/least, 
 * return the index of the first one. 
 * 
 * Assume the array of strings contains at least one string. 
 *
 * Note: Do NOT use functions from string.h. 
 *
 * Example: 
 * min_index(['one', 'two', 'three'], 3) = 0
 * min_index(['caterpillar', 'butterfly', 'bug'], 3) = 3
 * min_index(['alpha', 'beta', 'gamma'], 3) = 0
 * min_index(['beta', 'alpha', 'gamma'], 3) = 1
 * min_index(['alpha', 'alpha', 'beta'], 3) = 0

 */

int min_index(char **arr, int n){
  int i;
  char *temp = *arr;
  int min = 0;
  for(i = 0; i < n; i++){
    int cpm;
    cpm = strcmp(temp, *(arr+i));
    if(cpm > 0){
      temp = *(arr+i);
      min = i;
    }
  }
  return min;    		     
}

/*
 * Using the min and swap functions you previously wrote, implement
 * a function that sorts strings in lexicographical order using the
 * following logic:
 * 
 * while i <  N - 1:
 *   select smallest string from array starting at index i
 *   swap with element at index i
 *
 * Some questions to think about while implementing your solution:
 *
 * How would you use the min function as defined above to select
 * the smallest string starting at some index?
 *
 * Example: 
 * sort(["one", "two", "three"], 3) = ["one", "three", "two"] (Note: the input array is modified, not returned)
 * sort(["butterfly", "caterpillar", "apple"), 3) = ["apple", "butterfly", "caterpillar"]
 * 
 * arr: a pointer to an array of strings
 * len: the number of strings in the arr array
 */
void sort(char **arr, int len){
  int i;
  for(i = 0; i < len; i++, len--){
    int index = 0;
    index = min_index((arr+i), len);
    swap((arr+i), (arr+i+index));    
  }
}

/*
 * Given a 2D N x N array matrix of ints, return True if the
 * matrix is a magic square, False otherwise.
 * 
 * A magic square is defined as one that is filled with distinct
 * integers in the range 1, 2, ..., n^2 and in which every row, column,
  for(i = 0 ; i < n ;i++){
    for(j = 0 ; j < n;j++){
      temp[i] += matrix[i][j];
    }
  } * and diagonal add up to the same number.
 *
 * Example: 
 * is_magical([[8, 1, 6],[3, 5, 7],[4, 9, 2]], 3) = true;
 * is_magical([[1, 2],[3, 4]]), 2) = false; 
 * 
 * matrix is a pointer to a 2D array 
 * n is number of columns and rows in that 2D array
 */
int is_magical(int **matrix, int n){
  int is_mag = TRUE;
  int *temp;
  temp = (int*)calloc(2*n+2, sizeof(int)); // apply for a block of memory to store the sum of rows, sum of columns and sum of diagonals.
  int i, j, k = 0;
  for(i = 0 ; i < n ;i++){                 //counting the sum of each rows and put them into the temp array.
    for(j = 0 ; j < n;j++){
      temp[i] += matrix[i][j];
    }
  }
  for(i = 0; i < n ;i++){                  //counting the sum of each columns and put them into the temp array.
    for(j = 0 ; j < n;j++){
      temp[n+i] += matrix[j][i];
    }
  }
  for(i = 0 ; i < n ;i++){                  //counting the sum of two diagonals and put them into the temp array.
    for(j = 0 ; j < n;j++){
      if(i == j){
	temp[2*n] += matrix[i][j];
	temp[2*n+1] += matrix[i][n-1-j];
      }
    }
  }
  for(i = 0 ; i < 2*n+1; i++){
    if(temp[i] != temp[i + 1]){
      is_mag = FALSE;                       //if there is a item that is not equal to the other, change the is_mag variable to FALSE
      return is_mag;
    }
  }
  return is_mag;
}



