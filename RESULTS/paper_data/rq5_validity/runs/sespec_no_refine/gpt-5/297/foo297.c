
#include <stdlib.h>

/*@
  ensures \result == fib(seed);
  assigns \nothing;
*/
int foo297(int seed) {

    int *result = (int *)malloc(sizeof(int) * (seed + 1));
    int result_len = seed + 1;
    result[0] = 2;
    result[1] = 1;
    
            
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant 2 <= l <= result_len;
      loop invariant \forall integer k; 0 <= k < l ==> result[k] == fib(k);
      loop invariant \forall integer k; 0 <= k < l ==> 0 <= k < result_len;
      loop assigns l, result[..];
    */
    for (int l = 2; l <= seed; l++) {
        result[l] = result[l - 1]
                  + result[l - 2];
    }
            
    return result[seed];
}
