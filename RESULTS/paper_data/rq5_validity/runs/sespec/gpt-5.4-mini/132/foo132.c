
#include <limits.h>

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures a_len == 0 ==> \result == -1;
  ensures a_len > 0 ==> \result == INT_MIN;
  ensures \result == -1 <==> a_len == 0;
  ensures a_len > 0 ==> \forall integer k; 0 <= k < a_len ==> \result <= a[k];
  ensures \result == (a_len == 0 ? -1 : INT_MIN);
*/
int foo132(int * a, int a_len) {
    /*@ requires a_len >= 0; */

    if (a_len == 0) return -1;
    int res = INT_MIN;
        
    /*@
      loop invariant 0 <= i;
      loop invariant res == INT_MIN;
      loop invariant \forall integer k; 0 <= k < i ==> res <= a[k];
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop assigns i, res;
    */
    for(int i = 0; i < a_len; i++) {
        res = ((a[i] < res) ? a[i] : res);
    }
            
    return res;
}
