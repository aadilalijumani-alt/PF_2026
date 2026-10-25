#include <stdio.h>

void bubbleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
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
    int scores[20];
    int n, i;

    printf("Enter number of scores: ");
    scanf("%d", &n);
    while (n < 1 || n > 20) {
        printf("Invalid size\n");
        printf("Enter number of scores: ");
        scanf("%d", &n);
    }

    printf("Enter scores: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    printf("Before sorting: ");
    printArray(scores, n);
    bubbleSort(scores, n);
    printf("After sorting: ");
    printArray(scores, n);

    return 0;
}
