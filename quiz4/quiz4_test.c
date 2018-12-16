#include <stdio.h>
#include <stdlib.h>
#include "quiz4.h"

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

void test_swap()
{
  start_test("Swap");
  char *a = "x";
  char *b = "y";
  swap(&a, &b);
  assert(a[0] == 'y');
  assert(b[0] == 'x');

  char *hi = "hi";
  char *bye = "bye";

  char *s1 = hi;
  char *s2 = bye;
  swap(&s1, &s2);

  assert(s1 == bye);
  assert(s2 == hi);
  end_test();
}

void test_strcmp()
{
  start_test("String Compare");
  assert(strcmp("hi", "hi") == 0);
  assert(strcmp("aardvark", "zebra") < 0);
  assert(strcmp("tiger", "alien") > 0);
  end_test();
}

void test_min_index()
{
  start_test("Min Index");
  char *strings1[] = {"shotgun", "attic", "fellow", "alien", "drown", "acoustic"};
  assert(min_index(strings1, sizeof(strings1) / sizeof(strings1[0])) == 5);

  char *strings2[] = {"whisper"};
  assert(min_index(strings2, sizeof(strings2) / sizeof(strings2[0])) == 0);

  char *strings3[] = {"herb", "captive", "dust", "light", "possess"};
  assert(min_index(strings3, sizeof(strings3) / sizeof(strings3[0])) == 1);
  end_test();
}

void test_sort()
{
  start_test("Sort");

  char *str1 = "equivalent";
  char *str2 = "mystical";
  char *str3 = "southern";
  char *str4 = "werewolf";
  char *str5 = "human";

  char *arr1[] = {str1, str2, str3, str4, str5};
  char *expected1[] = {str1, str5, str2, str3, str4};
  sort(arr1, 5);

  int i = 0;
  for(; i < 5; i++) {
    assert(arr1[i] = expected1[i]);
  }

  char *str6 = "complicated";
  char *str7 = "airtight";
  char *str8 = "lady";

  char *arr2[] = {str6, str7, str8};
  char *expected2[] = {str7, str6, str8};
  sort(arr2, 3);

  i = 0;
  for(; i < 3; i++) {
    assert(arr2[i] = expected2[i]);
  }

  end_test();
}

int **create_3x3(int arr[3][3])
{
  int i = 0;
  int **ret = malloc(sizeof(int *) * 3);
  for(; i < 3; i++) {
    ret[i] = malloc(sizeof(int) * 3);
    int j = 0;
    for(; j < 3; j++) {
      ret[i][j] = arr[i][j];
    }
  }
  return ret;
}

int **create_4x4(int arr[4][4])
{
  int i = 0;
  int **ret = malloc(sizeof(int *) * 4);
  for(; i < 4; i++) {
    ret[i] = malloc(sizeof(int) * 4);
    int j = 0;
    for(; j < 4; j++) {
      ret[i][j] = arr[i][j];
    }
  }
  return ret;
}

void free_array(int **arr, int n)
{
  int i = 0;
  for(; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
}

void test_is_magical()
{
  start_test("Magic Square");

  int test1[][3] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};
  int **allocated_test1 = create_3x3(test1);
  assert(is_magical(allocated_test1, 3));
  free_array(allocated_test1, 3);

  int test2[][4] = {{4, 14, 15, 1}, {9, 7, 6, 12}, {5, 11, 10, 8}, {16, 2, 3, 13}};
  int **allocated_test2 = create_4x4(test2);
  assert(is_magical(allocated_test2, 4));
  free_array(allocated_test2, 4);

  int test3[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int **allocated_test3 = create_3x3(test3);
  assert(!is_magical(allocated_test3, 3));
  free_array(allocated_test3, 3);

  end_test();
}

int main()
{
  test_swap();
  test_strcmp();
  test_min_index();
  test_sort();
  test_is_magical();

  return EXIT_SUCCESS;
}

