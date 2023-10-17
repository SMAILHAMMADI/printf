#include "main.h"
#include <stdarg.h>
#include <unistd.h>

void p(char b[], int *b_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, b_ind = 0;
	va_list args;
	char b[B_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			b[b_ind++] = format[i];
			if (b_ind == B_SIZE)
				p(b, &b_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			p(b, &b_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	p(b, &b_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @b: Array of chars
 * @b_ind: Index at which to add next char, represents the length.
 */
void p(char b[], int *b_ind)
{
	if (*b_ind > 0)
		write(1, &b[0], *b_ind);

	*b_ind = 0;
}

