#ifndef _PRINTF
#define _PRINTF

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int _printf(const char *format, ...);

#endif
