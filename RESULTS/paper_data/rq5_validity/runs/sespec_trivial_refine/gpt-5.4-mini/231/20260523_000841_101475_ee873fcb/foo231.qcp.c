#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo231(int * p, int p_len, int array) 
/*@
With p_l
Require store_int_array(p, p_len, p_l)
Ensure Results(__return)
*/{

		int count = 0;
		int total = p_len;
	
 	/*0*/ 
 /*@ Inv
    exists  p_l,    
    store_int_array(p, p_len, p_l) &&
    (0 <= index && index <= total - 1) &&
    (count == \numof{ integer i, j 0 <= i && i < index && i + 1 <= j && j < total && p_l[i] != p_l[j] })
    */
for (int index = 0; index < total - 1; index++) {
		
 	/*1*/ 
 /*@ Inv
    exists  p_l,    
    store_int_array(p, p_len, p_l) &&
    (index + 1 <= c && c <= total) &&
    (count == \numof{ integer i, j 0 <= i && i < index && i + 1 <= j && j < total && p_l[i] != p_l[j] } + \numof{ integer j index + 1 <= j && j < c && p_l[index] != p_l[j] })
    */
for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
		}
		return count;
}