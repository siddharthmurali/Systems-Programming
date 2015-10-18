#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MYMALLOC_H

typedef struct memBlock memBlock;
struct memBlock{
	memBlock *prev;
	memBlock *next;
	int isFree;
	int size;
};

void *mymalloc(unsigned int size, char * file, int line);
void *mycalloc(int numEle, unsigned int size, char *file, int line);
void *myrealloc(void *ptr, unsigned int size, char *file, int line);
void myfree(void *ptr, char *file, int line);

