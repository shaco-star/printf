#include "main.h"

#define _MINUS 1
#define _PLUS 2
#define _HASH 8
#define _ZERO 4
#define _SPACE 16

/**
 * get_flags - Calculates flags
 * @format: Formatted string
 * @i: parameter
 * Return: Flags
 */

int get_flags(const char *format, int *i) {
        int j, cr;
        int flags = 0;
        const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
        const int FLAGS_ARR[] = {_MINUS, _PLUS, _ZERO, _HASH, _SPACE, 0};
        for (cr = *i + 1; format[cr] != '\0'; cr++) {
                for (j = 0; FLAGS_CH[j] != '\0'; j++)
                        if (format[cr] == FLAGS_CH[j]) {
                                flags |= FLAGS_ARR[j];
                                break;
                        }
                if (FLAGS_CH[j] == 0)
                        break;
        }
        *i = cr - 1;
        return (flags);
}
