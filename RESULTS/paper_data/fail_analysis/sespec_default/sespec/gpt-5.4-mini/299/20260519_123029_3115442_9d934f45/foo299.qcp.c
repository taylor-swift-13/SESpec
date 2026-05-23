#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo299(int * data, int data_len, int array);

int foo299(int * data, int data_len, int array) 
/*@
With data_l
Require store_int_array(data, data_len, data_l) && data_len > 0 && data_len < 100
Ensure Results(__return)
*/{

		int i = 0, top = array - 1;
	
 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  data_l,    
    store_int_array(data, data_len, data_l) && data_len > 0 && data_len < 100 &&
    (0 <= i) &&
(top <= array - 1) &&
(array == array@pre) &&
(data_len == data_len@pre) &&
(data == data@pre) &&
(\valid_read(data + (0 .. data_len - 1))
          loop assigns i, top)
    */
    
            while (i < top) {
			int p = i + (top - i) / 2;
			if (data[p] < data[p + 1]) {
				i = p + 1;
			} else {
				top = p;
			}
		}
		return i;
}