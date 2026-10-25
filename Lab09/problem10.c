#include <stdio.h>

int add(int a, int b, int *result) {
    *result = a + b;
    return 1;
}

int subtract(int a, int b, int *result) {
    *result = a - b;
    return 1;
}

int multiply(int a, int b, int *result) {
    *result = a * b;
    return 1;
}

int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;
    }
    *result = a / b;
    return 1;
}

int main() {
    int (*ops[])(int, int, int *) = {add, subtract, multiply, divide};
    char *names[] = {"Add", "Subtract", "Multiply", "Divide"};
    int choice = 0;
    int a, b, result;

    while (choice != 5) {
        printf("\n1 Add\n2 Subtract\n3 Multiply\n4 Divide\n5 Exit\n");
        printf("Choice (1-5): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice\n");
        } else if (choice == 5) {
            printf("Goodbye.\n");
        } else {
            printf("Enter a and b: ");
            scanf("%d %d", &a, &b);
            if (ops[choice - 1](a, b, &result)) {
                printf("%s result: %d\n", names[choice - 1], result);
            } else {
                printf("Error: division by zero\n");
            }
        }
    }

    return 0;
}
