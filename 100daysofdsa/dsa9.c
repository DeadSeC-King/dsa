//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>
#include <string.h>
int main() {
    char codeName[100];
    printf("Enter the code name: ");
    fgets(codeName, sizeof(codeName), stdin);
    codeName[strcspn(codeName, "\n")] = '\0'; // Remove newline character

    int length = strlen(codeName);
    char mirrorCode[100];

    for (int i = 0; i < length; i++) {
        mirrorCode[i] = codeName[length - 1 - i];
    }
    mirrorCode[length] = '\0'; // Null-terminate the string

    printf("Mirror format: %s\n", mirrorCode);
    return 0;
}