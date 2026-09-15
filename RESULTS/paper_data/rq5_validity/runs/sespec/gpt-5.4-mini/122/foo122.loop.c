
#include <string.h>

int foo122(const char * s) {

        int n = ((int)strlen(s));

        /*@
          loop invariant 0 <= i;
          loop invariant \forall integer k; 0 <= k < i ==> s[k] == s[n - 1 - k];
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
