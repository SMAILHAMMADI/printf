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
va_list arg;
int count = 0;
va_start(arg, format);
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
char c = va_arg(arg, int);
putchar(c);
count++;
break;
}
case 's':
{
char *s = va_arg(arg, char *);
if (s == NULL)
str = "(null)";
while (*s)
{
putchar(*s);
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
va_end(arg);
return (count);
}
