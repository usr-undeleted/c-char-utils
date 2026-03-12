#include <utils.h>
#include <stdio.h>

// this is just example code
int main () {

	char *word = "Bamboozled!";
	char letter = 'R';
	int index = 4;

	char *result = charplc(word, letter, index, 2);

	printf("Original = %s\nResult = %s\n", word, result);

	// remember to free the heap memory!
	free(result);

	return 0;
}
