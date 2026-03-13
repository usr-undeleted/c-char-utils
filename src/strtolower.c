#include <stdio.h>
#include <utils.h>

// this is just example code
int main () {
    char *word = "AAAA AARGH ARRGHH";

    printf("Original string: %s\nNew one: %s\n", word,strtolower(word));

    return 0;
}
