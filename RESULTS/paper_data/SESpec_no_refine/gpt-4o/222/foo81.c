
/*@
  logic integer count_odd_pairs(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd_pairs(arr, lo, hi - 1) +
               (\exists integer j; lo <= j < hi && ((arr[hi - 1] ^ arr[j]) % 2 == 1) ? 1 : 0);
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires arr_len >= 0;
  ensures \result >= 0;
  ensures \result == count_odd_pairs(arr, 0, arr_len);
  assigns \nothing;
*/
int foo81(int * arr, int arr_len, int n) {

    int result = 0;
    int offset = arr_len;

    /*@
      loop invariant 0 <= index <= offset;
      loop invariant result == count_odd_pairs(arr, 0, index);
      loop invariant offset == \at(arr_len, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns index, result;
    */
    for (int index = 0; index < offset; index++) {

        /*@
          loop invariant index + 1 <= c <= offset;
          loop invariant result >= 0;
          loop invariant result == count_odd_pairs(arr, 0, index) +
                                   count_odd_pairs(arr + index, index + 1, c);
          loop assigns c, result;
        */
        for (int c = index + 1; c < offset; c++) {
            if ((arr[index] ^ arr[c]) % 2 == 1) {
                result++;
            }
        }

    }

    return result;
}
