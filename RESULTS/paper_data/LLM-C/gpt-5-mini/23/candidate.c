#include <string.h>

/*@
    requires \valid_read(arg + (0 .. \strlen(arg)));
    assigns \nothing;
    behavior empty:
        assumes \strlen(arg) < 1;
        ensures \result == -1;
    behavior non_empty:
        assumes \strlen(arg) >= 1;
        ensures \result == 0;
    complete behaviors empty, non_empty;
    disjoint behaviors empty, non_empty;
*/
int fun(const char *arg);

int fun(const char *arg) {
    if (((int)strlen(arg)) < 1) return -1;
    unsigned short my_char = (unsigned short)arg[0];
    int x = my_char;
    if (!(x >= 0 && x <= 65535)) return 0;
    my_char = 65535;
    my_char++;
    if (my_char == 0) return 0;
    return 1;
}
