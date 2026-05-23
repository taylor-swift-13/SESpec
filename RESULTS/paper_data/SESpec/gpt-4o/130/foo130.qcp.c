#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo130(int search, int array[], int array_len);

int foo130(int search, int array[], int array_len) 
/*@

Require emp
Ensure Results(__return)
*/{

	      int location = -1;
        int c;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= c && c <= array_len) &&
(location == -1 || (0 <= location && location < c && array_l[location] == search)) &&
(forall (i:Z), 0 <= i && i < c => array_l[i] == array_l[i]@pre
      loop assigns c, location)
    */
    
    for (c = 0; c < array_len; c++) {
        if (array[c] == search) {
            location = c;
            break;
        }
    }
       if (c == array_len) {
            location = -1;
       }
     return location;
}