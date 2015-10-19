#include "mymalloc.h"

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;
int debug = 1;

void *mycalloc(int numEle, unsigned int size, char *file, int line){


return 0;
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
	front =  newBlock;
	newBlock->prev=NULL; 
	newBlock->size=size; 
	
	
	return front->data;

}


/*
void *myrealloc(void *ptr, unsigned int size, char *file, int line){

	int ptrSize;
	int ptrIsFree;
	memBlock* ptrNext;
	memBlock* ptrPrev;	
	
	ptrSize = ptr - (sizeof(int) +1);
	ptrIsFree = ptrSize -(sizeof(int) +1);
        ptrNext = ptrIsFree -(sizeof(memBlock*) +1);
        ptrPrev = ptrNext - (sizeof(memBlock*) + 1);	
	if(ptr == NULL){
		printf("%s:%d: Error: Cannot realloc to Null", file, line);
		exit(EXIT_FAILURE);
	}
	else{
		ptrSize = size;
		ptrNext = front;
		front = ptrNext;
	}

	return ptr;
				

} 
*/

void myfree(void *ptr, char *file, int line){

//	printf("seg check\n");
	
	int i;
	void* ptrSize;
	void* ptrIsFree;	
	memBlock* ptrNext;
	memBlock* ptrPrev;

//	printf("seg check\n");

	ptrSize = ptr - (sizeof(int) + 1);
	ptrIsFree = ptrSize -(sizeof(int) +1);
	ptrNext = ptrIsFree -(sizeof(memBlock*) +1);
	ptrPrev = ptrNext - (sizeof(memBlock*) + 1);

	printf("seg check\n");

	int *ptrSizeUV = ptrSize;
	
	printf("%d\n", *ptrSizeUV);

	printf("seg check\n");

	if(ptrSizeUV ==0){
		printf("Error: Cannot free size 0");
		return;
	}

	printf("seg check after EC\n");

	ptrPrev->next = ptrNext;

	printf("seg check before for\n");	
	for(i = 0; i<=*ptrSizeUV; i++){
		memBlock* newBlock = (memBlock*)malloc(sizeof(memBlock));
		end -> next = newBlock;
		end = newBlock;
		end -> isFree = 0;
	}

	printf("free accomplished");
	return;
						
	
	return;
}



	
