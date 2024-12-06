/* Print the Collatz sequence
 *
 * Kurlan Beeharry, McMaster University, 10 October 2024
 */

#include <stdlib.h>
#include <stdio.h>

/* Recursive function that prints the Collatz sequence from a given input.
 * 
 */

int hailstone(int n){
	if(n == 1){
		puts("");
		return 1;
	
	} else if(n % 2 == 0){
		printf("%d ", n/2);
		return hailstone(n/2);
	
	} else{
		printf("%d ", 3*n+1);
		return hailstone(3*n+1);	
	}
}

/* Main function that reads user input.
 * Check for invalid inputs
 * Calls the hailstone function
 */

int main(){
	int n;

	puts("Please enter a positive integer (n > 1): ");
	int result = scanf("%d", &n);
	
	if(result == 0){
		fprintf(stderr, "Invalid Input ! \n");
		return EXIT_FAILURE;
	
	}else if(n <= 0){
		fprintf(stderr, "Integer not positive");
		return EXIT_FAILURE;
	
	} else {
		printf("%d ", n);
		hailstone(n);
		return EXIT_SUCCESS;
	}
}
