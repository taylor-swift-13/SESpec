#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo116(int * array, int array_len, int start, int end);

int foo116(int * array, int array_len, int start, int end) 
/*@
With array_l
Require store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100
Ensure Results(__return)
*/{

        int min = start;
        int max = end;
        int mid;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) && array_len > 0 && array_len < 100 &&
    ((start@pre <= end@pre) => (min <= max + 1)) &&
((start@pre <= end@pre) => (((max == end@pre)&&(min == start@pre)&&(end == end@pre)&&(start == start@pre)&&(array_len == array_len@pre)&&(array == array@pre)) || ((min >= start@pre) && (max <= end@pre) && (min <= max + 1)))) &&
((start@pre <= end@pre) => (((max == end@pre)&&(min == start@pre)&&(end == end@pre)&&(start == start@pre)&&(array_len == array_len@pre)&&(array == array@pre)) || ((min >= start@pre) && (max <= end@pre) && (min <= max + 1)))) &&
((!(start@pre <= end@pre)) => ((max == end@pre)&&(min == start@pre)&&(end == end@pre)&&(start == start@pre)&&(array_len == array_len@pre)&&(array == array@pre))) &&
(end == end@pre) &&
(start == start@pre) &&
(array_len == array_len@pre) &&
(array == array@pre) &&
(same_array{Pre,Here}(array, array_len@pre) 
          loop assigns mid, min, max)
    */
    
            while (min <= max) {
            mid = (min + max) / 2;
            int current = array[mid];

            if (current == mid) {
                min = mid + 1;
            } else if (current < mid) {
                min = mid + 1;
            } else {
                max = mid - 1;
            }
        }
        return min;
}