#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - Structure to hold various flags for formatting.
 * @plus: Flag for positive number formatting.
 * @space: Flag for space formatting.
 * @hash: Flag for hash formatting.
 */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flags_t;

/**
 * struct printHandler - Structure to map format specifiers to functions.
 * @c: Format specifier character.
 * @f: Function pointer for corresponding specifier.
 */
typedef struct printHandler
{
    char c;
    int (*f)(va_list ap, flags_t *f);
} ph;

/* Number Printing */
int print_integer(va_list l, flags_t *f);
void display_number(int n);
int print_unsigned_integer(va_list l, flags_t *f);
int digit_count(int i);

/* Base Printing */
int print_hexadecimal(va_list l, flags_t *f);
int print_big_hexadecimal(va_list l, flags_t *f);
int print_binary_representation(va_list l, flags_t *f);
int print_octal_representation(va_list l, flags_t *f);

/* Conversion */
char *convert_to_base(unsigned long int num, int base, int lowercase);

/* Printf */
int custom_printf(const char *format, ...);

/* Function Selector */
int (*select_print_function(char s))(va_list, flags_t *);

/* Flag Getter */
int get_flag_value(char s, flags_t *f);

/* Alphabetic Printing */
int print_text(va_list l, flags_t *f);
int print_character(va_list l, flags_t *f);

/* Write Operations */
int print_character_to_output(char c);
int print_string_to_output(char *str);

/* Custom Printing */
int print_rotated_text(va_list l, flags_t *f);
int print_reversed_text(va_list l, flags_t *f);
int print_big_text(va_list l, flags_t *f);

/* Address Printing */
int print_memory_address(va_list l, flags_t *f);

/* Percentage Printing */
int print_percentage_symbol(va_list l, flags_t *f);

#endif /* MAIN_H */

