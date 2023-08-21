#include "main.h"

/**
 * custom_printf - Custom printf function
 * @format: Pointer to format string
 * Description: Implements some functions of printf
 * Return: Number of characters printed
 */
int custom_printf(const char *format, ...)
{
    const char *fmt_ptr;
    int char_count = 0;
    va_list arg_list;

    if (!format)
        return -1;

    va_start(arg_list, format);
    fmt_ptr = format;

    char_count = process_format_string(arg_list, fmt_ptr);

    va_end(arg_list);
    return char_count;
}

/**
 * process_format_string - Process the format string
 * @arg_list: va_list for arguments
 * @fmt_ptr: Pointer to format string
 * Description: Processes the format string and prints accordingly
 * Return: Total number of characters printed
 */
int process_format_string(va_list arg_list, const char *fmt_ptr)
{
    int i = 0;
    int percent_flag = 0;
    int fmt_char_count = 0;
    int total_char_count = 0;
    int percent_check_result = 0;

    while (i < _strlen((char *)fmt_ptr) && *fmt_ptr != '\0')
    {
        char current_char = fmt_ptr[i];

        if (current_char == '%')
        {
            i++;
            percent_flag++;
            current_char = fmt_ptr[i];

            if (current_char == '\0' && _strlen((char *)fmt_ptr) == 1)
                return -1;

            if (current_char == '\0')
                return total_char_count;

            if (current_char == '%')
            {
                percent_flag++;
            }
            else
            {
                fmt_char_count = handle_format_specifier(current_char, arg_list);

                if (fmt_char_count >= 0 && fmt_char_count != -1)
                {
                    i++;
                    current_char = fmt_ptr[i];
                    if (current_char == '%')
                        percent_flag--;
                    total_char_count += fmt_char_count;
                }
                else if (fmt_char_count == -1 && current_char != '\n')
                {
                    total_char_count += _putchar('%');
                }
            }
        }
        
        percent_check_result = check_and_print_percent(&percent_flag, current_char);
        total_char_count += percent_check_result;

        if (percent_check_result == 0 && current_char != '\0' && current_char != '%')
        {
            total_char_count += _putchar(current_char);
            i++;
        }

        percent_check_result = 0;
    }

    return total_char_count;
}

/**
 * check_and_print_percent - Check for and print '%'
 * @percent_flag: Pointer to percent_flag
 * @current_char: Current character
 * Description: Checks for and prints '%' character
 * Return: Number of characters printed for '%'
 */
int check_and_print_percent(int *percent_flag, char current_char)
{
    int tmp_percent_flag;
    int char_count = 0;

    tmp_percent_flag = *percent_flag;

    if (tmp_percent_flag == 2 && current_char == '%')
    {
        _putchar('%');
        tmp_percent_flag = 0;
        char_count = 1;
    }

    return char_count;
}

/**
 * call_function_manager - Call the function manager
 * @aux: Character parameter
 * @arg: va_list argument
 * Description: Calls the function manager and returns character count
 * Return: Number of characters printed
 */
int call_function_manager(char aux, va_list arg)
{
    int char_count = 0;

    char_count = handle_format_specifier(aux, arg);
    return char_count;
}

