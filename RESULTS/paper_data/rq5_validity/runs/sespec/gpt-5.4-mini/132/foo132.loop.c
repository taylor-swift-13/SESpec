
#include <limits.h>

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
