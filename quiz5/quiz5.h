#ifndef QUIZ5_H
#define QUIZ5_H

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
void crop_hi(int* arr, int len, int ceiling);

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
void swap_mid_back(int* arr, int len);

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
void redact(char* str);


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
void word_to_pig_latin(char* word, char* out);


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
void phrase_to_pig_latin(char* phrase, char* out); 

#endif
