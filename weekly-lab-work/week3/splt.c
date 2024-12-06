/* A program to split texts into seperate words
 * Kurlan Beeharry
 * September 24, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	// Declaring string
	char s[1000];
	
	while(true){
		// Reading word
		int result = scanf("%s", s);
		
		// Error when no string found
		if(result == 0){
			fprintf(stderr, "Bad Value\n");
			return EXIT_FAILURE;

		// Stop when end of file
		}else if(result == EOF){
			break;
		}

		// Displaying each word
		printf("%s\n", s);

	}
	return EXIT_SUCCESS;
}
