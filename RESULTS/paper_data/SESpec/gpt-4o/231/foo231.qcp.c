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
	
 	/*@ Inv
    exists  p_l,    
    store_int_array(p, p_len, p_l) &&
    (0 <= index && index <= total) &&
    (count >= 0) &&
    (total == p_len@pre) &&
    (array == array@pre) &&
    (p_len == p_len@pre) &&
    (p == p@pre)
    */
for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant index + 1 <= c <= total;
          loop invariant count >= 0;
          loop invariant \forall int j; index + 1 <= j < c ==> (p[index] != p[j] ==> count >= 0);
          loop assigns c, count;
        */
        /*@ Inv
    exists  p_l,    
    store_int_array(p, p_len, p_l) &&
    (index + 1 <= c && c <= total) &&
    (count >= 0) &&
    (forall (j:Z), index + 1 <= j && j < c => (p_l[index] != p_l[j] => count >= 0))
    */
for (int c = index + 1; c < total; c++) {
            if (p[index] != p[c]) {
                count++;
            }
        }
    }
		return count;
}