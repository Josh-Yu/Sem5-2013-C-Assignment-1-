/****************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 1 2013 Assignment #1 
* Full Name        : Joshua Yu
* Student Number   : 3235184
* Yallara Username : S3235184
* Course Code      : COSC1284
* Program Code     : BP162
* Start up code provided by Paul Miller and Xiaodong Li
***************************************************************************/

#include "assign1.h"

/* Function readRestOfLine() is used for buffer clearing. 
 * Please refer to "test_fgets.c" on Blackboard: 
 * "Course Documents"->"Function Examples"->"Input Validation Examples" */
void readRestOfLine()
{
int c;
    /* Read until the end of the line or end-of-file. */   
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
        ;
    /* Clear the error and end-of-file flags. */
    clearerr(stdin);
}
/* Function code has been referenced from 'getInteger-advanced.c' file that is on blackboard*/
int getUserInput(int charLimit, char array[], int max, int type)
{
char* endPtr;
int inputValid = FALSE;
int tempInteger = 0;
int min = 1;
do{
inputValid = FALSE;
	
	fgets(array, charLimit, stdin);
	
	/* Checks if the user has entered a space to indicate to return to menu  */
	if(array[0] == '\n')
	{
		return TRUE;
	}
	else /* Checks if the char length is witin the array container size*/
	{
		/* Checks if the last index was an \n to signify it was 1 character and not too long
		If the user input did not have \n, it means it was too long for the buffer*/
		if (array[strlen(array) - 1] != '\n')
		{
			/*printf("(DEBUG - Last character does not have \\n \n"); */
		printf("Input buffer overflow- Clearing buffer\n");
		printf("Please Re-enter Input, too many characters previously entered\n");
		readRestOfLine();
		inputValid = FALSE;
		}
		else
		{
         /* String length was ok. Replacing \n with \0 */
			/*printf("DEBUG-String Length is okay, replace \\n with \\0\n"); */
		array[strlen(array) - 1] = '\0';
		inputValid = TRUE;
		}
	}
	
	/*printf("Before processing integer range\n"); */
	/*Perform integer range check if correct parameter passed in */
	if(inputValid != FALSE && type == INTEGER_CHECK)
	{
		/*printf("\n DEBUG Checking if integer range is correct\n"); */
		/* Convert string to an integer. */
		tempInteger = (int) strtol(array, &endPtr, 10);

		/* Validate integer result. */
		if (strcmp(endPtr, "") != 0)
		{
			printf("Input was not numeric.\n");
			inputValid = FALSE;
			printf("Please re-enter value that is a integer\n");
		}
		else if (tempInteger < min || tempInteger > max)
		{
			printf("Input was not within range %d - %d.\n", min, max);
			inputValid = FALSE;
			printf("Please re-enter value between %d and %d:\n", min, max);
		}
		else /* enters here if the input is numeric and within range*/
		{
			inputValid = TRUE;
		}
	}
	/* cases where no integer range check needed */
		
	
	}while(!inputValid);
	return FALSE;
}
/* Displays basic menu options */
void menu(int optionStats[])
{
char userInput[MAX_OPTION_INPUT + EXTRA_SPACES];/*Holds the char array of user selections via menu */
char phoneNumber[MAX_PHONE + EXTRA_SPACES]; 	/* Function 1 -Translate PhoneNumber*/
char fibo[MAX_FIBO_SIZE + EXTRA_SPACES]; 		/* Function 2-Fibonachi*/
char line[MAX_LINE_CHARS + EXTRA_SPACES]; 		/* Function 3-SortLine */
char string[MAX_STRING_SIZE + EXTRA_SPACES]; 	/* Function 4 - String */
char substring[MAX_STRING_SIZE + EXTRA_SPACES]; /* Function 4 - Substring */
char userInteger[MAX_INTEGER_SIZE + EXTRA_SPACES]; 	/* Function 5 - Minesweeper-holds the input entered by user*/
char numMinesInput[MAX_THOUSAND_INT + EXTRA_SPACES]; /* Function 5 - Holds number of mines (max value 10000) */

int choice;
char* endPtr;

int n = 0;
int m = 0;
int numMines = 0;

do{
    printf("\nMain Menu: \n");
	printf("1) Translating alphabetic number\n");
	printf("2) Fibonacci numbers\n");
	printf("3) Sort line\n");
	printf("4) Find substrings\n");
	printf("5) Minesweeper\n");
	printf("6) Session Summary\n");
	printf("7) Exit\n\n");

	printf("Select your option:");
	getUserInput(MAX_OPTION_INPUT + EXTRA_SPACES, userInput, 7,
	NO_RANGE_CHECK_REQUIRED);


	/* Convert char to string */
	choice = (int) strtol(userInput, &endPtr, 10);
	
	printf("Choice is %d\n", choice);

switch(choice)
{
	default:
	printf("Input does not match any available options\n");
	break;
	
	case 1:
	printf("Translating alphabetic number\n");
	printf("------------------------------\n\n");
	printf("Enter Phone Number: ");
	if(getUserInput(MAX_PHONE + EXTRA_SPACES, phoneNumber, MAX_PHONE,
	NO_RANGE_CHECK_REQUIRED))
	{
		printf("Returning to Menu\n");
		break;
	}
	printf("\nTranslated Phone Number is:\n");
	translateNumber(optionStats, phoneNumber);
	printf("\n");
	break;

	case 2:
	printf("Fibonacci Numbers\n");
	printf("-----------------\n\n");
	printf("Enter a positive integer (1-40): ");
	if(getUserInput(MAX_FIBO_SIZE + EXTRA_SPACES, fibo, MAX_NUM_FIBO,
	INTEGER_CHECK))
	{
		printf("Returning to Menu\n");
		break;
	}
	
	choice = (int) strtol(&fibo[0], NULL, 10);
	fibonacciNumbers(optionStats, choice);
	break;

	case 3:
	printf("Sort Line\n");
	printf("-----------------\n\n");
	printf("Enter a string (1-40 characters): \n");
	
	if(getUserInput(MAX_LINE_CHARS + EXTRA_SPACES, line, MAX_LINE_CHARS,
	NO_RANGE_CHECK_REQUIRED))
	{
		printf("Returning to Menu\n");
		break;
	}
	sortLine(optionStats, line);
	break;

	case 4:
	printf("Find substring\n");
	printf("-----------------\n\n");
	
	printf("Enter a string (1 - 20 characters): ");
	if(getUserInput(MAX_STRING_SIZE + EXTRA_SPACES, string,  MAX_STRING_SIZE, 
	NO_RANGE_CHECK_REQUIRED))
	{
		printf("Returning to Menu\n");
		break;
	}
	
	printf("Enter a substring (1 - 20 characters): ");
	if(getUserInput(MAX_STRING_SIZE + EXTRA_SPACES, substring, MAX_STRING_SIZE,
	NO_RANGE_CHECK_REQUIRED))
	{
		printf("Returning to Menu\n");
		break;
	}
	findSubstring(optionStats, string , substring);
	break;
	
	
	case 5:	
	printf("Mine sweeper\n");
	printf("------------\n");
	printf("The number of lines (m): ");
	if(getUserInput(MAX_INTEGER_SIZE + EXTRA_SPACES, userInteger,
	MAX_NUM_LINES, INTEGER_CHECK))
	{
		printf("Returning to Menu\n");
		break;
	}
	m = (int) strtol(userInteger, &endPtr, 10);
	
	
	printf("\nThe number of columns (n): ");
	if(getUserInput(MAX_INTEGER_SIZE + EXTRA_SPACES,userInteger, 
	MAX_NUM_LINES, INTEGER_CHECK))
	{
		printf("Returning to Menu\n");
		break;
	}
	n = (int) strtol(userInteger, &endPtr, 10);
	
	/* Need to calc max mines from m * n */
	printf("\nThe number of mines (numMines): ");
	if(getUserInput(MAX_THOUSAND_INT + EXTRA_SPACES,numMinesInput, 
	(m*n-1), INTEGER_CHECK))
	{
		printf("Returning to Menu\n");
		break;
	}
	numMines = (int) strtol(numMinesInput, &endPtr, 10);
	
	minesweeper( optionStats, n, m, numMines);
	break;

	case 6:
	printf("Session Summary\n");
	printf("---------------\n\n");
	sessionSummary(optionStats);
	break;

	case EXIT:
	printf("Exiting Program\n");
	exit(EXIT_SUCCESS);
	break;

}
}while(choice != EXIT);
}