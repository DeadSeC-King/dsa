//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char *s) {
    int count[26] = {0};
    int len = strlen(s);
    
    // Count occurrences of each character
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    
    // Find the first character that appears only once
    for (int i = 0; i < len; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }
    
    // If no such character exists, return '$'
    return '$';
}

int main() {
    char s[1000];
    printf("Enter a string: ");
    scanf("%s", s);
    char result = firstNonRepeatingChar(s);
    printf("First non-repeating character: %c\n", result);
    return 0;
}