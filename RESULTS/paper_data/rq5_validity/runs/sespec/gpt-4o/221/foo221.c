
/*@
  logic integer count_odd_xor_pairs(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd_xor_pairs(arr, lo, hi - 1) +
               (arr[hi - 1] ^ arr[lo]) % 2 == 1 ? 1 : 0;
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires arr_len >= 0;
  requires \forall integer i; 0 <= i < arr_len ==> arr[i] >= 0; // Ensure array elements are non-negative
  ensures \result >= 0;
  assigns \nothing;
*/
int foo221(int * arr, int arr_len, int n) {

    int found = 0;
    int offset = arr_len;

    /*@
      loop invariant 0 <= c <= offset;
      loop invariant found >= 0;
      loop invariant offset == \at(arr_len, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns c, found;
    */
    for (int c = 0; c < offset; c++) {

        /*@
          loop invariant c + 1 <= index <= offset;
          loop invariant found >= 0;
          loop invariant offset == \at(arr_len, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns index, found;
        */
        for (int index = c + 1; index < offset; index++) {
            if ((arr[c] ^ arr[index]) % 2 == 1) {
                found++;
            }
        }
    }

    return found;
}
