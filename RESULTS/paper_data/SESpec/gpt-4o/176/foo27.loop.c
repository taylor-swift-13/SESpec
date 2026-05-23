
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer count_less{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_less(a, lo, hi - 1, v) + (a[hi - 1] < v ? 1 : 0);
*/

/*@
  logic integer count_greater{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_greater(a, lo, hi - 1, v) + (a[hi - 1] > v ? 1 : 0);
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires \at(arr_len, Pre) > 0 && \at(arr_len, Pre) < 100;
  ensures \result == -1 || (0 <= \result < arr_len && arr[\result] == array);
  ensures \result == -1 || (\result == arr_len - 1 || arr[\result + 1] != array);
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
  assigns \nothing;
*/
int foo27(int * arr, int arr_len, int array) {

    int found = 0;
    int hi = arr_len - 1;
    int end = 0;

    /*@
      loop invariant 0 <= found <= hi + 1 <= arr_len;
      loop invariant 0 <= end < arr_len;
      loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
      loop invariant count_eq(arr, 0, arr_len, array) == \at(count_eq(arr, 0, arr_len, array), Pre);
      loop invariant count_less(arr, 0, arr_len, array) == \at(count_less(arr, 0, arr_len, array), Pre);
      loop invariant count_greater(arr, 0, arr_len, array) == \at(count_greater(arr, 0, arr_len, array), Pre);
      loop assigns end, found, hi;
    */
    while (found <= hi) {
        end = (found + hi) / 2;
        if (arr[end] == array) {
            if (end == arr_len - 1
                    || arr[end + 1] != array) {
                return end;
            } else {
                found = end + 1;
            }
        } else if (arr[end] < array) {
            found = end + 1;
        } else {
            hi = end - 1;
        }
    }

    return -1;
}
