#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertbeg(int value){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
void insertend(int value ){
    struct node *temp;
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    if(head=NULL){
        head=newnode;
        return;
    }
    temp=head;
    while (head!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertpos(int value , int pos ){
    struct node *newnode;
    struct node *temp;
    int i;
    newnode=malloc(sizeof(struct node));
    
}