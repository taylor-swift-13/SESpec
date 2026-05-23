#include <string.h>

/*@
    requires \valid_read(s);
    requires \valid_read(t);
    ensures \result == 1 ==> (\forall integer i; 0 <= i < strlen(s) ==> 
                              (\exists integer j; 0 <= j < strlen(t) && s[i] == t[j]));
    ensures \result == 0 ==> (\exists integer i; 0 <= i < strlen(s) && 
                              (\forall integer j; 0 <= j < strlen(t) && s[i] != t[j]));
    assigns \nothing;
*/
int isSubsequence(const char * s, const char * t);

int isSubsequence(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        /*@
            loop invariant 0 <= i <= n;
            loop invariant 0 <= j <= m;
            loop invariant \forall integer k; 0 <= k < i ==> 
                            (\exists integer l; 0 <= l < j && s[k] == t[l]);
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
