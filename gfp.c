#include "main.h"

/**
 * get_print - Selects the appropriate printing function based on the conversion specifier.
 * @s: The character holding the conversion specifier.
 *
 * Description: This function iterates through the array of structs, func_arr[],
 *              to find a match between the conversion specifier passed to _printf
 *              and the first element of the struct. It then returns the corresponding
 *              printing function.
 *
 * Return: A pointer to the matching printing function, or NULL if no match is found.
 */
int (*get_print(char s))(va_list, flags_t *)
{
    ph func_arr[] = {
        {'i', print_int},
        {'s', print_string},
        {'c', print_char},
        {'d', print_int},
        {'u', print_unsigned},
        {'x', print_hex},
        {'X', print_hex_big},
        {'b', print_binary},
        {'o', print_octal},
        {'R', print_rot13},
        {'r', print_rev},
        {'S', print_bigS},
        {'p', print_address},
        {'%', print_percent}
    };
    int num_funcs = 14;

    register int i;

    for (i = 0; i < num_funcs; i++)
    {
        if (func_arr[i].c == s)
        {
            return (func_arr[i].f);
        }
    }

    return (NULL);
}

