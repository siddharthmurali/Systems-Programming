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
	if(ptr == 0){
		printf("Error: Cannot free pointer that does not exist\n");
	}

	memBlock curr = (memblock)((char*)ptr - sizeof(memBlock));

	//Other checks 

	if ( (char*)ptr >= 	
	
	return;
						
}
