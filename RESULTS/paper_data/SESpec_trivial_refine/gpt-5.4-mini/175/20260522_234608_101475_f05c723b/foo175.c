
        /*@
        predicate sorted{L}(int *arr, integer n) =
          \forall integer x, y; 0 <= x <= y < n ==> arr[x] <= arr[y];
        */

/*@
  requires 0 <= arr_len;
  requires arr_len > 0 ==> \valid_read(arr + (0 .. arr_len - 1));
  requires arr_len > 0 ==> sorted(arr, arr_len);
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < arr_len);
  ensures \result >= 0 ==> arr[\result] == Array;
  ensures \result >= 0 ==> (\result == arr_len - 1 || arr[\result + 1] != Array);
  ensures \result == -1 ==> \true;
  ensures \result >= 0 ==> \result < arr_len;
*/
int foo175(int *arr, int arr_len, int Array)
{
  int i = 0;
  int hi = arr_len - 1;
  int end = 0;

  /*@
    loop invariant 0 <= i <= arr_len;
    loop invariant -1 <= hi < arr_len;
    loop invariant i <= hi + 1;
    loop invariant sorted(arr, arr_len);
    loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= Array;
    loop assigns i, hi, end;
    loop variant hi - i + 1;
  */
  while (i <= hi) {
    end = (i + hi) / 2;
    if (arr[end] == Array) {
      if (end == arr_len - 1 || arr[end + 1] != Array) {
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
