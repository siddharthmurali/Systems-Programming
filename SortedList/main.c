#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.c"
//SidSunnyLabs



int compFloats(void * p1, void * p2 ){

        float   * x1 = (float *)p1;
        float   * x2 = (float *)p2;

        if ( *x1 < *x2 )
                return -1;
        else if ( *x1 > *x2 )
                return 1;
        else
                return 0;
}

void destoryFunc(void *p){
	free(p);
}

int (*compFloats)(void *,void *);
int (*destroyFunc)(void *);

int main (int argc, char ** argv){

	printf("Testing Int Comparing \n");

	SLCreate(compFloats,destroyFunc);
	

	return 0;
}
