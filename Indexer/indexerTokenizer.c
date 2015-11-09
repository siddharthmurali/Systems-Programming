#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include "indexerList.c"
//#include "indexerList.h"
//#include "indexer.c"
#define BUFFER_LEN 25
#define REALLOC_OFFSET 10

void tokenate(FILE* file, char* filename){
	printf("It has entered tokenate");

	if (file == NULL){
		return;
	}

	char *token = (char *) malloc(sizeof(char) * (25 + 1));

	int c;
	int cCount = 0;
	do {
		c = fgetc(file);

		if (isalnum(c)) {
			if( cCount == 25) {
				token = (char *) realloc( token, (35) );
			}

			token[cCount] = tolower( c ); //Make it lower case
			cCount++;
		} else {
			if ( cCount > 0 ) {
				token[cCount] = '\0';
				cCount = 0;

				//indexWord( word, filename );
				printf("%s\n", token);
			}

			if ( feof(file) ) {
				break;
			} else if( cCount > 0 ) {
				token = (char *) malloc(sizeof(char) * (26));
			}
		}

	} while(1);


}


int main(int argc, char* argv[]){
char* filename = argv[1];
if (filename == NULL )  return -1;

	FILE *fpData;

	// open file given from filename given
	fpData = fopen(filename, "r");

	// check if files exist, if not error message and abort
	if( fpData == NULL ){
		//fprintf(stderr, "%sError Opening Files: %s%s%s\n", KRED, KNRM, filename, KRED);
		printf("Error opening file");
		return -1;
	}

	tokenate(fpData, filename);

	fclose(fpData);


return 0;

}
