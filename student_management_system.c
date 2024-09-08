#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

// Function to add a student
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    Student student;
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    getchar(); // To consume the newline character left by scanf

    printf("Enter student name: ");
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline character

    printf("Enter student grade: ");
    scanf("%f", &student.grade);

    students[student_count++] = student;
    printf("Student added successfully!\n");
}

// Function to display all students
void display_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Grade: %.2f\n\n", students[i].grade);
    }
}

// Function to delete a student by ID
void delete_student() {
    int id, found = 0;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            found = 1;
            printf("Student deleted successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to search for a student by ID
void search_student() {
    int id, found = 0;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Grade: %.2f\n", students[i].grade);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to display the menu and handle user choices
void menu() {
    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                search_student();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

// Main function to start the program
int main() {
    menu();
    return 0;
}
