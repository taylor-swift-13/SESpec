
#include <limits.h>

/*@
  logic integer min_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 2147483647
             : (min_prefix(a, lo, hi - 1) < a[hi - 1] ? min_prefix(a, lo, hi - 1) : a[hi - 1]);
*/

/*@
  requires \valid_read(a + (0..a_len-1));
  requires a_len >= 0;
  assigns \nothing;
  ensures a_len == 0 ==> \result == -1;
  ensures a_len > 0  ==> \result == (min_prefix(a, 0, a_len) < INT_MIN ? min_prefix(a, 0, a_len) : INT_MIN);
*/
int foo55(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        
        /*@
          loop invariant 0 <= i <= a_len;
          loop invariant res == (i == 0
                                 ? INT_MIN
                                 : (min_prefix(a, 0, i) < INT_MIN ? min_prefix(a, 0, i) : INT_MIN));
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop assigns i, res;
        */
        for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
            
        return res;
}
