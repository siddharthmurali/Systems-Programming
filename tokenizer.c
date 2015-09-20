/*
 * tokenizer.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 */

struct TokenizerT_ {
	char* tokenString; 
	int stringLocation;
	char** tokens; 
	char** tokenTypes; 
};

typedef struct TokenizerT_ TokenizerT;

/*
 * TKCreate creates a new TokenizerT object for a given token stream
 * (given as a string).
 * 
 * TKCreate should copy the arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */
TokenizerT *TKCreate( char * ts ) {
	TokenizerT* newWord = malloc ( sizeof (TokenizerT));
	newWord->tokenString=ts;
	newWord->stringLocation=1; 
	newWord->tokens = (char  **)malloc(sizeof(char *));
	*newWord->tokens = (char *)malloc(sizeof(char));	

	newWord->tokenTypes = (char  **)malloc(sizeof(char *));
	*newWord->tokenTypes = (char *)malloc(sizeof(char));	
  return newWord;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * You need to fill in this function as part of your implementation.
 */

void TKDestroy( TokenizerT * tk ) {

free(tk);
free(tk -> tokenString);
free(tk -> tokens);
free(tk -> tokenTypes);

//We need to free all pointers within a struct
}



//Sees what type of token the character is based off the previous character
int checkType(int previousIndVar, char tokenLetter){


	if(isalpha(tokenLetter)>0){ 

		return 1; 

	}
	else if  (isdigit(tokenLetter)>0) {


		return 2;
	}else {

	return 0;

	}


	return 0;
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * You need to fill in this function as part of your implementation.
 */

char *TKGetNextToken( TokenizerT * tk ) {

	int x=tk->stringLocation;
	int y=0;
	char *token=(char *)malloc(sizeof(char)); 

	//early implementation, plan to use this for the ctypes. Indicator is the type of token the word currently is
	int previousIndVar = 0;
	int indicatorVar = 0; 

	previousIndVar=checkType(0,tk->tokenString[x]);
	token[strlen(token)]=tk->tokenString[0]; 
	for (x;x<strlen(tk->tokenString);x++){

		//method checkType here to do ctype checks
		indicatorVar=checkType(previousIndVar, tk->tokenString[x]);	
		if (previousIndVar!=indicatorVar){
			tk->stringLocation=x;		
			break;
		}else { 

			token=(char *)realloc(token, sizeof(char)); 
			token[strlen(token)]=tk->tokenString[x];

		}
	}

		//delimmiter for the token word
		token[strlen(token)+1]='\0';

		
  return token;
}

/*
 * main will have a string argument (in argv[1]).
 * The string argument contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {

	int x = 2;
	int sizeWord=0;
	char *tokenStream=(char *)malloc ( sizeof (strlen(argv[1])));
	char **stringArray = (char **)malloc((argc) * sizeof(char *));
//	char stringArray[argc];
	int i;

	strcpy(tokenStream,argv[1]);
	

	for (x; x<argc; x++){
		//creates a character string for the full inputed tokenstream
		
		int stringSize = sizeof(argv[x]);
		
		stringArray[x] = (char *)malloc(stringSize+1);
		
		strcpy(stringArray[x], argv[x]);		
		printf("%s\n", stringArray[x]);
		//above populates stringArray
		
		sizeWord = (strlen((argv[x])));
		printf("New Argument: %s\n",argv[x]);	
		char* tmp=" ";
		strcat(tokenStream,tmp);
		tokenStream=(char *)realloc(tokenStream, sizeof(strlen(argv[x])));
		strcat(tokenStream,argv[x]);
		printf("\n");
	}

	//passes this string to TKCreate to create a new tokenizer struct
	
	
	TokenizerT* newToken=TKCreate(tokenStream); 
	char* tmp=TKGetNextToken(newToken); 
	
			
	printf("FUll STRING: %s and first token from TKGetNextToken:  %s\n", tokenStream,tmp);
	
	TKDestroy(newToken);	
  return 0;
}
