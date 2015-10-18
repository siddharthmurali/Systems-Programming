#include <mymalloc.h>

//Need to add definitions, etc...

static memBlock* front; 
static memBlock* end;

void *mycalloc(int numEle, unsigned int size, char *file, int line){



}	


void *mymalloc(unsigned int size, char * file, int line){
	static int initialized =0;

	
	if (front==null)  
		intialize=0;
	
	if (!intialize){
		front = (memBlock*)malloc(sizeof(memBlock)); 
		for (int x=0; x<5000; x++){
			front->next = (memBlock*)malloc(sizeof(memBlock)); 
			font=front->next;	
		{
	}


	 

}

void *myrealloc(void *ptr, unsigned int size, char *file, int line){





} 


void myfree(void *ptr, char *file, int line){





}
	
