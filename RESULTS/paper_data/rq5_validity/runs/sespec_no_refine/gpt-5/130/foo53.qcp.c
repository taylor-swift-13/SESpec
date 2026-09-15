#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo53(int search, int array[]);

int foo53(int search, int array[]) 
/*@

Require emp
Ensure Results(__return)
*/{

	      int c;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= c && c <= n) &&
(-1 <= location && location < c || location == -1) &&
(forall (k:Z), 0 <= k && k < (location == -1 ? c : location) => array_l[k] != search) &&
(location != -1 => (0 <= location && location < c && array_l[location] == search)) &&
(forall (k:Z), 0 <= k && k < n => array_l[k] == array_l[k]@pre) &&
(forall (v:Z), count_eq(array, 0, n, v) == \at(count_eq(array, 0, n, v), Pre)
      loop assigns c, location)
    */
    
    for (c = 0; c < n; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }
       if (c == array.length) {
            location = -1;
       }
     return location;
}