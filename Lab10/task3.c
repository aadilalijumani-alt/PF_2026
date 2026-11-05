#include <stdio.h>
#include <string.h>

int main() {
    char correct[] = "lab10pass";
    char password[50];

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(password, correct) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    if (strncmp(password, correct, 3) == 0) {
        printf("First 3 characters match.\n");
    } else {
        printf("First 3 characters do not match.\n");
    }

    return 0;
}
