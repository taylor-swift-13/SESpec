#include <stddef.h>

int getPairsCount(int * arr, int arr_len, int n, int sum);

/*@ 
  logic integer matches_with_i{L}(int *arr, integer p, integer n, integer s) =
    (p >= n-1) ? 0 :
    matches_with_i{L}(arr, p, n-1, s) + ((arr[p] + arr[n-1] == s) ? 1 : 0);

  logic integer count_with_prefix{L}(int *arr, integer i, integer n, integer s) =
    (i <= 0) ? 0 :
    count_with_prefix{L}(arr, i-1, n, s) + matches_with_i{L}(arr, i-1, n, s);

  logic integer matches_range{L}(int* arr, integer p, integer a, integer b, integer s) =
    (b <= a) ? 0 :
    matches_range{L}(arr, p, a, b-1, s) + ((arr[p] + arr[b-1] == s) ? 1 : 0);

  lemma matches_with_i_equals_range{L}:
    \forall int* arr, integer p, n, s;
      p >= 0 ==> matches_with_i{L}(arr, p, n, s) == matches_range{L}(arr, p, p+1, n, s);
*/

/*@ 
  requires arr_len >= 0;
  requires 0 <= n <= arr_len;
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures \result == count_with_prefix{Pre}(arr, n, n, sum);
  ensures 0 <= \result <= (n * (n - 1)) / 2;
*/
int getPairsCount(int * arr, int arr_len, int n, int sum) {

        int count = 0;
        /*@
          loop invariant 0 <= i <= n;
          loop invariant count == count_with_prefix{Pre}(arr, i, n, sum);
          loop assigns i, j, count;
          loop variant n - i;
        */
        for (int i = 0; i < n; i++) {
            /*@
              loop invariant i + 1 <= j <= n;
              loop invariant count == count_with_prefix{Pre}(arr, i, n, sum) + matches_range{Pre}(arr, i, i+1, j, sum);
              loop assigns j, count;
              loop variant n - j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] + arr[j] == sum) {
                    count++;
                }
            }
        }
        return count;
}
