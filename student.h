#ifndef STUDENT_H
#define STUDENT_H

// Define the number of subjects for all students
#define NUM_SUBJECTS 5

/**
 * @struct Student
 * @brief Represents a single student with personal details, marks, and total score.
 */
typedef struct {
    char name[100];      // Student's full name
    char rollNo[20];     // Student's roll number (unique identifier)
    float marks[NUM_SUBJECTS]; // Array to store marks for multiple subjects
    float totalScore;    // Calculated sum of all subject marks, used for ranking
} Student;

/**
 * @brief Calculates the sum of all subject marks for a given student
 * and updates their totalScore field.
 * @param s A pointer to the Student object whose totalScore needs to be updated.
 */
void calculateTotalScore(Student* s);

#endif // STUDENT_H