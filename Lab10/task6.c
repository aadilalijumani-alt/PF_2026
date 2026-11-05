#include <stdio.h>
#include <string.h>

int main() {
    char names[5][50];
    char temp[50];
    int i, j;

    printf("Enter 5 student names (no spaces):\n");
    for (i = 0; i < 5; i++) {
        scanf("%s", names[i]);
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
            
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nSorted names:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
