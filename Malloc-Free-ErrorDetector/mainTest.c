#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.c" 

#define malloc( x ) mymalloc(x, __FILE__, __LINE__)
#define free( x) myfree(x, __FILE__, __LINE__ )
#define calloc(x) mycalloc(x, __FILE__, __LINE__)
#define realloc(x) myrealloc(x, __FILE__, __LINE__)


int main() {

	printf("Malloc() and Free() Debugger");

	char* test = (char *) malloc(sizeof(char)); 	
	test = "d";
	printf("d = %s\n",test);
	return 0;
}
