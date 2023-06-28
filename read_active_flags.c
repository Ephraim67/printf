#include "main.h"

/**
 * read_active_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @currentIndex: take a parameter.
 * Return: Flags:
 */
int read_active_flags(const char *format, int *currentIndex)
{
	int j, currentIdx;
	int flags = 0;
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {FLAG_V1, FLAG_V2, FLAG_V4, HASH_FLAG, SPACE_FLAG, 0};

	for (currentIdx = *currentIndex + 1; format[currentIdx] != '\0'; currentIdx++)
	{
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
			if (format[currentIdx] == FLAGS_CHARS[j])
			{
				flags |= FLAGS_VALUES[j];
				break;
			}

		if (FLAGS_CHARS[j] == 0)
break;
	}
	*currentIndex = currentIdx - 1;
	return (flags);
}
