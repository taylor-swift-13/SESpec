
#include <string.h>

/*@ requires valid_string(s1);
    requires valid_string(s2);
    requires (int)strlen(s1) <= INT_MAX;
    requires (int)strlen(s2) >= (int)strlen(s1);
    assigns \nothing;
*/
int foo20(const char *s1, const char *s2) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i;
      loop invariant count <= (int)strlen(s1) - 1;
      loop invariant i == ((int)strlen(s1) - 1) - count;
      loop invariant \forall integer p; 0 <= p <= (int)strlen(s1) ==> s1[p] == \at(s1[p], Pre);
      loop invariant \forall integer q; 0 <= q <= (int)strlen(s2) ==> s2[q] == \at(s2[q], Pre);
      loop assigns count, i;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
            
    return 1;
}
