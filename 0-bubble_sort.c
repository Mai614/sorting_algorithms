#include "sort.h"

/**
 * swap_ints - Swaps two integers
 *
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers using Bubble Sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
size_t i, len = size;
bool bubbly = false;

if (array == NULL || size < 2)
return;

/* Loop until no swaps are made in one pass */
while (bubbly == false)
{
bubbly = true;

/* Perform one pass of bubble sort */
for (i = 0; i < len - 1; i++)
{
/* Swap elements if they are in the wrong order */
if (array[i] > array[i + 1])
{
swap_ints(array + i, array + i + 1);
print_array(array, size);
bubbly = false;
}
}

/* Decrease the length to avoid rechecking the last element */
len--;
}
}
