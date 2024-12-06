#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int find_index(int array[], int size, int key){
	for(int i = 0; i < size; i++){
		if(array[i] == key){
			return i;	
		}
	}
	return -1;
}

int *find_pointer(int array[], int size, int key){
	for(int *p = array; p < array + size; p++){
		if(*p == key){
			return p;
		}
	}
	return NULL;
}

int count(int array[], int size, int key){
	int count = 0;
	int *pointer = array;
	int new_size = size;

	while(true){
		pointer = find_pointer(pointer, new_size, key);
		if(pointer == NULL){
			break;
		}
		pointer++;
		new_size = pointer - array;
		count++;
	}

	return count;
}

int count2d(int row, int column, int array[row][column], int key){
	int sum = 0;
	for(int i = 0; i < row; i++){
		sum += count(array[i], column, key);
	}
	return sum;
}
