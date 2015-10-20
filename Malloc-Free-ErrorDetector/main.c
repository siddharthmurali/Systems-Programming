#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mymalloc.c"

#define malloc(x) mymalloc(x, __FILE__, __LINE__);
//#define calloc(x, y) mycalloc(x,y, __FILE__, __LINE__);
//#define realloc(x,y) myrealloc(x,y, __FILE__, __LINE__);
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

	int* s = (int*) malloc(sizeof(int)); 
	//char* a = (char*) malloc(sizeof(char)); 

	int* d = (int*) malloc(sizeof(int));

	*d = 20;
	*s = 10;
	//a = "s"; 

	//FREE TEST
	printf("Preliminary Free Tests:\n");
	
	free(s)

	printf("\n");

	//REALLOC TEST

	char *str;
	
//	str = (char *)malloc(15);
//	str = (char *)realloc(str, 25);

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


