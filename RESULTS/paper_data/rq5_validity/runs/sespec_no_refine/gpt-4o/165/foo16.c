
/*@
  // No additional predicate or logic function is required for this program.
*/

/*@ 
  predicate is_even(integer x) = (x & 1) == 0;

  predicate even_pair_exists(int *arr, integer len) =
    \exists integer i, j; 0 <= i < j < len && is_even(arr[i] ^ arr[j]);
*/
/*@
  requires \valid(arr + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;

  assigns \nothing;

  ensures \result == -1 <==> arr == \null;
  ensures \result == 0 <==> arr != \null && arr_len == 1;
  ensures \result >= 0;
  ensures \result == \sum(0 <= i < arr_len, 0 <= j < arr_len && i < j && is_even(arr[i] ^ arr[j]) ? 1 : 0);
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
      loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < arr_len && k != l ==> 
                      ((arr[k] ^ arr[l]) & 1) == 0 ==> evenPairCount >= 1;
      loop assigns i, evenPairCount;
    */
    for (int i = 0; i < arr_len; i++) {
        
        /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant evenPairCount >= 0;
          loop invariant \forall integer k, l; 0 <= k <= i && i + 1 <= l < c && k != l ==> 
                          ((arr[k] ^ arr[l]) & 1) == 0 ==> evenPairCount >= 1;
          loop assigns c, pair, odd, even, evenPairCount;
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
