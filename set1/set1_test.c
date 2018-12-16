#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "set1.h"

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

void test_fizzbuzzbang()
{
  start_test("FizzBuzzBang");
  fizzbuzzbang(60, 2, 3, 5);
  printf("\n\n");
  fizzbuzzbang(100, 2, 4, 8);
  printf("\n\n");
  fizzbuzzbang(50, 3, 7, 5);
  end_test();
}

void test_salary_range()
{
  start_test("Salary Range");
  assert(salary_range(1000, 8000) == 9);
  assert(salary_range(100, 200) == 0);
  assert(salary_range(3000, 5000) == 4);
  assert(salary_range(2000, 7000) == 7);
  end_test();
}

void test_print_numbers()
{
  start_test("Print Numbers");
  print_numbers(3);
  print_numbers(7);
  end_test();
}

void test_mean()
{
  start_test("Mean");
  assert(fabs(mean() - 23.5) < 0.0001);
  end_test();
}

void test_median()
{
  start_test("Median");
  assert(fabs(median() - 21.0) < 0.0001);
  end_test();
}

void test_mode()
{
  start_test("Mode");
  assert(mode() == 17);
  end_test();
}

void test_power()
{
  start_test("Power");
  assert(power(8, 2) == 64);
  assert(power(2, 7) == 128);
  assert(power(7, 3) == 343);
  assert(power(3, 5) == 243);
  end_test();
}

void test_first_digit()
{
  start_test("First Digit");
  assert(first_digit(0) == 0);
  assert(first_digit(2222) == 2);
  assert(first_digit(6287) == 6);
  assert(first_digit(1832) == 1);
  assert(first_digit(-234) == 2);
  end_test();
}

int main()
{
  test_fizzbuzzbang();
  test_salary_range();
  test_print_numbers();
  test_mean();
  test_median();
  test_mode();
  test_power();
  test_first_digit();

  return EXIT_SUCCESS;
}

