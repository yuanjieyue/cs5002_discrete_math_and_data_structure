#ifndef QUIZ3_H
#define QUIZ3_H

/*
 * Print all even numbers up to, and including  n
 */
void print_even(int n);

/*
 * Print this pattern for upto n rows (n > 0). For example, if n = 5:
 *
 *         #####
 *         ####
 *         ###
 *         ##
 *         #
 *
 */
void print_pattern(int n);

/*
 * Given a score >= 0, return its corresponding grade letter based
 * on this table.

 * 0  - 49: F
 * 50 - 59: E
 * 60 - 69: D
 * 70 - 79: C
 * 80 - 89: B
 * 90+    : A
 */
char grade(int score);

/*
 * In C, boolean types (i.e., true or false) are actually integers
 * which evaluate to true if the value is non-zero.
 * Write a function that returns true if n is prime, false otherwise.
 */
int is_prime(int n);

/*
 * Return the sum of all digits for the input n. Assume n is
 * non-negative.
 */
int sum_of_digits(int n);

/*
 * This function should calculate the reverse of the input
 * number n and return it. Preserve the sign of the number. If
 * it is negative the returned value should be negative and
 * vice versa.
 */
int reverse(int n);

/*
 * Given an operator (one of '+', '-', '*', '/'), and two numbers
 * calculate the result of applying that operation to the two
 * numbers.
 *
 * Bonus points for using a switch statement.
 */
float calc(int x, int y, char op);

#endif
