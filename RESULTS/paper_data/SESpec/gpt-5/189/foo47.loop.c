
/*@
  logic integer count_eq_in_range{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq_in_range(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo47(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
          loop invariant 1 <= i;
          loop invariant (i < n) ==> i <= n;
          loop invariant \at(arr_len,Pre) == arr_len;
          loop invariant \at(arr,Pre) == arr;
          loop invariant \at(n,Pre) == n;
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
          loop invariant 1 <= count <= i;
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
