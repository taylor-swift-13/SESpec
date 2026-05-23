
#include <string.h>
#include <stddef.h>

/*@ 
  logic integer cnt_char(char *a, integer lo, integer hi, integer c) =
    lo >= hi ? 0
             : cnt_char(a, lo, hi - 1, c) + ((a[hi - 1] == (char)c) ? 1 : 0);
*/

/*@
  requires \valid_read(s);
  requires \valid_read(t);
  // Strengthen preconditions to establish loop bounds on i and j
  // by ensuring the computed lengths are non-negative as integers.
  requires (int)strlen(s) >= 0;
  requires (int)strlen(t) >= 0;
*/
int foo124(const char * s, const char * t) {

    int n = ((int)strlen(s)), m = ((int)strlen(t));
    int i = 0, j = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= j <= m;
      loop invariant i <= j;

      loop invariant \forall integer k; 0 <= k < n ==> s[k] == \at(s[k], Pre);
      loop invariant \forall integer k; 0 <= k < m ==> t[k] == \at(t[k], Pre);

      loop invariant \forall integer v; -128 <= v < 128 ==>
        cnt_char((char*)t, 0, j, v) >= cnt_char((char*)s, 0, i, v);

      loop invariant (!(i < n && j < m)) ==> (i >= n || j >= m);

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
