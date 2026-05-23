#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (cat_sum : Z -> Z -> Z -> Z) */
int foo198(int c) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (c + 1));
int arr_len = c + 1;
		arr[0] = 1;
	
 	/*@ Inv
    (forall (k:Z), 1 <= k && k < cat => (exists (t:Z), 0 <= t && t < k))
    */
for (int cat = 1; cat <= c; cat++) {
			arr[cat] = 0;
			
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant \forall integer k; 0 <= k < n ==> 0 <= cat - k - 1 < cat;
          loop assigns arr[cat], n;
            */
            /*@ Inv
    (forall (k:Z), 0 <= k && k < n => 0 <= cat - k - 1 < cat)
    */
for (int n = 0; n < cat; n++) {
				arr[cat] += arr[n]
						* arr[cat - n - 1];
			}
            
		}
		return arr[c];
}