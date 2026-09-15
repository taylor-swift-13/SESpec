#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo247(int * indices, int indices_len, int num) 
/*@
With indices_l
Require store_int_array(indices, indices_len, indices_l)
Ensure Results(__return)
*/{

		int ret = 0;

	
 	/*0*/ 
 /*@ Inv
    exists  indices_l,    
    store_int_array(indices, indices_len, indices_l) &&
    (0 <= index && index <= num) &&
    (ret >= 0)
    */
for (int index = 0; index < num; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  indices_l,    
    store_int_array(indices, indices_len, indices_l) &&
    (index + 1 <= c && c <= num) &&
    (0 <= index && index < num) &&
    (ret >= 0)
    */
for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
}