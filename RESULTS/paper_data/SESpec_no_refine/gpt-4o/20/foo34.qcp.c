#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo34(int * x, int x_len, int * y, int y_len);

int foo34(int * x, int x_len, int * y, int y_len) 
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
    (0 <= index && index <= x_len) &&
(forall (i:Z), 0 <= i && i < index => x_l[i] == y_l[reverse_index(x_len, i)]) &&
(y_len == y_len@pre) &&
(y == y@pre) &&
(x_len == x_len@pre) &&
(x == x@pre) &&
(forall (i:Z), 0 <= i && i < y_len => y_l[i] == y_l[i]@pre) &&
(forall (i:Z), 0 <= i && i < x_len => x_l[i] == x_l[i]@pre
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