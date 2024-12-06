/* A program to check for valid dates 
 * Kurlan Beeharry
 * October 8, 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	// Input variables
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

		// User input in correct format
		printf("Enter a date (mm/dd/yyyy): ");
		int result = scanf("%d /%d /%d", &m, &d, &y);
		
		int maxDay = 0;

		// Check for valid days in month entered
		if(m <= 12 && m >= 1){
			switch(m){
                	        case 2:
                        	        maxDay = 28;
                                	break;
                        	case 4:
                                	maxDay = 30;
                                	break;
                        	case 6:
                                	maxDay = 30;
                                	break;
                        	case 9:
                                	maxDay = 30;
                                	break;
                        	case 11:
                                	maxDay = 30;
                                	break;
                        	default:
                                	maxDay = 31;
        	                        break;
                	}
				
			// When input valid, check for earliest date
			if(d <= maxDay && d >= 1){

				// When first date entered
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

					//When earlier month found
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
		}

	} while(m != 0 || d != 0 || y != 0); // Do while input 0/0/0 not entered

	// Assigning month in english to input entered
	if(prevY != 0 && prevM != 0 && prevD != 0){
		char* s;
		switch(prevM){
			case 1:
				s = "January";
				break;
			case 2:
				s = "February";
				break;
			case 3:
				s = "March";
				break;
			case 4:
				s = "April";
				break;
			case 5:
				s = "May";
				break;
			case 6:
				s = "June";
				break;
			case 7:
				s = "July";
				break;
			case 8:
				s = "August";
				break;
			case 9:
				s = "September";
				break;
			case 10:
				s = "October";
				break;
			case 11:
				s = "November";
				break;
			case 12:
				s = "December";
				break;
		}
		// Display earliest date
		printf("\nThe earliest valid date is %d %s, %d.\n", prevD, s, prevY);
	} else {
		puts("no dates entered");
	}
}
