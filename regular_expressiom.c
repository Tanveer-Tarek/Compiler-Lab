#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    int f = 0;

    printf("Enter the input: ");
    scanf("%s", str);

    int length = sizeof(str);


    int i = 0;

    // Consume 'a's
    while (i < length && str[i] == 'b') {
        i++;
    }

    // Now check for one 'b'
    if (i < length && str[i] == 'a') {
        i++;
        // Check if there are any characters left
        if (i == length) {
            f = 1; // Valid: pattern matched
        }
    }

    if (f == 1) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
