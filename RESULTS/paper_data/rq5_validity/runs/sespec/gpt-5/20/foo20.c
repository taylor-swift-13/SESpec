
#include <string.h>

/*@
  requires \valid(s1);
  requires \valid(s2);
  assigns \nothing;
  ensures \result == 0 ==> \forall integer k; k >= 0 ==> s1[k] == \at(s1[k], Pre);
  ensures \result == 0 ==> \forall integer k; k >= 0 ==> s2[k] == \at(s2[k], Pre);
  ensures \result == 1 ==> \forall integer k; k >= 0 ==> s1[k] == \at(s1[k], Pre);
  ensures \result == 1 ==> \forall integer k; k >= 0 ==> s2[k] == \at(s2[k], Pre);
*/
int foo20(const char *s1, const char *s2) {
    int i = 0;
    
    /*@
      loop invariant 0 <= i;
      loop invariant i + count == (int)strlen(s1) - 1;
      loop invariant \forall integer k; k >= 0 ==> s2[k] == \at(s2[k], Pre);
      loop invariant \forall integer k; k >= 0 ==> s1[k] == \at(s1[k], Pre);
      loop assigns count, i;
    */
    for (int count = ((int)strlen(s1)) - 1; count >= 0; count--) {
        if (s1[count] == s2[i]) return 0;
        ++i;
    }
            
    return 1;
}
