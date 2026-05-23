
/*@
  logic integer count_even_pairs(int* arr, integer lo, integer hi) =
    lo >= hi ? 0 :
    count_even_pairs(arr, lo, hi - 1) +
    (\exists integer j; lo <= j < hi && ((arr[hi - 1] ^ arr[j]) & 1) == 0 ? 1 : 0);
*/

/*@
  requires arr != \null;
  requires arr_len > 0;
  requires \valid(arr + (0 .. arr_len - 1));
  ensures \result >= 0;
  ensures \result == count_even_pairs(arr, 0, arr_len);
*/
int foo15(int * arr, int arr_len, int n) {

    if (arr == NULL) {
        return -1;
    }
    if (arr_len == 1) {
        return 0;
    }

    int evenPairCount = 0;

    /*@
      loop invariant 0 <= i <= arr_len;
      loop invariant evenPairCount == count_even_pairs(arr, 0, i);
      loop assigns i, evenPairCount;
    */
    for (int i = 0; i < arr_len; i++) {

        /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant evenPairCount == count_even_pairs(arr, 0, i) +
                                         count_even_pairs(arr + i, i + 1, c);
          loop assigns c, evenPairCount;
        */
        for (int c = i + 1; c < arr_len; c++) {
            int even = arr[i];
            int odd = arr[c];
            int z = even ^ odd;
            if ((z & 1) == 0) {
                evenPairCount++;
            }
        }
    }

    return evenPairCount;
}
