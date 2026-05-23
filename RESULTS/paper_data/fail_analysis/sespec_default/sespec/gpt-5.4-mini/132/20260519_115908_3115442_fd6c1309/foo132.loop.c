
#include <limits.h>

/*@ 
  logic integer min_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? INT_MIN :
    (a[hi - 1] < min_prefix(a, lo, hi - 1) ? a[hi - 1] : min_prefix(a, lo, hi - 1));
*/

int foo132(int * a, int a_len) {

        if (a_len == 0) return -1;
        int res = INT_MIN;
        
            
        /*@
          loop invariant res == min_prefix(a, 0, i);
          loop invariant \forall integer k; 0 <= k < i ==> res <= a[k];
          loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
          loop invariant (i < a_len) ==> (res == min_prefix(a, 0, i));
          loop invariant (!(i < a_len)) ==> (res == min_prefix(a, 0, a_len));
          loop assigns i, res;
            */
            for(int i = 0; i < a_len; i++) {
            res = ((a[i] < res) ? a[i] : res);
        }
            
        return res;
}
