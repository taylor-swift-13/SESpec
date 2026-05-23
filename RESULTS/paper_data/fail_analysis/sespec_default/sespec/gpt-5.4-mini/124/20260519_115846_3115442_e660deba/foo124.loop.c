
#include <string.h>

/*@
  logic integer count_matches(char *s, integer lo, integer hi, char c) =
    lo >= hi ? 0
             : count_matches(s, lo, hi - 1, c) + (s[hi - 1] == c ? 1 : 0);
*/

int foo124(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        
            
        /*@
          loop invariant i <= j;
          loop invariant \forall integer k; 0 <= k < n ==> s[k] == \at(s[k], Pre);
          loop invariant \forall integer k; 0 <= k < m ==> t[k] == \at(t[k], Pre);
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
