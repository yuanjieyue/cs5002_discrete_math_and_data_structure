#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz5.h"

#define assert(EXPRESSION) ((EXPRESSION) ? _assert_pass(#EXPRESSION, __FILE__, __LINE__) : \
                                           _assert_fail(#EXPRESSION, __FILE__, __LINE__))

void _assert_fail(const char* expression, const char* file, int line)
{
  fprintf(stderr, "Assertion '%s' failed, file '%s' line '%d'.\n", expression, file, line);
}

void _assert_pass(const char *expression, const char *file, int line)
{
  fprintf(stdout, "Assertion '%s' passed, file '%s' line '%d'.\n", expression, file, line);
}

void start_test(const char *test)
{
  static int count = 1;
  printf("Test #%d: %s\n\n", count++, test);
}

void end_test()
{
  printf("\n--------------------------------\n\n");
}

void arrays_equal(int* actual, int* expected, int len) {
  int i;
  for (i = 0; i < len; i++) {
    assert(actual[i] == expected[i]);
  }
}

void test_crop_hi() {
  start_test("test_crop_hi()");

  int arr1[4] = { 3, 1, 2, 4 };
  int ceiling1 = 2;
  int expected1[4] = {ceiling1, 1, 2, ceiling1};
  crop_hi(arr1, 4, ceiling1);
  arrays_equal(arr1, expected1, 4);

  int arr2[3] = { -2, 1, 3};
  int ceiling2 = -3;
  int expected2[3] = {ceiling2, ceiling2, ceiling2};
  crop_hi(arr2, 3, ceiling2);
  arrays_equal(arr2, expected2, 3);

  end_test();
}

void test_swap_mid_back() {
  start_test("test_swap_mid_back()");

  // case: even number of elements
  int arr1[4] = { 1, 2, 3, 4 };
  int expected1[4] = { 1, 4, 3, 2 };
  swap_mid_back(arr1, 4);
  arrays_equal(arr1, expected1, 4);

  // case: odd number of elements
  int arr2[5] = { 1, 2, 3, 4, 5};
  int expected2[5] = { 1, 2, 5, 4, 3 };
  swap_mid_back(arr2, 5);
  arrays_equal(arr2, expected2, 5);

  end_test();
}

void test_redact() {
  start_test("test_redact()");

  char str1[] = "52%";
  char expected1[] = "**%";
  redact(str1);
  assert(strcmp(str1, expected1) == 0);

  char str2[] = "10. And then there were 19.";
  char expected2[] = "**. And then there were **.";
  redact(str2);
  assert(strcmp(str2, expected2) == 0);

  char str3[] = "There were 46 failures.";
  char expected3[] = "There were ** failures.";

  redact(str3);
  assert(strcmp(str3, expected3) == 0); 
  
  end_test();
}

void test_word_to_pig_latin() {
  start_test("test_word_to_pig_latin()");

  char in1[] = "phone";
  char out[strlen(in1) + 3];
  char* exp1 = "honepay";
  word_to_pig_latin(in1, out); 
  assert(strcmp(exp1, out) == 0);

  end_test();
}

void test_phrase_to_pig_latin(){
  start_test("test_phase_to_pig_latin()");

  char in1[] = "The phone is broken";
  char out[strlen(in1) + 9]; 
  char* exp1 = "heTay honepay siay rokenbay";
  phrase_to_pig_latin(in1, out);
  assert(strcmp(exp1, out) == 0);
  end_test(); 
  
  
}

int main()
{
  test_crop_hi();
  test_swap_mid_back();
  test_redact();

  test_word_to_pig_latin();
  test_phrase_to_pig_latin();

  return EXIT_SUCCESS;
}
