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

	
 	/*@ Inv
    exists  indices_l,    
    store_int_array(indices, indices_len, indices_l) &&
    (0 <= index && index <= num) &&
    (ret >= 0) &&
    (forall (i:Z), forall (j:Z), 0 <= i && i < index && i < j && j < num => indices_l[i] > indices_l[j] => ret >= 0) &&
    (forall (i:Z), forall (j:Z), 0 <= i && i < index && i < j && j < num => indices_l[i] <= indices_l[j] => ret >= 0) &&
    (num == num@pre) &&
    (indices_len == indices_len@pre) &&
    (indices == indices@pre)
    */
for (int index = 0; index < num; index++) {
        
        /*@
          loop invariant index + 1 <= c <= num;
          loop invariant ret >= 0;
          loop invariant \forall int i, j; 0 <= i < index && i < j < num ==> indices[i] > indices[j] ==> ret >= 0;
          loop invariant \forall int i, j; 0 <= i < index && i < j < num ==> indices[i] <= indices[j] ==> ret >= 0;
          loop assigns c, ret;
        */
        /*@ Inv
    exists  indices_l,    
    store_int_array(indices, indices_len, indices_l) &&
    (index + 1 <= c && c <= num) &&
    (ret >= 0) &&
    (forall (i:Z), forall (j:Z), 0 <= i && i < index && i < j && j < num => indices_l[i] > indices_l[j] => ret >= 0) &&
    (forall (i:Z), forall (j:Z), 0 <= i && i < index && i < j && j < num => indices_l[i] <= indices_l[j] => ret >= 0)
    */
for (int c = index + 1; c < num; c++) {
            if (indices[index] > indices[c]) {
                ret++;
            }
        }
    }
		return ret;
}