/* Kurlan Beeharry, 400521584, November 20 2024
 *
 * The cleaner file contains cleaner functions to clean the 2d arrays of floats in different ways.
 * The functions take in a 2d array of floats and its size, then cleans it.
 * The functions output a pointer to the cleaned 2d array of floats.
 *
 * */

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/* Clean Delete Function
 *
 * Parameters:
 * int *rows = pointer to an integer representing the rows of the array
 * int columns = integer representing the columns in the array.
 * float data[*rows][columns] = 2d array of float values.
 *
 * The function takes in a 2d array of floats and its size, then deletes any row with a NAN value.
 * 
 * The function outputs a pointer to the cleaned 2d array of floats.
 */

float *clean_delete(int *rows, int columns, float data[*rows][columns]){
	int new_row = 0;

	// Allocate memory for 2d array
	float (*cleaned_array)[columns] = malloc(1 * columns * sizeof(float));
	
	if(cleaned_array == NULL){
		return NULL;
	}

	// Iterate through each row and delete rows including a NAN value
	for(int r = 0; r < *rows; r++){
		bool copy = true;
		
		for(int c = 0; c < columns; c++){
			if(isnan(data[r][c])){ 
				copy = false;
			}
		}

		// Adding clean rows to cleaned array and reallocating memory with changing size
		if(copy == true){
			new_row++;
                        cleaned_array = realloc(cleaned_array, new_row * columns * sizeof(float));
                        if(cleaned_array == NULL){
				return NULL;
			}

			for(int j = 0; j < columns; j++){
				cleaned_array[new_row - 1][j] = data[r][j];
			}
		}
	}

	*rows = new_row;
	return (float *)cleaned_array;
}


/* Clean Impute Function
 *
 * Parameters:
 * int rows = integer representing the rows of the array
 * int columns = integer representing the columns in the array.
 * float data[*rows][columns] = 2d array of float values.
 *
 * The function takes in a 2d array of floats and its size, then replaces any NAN value
 * with the average of valid values in the column.
 *
 * The function outputs a pointer to the cleaned 2d array of floats.
 */

void clean_impute(int rows, int columns, float (*data)[rows][columns]){
	// Iterate through columns
	for(int c = 0; c < columns; c++){
		for(int r = 0; r < rows; r++){
			// Replace NAN values with average of valid values in columns
			if(isnan((*data)[r][c])){
				float sum = 0;
				int valid_nums = 0;
				
				for(int i = 0; i < rows; i++){
					if(!isnan((*data)[i][c])){
						valid_nums++;
						sum += (*data)[i][c]; 	
					}
				}
				
				// If all values are NAN, make them all 0
				if(valid_nums > 0){
					(*data)[r][c] = sum / valid_nums;
				} else {
					(*data)[r][c] = 0;
				}
			}
		}
	}
}
