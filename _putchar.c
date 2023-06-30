#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/* _putchar - Prints the contents of the buffer if it exist
 * @c: chars
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
