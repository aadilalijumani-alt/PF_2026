#include <stdio.h>

int main() {
    int a[5][5], b[5][5];
    int p[5][5], temp[5][5];
    int rows, cols, i, j, k, n;

    printf("Enter number of rows (max 5): ");
    scanf("%d", &rows);
    printf("Enter number of columns (max 5): ");
    scanf("%d", &cols);

    if (rows < 1 || rows > 5 || cols < 1 || cols > 5) {
        printf("Invalid size! Size must be between 1 and 5.\n");
        return 0;
    }

    printf("Enter the matrix elements:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nYour matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("\n===== Types of this matrix =====\n");
    int isSquare = 0;
    if (rows == cols) {
        isSquare = 1;
        printf("- Square Matrix\n");
    } else {
        printf("- Rectangular Matrix\n");
    }

    int isZero = 1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (a[i][j] != 0) {
                isZero = 0;
            }
        }
    }
    if (isZero == 1) {
        printf("- Zero Matrix\n");
        printf("- Null Matrix\n");
    }

    if (rows == 1) {
        printf("- Row Matrix\n");
    }

    if (cols == 1) {
        printf("- Column Matrix\n");
    }

    if (isSquare == 1) {
        n = rows;

        int isDiagonal = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j && a[i][j] != 0) {
                    isDiagonal = 0;
                }
            }
        }
        if (isDiagonal == 1) {
            printf("- Diagonal Matrix\n");
        }

        if (isDiagonal == 1) {
            int isScalar = 1;
            for (i = 0; i < n; i++) {
                if (a[i][i] != a[0][0]) {
                    isScalar = 0;
                }
            }
            if (isScalar == 1) {
                printf("- Scalar Matrix\n");
            }
        }

        int isIdentity = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j && a[i][j] != 1) {
                    isIdentity = 0;
                }
                if (i != j && a[i][j] != 0) {
                    isIdentity = 0;
                }
            }
        }
        if (isIdentity == 1) {
            printf("- Identity Matrix\n");
        }

        int isUpper = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (a[i][j] != 0) {
                    isUpper = 0;
                }
            }
        }
        if (isUpper == 1) {
            printf("- Upper Triangular Matrix\n");
        }

        int isLower = 1;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (a[i][j] != 0) {
                    isLower = 0;
                }
            }
        }
        if (isLower == 1) {
            printf("- Lower Triangular Matrix\n");
        }

        int isSym = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] != a[j][i]) {
                    isSym = 0;
                }
            }
        }
        if (isSym == 1) {
            printf("- Symmetric Matrix\n");
        }

        int isSkew = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] != -a[j][i]) {
                    isSkew = 0;
                }
            }
        }
        if (isSkew == 1) {
            printf("- Skew-Symmetric Matrix\n");
        }

        double d[5][5];
        double det = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                d[i][j] = a[i][j];
            }
        }
        for (i = 0; i < n; i++) {
            
            int pivot = -1;
            for (k = i; k < n; k++) {
                if (d[k][i] != 0) {
                    pivot = k;
                    break;
                }
            }
            if (pivot == -1) {
                det = 0;
                break;
            }
            if (pivot != i) {
                for (j = 0; j < n; j++) {
                    double t = d[i][j];
                    d[i][j] = d[pivot][j];
                    d[pivot][j] = t;
                }
                det = -det;
            }
            det = det * d[i][i];
            for (k = i + 1; k < n; k++) {
                double f = d[k][i] / d[i][i];
                for (j = i; j < n; j++) {
                    d[k][j] = d[k][j] - f * d[i][j];
                }
            }
        }
        if (det == 0) {
            printf("- Singular Matrix (determinant = 0)\n");
        } else {
            printf("- Non-Singular Matrix (determinant = %.2f)\n", det);
        }

        int isIdem = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                temp[i][j] = 0;
                for (k = 0; k < n; k++) {
                    temp[i][j] = temp[i][j] + a[i][k] * a[k][j];
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (temp[i][j] != a[i][j]) {
                    isIdem = 0;
                }
            }
        }
        if (isIdem == 1) {
            printf("- Idempotent Matrix\n");
        }

        int isNil = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                p[i][j] = a[i][j];  
            }
        }
        for (int power = 1; power <= n; power++) {
            int allZero = 1;
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if (p[i][j] != 0) {
                        allZero = 0;
                    }
                }
            }
            if (allZero == 1) {
                isNil = 1;
                break;
            }
            
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    temp[i][j] = 0;
                    for (k = 0; k < n; k++) {
                        temp[i][j] = temp[i][j] + p[i][k] * a[k][j];
                    }
                }
            }
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    p[i][j] = temp[i][j];
                }
            }
        }
        if (isNil == 1) {
            printf("- Nilpotent Matrix\n");
        }
    } else {
        printf("(Square matrix types are not checked because the matrix is not square)\n");
    }

    char choice;
    printf("\nDo you want to compare with another matrix? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the second matrix (%d x %d):\n", rows, cols);
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("Enter b[%d][%d]: ", i, j);
                scanf("%d", &b[i][j]);
            }
        }
        int isEqual = 1;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                if (a[i][j] != b[i][j]) {
                    isEqual = 0;
                }
            }
        }
        if (isEqual == 1) {
            printf("- Equal Matrix (both matrices are equal)\n");
        } else {
            printf("- The two matrices are NOT equal\n");
        }
    }

    return 0;
}