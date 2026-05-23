
/*@
  // No additional predicates or logic functions are required for this program.
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures \result == -1 ==> arr == \null;
  ensures \result == 0 ==> arr != \null && arr_len == 1;
  ensures \result >= 0 ==> arr != \null && arr_len > 1;
  ensures \result == \sum(0 <= i < arr_len, 0 <= c < arr_len && i < c && ((arr[i] ^ arr[c]) & 1) == 0 ? 1 : 0);
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
      loop invariant evenPairCount == \sum(0 <= x < i, 0 <= y < arr_len && x < y && ((arr[x] ^ arr[y]) & 1) == 0 ? 1 : 0);
      loop invariant \forall integer x, y; 0 <= x < i && x < y < arr_len ==> 
          ((arr[x] ^ arr[y]) & 1) == 0 ==> evenPairCount >= 1;
      loop assigns i, evenPairCount;
    */
    for (int i = 0; i < arr_len; i++) {

        /*@
          loop invariant i + 1 <= c <= arr_len + 1;
          loop invariant evenPairCount == \sum(0 <= x <= i, 0 <= y < c && x < y && ((arr[x] ^ arr[y]) & 1) == 0 ? 1 : 0);
          loop invariant \forall integer x, y; 0 <= x <= i && x < y < c ==> 
              ((arr[x] ^ arr[y]) & 1) == 0 ==> evenPairCount >= 1;
          loop assigns c, evenPairCount;
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
