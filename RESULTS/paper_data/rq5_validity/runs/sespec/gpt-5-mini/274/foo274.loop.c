
/*@
  logic integer sum_even_indices_even_values(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : sum_even_indices_even_values(a, lo, hi - 1)
                + (((hi - 1) % 2 == 0 && a[hi - 1] % 2 == 0) ? a[hi - 1] : 0);
*/

/*@
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires arr_len >= 0;
  requires n >= 0;
  requires n <= arr_len;
  assigns \nothing;
*/
int foo274(int * arr, int arr_len, int n) {

    int count = 0;

    /*@
      loop invariant 0 <= n == \at(n, Pre);
      loop invariant 0 <= arr_len == \at(arr_len, Pre);
      loop invariant \valid_read(arr + (0 .. arr_len - 1));
      loop invariant arr == \at(arr, Pre);

      loop invariant 0 <= i <= \at(n, Pre);
      loop invariant count == sum_even_indices_even_values(arr, 0, i);
      loop invariant \forall integer k; 0 <= k < i ==> 0 <= k < \at(arr_len, Pre);
      loop invariant (i >= \at(n, Pre)) ==> count == sum_even_indices_even_values(arr, 0, \at(n, Pre));

      loop invariant (i < \at(n, Pre)) ==>
        ( (i % 2 == 0 && arr[i] % 2 == 0) ==> (count + arr[i] == sum_even_indices_even_values(arr, 0, i+1)) );

      loop invariant (i < \at(n, Pre)) ==>
        ( (! (i % 2 == 0 && arr[i] % 2 == 0)) ==> (count == sum_even_indices_even_values(arr, 0, i+1)) );

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
