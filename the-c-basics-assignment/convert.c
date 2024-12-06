/* Kurlan Beeharry, 400521584, November 6 2024
 *
 * The convert utility uses a recursive function to convert numbers from base 10 to a different radix
 * It can take numbers from standard input or directly in the command line arguments.
 * It displays the numbers in the order they are inputted.
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Header files for additional functions

#include "numconvert.h"
#include "reader.h"


/*
 * Usage function
 *
 * No parameters
 *
 * Displays a usage message when error occurs
 *
 * Returns 1 and sends output to standard error
 *
 * */

int usage(){
	fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n	1 < BASE < 37\n	START and FINISH are long integers\n");
	return 1;
}


/*
 * Help function
 *
 * No parameters
 *
 * Displays command information for users to understand the convert utility
 *
 * Returns 0 and outputs to standard output
 *
 * */

int help(){
	puts("				User Commands				\n");
	puts("convert - Version 1.0.0\n");
	
	// NAME
	puts("NAME\n	convert - reads long integers from standard input and displays the numbers converted\n	to a new radix(base).\n");

	// USAGE
	puts("USAGE\n	Usage: convert [-b BASE] [-r START FINISH]\n		1 < BASE < 37\n		START and FINISH are long integers.\n");	
	
	// DESCRIPTION
	puts("DESCRIPTION\n\n	convert reads long integers in base 10 from standard input and converts them\n	into a different radix. If [-b BASE] is used, then it changes the base to the given BASE, \n	else it converts to base 16. If [-r START FINISH] is entered, then displays converted\n	numbers from starting value to finish value.\n");

	// OPTIONS
	puts("OPTIONS\n\nGeneric Program Information\n	--help  Opens this page of usage and information.\n");
	puts("Argument information\n	-b  Accepts a BASE, which is the desired radix to convert to\n	-r  Accepts a START and FINISH, instead or reading from standard input, \n	    converts the numbers from START to FINISH.\n");

	// EXIT
	puts("EXIT STATUS\n	When program run successfully and end with EOF, exit status is 0, if error is run into, \n	exits with 1.\n");
	
	//EXAMPLE
	puts("EXAMPLE\n	The following example outputs the number of radix 16 'FF'.\n	The standard input is 255, which represents the base 10 value.\n");	
	puts("	/$ convert\n	   255\n	   FF\n");

	puts("	The following example outputs the number of radix 2 '10'.\n	The argument '-b 2' represents the conversion to radix 2.\n	The standard input is 2, which represents the base 10 value.\n");
        puts("	/$ convert -b 2\n	   2\n	   10");

	puts("	The following example outputs the number of radix 16 '-11 -10 -1 0 1 10 11'.\n	The argument '-b 2' represents the base to be converted to.\n	The argument '-r -3 3' represents the start and finishing numbers to convert.\n");
        puts("	/$ convert -b 2 -r -3 3\n	   -11\n	   10\n	   -1\n	   0\n	   1\n	   10\n	   11\n");

	return 0;
}

/*
 * Runtime Function
 *
 * Parameters:
 * int option = integer representing the specific task to perform
 * int base = base to convert to
 * long start and finish = start and finish values when '-r' is used
 * 
 * Handles all actions to perform depending on the command line arguments entered
 *
 * Returns 1 when error occurs and 0 when successful, outputs depend on the function called.
 *
 * */

int runtime(int option, int base, long start, long finish){
        int return_value = -1;
	switch(option){
                case -1:
                        return_value = usage();
			break;
                case 1:
                        return_value = help();
			break;
                case 2:
			return_value = stdin_convert(base);
			break;
                case 3:
                        return_value = range_convert(base, start, finish);
			break;
        }
	return return_value;
}

/*
 * Main Function
 *
 * Only runs the program by calling other functions
 *
 * Returns 0 when successful and 1 when error occurs, output depends on functions called
 *
 * */

int main(int argc, char *argv[]){
	int base;
	long start, finish;
	
	// Integer value corresponding to task to perform depending on command line arguments
	int check = reader_check(argc, argv, &base, &start, &finish);
	
	return runtime(check, base, start, finish);
}
