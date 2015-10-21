#ifndef MALLOC_H
#define MALLOC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define malloc( x )  mymalloc( x, __FILE__, __LINE__ )
#define free( x )  myfree( x, __FILE__, __LINE__ )



typedef struct  memBlock* memBlock;
struct memBlock{ 		// memBlock struct for each memory "node"
	memBlock prev;
	memBlock next;
	int isFree;
	unsigned int size;
	 
};

// Function definitions to be implemented in malloc.c

void *mymalloc(unsigned int size, char * file, int line);
void myfree(void *ptr, char *file, int line);


