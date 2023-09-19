#include "main.h"

/**
 * get_width - a functions that calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: the width
 */
int get_width(const char *format, int *i, va_list list)
{
	int cur_i;
	int width = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			width *= 10;
			width += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (width);
}
