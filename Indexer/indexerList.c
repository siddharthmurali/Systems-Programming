#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "indexerList.h"


tokenNodePtr indexInsert(tokenNodePtr front, char* token, char* filePath){

	if (front==NULL) {
		// first tokennode and filenode

		tokenNodePtr firstToken=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 
		firstToken->token = token; 

		fileNode firstFile = (fileNode) malloc(sizeof(fileNode)); 
		firstFile->filePath = strdup(filePath); 
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

		//add sort insertSpot->nextFile = sortFreq(insertSpot->nextFile);


		return front;
	}


	tokenNodePtr newToke=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 
	newToke->token = token; 

	fileNode newFile = (fileNode) malloc(sizeof(fileNode)); 
	newFile->filePath = strdup(filePath); 
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

fileNode sortFreq(fileNode front) {


	

}
fileNode sortFreq(fileNode front) {

        fileNode tmp=front;
        fileNode ptr=tmp->nextFile;
        fileNode lag=front;

        if(ptr->freq > tmp->freq){
                tmp->nextFile = ptr->nextFile;
                ptr->nextFile = tmp;
                front=ptr;
                ptr=tmp;
                tmp=ptr;
        }


        if(ptr->freq == tmp->freq){
                int ic = indexCompare(ptr->filePath, tmp->filePath);
                if(ic < 0){
                        tmp->nextFile = ptr->nextFile;
                        ptr->nextFile = tmp;
                        front=ptr;
                        ptr=tmp;
                        tmp=ptr;
                }
        }
	
	 while(1){
                if(ptr->freq > tmp->freq){
                        while(lag->nextFile !=tmp){
                                lag = lag->nextFile;
                        }
                        lag->nextFile = ptr;
                        if(ptr->nextFile != NULL){
                                tmp->nextFile = ptr->nextFile;
                        }
                        else{
                                tmp->nextFile = NULL;
                        }
                        ptr->nextFile = tmp;
                }
                if(ptr->freq == tmp->freq){
                        int icVal = indexCompare(ptr->filePath, tmp->filePath);
                        if(icVal < 0){

                                while(lag->nextFile !=tmp){
                                        lag = lag->nextFile;
                                }
                                lag->nextFile = ptr;
                                if(ptr->nextFile != NULL){
                                        tmp->nextFile = ptr->nextFile;
                                }
                                else{
                                        tmp->nextFile = NULL;
                                }
                        }
                }
                else{
                        continue;
                }

                ptr->nextFile = tmp;
                ptr = ptr->nextFile;
                tmp= tmp->nextFile;

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


void indexPrintToFile(int dirCheck, tokenNodePtr front, char* file) {

	if (dirCheck) 
		chdir("..");

	if(front==NULL) {
		printf("There are no tokens...\n"); 
	}

	FILE *f = fopen(file, "w"); 

	if (f==NULL) {
		perror("Error");
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
