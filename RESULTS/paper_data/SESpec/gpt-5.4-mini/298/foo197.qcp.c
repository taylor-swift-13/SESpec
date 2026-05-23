#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo197(int * a, int a_len, int leftElement, int rightElement);

int foo197(int * a, int a_len, int leftElement, int rightElement) 
/*@
With a_l
Require store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100
Ensure Results(__return)
*/{

        int i = leftElement;
        int j = rightElement;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l,    
    store_int_array(a, a_len, a_l) && a_len > 0 && a_len < 100 &&
    ((leftElement@pre <= rightElement@pre) => (((j == rightElement@pre)&&(i == leftElement@pre)&&(rightElement == rightElement@pre)&&(leftElement == leftElement@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (leftElement <= i))) &&
((leftElement@pre <= rightElement@pre) => (((j == rightElement@pre)&&(i == leftElement@pre)&&(rightElement == rightElement@pre)&&(leftElement == leftElement@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (j <= rightElement))) &&
((!(leftElement@pre <= rightElement@pre)) => ((j == rightElement@pre)&&(i == leftElement@pre)&&(rightElement == rightElement@pre)&&(leftElement == leftElement@pre)&&(a_len == a_len@pre)&&(a == a@pre))) &&
(rightElement == rightElement@pre) &&
(leftElement == leftElement@pre) &&
(a_len == a_len@pre) &&
(a == a@pre) &&
(forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre
          loop assigns i, j)
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