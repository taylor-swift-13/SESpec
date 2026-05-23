#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (fixed_prefix : Z -> Z -> Z -> Prop) */
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
    ((leftElement@pre <= rightElement@pre) => (leftElement@pre <= i)) &&
    ((leftElement@pre <= rightElement@pre) => (j <= rightElement@pre)) &&
    ((leftElement@pre <= rightElement@pre) => (i <= j + 1)) &&
    ((leftElement@pre <= rightElement@pre) => (i > j => (j + 1 == i))) &&
    ((leftElement@pre <= rightElement@pre) => (i >= leftElement@pre && i <= rightElement@pre + 1)) &&
    ((leftElement@pre <= rightElement@pre) => (j >= leftElement@pre - 1 && j <= rightElement@pre)) &&
    ((leftElement@pre <= rightElement@pre) => (((j == rightElement@pre)&&(i == leftElement@pre)&&(rightElement == rightElement@pre)&&(leftElement == leftElement@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (i >= leftElement@pre && i <= rightElement@pre + 1))) &&
    ((leftElement@pre <= rightElement@pre) => (((j == rightElement@pre)&&(i == leftElement@pre)&&(rightElement == rightElement@pre)&&(leftElement == leftElement@pre)&&(a_len == a_len@pre)&&(a == a@pre)) || (j >= leftElement@pre - 1 && j <= rightElement@pre))) &&
    ((!(leftElement@pre <= rightElement@pre)) => ((j == rightElement@pre)&&(i == leftElement@pre)&&(rightElement == rightElement@pre)&&(leftElement == leftElement@pre)&&(a_len == a_len@pre)&&(a == a@pre))) &&
    (rightElement == rightElement@pre) &&
    (leftElement == leftElement@pre) &&
    (a_len == a_len@pre) &&
    (a == a@pre) &&
    (forall (k:Z), 0 <= k && k < a_len => a_l[k] == a_l[k]@pre)
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