#include <stdio.h>
#include <string.h>
int main()
{
    char str[200];
    int f = 0;
    printf("Enter the code line:\n");
    fgets(str, 200, stdin);

    str[strcspn(str, "\n")] = 0;

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] == '/' && str[i + 1] == '/') {
            printf("Single line comment detected\n");
            f = 1;
            break;
        }
        else if (str[i] == '/' && str[i + 1] == '*') {

            for (int j = i + 2; j < length; j++) {
                if (str[j] == '*' && str[j + 1] == '/') {
                    printf("Multiple line comment detected\n");
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                break;
            }
        }
    }

    if (f == 0) {
        printf("No comments detected\n");
    }

    return 0;
}
