#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo298(int * a, int a_len, int leftElement, int rightElement) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int i = leftElement;
        int j = rightElement;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (leftElement <= i && i <= j + 1) &&
    (-1 <= j && j < a_len) &&
    (0 <= i && i <= a_len)
    */
while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return i;
}