#include <stdio.h>
#include <string.h>

int main() {
    char first[50];
    char last[50];
    char full[100];

    printf("Enter first name: ");
    scanf("%s", first);               

    printf("Enter last name: ");
    scanf("%s", last);

    strcpy(full, first);              
    strcat(full, " ");                
    strcat(full, last);               

    printf("Full name: %s\n", full);

    return 0;
}
