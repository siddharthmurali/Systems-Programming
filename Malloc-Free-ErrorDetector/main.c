#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.c"

#define malloc(x) mymalloc(x, __FILE__, __LINE__);
#define calloc(x, y) mycalloc(x,y, __FILE__, __LINE__);
#define realloc(x,y) myrealloc(x,y, __FILE__, __LINE__);
#define free(x) myfree(x, __FILE__, __LINE__);

struct node{
	struct node *next;
	int data;
};

typedef struct node* nodeptr;

int main(int argc, char **argv){

//Implement Test Cases

	printf("\n");

	//MALLOC TEST
	printf("Preliminary Malloc Tests:\n"); 

	char* s = (char*) malloc(sizeof(char)); 

	s = "d";
	printf("s = %s\n", s); 

	printf("\n");

	//CALLOC TEST
	printf("Preliminary Calloc Tests:\n"); 

	int* t = (int*) calloc(3,sizeof(int)); 

	t[0] = 2; 
	t[1] = 3;

	printf("t[0] = %d and t[1] = %d\n", t[0],t[1]); 
	printf("\n");


	//HEAP STRESS TEST - Heap Overflow 
	printf("Heap Overflow Test:\n");
		

return 0;
}


