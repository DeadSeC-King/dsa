//wap of union to store students name ,id and course and display it
#include <stdio.h>
union Student {
    char name[50];
    int sapid;
    char course[50];
};
int main() {
    union Student student;

    // Input student name
    printf("Enter student name: ");
    fgets(student.name, sizeof(student.name), stdin);
  

    // Input student SAP ID
    printf("Enter student SAP ID: ");
    scanf("%d", &student.sapid);
    while (getchar() != '\n');

    // Input student course
    printf("Enter student course: ");
    fgets(student.course, sizeof(student.course), stdin);
    printf("Student Name: %s", student.name);
    printf("Student SAP ID: %d\n", student.sapid);
    printf("Student Course: %s", student.course);

    return 0;
}