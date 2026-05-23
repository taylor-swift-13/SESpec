
#include <stddef.h>
#include <stdlib.h>

/*@
  logic integer arr_eq{L}(int* a, int* b, integer lo, integer hi) =
    lo >= hi ? 1
             : (a[hi-1] == b[hi-1] ? arr_eq(a,b,lo,hi-1) : 0);
*/
/*@
  logic integer max_prod_prefix(int* arr, int* mpis, integer i) =
    i <= 0 ? 0 :
    (i == 1 ? mpis[0] :
      (mpis[i-1] >= max_prod_prefix(arr, mpis, i-1) ? mpis[i-1] : max_prod_prefix(arr, mpis, i-1)));
*/
/*@
  logic integer mpis_copied_prefix{L}(int* arr, int* mpis, integer i) =
    i <= 0 ? 1 : (mpis[i-1] == arr[i-1] ? mpis_copied_prefix(arr, mpis, i-1) : 0);
*/

/*@
  logic integer copied_prefix(int* a, int* b, integer i) =
    i <= 0 ? 1 : (b[i-1] == a[i-1] ? copied_prefix(a,b,i-1) : 0);
*/
        

/*@
  requires \valid_read(arr + (0..arr_len-1));
  requires n >= 0;
  assigns \nothing;
*/



int foo8_c157(int * arr, int arr_len, int n) {

        int *mpis = (int *)malloc(sizeof(int) * (n));
        int mpis_len = n;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 0 <= i <= n;
              loop invariant \valid_read(arr + (0..arr_len-1));
              loop assigns i, mpis[0..n-1];
            */
            for (int i = 0; i < n; i++) {
                mpis[i] = arr[i];
            }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant \valid_read(arr + (0..arr_len-1));
              loop assigns i, mpis[0..n-1];
            */
            for (int i = 1; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant \valid_read(arr + (0..arr_len-1));
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
