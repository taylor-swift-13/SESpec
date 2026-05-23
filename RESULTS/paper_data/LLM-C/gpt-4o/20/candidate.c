#include <string.h>

/*@
    requires \valid_read(s1);
    requires \valid_read(s2);
    requires \valid_read(s1 + (0 .. strlen(s1)));
    requires \valid_read(s2 + (0 .. strlen(s2)));
    ensures \result == 0 ==> \exists integer i, j; 0 <= i < strlen(s1) && 0 <= j < strlen(s2) && s1[strlen(s1) - 1 - i] == s2[j];
    ensures \result == 1 ==> \forall integer i, j; 0 <= i < strlen(s1) && 0 <= j < strlen(s2) ==> s1[strlen(s1) - 1 - i] != s2[j];
    assigns \nothing;
*/
int f(const char *s1, const char *s2) {
    int i = 0;
    /*@
    loop invariant 0 <= count + 1 <= (int)strlen(s1);
    loop invariant 0 <= i <= (int)strlen(s2);
    loop assigns count, i;
    loop invariant \forall integer k; count + 1 <= k < (int)strlen(s1) ==> s1[k] != s2[k - count - 1];
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
    return 1;
}
