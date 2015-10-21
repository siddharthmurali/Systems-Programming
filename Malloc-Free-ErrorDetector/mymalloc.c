#include "mymalloc.h"

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;
static char TotalMemBlock[5000];
long unsigned int blockCount=0;
long unsigned int spaceCount=0;

void *mymalloc(unsigned int size, char * file, int line) {

	//Cannot allocate to 0 or less
	if(size<=0){
		printf("Error: Cannot allocate memory to size of %d\n", size);
		return (void*) 0;
	}
	
	//Not enough space
	if((size + sizeof(struct memBlock) > (5000 - (spaceCount + sizeof(struct memBlock))))){
		printf("Error: Not enough space to allocate memory of size %d\n", size);
	}

	static int initialize = 0;

	if(initialized == 0){
		front = (memBlock*) TotalMemBlock;
		end = front;
		front->prev = 0;
		front->isFree = 0;
		front->size = totMemSize - blockSize;
		

}

void myfree(void *ptr, char *file, int line){
	int i;
	int x = 0;	
	memBlock * nodePtr;

	//Initial Null Check
	if(ptr == NULL){
		printf("Error: Cannot free pointer that does not exist\n");
	}

	//Check pointer map for node pointer
	for(i=0; i<5000; i++){
		if(map[i].dataAddr == ptr){
			nodePtr = map[i].memAddr;
			x = 1;
			break;
		}
	}

	//Error for non-existant node pointer
	if(x== 0){
		printf("Error: pointer was never allocated to memory\n");
	}

	//Delete current nod
	if(nodePtr->prev == NULL){
		front = nodePtr->next;
	}
	else if(nodePtr == end){
		end = end->prev;
	}
	else{
		nodePtr->prev->next = nodePtr->next;
	}
	

	//repopulate list with # nodes = size(nodePtr)
	for(i = 0; i<=nodePtr->size; i++){
		memBlock* newBlock = (memBlock*)malloc(sizeof(memBlock));
		end -> next = newBlock;
		newBlock->prev = end;
		end = newBlock;
		end -> isFree = 1;
	}
	
	free(nodePtr->data);
	free(nodePtr);
	
	return;
						
}

