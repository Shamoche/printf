#include "main.h"

/**
 * print_hex - Prints a number in hexadecimal base, in lowercase.
 * @l: The va_list containing arguments from _printf.
 * @f: A pointer to the flags struct that determines whether a flag is passed to _printf.
 *
 * Description: The function calls convert() to convert the input number into
 *              the correct base and returns it as a string.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 16, 1);
    int count = 0;

    if (f->hash == 1 && str[0] != '0')
        count += _puts("0x");
    count += _puts(str);

    return (count);
}

/**
 * print_hex_big - Prints a number in hexadecimal base, in uppercase.
 * @l: The va_list containing arguments from _printf.
 * @f: A pointer to the flags struct that determines whether a flag is passed to _printf.
 *
 * Description: The function calls convert() to convert the input number into
 *              the correct base and returns it as a string.
 *
 * Return: The number of characters printed.
 */
int print_hex_big(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 16, 0);
    int count = 0;

    if (f->hash == 1 && str[0] != '0')
        count += _puts("0X");
    count += _puts(str);

    return (count);
}

/**
 * print_binary - Prints a number in binary (base 2).
 * @l: The va_list containing arguments from _printf.
 * @f: A pointer to the flags struct that determines whether a flag is passed to _printf.
 *
 * Description: The function calls convert() to convert the input number into
 *              the correct base and returns it as a string.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 2, 0);

    (void)f;
    return (_puts(str));
}

/**
 * print_octal - Prints a number in octal (base 8).
 * @l: The va_list containing arguments from _printf.
 * @f: A pointer to the flags struct that determines whether a flag is passed to _printf.
 *
 * Description: The function calls convert() to convert the input number into
 *              the correct base and returns it as a string.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list l, flags_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 8, 0);
    int count = 0;

    if (f->hash == 1 && str[0] != '0')
        count += _putchar('0');
    count += _puts(str);

    return (count);
}

