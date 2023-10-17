#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format != '%')
{
putchar(*format);
count++;
}
else
{
format++; /* Move past '%' */
switch (*format)
{
case 'c':
{
char c = va_arg(args, int);
putchar(c);
count++;
break;
}
case 's':
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
putchar(*str);
str++;
count++;
}
break;
}
case '%':
{
putchar('%');
count++;
break;
}
default:
{
putchar('%');
count++;
if (*format)
putchar(*format);
else
break;
count++;
break;
}
}
}
format++;
}

va_end(args);
return (count);
}
