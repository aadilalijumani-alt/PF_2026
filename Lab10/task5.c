#include <stdio.h>
#include <string.h>

int main() {
    char cities[5][50];
    int i, maxLen = 0, longestIndex = 0;

    printf("Enter 5 city names:\n");
    for (i = 0; i < 5; i++) {
        fgets(cities[i], 50, stdin);
        cities[i][strcspn(cities[i], "\n")] = '\0';  
    }

    printf("\nCities:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", cities[i]);
        if (strlen(cities[i]) > maxLen) {
            maxLen = strlen(cities[i]);
            longestIndex = i;
        }
    }

    printf("\nLongest city name: %s (length %d)\n",
           cities[longestIndex], maxLen);

    return 0;
}
