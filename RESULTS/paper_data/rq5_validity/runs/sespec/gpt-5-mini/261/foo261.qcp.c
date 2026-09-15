#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo261(int * a, int a_len, int x) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int i = 0;
        int j = a_len - 1;
       
  /*0*/ 
 /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= i && i <= a_len) &&
    (-1 <= j && j <= a_len - 1) &&
    (i <= j + 1) &&
    (forall (k:Z), 0 <= k && k < i => a_l[k] < x) &&
    (forall (k:Z), j < k && k < a_len => a_l[k] > x) &&
    ((i <= j) => (forall (k:Z), i <= k && k <= j => a_l[k] != x))
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