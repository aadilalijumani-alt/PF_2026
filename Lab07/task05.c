#include <stdio.h>

int main() {
    int arr[3][3][3];
    int i, j, k;
    int l1, l2;

    for (i = 0; i < 3; i++) {
        printf("Enter elements of Layer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("Enter arr[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
    printf("\n===== The 3D Matrix Set =====\n");
    for (i = 0; i < 3; i++) {
        printf("Layer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%d\t", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int identicalPairs = 0;
    int totalPairs = 0;

    printf("===== Layer Comparison =====\n");

    for (l1 = 0; l1 < 3; l1++) {
        for (l2 = l1 + 1; l2 < 3; l2++) {
            int diffCount = 0;
            totalPairs++;

            printf("\nComparing Layer %d and Layer %d:\n", l1 + 1, l2 + 1);

            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    if (arr[l1][j][k] != arr[l2][j][k]) {
                        diffCount++;
                        printf("  Difference at row %d, column %d: %d != %d\n",
                               j + 1, k + 1, arr[l1][j][k], arr[l2][j][k]);
                    }
                }
            }

            if (diffCount == 0) {
                printf("  Result: Layer %d and Layer %d are IDENTICAL.\n", l1 + 1, l2 + 1);
                identicalPairs++;
            } else {
                printf("  Result: Layer %d and Layer %d are DISTINCT (%d elements differ).\n",
                       l1 + 1, l2 + 1, diffCount);
            }
        }
    }

    printf("\n===== Summary =====\n");
    printf("Total pairs compared  = %d\n", totalPairs);
    printf("Identical pairs       = %d\n", identicalPairs);
    printf("Distinct pairs        = %d\n", totalPairs - identicalPairs);

    if (identicalPairs == 3) {
        printf("All three layers are identical.\n");
    } else if (identicalPairs == 0) {
        printf("All three layers are distinct.\n");
    } else {
        printf("Some layers are identical and some are distinct.\n");
    }

    return 0;
}