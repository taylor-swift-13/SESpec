#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (rev_eq : Z -> Z -> Z -> Prop) */
int foo111(int * x, int x_len, int * y, int y_len) 
/*@
With x_l y_l
Require store_int_array(x, x_len, x_l) && store_int_array(y, y_len, y_l)
Ensure Results(__return)
*/{

        if (x_len != y_len) return 0;
        int index = 0;

       
  /*@ Inv
    exists  x_l y_l,    
    store_int_array(x, x_len, x_l) && store_int_array(y, y_len, y_l) &&
    (0 <= index) &&
    (x_len < 0 || index <= x_len) &&
    (forall (k:Z), 0 <= k && k < index => x_l[k] == y_l[x_len - 1 - k])
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