#include "mymalloc.h"

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;
int debug = 1;

void *mycalloc(int numEle, unsigned int size, char *file, int line){



}	


void *mymalloc(unsigned int size, char * file, int line) {
	static int initialized = 0;
	int x=0;
	
	if (front==NULL) { 
		initialized=0;
	}

	if (debug) 
		printf("Before initialization\n");

	if (!initialized){
		front = (memBlock*)malloc(sizeof(memBlock)); 
		front->isFree = 1;
		front->size = 0; 
		front->prev=NULL;
		front->next=NULL;
		memBlock* fptr=front;
		memBlock* bptr=front;
		front=front->next;

		for (x=0; x<5000; x++){

			front= (memBlock*)malloc(sizeof(memBlock)); 
			front->isFree = 1;
			front->size = 1; 
			front->prev=bptr;
			front->next=NULL;
			bptr=front;
			front=front->next;	
		}
		
		end = bptr;
		front = fptr;
	}

		
	if (size==0){
		printf("ERROR: Can't allocate size 0");
		return (void *) 0;
	}

	int spaceCheck = 0;
	int count = 0 ;
	memBlock* nodeDelptr = end;

	if (debug)
		printf("Before while loop: nodedelptr->isFree = %d\n",nodeDelptr->isFree);

	while(nodeDelptr->isFree==1) {
		count++;

		if (debug)
			printf("In while loop to delete nodes\n");
		if (count==size) {
			spaceCheck=1; 
			break;	

		} 

		if (count>size) 
			break;

		nodeDelptr=nodeDelptr->prev;	
	}	

	

	if (!spaceCheck){ 
		printf("Error: Not enough space to malloc size of %d",size); 
		return (void *) 0;
	}

	while(nodeDelptr->next!=NULL){

		nodeDelptr=nodeDelptr->next; 
		free(nodeDelptr->prev);	
	}

	
	memBlock* newBlock= (memBlock*) malloc(sizeof(memBlock)); 
	newBlock->next=front; 
<<<<<<< HEAD
	front =  newBlock;
=======
	front = newBlock;
>>>>>>> 4c2174b140abf760c54bf30b02621e027972201b
	newBlock->prev=NULL; 
	newBlock->size=size; 
	
	
<<<<<<< HEAD
	return front->data;
=======
	return (void *)newBlock->data;
>>>>>>> 6f629371e9f5b2065dee0830f7cbb654adf4087d

}

void *myrealloc(void *ptr, unsigned int size, char *file, int line){





} 


void myfree(void *ptr, char *file, int line){
	
	int i;

	ptrSize = ptr - (sizeof(int) + 1);
	ptrIsFree = ptrSize -(sizeof(int +1);
	ptrNext = ptrIsFree -(sizeof(memBlock* +1);
	ptrPrev = ptrNext - (sizeof(memBlock* + 1);
	if(ptrSize ==0){
		printf("Error: Cannot free size 0");
		return;
	}
	
	ptrPrev->next = ptrNext;

	else{
		for(i = 0; i<=ptrSize; i++){
			memBlock* newBlock = (memBlock*)malloc(sizeof(memBlock));
			end -> next = newBlock;
			end = newBlock;
			end -> isFree = 0;
		}
		return;
	}					
	
	return;
}



}
	
