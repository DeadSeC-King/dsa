//wap to create a simple strcuture of student and display student name,sapid,course
#include <stdio.h>
struct Student {
    char name[50];
    int sapid;
    char course[50];
};
int main() {
    struct Student student1;

    // Input student details
    printf("Enter student name: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    printf("Enter student SAP ID: ");
    scanf("%d", &student1.sapid);
    printf("Enter student course: ");
    scanf(" %[^\n]s", student1.course);

    // Display student details
    printf("\nStudent Details:\n");
    printf("Name: %s", student1.name);
    printf("SAP ID: %d\n", student1.sapid);
    printf("Course: %s\n", student1.course);

    return 0;
}
