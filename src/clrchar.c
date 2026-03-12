#include <utils.h>
#include <stdio.h>

// this is just example code
int main () {

	char *word = "Bamboozled!";
	int index = 0;

	char *result = clrchar(word, index, 2);

	printf("Original = %s\nResult = %s\n", word, result);

	return 0;
}
