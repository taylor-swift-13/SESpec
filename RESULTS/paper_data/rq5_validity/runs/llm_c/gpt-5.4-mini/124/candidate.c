#include <string.h>

/*@
    requires s != \null;
    requires t != \null;
    requires \valid_read(s + (0 .. strlen(s)));
    requires \valid_read(t + (0 .. strlen(t)));
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int isSubsequence(const char * s, const char * t);

int isSubsequence(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        /*@
            loop invariant 0 <= i <= n;
            loop invariant 0 <= j <= m;
            loop invariant i <= j;
            loop assigns i, j;
            loop variant (n - i) + (m - j);
        */
        while (i < n && j < m) {
            if (s[i) == t[j)) {
                i++;
            }
            j++;
        }
        return i == n;
}
