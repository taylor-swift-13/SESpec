
/*@
  logic integer prefix_eq{L}(int* a, int* b, integer len) =
    len <= 0 ? 1 : (prefix_eq(a, b, len - 1) && a[len - 1] == b[len - 1] ? 1 : 0);

  // Read-only frame predicate for array arr over a fixed length n
  predicate arr_unchanged{L1,L2}(int* arr, integer n) =
    \forall integer k; 0 <= k < n ==> \at(arr[k], L1) == \at(arr[k], L2);
*/
/*@
  // No extra predicates or logic functions are needed here.
*/

        /*@
        // No additional predicates needed.
        */
        

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

#include <stdlib.h>

int foo157(int * arr, int arr_len, int n) {

        int *mpis = (int *)malloc(sizeof(int) * (n));
        int mpis_len = n;
        
        /*@ 
          loop invariant 0 <= n ==>
                           (0 <= i <= n);
          loop invariant mpis_len == n;
          loop invariant \forall integer k; i <= k < n ==> \true;
          loop assigns i, mpis[0..n-1];
        */
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n;
          loop invariant \valid(mpis + (0..n-1));
          loop invariant \valid_read(arr + (0..arr_len-1));
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] >= arr[k];
          loop assigns i, j, mpis[..];
            */
            for (int i = 1; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= i;
          loop invariant \valid(mpis + (0..n-1));
          loop invariant \valid_read(arr + (0..arr_len-1));
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] >= arr[k];
          loop invariant \forall integer k; j <= k < i ==> mpis[k] >= arr[k];
          loop invariant \forall integer k; 0 <= k < j ==> mpis[k] >= arr[k];
          loop invariant mpis[i] >= arr[i];
          loop assigns j, mpis[i];
            */
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
            
        }
            
        int max = mpis[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= n;
          loop invariant \valid_read(mpis + (0..n-1));
          loop invariant \forall integer k; 0 <= k < n ==> mpis[k] == \at(mpis[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] <= max;
          loop assigns i, max;
            */
            for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
            
        return max;
}
