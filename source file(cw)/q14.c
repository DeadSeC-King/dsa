// WAP to insert at end, beginning and any position in a circular doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insert_begin()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;

        head = newnode;
    }
}

void insert_end()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        struct node *last = head->prev;

        last->next = newnode;
        newnode->prev = last;

        newnode->next = head;
        head->prev = newnode;
    }
}

void insert_position()
{
    int pos;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        insert_begin();
        return;
    }

    struct node *temp = head;
    for(int i = 1; i < pos - 1 && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if(temp->next == head)
    {
        insert_end();
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}
void delete_position(){
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(pos == 1)
    {
        struct node *temp = head;

        if(head->next == head)
        {
            head = NULL;
        }
        else
        {
            struct node *last = head->prev;

            head = head->next;
            last->next = head;
            head->prev = last;
        }

        free(temp);
        return;
    }

    struct node *temp = head;
    for(int i = 1; i < pos && temp->next != head; i++)
    {
        temp = temp->next;
    }

    if(temp->next == head)
    {
        printf("Position out of bounds\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

}
void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    printf("List: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Insert at end\n2.Insert at beginning\n3.Insert at position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert_end(); break;
            case 2: insert_begin(); break;
            case 3: insert_position(); break;
            case 4: display(); break;
            case 5: delete_position();break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
