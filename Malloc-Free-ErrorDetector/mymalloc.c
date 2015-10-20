#include "mymalloc.h"

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;
static memMap* map;
int debug = 0;


void intializer() {
	int x=0 ;

	// intialize the 5000 nodes for the linked list
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



	//intialize the mapping array 
	map= (memMap*) malloc(sizeof(memMap)*5000); 
	int y=0; 
	for(y=0; y<sizeof(map);y++) {
		map[y].memAddr = 0; 
		map[y].dataAddr = 0;
	}
	
	if (debug)
		printf("Map 3 values: %p and %p\n",map[2].memAddr, map[2].dataAddr);
}

void *mymalloc(unsigned int size, char * file, int line) {
	int x=0;

	if (debug) 
		printf("Before initialization\n");


	//intializes doubly linked list if first malloc
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

	//checks to make sure there are enough free nodes at the end of the list.
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

	//delets the free nodes at the end of the doubly linked list
	while(nodeDelptr->next!=NULL){

		nodeDelptr=nodeDelptr->next; 
		free(nodeDelptr->prev);	
	}


	//adds a new node to the beginning of the list of the new mallocd data. This is where the 
	//free nodes are joined into one node. Ex. malloc(sizeof(int)) ==> 4 free nodes are deleted at 
	//the end of the list and 1 node of size=4 is created in the beginning
	
	memBlock* newBlock= (memBlock*) malloc(sizeof(memBlock)); 
	newBlock->next=front; 
	newBlock->prev=NULL; 
	newBlock->size=size; 
	newBlock->data=(void *) malloc(sizeof(size));
	newBlock->isFree = 0;	
	
	front =  newBlock;

	
	//adds the malloc to the memory map 
	int y; 

	for(y=0;y<sizeof(map);y++){

		if(map[y].memAddr==0) {
			map[y].memAddr = newBlock;
			map[y].dataAddr = newBlock->data;
			printf("inserted data into map\n");
			break;

		}
		
	}

<<<<<<< HEAD
	printf("newblock->data Addr: %p\n", newBlock->data);
=======
	printf("map[0] memAddr Data: %p\n", map[0].memAddr);
	printf("newBlock Add: %p\n", newBlock);
	printf("newBlock->Data: %p\n", newBlock->data);
>>>>>>> 30250618dad077483af307d268ceef99ffba1f45
	return newBlock->data;
}

void myfree(void *ptr, char *file, int line){
	printf("\n");
	printf("Entering myFree\n");

	printf("ptr Add: %p\n", ptr);
	int i;
	memBlock * nodePtr;
	printf("myFree: initialized nodePtr\n");
	for(i=0; i<5000; i++){
		if(map[i].dataAddr == ptr){
			nodePtr = map[i].memAddr;
			printf("Found data in map\n");
			break;
		}
	}
<<<<<<< HEAD
	printf("nodePtr Add: %p\n", &nodePtr);
=======
	printf("nodePtr Add: %p\n", nodePtr);

	int isFree = nodePtr->isFree;
	printf("nodePtr isFree?: %d\n", isFree);
>>>>>>> 30250618dad077483af307d268ceef99ffba1f45

	memBlock* nodePtrPrev = nodePtr->prev;
	printf("nodePtrPrev size: %d\n", nodePtrPrev->size);
	//nodePtrPrev->next = nodePtr->next;

	/*
	for(i = 0; i<=ptrSizeUV; i++){
		memBlock* newBlock = (memBlock*)malloc(sizeof(memBlock));
		end -> next = newBlock;
		end = newBlock;
		end -> isFree = 0;
	}
	*/

	printf("free accomplished");
	return;
						
	
}

