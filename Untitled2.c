#include <stdio.h>

int main() {
    char input[100];
    int i = 0;
    int b_count = 0;

    printf("Enter a string to match the pattern 'a*b+': ");
    scanf("%s", input);

    while (input[i] == 'a') {
        i++;
    }

    while (input[i] == 'b') {
        b_count++;
        i++;
    }

    if (b_count > 0 && input[i] == '\0') {
        printf("The input matches the pattern 'a*b+'.\n");
    } else {
        printf("The input does not match the pattern 'a*b+'.\n");
    }

    return 0;
}
