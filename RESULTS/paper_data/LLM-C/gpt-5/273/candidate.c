#include <stddef.h>

int sumOfSubarrayProd(int * arr, int arr_len, int n);

/*@ 
  logic integer prod_range(int *a, integer l, integer u) =
    l > u ? 1 : (integer)a[l] * prod_range(a, l+1, u);

  logic integer sum_prod_prefix(int *a, integer i, integer j) =
    j < i ? 0 : sum_prod_prefix(a, i, j-1) + prod_range(a, i, j);

  logic integer sum_all_prefix(int *a, integer n, integer i) =
    i <= 0 ? 0 : sum_all_prefix(a, n, i-1) + sum_prod_prefix(a, i-1, n-1);
*/

/*@
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires n > 0 ==> \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures \result == sum_all_prefix(arr, n, n);
*/
int sumOfSubarrayProd(int * arr, int arr_len, int n) {

        int sum = 0;
        /*@
          loop invariant 0 <= i <= n;
          loop invariant sum == sum_all_prefix(arr, n, i);
          loop assigns i, sum;
          loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            int product = 1;
            /*@
              loop invariant i <= j <= n;
              loop invariant product == prod_range(arr, i, j-1);
              loop invariant sum == sum_all_prefix(arr, n, i) + sum_prod_prefix(arr, i, j-1);
              loop assigns j, product, sum;
              loop variant n - j;
            */
            for (int j = i; j < n; j++) {
                product *= arr[j];
                sum += product;
            }
        }
        return sum;
}
