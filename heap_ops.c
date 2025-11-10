#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcmp to check "N/A"
#include "heap_ops.h"

// Internal static variables for the Max-Heap
static Student heap[MAX_HEAP_SIZE]; // Array representing the heap
static int heapSize;                // Current number of elements in the heap

// --- Internal Helper Function Prototypes ---
static void swap(Student* a, Student* b);
static int parent(int i);
static void heapify_up(int index);

// --- Public Function Implementations ---

void init_heap() {
    heapSize = 0; // Heap is empty initially
}

void insert_into_heap(Student s) {
    if (heapSize >= MAX_HEAP_SIZE) {
        fprintf(stderr, "Error: Heap is full. Cannot add more students.\n");
        return;
    }
    
    // 1. Insert the new element at the very end of the heap array
    heap[heapSize] = s;
    int currentIndex = heapSize; // Store its position
    heapSize++;                  // Increment heap size

    // 2. Restore the Max-Heap property by moving the new element up ("bubbling up")
    heapify_up(currentIndex);
}

Student get_top_student_from_heap() {
    if (heapSize == 0) {
        printf("Heap is empty. No top student available.\n");
        // Return a sentinel (empty) Student object to indicate no student found
        Student empty = {"N/A", "N/A", {0}, 0.0};
        return empty;
    }
    // In a Max-Heap, the element with the highest key (totalScore) is always at index 0.
    return heap[0];
}

// --- Internal Helper Function Implementations ---

/**
 * @brief Swaps the contents of two Student objects.
 */
static void swap(Student* a, Student* b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Calculates the index of the parent node for a given child index.
 */
static int parent(int i) {
    return (i - 1) / 2;
}

/**
 * @brief Moves an element at 'index' up the heap (towards the root)
 * until the Max-Heap property is satisfied or it reaches the root.
 */
static void heapify_up(int index) {
    // Stop if we are already at the root of the heap
    if (index == 0) return;

    int p_index = parent(index); // Get the parent's index

    // If the child's score is greater than its parent's score, they are out of order.
    // Swap them and continue checking upwards.
    if (heap[index].totalScore > heap[p_index].totalScore) {
        swap(&heap[index], &heap[p_index]);
        // Recursively call heapify_up for the parent's new position (where the child just moved)
        heapify_up(p_index);
    }
}