#include <stdio.h>
#include <utils.h>
#include <stdlib.h>

// this is just example code
int main (int argc, char *argv[]) {

	char *word = "HaIii!!";
	char letter = 'i';
	printf("Word is '%s'\nLetter is '%c'\n", word, letter);

	// read the header to see all options
	if (argc < 2) {
		printf("Please input an option as the second arg!\n");
		return 1;
	}
	int option = atoi(argv[1]);

	if (option < 1 || option > 2) {
		printf("Invalid option!\n");
		return 2;
	}

	int result = fndchar(word, letter, 1, option);

	if (option == 2) {
		printf("located char = '%c'\n", word[result]);
	} else

	if (option == 1) {
		printf("total amount of matches = %d\n", result);
	}
	return 0;
}

