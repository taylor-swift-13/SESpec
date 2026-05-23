#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sp : Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_q_from : Z -> Z -> Z -> Z -> Z) */
/*@ Extern Coq (count_p_lt : Z -> Z -> Z -> Z) */
int foo164(int * arr, int arr_len, int n) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

		if (arr == NULL) {
			return -1;
		}
		if (arr_len == 1) {
			return 0;
		}

		int evenPairCount = 0;
	
 	/*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (forall (k:Z), 0 <= k && k < arr_len => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (forall (p:Z), forall (q:Z), 0 <= p && p < i && p < q && q < arr_len => sp(arr,p,q) >= 0) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int i = 0; i < arr_len; i++) {
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= c <= arr_len;
          loop assigns evenPairCount, c;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i + 1 <= c && c <= arr_len)
    */
for (int c = i + 1; c < arr_len; c++) {
				int even = arr[i];
				int odd = arr[c];
				int z = even ^ odd;
				if ((z & 1) == 0) {
					evenPairCount++;
				}
			}
            
		}
		return evenPairCount;
}