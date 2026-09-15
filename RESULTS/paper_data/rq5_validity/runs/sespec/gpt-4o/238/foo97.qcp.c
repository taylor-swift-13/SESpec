#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo97(int * a, int a_len, int n);

int foo97(int * a, int a_len, int n) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        int count = 0;
        int length = a_len;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    (0 <= i && i <= length) &&
(count >= 0
      loop assigns i, count
      loop variant length - i)
    */
    
    for (int i = 0; i < length; i++) {
        /*@
          loop invariant i + 1 <= j <= length;
          loop invariant count >= 0;
          loop assigns j, count;
          loop variant length - j;
        */
        for (int j = i + 1; j < length; j++) {
            if ((a[i] ^ a[j]) % 2 == 1) {
                count++;
            }
        }
    }
        return count;
}