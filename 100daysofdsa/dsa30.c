//Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* newNode(int coeff, int exp) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node** lastPtr = &result;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            *lastPtr = newNode(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            *lastPtr = newNode(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                *lastPtr = newNode(sumCoeff, poly1->exp);
                lastPtr = &((*lastPtr)->next);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        lastPtr = &((*lastPtr)->next);
    }
    while (poly1 != NULL) {
        *lastPtr = newNode(poly1->coeff, poly1->exp);
        lastPtr = &((*lastPtr)->next);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        *lastPtr = newNode(poly2->coeff, poly2->exp);
        lastPtr = &((*lastPtr)->next);
        poly2 = poly2->next;
    }
    return result;
}
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coeff, poly->exp);
        if (poly->next != NULL && poly->next->coeff >= 0) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}
int main() {
    struct Node* poly1 = newNode(3, 2);
    poly1->next = newNode(5, 1);
    poly1->next->next = newNode(6, 0);
    struct Node* poly2 = newNode(6, 1);
    poly2->next = newNode(8, 0);
    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    struct Node* result = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    printPolynomial(result);
    return 0;
}
