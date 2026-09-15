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
    (0 <= count) &&
    (total == p_len@pre) &&
    (array == array@pre) &&
    (p_len == p_len@pre) &&
    (p == p@pre) &&
    (forall (k:Z), 0 <= k && k < total => p_l[k] == p_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < total => 0 <= p_l[k] && p_l[k] <= 100)
    */
for (int index = 0; index < total - 1; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant index + 1 <= c <= total;
          loop invariant 0 <= count;
          loop invariant \forall integer k; 0 <= k < total ==> p[k] == \at(p[k], Pre);
          loop invariant \forall integer k; 0 <= k < total ==> 0 <= p[k] <= 100;
          loop assigns count, c;
            */
            /*@ Inv
    exists  p_l,    
    store_int_array(p, p_len, p_l) &&
    (index + 1 <= c && c <= total) &&
    (0 <= count) &&
    (forall (k:Z), 0 <= k && k < total => p_l[k] == p_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < total => 0 <= p_l[k] && p_l[k] <= 100)
    */
for (int c = index + 1; c < total; c++) {
				if (p[index] != p[c]) {
					count++;
				}
			}
            
		}
		return count;
}