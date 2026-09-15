
#include <limits.h>

/*@ 
  logic integer max_prefix(int* a, integer n) =
    n <= 0 ? INT_MIN
           : (max_prefix(a, n - 1) < a[n - 1] ? a[n - 1] : max_prefix(a, n - 1));
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
