
#include <string.h>

/*@ predicate prefix_pal{L}(char *s, integer n, integer i) =
      \forall integer k; 0 <= k < i ==> s[k] == s[n - 1 - k]; */

int foo122(const char * s) {

        int n = ((int)strlen(s));

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == ((int)strlen(s));
          loop invariant \forall integer k; 0 <= k < i ==> 0 <= n - 1 - k < n;
          loop invariant i == 0 || (\exists integer k; 0 <= k < i && s[k] == s[n - 1 - k]);
          loop invariant (i < ((int)strlen(s))) ==> (0 <= i && i < n && 0 <= n - 1 - i && n - 1 - i < n);
          loop invariant \forall integer k; 0 <= k < n ==> s[k] == \at(s[k], Pre) ;
          loop assigns i;
            */
            for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }
            

        return 1;
}
