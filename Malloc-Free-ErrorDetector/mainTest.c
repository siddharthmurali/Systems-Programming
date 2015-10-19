#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mymalloc.c" 


int main() {

	printf("Malloc() and Free() Debugger");

	char* test = (char *) malloc(sizeof(char)); 	
	return 0;
}
