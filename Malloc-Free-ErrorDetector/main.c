#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.c"


struct node{
	struct node *next;
	int data;
};

typedef struct node* nodeptr;

int main(int argc, char **argv){

//Implement Test Cases

	printf("\n");
	//PreliminaryTests
	
	//MALLOC TEST
	printf("Preliminary Malloc Tests:\n"); 

	int* s = (int*) malloc(sizeof(int)); 
	int* d = (int*) malloc(sizeof(int));

	*d = 20;
	*s = 10;

	//FREE TEST
	printf("Preliminary Free Tests:\n");
	
	free(s);
	free(d);
	printf("\n");



	//HEAP STRESS TEST - Heap Overflow 
	printf("Heap Overflow Test:\n");
		

	return 0;
}


