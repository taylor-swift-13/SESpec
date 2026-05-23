
/*@
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires \forall integer k; 0 <= k + 1 < arr_len ==> arr[k] <= arr[k+1];
  assigns \nothing;
  ensures \result == -1 ==>
            \forall integer k; 0 <= k < arr_len ==> arr[k] != Array;
  ensures \result != -1 ==> 0 <= \result < arr_len
                          && arr[\result] == Array
                          && (\result == arr_len - 1 || arr[\result + 1] != Array);
*/
int foo175(int * arr, int arr_len, int Array) {

    int i = 0;
    int hi = arr_len - 1;
    int end = 0;

    /*@
      loop invariant 0 <= i <= arr_len;
      loop invariant -1 <= hi <= arr_len - 1;
      loop invariant i <= hi + 1;
      // Elements strictly before i are < Array
      // Elements strictly after hi are > Array
      // Input remains sorted and unchanged
      loop invariant \forall integer k; 0 <= k + 1 < arr_len ==> arr[k] <= arr[k+1];
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      // If Array exists in the whole array, then some occurrence lies in [i..hi]
      // Exit implication shape
      loop invariant (i > hi) ==> (i == hi + 1);
      loop invariant Array == \at(Array,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop assigns end, i, hi;
    */
    while (i <= hi) {
        end = (i + hi) / 2;
        if (arr[end] == Array) {
            if (end == arr_len - 1
                    || arr[end + 1] != Array) {
                return end;
            } else {
                i = end + 1;
            }
        } else if (arr[end] < Array) {
            i = end + 1;
        } else {
            hi = end - 1;
        }
    }

    return -1;
}
