#include <stdio.h>
#include <string.h>

int copyfunc(char *str) {
    char buffer[600];
    strcpy(buffer, str);
    printf("Input: %s\n", buffer);
    return 0;
}

int main(int argc, char *argv[]) {
    copyfunc(argv[1]);
}
