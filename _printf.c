#include "main.h"
/**
 * _printf - function that print anything
 *@format: format pointer
 * by wafa & taha
 * Return: count
 */
int _printf(const char *format, ...)
{
unsigned int count = 0;
va_list args;
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
count += putcharwt(va_arg(args, int));
else if (*format == 's')
{
char *s = va_arg(args, char*);
if (s == NULL)
count += putswt("(null)");
else
count += putswt(s);
}
else if (*format == '%')
count += putcharwt('%');
else
{
putcharwt('%');
putcharwt(*format);
count = +2;
}
}
else
count += putcharwt(*format);
format++;
}
va_end(args);
return (count);
}
