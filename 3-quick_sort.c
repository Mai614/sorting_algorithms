#include "sort.h"

/**
 * swap_ints - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme to choose
 *the pivot element for the Quick Sort algorithm.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @left: Index of the leftmost element of the partition.
 * @right: Index of the rightmost element of the partition.
 *Return: The index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
int *pivot, above, below;

pivot = array + right;
for (above = below = left; below < right; below++)
{
if (array[below] < *pivot)
{
if (above < below)
{
swap_ints(array + below, array + above);
print_array(array, size);
}
above++;
}
}

if (array[above] > *pivot)
{
swap_ints(array + above, pivot);
print_array(array, size);
}

return (above);
}

/**
 * lomuto_sort - Recursive function to perform Quick
 *Sort using Lomuto partition.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * @left: Index of the leftmost element of the partition.
 * @right: Index of the rightmost element of the partition.
 *
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
int part;

if (right - left > 0)
{
part = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, part - 1);
lomuto_sort(array, size, part + 1, right);
}
}

/**
 * quick_sort - Sorts an array of integers in
 *ascending order using the Quick Sort algorithm.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 *
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, size, 0, size - 1);
}
