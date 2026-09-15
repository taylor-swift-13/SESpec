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
    (forall (k:Z), 0 <= k && k < array_len => array[k] == array[k]@pre) &&
    (location == -1 || (0 <= location && location < c && array[location] == search)) &&
    (forall (k:Z), 0 <= k && k < c => array[k] != search) &&
    (location == -1 => forall (k:Z), 0 <= k && k < c => array[k] != search) &&
    (location != -1 => (array[location] == search && 0 <= location && location < c)) &&
    (c == 0 => location == -1) &&
    ((c < array_len) => (c >= 0 && c < array_len)) &&
    ((!(c < array_len)) => (c >= array_len))
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