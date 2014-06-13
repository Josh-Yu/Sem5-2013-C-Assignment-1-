/****************************************************************************
* COSC1283/1284 - Programming Techniques
* Semester 1 2013 Assignment #1 
* Full Name        : Joshua Yu
* Student Number   : S3235184
* Yallara Username : S3235184
* Course Code      : COSC1284
* Program Code     : BP162
* Start up code provided by Paul Miller and Xiaodong Li
* Some codes are adopted here with permission by an anonymous author
***************************************************************************/

#include "assign1.h"


/*  "Translating alphabetic number" of user input to 
	  numbers associated on a telephone
 *  
 */
void translateNumber(int * optionStats, char * phoneNumber)
{
int i; 

	/* Cycle thru the array using isalpha then convert to equilviant number via case statements*/
	for(i = 0; i < strlen(phoneNumber); i++)
	{
		if(isalpha(phoneNumber[i]))
		{
			switch(phoneNumber[i])
			{
			/* Phone digit is 2   */
			case 'A':
			case 'B':
			case 'C':
			phoneNumber[i] = '2';
			break;
	
			/* Phone digit is 3   */
			case 'D':
			case 'E':
			case 'F':
			phoneNumber[i] = '3';
			break;
	
			/* Phone digit is 4   */
			case 'G':
			case 'H':
			case 'I':
			phoneNumber[i] = '4';
			break;
	
			/* Phone digit is 5   */
			case 'J':
			case 'K':
			case 'L':
			phoneNumber[i] = '5';
			break;
	
			/* Phone digit is 6   */
			case 'M':
			case 'N':
			case 'O':
			phoneNumber[i] = '6';
			break;
	
			/* Phone digit is 7   */
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			phoneNumber[i] = '7';
			break;

			/* Phone digit is 8   */
			case 'T':
			case 'U':
			case 'V':
			phoneNumber[i] = '8';
			break;
	
			/* Phone digit is 9   */
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			phoneNumber[i] = '9';
			break;
			}
		}
	} /* end For Loop */
		printf("%s",phoneNumber);
optionStats[0]++;
} /* End translate function*/


/* Function generates  "Fibonacci sequence between 1-40"  
 */
void fibonacciNumbers(int * optionStats, int num)
{
int counter = num;
int fibo_one = 0;
int fibo_two = 0;
int fibo_current = 0;
int sum = 0;
double average = 0.0;
int i;

	printf("Fibonacci sequence for first %d terms:\n", num);
	for(i = 0; i < counter; i++)
	{	
		if(i == 1)/*prevents the third term doing 1+1=2*/
		{
			fibo_one = 1;
		}
	/*	printf("Fibo1 = %d\n", fibo_one);
		printf("Fibo2 = %d\n", fibo_two); */
		
		fibo_current = fibo_one + fibo_two;	
		fibo_one = fibo_two;
		fibo_two = fibo_current;
		
		sum = sum + fibo_current; 
			if(i > 0 && i % 5 == 0){
			printf("\n");
			}
			printf("%-9d", fibo_current);
		}
		
	printf("\n\n%-9s%d\n","Sum:",sum);
	average = (double)sum / counter;
	printf("%-9s%.2f\n","Average:",average);
	optionStats[1]++;
}


/*  "Sort line" Sorts only alphabetical characters and converts to lower case
	if needed
 */
void sortLine(int * optionStats, char * line)
{
/* char array[20] = line; */
int i = 0;
int x = 0;
char temp[1];	
	for(i = 0; i < strlen(line); i++) /*Outer loop to check the current index*/
	{
		if(isupper(line[i])) /*if char is uppercase, convert  */
		{
			line[i] = tolower(line[i]);
		}
			/*printf("DEBUG-Current Loop %i / char %c\n", i, line[i]); */
			for(x = 0; x <strlen(line); x++)
			{
				if(line[i] < line[x]) 
				/* If second char is less than first char, swap */
				{
				temp[0] = line[i];
				line[i] = line[x];
				line[x] = temp[0];
				}
			}	
	}
	/*  prints only indexes that are alphabetical*/
	printf("Output: ");
	for(i = 0; i < strlen(line); i++)
	{		
		if(isalpha(line[i]))
		{
			printf("%c", line[i]);
		}
	}
	 printf("\n");
	 optionStats[2]++;
}


/*  "Find substring" o  
 * mimics strstr() library function 
 * Determines if a substring exists in a string
 */
void findSubstring(int * optionStats, char * string, char * substring)
{
int i;
int j = 0;
int x = 0;/*temp counter varible needed (inner loop) keep count of string pos*/
int subStringFound = FALSE;

int matchFound = 0;

for(i = 0; i < strlen(string); i++)
{
	/*  if 1 sub string has not been found, keep looking*/
	if(subStringFound == FALSE) 
	{
		/*finds start of substring in string OR next occruring start */
		if(substring[j] == string[i]) 
		{
		/* Disposal temp variable to cycle through string without affecting 
			current string itteration*/
			x = i; 
			/*resets the counter  in cases where substring was partially found 
			in string */
			matchFound =0; 
			
			/*Inner loop checks if the current char matches, then interates x 
			to next character in string adds 1 to matchFound (used at the end 
			to confirm substring is found)
			*/		
			for(j = 0; j < strlen(substring); j++)
			{
			/*printf("DEBUG- Current j counter is %d\n", j);
			printf("\n\nCHecking substring %c is same as index %d %c \n", 
			substring[j], x,string[x]); */
				if (substring[j] == string[x])
				{
					matchFound++; 
					x++;
				}
				else
				{
					j = 0; /*resets to the start of substring to look again */
					printf("Break out of inner loop\n");
					/*Break loop if the substring sequence is interupted*/
					break; 
				}
			}
			/* 
			If the number of consequtive characters found 
			match the length of substring. hence substring has been found
			*/
			if(matchFound == strlen(substring)) 
			{
				subStringFound = TRUE;
			}
		}
	}
}

optionStats[3]++;
	if(subStringFound)
	{
		printf("Output: \"%s\" is a substring of %s",substring ,string);
	}
	else
	{
		printf("Output: %s is NOT a substring of %s ", substring, string);
	}
}

/* Function minesweeper() creates a field of N x M for the game of
 * minesweeper. The function first reads in integers N and M, and the
 * number of mines allowed, then output a field of the same size,
 * with the "." characters replaced by the number of mines adjacent to
 * that square. Note that the mine squares are randomly placed on the field.
 * 
 */
void minesweeper(int *optionStats, int n, int m, int numMines)
{
/* rowsXcols*/
char choice = ' ';
do{

char userInput[MAX_OPTION_INPUT+ EXTRA_SPACES];
char gameBoard[100][100];
int gameBoardNumbers[100][100];
int i =0;
int j=0;
int rowRandom =0;
int colRandom =0;
int mineFound = FALSE;
/* Minesweeper-holds the input entered by user*/
char userInteger[MAX_INTEGER_SIZE + EXTRA_SPACES]; 	
/* Holds number of mines (max value 10000) */
char numMinesInput[MAX_THOUSAND_INT + EXTRA_SPACES]; 
char* endPtr; /* Used for string to long conversion*/


/* if condition when user wants to try again with minesweeper
*	Reprompts user for inputs*/

if(choice == 'y')
{
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
}


printf("Number of mines is: %d\n", numMines);
printf("Value of m is: %d\n", m);
printf("Value of n is: %d\n========\n", n);
/* *ptr_GameBoard = (char*)malloc(sizeof(char) * m); */

/* Planting the mines on the gameboard*/
for( i = 0; i < numMines; i++)
{

mineFound = FALSE;
 
 /* Loop checks if the the generated co-ords does not 
have a mine already, if it does, regenerate co-ords */

do{
/*Generate random position where mines will go*/
	rowRandom = rand() % m;
	colRandom = rand() % n;
		if(gameBoard[rowRandom][colRandom] == '*')
		{
			mineFound = TRUE;
		}
		else
		{
			/*printf("No Mine detected\n"); */
			mineFound = FALSE;
			gameBoard[rowRandom][colRandom] = '*';
			gameBoardNumbers[rowRandom][colRandom] = '*';
		}
}while(mineFound == TRUE);


} 

printf("Printing off Board..\n");
for(i = 0; i< m; i++)
{
	for(j =0; j<n; j++)
	{
		if(gameBoard[i][j] != '*')
		{
			gameBoard[i][j] = '.';
			gameBoardNumbers[i][j] = 0;
		}
	printf("%c", gameBoard[i][j]);
	}
printf("\n");
}

/*prints out board with numbers */
for(i = 0; i< m; i++)
{
	for(j =0; j<n; j++)
	{
		if(gameBoard[i][j] == '*')
		{
		
		/*checks above row above the star	*/
			if(i != TOP_BOUNDARY)
			{
				/* check top left diagonal */
				if(gameBoard[i-1][j-1] != '*')
				{
					gameBoardNumbers[i-1][j - 1]++;
				}
				/* checks direct above*/
				if(gameBoard[i-1][j] != '*')
				{
					gameBoardNumbers[i-1][j]++;
				}
				
				if(j != (n-1))
				{
					/*Checks top right diagonal */
					if(gameBoard[i-1][j+1] != '*')
					{
						gameBoardNumbers[i-1][j+1]++;
					}
				}
			}
			
			/*check left side */
			if (j != TOP_BOUNDARY)
			{	
				if(gameBoard[i][j-1] != '*')
				{
					gameBoardNumbers[i][j-1]++;
				}
			}
			
			/* check right side*/
			if(j != (n-1))
			{
				if(gameBoard[i][j+1] != '*')
				{
					gameBoardNumbers[i][j+1]++;
				}
			}
				
				/*checks bottom row below star */
			if(i != (n-1))
			{
				/* check bottom left diagonal */
				if(gameBoard[i+1][j-1] != '*')
				{
					gameBoardNumbers[i+1][j - 1]++;
				}
				/* checks direct below*/
				if(gameBoard[i+1][j] != '*')
				{
					gameBoardNumbers[i+1][j]++;
				}
				/*Checks bottom right diagonal */
				if(j != (n-1))
				{
					if(gameBoard[i+1][j+1] != '*')
					{
						gameBoardNumbers[i+1][j+1]++;
					}
				}
			}
		}
	}
}

	/* Print out of the gameboard with numbers*/
	for(i = 0; i< m; i++)
	{
		for(j =0; j<n; j++)
		{
			if(gameBoardNumbers[i][j] == '*')
			{
				printf("%c", gameBoardNumbers[i][j]);
			}
			else
			{
				printf("%d", gameBoardNumbers[i][j]);
			}
		}
			printf("\n");
	}
optionStats[4]++;
	
	/* Use memset to clear the array*/
	memset(gameBoardNumbers,0,sizeof(gameBoardNumbers));
	memset(gameBoard,'.',sizeof(gameBoard));
	printf("Try Again (y/n): ");

	if(getUserInput(MAX_OPTION_INPUT + EXTRA_SPACES, userInput,
	MAX_OPTION_INPUT,NO_RANGE_CHECK_REQUIRED))
	{
		printf("Returning to Menu\n");
		break;
	}
	choice = userInput[0];
}while(choice == 'y');


}

/* "Session summary"  
 * Function sessionSummary() reports the program usage.  
 */
void sessionSummary(int *optionStats)
{

int i;
int optionsCounter = 1;

printf("Option  Count\n");
printf("------  -----\n");
optionStats[5]++;


	for(i=0; i < NUM_OPTION_STATS; i++)
	{
		printf("%6d  %5d\n", optionsCounter, optionStats[i]);
		optionsCounter++;
	}

}

