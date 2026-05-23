#include <string.h>

/*@
  predicate subseq_n{L}(char *s, char *t, integer n, integer m) =
    n == 0
    || (m > 0 &&
        ( (s[0] == t[0] && subseq_n(s+1, t+1, n-1, m-1))
          || subseq_n(s, t+1, n, m-1) ));
*/

/*@
    requires s != \null && t != \null;
    requires \valid_read(s + (0 .. \strlen(s)));
    requires \valid_read(t + (0 .. \strlen(t)));
    assigns \nothing;
    ensures \result == 1 <==> subseq_n(s, t, \strlen(s), \strlen(t));
    ensures \result == 0 <==> !subseq_n(s, t, \strlen(s), \strlen(t));
*/
int isSubsequence(const char * s, const char * t);

int isSubsequence(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        /*@
            loop invariant 0 <= i <= n;
            loop invariant 0 <= j <= m;
            loop invariant subseq_n((char*)s, (char*)t, i, j);
            loop assigns i, j;
            loop variant m - j;
        */
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == n;
}
