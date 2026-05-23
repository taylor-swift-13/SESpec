
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires arr_len > 0 && arr_len < 100;
  requires sorted(arr, 0, arr_len);
  ensures \result == -1 || (0 <= \result < arr_len && arr[\result] == array);
  ensures \result == -1 ==> \forall integer k; 0 <= k < arr_len ==> arr[k] != array;
  assigns \nothing;
*/
int foo28(int * arr, int arr_len, int array) {

    int i = 0;
    int hi = arr_len - 1;
    int end = 0;

    /*@
      loop invariant 0 <= i <= arr_len;
      loop invariant -1 <= hi < arr_len;
      loop invariant 0 <= end < arr_len;
      loop invariant sorted(arr, 0, arr_len);
      loop invariant count_eq(arr, 0, arr_len, array) == \at(count_eq(arr, 0, arr_len, array), Pre);
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
