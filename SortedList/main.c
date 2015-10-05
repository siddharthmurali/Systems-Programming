#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.c"
//SidSunnyLabs



int compInt(void * p1, void * p2 ){

        int   * x1 = (int *)p1;
        int   * x2 = (int *)p2;

        if ( *x1 < *x2 )
                return -1;
        else if ( *x1 > *x2 )
                return 1;
        else
                return 0;
}

void destroyFunc(void *p){
	free(p);
}

void printInt(SortedListPtr list){
 	if(list == NULL) {
		printf("Error. Sorted List is null");
		return;
	}

	if (list->front == NULL) {
		printf("Error. list-front is null");
	}
	
 	Nodeptr ptr = NULL;
 	printf("%d\n", *(int *)(list->front->data));	
	for(ptr = list->front; ptr != NULL; ptr = ptr->next){
		printf("%d->", *(int*)ptr->data);
	}
	printf("\n");
}


int main (int argc, char ** argv){

	printf("Testing Int Comparing \n");

	
	SortedListPtr slInt=SLCreate(compInt,destroyFunc);
	printf("Input is: 3, 5, 1, 8, 9");

	int x = 3; 
	int y = 5; 
	int a = 1; 
	int b = 8; 
	int c = 6; 	

	SLInsert(slInt, (void *)&x);
	SLInsert(slInt, (void *)&y);
	SLInsert(slInt, (void *)&a);
	SLInsert(slInt, (void *)&b);
	SLInsert(slInt, (void *)&c);

	printInt(slInt);

	
	return 0;
}
