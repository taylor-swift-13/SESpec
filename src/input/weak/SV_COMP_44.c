#include <string.h>

int foo44(const char * arg);

int foo44(const char * arg) {

    if (((int)strlen(arg)) < 1)
      return -1;
    char my_char = arg[0];
    int x = my_char;
    if (!(x >= 0 && x <= 0xffff))
      return 0;

    my_char = (char)0xff;
    my_char++;
    if (my_char == 0)
      return 0;
    return 1;
}
