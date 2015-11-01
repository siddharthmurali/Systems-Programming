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
		firstToken->nextNode = NULL;
		front=firstToken;

		return front;
	}

	int compareReturn=0;
	int prevCompareReturn=0;
	int foundSpot=0;
	int newToken=1;
	tokenNodePtr insertSpot = front;
	tokenNodePtr tmpFront = front;

	//Sid if you have questions about this finding the spot of insertions, ask me. This shits too confusing

	//loop through the linked list to find spot to insert
	do { 
		/* 
		Insertion Cases: 

		(4 6 9 10). Insert 5. Passes, returns insertSpot = 4;  

		(4 6 9 10). Insert 7. Passes, returns insertSpot = 6; 

		(4 6 9 10). Insert 2. Passes, returns insertSpot = 4; 

		(4 6 9 10). Inseert 11. Passes, returns insertSpot = 10; 

		*/

		compareReturn = indexCompare(front->token, token);	

		if (compareReturn==0 ){ 
		//if front->token == token
			insertSpot = front; 
			newToken=0;
			break;
		} 

		if (compareReturn>0) {
		//if front->token > token 
			if ( prevCompareReturn == 1) 
				break;
		}

		if (compareReturn<0) {
		//if front->token < token
			prevCompareReturn=1;
			insertSpot = front;
		}
	
		front=front->nextNode;

	} while (front!=NULL); 

	front=tmpFront;	

	if (newToken==0) {
	//if it is not a new token

		//add a file node

		return front;
	}
	
	if (insertSpot==front){
	//if insertion spot is the front of the list

		tokenNodePtr newToke=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 

		if(indexCompare(insertSpot->token, token)>0){
			// if insertSpot->token > token
			newToke->token = token; 
			newToke->nextNode = insertSpot;

			fileNode newFile = (fileNode) malloc(sizeof(fileNode)); 
			newFile->filePath = filePath; 
			newFile->nextFile = NULL; 

			newToke->nextFile = newFile;

		}else{ 
			// if insertSpot->token < token

			tokenNodePtr tmpPtr = insertSpot->nextNode;	

			newToke->token = token; 
			newToke->nextNode = tmpPtr;

			insertSpot->nextNode = newToke;

			fileNode newFile = (fileNode) malloc(sizeof(fileNode)); 
			newFile->filePath = filePath; 
			newFile->nextFile = NULL; 

			newToke->nextFile = newFile;
		}
	
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
