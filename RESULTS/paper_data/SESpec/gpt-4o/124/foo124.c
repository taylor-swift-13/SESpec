
#include <string.h>

/*@
  logic integer prefix_match(const char* s, const char* t, integer n, integer m) =
    n == 0 || m == 0 ? 0
                     : (s[0] == t[0] ? 1 + prefix_match(s + 1, t + 1, n - 1, m - 1)
                                     : prefix_match(s + 1, t + 1, n - 1, m - 1));
*/

/*@
  requires \valid(s);
  requires \valid(t);
  assigns \nothing;
  ensures \result == 1 <==> (\forall integer k; 0 <= k < strlen(s) ==> s[k] == t[k]);
  ensures \result == 0 <==> (\exists integer k; 0 <= k < strlen(s) && s[k] != t[k]);
*/
int foo124(const char * s, const char * t) {

    int n = ((int)strlen(s)), m = ((int)strlen(t));
    int i = 0, j = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= j <= m;
      loop invariant \forall integer k; 0 <= k < i ==> s[k] == t[k];
      loop invariant \forall integer k; 0 <= k < n ==> s[k] == \at(s[k], Pre);
      loop invariant \forall integer k; 0 <= k < m ==> t[k] == \at(t[k], Pre);
      loop invariant prefix_match(s, t, i, j) == i;
      loop invariant (i < n && j < m) ==> (s[i] != t[j] ==> prefix_match(s, t, i, j) == i);
      loop invariant (!(i < n && j < m)) ==> (prefix_match(s, t, i, j) == i);
      loop assigns i, j;
    */
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == n;
}
