/* Kurlan Beeharry, 400521584, November 20 2024
 *
 * The clean utility cleans data in the form of a 2d array, either by deleting or imputing data.
 * It takes in a 2d array from standard input with the first line as the size of the array.
 * It outputs the cleaned data in a 2d array.
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "reader.h"
#include "cleaner.h"

/* Main function
 * 
 * Parameters:
 * int argc = integer representing the amount of command line arguments
 * char *argc[] = array of strings representing the arguments passed
 *
 * Handles all actions after command line arguments are entered
 *
 * Returns 0 if successful and 1 when error occurs.
 * 
 */

int main(int argc, char *argv[]){
	int rows;
	int columns;

	// If no arguments passed, clean_impute
	if(argc == 1){
		
		float (*data)[columns] = (float (*)[columns])read_data(&rows, &columns);
		
		clean_impute(rows, columns, data);
		
		output_data(rows, columns, data);
	
		free(data);	

	// If -d flag passed, clean_delete	
	} else if (argc == 2 && strcmp(argv[1], "-d") == 0){
		
		float (*data)[columns] = (float (*)[columns])read_data(&rows, &columns);
		
		float (*cleaned_data)[columns] = (float (*)[columns])clean_delete(&rows, columns, data);
        	
		output_data(rows, columns, cleaned_data);
		
		free(cleaned_data);
		free(data);

	// When invalid arguments passed	
	} else {
		fprintf(stderr, "Usage: clean [-d]\n");
	}
}
