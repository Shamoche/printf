#include "main.h"

/**
 * _custom_putchar - writes a single character to the standard output
 * @character: The character to be written
 * Return: On success, returns 1. On error, returns -1.
 */

int _custom_putchar(char character)
{
    return (write(1, &character, 1));
}

