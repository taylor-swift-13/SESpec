
/*@
  // No additional predicates or logic functions are required for this program.
*/

/*@
  // Define a logic function to compute the summation of even pairs
  logic integer count_even_pairs(int* arr, integer arr_len) =
    \sum(0, arr_len - 1, \lambda integer i; 
      \sum(i + 1, arr_len - 1, \lambda integer c; 
        (((arr[i] ^ arr[c]) & 1) == 0 ? 1 : 0)));
*/
/*@
  requires arr != \null;
  requires arr_len > 0;
  requires arr_len < 100;
  requires \valid(arr + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result == -1 <==> arr == \null;
  ensures \result == 0 <==> arr != \null && arr_len == 1;
  ensures arr != \null && arr_len > 1 ==> \result == count_even_pairs(arr, arr_len);
*/
int foo16(int * arr, int arr_len, int n) {

    if (arr == NULL) {
        return -1;
    }
    if (arr_len == 1) {
        return 0;
    }

    int evenPairCount = 0;
    /*@
      loop invariant 0 <= i <= arr_len;
      loop invariant evenPairCount >= 0;
      loop invariant evenPairCount == \sum(0, i - 1, \lambda integer k; 
                                           \sum(k + 1, arr_len - 1, \lambda integer l; 
                                                (((arr[k] ^ arr[l]) & 1) == 0 ? 1 : 0)));
      loop assigns i, evenPairCount;
    */
    for (int i = 0; i < arr_len; i++) {
        /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant evenPairCount >= 0;
          loop invariant evenPairCount == \sum(0, i - 1, \lambda integer k; 
                                               \sum(k + 1, arr_len - 1, \lambda integer l; 
                                                    (((arr[k] ^ arr[l]) & 1) == 0 ? 1 : 0)))
                                          + \sum(i, c - 1, \lambda integer l; 
                                                    (((arr[i] ^ arr[l]) & 1) == 0 ? 1 : 0));
          loop assigns c, evenPairCount;
        */
        for (int c = i + 1; c < arr_len; c++) {
            int pair = arr[i];
            int odd = arr[c];
            int even = pair ^ odd;
            if ((even & 1) == 0) {
                evenPairCount++;
            }
        }
    }
    return evenPairCount;
}
