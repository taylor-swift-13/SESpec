#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (count_gt : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (invcount_upto : Z -> Z -> Z -> Z) */
int foo247(int * indices, int indices_len, int num) 
/*@
With indices_l
Require store_int_array(indices, indices_len, indices_l)
Ensure Results(__return)
*/{

		int ret = 0;

	
 	/*@ Inv
    exists  indices_l,    
    store_int_array(indices, indices_len, indices_l) &&
    (0 <= index && index <= num) &&
    (0 <= ret) &&
    (forall (k:Z), 0 <= k && k < indices_len => indices_l[k] == indices_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < index => 0 <= indices_l[k] && indices_l[k] <= 100) &&
    (forall (i:Z), forall (j:Z), 0 <= i && i < j && j < index => indices_l[i] <= indices_l[j] || indices_l[i] > indices_l[j])
    */
for (int index = 0; index < num; index++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= index && index < num;
          loop invariant index + 1 <= c && c <= num;
          loop invariant ret >= 0;
          loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k], Pre);
          loop invariant \forall integer k; 0 <= k < indices_len ==> 0 <= indices[k] <= 100;
          loop assigns c, ret;
            */
            /*@ Inv
    exists  indices_l,    
    store_int_array(indices, indices_len, indices_l) &&
    (0 <= index && index < num) &&
    (index + 1 <= c && c <= num) &&
    (ret >= 0) &&
    (forall (k:Z), 0 <= k && k < indices_len => indices_l[k] == indices_l[k]@pre) &&
    (forall (k:Z), 0 <= k && k < indices_len => 0 <= indices_l[k] && indices_l[k] <= 100)
    */
for (int c = index + 1; c < num; c++) {
				if (indices[index] > indices[c]) {
					ret++;
				}
			}
            
		}
		return ret;
}