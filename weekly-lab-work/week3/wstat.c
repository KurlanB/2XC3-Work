/* A counting average line length program
 *
 * Kurlan Beeharry, September 24, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	// Declaring counters
	double numChar;
	double numWord;
	double numLine;
	
	// Reading input from wc command
	int result = scanf("%lf %lf %lf", &numLine, &numWord, &numChar);	

	// Calculating average line length
	if(result == 3){
		double average = (numChar - numLine) / numLine;
		printf("%.1lf\n", average);
		return EXIT_SUCCESS;

	// Handle error if no argument received
	} else if(result == 0){
		fprintf(stderr, "No input detected\n");
		return EXIT_FAILURE;
	
	// Handle other errors
	} else {
		fprintf(stderr, "Invalid input\n");
                return EXIT_FAILURE;
	}
}
