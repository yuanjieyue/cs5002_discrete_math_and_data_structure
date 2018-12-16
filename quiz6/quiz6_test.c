#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quiz6.h"

Name name1;
Name name2;
Name name3;
Name name4;

Couple couple1 = {&name1, &name2, NULL, 0};
Couple couple2 = {&name3, &name4, NULL, 0};

void init()
{
  srand(time(NULL));

  name1.first = female_names[0];
  name1.middle = female_names[3];
  name1.last = last_names[8];

  name2.first = male_names[4];
  name2.middle = male_names[7];
  name2.last = last_names[9];

  name3.first = female_names[2];
  name3.middle = female_names[6];
  name3.last = last_names[7];

  name4.first = male_names[1];
  name4.last = last_names[4];
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


void test_big()
{
  start_test("Print Big");

  big(&name1);
  big(&name2);
  big(&name4);

  end_test();
}

void test_last()
{
  start_test("Print Last");

  last(&name2);
  last(&name4);

  end_test();
}

void test_reg()
{
  start_test("Print Reg");

  reg(&name3);
  reg(&name4);

  end_test();
}

void test_mid()
{
  start_test("Print Mid");

  mid(&name4);
  mid(&name1);

  end_test();
}

void test_small()
{
  start_test("Print Small");

  small(&name4);
  small(&name2);

  end_test();
}

void test_fmt()
{
  start_test("Print Fmt");

  fmt(&name1, 'B');
  fmt(&name1, 'L');
  fmt(&name1, 'R');
  fmt(&name1, 'M');
  fmt(&name1, 'S');

  fmt(&name4, 'B');
  fmt(&name4, 'L');
  fmt(&name4, 'R');
  fmt(&name4, 'M');
  fmt(&name4, 'S');

  end_test();
}

void test_generate_random()
{
  start_test("Random Name");

  Name rand1 = generate_random();
  Name rand2 = generate_random();

  fmt(&rand1, 'L');
  fmt(&rand2, 'L');

  end_test();
}

void test_generate_and_fmt_random_array()
{
  start_test("Random Name Array");

  Name names[5]; 

  generate_random_array(names, 5);
  fmt_array(names, 5, 'L');
  fmt_array(names, 5, 'S');

  end_test();
}

void test_fmt_array(){
  start_test("Format Array");
  
  printf("Create this test\n");

  end_test(); 
}

void test_couple_name()
{
  start_test("Print Couple Name");

  couple_name(&couple1);
  couple_name(&couple2);

  end_test();
}


void test_new_couple_and_family()
{
  start_test("New Couple");

  Couple c1 = new_couple(&name1, &name2);
  Couple c2 = new_couple(&name3, &name4);

  family(&c1);
  family(&c2);


  end_test();
}

void test_wedding()
{
  start_test("Wedding");

  Couple groom_parents = new_couple(&name1, &name2);
  Couple bride_parents = new_couple(&name3, &name4);

  Couple new_couple = wedding(&bride_parents, &groom_parents);

  announce(&bride_parents, &groom_parents, &new_couple); 

  couple_name(&new_couple);

  end_test();
}


int main(void)
{
  init();
  
  test_big();
  test_last();
  test_reg();
  test_mid();
  test_small();
  test_fmt();
  
  test_generate_random();
  test_generate_and_fmt_random_array();
  
  test_fmt_array(); 
  test_couple_name();
  test_new_couple_and_family();

  test_wedding(); 
  
  return EXIT_SUCCESS;
}

