
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
  logic integer is_in_range{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : (a[lo] == v ? 1 : is_in_range(a, lo + 1, hi, v));
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns found, hi, end;
  ensures \result == -1 <==> count_eq(arr, 0, arr_len, array) == 0;
  ensures \result >= 0 ==> arr[\result] == array;
  ensures \result >= 0 ==> \forall integer k; \result < k < arr_len ==> arr[k] != array;
  ensures \result == last_occurrence(arr, 0, arr_len - 1, array);
*/
int foo27(int * arr, int arr_len, int array) {

    int found = 0;
    int hi = arr_len - 1;
    int end = 0;

    /*@
      loop invariant array == \at(array,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant 0 <= found <= arr_len;
      loop invariant -1 <= hi < arr_len;
      loop invariant 0 <= end < arr_len;
      loop invariant \forall integer k; 0 <= k < found ==> arr[k] < array;
      loop invariant \forall integer k; hi < k < arr_len ==> arr[k] > array;
      loop assigns end, found, hi;
      loop variant hi - found;
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
