#include "main.h"

/**
 * calculate_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @current_index: List of arguments to be printed.
 *
 * Return: Precision.
 */
int calculate_size(const char *format, int *current_index)
{
	int currIndex = *current_index + 1;
	int size = 0;

	if (format[currIndex] == 'l')
		size = LARGE_SIZE;
	else if (format[currIndex] == 'h')
		size = SMALL_SIZE;

	if (size == 0)
		*current_index = currIndex - 1;
	else
		*current_index = currIndex;

	return (size);
}
