#include <stdio.h>

int main() {
    int a[3][3], b[3][3], c[3][3];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows of first matrix (max 3): ");
    scanf("%d", &r1);
    printf("Enter columns of first matrix (max 3): ");
    scanf("%d", &c1);
    printf("Enter rows of second matrix (max 3): ");
    scanf("%d", &r2);
    printf("Enter columns of second matrix (max 3): ");
    scanf("%d", &c2);

    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3 || r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3) {
        printf("Error: size of matrix cannot be more than 3x3.\n");
        return 0;
    }

    if (c1 != r2) {
        printf("Error: Multiplication is not possible!\n");
        printf("Columns of first matrix (%d) must be equal to rows of second matrix (%d).\n", c1, r2);
        return 0;
    }

    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Enter b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (k = 0; k < c1; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf("\nFirst Matrix (%d x %d):\n", r1, c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond Matrix (%d x %d):\n", r2, c2);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    printf("\nResult Matrix (%d x %d):\n", r1, c2);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}