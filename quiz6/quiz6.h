#ifndef QUIZ6_H
#define QUIZ6_H

#define MAX_NUM_KIDS 5 

/*
 * In this quiz, you'll get experience with structs and random. 
 * 
 * We haven't covered random in class, but it has been in the notes, and is a 
 * handy thing to get experience with. See Flashcard 5.21 (Loops->rand). 
 * Assume the generator as been seeded (you don't need to call srand at all). 
 * 
 * A reference: 
 * To get a random number in a range between 0 and (n-1), call: 
 * rand() % n; 
 * 
 * That's it! 
 * 
 * An explanation: 
 * rand() generates a number between 0 and some big number (>= 32767). 
 * To reduce it to a number between 0 and, say, 5, we divide by 6-- 
 * the remainder will be between 0 and 5 (there will be 6 possible values). 
 * If we really want a number between 1 and 6 (inclusive) rather than 0 and 5, we can shift it: 
 * x = (rand() % 6) + 1; 
 * 
 * Ask on Piazza with any other questions! 
 */

// A Name consists of first, last, and
// and an OPTIONAL middle name.
struct Name {
  char *first;
  char *middle;
  char *last;
};

typedef struct Name Name;

// A "couple" consists of a wife, hubby and their
// kids. They could have no kids in which case
// nums_kids == 0 && kids == NULL
struct couple {
  Name *hubby;
  Name *wife;
  Name kids[MAX_NUM_KIDS];
  int num_kids;
};

typedef struct couple Couple; 


extern char *female_names[];
extern char *male_names[];
extern char *last_names[];
extern const int LENGTH;


/*
 * Print the string <first> <middle> <last>
 * e.g. if first = "Marlin", middle = "Jay",
 * and last = "Eller", then print:
 * Marlin Jay Eller
 * 
 * If the middle name is NULL, then print: 
 * Marlin Eller
 *
 * name: a pointer to a Name
 */
void big(Name *name);


/*
 * Print the string <last>, <first>
 * For the same example as used previously, print:
 * Eller, Marlin
 *
 * name: a pointer to a Name
 */
void last(Name *name);


/*
 * Print the string <first> <last>
 * For the same example, this would be:
 * "Marlin Eller"
 * (regular usage)
 *
 * name: a pointer to a Name
 */
void reg(Name *name);


/*
 * Print <first> <middle-initial><dot> <last>
 * For the same example, this would print:
 * Marlin J. Eller
 * 
 * If the middle name is NULL, print: 
 * Marlin Eller
 *
 * name: a pointer to a Name
 */
void mid(Name *name);


/*
 * Print just the first name.
 * For the same example, this would print:
 * Marlin
 *
 * name: a pointer to a Name
 */
void small(Name *name);


/* Given a format char, print the given
 * name in the format specified by char.
 * The mapping is shown below:
 * B -> 'big' format
 * L -> 'last' format
 * R -> 'reg' format
 * M -> 'mid' format
 * S -> 'small' format
 * 
 * name: a pointer to a Name 
 * fmt: a char indicating the format to use
 */
void fmt(Name *name, char fmt);


/*
 * This function should return a randomly
 * generated name. This random name should be
 * generated as follows:
 * 1. Using a random number generator (see note below), pick either male_names or female_names
 * 2. From array you picked, generate two random indices to be the first and
 *    middle names. You can choose for the middle name to be NULL, if you desire. 
 *    A. The middle name for a female must be a female name, and a male 
 *       must have a male middle name. 
 *    B. It is okay for the first and middle name to be the same. 
 * 3. Generate one more random index to pick a name from the last_name array.
 *
 * Do not copy the strings. Copying the pointers to the strings are sufficient
 * to solve this problem. 
 *
 * Random number generator: see Flashcard 5.21 (Loops->rand). 
 * Assume the generator as been seeded (you don't need to call srand at all). 
 * Otherwise, to get a random number in a range between 0 and n, call: 
 * rand() % n; 
 *
 * Returns: a Name 
 */
Name generate_random();


/*
 * This function should populate an array
 * with randomly generated names. The number
 * of names to be generated is specified
 * by the parameter n.
 *
 * names: An array of n Names
 * n: The number of Names in names/length of the array. 
 */
void generate_random_array(Name* names, int n);


/*
 * Given an array of names, print them according to the
 * format specified by the second parameter, fmt.
 * The char -> format mappings are same as for s_fmt.
 *
 * Exception to the rule: if format is 'S' then
 * all names should be printed on the same line.
 *
 * names: an array of n names
 * n: the number of Names/length of the array. 
 * format: char specifying format to print out. 
 */
void fmt_array(Name *names, int n, char format);


/*
 * This function takes in reference to a couple and prints
 * their name as Mr. and Ms. <hubby last name>-<wife last name>
 * e.g., Mr. and Ms. Jones-Smith
 *
 * couple: pointer to the couple
 */
void couple_name(Couple *couple);


/*
 * This function should create a couple
 * given two names. Give them a random
 * number of kids, up to MAX_NUM_KIDS.  
 * The kids should have random names, including a random last name. 
 * Suggestion: consider a helper function, add_some_kids() 
 * to add kids to the couple. 
 *
 * Note on random: see Flashcard 5.21 (Loops->rand). 
 * Assume the generator as been seeded (you don't need to call srand at all). 
 * Otherwise, to get a random number in a range between 0 and n, call: 
 * rand() % n; 
 *
 * w: the wife's name
 * h: the husband's name
 */
Couple new_couple(Name *w, Name *h);


/*
 * This function given two couples - assume
 * these two be the bride's parents and groom's
 * parents - will pick a random kid from each
 * couple and returning them as a couple.
 * Before returning the new couple, make sure to announce
 * their wedding using the function defined below.
 *
 * What if one of parents don't have any kids? In this
 * situation you may want to define a helper function -
 * maybe something like add_some_kids() - and call this.
 *
 * bride_parents: pointer to the parents of the "bride" (note: we're equal opportunity-- this could be male or female)
 * groom_parents: pointer to the parents of the "groom" (see above note)
 *
 * return: A new Couple. You get to decide if they have kids or not! 
 */
Couple wedding(Couple *bride_parents, Couple *groom_parents);


/*
 * Annouce the new couple's wedding by printing it
 * out in the following format:
 *
 * Mr. and Ms. Smith                         <- bride's parents
 * and
 * Mr. and Ms. Jones                         <- groom's parents
 * request the honor of your presence
 * at the marriage of their children
 * Mary Ann Smith                            <- bride'a full name
 * and
 * Edward Malcolm Jones                      <- groom's full name
 */
void announce(Couple *bride_parents, Couple *groom_parents, Couple *couple);


/*
 * Given a couple, print their names and their kids names.
 * The format should follow the example shown below:
 *
 * Mr. and Ms. Smith and their 3 children: John Sally Vicky
 * OR
 * Mr. and Ms. Smith and their child: Ben
 *
 * If they have no kids then just print:
 *
 * Mr. and Ms. Jones
 */
void family(Couple *couple);

#endif

