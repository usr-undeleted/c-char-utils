#include <stdio.h>
#include <utils.h>

// this is just example code
int main () {

    char word[] = "This phrase has a simply surprising amount of 'S's!";
    char match = 's';
    char replace = '0';

    int quant = chchar(word, match, replace, 1);

    printf("String is now: %s\nChars replaced: %d\n", word, quant);
    return 0;
}
