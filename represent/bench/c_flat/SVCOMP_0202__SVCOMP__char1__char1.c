#include <string.h>

int fun(const char * arg);

int fun(const char * arg) {

    if (((int)strlen(arg)) < 1)
      return -1;
    char my_char = arg[0);
    int x = my_char;
    if (!(x >= 0 && x <= '\uffff'))
      return 0;

    my_char = '\uffff';
    my_char++;
    if (my_char == 0)
      return 0;
    return 1;
}
