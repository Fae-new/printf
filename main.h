#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void print_binary(unsigned int num);
char *int_to_string(int num);
int printstr(char *str);
int print(const char *format, va_list args);
int _printf(const char *format, ...);
#endif
