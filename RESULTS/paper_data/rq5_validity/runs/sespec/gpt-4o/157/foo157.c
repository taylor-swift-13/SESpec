
#include <stdlib.h>

/*@
  logic integer product_prefix(int* arr, integer i, integer j) =
    i >= j ? 1 : product_prefix(arr, i, j - 1) * arr[j - 1];
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires arr_len >= 0;
  requires n >= 0 && n <= arr_len;
  assigns arr[0..arr_len-1], \result;
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

    /*@
                        \forall integer j; 0 <= j < k ==> 
                            (arr[k] > arr[j] && mpis[k] < mpis[j] * arr[k]) ==> 
                                mpis[k] == mpis[j] * arr[k];
                        mpis[k] >= arr[k];
                        mpis[k] <= product_prefix(arr, 0, k + 1);
      loop assigns i, mpis[0..n-1];
    */
    for (int i = 1; i < n; i++) {
        /*@
          loop invariant 0 <= j <= i;
                            \forall integer j; 0 <= j < k ==> 
                                (arr[k] > arr[j] && mpis[k] < mpis[j] * arr[k]) ==> 
                                    mpis[k] == mpis[j] * arr[k];
                            mpis[k] >= arr[k];
                            mpis[k] <= product_prefix(arr, 0, k + 1);
          loop assigns j, mpis[0..n-1];
        */
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                mpis[i] = mpis[j] * arr[i];
            }
        }
    }

    int max = mpis[0];
    /*@
      loop invariant 1 <= i <= n;
      loop invariant \exists integer k; 0 <= k < i && max == mpis[k];
      loop assigns i, max;
    */
    for (int i = 1; i < n; i++) {
        if (mpis[i] > max) {
            max = mpis[i];
        }
    }

    return max;
}
