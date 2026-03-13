#include <utils.h>
#include <stdio.h>

// this is just example code
int main () {

	char *word = "I am!";
	char *append = "amazing";
	int index = 4;

	char *result = strapp(word, append, index, 2);

	printf("Original = %s\nResult = %s\n", word, result);

	// remember to free the heap memory!
	free(result);

	return 0;
}
