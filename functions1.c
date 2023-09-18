#include "main.h"

/************************* PRINTS UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Print an unsigned number
 * @types: List arguments
 * @buffer: Buffer array to handle print
 * @flags:  To calculate active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specified
 * Return: Number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = (num % 10) + '0';
		num /= 10;
	}

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}

/************* PRINTS UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Print an unsigned number in octal notation
 * @types: List arguments
 * @buffer: Buffer array to handle print
 * @flags:  To calculate active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specified
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[c--] = '0';

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}

/************** PRINTS UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Print an unsigned number in hexadecimal notation
 * @types: List arguments
 * @buffer: Buffer array to handle print.
 * @flags:  To calculate active flags
 * @width: Get width.
 * @precision: Precision specification.
 * @size: Size specified
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINTS UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Print an unsigned number in upper hexadecimal notation
 * @types: List arguments
 * @buffer: Buffer array to handle print.
 * @flags:  To calculate active flags
 * @width: Get width.
 * @precision: Precision specification.
 * @size: Size specified
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINTS HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Print a hexadecimal number in lower or upper
 * @types: List arguments
 * @map_to: Array of values to which to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  To calculate active flags.
 * @flag_ch: To calculate active flags.
 * @width: Get width.
 * @precision: Precision specification.
 * @size: Size specified
 * @size: Size specification.
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[c--] = map_to[num % 16];
		num /= 6;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[c--] = flag_ch;
		buffer[c--] = '0';
	}

	c++;

	return (write_unsgnd(0, c, buffer, flags, width, precision, size));
}


