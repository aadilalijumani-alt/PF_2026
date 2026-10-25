#include <stdio.h>

void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    int temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void printArray(const int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int songs[20];
    int n, i;

    printf("Enter number of songs: ");
    scanf("%d", &n);
    while (n < 1 || n > 20) {
        printf("Invalid size\n");
        printf("Enter number of songs: ");
        scanf("%d", &n);
    }

    printf("Enter song IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &songs[i]);
    }

    printf("Original: ");
    printArray(songs, n);
    reverseArray(songs, n);
    printf("Reversed: ");
    printArray(songs, n);

    return 0;
}
