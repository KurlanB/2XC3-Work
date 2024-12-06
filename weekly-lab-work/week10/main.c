#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "string_utilities.h"

#define INPUT_SIZE 1000

int main(){
	char input[INPUT_SIZE + 1];

	while(fgets(input, INPUT_SIZE, stdin)){
		char *str = input;
		char *first;
		char *last;
		
		trim(&str, &first, &last);
		
		to_upper(str);
		puts("");
		char *lower = to_lower_pure(str);
		
		printf("%s\n", lower);
		free(lower); 
	}
}
