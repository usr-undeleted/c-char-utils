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
// 2. return new string
// returns \0 incase it fails
char *charplc(char *word, char letter, int index, int option) {

	int len = strlen(word);

	// malloc-ed in order to be returned
	char *result = (char *)malloc(len + 1);

	// again, make sure user doesnt put invalid input
	if (word[0] == '\0' || letter == '\0' || index < 0 || option < 1 || option > 2) {
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

	// malloc-ed in order to be returned
	char *result = (char *)malloc(len - 1);

	if (word[0] == '\0' || index < 0 || option < 1 || option > 2) {
		return "";
	}

	// move index to the right once since string is decreased
	index++;

	if (option == 1) {
		// set result to word
		for (int i = 0; i < len; i++) {
			result[i] = word[i];
		}

		// replace char with space
		result[index] = ' ';

		return result;

	} else

		if (option == 2) {
			// set result to word
			for (int i = 0; i < len; i++) {
				result[i] = word[i];
			}

			// get anything after index in word and put it in result[index - 1]
			// (move anything floating back)
			for (int i = index; i < len; i++) {
				result[i - 1] = word[i];
			}

			return result;
	}
}

#endif
