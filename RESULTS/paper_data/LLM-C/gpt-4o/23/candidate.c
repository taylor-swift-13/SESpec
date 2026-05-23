#include <string.h>

/*@
    requires \valid_read(arg);
    ensures \result == -1 || \result == 0 || \result == 1;
    ensures \result == -1 ==> strlen(arg) < 1;
    ensures \result == 0 ==> (strlen(arg) >= 1 && ((unsigned short)arg[0] > 65535 || ((unsigned short)arg[0] == 65535 && ((unsigned short)arg[0] + 1) == 0)));
    ensures \result == 1 ==> (strlen(arg) >= 1 && (unsigned short)arg[0] <= 65535 && ((unsigned short)arg[0] != 65535 || ((unsigned short)arg[0] + 1) != 0));
    assigns \nothing;
*/
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
