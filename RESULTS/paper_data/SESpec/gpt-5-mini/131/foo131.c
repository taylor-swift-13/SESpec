
#include <limits.h>

/*@
  logic integer prefix_max(int *a, integer lo, integer hi) =
    lo >= hi ? INT_MIN
             : ( a[hi-1] > prefix_max(a, lo, hi-1) ? a[hi-1] : prefix_max(a, lo, hi-1) );
*/

/*@
  requires \valid_read(a + (0..a_len-1));
  requires a_len >= 0;
  assigns \nothing;
  ensures (a_len == 0) ==> \result == -1;
  ensures (a_len > 0) ==> \result == prefix_max(a, 0, a_len);
  ensures \result >= INT_MIN;
  ensures \forall integer k; 0 <= k < a_len ==> a[k] <= \result;
*/
int foo131(int * a, int a_len) {

    if (a_len == 0) return -1;
    int res = INT_MIN;
    
    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant res == prefix_max(a, 0, i);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop invariant \forall integer k; 0 <= k < i ==> a[k] <= res;
      loop assigns i, res;
    */
    for(int i = 0; i < a_len; i++) {
        res = ((a[i] > res) ? a[i] : res);
    }
        
    return res;
}
