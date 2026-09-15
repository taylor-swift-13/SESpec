
        /*@
        */

/*@
  requires arr_len >= 0;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len - 1));
  requires \forall integer i, j; 0 <= i <= j < arr_len ==> arr[i] <= arr[j];

  assigns \nothing;

  ensures \result == -1 <==> (\forall integer i; 0 <= i < arr_len ==> arr[i] != array);
  ensures \result != -1 ==> 0 <= \result < arr_len && arr[\result] == array;
  ensures \result != -1 ==> (\forall integer j; \result < j < arr_len ==> arr[j] != array);
*/
int foo177(int *arr, int arr_len, int array) {
    int i = 0;
    int hi = arr_len - 1;
    int end = 0;

    /*@
      loop invariant 0 <= i <= arr_len;
      loop invariant -1 <= hi < arr_len;
      loop invariant i <= hi + 1;
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] < array;
      loop invariant \forall integer j; hi < j < arr_len ==> arr[j] > array;
      loop assigns i, hi, end;
      loop variant hi - i + 1;
    */
    while (i <= hi) {
        end = (i + hi) / 2;
        if (arr[end] == array) {
            if (end == arr_len - 1 || arr[end + 1] != array) {
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
