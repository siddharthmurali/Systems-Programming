#include <stdio.h>
#include <stdlib.h>
//#include "indexerTokenizer.c"
#include "indexerList.c"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	
	int isDirBool = 0;
	struct stat statbuf;

	FILE *fp = fopen(argv[1], "r");
		if(fp == NULL){
			printf("is null\n");
		} 

		stat(argv[1], &statbuf);
 
		if(S_ISDIR(statbuf.st_mode)){
			printf("directory\n");
			isDirBool = 1;
		}
		else{
			printf("file\n");
		}

		if(isDirBool == 1){
			

		}
		
}


/*				

	//Get initial input and depending on input type, go through directory or a single file

	tokenNodePtr front = NULL; //keep outside while loop 

	//while loop to keep asking for more input


	// indexInsert(front node, token word, filepath); 
	front = indexInsert(front, "a", "testFile"); //use this to insert a new token into the list, indexInsert() will return the front of the list
	front = indexInsert(front, "b", "testFile2");
	front = indexInsert(front, "b", "testFile3");
	front = indexInsert(front, "b", "testFile2");
	front = indexInsert(front, "b", "testFileasdf2");
	front = indexInsert(front, "b", "testFileasdf2");
	front = indexInsert(front, "sid", "testFileasdf2");
	front = indexInsert(front, "sunny", "testFileasdf2");
	front = indexInsert(front, "sid", "testFileasdf2");
	front = indexInsert(front, "dog", "testFileasdf2");
	front = indexInsert(front, "apples`", "testFileasdf2");
	front = indexInsert(front, "c", "tessdfasdfile2");
	front = indexInsert(front, "a", "zestFileee");
	front = indexInsert(front, "a", "zestfffFileee");
	front = indexInsert(front, "a", "zefffstFileee");
	front = indexInsert(front, "a", "zrrestFileee");
	front = indexInsert(front, "a", "zaestFileee");
	front = indexInsert(front, "a", "zestFileee");
	front = indexInsert(front, "j", "zestFileee");


	indexPrint(front);
	
}

//Add helper functions sorting?

*/



