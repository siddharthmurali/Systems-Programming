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
		printf("Before initialization");

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
		
		end = front;
		front = fptr;
	}
	
	if (size==0){
		printf("ERROR: Can't allocate size 0");
		return (void *) 0;
	}

	int spaceCheck = 0;
	int count = 0 ;
	memBlock* nodeDelptr = end;

	while(nodeDelptr->isFree) {
		count++;
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
	newBlock->prev=NULL; 
	newBlock->size=size; 
	
	
	return (void *)newBlock->data;


}

void *myrealloc(void *ptr, unsigned int size, char *file, int line){





} 


void myfree(void *ptr, char *file, int line){





}
	
