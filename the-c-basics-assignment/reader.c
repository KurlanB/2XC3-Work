/* Kurlan Beeharry, 400521584, November 6 2024
 *
 * Reader function to read from command line arguments and communicating task to perform
 * 
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Header file
#include "reader.h"

// Defining constants
#define MAX 37
#define MIN 1
#define BASE 16


/* Reader Check Function
 *
 * Parameters:
 * int *base = Pointer to the base value to convert to
 * long *start, finish = Pointers to the start and finish values to convert
 * 
 * Reads the command line arguments, checking for errors and returns a value representing the task to 
 * perform based on the arguments passed. 
 * 
 * Returns -1 when error occurs, 1 when help is wanted, 2 when only '-b' is used 
 * and 3 when '-r' has been used. No output. 
 *
 * */

int reader_check(int argc, char *argv[], int *base, long *start, long *finish){
	
	// Calling help function
	if(argc == 2 && strcmp(argv[1], "--help") == 0){
		return 1;
	} else {
		switch(argc){
			case 1: // If no arguments entered

				*base = BASE;
				return 2;
			
			case 3: // If 2 arguments passed
				
				// When '-b' and numeric character entered
				if(strcmp(argv[1], "-b") == 0 && atoi(argv[2]) != 0){
					
					// If the number is between the correct range
					if(atoi(argv[2]) < MAX && atoi(argv[2]) > MIN){
						
						*base = atoi(argv[2]);
						return 2;
					}
				}
				return -1;

			case 4: // If 3 arguments passed

				// If '-r entered'
				if(strcmp(argv[1], "-r") == 0){
					
					// If the character is not numeric, error occurs
					if((atol(argv[2]) == 0 && strcmp(argv[2], "0")) 
					|| ((atol(argv[3]) == 0) && strcmp(argv[3], "0") != 0)){
						return -1;
					}
					
					// Changing the values correctly
					*base = BASE;
					*start = atol(argv[2]);
					*finish = atol(argv[3]);
					return 3;
				}
				break;
			
			case 6: // If 6 arugments passed
				
				// If '-b BASE' and '-r' are both entered correctly
				if(strcmp(argv[1], "-b") == 0 && atoi(argv[2]) != 0 
				&& strcmp(argv[3], "-r") == 0){ 
					
					// If the START and FINISH are both non-numeric, error occurs 
					if((atol(argv[4]) == 0 && strcmp(argv[4], "0")) 
					|| (atol(argv[5]) == 0 && strcmp(argv[5], "0") != 0)){
						return -1;
					}
					
					// If BASE is between correct range
					if(atoi(argv[2]) < MAX && atoi(argv[2]) > MIN){
                                                
						// Changing the corresponding values
						*base = atoi(argv[2]);
						*start = atol(argv[4]);
						*finish = atol(argv[5]);
						return 3;
					}
				}
				break;

			default: // If other number of argument passed
				return -1;
		}
	}
	return -1;
}
