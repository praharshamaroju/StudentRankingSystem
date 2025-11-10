#ifndef HEAP_OPS_H
#define HEAP_OPS_H

#include "student.h" // Include Student structure definition

// Using a fixed-size array for the heap for simplicity in a micro-project.
#define MAX_HEAP_SIZE 200 

/**
 * @brief Initializes the Max-Heap, typically by setting its current size to zero.
 */
void init_heap();

/**
 * @brief Inserts a new student into the Max-Heap.
 * This is an O(log N) operation.
 * @param s The Student object to insert into the heap.
 */
void insert_into_heap(Student s);

/**
 * @brief Retrieves the top-ranked student (the one with the highest totalScore)
 * from the Max-Heap without removing them.
 * This is an O(1) operation.
 * @return The Student object at the root of the heap.
 */
Student get_top_student_from_heap();

#endif // HEAP_OPS_H