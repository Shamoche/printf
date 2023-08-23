#ifndef MAIN_H
#define MAIN_H
#define BUFFER 1024
#define UNUSED x (void) x

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>


#define FLAG_MINUS 0
#define FLAG_PLUS 1

int myputchar(va_list arg, char buffer[], int flag, int precision, int width, int size);
int mystring(va_list arg, char buffer[], int flag, int precision, int width, int size);
int my_percent(va_list arg, char buffer[], int flag. int precision, int width, int size);

#endif
