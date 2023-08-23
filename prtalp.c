#include "main.h"

/**
 * print_string - Prints each character of a string.
 * @l: The va_list containing arguments from _printf.
 * @f: A pointer to the flags struct that determines whether a flag is passed to _printf.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list l, flags_t *f)
{
    char *s = va_arg(l, char *);

    (void)f;

    if (!s)
        s = "(null)";
    
    return (_puts(s));
}

/**
 * print_char - Prints a character.
 * @l: The va_list containing arguments from _printf.
 * @f: A pointer to the flags struct that determines whether a flag is passed to _printf.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list l, flags_t *f)
{
    (void)f;
    _putchar(va_arg(l, int));
    return (1);
}

