
/*@
  logic integer sum_even_indices(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_indices(arr, lo, hi - 1) + 
               ((hi - 1) % 2 == 0 && arr[hi - 1] % 2 == 0 ? arr[hi - 1] : 0);
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires arr_len >= 0;
  requires n >= 0 && n <= arr_len;
  assigns \nothing;
  ensures \result == sum_even_indices(arr, 0, n);
  ensures \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
  ensures n == \at(n, Pre);
  ensures arr_len == \at(arr_len, Pre);
  ensures arr == \at(arr, Pre);
*/
int foo274(int * arr, int arr_len, int n) {

    int count = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant count == sum_even_indices(arr, 0, i);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant (!(i < n)) ==> ((count == sum_even_indices(arr, 0, n)) &&
                                     (n == \at(n, Pre)) &&
                                     (arr_len == \at(arr_len, Pre)) &&
                                     (arr == \at(arr, Pre)));
      loop assigns i, count;
    */
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[i] % 2 == 0) {
                count += arr[i];
            }
        }
    }

    return count;
}
