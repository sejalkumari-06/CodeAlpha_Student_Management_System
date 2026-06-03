#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student students[100];
int count = 0;

void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("\nStudent Added Successfully!\n");
}

void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\n----- Student Records -----\n");

    for (i = 0; i < count; i++) {
        printf("\nRoll No : %d", students[i].rollNo);
        printf("\nName    : %s", students[i].name);
        printf("\nMarks   : %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found!");
            printf("\nRoll No : %d", students[i].rollNo);
            printf("\nName    : %s", students[i].name);
            printf("\nMarks   : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent Not Found!\n");
}

void updateStudent() {
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {

            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nRecord Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent Not Found!\n");
}

void deleteStudent() {
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {

            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            found = 1;

            printf("\nStudent Record Deleted Successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nStudent Not Found!\n");
}

void averageMarks() {
    int i;

    if (count == 0) {
        printf("\nNo Student Records Available!\n");
        return;
    }

    float sum = 0;

    for (i = 0; i < count; i++) {
        sum += students[i].marks;
    }

    printf("\nAverage Marks = %.2f\n", sum / count);
}

int main() {
    int choice;

    do {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Calculate Average Marks");
        printf("\n7. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                averageMarks();
                break;

            case 7:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}