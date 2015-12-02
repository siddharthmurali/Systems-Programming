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
	//free(p);
}

void printInt(SortedListPtr list){
 	if(list == NULL) {
		printf("Error. List is null");
		return;
	}
	
 	Nodeptr ptr = NULL;

	if (list->front==NULL) 
		printf("List->front is NULL\n");
 
	printf("Sorted List: ");	
	for(ptr = list->front; ptr != NULL; ptr = ptr->next){
		printf("%d->", *(int*)ptr->data);
	}
	printf("\n");
}

int main (int argc, char ** argv){

	SortedListPtr slInt=SLCreate(compInt,destroyFunc);
	printf("\n");
	printf("Input is: 3, 5, 1, 8, 9\n");

	printf("Testing inserting nodes\n");
	int x = 3; 
	int y = 5; 
	int a = 1; 
	int b = 8; 
	int c = 6; 	
	int returnFront = 0 ;
	returnFront=SLInsert(slInt, (void *)&x);

	SLInsert(slInt, (void *)&y);
	SLInsert(slInt, (void *)&a);
	SLInsert(slInt, (void *)&b);
	SLInsert(slInt, (void *)&c);

	printInt(slInt);
	printf("\n");

	printf("Testing removing nodes\n"); 
	int d=1;
	SLRemove(slInt, (void *)&d);
	printInt(slInt);
	printf("\n");

	printf("Testing another insertion\n"); 
	int e=4; 
	SLInsert(slInt, (void *)&e);
	printInt(slInt);
	printf("\n");
	

	printf("Testing first iterator");
	printf("\n");
	SortedListIteratorPtr iter = SLCreateIterator(slInt);
	Nodeptr tmp = SLGetItem(iter);
	printf("Iterator is pointing to %d\n",*(int *)tmp->data); 
	SLNextItem(iter);	
	SLNextItem(iter);	
	tmp=SLGetItem(iter);
	printf("After 2 iterations is now pointing to %d\n",*(int *)tmp->data); 
	printf("\n");

	printf("Testing second iterator");
	printf("\n");
	SortedListIteratorPtr iter2 = SLCreateIterator(slInt);
	Nodeptr tmp2 = SLGetItem(iter2);
	printf("Iterator is pointing to %d\n",*(int *)tmp2->data); 
	SLNextItem(iter2);	
	tmp2=SLGetItem(iter2);
	printf("After one Iteration is now pointing to %d\n",*(int *)tmp2->data); 
	printf("\n");

	printf("Testing removing a node with iterator pointing to it\n"); 
	printf("Removing a node with one iterator pointing to it.\n"); 
	int q=6;
	SLRemove(slInt, (void *)&q);
	printInt(slInt);
	tmp2=SLGetItem(iter2);
	printf("Iterator is still pointing to %d\n",*(int *)tmp2->data); 
	SLNextItem(iter2);	
	SLNextItem(iter2);	
	tmp2=SLGetItem(iter2);
	printf("After 2 SLNextItems, Iterator is now pointing to %d\n",*(int *)tmp2->data); 

	printf("\n");

	printf("Destroying the iterators\n"); 
	SLDestroyIterator(iter);
	SLDestroyIterator(iter2); 
	printf("Success.\n"); 
	printf("Destroying the list\n");
	SLDestroy(slInt);
	printf("Success.\n"); 
	return 0;
}
