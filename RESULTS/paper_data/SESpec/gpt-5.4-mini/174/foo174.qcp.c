#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo174(int * a, int a_len) 
/*@
With a_l
Require store_int_array(a, a_len, a_l)
Ensure Results(__return)
*/{

        int start = 0;
        int end = a_len - 1;
       
  /*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) &&
    (0 <= start) &&
    (end < a_len) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (i:Z), 0 <= i && i < a_len => a_l[i] == a_l[i]@pre) &&
    (start <= end + 1) &&
    (start <= a_len) &&
    (-1 <= end)
    */
while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && a[mid] > a[mid + 1]) {
                return mid + 1;
            } else if (mid > start && a[mid] < a[mid - 1]) {
                return mid;
            }
            if (a[mid] >= a[start]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return 0;
}