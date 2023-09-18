#include "main.h"

/**
 * get_size - a functions that calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int cur_i = *i + 1;
	int sze = 0;

	if (format[curr_i] == 'l')
		sze = S_LONG;
	else if (format[curr_i] == 'h')
		sze = S_SHORT;

	if (sze == 0)
		*i = cur_i - 1;
	else
		*i = cur_i;

	return (sze);
}
