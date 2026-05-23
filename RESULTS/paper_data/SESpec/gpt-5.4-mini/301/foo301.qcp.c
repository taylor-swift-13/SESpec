#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo301(int * data, int data_len, int array) 
/*@
With data_l
Require store_int_array(data, data_len, data_l)
Ensure Results(__return)
*/{

		int found = 0, top = array - 1;
	
 	/*@ Inv
    exists  data_l,    
    store_int_array(data, data_len, data_l) &&
    (0 <= found && found <= top + 1) &&
    (top < array) &&
    (array == array@pre) &&
    (data_len == data_len@pre) &&
    (data == data@pre) &&
    (forall (k:Z), 0 <= k && k < data_len => data_l[k] == data_l[k]@pre) &&
    ((0 < array@pre - 1) => (0 <= found && found <= top + 1)) &&
    ((0 < array@pre - 1) => (((top == array@pre - 1)&&(found == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre)) || (0 <= found && found <= top + 1))) &&
    ((0 < array@pre - 1) => (((top == array@pre - 1)&&(found == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre)) || (0 <= top && top < array))) &&
    ((!(0 < array@pre - 1)) => ((top == array@pre - 1)&&(found == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre))) &&
    (array == array@pre) &&
    (data_len == data_len@pre) &&
    (data == data@pre) &&
    (forall (k:Z), 0 <= k && k < data_len => data_l[k] == data_l[k]@pre)
    */
while (found < top) {
			int i = found + (top - found) / 2;
			if (data[i] < data[i + 1]) {
				found = i + 1;
			} else {
				top = i;
			}
		}
		return found;
}