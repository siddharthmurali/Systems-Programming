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

tokenNodePtr frontDir;
void tokenate(FILE *file, char *filename);

void traverseDir(char *dirName){
	DIR *d;	
	struct dirent *dir;

	d = opendir(dirName);

	if(d == NULL){
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
			char path[100];
			getcwd(path, 100);

			
			FILE *f;

			f = fopen(dir->d_name, "r");
		//	printf("%s file\n", dir->d_name);

			tokenate( f , dir->d_name);
			fclose(f);
		} 

		if ( dir->d_type == 4) {
			char path[100];
			getcwd(path, 100);
			traverseDir(dir->d_name);
			chdir(path);
		}
	} 

	return;
}


void tokenate( FILE* file, char* filename){

	tokenNodePtr front = NULL;

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
				
				frontDir = indexInsert(frontDir, token, filename);
			}

			if ( feof(file) ) {
				break;
			} 
			else if( cCount > 0 ) {
				token = (char *) malloc(sizeof(char) * (26));
			}
		}

	};

}


void  tokenateHelper(char* filename){
	
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

	tokenNodePtr front;
	frontDir=NULL;

	if(S_ISDIR(statbuf.st_mode)){
		traverseDir(argv[1]);
		indexPrint(frontDir);
	}
	else{
		tokenateHelper(argv[1]);
		indexPrint(frontDir);
	}


	
	indexPrintToFile(frontDir, argv[2]);
	return 0;
}

