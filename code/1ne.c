#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 200

struct report {
	int* entries;
	int size;
};

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

void parseToIntBuffer(int * entries, struct file fInfo) {
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
}

struct report* createReport(struct file *fInfo){
	struct report *r = malloc(sizeof(int) * fInfo->lines + sizeof(int) * 1);
	int *entries = malloc(sizeof(int) * fInfo->lines+1);

	parseToIntBuffer(entries, *fInfo);
 
	r->size = fInfo->lines;
	r->entries = entries;
	return r;
}

void printBuffer(char* buffer, int length){
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

int findSumOf2(struct report *r){
  int magic_input = 2020;
  int sum = 0;
  int result = 0;

  for (int i = 0; i < r->size - 1; i++) {
	  for (int j = i + 1; j < r->size; j++) {
		  sum = r->entries[i] + r->entries[j];

		  if (sum == magic_input) {
			  int result = r->entries[i] * r->entries[j];
			  return result;
		  }
	  }
  }
  return result;
}

int findSumOf3(struct report *r) {
	int magic_input = 2020;
	int sum = 0;
	int result = 0;

	for (int i = 0; i < r->size; i++) {
		for (int j = 0; j < r->size; j++) {
			if(j == i)
				continue;
			for (int k = 0; k < r->size; k++) {
				if(k == i || k == j){
					continue;
				}
				else{
				sum = r->entries[i] + r->entries[j] + r->entries[k];

					if (sum == magic_input) {
						int result = r->entries[i] * r->entries[j] * r->entries[k];
						return result;
					}
				}
			}
		}
	}
	return result;
}


int program(){
	struct file *fInfo = getFileData("../data/input1.txt");
	struct report *r = createReport(fInfo);

	int resultSum2 = findSumOf2(r);
	int resultSum3 = findSumOf3(r);
	printf("Sum2 %d\nSum3 %d\n", resultSum2, resultSum3);

	return 0;
}

int main(int argc, char* argv){
	program();
	return 0;
}
