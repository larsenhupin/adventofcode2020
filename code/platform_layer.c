#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 200

struct file {
	int size;
	char* buffer;
	int lines;
};

void charBufferReinitialisation(char *buffer, int size){
	for (int i = 0; i < size; i++) {
		buffer[i] = '\0';
	}
}

int * parseToIntBuffer(struct file fInfo) {
	int *entries = malloc(sizeof(int) * fInfo.lines+1);
	char arr[MAX_CHAR] = { '\0' };
	int nbOfChar = 0;
	int line = 0;
	int array_size = 0;

	for (int i = 0; i <= fInfo.size ; i++) {		
		if (fInfo.buffer[i] == '\n') {
			if (nbOfChar > array_size) {
				array_size = nbOfChar;
			}
			entries[line] = atoi(arr);
			line++;
			charBufferReinitialisation(arr, array_size);
			nbOfChar = 0;
		}
		else if(i == fInfo.size){
			entries[line] = atoi(arr);
		}
		else {
			arr[nbOfChar] = fInfo.buffer[i];
			nbOfChar++;
		}
	}

	return entries;
}

void printCharBuffer(char* buffer, int length){
	for(int i = 0; i < length; i++){
    	printf("%c", buffer[i]);
	}
}

int getNumberOfLines(char* buffer, int length) {
	int numberOfLines = 1;
	for (int i = 0; i < length; i++) {
		if(buffer[i] == '\n'){
			numberOfLines++;
		}
	}
	return numberOfLines;
}

struct file* getFileData(char* filename){
	struct file *fInfo;
	char* buffer = 0;
	int fileLength = 0;

	FILE* f = fopen(filename, "r");

	if(f){
	fseek(f, 0, SEEK_END);
	fileLength = ftell(f);
	fseek(f, 0, SEEK_SET);
	buffer = malloc(fileLength);
	if(buffer){
	  fread(buffer, 1, fileLength, f);
	}
	}
	fclose(f);

	fInfo = (struct file *)malloc(sizeof(struct file) + sizeof(int) * 2 + sizeof(char) * fileLength + 1);
	fInfo->lines = getNumberOfLines(buffer, fileLength);
	fInfo->size = fileLength;
	fInfo->buffer = buffer;

	return fInfo; 
}