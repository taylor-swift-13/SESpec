#include <string.h>

/*@
    requires \valid_read(s1 + (0 .. strlen(s1)));
    requires \valid_read(s2 + (0 .. strlen(s1)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int f(const char *s1, const char *s2);

 /*@
    requires \valid_read(s1 + (0 .. strlen(s1)));
    requires \valid_read(s2 + (0 .. strlen(s1)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int f(const char *s1, const char *s2) {
    int i = 0;
    /*@
        loop invariant -1 <= count < (int)strlen(s1);
        loop invariant 0 <= i <= (int)strlen(s1);
        loop assigns count, i;
        loop variant count + 1;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}
