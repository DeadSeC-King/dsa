//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>
#define MAX_CANDIDATES 1000
#define MAX_NAME_LENGTH 100

char* findWinner(char candidates[MAX_CANDIDATES][MAX_NAME_LENGTH], int n) {
    int count[MAX_CANDIDATES] = {0};
    
    // Count votes for each candidate
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(candidates[i], candidates[j]) == 0) {
                count[i]++;
            }
        }
    }
    
    // Find the candidate with the maximum votes
    int maxVotes = 0;
    char* winner = NULL;
    
    for (int i = 0; i < n; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            winner = candidates[i];
        } else if (count[i] == maxVotes && strcmp(candidates[i], winner) < 0) {
            winner = candidates[i];
        }
    }
    
    return winner;
}

int main() {
    int n;
    char candidates[MAX_CANDIDATES][MAX_NAME_LENGTH];
    
    printf("Enter the number of votes: ");
    scanf("%d", &n);
    
    printf("Enter the candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", candidates[i]);
    }
    
    char* winner = findWinner(candidates, n);
    printf("The winner is: %s\n", winner);
    
    return 0;
}