#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo127(int * a, int a_len, int x);

int foo127(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        int i = 0;
        int j = a_len - 1;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    (x == x@pre) &&
(a_len == a_len@pre) &&
(a == a@pre
      loop assigns i, j)
    */
    
    while (i <= j) {
        int mid = (i + j) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
        return i;
}