/* A program to display a calendar
 * Kurlan Beeharry
 * October 8, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	int numDays;
	int day;

	// Input for number of days
	printf("How many days in this month? ");
	int result = scanf("%d", &numDays);
	
	int result1 = 0;

	// If no error, Input for starting day
	if(result == 1 && numDays > 0 && numDays <= 31){
		printf("\nWhat's the starting day (1=Monday, 7=Sunday)? ");
        	result1 = scanf("%d", &day);

	} else {
		fprintf(stderr, "Invalid input\n");
		return EXIT_FAILURE;
	}

	// If input valid, then display calendar
	if(result1 == 1 && day > 0 && day <= 7){

		// Displaying days of the week
		printf(" M  T  W  T  F  S  S\n");
		int countDays = 1;
		
		// Keep displaying until end of days
		while(countDays <= numDays){

			// Display only seven days per row
			for(int i = 1; i <= 7; i++){
				
				// Displaying first day and date
				if(countDays == 1){
					if(i == day){
						printf("%2d ", countDays);
						countDays++;
					}else{
						printf("%3s", "   ");
					}
				
				// Displaying rest of days	
				} else {
					if(countDays <= numDays){
						printf("%2d ", countDays);
						countDays++;
					}else{
						break;
					}
				}		
			}
			// Create new row/week
			puts("");
		}
	// Errors
	} else {
		fprintf(stderr, "Invalid input\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
