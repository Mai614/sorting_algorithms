#include "sort.h"


/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using the Knuth sequence */
	while (gap < size / 3)
		gap = 3 * gap + 1;

	/* Start Shell sort with decreasing gaps */
	while (gap >= 1)
	{
		/* Perform insertion sort with current gap */
		for (i = gap; i < size; i++)
		{
			int current = array[i];

			/* Shift elements that are 'gap' positions apart */
			for (j = i; j >= gap && current < array[j - gap]; j -= gap)
				array[j] = array[j - gap];

			/* Place the current element at its correct position */
			array[j] = current;
		}

		/* Reduce the gap for the next iteration */
		gap /= 3;

		/* Print the current state of the array */
		print_array(array, size);
	}
}
