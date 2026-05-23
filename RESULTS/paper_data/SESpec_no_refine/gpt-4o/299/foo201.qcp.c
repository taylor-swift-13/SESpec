#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

int foo201(int * data, int data_len, int array);

int foo201(int * data, int data_len, int array) 
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
    ((0 < array@pre - 1) => (((top == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre)) || (i >= 0 && i <= top))) &&
((0 < array@pre - 1) => (((top == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre)) || (top >= i && top < array@pre))) &&
((!(0 < array@pre - 1)) => ((top == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre))) &&
(array == array@pre) &&
(data_len == data_len@pre) &&
(data == data@pre) &&
(forall (k:Z), 0 <= k && k < data_len => data_l[k] == data_l[k]@pre
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