#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcmp in top student check
#include "student.h"
#include "array_ops.h"
#include "heap_ops.h"

/**
 * @brief Displays the main menu options to the user.
 */
void displayMenu() {
    printf("\n========================================\n");
    printf("   Student Ranking System (Array vs. Heap)\n");
    printf("========================================\n");
    printf("1. Add New Student\n");
    printf("2. Display Top Student (Fast - from Heap O(1))\n");
    printf("3. Display Full Rank List (Slower - from Array O(N log N))\n");
    printf("4. Exit\n");
    printf("----------------------------------------\n");
    printf("Enter your choice: ");
}

/**
 * @brief Clears the input buffer to prevent residual newlines or characters
 * from interfering with subsequent scanf calls, especially after reading integers.
 */
static void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Prompts the user to enter details for a new student (name, roll number, marks).
 * It also calculates the student's total score.
 * @return A Student object populated with user-provided data.
 */
Student getStudentDetails() {
    Student s;
    printf("\n--- Enter New Student Details ---\n");
    printf("Enter name: ");
    clearInputBuffer(); // Clear buffer before reading string
    scanf(" %[^\n]", s.name); // Read string with spaces until newline
    
    printf("Enter roll number: ");
    clearInputBuffer();
    scanf(" %[^\n]", s.rollNo);
    
    s.totalScore = 0; // Initialize total score
    printf("Enter marks for %d subjects (e.g., 85.5 78 92.0 65 70):\n", NUM_SUBJECTS);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d mark: ", i + 1);
        scanf("%f", &s.marks[i]);
    }
    calculateTotalScore(&s); // Calculate the total score for this student
    
    return s;
}

int main() {
    int choice = 0;

    // Initialize both data structures at the start of the program
    init_array();
    init_heap();
    printf("System successfully initialized with empty student lists.\n");

    // Main program loop: continues until the user chooses to exit (choice 4)
    while (choice != 4) {
        displayMenu(); // Show the menu
        
        // Read user's choice, handling invalid non-numeric input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number corresponding to a menu option.\n");
            clearInputBuffer(); // Clear buffer to prevent infinite loop
            continue; // Go back to the start of the loop
        }

        // Process the user's choice
        switch (choice) {
            case 1: // Add New Student
                {
                    Student newStudent = getStudentDetails(); // Get details from user
                    
                    // Add the student to both data structures
                    add_student_to_array(newStudent);
                    insert_into_heap(newStudent);
                    
                    printf("\nSUCCESS: Student '%s' (Roll: %s) added to both Array and Heap.\n", 
                           newStudent.name, newStudent.rollNo);
                }
                break;
            case 2: // Display Top Student (from Heap)
                {
                    Student topStudent = get_top_student_from_heap();
                    printf("\n--- Top Ranked Student (from Max-Heap: O(1)) ---\n");
                    // Check if the returned student is a sentinel for an empty heap
                    if (topStudent.totalScore == 0.0 && strcmp(topStudent.name, "N/A") == 0) {
                         // Message already printed by get_top_student_from_heap()
                    } else {
                        printf("Name: %s | Roll: %s | Score: %.2f\n", 
                               topStudent.name, topStudent.rollNo, topStudent.totalScore);
                    }
                }
                break;
            case 3: // Display Full Rank List (from Array)
                display_ranks_from_array();
                break;
            case 4: // Exit
                printf("Exiting Student Ranking System. Cleaning up memory.\n");
                break;
            default: // Invalid choice
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    // Clean up dynamically allocated memory before program ends
    free_array(); 
    // (Heap in this case uses a static array, so no explicit free_heap() is needed)

    return 0; // Indicate successful program execution
}

// Implementation for calculateTotalScore (from student.h)
void calculateTotalScore(Student* s) {
    s->totalScore = 0.0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        s->totalScore += s->marks[i];
    }
}