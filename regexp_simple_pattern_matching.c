#include <stdlib.h>
#include <stdio.h>
#include <regex.h>

void match_string(char *pattern, char *string) {
    regex_t regex;

    if(regcomp(&regex, pattern, 0)) {
        printf("not compiled!\n");
        exit(1);
    } else {
        printf("compiled!\n");
    }
    if(!regexec(&regex, string, 0, NULL, 0)) {
        printf("matched!\n");
    }
    regfree(&regex);
}

int main(int argc, char *argv[]) {
    match_string(argv[1], argv[2]);
    return 0;
}

