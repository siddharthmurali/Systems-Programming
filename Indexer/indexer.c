#include <stdio.h>
#include <stdlib.h>
//#include "indexerTokenizer.c"
#include "indexerList.c"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

static void cat(FILE *fp)
{
    char   buffer[4096];
    size_t nbytes;
    while ((nbytes = fread(buffer, sizeof(char), sizeof(buffer), fp)) != 0)
         fwrite(buffer, sizeof(char), nbytes, stdout);
}


int main(int argc, char* argv[]){
	
	int isDirBool = 0;
	struct stat statbuf;
	struct dirent *dir;
	int c;
	DIR *d;
	FILE *fp;
	char str[200];
	fp = fopen(argv[1], "r");
		if(fp == NULL){
			printf("is null\n");
			fclose(fp);
		} 

		stat(argv[1], &statbuf);
 
		if(S_ISDIR(statbuf.st_mode)){
			printf("directory\n");
			isDirBool = 1;
			fclose(fp);
		}
		else{
			printf("file\n");
			while(1){
				c = fgetc(fp);
				if(feof(fp)){
					break;
				}
				printf("%c", c);
			}
			fclose(fp);
		}

		FILE *fileIter;

		if(isDirBool == 1){
			
			d = opendir(argv[1]);
			while ((dir = readdir(d))){

     				if (!strcmp (dir->d_name, ".")){
           				continue;
				}
       				if (!strcmp (dir->d_name, "..")){    
           				continue;
				}
				
				printf("%s\n", dir->d_name);
				fileIter = fopen(dir->d_name, "rw");
     				if(fileIter == NULL){
					printf("file is Null\n");
					fprintf(stderr, "Error : Failed to open file - %s\n", strerror(errno));

        				return 1;
				}
				else{
					while(1){
						c = fgetc(fileIter);
						if(feof(fileIter)){
							break;
						}
						printf("%c", c);
					}
									
  					fclose(fileIter);
  				}
			 }
				
   			 closedir(d);
		}

		}


/*				

	//Get initial input and depending on input type, go through directory or a single file

	tokenNodePtr front = NULL; //keep outside while loop 

	//while loop to keep asking for more input


	// indexInsert(front node, token word, filepath); 
	front = indexInsert(front, "a", "testFile"); //use this to insert a new token into the list, indexInsert() will return the front of the list
	front = indexInsert(front, "b", "testFile2");
	front = indexInsert(front, "b", "testFile3");
	front = indexInsert(front, "b", "testFile2");
	front = indexInsert(front, "b", "testFileasdf2");
	front = indexInsert(front, "b", "testFileasdf2");
	front = indexInsert(front, "sid", "testFileasdf2");
	front = indexInsert(front, "sunny", "testFileasdf2");
	front = indexInsert(front, "sid", "testFileasdf2");
	front = indexInsert(front, "dog", "testFileasdf2");
	front = indexInsert(front, "apples`", "testFileasdf2");
	front = indexInsert(front, "c", "tessdfasdfile2");
	front = indexInsert(front, "a", "zestFileee");
	front = indexInsert(front, "a", "zestfffFileee");
	front = indexInsert(front, "a", "zefffstFileee");
	front = indexInsert(front, "a", "zrrestFileee");
	front = indexInsert(front, "a", "zaestFileee");
	front = indexInsert(front, "a", "zestFileee");
	front = indexInsert(front, "j", "zestFileee");


	indexPrint(front);
	
}

//Add helper functions sorting?

*/



