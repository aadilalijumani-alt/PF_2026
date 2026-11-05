#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char copy[100];

    printf("Enter your name: ");
    fgets(name, 100, stdin);         

    name[strcspn(name, "\n")] = '\0';

    printf("Length of name: %lu\n", strlen(name));

    strcpy(copy, name);               
    printf("Copied name: %s\n", copy);

    printf("sizeof(name) = %lu\n", sizeof(name));
    printf("strlen(name) = %lu\n", strlen(name));

    return 0;
}
