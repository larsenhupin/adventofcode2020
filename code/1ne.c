#include "platform_layer.c"

static int magic_input = 2020;

struct report {
	int* entries;
	int size;
};

struct report* createReport(struct file *fInfo){
	struct report *r = malloc(sizeof(int) * fInfo->lines + sizeof(int) * 1);
	int *entries = parseToIntBuffer(*fInfo);
 
	r->size = fInfo->lines;
	r->entries = entries;
	return r;
}

int findSumOf2(struct report *r){
  int sum = 0;
  int result = 0;

  for (int i = 0; i < r->size - 1; i++) {
	  for (int j = i + 1; j < r->size - 1; j++) {
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