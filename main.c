#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    char input[100];

    while (1) {
        printf("Enter two integers separated by space (or type 'exit' to quit): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (sscanf(input, "%d %d", &num1, &num2) != 2) {
            if (strncmp(input, "exit", 4) == 0) {
                break;
            }
            printf("Please enter valid integers.\n");
            continue;
        }

        printf("The GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
    }

    return 0;
}