#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    count += printf("%c", va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(*format);
                    break;
            }
        }
        else
        {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return (count);
}
