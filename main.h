#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define NOT_USED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_V1 1
#define FLAG_V2 2
#define FLAG_V4 4
#define HASH_Flag 8
#define SPACE_FLAG 16

/* SIZES */
#define LARGE_SIZE 2
#define SMALL_SIZE 1


/* specifiers handler*/
int read_active_flags(const char *format, int *index);
int calculate_width(const char *format, int *index, va_list list);
int calculate_precision(const char *format, int *index, va_list list);
int calculate_size(const char *format, int *index);
void write_buffer(char buffer[], int *buff_ind);


int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
#endif
