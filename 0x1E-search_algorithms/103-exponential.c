#include "search_algos.h"

/**
 * _print_array - prints an array
 *
 * @array: the array
 * @low: lower bound
 * @high: higher bound
 */
void _print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i != high)
			printf(", ");
	}
	printf("\n");
}

/**
 * _binary_search - searches through an array using binary search
 * algorithm
 *
 * @array: pointer to the first element of the array to search
 * @left: the lower bound of the array
 * @right: the higher bound of the array
 * @value: the value to be searched
 * Return: the first index where the value is located or -1
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	right--;
	while (left <= right)
	{
		_print_array(array, left, right);
		mid = (left + right) / 2;
		if (array[mid] < value)
			left = mid + 1;
		else if (array[mid] > value)
			right = mid - 1;
		else
			return (mid);
	}
	return (-1);
}

/**
 * exponential_search - searches though an array using exponential algo
 *
 * @array: pointer to the first element of the array to search
 * @size: the size of the array
 * @value: the value to be searched
 * Return: the index of the element otherwise -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low, high;

	if (array == NULL)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = bound + 1 < size ? bound + 1 : size;
	printf("Value found between indexes [%ld] and [%ld]\n", low, high - 1);
	return (_binary_search(array, low, high, value));
}
