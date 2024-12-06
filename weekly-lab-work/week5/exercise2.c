/* A program to check for the earliest valid date 
 * Kurlan Beeharry
 * October 8, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	// User input variables
	int m;
        int d;
        int y;

	// Valid date variables
	int prevM = 0;
	int prevD = 0;
	int prevY = 0;

	do{
		m = 0;
		d = 0;
		y = 0;

		// Gathering input from user in proper format
		printf("Enter a date (mm/dd/yyyy): ");
		int result = scanf("%d /%d /%d", &m, &d, &y);
		
		// When inputs are valid check if earlier
		if(d <= 31 && d >= 1 && m <= 12 && m >= 1){

			// Setting first date	
			if(prevY == 0){
				prevY = y;
				prevM = m;
				prevD = d;

			// When earlier year found
			}else if(prevY > y){
				prevY = y;
				prevM = m;
				prevD = d;

			// When same year found, check for month
			}else if(prevY == y){
				
				// When earlier month found
				if(prevM > m){
					prevY = y;
					prevM = m;
					prevD = d;

				// When same month found, check for day
				}else if (prevM == m){

					// When earlier day found
					if(prevD > d){
						prevY = y;
						prevM = m;
						prevD = d;
					}
				}
			}

		}
	} while(m != 0 || d != 0 || y != 0); // Do while the 0/0/0 input not entered

	// Displaying final date
	if(prevY != 0 && prevM != 0 && prevD != 0){
		printf("\nThe earliest valid date is %d/%d/%d.\n", prevM, prevD, prevY);
	} else {
		puts("no dates entered");
	}
}
