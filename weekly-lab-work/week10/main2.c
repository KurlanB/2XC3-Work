#include <stdlib.h>
#include <stdio.h>

#include "string_utilities.h"

int main(){
	char *s = "	hello friend	";
	char *first, *last;
	find_content(s, &first, &last);
	printf("%c...%c\n", *first, *last);

	s = "       ";
	find_content(s, &first, &last);
        printf("%c...%c\n", *first, *last);

	s = "     hello";
	find_content(s, &first, &last);
        printf("%c...%c\n", *first, *last);

	s = "a";
	find_content(s, &first, &last);
        printf("%c...%c\n", *first, *last);
	
	s = " ";
	find_content(s, &first, &last);
        printf("%c...%c\n", *first, *last);

	
	//char input[] = "       hello       ";
	char input[] = " ";
	char *str = input;
	trim(&str, &first, &last);
	printf("%s\n", str);
}
