#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */
/*@ Extern Coq (max_subarray_sum : Z -> Z -> Z -> Z) */
/*@ Extern Coq (max_subarray_start : Z -> Z -> Z -> Z) */
/*@ Extern Coq (max_subarray_end : Z -> Z -> Z -> Z) */
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

       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (max_so_far >= 0) &&
    (max_ending_here >= 0 || max_ending_here == sum(a, s, i)) &&
    (size == size@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre)
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