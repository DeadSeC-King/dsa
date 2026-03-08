#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union uni
{
    float cgpa;
    int marks;
};

struct adresss
{
    char city[30];
    int pin;
};

struct student
{
    char name[50];
    char address[100];
    int id;
    struct adresss ad;
    union uni u;
    int type; // 1 = cgpa , 2 = marks
    struct student *next;
};

struct student *head = NULL;

void insert()
{
    struct student *newnode = (struct student*)malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", newnode->name);

    printf("Enter address: ");
    scanf(" %[^\n]", newnode->address);

    printf("Enter id: ");
    scanf("%d", &newnode->id);

    printf("Enter city: ");
    scanf(" %[^\n]", newnode->ad.city);

    printf("Enter pin: ");
    scanf("%d", &newnode->ad.pin);

    printf("Enter 1 for CGPA and 2 for Marks: ");
    scanf("%d", &newnode->type);

    if(newnode->type == 1)
    {
        printf("Enter CGPA: ");
        scanf("%f", &newnode->u.cgpa);
    }
    else
    {
        printf("Enter Marks: ");
        scanf("%d", &newnode->u.marks);
    }

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct student *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("Student inserted successfully\n");
}

void deleteNode()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct student *temp = head;
    head = head->next;
    free(temp);

    printf("First student deleted\n");
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct student *temp = head;

    while(temp != NULL)
    {
        printf("\nName: %s\n", temp->name);
        printf("Address: %s\n", temp->address);
        printf("ID: %d\n", temp->id);
        printf("City: %s\n", temp->ad.city);
        printf("Pin: %d\n", temp->ad.pin);

        if(temp->type == 1)
            printf("CGPA: %.2f\n", temp->u.cgpa);
        else
            printf("Marks: %d\n", temp->u.marks);

        temp = temp->next;
    }
}

void search()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    struct student *temp = head;

    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("\nStudent Found\n");
            printf("Name: %s\n", temp->name);
            printf("Address: %s\n", temp->address);
            printf("ID: %d\n", temp->id);
            printf("City: %s\n", temp->ad.city);
            printf("Pin: %d\n", temp->ad.pin);

            if(temp->type == 1)
                printf("CGPA: %.2f\n", temp->u.cgpa);
            else
                printf("Marks: %d\n", temp->u.marks);

            return;
        }

        temp = temp->next;
    }

    printf("Student with ID %d not found\n", id);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n----- Student Management -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                search();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}