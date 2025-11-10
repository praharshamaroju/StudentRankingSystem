#include <stdio.h>
#include <stdlib.h> // For malloc, realloc, qsort
#include "array_ops.h"

// Internal static variables to manage the dynamic array
static Student* studentArray; // Pointer to the dynamically allocated array
static int arrayCapacity;     // Current maximum number of students the array can hold
static int studentCount;      // Current number of students actually in the array

/**
 * @brief Comparison function required by qsort to sort students.
 * Sorts students in DESCENDING order of their totalScore.
 */
static int compareStudents(const void* a, const void* b) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    
    // For descending order, if s1 < s2, s1 should come *after* s2, so return 1.
    if (s1->totalScore < s2->totalScore) return 1;
    if (s1->totalScore > s2->totalScore) return -1;
    return 0; // Scores are equal
}

// --- Public Function Implementations ---

void init_array() {
    arrayCapacity = 10; // Start with a small initial capacity
    studentCount = 0;   // No students initially
    studentArray = (Student*)malloc(arrayCapacity * sizeof(Student));
    if (studentArray == NULL) {
        fprintf(stderr, "Error: Could not allocate initial memory for array.\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
}

void add_student_to_array(Student s) {
    // Check if the array is full and needs to be resized
    if (studentCount == arrayCapacity) {
        arrayCapacity *= 2; // Double the capacity
        studentArray = (Student*)realloc(studentArray, arrayCapacity * sizeof(Student));
        if (studentArray == NULL) {
            fprintf(stderr, "Error: Could not reallocate memory for array.\n");
            exit(EXIT_FAILURE); // Exit if memory reallocation fails
        }
    }
    
    // Add the new student to the next available position
    studentArray[studentCount] = s;
    studentCount++; // Increment the count of students
}

void display_ranks_from_array() {
    if (studentCount == 0) {
        printf("No students in the system yet to display ranks.\n");
        return;
    }

    // Sort the entire array using the standard library's quicksort function.
    // This is the O(N log N) operation for displaying a full ranked list.
    qsort(studentArray, studentCount, sizeof(Student), compareStudents);

    // Print the ranked list
    printf("\n--- Full Student Rank List (Sorted Array Method) ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Rank %2d: %-25s | Roll: %-10s | Score: %.2f\n", 
               i + 1, 
               studentArray[i].name, 
               studentArray[i].rollNo, 
               studentArray[i].totalScore);
    }
}

void free_array() {
    free(studentArray); // Release the dynamically allocated memory
    studentArray = NULL; // Prevent dangling pointer
    studentCount = 0;
    arrayCapacity = 0;
}