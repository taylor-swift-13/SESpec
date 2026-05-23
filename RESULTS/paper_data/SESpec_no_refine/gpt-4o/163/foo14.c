
/*@
  // No additional predicate or logic function is required for this program.
*/

/*@
  predicate is_even(integer x) = (x & 1) == 0;

  logic integer count_even_pairs{L}(int *arr, integer len) =
    \sum(0, len - 1, \lambda integer i; \sum(i + 1, len - 1, \lambda integer c;
      is_even(arr[i] ^ arr[c]) ? 1 : 0));
*/
/*@
  requires \valid(arr + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == -1 ==> arr == \null;
  ensures \result == 0 ==> arr != \null && arr_len == 1;
  ensures \result == count_even_pairs(arr, arr_len);
*/
int foo14(int * arr, int arr_len, int n) {

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
                                         \sum(i + 1, c - 1, \lambda integer j; is_even(arr[i] ^ arr[j]) ? 1 : 0);
          loop assigns c, evenPairCount;
          loop variant arr_len - c;
        */
        for (int c = i + 1; c < arr_len; c++) {
            int odd = arr[i];
            int b = arr[c];
            int even = odd ^ b;
            if ((even & 1) == 0) {
                evenPairCount++;
            }
        }
    }

    return evenPairCount;
}
