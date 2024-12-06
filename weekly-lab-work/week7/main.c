#include <stdlib.h>
#include <stdio.h>
#include "array_utilities.h"

int main(){
	int array[] = {1, 2, 3, 2, 5, -1, 10, 99, 22, -100, 100};
	int size = 11;
	int key, index, counter;
	int *pointer;

	puts("--------Index Test Cases--------");

	puts("Test Case #1");
	key = 100;
	index = find_index(array, size, key);
	printf("Key: %d, Index: %d\n", key, index);

	puts("Test Case #2");
        key = 1;
	index = find_index(array, size, key);
        printf("Key: %d, Index: %d\n", key, index);

	puts("Test Case #3");
        key = -1;                                                                      
	index = find_index(array, size, key);
        printf("Key: %d, Index: %d\n", key, index);

	puts("Test Case #4");
        key = 99;                                                                 
	index = find_index(array, size, key);
        printf("Key: %d, Index: %d\n", key, index);

	puts("Test Case #5");
        key = 101;                                                                                            index = find_index(array, size, key);
        printf("Key: %d, Index: %d\n", key, index);

	puts("-------Pointer Test Cases--------");

	puts("Test Case #1");
        key = 2; 
	pointer = find_pointer(array, size, key);
	if(pointer == NULL){
		printf("Key %d NOT FOUND\n", key);
	} else {
		printf("Key %d FOUND %d\n", key, *pointer);
	}

	puts("Test Case #2");
        key = -100;
        pointer = find_pointer(array, size, key);
        if(pointer == NULL){
                printf("Key %d NOT FOUND\n", key);
        } else {
                printf("Key %d FOUND %d\n", key, *pointer);
        }

	puts("Test Case #3");
        key = 321;
        pointer = find_pointer(array, size, key);
        if(pointer == NULL){
                printf("Key %d NOT FOUND\n", key);
        } else {
                printf("Key %d FOUND %d\n", key, *pointer);
        }

	puts("Test Case #4");
        key = 1;
        pointer = find_pointer(array, size, key);
        if(pointer == NULL){
                printf("Key %d NOT FOUND\n", key);
        } else {
                printf("Key %d FOUND %d\n", key, *pointer);
        }
	 
	puts("Test Case #5");
        key = 100;
        pointer = find_pointer(array, size, key);
        if(pointer == NULL){
                printf("Key %d NOT FOUND\n", key);
        } else {
                printf("Key %d FOUND %d\n", key, *pointer);
        }

	puts("-------Count Test Cases------");

	puts("Test Case #1");
	key = 2;
	counter = count(array, size, key);
	printf("Key %d, Count %d\n", key, counter);

	puts("Test Case #2");
        key = 100;
        counter = count(array, size, key);
        printf("Key %d, Count %d\n", key, counter);

	puts("Test Case #3");
        key = 1234;
        counter = count(array, size, key);
        printf("Key %d, Count %d\n", key, counter);

	puts("------Count2d Test Case------");

	int array2[3][4] = {{1,2,3,4}, {4,3,2,1}, {5,6,7,8}};
	puts("Test Case #1");
	key = 2;
	counter = count2d(3, 4, array2, key);
	printf("Key %d, Count %d\n", key, counter);

}	
