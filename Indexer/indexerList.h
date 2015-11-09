#ifndef SORTED_LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>

typedef struct fileNode* fileNode;
struct fileNode{
	char* filePath; 
	int freq;
	fileNode nextFile;
};

typedef struct tokenNode* tokenNodePtr;
struct tokenNode{
	char* token; 
	fileNode nextFile; 
	tokenNodePtr nextNode;
};



tokenNodePtr indexInsert(tokenNodePtr front, char* token, char* filePath);
void indexPrint(tokenNodePtr front); 
int indexCompare(char* newToken, char* token);
char* strlwr(char* str);

#endif
