#include <stdio.h>
#include <stdlib.h>

struct report {
	int count;
	int entries[];
};

struct file {
  int fileLength;
  char* buffer;
};

struct report* getReport(struct file *fInfo){
  struct report *r;
  int chiffre;

  int *entries = malloc(sizeof(int) * fInfo->fileLength);
  
  char *arr;
  int array_size = 0;
  int j = 0;
  int numberOfChiffre = 0;

  printf("%i bytes\n", fInfo->fileLength);

  for(int i = 0; i < fInfo->fileLength - 1; i++){
    
    if(fInfo->buffer[i] != '\n'){
      arr[j] = fInfo->buffer[i];
      j++;
      
    }
    else{
      numberOfChiffre++;
      if(j > array_size){
        array_size = j;
      }

      chiffre = atoi(arr);
      printf("%i\n", chiffre);
      
      for(int i = j; i < array_size; i++){
        arr[i] = '\0';
      }
      j = 0;
    }
  }
}

void printBuffer(char* buffer, int length){
  for(int i = 0; i < length; i++){
    printf("%c", buffer[i]);
  }
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
  
 	fInfo = (struct file *)malloc(sizeof(struct file) + sizeof(char) + sizeof(int) * fileLength);

  fInfo->fileLength = fileLength;
  fInfo->buffer = buffer;

  return fInfo; 
}

int program(){
	struct file *fInfo = getFileData("../data/input1.txt");
  //printBuffer(fInfo->buffer, fInfo->fileLength);
  struct report *r = getReport(fInfo);
  
	return 0;
}

int main(int argc, char* argv){

	program();
	return 0;
}
