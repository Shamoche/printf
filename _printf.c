#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: a character string containing zero or more directives.
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    int i, count = 0;
    char *s;
    va_list args;

    va_start(args, format);

    for (i = 0; format && format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    s = va_arg(args, char *);
                    if (!s)
                        s = "(null)";
                    count += printf("%s", s);
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(format[i]);
                    break;
            }
        }
        else
        {
            count += putchar(format[i]);
        }
    }

    va_end(args);

    return count;
}

