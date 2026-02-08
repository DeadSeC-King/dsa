#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student data
typedef struct Student {
    int id;
    char name[50];
    float gpa;
    struct Student* next;
} Student;

// Function Prototypes
void displayMenu();
void addStudent(Student** head);
void displayStudents(Student* head);
void searchStudent(Student* head);
void deleteStudent(Student** head);

int main() {
    Student* head = NULL;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(&head); break;
            case 2: displayStudents(head); break;
            case 3: searchStudent(head); break;
            case 4: deleteStudent(&head); break;
            case 5: printf("Exiting system. Goodbye!\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Delete Student by ID\n");
    printf("5. Exit\n");
}

// Function to add a student at the end of the list
void addStudent(Student** head) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", newStudent->name); // Reads string with spaces
    printf("Enter GPA: ");
    scanf("%f", &newStudent->gpa);
    newStudent->next = NULL;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("Student added successfully!\n");
}

// Function to print all students
void displayStudents(Student* head) {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nID\tName\t\tGPA\n");
    printf("----------------------------\n");
    while (head != NULL) {
        printf("%d\t%-15s\t%.2f\n", head->id, head->name, head->gpa);
        head = head->next;
    }
}

// Function to search for a specific student
void searchStudent(Student* head) {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (head != NULL) {
        if (head->id == id) {
            printf("\nStudent Found: ID: %d, Name: %s, GPA: %.2f\n", head->id, head->name, head->gpa);
            found = 1;
            break;
        }
        head = head->next;
    }
    if (!found) printf("Student with ID %d not found.\n", id);
}

// Function to delete a student by ID
void deleteStudent(Student** head) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Student *temp = *head, *prev = NULL;

    // Case 1: If the student to
    if (temp != NULL && temp->id == id) {
        *head = temp->next;
        free(temp);
        printf("Student record deleted.\n");
        return;
    }
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student ID not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student record deleted.\n");
}