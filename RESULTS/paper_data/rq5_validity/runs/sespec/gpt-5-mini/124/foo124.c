
#include <string.h>

/*@
  requires \exists integer ls; ls >= 0 && \valid_read(s + (0 .. ls)) && s[ls] == '\0';
  requires \exists integer lt; lt >= 0 && \valid_read(t + (0 .. lt)) && t[lt] == '\0';
  assigns \nothing;
*/
int foo124(const char * s, const char * t) {

        int n = ((int)strlen(s)), m = ((int)strlen(t));
        int i = 0, j = 0;

        /*@
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
