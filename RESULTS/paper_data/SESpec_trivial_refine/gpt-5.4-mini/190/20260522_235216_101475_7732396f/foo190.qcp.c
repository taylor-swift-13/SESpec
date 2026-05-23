#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sorted : Z -> Z -> Prop) */
int foo190(int * sortedArray, int sortedArray_len, int value) 
/*@
With sortedArray_l
Require store_int_array(sortedArray, sortedArray_len, sortedArray_l)
Ensure Results(__return)
*/{

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

       
  /*@ Inv
    exists  sortedArray_l,    
    store_int_array(sortedArray, sortedArray_len, sortedArray_l) &&
    (sorted(sortedArray, sortedArray_len)) &&
    (0 <= lo && lo <= sortedArray_len) &&
    (-1 <= hi && hi < sortedArray_len) &&
    (lo <= hi + 1)
    */
while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (sortedArray[mid] == value) {
                return mid;
            } else if (sortedArray[mid] < value) {
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return -1;
}