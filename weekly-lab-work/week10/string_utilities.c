#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

void to_upper(char str[]){
	for(int i = 0; i < strlen(str); i++){
		if(str[i] >= 97 && str[i] <= 122){
			str[i] -= 32;
		} 
		printf("%c", str[i]);
	}
}

char *to_lower_pure(char str[]){
	char *lower_str = malloc((strlen(str) + 1) * sizeof(char));
	
	strcpy(lower_str, str);
	
	for(int i = 0; i < strlen(lower_str); i++){
		if(lower_str[i] >= 65 && lower_str[i] <= 90){
			lower_str[i] += 32;
		}
	}
	
	lower_str = realloc(lower_str, (strlen(lower_str) + 1) * sizeof(char));

	return lower_str; 
}

void find_content(char *str, char **first, char **last){
	*first = "\0";
	*last = "\0";

	for(int i = 0; i < strlen(str); i++){
		if(str[i] != '\n' && str[i] != '\t' && str[i] != ' '){
			*first = &str[i];
			break;
		}
	}

	if(*first == *last){
		*first = "\0";
		*last = "\0";
		return;
	}
	for(int i = strlen(str) - 1; i >= 0; i--){
		if(str[i] != '\n' && str[i] != '\t' && str[i] != ' '){
                	*last = &str[i];
                	break;
                }
	}
}

void trim(char **str, char **first, char **last){
	find_content(*str, first, last);
	if(**first != '\0'){
		char *c = *str;
		while(*c != **first){
			*str += 1;
			*c++;
		}
		*(*last + 1) = '\0';
	}
}

