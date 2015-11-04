#include <stdio.h>
#include <stdlib.h>
#include "indexerTokenizer.c"
#include "indexerList.c"

int main(int argc, char* argv[]){

	//Get initial input and depending on input type, go through directory or a single file

	tokenNodePtr front = NULL; //keep outside while loop 

	//while loop to keep asking for more input


	// indexInsert(front node, token word, filepath); 
	front = indexInsert(front, "b", "testFile2");
	front = indexInsert(front, "a", "testFile"); //use this to insert a new token into the list, indexInsert() will return the front of the list
	front = indexInsert(front, "a", "zestFileee");
	front = indexInsert(front, "a", "zestfffFileee");
	front = indexInsert(front, "a", "zefffstFileee");
	front = indexInsert(front, "a", "zrrestFileee");
	front = indexInsert(front, "a", "zaestFileee");
	front = indexInsert(front, "a", "zestFileee");


	indexPrint(front);
	
}

//Add helper functions sorting?





