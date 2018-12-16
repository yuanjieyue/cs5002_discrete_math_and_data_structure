#include <stdio.h>
#include "set1.h"

int salaries[] = {4400, 3010, 3700, 5600, 7800, 6100, 7700, 4050, 2900};
int salaries_length = sizeof(salaries) / sizeof(salaries[0]);

int sorted[] = {4, 6, 8, 17, 17, 18, 24, 29, 31, 33, 45, 50};
int sorted_length = sizeof(sorted) / sizeof(sorted[0]);

/*
 * This function should print all the numbers from to 1 to the number specified by
 * length. When the number is divisible by fizz_num, it should instead print 'Fizz'.
 * Similarly, when the number is divisble by buzz_num, it should print 'Buzz', and
 * when the number is divisible by bang_num, it should print 'Bang'.
 *
 * If the number is divisible by more than one of the three specified numbers, it should
 * print the equivalent for all divisible numbers.
 *
 * For example, for the call fizzbuzzbang(60, 2, 3, 5):
 * 1                       // 1
 * Fizz                    // 2
 * Buzz                    // 3
 * Fizz                    // 4
 * Bang                    // 5
 * FizzBuzz                // 6
 * 7                       // 7
 * ...
 * BuzzBang                // 15
 * ...
 * FizzBuzzBang            // 30
 * ...
 *
 * You do not need to print what is shown as a comment in the sample output above.
 */
void fizzbuzzbang(int length, int fizz_num, int buzz_num, int bang_num)
{
  int i;
  int isFizz = 0;
  int isBuzz = 0;
  int isBang = 0;
  for(i = 1; i <= length; i++){
    isFizz = i % fizz_num == 0;
    isBuzz = i % buzz_num == 0;
    isBang = i % bang_num == 0;
    if(isFizz || isBuzz || isBang){
      if(isFizz){
        printf("%s", "Fizz");
      }
      if(isBuzz){
	printf("%s", "Buzz");
      }
      if(isBang){
	printf("%s", "Bang");
      }
    }
    else {
      printf("%d",i);
    }
    printf("\n");
  }
}

/*
 * Return the number of employees whose salary is in between lower and upper.
 * The employees' salaries are specified in the array called salaries.
 * Consider the lower and upper bounds to be inclusive in your calculation
 * (which mean that if salary == lower it should included in the total and
 * same with upper values being included).
 * The number of salaries present in the array is stored in the variable
 * salaries_length.
 */
int salary_range(int lower_bound, int upper_bound)
{
  int numOfEmployee = 0;
  int i;
  for(i = 0; i < salaries_length; i++){
    if(salaries[i] >= lower_bound && salaries[i] <= upper_bound){
      numOfEmployee++;
    }
  }
  return numOfEmployee;
}

/*
 * This function should print n numbers all in one line
 * where each number i should repeat i times.
 *
 * For example, print_numbers(5) -> 122333444455555
 *              print_numbers(3) -> 122333
 */
void print_numbers(int n)
{
  int i;
  for(i = 1; i <= n; i++){
    int j;
    for(j = 0; j < i; j++){
      printf("%d", i);
    }
  }
}

/*
 * For the sorted array called sorted, calculate the
 * the average. The length of this array is stored in the variable
 * sorted_length.
 * ref: https://www.khanacademy.org/math/statistics-probability/summarizing-quantitative-data/mean-median-basics/a/mean-median-and-mode-review
 */
float mean()
{
  float aver = 0;
  int sum = 0;
  int i;
  for(i = 0; i < sorted_length; i++){
    sum += sorted[i];
  }
  aver = (float)sum / sorted_length;

  return aver;
}

/*
 * For the sorted array called sorted, calculate the
 * the median. The length of this array is stored in the variable
 * sorted_length.
 */
float median()
{
  float median = 0;
  if(sorted_length % 2 ==0){
    median = (sorted[(sorted_length - 1) / 2] + sorted[(sorted_length - 1) / 2 + 1]) / 2;
  }
  else {
    median = sorted[(sorted_length - 1) / 2];
  }

  return median;
}

/*
 * For the sorted array called sorted, calculate the
 * the mode. The length of this array is stored in the variable
 * sorted_length.
 */
int mode()
{
  int count = 1;
  int maxCount = 1;
  int i, mode;
  for(i = 1; i <= sorted_length; i++){
    if(sorted[i-1] == sorted[i]){
      count++;
    }
    if(maxCount < count){
      maxCount = count;
      mode = sorted[i];
    }
    count = 1;
  }
  if(maxCount == 1){
    return 0;
  }
  else{
    return mode;
  }
}

/*
 * Given a base and exponent, this function should return
 * the base raised to the exponent. Assume that base >= 0
 * and exponent >= 0 always. Further you can assume that
 * base and exponent will never both be zero.
 */
int power(int base, int exp)
{
  int power = 1;
  int i;
  if(base == 0){
    power = 0;
  }
  else if(exp == 0){
    power = 1;
  }
  else{
    for(i = 0; i < exp; i++){
      power *= base;
    }
  }

  return power;
}

/*
 * Given an integer (negative or positive), return the
 * first (most-significant) digit.
 */
int first_digit(int n)
{
  int first_digit;
  int i;
  if(n == 0){
    first_digit = 0;
  }
  while( n != 0){
    if(n > 0){
      first_digit = n;
    }
    else{
      first_digit = -n;
    }
    n /= 10;
  }
  return first_digit;
}
