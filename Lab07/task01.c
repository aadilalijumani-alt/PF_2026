#include <stdio.h>

int main() {
    int a[3][3], t[3][3], cof[3][3], adj[3][3];
    float inv[3][3];
    int i, j, k, l;
    int det;

    printf("Enter the elements of 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n--- Original Matrix ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            t[j][i] = a[i][j];
        }
    }
    printf("\n--- Transpose ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }

    det = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    printf("\n--- Determinant ---\n");
    printf("Determinant = %d\n", det);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int m[2][2];
            int r = 0, c = 0;
            int minor;

            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    if (k != i && l != j) {
                        m[r][c] = a[k][l];
                        c++;
                        if (c == 2) {
                            c = 0;
                            r++;
                        }
                    }
                }
            }

            minor = m[0][0] * m[1][1] - m[0][1] * m[1][0];
            if ((i + j) % 2 == 0) {
                cof[i][j] = minor;
            } else {
                cof[i][j] = -minor;
            }
        }
    }
    printf("\n--- Cofactor Matrix ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", cof[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adj[j][i] = cof[i][j];
        }
    }
    printf("\n--- Adjoint Matrix ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n--- Inverse Matrix ---\n");
    if (det == 0) {
        printf("Determinant is 0, so the inverse does not exist.\n");
    } else {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                inv[i][j] = (float)adj[i][j] / det;
            }
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%.2f\t", inv[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}