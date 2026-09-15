
/*@
  // No additional predicates or logic functions are required for this program.
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
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
      loop assigns i, evenPairCount;
    */
    for (int i = 0; i < arr_len; i++) {
        /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant evenPairCount >= 0;
          loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < arr_len && k < l ==> 
                         ((arr[k] ^ arr[l]) & 1) == 0 ==> evenPairCount >= 1;
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
