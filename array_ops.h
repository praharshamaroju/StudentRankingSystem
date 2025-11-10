#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

#include "student.h" // Include Student structure definition

/**
 * @brief Initializes the dynamic array. Allocates initial memory and sets counters.
 */
void init_array();

/**
 * @brief Adds a new student record to the dynamic array.
 * If the array is full, it automatically resizes to accommodate more students.
 * @param s The Student object to be added.
 */
void add_student_to_array(Student s);

/**
 * @brief Sorts all students in the array by their totalScore in descending order
 * and then prints the ranked list to the console.
 */
void display_ranks_from_array();

/**
 * @brief Frees all dynamically allocated memory used by the array to prevent memory leaks.
 */
void free_array();

#endif // ARRAY_OPS_H