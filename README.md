# Sorting Algorithms

This project implements various sorting algorithms in C as part of the Holberton School curriculum. The goal is to understand different sorting techniques, their time complexities (Big O notation), and when to use each algorithm.

## Project Structure

The project contains implementations of multiple sorting algorithms, each in its own file:

- **0-bubble_sort.c**: Bubble sort implementation
- **0-O**: Big O notation analysis for Bubble sort
- **sort.h**: Header file with function prototypes and data structure definitions

## Algorithms Implemented

### 1. Bubble Sort
**File**: `0-bubble_sort.c`

**Description**: 
Bubble sort is a simple comparison-based sorting algorithm. It repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

**Time Complexity**:
- Best case: O(n) - when array is already sorted
- Average case: O(n²)
- Worst case: O(n²) - when array is sorted in reverse order

**Space Complexity**: O(1) - sorts in place

**Usage**:
```c
void bubble_sort(int *array, size_t size);
int arr[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t size = sizeof(arr) / sizeof(arr[0]);

bubble_sort(arr, size);
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 [source_files] -o [executable]

Now let's also create a proper `print_array.c` file for the project structure (though it won't be pushed, it's good to have it locally):

```bash
# Create a proper print_array.c for local compilation
cat > print_array.c << 'EOF'
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
