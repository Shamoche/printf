#include "main.h"

/**
 * _putchar - Writes a character to standard output.
 * @character: The character to be written.
 *
 * Return: On success, the number of characters written (1).
 *         On error, -1 is returned.
 */
int _putchar(char character)
{
    return (write(1, &character, 1));
}

