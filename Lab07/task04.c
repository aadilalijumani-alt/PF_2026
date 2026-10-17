#include <stdio.h>

int main() {
    int arr[3][3][3];
    int i, j, k;
     for (i = 0; i < 3; i++) {
        printf("Enter elements of Layer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("Enter arr[%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
    printf("\n===== The 3D Array =====\n");
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

    int layerTotal[3];
    int grandTotal = 0;
    int overallMax = arr[0][0][0];
    int overallMin = arr[0][0][0];
    int maxL = 0, maxR = 0, maxC = 0;
    int minL = 0, minR = 0, minC = 0;

    printf("===== Layer wise Analysis =====\n");
    for (i = 0; i < 3; i++) {
        int rowSum[3] = {0, 0, 0};
        int colSum[3] = {0, 0, 0};
        int mainDiag = 0, otherDiag = 0;
        int total = 0;
        int layerMax = arr[i][0][0];
        int layerMin = arr[i][0][0];

        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                total = total + arr[i][j][k];
                rowSum[j] = rowSum[j] + arr[i][j][k];
                colSum[k] = colSum[k] + arr[i][j][k];

                if (j == k) {
                    mainDiag = mainDiag + arr[i][j][k];
                }
                if (j + k == 2) {
                    otherDiag = otherDiag + arr[i][j][k];
                }

                if (arr[i][j][k] > layerMax) {
                    layerMax = arr[i][j][k];
                }
                if (arr[i][j][k] < layerMin) {
                    layerMin = arr[i][j][k];
                }

                if (arr[i][j][k] > overallMax) {
                    overallMax = arr[i][j][k];
                    maxL = i; maxR = j; maxC = k;
                }
                if (arr[i][j][k] < overallMin) {
                    overallMin = arr[i][j][k];
                    minL = i; minR = j; minC = k;
                }
            }
        }

        layerTotal[i] = total;
        grandTotal = grandTotal + total;

        printf("\nLayer %d:\n", i + 1);
        printf("  Total of layer     = %d\n", total);
        printf("  Average of layer   = %.2f\n", total / 9.0);
        printf("  Maximum in layer   = %d\n", layerMax);
        printf("  Minimum in layer   = %d\n", layerMin);
        for (j = 0; j < 3; j++) {
            printf("  Sum of row %d       = %d\n", j + 1, rowSum[j]);
        }
        for (k = 0; k < 3; k++) {
            printf("  Sum of column %d    = %d\n", k + 1, colSum[k]);
        }
        printf("  Main diagonal sum  = %d\n", mainDiag);
        printf("  Other diagonal sum = %d\n", otherDiag);
    }

    int bestLayer = 0, worstLayer = 0;
    for (i = 1; i < 3; i++) {
        if (layerTotal[i] > layerTotal[bestLayer]) {
            bestLayer = i;
        }
        if (layerTotal[i] < layerTotal[worstLayer]) {
            worstLayer = i;
        }
    }

    printf("\n===== Overall Insights =====\n");
    printf("Grand total of all elements = %d\n", grandTotal);
    printf("Overall average             = %.2f\n", grandTotal / 27.0);
    printf("Largest element  = %d (at layer %d, row %d, column %d)\n", overallMax, maxL + 1, maxR + 1, maxC + 1);
    printf("Smallest element = %d (at layer %d, row %d, column %d)\n", overallMin, minL + 1, minR + 1, minC + 1);
    printf("Layer with highest total = Layer %d (%d)\n", bestLayer + 1, layerTotal[bestLayer]);
    printf("Layer with lowest total  = Layer %d (%d)\n", worstLayer + 1, layerTotal[worstLayer]);

    return 0;
}