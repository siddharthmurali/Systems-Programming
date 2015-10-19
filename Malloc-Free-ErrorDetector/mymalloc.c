#include <mymalloc.h>

//Need to add definitions, etc...



//Macro Definitions

#define mymalloc( x ) mymalloc(x, __FILE__, __LINE__)
#define myfree( x) myfree(x, __FILE__, __LINE__ )
#define mycalloc(x) mycalloc(x, __FILE__, __LINE__)
#define myrealloc(x) myrealloc(x, __FILE__, __LINE__)




void myfree(void *ptr, char *file, int line){
//Just to check twitter mod	
void *mycalloc(int numEle, unsigned int size, char *file, int line){

	
