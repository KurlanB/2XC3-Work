/* Kurlan Beeharry, 400521584, November 20, 2024
 * 
 * Reader file for the input and output functions
 * Reader function takes in pointer values and reads the 2d array from standard input
 * It outputs the pointer to the 2d array
 *
 * Output function reads a 2d array and prints the values in the correct format.
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/* Read Data Function
 *
 * Parameters:
 * int *rows = pointer to integer representing the rows of 2d array.
 * int *columns = pointer to integer representing the columns of the 2d array.
 *
 * Read from standard input and assign values for rows and columns
 * 
 * Outputs a pointer to the 2d array.
 *
 * */

float *read_data(int *rows, int *columns){
	scanf("%d %d", rows, columns);
	float (*data)[*columns] = malloc(*rows * *columns * sizeof(float));
	
	if(data == NULL){
		return NULL; 
	}
	for(int r = 0; r < *rows; r++){
		for(int c = 0; c < *columns; c++){
			scanf("%f", &data[r][c]);		
		}
	}

	return (float *)data;
}

/* Output Data Function
 *
 * Parameters:
 * int rows = integer representing the rows of 2d array.
 * int columns = integer representing the columns of the 2d array.
 * float data[rows][columns] = 
 *
 * Read from standard input and assign values for rows and columns.
 *
 * Prints the rows and columns amount and the 2d array in the correct format.
 *
 * */

void output_data(int rows, int columns, float data[rows][columns]){
	printf("%d %d\n", rows, columns);
	
        for(int r = 0; r < rows; r++){
                for(int c = 0; c < columns; c++){
                        printf("%.3f ", data[r][c]);
                }
                puts("");
        }	
}
