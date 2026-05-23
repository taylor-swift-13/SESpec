#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo130(int search, int array[], int array_len) 
/*@

Require emp
Ensure Results(__return)
*/{

	      int location = -1;
        int c;

       
  /*@ Inv
    (0 <= c && c <= array_len) &&
    (location == -1 || (0 <= location && location < array_len && array[location] == search))
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