
/*@
  // No additional predicate or logic function is needed for this program.
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
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
      loop invariant evenPairCount >= 0;
      loop invariant \forall integer x, y; 0 <= x < i && 0 <= y < arr_len && x < y ==> 
                      ((arr[x] ^ arr[y]) & 1) == 0 ==> evenPairCount >= 1;
      loop assigns i, evenPairCount;
    */
    for (int i = 0; i < arr_len; i++) {
        /*@
          loop invariant i + 1 <= c <= arr_len;
          loop invariant evenPairCount >= 0;
          loop invariant \forall integer x, y; 0 <= x <= i && i + 1 <= y < c && x < y ==> 
                          ((arr[x] ^ arr[y]) & 1) == 0 ==> evenPairCount >= 1;
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
