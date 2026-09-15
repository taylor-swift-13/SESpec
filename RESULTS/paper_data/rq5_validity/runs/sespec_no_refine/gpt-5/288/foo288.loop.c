
#include <stdlib.h>

int foo288(int j) {

    int *ret = (int *)malloc(sizeof(int) * (j + 1));
    int ret_len = j + 1;
    ret[0] = 0;
    ret[1] = 1;
    
    /*@ 
      loop invariant 2 <= p <= j + 1;
      loop invariant ret_len == j + 1;
      loop invariant \valid(ret + (0 .. ret_len-1));
      loop invariant \forall integer k; 0 <= k < 2 ==> ret[k] == \at(ret[k], Pre);
      loop invariant \forall integer k; 2 <= k < p ==> ret[k] == ret[k - 1] + 2 * ret[k - 2];
      loop assigns p, ret[..];
    */
    for (int p = 2; p <= j; p++) {
        ret[p] = ret[p - 1]
                + 2 * ret[p - 2];
    }
        
    return ret[j];
}
