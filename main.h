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
#define HASH_FLAG 8
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
int is_digit(char c);

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int _putchar(char c);


/**

 * struct fmt - Struct op

 *

 * @ght: The format.

 * @fn: The function associated.

 */

struct ght

{

	char ght;

	int (*fn)(va_list, char[], int, int, int, int);

};





/**

 * typedef struct fmt fmt_t - Struct op

 *

 * @ght: The format.

 * @gh_t: The function associated.

 */

typedef struct ght ght_t;



int _printf(const char *format, ...);

int handle_print(const char *ght, int *i,

va_list list, char buffer[], int flags, int width, int precision, int size);




/* Funtions to print chars and strings */

int print_char(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int print_percent(va_list types, char buffer[],

	int flags, int width, int precision, int size);



/* Functions to print numbers */

int print_int(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int print_binary(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int print_unsigned(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int print_octal(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int print_hexadecimal(va_list types, char buffer[],

	int flags, int width, int precision, int size);

int print_hexa_upper(va_list types, char buffer[],

	int flags, int width, int precision, int size);



int print_hexa(va_list types, char map_to[],

char buffer[], int flags, char flag_ch, int width, int precision, int size);



/* Function to print non printable characters */

int print_non_printable(va_list types, char buffer[],

	int flags, int width, int precision, int size);



/* Funcion to print memory address */

int print_pointer(va_list types, char buffer[],

	int flags, int width, int precision, int size);



/* Funciotns to handle other specifiers */

int get_flags(const char *format, int *i);

int get_width(const char *format, int *i, va_list list);

int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i);



/*Function to print string in reverse*/

int print_reverse(va_list types, char buffer[],

	int flags, int width, int precision, int size);



/*Function to print a string in rot 13*/

int print_rot13string(va_list types, char buffer[],

	int flags, int width, int precision, int size);



/* width handler */

int handle_write_char(char c, char buffer[],

	int flags, int width, int precision, int size);

int write_number(int is_positive, int ind, char buffer[],

	int flags, int width, int precision, int size);

int write_num(int ind, char bff[], int flags, int width, int precision,

	int length, char padd, char extra_c);

int write_pointer(char buffer[], int ind, int length,

	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,

#endif /* MAIN_H */

