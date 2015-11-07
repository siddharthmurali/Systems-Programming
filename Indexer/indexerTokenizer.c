#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct token* tokenPtr;

struct token{
	char word[50];
	char fileName[50];
	int freq;
	tokenPtr next;
};


struct tokenStream{
	tokenPtr head;
	tokenPtr token;
	tokenPtr next;
};
typedef struct tokenStream* tokenStreamPtr;

tokenPtr tokenate(tokenPtr head, FILE f){
	
	FILE *fp;
	fp = fopen(f, "r");
	char line[300];
	char c;
	int linePlaceHolder = 0;
	int lineCountCurr = 0;
	char tmp[50];
	tokenPtr newToken;
	tokenPtr tokenIter;
	while(fgets(line, sizeof(line), fp) != NULL){
		c = line[lineCountCurr];			 
		while(1){
			if(isalnum(c)){
				c = line[lineCountCurr++];
			}
			else{
				newToken =(tokenPtr) malloc(sizeof( struct token));			
				linePlaceHolder;
				while(linePlaceHolder != lineCountCurr){
					tmp[linePlaceHolder] = line[linePlaceHolder];
					linePlaceHolder++;
				}
				newToken->word = tmp;
				if(head == NULL){
					head = newToken;
				}
				else{
					tokenIter =(tokenPtr)malloc(sizeof(struct token));
					while(tokenIter->next != NULL){
						tokenIter = tokenIter->next;
					}
					tokenIter->next = newToken;
				} 		
			}
							 
			if(lineCountCurr > 299){
				break;
			} 
		}

	}
}
