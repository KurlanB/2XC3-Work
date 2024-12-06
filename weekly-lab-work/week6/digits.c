/* The digits function definition
 * 
 * Kurlan Beeharry, Mcmaster University, 2024
 */

#include <stdlib.h>
#include <stdio.h>


/* digits function
 *
 * Counts the sum of all digits in given number and finds the max and min
 * Input: Number of long type
 * Output: Returns sum of digits
 */

int digits(long n, int * max, int * min) {
	int sum = 0; 
	*min = 100;
	*max = -100;
	n = abs(n);

	do{
		// Finding digit from remainder of division by 10

		int digit = n % 10;

		// Assigning new max and min numbers
		if(digit > *max){
			*max = digit;
		}

		if(digit < *min){
			*min = digit;
		}

		// Adding digits to sum
		sum += digit;

		// Removing digit that's been counted
		n /= 10;
		
	}while(n > 0);
	
	return sum;
}

