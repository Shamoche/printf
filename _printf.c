#include "main.h"

/**
 * _custom_printf - custom implementation of the printf function
 * @format: the format specifier
 * Return: the number of characters printed
 */

int _custom_printf(const char *format, ...)
{
    int printed = 0;

    va_list args;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            printed = format_handler(format, args, printed);
            format++;
        }
        else
        {
            _putchar(*format);
            printed++;
            format++;
        }
    }
    va_end(args);
    return (printed);
}

