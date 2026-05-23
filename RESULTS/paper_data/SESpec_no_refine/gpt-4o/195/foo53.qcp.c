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
/*@ Inv emp */ /*0*/ 
 for (c = 0; c < array.length; c++) {
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