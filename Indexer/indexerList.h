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
fileNode sortFreq(fileNode front);
void indexPrintToFile(int dirCheck, tokenNodePtr front, char* file); 
int indexCompare(char* newToken, char* token);
char* strlwr(char* str);

#endif
