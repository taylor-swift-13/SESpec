#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
/*@ Extern Coq (invcnt : Z -> Z -> Z -> Z) */
/*@ Extern Coq (invprefix : Z -> Z -> Z -> Z) */

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
    (0 <= ret) &&
    (ret == invprefix(indices, num, index)) &&
    (forall (k:Z), 0 <= k && k < indices_len => indices_l[k] == indices_l[k]@pre)
    */
for (int index = 0; index < num; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  indices_l,    
    store_int_array(indices, indices_len, indices_l) &&
    (0 <= index && index <= num) &&
    (0 <= c && c <= num) &&
    (c == index + 1 || (index + 1 <= c && c <= num)) &&
    (ret >= 0) &&
    (ret == invprefix(indices, num, index) + invcnt(indices, index, c)) &&
    (forall (k:Z), 0 <= k && k < indices_len => indices_l[k] == indices_l[k]@pre) &&
    (forall (k:Z), index + 1 <= k && k < c => (indices_l[index] > indices_l[k] ? true : true))
    */
for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
		}
		return ret;
}