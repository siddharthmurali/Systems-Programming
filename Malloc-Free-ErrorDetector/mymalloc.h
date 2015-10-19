#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MYMALLOC_H
#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )
#define calloc( x , y ) mycalloc( x, y, __FILE__, __LINE__ )
#define realloc( x , y ) myrealloc( x, y, __FILE__, __LINE__ )


typedef struct memBlock memBlock;
struct memBlock{ 		// memBlock struct for each memory "node"
	memBlock *prev;
	memBlock *next;
	int isFree;
	int size;
	void* data; 
};

// Function definitions to be implemented in malloc.c

void *mymalloc(unsigned int size, char * file, int line);
void *mycalloc(int numEle, unsigned int size, char *file, int line);
void *myrealloc(void *ptr, unsigned int size, char *file, int line);
void myfree(void *ptr, char *file, int line);

