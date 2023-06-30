#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

 /* _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	char c, *s, buffer[16];
	int index = 0, num;
	int count = 0;

va_start(args, format);
while (*format != '\0')
{
	if (*format == '%')
	{
		format++;
		/** Handle the conversion specifier*/
		switch (*format)
		{
			case 'c':
				{
					c = va_arg(args, int);
					count += _putchar(c);
					break;
				}
			case 's':
				{
					s = va_arg(args, char*);
					if (s == NULL)
						s = "(null)";
					while (*s != '\0')
					{
						count += _putchar(*s);
						s++;
					}
					break;
				}
			case '%':
				count += _putchar('%');
				break;
			case 'd':
			case 'i':
				{
					num = va_arg(args, int);
					if (num < 0)
					{
						count += _putchar('-');
						num = -num;
					}
					/** Print the digits in reverse order*/
					index = 0;
					if (num == 0)
						buffer[index++] = '0';
					else
					{
						while (num != 0)
						{
							buffer[index++] = '0' + (num % 10);
							num /= 10;
						}
					}
					while (index > 0)
					{
						count += _putchar(buffer[--index]);
					}
					break;
				}
			case 'u':
				{
					unsigned int num1 = va_arg(args, unsigned int);
					char buffer[16];
					int index = 0;
					if (num1 == 0)
					{
						buffer[index++] = '0';
					}
					else
					{
						while (num1 != 0)
						{
							buffer[index++] = '0' + (num1 % 10);
							num1 /= 10;
						}
					}
					while (index > 0)
					{
						count += _putchar(buffer[--index]);
					}
					break;
				}
			case 'o':
				{
					unsigned int num = va_arg(args, unsigned int);
					char buffer[16];
					int index = 0;
					if (num == 0)
					{
						buffer[index++] = '0';
					}
					else
					{
						while (num != 0)
						{
							buffer[index++] = '0' + (num % 8);
							num /= 8;
						}
					}
					while (index > 0)
					{
						count += _putchar(buffer[--index]);
					}
					break;
				}
			case 'x':
				{
					unsigned int num = va_arg(args, unsigned int);
					char buffer[16];
					int index = 0;
					if (num == 0)
					{
						buffer[index++] = '0';
					}
					else
					{
						while (num != 0)
						{
							int digit = num % 16;
							buffer[index++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
							num /= 16;
						}
					}
					while (index > 0)
					{
						count += _putchar(buffer[--index]);
					}
					break;
				}
			case 'X':
				{
					unsigned int num = va_arg(args, unsigned int);
					char buffer[16];
					int index = 0;
					if (num == 0)
					{
						buffer[index++] = '0';
					}
					else
					{
						while (num != 0)
						{
							int digit = num % 16;
							buffer[index++] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
							num /= 16;
						}
					}
					while (index > 0)
					{
						count += _putchar(buffer[--index]);
					}
					break;
				}
			default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
		}
	}
	else
	{
		count += _putchar(*format);
	}
	format++;
}
va_end(args);
return (count);
}
