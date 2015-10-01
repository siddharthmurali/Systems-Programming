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
<<<<<<< HEAD
	TokenizerT* newWord = malloc ( sizeof (TokenizerT));
	newWord->tokenString=ts;
	newWord->stringLocation=1; 
	newWord->tokens = (char  **)malloc(sizeof(char *));
	newWord->tokens[0] = (char *)malloc(sizeof(char));	

	newWord->tokenTypes = (char  **)malloc(sizeof(char *));
	*newWord->tokenTypes = (char *)malloc(sizeof(char));	
  return newWord;
=======

	TokenizerT* tokenator = malloc(sizeof(TokenizerT));
	tokenator -> tokenString=ts;
	tokenator -> stringLocation=1; 
	tokenator -> tokens = (char  **)malloc(sizeof(char *));
	*tokenator -> tokens = (char *)malloc(sizeof(char));	

	tokenator -> tokenTypes = (char  **)malloc(sizeof(char *));
	*tokenator -> tokenTypes = (char *)malloc(sizeof(char));

	printf("\n Reached TKCreate\n");
	
  return tokenator;
>>>>>>> 005f4726149c3f0da30f8238eae005014a13ed1d
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
<<<<<<< HEAD
char* checkType( char* word){

	int prevInd=0;
	int currInd=0;	
	int x=0;
=======
int checkType(char* word){

int prevInd=0;
	int currInd=0;	
	int x=1;
>>>>>>> 005f4726149c3f0da30f8238eae005014a13ed1d
	int stringLocation=0;

	char* token = (char *)malloc(sizeof(char));
	char* tokenType= "word";
<<<<<<< HEAD
	//token[strlen(token)]=word[0]; 
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
			if (prevInd==3){
				prevInd=0;
			}
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
						continue;
					}
				}

				if(prevInd==7) {
					if(word[x]=='e') {
						tokenType="Floating Point";
						token[strlen(token)]=word[x]; 
						token = (char *)realloc(token, sizeof(char));
						continue;
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
					token[strlen(token)]=word[x];
					continue;
				}

				if(prevInd==7){

					if(asciiVal==101){
						tokenType="Float";
						token = (char *)realloc(token, sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=7;
						continue;
					}else {
						token[strlen(token)+1]='\0';
						printf("%s '%s'\n",tokenType,token);
						prevInd=0;
						free(token);
						token=(char *)malloc(sizeof(char));
						token[strlen(token)]=word[x];
						prevInd=1;
						continue;
					}
				}



				if(prevInd==4){
						if(((asciiVal>=65)&&(asciiVal<=70))||((asciiVal>=97)&&(asciiVal<=102))){
							tokenType="Hexadecmial";
							token[strlen(token)]=word[x]; 
							token = (char *)realloc(token, sizeof(char));
							prevInd=4;
							continue;
						}else{
							token[strlen(token)+1]='\0';
							printf("%s '%s'\n",tokenType,token);
							prevInd=0;
							free(token);
							token=(char *)malloc(sizeof(char));
							token[strlen(token)]=word[x];
							prevInd=1;
							continue;
						}
				}


				if(prevInd==5){
					token[strlen(token)+1]='\0';
					printf("%s '%s'\n",tokenType,token);
					prevInd=0;
					free(token);
					token=(char *)malloc(sizeof(char));
					token[strlen(token)]=word[x];
					prevInd=1;
					continue;
				}


	
				if (prevInd==8){

					if((asciiVal==88)||(asciiVal==120)){
						tokenType="hexadecmial";
						token[strlen(token)]=word[x]; 
						token = (char *)realloc(token, sizeof(char));
						prevInd=4;
						continue;

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
				if(asciiVal!=48){
					tokenType="Number";
					token = (char *)realloc(token, sizeof(char));
					token[strlen(token)]=word[x]; 
					prevInd=2;
					continue;
				}else{ 
					tokenType="Hexadecimal or Octal";
					token = (char *)realloc(token, sizeof(char));
					token[strlen(token)]=word[x]; 
					prevInd=8;
					continue;
					printf("in else\n");
				}
			} else {
				if (prevInd==1) {
					if (asciiVal!=48){
						tokenType="Word";
						token = (char *)realloc(token, sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=1;
					}else{

						token[strlen(token)+1]='\0';

						printf("%s '%s'\n",tokenType,token);
						prevInd=2;
						free(token);
						tokenType="Hexadecimal or Octal";
						token=(char *)malloc(sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=8;
						continue;

					}
				} 
				
				if ((prevInd==8) || (prevInd==5)){
					if ((asciiVal>=48)&&(asciiVal<=55)){

						tokenType="Octal";
						token = (char *)realloc(token, sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=5;
						continue;

					}

				}

				if(prevInd==7){
						tokenType="Float";
						token = (char *)realloc(token, sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=7;
						continue;
				}

				if (prevInd==4){


					if((asciiVal>48)&&(asciiVal<57)){
						tokenType="Hexadecimal";
						token = (char *)realloc(token, sizeof(char));
						token[strlen(token)]=word[x]; 
						prevInd=4;
						continue;
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

					printf("%s '%s'\n",tokenType,token);
					prevInd=2;
					free(token);
					token=(char *)malloc(sizeof(char));

					}
				}
			}

		}else if (ispunct(word[x])){


			if (asciiVal==46) {

				if (prevInd==2){
				
					tokenType="Float";
					token = (char *)realloc(token, sizeof(char));
					token[strlen(token)]=word[x]; 
					prevInd=7;
				}
				continue;
			}

			if(prevInd!=3434){
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);

		}
		
		if( asciiVal == 40){
			free(token);
			tokenType="Left Paranthesis";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		if( asciiVal == 41){

			free(token);
			tokenType="Right Paranthesis";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}


		if( asciiVal == 91){
=======
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

>>>>>>> 005f4726149c3f0da30f8238eae005014a13ed1d

			free(token);
			tokenType="Left Bracket";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		if( asciiVal == 93){

			free(token);
			tokenType="Right Bracket";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}


		if( asciiVal == 38){

			free(token);
			tokenType="And";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x];
			int asciiVal2=word[x+1]; 

			if (asciiVal2==38){
				tokenType="Double And";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}

 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}


		if( asciiVal == 45){

			free(token);
			tokenType="Minus";
			token=(char *)malloc(sizeof(char));

			token[strlen(token)]=word[x]; 
			int asciiVal2=word[x+1]; 

			if (asciiVal2==45){
				tokenType="Double Minus";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}


		if( asciiVal == 33){
			free(token);
			tokenType="Exlamation";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			int asciiVal2=word[x+1]; 

			if (asciiVal2==61){
				free(token);
				token=(char *)malloc(sizeof(char));
				token[strlen(token)]=word[x]; 
				tokenType="Not Equal";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}


		if( asciiVal == 126){

			free(token);
			tokenType="Tilda";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		if( asciiVal == 43){
			free(token);
			tokenType="Plus";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			int asciiVal2=word[x+1]; 

			if (asciiVal2==43){
				tokenType="Double Plus";
				token = (char *)realloc(token, sizeof(char));
				x=x+1;
				token[strlen(token)]=word[x+1]; 
			}
			if (asciiVal2==61){
				tokenType="Plus Equals";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		if( asciiVal == 60){
			free(token);
			tokenType="Greater Than";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			int asciiVal2=word[x+1]; 

			if (asciiVal2==60){
				tokenType="Double greater than";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			if (asciiVal2==61){
				tokenType="Greater than or equal too";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

<<<<<<< HEAD
		if( asciiVal == 62){

			free(token);
			tokenType="Less than";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			int asciiVal2=word[x+1]; 

			if (asciiVal2==62){
				tokenType="Double Less than";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			if (asciiVal2==61){
				tokenType="Less than or equal too";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		if( asciiVal == 61){

			free(token);
			tokenType="Equals";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			int asciiVal2=word[x+1]; 

			if (asciiVal2==61){
				tokenType="Double Equals";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		if( asciiVal == 124){

			free(token);
			tokenType="Pipeline";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			int asciiVal2=word[x+1]; 

			if (asciiVal2==124){
				tokenType="Double Pipeline";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		if( asciiVal == 58){

			free(token);
			tokenType="Colon";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 59){

			free(token);
			tokenType="Semi-colon";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 63){

			free(token);
			tokenType="Question Mark";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 123){

			free(token);
			tokenType="Right Curly Brace";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 125){

			free(token);
			tokenType="Left";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 39){

			free(token);
			tokenType="Aprostophe";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 44){

			free(token);
			tokenType="Comma";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 37){

			free(token);
			tokenType="Modulus";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 94){

			free(token);
			tokenType="Bitwise executive or";
			token=(char *)malloc(sizeof(char));
			token[strlen(token)]=word[x]; 
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}
		if( asciiVal == 45){

			int asciiVal2=word[x+1]; 

			if (asciiVal2==62){
				free(token);
				token=(char *)malloc(sizeof(char));
				token[strlen(token)]=word[x]; 
				tokenType="Pointer";
				token = (char *)realloc(token, sizeof(char));
				token[strlen(token)]=word[x+1]; 
			x=x+1;
			}
			token[strlen(token)+1]='\0';
			printf("%s '%s'\n",tokenType,token);
			free(token);
			token=(char *)malloc(sizeof(char));
			prevInd=3;
		}

		}	
	}

					if (prevInd!=3){	
					token[strlen(token)+1]='\0';
					printf("%s '%s'\n",tokenType,token);
					free(token);
				}
	return token;
=======
>>>>>>> 005f4726149c3f0da30f8238eae005014a13ed1d
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
<<<<<<< HEAD


/*
	int x=tk->stringLocation;
	int y=0;
	char *token=(char *)malloc(sizeof(char)); 

	//early implementation, plan to use this for the ctypes. Indicator is the type of token the word currently is
	int previousIndVar = 0;
	int indicatorVar = 0; 

	token[strlen(token)]=tk->tokenString[0]; 
	for (x;x<strlen(tk->tokenString);x++){

		//method checkType here to do ctype checks
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
*/



		
  return checkType("0x23hello0x123asdf");
=======
	
	char *token=(char *)malloc(sizeof(char));		
	printf("\n Reached TKGetNextToken\n");
	
  return token;
>>>>>>> 005f4726149c3f0da30f8238eae005014a13ed1d
}

/*
 * main will have a string argument (in argv[1]).
 * The string argument contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */

int main(int argc, char **argv) {
<<<<<<< HEAD

	int x = 1;
	int sizeWord=0;
	for (x; x<argc; x++){
		//creates a character string for the full inputed tokenstream
		checkType(argv[x]);	
	}

=======
	
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
	
>>>>>>> 005f4726149c3f0da30f8238eae005014a13ed1d
  return 0;
}
