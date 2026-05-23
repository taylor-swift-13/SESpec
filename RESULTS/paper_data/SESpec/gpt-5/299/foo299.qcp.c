#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo299(int * data, int data_len, int array) 
/*@
With data_l
Require store_int_array(data, data_len, data_l)
Ensure Results(__return)
*/{

		int i = 0, top = array - 1;
	
 	/*@ Inv
    exists  data_l,    
    store_int_array(data, data_len, data_l) &&
    ((0 < array@pre - 1) => (0 <= i && i <= top + 1)) &&
    ((0 < array@pre - 1) => (-1 <= top && top < array@pre)) &&
    ((0 < array@pre - 1) => (i <= top || i == top + 1)) &&
    ((0 < array@pre - 1) => (0 <= i)) &&
    ((0 < array@pre - 1) => (top < array@pre)) &&
    ((0 < array@pre - 1) => (i <= top + 1)) &&
    ((0 < array@pre - 1) => ((i < top) => (i + 1 <= top))) &&
    ((0 < array@pre - 1) => ((i >= top) => (i == top))) &&
    ((0 < array@pre - 1) => (top <= array@pre - 1)) &&
    ((0 < array@pre - 1) => (i <= top)) &&
    ((0 < array@pre - 1) => (((top == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre)) || (0 <= i && i <= top && top < array@pre))) &&
    ((0 < array@pre - 1) => (((top == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre)) || (i <= top && top < array@pre && 0 <= top))) &&
    ((!(0 < array@pre - 1)) => ((top == array@pre - 1)&&(i == 0)&&(array == array@pre)&&(data_len == data_len@pre)&&(data == data@pre))) &&
    (array == array@pre) &&
    (data_len == data_len@pre) &&
    (data == data@pre) &&
    (forall (k:Z), 0 <= k && k < data_len => data_l[k] == data_l[k]@pre)
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