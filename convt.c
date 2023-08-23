#include "main.h"

/**
 * convert - Converts a number from a given base into a string representation.
 * @num: The input number to be converted.
 * @base: The input base for conversion.
 * @lowercase: Flag indicating whether hex values should be in lowercase.
 * Return: A string representing the converted number.
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char *rep;
    static char buffer[50];
    char *ptr;

    rep = (lowercase)
        ? "0123456789abcdef"
        : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';
    do {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}

