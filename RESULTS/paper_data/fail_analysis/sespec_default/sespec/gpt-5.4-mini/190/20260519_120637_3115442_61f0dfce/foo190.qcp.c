#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo190(int * sortedArray, int sortedArray_len, int value);

int foo190(int * sortedArray, int sortedArray_len, int value) 
/*@
With sortedArray_l
Require store_int_array(sortedArray, sortedArray_len, sortedArray_l) && sortedArray_len > 0 && sortedArray_len < 100
Ensure Results(__return)
*/{

        if (value < sortedArray[0]) return -1;
        if (value > sortedArray[sortedArray_len-1]) return -1;
        int lo = 0;
        int hi = sortedArray_len-1;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  sortedArray_l,    
    store_int_array(sortedArray, sortedArray_len, sortedArray_l) && sortedArray_len > 0 && sortedArray_len < 100 &&
    ((0 <= sortedArray_len@pre - 1) => (((hi == sortedArray_len@pre - 1)&&(lo == 0)&&(value == value@pre)&&(sortedArray_len == sortedArray_len@pre)&&(sortedArray == sortedArray@pre)) || (0 <= lo && lo <= hi + 1))) &&
((0 <= sortedArray_len@pre - 1) => (((hi == sortedArray_len@pre - 1)&&(lo == 0)&&(value == value@pre)&&(sortedArray_len == sortedArray_len@pre)&&(sortedArray == sortedArray@pre)) || (lo >= 0 && hi < sortedArray_len@pre))) &&
((!(0 <= sortedArray_len@pre - 1)) => ((hi == sortedArray_len@pre - 1)&&(lo == 0)&&(value == value@pre)&&(sortedArray_len == sortedArray_len@pre)&&(sortedArray == sortedArray@pre))) &&
(value == value@pre) &&
(sortedArray_len == sortedArray_len@pre) &&
(sortedArray == sortedArray@pre) &&
(forall (k:Z), 0 <= k && k < sortedArray_len => sortedArray_l[k] == sortedArray_l[k]@pre)
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