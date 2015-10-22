#include "mymalloc.h"

#define MESIZE sizeof(struct MemEntry)
#define BLOCKSIZE (1024)
#define LISTLENGTH (BLOCKSIZE/MESIZE+1)
static char big_block[BLOCKSIZE];
static void *memEntryList[BLOCKSIZE/MESIZE+1];
static int listindex = 0;

/* Obtains a free index from the memEntryList array */
static int getIndex() {
	int i;
	for (i = 0; i < (LISTLENGTH); i++) {
		if (memEntryList[i] == 0)
			return i;
	}
	return 1;
}
/* Checks if the memEntryList has a given entry */
int hasEntry(MemEntry *ptr) {
	int isValid = 0;
	for(listindex = 0; listindex < LISTLENGTH; listindex++) {
		if(ptr == memEntryList[listindex] && !ptr->isfree) {
			isValid = 1;
			return 0;	/*Success*/
		}
	}
	/*Failure*/
	return 1;
}

size_t getSize(void * p) {
    size_t *x = p;
    if (x) {
		--x;
		return *x;
	}
    return -1;
}

void exfnc(void) {
	
	
}

void *mymalloc(unsigned int size, char *file, int line){
	static int initialized = 0;
	static struct MemEntry *root, *last;
	struct MemEntry *p, *succ;
	
	// Error check, cannot malloc something to size 0
	if(size == 0){
		printf("%s:%d: error: Cannot malloc memory of size 0.\n", file, line);
		exit(EXIT_FAILURE);
	}
	
	// If initialized is NULL (i.e. equal to 0). Root has nothing (i.e nothing in memory atm)
	if(!initialized){
		root = (struct MemEntry*)big_block;
		root->prev = root->succ = 0;
		root->size = BLOCKSIZE - MESIZE;	
		root->isfree = 1;					// The space is occupied by the root, isfree becomes false.
		initialized = 1;					// Static int initialized is true. acts like a global.
		memEntryList[getIndex()] = big_block;
	}
	
	
	p = root;
	do{
		if(p->size < size)					// not enough space exists to store the memory.
			p = p->succ;
		else if (!p->isfree)				// the current space is occupied
			p = p->succ;
		else if (p->size < (size + MESIZE)){
			p->isfree = 0;
			return (char*)p + MESIZE;
		}else{								// Creating the doubly LL
			if (size < (BLOCKSIZE/4)){
				succ = (struct MemEntry*)((char*)p + MESIZE + size);
			}
			if (size >= (BLOCKSIZE/4))
			{
				succ = (struct MemEntry*)((BLOCKSIZE/2)+(char*)p + MESIZE + size);
			}
			succ->prev = p;
			succ->succ = p->succ;
			if(p->succ != 0)
				p->succ->prev = succ;
			p->succ = succ;
			succ->size = p->size - MESIZE - size;		// The rest of the unallocated memory (this is huge)
			succ->isfree = 1;
			p->size = size;
			p->isfree = 0;
			if (p == last) { last = succ; }
			else { last = last;	}
			memEntryList[getIndex()] = succ;
			return (char*)p + MESIZE;
		}
	}while(p != 0);
	
	// Handles saturation. Allocates more space when the big_block has insufficient memory.
	if ((p = (struct MemEntry*)sbrk(MESIZE + size)) == (void *)-1) {
		return 0;
	}
	else if (last == 0) {
		printf("SBKR makes first chunk size %d\n", size);
		p->prev = p->succ = 0;
		p->size = size;
		p->isfree = 0;
		root = last = p;
		return (char *)p + MESIZE;
	}
	else {
		printf("SBKR making another chunk size %d\n", size);
		p->prev = last;
		p->succ = last->succ;
		p->size = size;
		p->isfree = 0;
		last->succ = p;
		last = p;
		return (char *)p + MESIZE;
	}
	printf("%s:%d: error: not enough address space available. \n", file, line); 
	return 0;
}

void myfree(void *p, char *file, int line){
	struct MemEntry *ptr, *pred, *succ;
	ptr = (struct MemEntry*)((char*)p - MESIZE);
	
	// Check if pointer tries to free null
	if(!p){ 
		printf("%s:%d: error: Can't free pointer to NULL.\n", file, line); 
		exit(EXIT_FAILURE);
	}
	
	// Can't free pointers that were never allocated. Goes for double freeing too.
	if (ptr->isfree){
		printf(	"%s:%d: error: Cannot free memory from a variable that has no reserved memory. \n", file, line); 
		return;
	}	
	// Can't free dynamic memory not returned from malloc [eg free(p + 10)]
	if (hasEntry(ptr) == 1) {
		printf(	"%s:%d: error: Cannot free memory that was not returned from malloc or is not in the heap. \n", file, line);
		return;
	}
	
	if((pred = ptr->prev) != 0 && pred->isfree){
		pred->size += MESIZE + ptr->size;			// Adding the amount of space back when its freed
		pred->succ = ptr->succ;
		if(ptr->succ != 0)
			ptr->succ->prev = pred;
		memEntryList[listindex] = 0;
	}else{
		ptr->isfree = 1;
		pred = ptr;
	}
	if((succ = ptr->succ)!= 0 && succ->isfree){
		pred->size += MESIZE + succ->size;
		pred->succ = succ->succ;
		if(succ->succ != 0)
			succ->succ->prev = pred;
	}
	for (listindex = 0; listindex < LISTLENGTH; listindex++) {
		if (succ == memEntryList[listindex]) {
			memEntryList[listindex] = 0; 
			break;
		}
	}

}

void *mycalloc(int ct, unsigned int size, char *file, int line){
	void *ptr = mymalloc(ct*size, file, line);

	if(ptr){
		memset(ptr, '0', ct*size);
		return ptr;
	}
}

void *myrealloc(void *p, unsigned int size, char *file, int line){
	void *new;
	new = mymalloc(size, file, line);
	if(!p){ 
		printf("%s:%d: error: Cannot realloc to NULL.\n", file, line); 
		exit(EXIT_FAILURE);
	}
	else if(p){
		memcpy(new, p, size);
		myfree(p, file, line);
	}
	return new;
}
