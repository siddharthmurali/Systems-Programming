#include <stdlib.h>
#include <string.h>
#include "indexerList.h"


tokenNodePtr indexInsert(tokenNodePtr front, char* token, char* filePath){

	if (front==NULL) {
		// first tokennode and filenode
		tokenNodePtr firstToken=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 
		firstToken->token = token; 

		fileNode firstFile = (fileNode) malloc(sizeof(fileNode)); 
		firstFile->filePath = filePath; 
		firstFile->nextFile = NULL; 

		firstToken->nextFile = firstFile;
		front=firstToken;

		return front;
	}

	int compareRet=0;
	int prevCompareRet=0;
	int foundSpot=0;
	int newToken=1;
	tokenNodePtr insertSpot = front;

	//Sid if you have questions about this finding the spot of insertions, ask me. This shits too confusing

	//loop through the linked list to find spot to insert
	while (front->nextNode!=NULL) {
		compareRet= indexCompare(front->token, token);	

		if (compareRet==0 ){ 
		//if front->token == token
			insertSpot = front; 
			newToken=0;
			break;
		} 

		if (compareRet>0) {
		//if front->token >token 
			if ( prevCompareRet == 1) 
				break;
		}

		if (compareRet<0) {
		//if front->token < token
			prevCompareRet=1;
			insertSpot = front;
		}
	}

	if (newToken==0) {
	//if it is not a new token

		//add a file node

		return front;
	}
	
	if (insertSpot==front){
	//if insertion spot is the front of the list

		tokenNodePtr newToke=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 
		newToke->token = token; 
		newToke->nextNode = front;

		fileNode newFile = (fileNode) malloc(sizeof(fileNode)); 
		newFile->filePath = filePath; 
		newFile->nextFile = NULL; 

		newToke->nextFile = newFile;
	
		return newToke;	
	}

	if (insertSpot->nextNode == NULL) {
	// if the insertion spot is a new node at the end of the list
		tokenNodePtr newToke=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 
		newToke->token = token; 

		fileNode newFile = (fileNode) malloc(sizeof(fileNode)); 
		newFile->filePath = filePath; 
		newFile->nextFile = NULL; 

		newToke->nextFile = newFile;


	}else {
	// if the insertion spot is inside the list somewhere  
		


	} 


	

	return front;

}

int indexCompare(char* newToken, char* token){
	char* lnewToken = strlwr(newToken);
	char* ltoken = strlwr(token);

	return strcmp(lnewToken, ltoken);
}

char *strlwr(char *str)
{
	size_t i;
	size_t len = strlen(str);

	for(i=0; i<len; i++)
		str[i]=tolower((unsigned char)str[i]);

 	return str;
}
