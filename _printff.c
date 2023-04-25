#include "main.h"

/**
 * _printf - function that prints anything
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0, number;
    char *s, buffer[1024];
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    count += putcharwt(va_arg(args, int));
                    break;

                case 's':
                    s = va_arg(args, char *);
                    if (s == NULL)
                        count += putswt("(null)");
                    else
                        count += putswt(s);
                    break;

                case '%':
                    count += putcharwt('%');
                    break;

                case 'd':
                case 'i':
                    number = va_arg(args, int);
                    sprintf(buffer, "%d", number);
                    count += putswt(buffer);
                    break;

                default:
                    putcharwt('%');
                    putcharwt(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            count += putcharwt(*format);
        }

        format++;
    }

    va_end(args);

    return (count);
}
