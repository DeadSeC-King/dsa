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
void inserend(int value){
    struct node *newnode;
    struct node *temp;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertpos(int val,int pos){
    struct node *newnode;
    struct node *temp;
    int i;
    newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    if(pos==1){
        newnode->next=head;
        head=newnode;
        return;
    }
    temp=head;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}