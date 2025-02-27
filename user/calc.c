// user/calculator.c

#include "../kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: calc num1 operator num2\n");
        exit(0);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char operator = argv[2][0];
    char op_str[2] = {operator, '\0'}; // Create a string for the operator

    switch (operator) {
        case '+':
            printf("%d %s %d = %d\n", num1, op_str, num2, num1 + num2);
            break;
        case '-':
            printf("%d %s %d = %d\n", num1, op_str, num2, num1 - num2);
            break;
        case '*':
            printf("%d %s %d = %d\n", num1, op_str, num2, num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("%d %s %d = %d\n", num1, op_str, num2, num1 / num2);
            }
            break;
        default:
            printf("Unknown operator %s\n", op_str);
            break;
    }

    exit(0);
}