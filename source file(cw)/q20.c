#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* fptr = NULL;
struct Node* rptr = NULL;

// enqueue
void enqueue(int val) {
    struct Node* nptr = (struct Node*)malloc(sizeof(struct Node));

    if (nptr == NULL) {
        printf("Overflow! memory not avalable\n");
        return;
    }

    nptr->data = val;
    nptr->next = NULL;

    if (rptr == NULL) {
        fptr = rptr = nptr;
    } else {
        rptr->next = nptr;
        rptr = nptr;
    }

    printf("Valu insrted sucesfuly: %d\n", val);
}

// dequeue
void dequeue() {
    if (fptr == NULL) {
        printf(" queue is empty\n");
        return;
    }

    struct Node* dptr = fptr;
    printf("Deltd valu: %d\n", dptr->data);

    fptr = fptr->next;

    if (fptr == NULL)
        rptr = NULL;

    free(dptr);
}

// display
void display() {
    if (fptr == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* tptr = fptr;

    printf("Queue elements: ");
    while (tptr != NULL) {
        printf("%d ", tptr->data);
        tptr = tptr->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}