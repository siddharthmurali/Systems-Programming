#include <stdio.h>
#include <stdlib.h>
//#include "indexerTokenizer.c"
//#include "indexerList.c"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

void traverseDir(char *dirName){
	
	DIR *d;	
	struct dirent *dir;

	d = opendir(dirName);
	if(d == NULL){
		printf("Invalid directory\n");
	}
	
	dir=readdir(d);
	if(dir ==NULL){
		return;
	}
	chdir(dirName);

	while(dir){
		if (strcmp (dir->d_name, ".") == 0){
         		continue;
		}
       		if (!strcmp (dir->d_name, "..") == 0){    
           		continue;
		}
	}
}


void tokenate(FILE* file, char* filename){
	printf("It has entered tokenate\n");

	if (file == NULL){
		return;
	}

	char *token = (char *) malloc(sizeof(char) * (26));

	int c;
	int cCount = 0;
	while(1) {
	
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
			} 
			else if( cCount > 0 ) {
				token = (char *) malloc(sizeof(char) * (26));
			}
		}

	} 


}


void tokenateHelper(char* filename){
	
	if(filename == NULL){
		return;
	}

	FILE *f;

	f = fopen(filename, "r");

	if( f == NULL ){
		printf("Error opening file");
		return;
	}

	tokenate(f, filename);

	fclose(f);
}


int main(int argc, char* argv[]){
	
	struct stat statbuf;
	stat(argv[1], &statbuf);
	

	char *inputFile = argv[1];
	char *outputFile = argv[2];

	if(S_ISDIR(statbuf.st_mode)){
		printf("input is a directory\n");
		traverseDir(argv[1]);
	}
	else{
		printf("input isa file\n");
		tokenateHelper(argv[1]);
	}

	return 0;
}

