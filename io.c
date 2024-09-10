
#include <errno.h>
#include <unistd.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char () {
    char c;
    ssize_t input = read(STDIN_FILENO, &c, 1);
    if (input == 0 || input == -1) {
        return EOF;
    } else {
        return c;
    }
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
    ssize_t result = write(STDOUT_FILENO, &c ,1);
    if(result == 1){
        return 0;
    }else {
        return EOF;
    }
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
    while (*s != '\0') {
        if(write_char(*s) == EOF){
            return EOF;
        }
        s++;
    }
    return 0;
}

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
    char buffer[12];
    int i = 0;

    if (n == 0) {
        if (write_char('0') == EOF) {
            return EOF;
        }
        return 0;
    }

    while (n > 0) {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i > 0) {
        if (write_char(buffer[--i]) == EOF) {
            return EOF;
        }
    }

    return 0;
}
