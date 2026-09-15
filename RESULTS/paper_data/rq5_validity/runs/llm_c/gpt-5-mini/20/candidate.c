#include <string.h>

/*@
    requires \valid_read(s1 + (0 .. (int)strlen(s1)));
    requires \valid_read(s2 + (0 .. ((int)strlen(s1) - 1)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
    ensures \result == 0 <==> (\exists integer i; 0 <= i < (int)strlen(s1) &&
                                s1[(int)strlen(s1) - 1 - i] == s2[i]);
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (int)strlen(s1) ==>
                                s1[(int)strlen(s1) - 1 - i] != s2[i]);
*/
int f(const char *s1, const char *s2);

int f(const char *s1, const char *s2) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= (int)strlen(s1);
        loop invariant -1 <= count <= (int)strlen(s1) - 1;
        loop invariant count + i == (int)strlen(s1) - 1;
        loop invariant \forall integer k; 0 <= k < i ==>
                       s1[(int)strlen(s1) - 1 - k] != s2[k];
        loop assigns count, i;
        loop variant count + 1;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}
