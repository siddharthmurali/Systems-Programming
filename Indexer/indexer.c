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
		perror("Invalid directory\n");
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
			FILE *f;
			f = fopen(dir->d_name, "r");
			
			char filePath[100];
			getcwd(filePath, 100);

			char* tmpSlash = "/";
			char* fullName = (char *) malloc(2+strlen(filePath)+strlen(dir->d_name));
			strcpy(fullName, filePath); 
			strcat(fullName, tmpSlash);
			strcat(fullName, dir->d_name);
		
			
			tokenate( f , fullName);
			fclose(f);
			free(fullName);
		} 

		if ( dir->d_type == 4) {
			char filePath[100];
			getcwd(filePath, 100);
			traverseDir(dir->d_name);
			chdir(filePath);
		}
	} 

	return;
}


void tokenate( FILE* file, char* filename){

	tokenNodePtr front = NULL;

	if (file == NULL){
		return;
	}

	char *token = (char *) malloc(sizeof(char) * (100));

	int c;
	int cCount = 0;
	while(1) {
		c = fgetc(file);

		if (isalnum(c)) {
			if( cCount == 25) {
				//token = (char *) realloc( token, (35) );
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
				token = (char *) malloc(sizeof(char) * (100));
			}
		}

	};

	free(token);

}


void  tokenateHelper(char* filename){
	
	if(filename == NULL){
		return;
	}

	FILE *f;

	f = fopen(filename, "r");

	if( f == NULL ){
		perror("Error opening file");
		exit(0);
		return;
	}

	tokenate(f, filename);

	fclose(f);

}

void freeFront() {

	tokenNodePtr front=NULL;
	
	do{
                fileNode frontFile = frontDir->nextFile;
		fileNode tmpFront = NULL;

                do {
			free(frontFile->filePath);
			tmpFront = frontFile;
                        frontFile = frontFile->nextFile;
			free(tmpFront);
                } while (frontFile != NULL);

		front=frontDir;
		frontDir=frontDir->nextNode;
		free(front);
	}
	while(frontDir !=NULL);

}


int main(int argc, char* argv[]){
	
	struct stat statbuf;
	stat(argv[2], &statbuf);


	char *inputFile = argv[2];
	char *outputFile = argv[1];

	tokenNodePtr front;
	frontDir=NULL;

	int dirCheck=0;


	char filePath[100];
	getcwd(filePath, 100);


	DIR *d;	
	struct dirent *dir;

	d = opendir(filePath);

	chdir(filePath);

	int fileBool = 0 ;

	while((dir=readdir(d)) != NULL){

		if(strcmp(dir->d_name,argv[1])==0) {

			printf("\n");
			printf("Inverted file exists.\n");
			fileBool = 1;
			break;	
		}

	}
	if (fileBool) {
		int answer=0;
		printf("Would you like to overwrite the file? If so enter 1, otherwise enter 0 to exit.\n"); 
		scanf("%d",&answer); 

		if(answer==0) 
			exit(0); 
	}

	printf("\n");
	printf("INDEXING...\n");	
	if(S_ISDIR(statbuf.st_mode)){
		traverseDir(argv[2]);
		dirCheck=1;
	}
	else{
		tokenateHelper(argv[2]);
	}

	if (dirCheck) 	
		indexPrintToFile(dirCheck, filePath, frontDir, argv[1]);
	else 
		indexPrintToFile(dirCheck, filePath, frontDir, argv[1]);
	

	printf("Finished indexing.\n");
	printf("\n");
	printf("Output is in %s/%s\n", filePath,argv[1]);
	//freeFront();
	

	return 0;
}

