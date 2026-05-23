#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (is_match : Z -> Z -> Z -> Prop) */
int foo252(int * arr, int arr_len, int n, int sum) 
/*@
With arr_l
Require store_int_array(arr, arr_len, arr_l)
Ensure Results(__return)
*/{

        int count = 0;
       
  /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= count) &&
    (0 <= i && i <= n)
    */
for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count;
          loop invariant i + 1 <= j <= n;
          loop assigns count, j;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (0 <= i && i <= n) &&
    (0 <= count) &&
    (i + 1 <= j && j <= n)
    */
for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
            
        }
        return count;
}