#include<stdio.h>
#include <stdlib.h>

struct report {
	int count;
	int entries[];
};

void initEntries(struct report *r){
	for (int i = 0; i < r->count; i++){
		 r->entries[i] = 0;
	}
}

void printEntries(struct report *r){
	for (int i = 0; i < r->count; i++){
		printf("%i %d\n", i, r->entries[i] );
	}
}

int getFilelen(FILE *f){ // getFileInfo
	char c;
	int count = 0;
	if(f){
		while((c=fgetc(f))!=EOF){
			if (c == '\n'){
				count++;
			}
		}
		count++;
	}	
	return count;
}

void getDataFromFile(char* filename){
	int c;
	FILE* f = fopen(filename, "r");
	
	struct report *r;
	int filelen = getFilelen(f);

	int SizeOfReport = sizeof(struct report);


	r = (struct report *)malloc(sizeof(struct report) + sizeof(int) + sizeof(int) * filelen);

	int SizeOfR = sizeof(r);
	r->count = 0;
	if (r == NULL){
		printf("report is null");
	}

	r->count = filelen;

	// get text in memory

	printEntries(r);

	// use atoi with fgetc
	
	// --------------------------------------
	for (int i = 0; i < filelen; i++){
		printf("%i %d\n", i, r->entries[i] );
	}

	fclose(f);
}

int program_run(){

	struct report *r;
	getDataFromFile("../data/input1.txt");

	return 0;
}

int main(int argc, char* argv){

	program_run();
	return 0;
}