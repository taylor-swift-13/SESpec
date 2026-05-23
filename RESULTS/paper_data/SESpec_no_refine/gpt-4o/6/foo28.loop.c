
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr + (0..\at(arr_len,Pre)-1));
  ensures \result == -1 || (0 <= \result < \at(arr_len,Pre) && arr[\result] == array);
  ensures \result == -1 || (\result == \at(arr_len,Pre) - 1 || arr[\result + 1] != array);
  ensures \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
*/
int foo28(int * arr, int arr_len, int array) {

    int i = 0;
    int hi = arr_len - 1;
    int end = 0;

    /*@
      loop invariant 0 <= i <= arr_len;
      loop invariant -1 <= hi < arr_len;
      loop invariant 0 <= end < arr_len;
      loop invariant i <= hi + 1;
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
      loop assigns end, i, hi;
    */
    while (i <= hi) {
        end = (i + hi) / 2;
        if (arr[end] == array) {
            if (end == arr_len - 1
                    || arr[end + 1] != array) {
                return end;
            } else {
                i = end + 1;
            }
        } else if (arr[end] < array) {
            i = end + 1;
        } else {
            hi = end - 1;
        }
    }

    return -1;
}
