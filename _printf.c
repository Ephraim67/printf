#include "main.h"
 
/* print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffer_index: Index at which to add next char, represents the length.
 */
void write_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);
	*buffer_index = 0;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, output = 0, output_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
				write_buffer(buffer, &buffer_index);
			/* write(1, &format[i], 1);*/
			output_chars++;
		}
		else
		{
			write_buffer(buffer, &buffer_index);
			flags = read_active_flags(format, &i);
			width = calculate_width(format, &i, args);
			precision = calculate_precision(format, &i, args);
			size = calculate_size(format, &i);
			++i;
			output = print_handler(format, &i, args, buffer,
				flags, width, precision, size);
			if (output == -1)
				return (-1);
			output_chars += output;
		}
}

	write_buffer(buffer, &buffer_index);

	va_end(args);

	return (output_chars);
}


