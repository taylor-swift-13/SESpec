
/*@
  logic integer count_odd_xor_pairs(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd_xor_pairs(arr, lo, hi - 1) + 
               ((arr[lo] ^ arr[hi - 1]) % 2 == 1 ? 1 : 0);
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires arr_len >= 0;
  ensures \result >= 0;
  ensures \result == count_odd_xor_pairs(arr, 0, arr_len);
*/
int foo223(int * arr, int arr_len, int n) {

    int result = 0;
    int offset = arr_len;

    /*@
      loop invariant 0 <= c <= offset;
      loop invariant result >= 0;
      loop invariant offset == \at(arr_len, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns c, result;
    */
    for (int c = 0; c < offset; c++) {

        /*@
          loop invariant c + 1 <= index <= offset;
          loop invariant result >= 0;
          loop invariant offset == \at(arr_len, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns index, result;
        */
        for (int index = c + 1; index < offset; index++) {
            if ((arr[c] ^ arr[index]) % 2 == 1) {
                result++;
            }
        }
    }

    return result;
}
