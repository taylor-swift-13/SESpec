
#include <stdlib.h>

/*@ 
  predicate mpis_prefix{L}(int *mpis, int *arr, integer n, integer i) =
    0 <= i <= n && \forall integer k; 0 <= k < i ==> mpis[k] == arr[k];
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires arr_len >= 0;
  requires n >= 0;
  requires n <= arr_len;
*/
int foo157(int * arr, int arr_len, int n) {

    int *mpis = (int *)malloc(sizeof(int) * (n));
    int mpis_len = n;
        
    /*@
      loop invariant 0 <= i <= n;
      loop assigns i, mpis[0..n-1];
    */
    for (int i = 0; i < n; i++) {
        mpis[i] = arr[i];
    }
            
    /* Outer loop: do not mention 'j' here (j is inner-scope) */
    /*@
      loop assigns i, mpis[0..n-1];
    */
    for (int i = 1; i < n; i++) {
        /* Inner loop: j is in scope here, invariants may mention j */
        /*@
          loop assigns j, mpis[0..n-1];
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
      loop invariant (i < n) ==> (\forall integer k; 0 <= k < i ==> max >= mpis[k]);
      loop invariant (!(i < n)) ==> (\forall integer k; 0 <= k < n ==> max >= mpis[k]);
      
      loop assigns i, max;
    */
    for (int i = 1; i < n; i++) {
        if (mpis[i] > max) {
            max = mpis[i];
        }
    }
            
    return max;
}
