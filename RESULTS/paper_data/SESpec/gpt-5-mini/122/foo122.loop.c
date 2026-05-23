
#include <string.h>

/*@
  predicate chars_unchanged(const char *s, integer lo, integer hi) =
    \forall integer k; lo <= k < hi ==> s[k] == \at(s[k], Pre);
*/

/*@
  predicate symmetric_up_to(const char *s, integer n, integer i) =
    \forall integer k; 0 <= k < i ==> s[k] == s[n - 1 - k];
*/
        

int foo122(const char * s) {

        int n = ((int)strlen(s));

        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= i <= (int)strlen(s);
          loop invariant symmetric_up_to(s, n, i);
          loop invariant chars_unchanged(s, 0, (int)strlen(s));
          loop assigns i;
        */
        for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }
            

        return 1;
}
