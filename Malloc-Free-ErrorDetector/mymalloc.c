#include "mymalloc.h"

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;
<<<<<<< HEAD
=======
static memMap* map;
>>>>>>> 4cfb891885cd682c01d23dda1843a85108da4fe1
int debug = 0;

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

	//intializes doubly linked list if first malloc
	if (front==NULL) {
		intializer();
	}

	//checks to see if there are free nodes at the end of the list, each node is a byte. 
	while(nodeDelptr->isFree==1) {
                count++;

                if (debug)
                        printf("In while loop to delete nodes, count = %d and totalsize = %d\n",count,totalsize);

                if (count==totalsize) {
                        spaceCheck=1;
                        break;
<<<<<<< HEAD

return 0;
			return 0;
=======
>>>>>>> 4cfb891885cd682c01d23dda1843a85108da4fe1
                }

                if (count>totalsize)
                        break;

                nodeDelptr=nodeDelptr->prev;
        }

	if (!spaceCheck) {
		printf("ERROR: Not enough space to allocate desired size\n"); 
		return (void *) 0;
	}	

	//Deletes the number of nodes needed. Aka when number of free nodes=totalsize
	while(nodeDelptr->next!=NULL){

		nodeDelptr=nodeDelptr->next; 
		free(nodeDelptr->prev);	
	}


	//adds a new node to the beginning of the list of size=totalsize	
	memBlock* newBlock= (memBlock*) malloc(sizeof(memBlock)); 
	newBlock->next=front; 
	newBlock->prev=NULL; 
	newBlock->size=totalsize; 
	newBlock->data = malloc(numEle * (sizeof(size)));
<<<<<<< HEAD
=======

	front =  newBlock;

	//adds information to the memory map
	int y=0; 
	for(y=0;y<sizeof(map);y++){

		if(map[y].memAddr==0) {
			map[y].memAddr = newBlock;
			map[y].dataAddr = newBlock->data;
		}
	}
>>>>>>> 4cfb891885cd682c01d23dda1843a85108da4fe1

	return newBlock->data;
}	


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
	
<<<<<<< HEAD
	
	return front->data;
=======
	front =  newBlock;

	//adds the malloc to the memory map 
	int y=0; 

	for(y=0;y<sizeof(map);y++){

		if(map[y].memAddr==0) {
			map[y].memAddr = newBlock;
			map[y].dataAddr = newBlock->data;
		}
	}

	return newBlock->data;
>>>>>>> 4cfb891885cd682c01d23dda1843a85108da4fe1
}

/*
void *myrealloc(void *ptr, unsigned int size, char *file, int line){

	void* ptrSize;
	int ptrIsFree;
	memBlock* ptrNext;
	memBlock* ptrPrev;	
	
	ptrSize = &ptr - (sizeof(int));

	int* ptrSizeUV = ptrSize;	
	printf("%d\n", *ptrSizeUV);

	ptrIsFree = ptrSize -(sizeof(int));
        ptrNext = ptrIsFree -(sizeof(memBlock*));
        ptrPrev = ptrNext - (sizeof(memBlock*));	

	if(ptr == NULL){
		printf("%s:%d: Error: Cannot realloc to Null", file, line);
		exit(EXIT_FAILURE);
	}
	else{
		ptrSize = size;
		ptrNext = front;
		front = ptrNext;
	}

	printf("Accomplished Realloc\n");
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

<<<<<<< HEAD
	ptrSize = &ptr - (sizeof(int));
=======
	
	
	ptrSize = p - (sizeof(int));
>>>>>>> 4cfb891885cd682c01d23dda1843a85108da4fe1
	ptrIsFree = ptrSize -(sizeof(int));
	ptrNext = ptrIsFree -(sizeof(memBlock*));
	ptrPrev = ptrNext - (sizeof(memBlock*));

	printf("seg check");

	int ptrSizeUV = *((int *)ptrSize);

	printf("%d\n", ptrSizeUV);

	printf("seg check\n");

	if(ptrSizeUV ==0){
		printf("Error: Cannot free size 0");
		return;
	}

	printf("seg check after EC\n");

	ptrPrev->next = ptrNext;

	printf("seg check before for\n");	
	for(i = 0; i<=ptrSizeUV; i++){
		memBlock* newBlock = (memBlock*)malloc(sizeof(memBlock));
		end -> next = newBlock;
		end = newBlock;
		end -> isFree = 0;
	}

	printf("free accomplished");
	return;
						
	
	return;
}

<<<<<<< HEAD

=======
>>>>>>> 4cfb891885cd682c01d23dda1843a85108da4fe1
