
/*@
  logic integer min_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : ( hi == lo + 1 ? a[lo]
                              : ( a[hi-1] < min_prefix(a, lo, hi-1) ? a[hi-1] : min_prefix(a, lo, hi-1) ) );
*/

/*@
  predicate seen_min_value(int* a, integer lo, integer hi, integer v) =
    \exists integer k; lo < k <= hi && min_prefix(a, lo, k) == v;
*/

/*@
  requires \valid_read(arr + (0 .. arr_len-1));
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  assigns \nothing;
*/
int foo171(int * arr, int arr_len) {

    int result = 0;
    int min = arr[0];

    /*@
      loop invariant 1 <= i <= arr_len;
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant 0 <= result;
      loop invariant min == min_prefix(arr, 0, i);
      loop invariant result == 0 || seen_min_value(arr, 0, i, result);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
      loop assigns i, result, min;
    */
    for (int i = 1; i < arr_len; i++) {
        if (arr[i] > min) {
            result = result > min ? result : min;
        } else {
            min = arr[i];
        }
    }

    return result;
}
