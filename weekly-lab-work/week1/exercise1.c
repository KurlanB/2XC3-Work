/* An introduction program
*
* Kurlan Beeharry, September 12, 2024
*/
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

int main(){
    // Introduction
    printf("Name: Kurlan Beeharry\n");
    sleep(1.5);
    
    printf("Student#: 400521584\n");
    sleep(1.5);
    
    puts("Course Name: Development Basics - 2XC3\n");
    sleep(1.5);

    // Question 1
    puts("What do you think is the most useful thing you’ve learned so far in this course?");
    sleep(1.5);

    puts("I think Linux file management is really going to be useful in the future.\n");
    sleep(1.5);

    // Question 2
    puts("Is there anything you’ve learned so far that you do not think is useful? If so, explain why.");
    sleep(1.5);

    puts("No I don't think I've learned anything not useful.\n");
    sleep(1.5);

    // Question 3
    puts("What are the advantages and disadvantages of using vim for coding?");
    sleep(1.5);

    puts("It is easy to edit code quickly but takes too much time to learn all the shortcuts.\n");
    sleep(1.5);

    // Question 3
    puts("What are the advantages and disadvantages of using VS Code for coding?");
    sleep(1.5);

    puts("VSCode's assistance in writing and debugging code is a great advantage, \nhowever setting up all the extensions for debugging can be confusing.\n");
    sleep(1.5);
    return EXIT_SUCCESS;
}