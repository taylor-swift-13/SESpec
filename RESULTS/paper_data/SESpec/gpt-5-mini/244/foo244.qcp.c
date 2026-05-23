#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo244(int * array, int array_len, int num, int p) 
/*@
With array_l
Require store_int_array(array, array_len, array_l)
Ensure Results(__return)
*/{

		int ret = 0;
	
 	/*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (0 <= index) &&
    (0 <= ret) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre) &&
    (forall (k:Z), 0 <= k && k < array_len => 0 <= array_l[k] && array_l[k] <= 100)
    */
for (int index = 0; index < num; index++) {
        
        /*@
          loop invariant 0 <= index && index < num;
          loop invariant index + 1 <= j && j <= num;
          loop invariant 0 <= ret;
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant array_len == \at(array_len,Pre);
          loop invariant array == \at(array,Pre);
          loop invariant \forall integer k; 0 <= k < array_len ==> 0 <= array[k] <= 100;
          loop assigns j, ret;
        */
        /*@ Inv
    exists  array_l,    
    store_int_array(array, array_len, array_l) &&
    (0 <= index && index < num) &&
    (index + 1 <= j && j <= num) &&
    (0 <= ret) &&
    (p == p@pre) &&
    (num == num@pre) &&
    (array_len == array_len@pre) &&
    (array == array@pre) &&
    (forall (k:Z), 0 <= k && k < array_len => 0 <= array_l[k] && array_l[k] <= 100)
    */
for (int j = index + 1; j < num; j++) {
            if (array[index] + array[j] == p) {
                ret++;
            }
        }
        
    }
		return ret;
}