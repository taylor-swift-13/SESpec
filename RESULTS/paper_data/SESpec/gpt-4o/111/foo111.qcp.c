#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo111(int * x, int x_len, int * y, int y_len);

int foo111(int * x, int x_len, int * y, int y_len) 
/*@
With x_l y_l
Require store_int_array(x, x_len, x_l) && x_len > 0 && x_len < 100 && store_int_array(y, y_len, y_l) && y_len > 0 && y_len < 100
Ensure Results(__return)
*/{

        if (x_len != y_len) return 0;
        int index = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  x_l y_l,    
    store_int_array(x, x_len, x_l) && x_len > 0 && x_len < 100 && store_int_array(y, y_len, y_l) && y_len > 0 && y_len < 100 &&
    (forall (k:Z), 0 <= k && k < index => x_l[k] == y_l[reverse_index(x_len, k)]) &&
(forall (k:Z), index <= k && k < x_len => x_l[k] == x_l[k]@pre) &&
(forall (k:Z), index <= k && k < y_len => y_l[k] == y_l[k]@pre) &&
(x_len == x_len@pre) &&
(y_len == y_len@pre) &&
(x == x@pre) &&
(y == y@pre
      loop assigns index)
    */
    
    while (index < x_len) {
        if (x[index] != y[x_len - 1 - index]) {
            return 0;
        } else {
            index = index + 1;
        }
    }
        return 1;
}