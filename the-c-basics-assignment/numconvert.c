/* The numconvert Functions
 * 
 * Includes multiple functions to help convert the numbers entered to their corresponding radix
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Header file
#include "numconvert.h"


/* numconvert Function
 *
 * Parameters:
 * long number = number to be converted
 * int base = base to convert to
 *
 * Converts a number inputted to the base value using recursive iteration. 
 *
 * Returns 0 for success, outputs each character of the converted number one at a time
 *
 * */

void numconvert(long number, int base){
	
	// Recursively call itself until number reaches 0, then outputs - if number is negative
	if(number/base != 0){
                numconvert(number/base, base);
        } else if(number < 0){
		printf("%c", '-');
	}

	// Obtain digit using modulo
	int digit = (int)abs(number % base);
	
	// Arrays to store numbers and corresponding letters conversions
	int nums[N];
	char letters[N] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	// Filling the numbers array
	for(int x = 0; x < 26; x++){
		nums[x] = x + 10;
	}

	// Convert numbers to corresponding letters
	if(digit > 9){
		for(int i = 0; i < N; i++){
			if (nums[i] == digit){
				printf("%c", letters[i]);
				break;
			}
		}
	} else {
		printf("%d", digit);
	}
}


/* Range_convert Function
 *
 * Parameters:
 * int base = base to be converted to
 * long start, finish = values to convert from and to
 *
 * Converts values by calling numconvert from the start value to the finish value.
 *
 * Returns 0 and outputs the numbers converted in order from start to finish
 * */

int range_convert(int base, long start, long finish){
	for(long i = start; i <= finish; i++){
		numconvert(i, base);
		puts("");
	}
	return 0;
}


/* stdin_convert Function
 *
 * Parameters:
 * int base = base to be converted to
 *
 * Reads from standard input until EOF and converts all numbers inputted
 *
 * Returns 0 when succesful and 1 when error occurs. Outputs numbers converted 
 * or error message to standard error.
 *
 * */

int stdin_convert(int base){
	long number;
	while(true){
		int result = scanf("%ld", &number);

		if(result == EOF){
			break;
		} else if(result > 0){
			numconvert(number, base);
                	puts("");
		} else {
			fprintf(stderr,"Error: Non-long-int token encountered.\n");
			return 1;
		}
	}
	return 0;
}
