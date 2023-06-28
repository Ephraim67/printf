#include "main.h"

/**
 * calculate_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @index: Current index in the format string
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int calculate_precision(const char *format, int *index, va_list list)
{
	int currIndex = *index + 1;
	int precision = -1;

	if (format[currIndex] != '.')
		return (precision);
	precision = 0;
	for (currIndex += 1; format[currIndex] != '\0'; currIndex++)
	{
		if (is_digit(format[currIndex]))
		{
			precision *= 10;
			precision += format[currIndex] - '0';
		}
		else if (format[currIndex] == '*')
		{
			currIndex++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
}
	*index = currIndex - 1;
	return (precision);
}
