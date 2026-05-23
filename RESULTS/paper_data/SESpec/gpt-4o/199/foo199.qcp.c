#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (sum : Z -> Z -> Z -> Z) */
int foo199(int number) 
/*@

Require emp
Ensure Results(__return)
*/{

		int *arr = (int *)malloc(sizeof(int) * (number + 1));
int arr_len = number + 1;
		arr[0] = 1;
	
 	/*@ Inv
    (forall (i:Z), 0 <= i && i < c => arr[i] >= 0)
    */
for (int c = 1; c <= number; c++) {
        arr[c] = 0;

        /*@
          loop invariant 0 <= n <= c;
          
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
          loop assigns arr[c];
        */
        /*@ Inv
    (0 <= n && n <= c) &&
    (forall (i:Z), 0 <= i && i < c => arr[i] >= 0)
    */
for (int n = 0; n < c; n++) {
            arr[c] += arr[n] * arr[c - n - 1];
        }
    }
		return arr[number];
}