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
    (0 <= index) &&
    (total == p_len@pre) &&
    (array == array@pre) &&
    (p_len == p_len@pre) &&
    (p == p@pre) &&
    (0 <= count) &&
    (true)) &&
    (forall (i:Z), 0 <= i && i < total => p_l[i] == p_l[i]@pre) &&
    ((index < p_len@pre - 1) => (count >= 0))
    */
for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant 0 <= index && index <= total;
          loop invariant 0 <= count;
          loop invariant \forall integer k; 0 <= k < index ==>
                           (\forall integer j; k < j && j < total ==> p[k] != p[j] ? \true : \true);
          loop invariant \valid(p + (0..total-1));
          loop assigns index, count;
        */
        /*@ Inv
    exists  p_l,    
    store_int_array(p, p_len, p_l) &&
    (0 <= index && index <= total) &&
    (0 <= count) &&
    (forall (k:Z), 0 <= k && k < index => (forall (j:Z), k < j && j < total => p_l[k] != p_l[j] ? true : true)) &&
    (true))
    */
for (int c = index + 1; c < total; c++) {
            if (p[index] != p[c]) {
                count++;
            }
        }

    }
		return count;
}