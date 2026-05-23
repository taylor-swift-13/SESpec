
/*@
predicate sorted{L}(int *arr, integer n) =
  \forall integer i, j; 0 <= i <= j < n ==> arr[i] <= arr[j];
*/

/*@
  requires arr_len >= 0;
  requires \valid_read(arr + (0 .. arr_len - 1));
  requires sorted(arr, arr_len);
  assigns \nothing;
  ensures \result != -1 ==> 0 <= \result < arr_len;
  ensures \result != -1 ==> arr[\result] == array;
  ensures \result != -1 ==> (\result == arr_len - 1 || arr[\result + 1] != array);
*/
int foo176(int *arr, int arr_len, int array) {
  int found = 0;
  int hi = arr_len - 1;
  int end = 0;

  /*@
    loop invariant 0 <= found <= arr_len;
    loop invariant -1 <= hi < arr_len;
    loop invariant found <= hi + 1;
    loop assigns found, hi, end;
    loop variant hi - found + 1;
  */
  while (found <= hi) {
    end = (found + hi) / 2;
    if (arr[end] == array) {
      if (end == arr_len - 1 || arr[end + 1] != array) {
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
