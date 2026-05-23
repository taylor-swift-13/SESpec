#include <string.h>

/*@
    requires \valid_read(s1 + (0 .. \strlen(s1)));
    assigns \nothing;
    ensures \result == (((int)\strlen(s1)) == 24);
*/
int f(const char * s1);

int f(const char * s1) {

    return ((int)strlen(s1)) == 24;
}
