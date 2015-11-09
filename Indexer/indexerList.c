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
		firstFile->freq = 1;
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
	tokenNodePtr previnsertSpot = front;
	tokenNodePtr insertSpot = front;
	tokenNodePtr tmpFront = front;

	
	token = strdup(token); 
	front->token=strdup(front->token);

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

		fileNode frontFile = insertSpot->nextFile;
		fileNode tmpfrontFile = frontFile;

		do { 
			tmpfrontFile=frontFile;
			if (indexCompare(frontFile->filePath, filePath)==0) {
				frontFile->freq++;
				return front;
			}
			frontFile = frontFile->nextFile;

		} while (frontFile != NULL); 

		
		fileNode newFile = (fileNode) malloc(sizeof(fileNode)); 
		newFile->filePath = filePath; 
		newFile->freq = 1;
		newFile->nextFile = NULL; 

		tmpfrontFile->nextFile = newFile;

		return front;
	}


	tokenNodePtr newToke=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 
	newToke->token = token; 

	fileNode newFile = (fileNode) malloc(sizeof(fileNode)); 
	newFile->filePath = filePath; 
	newFile->freq = 1;
	newFile->nextFile = NULL; 

	newToke->nextFile = newFile;
	
	if (insertSpot==front){
	//if insertion spot is the front of the list

		if(indexCompare(insertSpot->token, token)>0){
			// if insertSpot->token > token
			newToke->nextNode = insertSpot;
			return newToke;

		}else{ 
			// if insertSpot->token < token
			tokenNodePtr tmpPtr = insertSpot->nextNode;	
			newToke->nextNode = tmpPtr;
			insertSpot->nextNode = newToke;
			return front;
		}
	
	}

	if (insertSpot->nextNode == NULL) {
	// if the insertion spot is the last of the list 
		newToke->nextNode = NULL;;
		insertSpot->nextNode = newToke; 
		return front;

	}else {
	// if the insertion spot is inside the list somewhere  
		tokenNodePtr tmpPtr = insertSpot->nextNode;	
		newToke->nextNode = tmpPtr;
		insertSpot->nextNode = newToke;
		return front;
	} 

	return front;

} 

void indexPrint(tokenNodePtr front) {
	tokenNodePtr tmpFront = front;
	tokenNodePtr front2 = front;
	int count=0;
	printf("{'list' : [\n");

	do{

		printf("            {'%s' : [\n",front->token); 

		fileNode tmpFrontFile = front-> nextFile;
		do{ 
			printf("                    {'%s' : '%d'},\n", tmpFrontFile->filePath, tmpFrontFile->freq); 
			tmpFrontFile= tmpFrontFile->nextFile;

		} while (tmpFrontFile!=NULL);
	
		front = front->nextNode;
		printf("            ]},\n"); 
	}while(front!=NULL);
	printf("]}\n");
}

void indexPrintToFile(tokenNodePtr front, char* file) {

	FILE *f = fopen(file, "w"); 

	if (f==NULL) {
		printf("Error: Cannot Open File"); 
		exit(1);
	}


	tokenNodePtr tmpFront = front;
	tokenNodePtr front2 = front;
	int count=0;
	fprintf(f,"{'list' : [\n");

	do{

		fprintf(f,"            {'%s' : [\n",front->token); 

		fileNode tmpFrontFile = front-> nextFile;
		do{ 
			fprintf(f,"                    {'%s' : '%d'},\n", tmpFrontFile->filePath, tmpFrontFile->freq); 
			tmpFrontFile= tmpFrontFile->nextFile;

		} while (tmpFrontFile!=NULL);
	
		front = front->nextNode;
		fprintf(f,"            ]},\n"); 
	}while(front!=NULL);
	fprintf(f,"]}\n");
	
	fclose(f);

}

int indexCompare(char* newToken, char* token){

	return strcmp(strlwr(newToken), strlwr(token));
}

char *strlwr(char *p)
{
	char *tmp = strdup(p);

	int i=0;
	for(i; tmp[i]; i++){
  		tmp[i] = tolower(tmp[i]);
	}

	return tmp;
}
