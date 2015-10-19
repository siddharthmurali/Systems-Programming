#include "mymalloc.h"

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;
int debug = 1;

void *mycalloc(int numEle, unsigned int size, char *file, int line){

	if (size==0){ 
		printf("ERROR: size of malloc cannot be 0"); 
		return (void *) 0;
	}

	int totalsize=numEle*size; 
	int count = 0; 
	int spaceCheck = 0;
	memBlock* nodeDelptr = end;

	if (debug && (front==NULL)) 
		printf("Front is equal to NULL in Calloc");

	if (front==NULL) {
		intializer();
	}

	while(nodeDelptr->isFree==1) {
                count++;

                if (debug)
                        printf("In while loop to delete nodes, count = %d and totalsize = %d\n",count,totalsize);

                if (count==totalsize) {
                        spaceCheck=1;
                        break;

                }

                if (count>totalsize)
                        break;

                nodeDelptr=nodeDelptr->prev;
        }

	if (!spaceCheck) {
		printf("ERROR: Not enough space to allocate desired size\n"); 
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
	newBlock->size=totalsize; 
	newBlock->data = malloc(numEle * (sizeof(size)));
}	


void intializer() {
	int x=0 ;

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

void *mymalloc(unsigned int size, char * file, int line) {
	int x=0;

	if (debug) 
		printf("Before initialization\n");

	if (front==NULL){
		intializer();
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
	newBlock->data = malloc(sizeof(size));
	
	
	return front->data;

}

/*
void *myrealloc(void *ptr, unsigned int size, char *file, int line){

	
	
	ptrSize = ptr - (sizeof(int) +1);
	ptrIsFree = ptrSize -(sizeof(int +1);
        ptrNext = ptrIsFree -(sizeof(memBlock* +1);
        ptrPrev = ptrNext - (sizeof(memBlock* + 1);	
	if(p == NULL){
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


*/
