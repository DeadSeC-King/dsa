//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>
#include <string.h>
char firstRepeatedCharacter(char* s) {
    int freq[26] = {0}; // Assuming only lowercase letters

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        freq[index]++;
        if (freq[index] == 2) {
            return s[i]; // Return the first repeated character
        }
    }
    return '\0'; // Return null character if no repeated character is found
}
int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    char result = firstRepeatedCharacter(s);
    if (result != '\0') {
        printf("The first repeated character is: %c\n", result);
    } else {
        printf("No repeated character found.\n");
    }

    return 0;
}
