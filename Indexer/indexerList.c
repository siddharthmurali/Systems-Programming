#include <stdlib.h>
#include <string.h>
#include "indexerList.h"


tokenNodePtr indexInsert(tokenNodePtr front, char* token, char* filePath){

	if (front==NULL) {
		tokenNodePtr firstToken=(tokenNodePtr) malloc(sizeof(tokenNodePtr)); 
		firstToken->token = token; 

		fileNode firstFile = (fileNode) malloc(sizeof(fileNode)); 
		firstFile->filePath = filePath; 
		firstFile->nextFile = NULL; 

		firstToken->nextFile = firstFile;
		front=firstToken;

		return front;
	}

	while (front->nextNode!=NULL) {




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
