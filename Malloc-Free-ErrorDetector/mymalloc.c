#include "mymalloc.h"

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;
static char TotalMemBlock[5000];
long unsigned int blockCount=0;
long unsigned int spaceCount=0;

void *mymalloc(unsigned int size, char * file, int line) {

	
	static int initialize = 0;
	memBlock* curr;
	memBlock* new;


	//Cannot allocate to 0 or less
	if(size<=0){
		printf("Error: Cannot allocate memory to size of %d\n", size);
		return (void*) 0;
	}
	
	//Not enough space
	if((size + sizeof(struct memBlock) > (5000 - (spaceCount + sizeof(struct memBlock))))){
		printf("Error: Not enough space to allocate memory of size %d\n", size);
	}

	if(initialize == 0){
		front = (memBlock*) TotalMemBlock;
		end = front;
		front->prev = 0;
		front->isFree = 0;
		front->size = 5000 - sizeof(struct memBlock);
		initialize = 1;
	}

	if(size < 250){
		curr = front;
		memBlock* lag = 0;
		do {
			memBlock* nxt = (struct memBlock*) (((char*)curr + sizeof(struct memBlock)) + (int)curr->size);
			
			if(curr->size < size){
				lag = curr;
				curr = nxt;
			}
			else if(curr->isFree == 0){
				lag = curr;
				curr = nxt;
			}
			else if(curr->size == size){
				curr->isFree = 0;
				
				if((char*)nxt >= (TotalMemBlock + 5000)){
					end = curr;
				}

			blockCount++;
			spaceCount += curr->size + sizeof(struct memBlock);

			return (void*) ((char*)curr + 500);
			}
			} while((char*)curr < (TotalMemBlock + 5000));
	}
	 else{ 

		curr = end;
		memBlock* nxt = (struct memBlock*) (((char*)curr + sizeof(struct memBlock)) + (int)curr->size);
		do{
			if(curr->size < size){
				nxt = curr;
				curr = curr->prev;
			}
			else if(curr->isFree == 0){
				nxt = curr;
				curr = curr->prev;
				
			}

			else if(curr->size == size){
				curr->isFree = 0;
			
				if((char*)nxt >=(TotalMemBlock + 5000)){
					end = curr;
				}
				blockCount++;
				spaceCount += curr->size + sizeof(struct memBlock);
			
				return (void*) ((char*)new + sizeof(struct memBlock));
			}
		} while((char*)curr >= TotalMemBlock);
	}

	
	return (void *) 0;
 } 
	
void myfree(void *ptr, char *file, int line){
	int i;
	int x = 0;	
	memBlock*  nodePtr;
	memBlock* prev;

	memBlock* curr = (memBlock*)((char*)ptr - sizeof(memBlock));

	//Initial Null Check
	if(ptr == 0){
		printf("Error: Cannot free pointer that does not exist\n");
	}

	//not in heap check 
	if ( (char*)ptr >=  (TotalMemBlock + 5000) || (((char*)ptr - sizeof(memBlock))) < TotalMemBlock){ 
		printf("ERORR: pointer is not in heap.\n");
		return; 
	}	


	//check if already free 
	if (curr->isFree) { 
		printf("ERROR: pointer is already freed"); 
		return; 
	}

	curr->isFree=1;
	blockCount--;	
	spaceCount = spaceCount - (curr->size + sizeof(memBlock));
	prev = (((memBlock*)(char*)curr+sizeof(memBlock))+(int)curr->size);

	if(prev <= end) {

		if (prev->isFree) {

			memBlock* twoprev = (memBlock*)(((char *)prev+sizeof(memBlock)) + (int)prev->size);
		
			if (twoprev <= end ) {
				twoprev->prev=curr; 
			}
		
			curr->size= curr->size  + ((prev->size)+sizeof(memBlock));

			if(prev==end) {

				end = curr; 
			}
	
		}
	}else {
		end = curr;
	}

	if (curr!=front && ((curr->prev)->isFree)) {

		if (curr == end ) {
			end = curr->prev; 
		} 

		if (prev <= end ) {
			prev->prev= curr -> prev; 

		}

		(curr->prev)->size += (curr->size + sizeof(memBlock));

	}	
						
}
