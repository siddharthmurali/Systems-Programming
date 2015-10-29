#include <stdio.h>
#include <stdlib.h>
#include "indexerTokenizer.c"
#include "indexerList.c"

int main(int argc, char* argv[]){

	//Get initial input and depending on input type, go through directory or a single file

	tokenNodePtr front = NULL; //keep outside while loop 

	//while loop to keep asking for more input

	front = indexInsert(front, "testToken", "testFile"); //use this to insert a new token into the list
	
}

//Add helper functions sorting?





