//wap to insert at end,first and any position in a doublylinked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;
void insert_end()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}
void insert_begin()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insert_position()
{
    int pos;
    printf("enter the position:");
    scanf("%d",&pos);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        int i=1;
        while(i<pos-1 && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp==NULL)
        {
            printf("position not found");
        }
        else
        {
            newnode->next=temp->next;
            newnode->prev=temp;
            if(temp->next!=NULL)
            {
                temp->next->prev=newnode;
            }
            temp->next=newnode;
        }
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n1.insert at end\n2.insert at beginning\n3.insert at position\n4.display\n5.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_end();
            break;
            case 2:insert_begin();
            break;
            case 3:insert_position();
            break;
            case 4:display();
            break;
            case 5:exit(0);
            default:printf("invalid choice");
        }
    }
    return 0;
}