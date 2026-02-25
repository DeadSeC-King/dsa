//First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, key, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the linked list
    struct Node {
        int data;
        struct Node* next;
    };
    
    struct Node* head = NULL;
    struct Node* temp = NULL;
    
    // Create the linked list
    for (i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = head;
        head = temp;
    }
    
    printf("Enter the key to find: ");
    scanf("%d", &key);
    
    // Search for the first occurrence of the key
    temp = head;
    int position = 1; // Position starts from 1
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key found at position: %d\n", position);
            break;
        }
        temp = temp->next;
        position++;
    }
    
    if (temp == NULL) {
        printf("Key not found in the list.\n");
    }
    
    // Free allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
 