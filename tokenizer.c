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

	TokenizerT* tokenator = malloc(sizeof(TokenizerT));
	tokenator -> tokenString=ts;
	tokenator -> stringLocation=1; 
	tokenator -> tokens = (char  **)malloc(sizeof(char *));
	*tokenator -> tokens = (char *)malloc(sizeof(char));	

	tokenator -> tokenTypes = (char  **)malloc(sizeof(char *));
	*tokenator -> tokenTypes = (char *)malloc(sizeof(char));

	printf("\n Reached TKCreate\n");
	
  return tokenator;
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
//free(tk -> tokens);
//free(tk -> tokenTypes);

printf("\n Reached TKDestroy\n");

//We need to free all pointers within a struct
}



//Sees what type of token the character is based off the previous character
int checkType(char* word){

int prevInd=0;
	int currInd=0;	
	int x=1;
	int stringLocation=0;

	char* token = (char *)malloc(sizeof(char));
	char* tokenType= "word";
	token[strlen(token)]=word[0]; 
/*
Indicator Key Values: 
1 - Alpha 
2 - Number 
3 - Punctuation 
4 - Hexadecimal Number 
5 - Octal Number 
6 - C Operator  
7 - Floating Point 
8 - Octal or Hexadecmial 
*/
	for(x;x<strlen(word);x++){
		int asciiVal=word[x];

		//for alphbetic characters
		if (isalpha(asciiVal)){
			currInd=1;
			if(prevInd==1) {
				tokenType="word";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x]; 
				prevInd=1;
			}else if (prevInd==0) {
				tokenType="word";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x]; 
				prevInd=1;
			} else {
				if(prevInd==4){
					if(((asciiVal>=61)&&(asciiVal<=66))||((asciiVal>=65)&&(asciiVal<=70))){
						tokenType="hexadecmial";
						token[strlen(token)]=word[x]; 
						token = (char *)realloc(token, sizeof(char));
						prevInd=4;
					}
				}

				if(prevInd==7) {
					if(word[x]=='e') {
						tokenType="Floating Point";
						token[strlen(token)]=word[x]; 
						token = (char *)realloc(token, sizeof(char));
					}
				} 

				if(prevInd==3) {
					token[strlen(token)+1]='\0';
					prevInd=0; 
					return token;
				}

				if(prevInd==2){
					token[strlen(token)+1]='\0';
					printf("%s '%s'\n",tokenType,token);
					prevInd=0;
					free(token);
					token=(char *)malloc(sizeof(char));
				}

				if (prevInd==8){

					if((asciiVal==88)||(asciiVal==120)){
						tokenType="hexadecmial";
						token[strlen(token)]=word[x]; 
						token = (char *)realloc(token, sizeof(char));
						prevInd=4;

					}else{




					}
				}
			}	

		} else if (isdigit(asciiVal)) {   // for number characters
			currInd=2; 

			if(prevInd==2){
				tokenType="Number";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x]; 
				prevInd=2;
			}else if (prevInd==0) {
				if(word[x]!='0'){
					tokenType="Number";
					token = (char *)realloc(token, sizeof(char));
					token[strlen(token)]=word[x]; 
					prevInd=2;
				}else{ 
					tokenType="Hexadecimal or Octal";
					token = (char *)realloc(token, sizeof(char));
					token[strlen(token)]=word[x]; 
					prevInd=8;
				}
			} else {
				if (prevInd==1) {
					tokenType="Word";
					token = (char *)realloc(token, sizeof(char));
					token[strlen(token)]=word[x]; 
					prevInd=1;
				} 
				
				if ((prevInd==8) || (prevInd==5)){

					if ((asciiVal>48)&&(asciiVal<55)){

						tokenType="Octal";
						token = (char *)realloc(token, sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=5;

					}

				}

				if (prevInd==5){

					if ((asciiVal>48)&&(asciiVal<55)){

						tokenType="Octal";
						token = (char *)realloc(token, sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=5;

					} else {

						token[strlen(token)+1]='\0';
						return token;

					}
				}
			}

		}else if (ispunct(word[x])){

			currInd=3; 

			if (prevInd!=2) {

			}
		}

		
		if( word[x] == "()"){
			
			tokenType = "function";
			token = (char *)realloc(token, sizeof(char));
			token[strlen(token)] = word[x];
		}

		if( word[x] == "[]"){

                        tokenType = "array element";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "->"){

                        tokenType = "structure pointer";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "&"){

                        tokenType = "address";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }	 	

		if( word[x] == "-"){

                        tokenType = "minus";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "!"){

                        tokenType = "negate";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "~"){

                        tokenType = "1's comp";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "++"){

                        tokenType = "inc";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "--"){

                        tokenType = "dec";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "sizeof()"){

                        tokenType = "cast";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == ">>"){

                        tokenType = "shift right";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "<"){

                        tokenType = "less than";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "=="){

                        tokenType = "equals";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "^"){

                        tokenType = "bitwise executive or";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "|"){

                        tokenType = "bitwise OR";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "&&"){

                        tokenType = "logical AND";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "||"){

                        tokenType = "logical AND";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "/"){

                        tokenType = "divide";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "<<"){

                        tokenType = "shift left";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == ">"){

                        tokenType = "greater than";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "!="){

                        tokenType = "not equals";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "%"){

                        tokenType = "modulus";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "<="){

                        tokenType = "less than or equal to";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == ">="){

                        tokenType = "greater than or equal to";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "["){

                        tokenType = "left bracket";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "]"){

                        tokenType = "right bracket";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == ","){

                        tokenType = "comma";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == """"){

                        tokenType = "double quotes";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

		if( word[x] == "'"){

                        tokenType = "single quote";
                        token = (char *)realloc(token, sizeof(char));
                        token[strlen(token)] = word[x];
                }

	}
	
	token[strlen(token)+1]='\0';
	printf("%s '%s'\n",tokenType,token);
	free(token);

	return token;
}


printf("\n Reached checkType\n");



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
	
	char *token=(char *)malloc(sizeof(char));		
	printf("\n Reached TKGetNextToken\n");
	
  return token;
}

/*
 * main will have a string argument (in argv[1]).
 * The string argument contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {
	
	int x = 0;
	char *tokenStream=(char *)malloc ( sizeof (strlen(argv[1])));

	for (x; x<argc; x++){
		//creates a character string for the full inputed tokenstream		
		checkType(argv[x]);
		TKCreate(argv[x]);
		printf("\n");
	}

	TokenizerT* tokenator = TKCreate(tokenStream);
	char* tokenized = TKGetNextToken(tokenator);

 	
	TKDestroy(tokenator);	
	
  return 0;
}
