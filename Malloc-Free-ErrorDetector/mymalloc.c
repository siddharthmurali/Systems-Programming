#include <mymalloc.h>

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;

void *mycalloc(int numEle, unsigned int size, char *file, int line){



}	


void *mymalloc(unsigned int size, char * file, int line){
	static int initialized = 0;
	
	if (front==null)  
		intialize=0;
	
	if (!intialize){
		front = (memBlock*)malloc(sizeof(memBlock)); 
		memBlock* fptr=front;

		for (int x=0; x<5000; x++){

			front->next = (memBlock*)malloc(sizeof(memBlock)); 
			front->isFree = 1;
			front->size = 0; 
			font=front->next;	
		{
		
		end = front;
		front = fptr;
	}
	
	if (size==0){
		printf("Can't allocate size 0");
		return (void *) 0;
	}

	bool spaceCheck = false; 
	int count = 0 ;
	memBlock* nodeDelptr = end;

	while(nodeDelptr->isFree) {
		count++;
		if (count==size) {
			spaceCheck=true; 
			break;	

		}
		nodeDelptr=nodeDelptr->prev;	
	}	


	if (!spaceCheck){ 
		printf("Error: Not enough space to malloc size of %d",size); 
		return (void *) 0;
	}

	while(nodeDelptr->next!=null){

		nodeDelptr=nodeDelptr->next; 
		free(nodeDelptr->prev);	


	}

	
	memBlock* newBlock= (memBlock*) malloc(sizeof(memBlock)); 
	newBlock->next=front; 
	front = newBlock;
	newBlock->prev=NULL; 
	newBlock->size=size; 
	
	
	return front->data;

	 

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


//Macro Definitions

#define mymalloc( x ) mymalloc(x, __FILE__, __LINE__)
#define myfree( x) myfree(x, __FILE__, __LINE__ )
#define mycalloc(x) mycalloc(x, __FILE__, __LINE__)
#define myrealloc(x) myrealloc(x, __FILE__, __LINE__)




void myfree(void *ptr, char *file, int line){
	


}
	
