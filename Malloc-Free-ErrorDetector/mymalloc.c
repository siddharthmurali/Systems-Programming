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
	newBlock->prev=NULL; 
	newBlock->size=size; 
	
	
	return newBlock->data;

	 

}

void *myrealloc(void *ptr, unsigned int size, char *file, int line){





} 


void myfree(void *ptr, char *file, int line){





}
	
