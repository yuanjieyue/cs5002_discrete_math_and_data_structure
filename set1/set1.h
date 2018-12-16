#ifndef SET1_H
#define SET1_H

extern int salaries[];
extern int salaries_length;

extern int sorted[];
extern int sorted_length;

void fizzbuzzbang(int length, int fizz_num, int buzz_num, int bang_num);

int salary_range(int lower_bound, int upper_bound);

void print_numbers(int n);

float mean();
float median();
int mode();

int power(int base, int exp);

int first_digit(int n);

#endif

