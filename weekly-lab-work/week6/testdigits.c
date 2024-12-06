/* Testfile to test the digits function
 * 
 * Kurlan Beeharry, McMaster University, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "digits.h"


/* Main function. Runs test cases for the digits function.
 * Exits with failure code on first test case fail.
 * Otherwise exits with success.
 */

int main() {

    	int min, max, sum;
    	long n;

    	// Test Case 1
    	n = 1234;
    	sum = digits(n, &max, &min);
    	printf("%ld: sum %d, min %d, max %d\n", n, sum, min, max);
    	if (max == 4 && min == 1 && sum == 10) {
        	puts("success");
    	} else {
        	puts("failure");
        	return EXIT_FAILURE;
    	}

	// Test Case 2
	n = 99810;
    	sum = digits(n, &max, &min);
    	printf("%ld: sum %d, min %d, max %d\n", n, sum, min, max);
    	if (max == 9 && min == 0 && sum == 27) {
       		puts("success");
    	} else {
        	puts("failure");
        	return EXIT_FAILURE;
    	}

    	// Test Case 3
    	n = 1;
    	sum = digits(n, &max, &min);
    	printf("%ld: sum %d, min %d, max %d\n", n, sum, min, max);
    	if (max == 1 && min == 1 && sum == 1) {
        	puts("success");
    	} else {
        	puts("failure");
        	return EXIT_FAILURE;
    	}

    	// Test Case 4
    	n = 0;
    	sum = digits(n, &max, &min);
    	printf("%ld: sum %d, min %d, max %d\n", n, sum, min, max);
    	if (max == 0 && min == 0 && sum == 0) {
        	puts("success");
    	} else {
        	puts("failure");
        	return EXIT_FAILURE;
    	}

 	// Test Case 5
    	n = -1234;
    	sum = digits(n, &max, &min);
    	printf("%ld: sum %d, min %d, max %d\n", n, sum, min, max);
    	if (max == 4 && min == 1 && sum == 10) {
        	puts("success");
    	} else {
        	puts("failure");
        	return EXIT_FAILURE;
    	}

    	return EXIT_SUCCESS;
}
