#include "main.h"

/**
 * convert - Convert a number into a string representation using the given base.
 * @num: The input number to be converted.
 * @base: The base for conversion (e.g., decimal, hexadecimal).
 * @lowercase: Flag indicating if hexadecimal letters should be lowercase.
 *
 * Return: A string containing the converted representation of the number.
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char *representation;
    static char buffer[50];
    char *result_ptr;

    representation = (lowercase)
                     ? "0123456789abcdef"
                     : "0123456789ABCDEF";

    result_ptr = &buffer[49];
    *result_ptr = '\0';

    do {
        *--result_ptr = representation[num % base];
        num /= base;
    } while (num != 0);

    return (result_ptr);
}

