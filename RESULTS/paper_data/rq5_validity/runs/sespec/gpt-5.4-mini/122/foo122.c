
#include <string.h>

/*@
  requires \valid_read(s + (0..99));
  requires \exists integer n; 0 <= n < 100 && s[n] == '\0';
  requires \forall integer i; 0 <= i < 100 ==> 0 <= s[i] <= 100;
  assigns \nothing;
*/
int foo122(const char * s) {

        int n = ((int)strlen(s));

        /*@
          loop invariant 0 <= i;
          loop invariant i <= n;
          loop invariant i <= (int)strlen(s);
          loop invariant n == (int)strlen(s);
          loop invariant \forall integer k; 0 <= k < n ==> s[k] == \at(s[k], Pre);
          loop assigns i;
        */
        for(int i = 0; i < ((int)strlen(s)); i++) {
            if(s[i] != s[n - 1 - i]) {
                return 0;
            }
        }

        return 1;
}
