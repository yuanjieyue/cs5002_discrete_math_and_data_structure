#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz5.h"

// TODO: implement funcitons in quiz5.c

/**
 * Write a function that replaces all numbers greater
 * than ceiling in arr with ceiling.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *
 * Example(s):
 * - crop_hi([1, 2, 3, 4], 4, 2) :: [1, 2, 2, 2]
 * - crop_hi([-3, 17,  7, -12, 10], 5, 8) :: [-3, 8, 7, -12, 8]
 *
 * @param arr     array of integers
 * @param len     length of arr
 * @param ceiling upper limit for ints in array
 */
void crop_hi(int* arr, int len, int ceiling){
  int i;
  for(i = 0; i < len; i++){
    if(arr[i] > ceiling){
      arr[i] = ceiling;
    }
  }
}                   

/**
 * Swaps the the last int in arr with the middle element in arr.
 *
 * Precondition(s):
 * - len > 0 (i.e. arrays MUST have at least one element)
 *
 * Example(s):
 * - swap_mid_back([1, 2, 3], 3) :: [1, 3, 2]
 * - swap_mid_back([-4, 3, 0, 1], 4) :: [-4, 1, 0, 3]
 *
 * @param arr array of integers
 * @param len length of arr
 */
void swap_mid_back(int* arr, int len){
  int mid = (int)((float)len/2 + 0.5);
  int temp;
  temp = arr[mid-1];
  arr[mid-1] = arr[len-1];
  arr[len-1] = temp;  
}

/**
 * Replaces all digits in a string with a '*'. 
 * 
 *
 * Example(s):
 * - redact("The part failed 58% of the time") ::
 *          "The part failed **% of the time"
 * - redact("There were 13 As in the class") :: "There were ** As in the class"
 *
 * @param  str      host string for old_char
 */
void redact(char* str){
  int i;
  for(i = 0; str[i] != '\0'; i++){
    if(str[i] >= '0' && str[i] <= '9'){
      str[i] = '*';
    }
  }
}


/**
 * Pig latin is an amusing way to encrypt messages. 
 * A word is converted from English to Pig Latin by 
 * taking the first letter from the word, putting it 
 * at the end, and adding 'ay' to it. 
 * 
 * Write a function to translate an English message to 
 * Pig Latin. 
 *
 * @param word the input word
 * @param where to write the encoded output
 *
 * Example: 
 * word_to_pig_latin("phone") :: "honepay"
 * word_to_pig_latin("box") :: "oxbay"
 */
void word_to_pig_latin(char* word, char* out){
  char first = word[0];
  int i, count = 0;
  for(i = 1; word[i] != '\0'; i++){
    out[i-1] = word[i];
    count++;    
  }
  out[count] = first;
  out[count + 1] = 'a';
  out[count + 2] = 'y';
}


/** 
 * Write a function to tranlate an entire phrase from 
 * English to Pig Latin. 
 *
 * Hint: Use the token function from the presentation. 
 *
 * Assume there are no punctuation characters to deal with. 
 * 
 * @param phrase to convert to pig latin
 * @param out the array to write the converted phrase to
 *
 */

void phrase_to_pig_latin(char* phrase, char* out){
  int i;
  char *s[30], *p;

  i = 0;
  p = strtok(phrase, " ");
  while(p != NULL){
    s[i] = (char*)malloc(strlen(p)+1);
    strcpy(s[i], p);
    p = strtok(NULL, " ");
    i++;
  }
  int j;
  for(j = 0; j < i; j++){
    char *word_out;
    word_out = (char*)malloc(strlen(s[j]) + 3);
    word_to_pig_latin(s[j], word_out);

    if(j != i-1){
      strcat(word_out, " ");
    }
    strcpy(out, word_out);
    out += strlen(word_out);
  }
}
