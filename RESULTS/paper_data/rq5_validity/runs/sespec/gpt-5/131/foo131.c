
#include <limits.h>

/*@ 
  logic integer max_prefix(int* a, integer n) =
    n <= 0 ? INT_MIN
           : (max_prefix(a, n - 1) < a[n - 1] ? a[n - 1] : max_prefix(a, n - 1));
*/

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures (a_len == 0) ==> \result == -1;
  ensures (a_len > 0) ==> \forall integer k; 0 <= k < a_len ==> a[k] <= \result;
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
  ensures \result == \result;
*/
int foo131(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> a[k] <= res;
          loop assigns i, res;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] > res) ? a[i] : res);
        }
            
        return res;
}
