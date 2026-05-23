#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
    (sum == sum@pre) &&
    (n == n@pre) &&
    (arr_len == arr_len@pre) &&
    (arr == arr@pre) &&
    (true)) &&
    (forall (k:Z), 0 <= k && k < arr_len => 0 <= arr_l[k] && arr_l[k] <= 100) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre) &&
    (0 <= count)
    */
for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i + 1 <= j <= n;
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count;
          loop invariant \valid(&arr[0] + (0..arr_len-1));
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop assigns count;
            */
            /*@ Inv
    exists  arr_l,    
    store_int_array(arr, arr_len, arr_l) &&
    (i + 1 <= j && j <= n) &&
    (0 <= i && i <= n) &&
    (0 <= count) &&
    (true)) &&
    (forall (k:Z), 0 <= k && k < arr_len => arr_l[k] == arr_l[k]@pre)
    */
for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
            
        }
        return count;
}