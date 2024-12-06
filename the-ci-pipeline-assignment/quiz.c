/* An simple quiz program
*
* Kurlan Beeharry, September 19, 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	//Display Help information
	if(argc > 1 && strcmp(argv[1], "--help") == 0){
		
		puts("Usage: quiz [-#] [<ANSWER>] \nQuiz about 2XC3 - Development Basics\n");
		puts("When no ANSWER, output quiz question.\n");
		puts("-#	display question of number #\n--help	display this help screen\n");
		puts("Examples:\n quiz -1	Display question 1\n quiz -1 'hi'	Display question 1 and answer validity");
		
	}else if (argc > 1 && strcmp(argv[1], "-1") == 0) { //Display first question
		puts("What does wsl stand for ?");
		
		//Display answer
		if (argc > 2){
			puts(argv[2]);
			
			//Display validity of answer
			if (strcmp(argv[2], "Windows Subsystem for Linux") == 0){
				puts("You have answered correctly !");
			} else {
				puts("You are incorrect");
			}
		}
		return EXIT_SUCCESS;

	} else if(argc > 1 && strcmp(argv[1], "-2") == 0) { //Display second question
		puts("What does CI stand for ?");
                
		//Display answer
		if (argc > 2){
                        puts(argv[2]);
                        
			//Display validity of answer
			if (strcmp(argv[2], "Continuous Integration") == 0){
                                puts("You have answered correctly !");
                        } else {
                                puts("You are incorrect");
                        }
		}
		return EXIT_SUCCESS;

	} else {	
		
		//Display error message if input is invalid
		puts("Usage: quiz [-#] [<ANSWER>]");
		puts("Try 'quiz --help' for more information.");
		return EXIT_FAILURE;
	}	
}
