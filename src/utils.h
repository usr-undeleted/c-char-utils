#ifndef CHARUTILS_H
#define CHARUTILS_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <stdio.h>

// the point of this header is to already write what the user would have
// written on their own to make their main code file shorter for better
// readability :3

// all funcs returns -1 if usage is invalid or func fails

// get string and letter to search, and (defined by option) do certain action.
// option 1: return the amount (quant) of chars found in string
// option 2: return the location of the first char located
int fndchar(char *word, char letter, int pckcase, int option) {

	int len = strlen(word);

	// checks if the input is valid
	if (option < 1 || option > 2 || word[0] == '\0' || letter == '\0' || pckcase < 0 || pckcase > 1) {
		return -1;
	}

	// if user wants to use lowercase, lower is turned into a lowercase version of word
	char lower[len];
	if (pckcase) {
		for (int i = 0;  i < len; i++) {
			lower[i] = tolower(word[i]);
		}
	// incase its not
	} else {
		for (int i = 0; i < len; i++) {
			lower[i] = word[i];
		}
	}

	// return total amount of matches
	if (option == 1) {

		int quant = 0;
		int match = 0;

		for (int i = 0; i < len; i++) {
			if (lower[i] == letter) {
				quant++;
				match = 1;
			}
		}

		// if no matches are found
		if (match == 0) {
			quant = -1;
		}
		return quant;
	}

	// return index of matched char
	if (option == 2) {
		for (int i = 0; i < len; i++) {
			if (lower[i] == letter) {
				return i;
			}
		}
	}
}

// takes string (word), replace all chars that are <match> with <replace>
// return the amount of chars replaced
// also supports case picking and error detection like the func above
int chchar(char word[], char match, char replace, int pckcase) {

	int len = strlen(word);

	// checks if the input is valid
	if (word[0] == '\0' || match == '\0' || replace == '\0' || pckcase < 0 || pckcase > 1) {
		return -1;
	}

	// if user wants to use lowercase, lower is turned into a lowercase version of word
	char lower[len];
	if (pckcase) {
		for (int i = 0;  i < len; i++) {
			lower[i] = tolower(word[i]);
		}
		// incase its not
	} else {
		for (int i = 0; i < len; i++) {
			lower[i] = word[i];
		}
	}

	int quant = 0;

	for (int i = 0; i < len; i++) {
		if (lower[i] == match) {
			word[i] = replace;
			quant++;
		}
	}

	return quant;
}

// takes string, and either (correlates to <option>):
// 1. append char to the end of string
// 2. return new string with char in <index>
// returns \0 incase it fails
char *charplc(char *word, char letter, int index, int option) {

	int len = strlen(word);

	// malloc-ed in order to be returned
	char *result = (char *)malloc(len + 1);
	if (!result) return NULL;

	// again, make sure user doesnt put invalid input
	if (word[0] == '\0' || letter == '\0' || index < 0 || option < 1 || option > 2 || index > len) {
		return "";
	}

	if (option == 1) {
		// set result to word
		for (int i = 0; i < len; i++) {
			result[i] = word[i];
		}

		// append char to end of string
		result[len] = letter;

		return result;

	} else

	if (option == 2) {
		// set result to word
		for (int i = 0; i < len; i++) {
			result[i] = word[i];
		}

		// put char in proper place
		result[index] = letter;

		// get anything after index in word and put it in result[index + 1]
		for (int i = index; i < len; i++) {
			result[i + 1] = word[i];
		}

		return result;
	}

}

// similar to charplc, but it clears the selected char and either (correlates to <option>):
// 1: replace removed char with a space
// 2: move all chars floating one to the left
char *clrchar(char *word, int index, int option) {

	int len = strlen(word);

	if (word[0] == '\0' || index < 0 || option < 1 || option > 2 || index > len) {
		return NULL;
	}

	switch (option) {
		case 1: {
			// malloc-ed here to prevent uneeded mem usage
			char *result = (char *)malloc(len);
			if (!result) return NULL;

			// copy word to result
			for (int i = 0; i < len; i++) {
				result[i] = word[i];
			}

			// set result[index] to space
			result[index] = ' ';

			return result;
		}
		case 2: {
			// malloc-ed here to prevent uneeded mem usage
			char *result = (char *)malloc(len);
			if (!result) return NULL;

			// copy everything before index
			for (int i = 0; i < index; i++) {
				result[i] = word[i];
			}

			// copy whatever is after index
			for (int i = index; i < len; i++) {
				result[i] = word[i + 1];
			}

			return result;
		}
	}
}

// deviates a little from the previous funcs, but it still works inside a string
// takes in an input string to be edited and one to be appended, and either:
// 1: just plops the string onto the end of the string
// (basically, switches place with whatever was in place before)
// 2: does the same but adds a space before the appended string
char *strapp(char *word, char *append, int index, int option) {

	int len = strlen(word);
	int applen = strlen(append);
	int totallen = applen + len;

	if (word[0] == '\0' || append[0] == '\0' || index < 0 || option < 1 || option > 2 || index > len) {
		return NULL;
	}

	switch (option) {
		case 1: {
			// malloc-ed here to prevent uneeded memory usage
			// + 1 to account for \0
			char *result = (char *)malloc(len + applen + 1);
			if (!result) return NULL;

			// copy everything before index
			for (int i = 0; i < index; i++) {
				result[i] = word[i];
			}

			// copy append to the end
			for (int i = 0; i < applen; i++) {
				result[index + i] = append[i];
			}

			// copy whatever was left of word
			for (int i = index; i < len; i++) {
				result[applen + i] = word[i];
			}

			// finalize string with end thingie
			result[len + applen] = '\0';

			return result;
		}
		case 2:
			// malloc-ed here to prevent uneeded memory usage
			// + 2 to include space and \0
			char *result = (char *)malloc(len + applen + 2);
			if (!result) return NULL;

			// malloc a new append with one space at the start
			char *edapp = (char *)malloc(sizeof(append) + 1);
			if (!result) return NULL;
			edapp[0] = ' ';

			// copy append's contents starting from [1]
			int j = 0;
			for (int i = 1; i < sizeof(edapp); i++) {
				edapp[i] = append[j];
				j++;
			}
			applen = sizeof(edapp);

			// copy everything before index
			for (int i = 0; i < index; i++) {
				result[i] = word[i];
			}

			// copy append to the end
			for (int i = 0; i < applen; i++) {
				result[index + i] = edapp[i];
			}

			// copy whatever was left of word
			for (int i = index; i < len; i++) {
				result[applen + i] = word[i];
			}

			// finalize string with end thingie
			result[len + applen] = '\0';

			return result;
	}

}

#endif
