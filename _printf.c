#include <stdarg.h>
#include <stdio.h>
#include <string.h>
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

	va_start(args, format);
	/*unsigned int count = 0;*/
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				putcharwt(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				putswt(s, stdout);
				count += strlen(s);
			}
			else if (*format == '%')
			{
				putcharwt('%');
				count++;
			}
		}
		else
		{
			putcharwt(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
