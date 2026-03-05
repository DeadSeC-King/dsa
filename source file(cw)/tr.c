#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertatbeg(int value){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
void insertatend(int value){
    struct node *newnode;
    struct node *temp;
    
}