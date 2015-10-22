#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stdlib.h>
#include <stdio.h>

typedef struct MemEntry MemEntry;

struct MemEntry{
	MemEntry *prev, *succ; //prev or next chunk of mem
	int isfree;	//boolean flag
	int size;
};


void *mymalloc(unsigned int size, char *file, int line);
void myfree(void *p, char *file, int line);
int hasEntry(MemEntry *ptr);
void *mycalloc(int ct, unsigned int size, char *file, int line);
void *myrealloc(void *p, unsigned int size, char *file, int line);
size_t getSize(void * p);

#endif
