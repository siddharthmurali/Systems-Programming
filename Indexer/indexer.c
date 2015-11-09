#include <stdio.h>
#include <stdlib.h>
//#include "indexerTokenizer.c"
#include "indexerList.c"
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
		printf("dirName = %s\n",dirName);

	if(d == NULL){
		printf("dirName = %s\n",dirName);
		printf("Invalid directory\n");
		exit(0);
	}

	

	chdir(dirName);

	while((dir=readdir(d)) != NULL){
		
		if (strcmp (dir->d_name, ".") == 0){
         		continue;
		}
       		if (strcmp (dir->d_name, "..") == 0){    
           		continue;
		}

		if (dir->d_type == 8) {

			printf("%s file\n", dir->d_name);
		} 

		if ( dir->d_type == 4) {
			traverseDir(dir->d_name);

		}
	} 

	return;
}


tokenNodePtr tokenate( FILE* file, char* filename){

	tokenNodePtr front = NULL;
	printf("It has entered tokenate");

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

				front = indexInsert(front, token, filename);
			}

			if ( feof(file) ) {
				break;
			} 
			else if( cCount > 0 ) {
				token = (char *) malloc(sizeof(char) * (26));
			}
		}

	};


	return front;
}


tokenNodePtr tokenateHelper(char* filename){
	
	if(filename == NULL){
		return;
	}

	FILE *f;

	f = fopen(filename, "r");

	if( f == NULL ){
		printf("Error opening file");
		return;
	}

	tokenNodePtr tmpFront = tokenate( f, filename);

	fclose(f);

	return tmpFront;
}


int main(int argc, char* argv[]){
	
	struct stat statbuf;
	stat(argv[1], &statbuf);


	char *inputFile = argv[1];
	char *outputFile = argv[2];

	tokenNodePtr front;

	if(S_ISDIR(statbuf.st_mode)){
		printf("input is a directory\n");
		traverseDir(argv[1]);
	}
	else{
		printf("input isa file\n");
		front=tokenateHelper(argv[1]);
	}

	indexPrint(front);

	indexPrintToFile(front, argv[2]);
	return 0;
}

