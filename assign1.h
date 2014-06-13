/****************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 1 2013 Assignment #1 
* Full Name        : Joshua Yu
* Student Number   : 3235184
* Yallara Username : s3235184
* Course Code      : COSC1284
* Program Code     : BP162
* Start up code provided by Paul Miller and Xiaodong Li
* Some codes are adopted here with permission by an anonymous author
***************************************************************************/

/* Header files. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Constants. */

/* Used for exiting the program, avoid magic numbers*/
#define EXIT 7


/* This is used to compensate for the extra character spaces taken up by
   the '\n' and '\0' when user is asked for input through fgets(). */
#define EXTRA_SPACES 2

/* Specifies the maximum input length a user can enter for the options
   . */
#define MAX_OPTION_INPUT 1

/* Specifies the max number of user inputs in the array. total of 7 options inc 0 index*/
#define NUM_OPTION_STATS 6

/* Specifies the max number of characters for the phone number input*/
#define MAX_PHONE 15

/* Specifies the max number of characters for the "Fibonachi function"*/
#define MAX_FIBO_SIZE 2

/* Specifies the max number of integer for "Fibonachi function"*/
#define MAX_NUM_FIBO 40

/* Specifies the maximum string size for "findStrings" function */
#define MAX_STRING_SIZE 20

/* Specifies the maximum char size for "sortLine" function */
#define MAX_LINE_CHARS 40

/* Specifies the max size of array to hold interger input for the "minesweeper"*/
#define MAX_INTEGER_SIZE 3
#define MAX_THOUSAND_INT 5

/* Specifies max number(limit) of lines and columns in minesweeper */
#define MAX_NUM_LINES 100

/* Used for input validation. */
#define TRUE 1
#define FALSE 0

/*Required to tell the getUserInput what type of range checks to perform */
#define NO_RANGE_CHECK_REQUIRED -1 /*cases where int range check is not needed */
#define INTEGER_CHECK 11

/* Specifies the top boundary for the minesweeper so it does not go out of bounds*/
#define TOP_BOUNDARY 0


/* Function prototypes. */
void translateNumber(int *, char *);
void fibonacciNumbers(int *, int);
void sortLine(int *, char *);
void findSubstring(int *, char *, char *);
void minesweeper(int*, int, int, int);
void sessionSummary(int *);



/* My defined utility function prototypes. */
void readRestOfLine();

void menu(int *);
int getUserInput(int , char *, int , int);


