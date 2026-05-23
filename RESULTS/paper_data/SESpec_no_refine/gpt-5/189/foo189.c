
/*@
  logic integer min_prefix(int* a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : (min_prefix(a, lo, hi - 1) < a[hi - 1] ? min_prefix(a, lo, hi - 1) : a[hi - 1]);

  logic integer count_eq_range{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq_range(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  assigns \nothing;
  ensures n == 0 ==> \result == 0;
*/
int foo189(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre) ;
          loop assigns i, min, count;
        */
        for (int i = 1; i < n; i++) {
            if (min > arr[i]) {
                min = arr[i];
                count = 1;
            } else if (min == arr[i]) {
                count++;
            }
        }

        return count;
}
