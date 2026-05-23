#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo200(int * a, int a_len, int size);

int foo200(int * a, int a_len, int size) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    (0 <= s && s <= i) &&
(0 <= start && start <= i) &&
(-1 <= end && end <= i) &&
(max_ending_here >= 0) &&
(max_so_far >= 0) &&
(size == size) &&
(a_len == a_len) &&
(a == a
          loop assigns i, max_ending_here, max_so_far, start, end, s)
    */
    
            for (int i = 0; i < size; i++) {
            max_ending_here += a[i];
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
            if (max_ending_here < 0) {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        return end - start + 1;
}