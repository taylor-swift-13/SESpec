
/*@
  // No additional predicate or logic function is needed for this program.
*/

/*@
  logic integer count_even_pairs{L}(int* arr, integer arr_len) =
    \sum(0, arr_len - 1, 
         \lambda integer i; 
         \sum(i + 1, arr_len - 1, 
              \lambda integer c; 
              (((arr[i] ^ arr[c]) & 1) == 0 ? 1 : 0)));

  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == -1 ==> arr == \null;
  ensures \result == 0 ==> arr != \null && arr_len == 1;
  ensures \result >= 0 ==> \result == count_even_pairs(arr, arr_len);
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
      loop invariant evenPairCount == count_even_pairs(arr, i);
      loop assigns i, evenPairCount;
      loop variant arr_len - i;
    */
    for (int i = 0; i < arr_len; i++) {
        /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant evenPairCount == count_even_pairs(arr, i) + 
                                          \sum(i + 1, c - 1, 
                                               \lambda integer j; 
                                               (((arr[i] ^ arr[j]) & 1) == 0 ? 1 : 0));
          loop assigns c, evenPairCount;
          loop variant arr_len - c;
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
