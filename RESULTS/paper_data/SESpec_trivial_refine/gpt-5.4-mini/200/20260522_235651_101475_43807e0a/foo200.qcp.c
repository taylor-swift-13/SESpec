#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo200(int * a, int a_len, int size) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int max_so_far = 0;
        int max_ending_here = 0;
        int start = 0;
        int end = 0;
        int s = 0;

       
  /*0*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= size) &&
    (0 <= s && s <= i + 1) &&
    (0 <= start && start <= size) &&
    (0 <= end && end <= size) &&
    (start <= end + 1)
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