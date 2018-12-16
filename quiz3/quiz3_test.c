#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quiz3.h"

#define assert(EXPRESSION) ((EXPRESSION) ? _assert_pass(#EXPRESSION, __FILE__, __LINE__) : \
                                           _assert_fail(#EXPRESSION, __FILE__, __LINE__))

void _assert_fail(const char *expression, const char *file, int line)
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

void test_print_even()
{
    start_test("Print Even");
    print_even(10);
    printf("\n\n");
    print_even(17);
    end_test();
}

void test_print_pattern()
{
    start_test("Print Pattern");
    print_pattern(4);
    printf("\n\n");
    print_pattern(6);
    end_test();
}

void test_grade()
{
    start_test("Grade");
    assert(grade(234) == 'A');
    assert(grade(47) == 'F');
    assert(grade(75) == 'C');
    assert(grade(94) == 'A');
    assert(grade(54) == 'E');
    assert(grade(87) == 'B');
    end_test();
}

void test_is_prime()
{
    start_test("Is Prime?");
    assert(is_prime(47) != 0);
    assert(is_prime(2) != 0);
    assert(is_prime(239) != 0);
    assert(is_prime(0) == 0);
    assert(is_prime(1) == 0);
    end_test();
}

void test_sum_of_digits()
{
    start_test("Sum of digits");
    assert(sum_of_digits(59) == 14);
    assert(sum_of_digits(0) == 0);
    assert(sum_of_digits(223) == 7);
    assert(sum_of_digits(64) == 10);
    end_test();
}

void test_reverse()
{
    start_test("Reverse");
    assert(reverse(59) == 95);
    assert(reverse(0) == 0);
    assert(reverse(222) == 222);
    assert(reverse(-64) == -46);
    end_test();
}

void test_calc()
{
    start_test("Calc");
    assert(fabs(calc(5, 6, '+') - 11) < 0.0001);
    assert(fabs(calc(8, 4, '-') - 4) < 0.0001);
    assert(fabs(calc(17, 4, '/') - 4.25) < 0.0001);
    assert(fabs(calc(3, 6, '*') - 18) < 0.0001);
    end_test();
}

int main(void)
{
    test_print_even();
    test_print_pattern();
    test_grade();
    test_is_prime();
    test_sum_of_digits();
    test_reverse();
    test_calc();

    return EXIT_SUCCESS;
}

