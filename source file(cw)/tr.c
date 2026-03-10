#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;
void insertbeg(int value){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if(head != NULL)
        head->prev = newnode;

    head = newnode;
}
void insertend(int value){
    struct node *newnode,*temp;

    newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL){
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}
void insertpos(int val,int pos){
    struct node *newnode,*temp;
    int i;

    newnode = malloc(sizeof(struct node));
    newnode->data = val;

    if(pos == 1){
        newnode->prev = NULL;
        newnode->next = head;

        if(head != NULL)
            head->prev = newnode;

        head = newnode;
        return;
    }

    temp = head;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}