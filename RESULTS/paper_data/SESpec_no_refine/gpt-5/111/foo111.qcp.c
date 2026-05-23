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
Ensure (x_l[0] != y_l[x_len - 1 - 0] && 0 < x_len && x_len == y_len && x_len > 0 && x_len < 100 && y_len > 0 && y_len < 100 && __return == 0 && store_int_array(y, y_len, y_l) * store_int_array(x, x_len, x_l)) || (x_len != y_len && x_len > 0 && x_len < 100 && y_len > 0 && y_len < 100 && __return == 0 && store_int_array(x, x_len, x_l) * store_int_array(y, y_len, y_l))
*/
{

        if (x_len != y_len) return 0;
        int index = 0;

       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (index < x_len) {
            if (x[index] != y[x_len - 1 - index]) {
                return 0;
            } else {
                index = index + 1;
            }
        }
        return 1;
}