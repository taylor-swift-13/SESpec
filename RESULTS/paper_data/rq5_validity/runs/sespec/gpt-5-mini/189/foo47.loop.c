
/*@
  logic integer count_min(int* a, integer lo, integer hi, integer m) =
    lo >= hi ? 0
             : count_min(a, lo, hi - 1, m) + (a[hi - 1] == m ? 1 : 0);
*/

/*@
  logic integer min_pref(int* a, integer lo, integer hi) =
    lo + 1 >= hi ? a[lo]
                 : ( a[hi-1] < min_pref(a, lo, hi - 1) ? a[hi-1] : min_pref(a, lo, hi - 1) );
*/

/*@
  requires \valid(arr + (0 .. arr_len-1));
  requires \at(n,Pre) != 0 && \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100 ;
  requires n >= 0 && arr_len >= 0;
  requires n <= arr_len;
  assigns \nothing;
*/
int foo47(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        /*@
          loop invariant 1 <= i <= n;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant min == min_pref(arr, 0, i);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
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
