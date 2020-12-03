#include<stdio.h>

typedef struct report report;

struct report {
	int nbOfEntries;
	char* str;
	char* err;
	int entries[];
};

int getFilelen(FILE *f){
	int c;
	int count = 0;
	if(f){
		while((c=fgetc(f))!=EOF){
			if (c == '\n'){
				count++;
			}
		}
		// Last entry doesn't have a newline
		count++;
	}	
	return count;
}

report* getDataFromFile(char* filename){
	int c;
	FILE* f = fopen(filename, "r");
	
	int filelen = getFilelen(f);

	// Create the struct
	//report *r = malloc(sizeof(report) +  filelen * sizeof(int));
	//report* r = malloc(sizeof(report) * (sizeof(int) * filelen));


	report* r = malloc(sizeof(report) + filelen * sizeof(int));

	// ------------------------------
	if(f){
		while((c=fgetc(f))!=EOF){
			r->str+=c;
		}
	}
	// ------------------------------
	r->nbOfEntries = filelen;

	// alloc -------------------------------------------

	for (int i = 0; i < r->nbOfEntries - 1; i++){
		fscanf(f, "%d,", &r->entries[i] );
	}


	printf("%s", "icant");

	fclose(f);

	return r;
}

int main(int argc, char* argv){

	//report* r;
	report* r = getDataFromFile("../data/input1.txt");
	printf("%i\n", 2);
	return 0;
}