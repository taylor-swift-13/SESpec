
/*@
  // No additional predicate or logic function is required for this program.
*/

/*@
  logic integer count_even_pairs{L}(int *a, integer len) =
    \sum(0, len - 1, \lambda integer i; \sum(i + 1, len - 1, \lambda integer j; (((a[i] ^ a[j]) & 1) == 0 ? 1 : 0)));

  requires \valid(a + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;

  assigns \nothing;

  ensures a == \null ==> \result == -1;
  ensures a != \null && a_len == 1 ==> \result == 0;
  ensures a != \null && a_len > 1 ==> \result == count_even_pairs(a, a_len);
*/
int foo17(int * a, int a_len, int n) {

    if (a == NULL) {
        return -1;
    }
    if (a_len == 1) {
        return 0;
    }

    int evenPairCount = 0;

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant evenPairCount == count_even_pairs(a, i);
      loop assigns i, evenPairCount;
      loop variant a_len - i;
    */
    for (int i = 0; i < a_len; i++) {

        /*@
          loop invariant i + 1 <= j <= a_len;
          loop invariant evenPairCount == count_even_pairs(a, i) + count_even_pairs(a + i + 1, j - (i + 1));
          loop assigns j, evenPairCount;
          loop variant a_len - j;
        */
        for (int j = i + 1; j < a_len; j++) {
            int x = a[i];
            int y = a[j];
            int v = x ^ y;
            if ((v & 1) == 0) {
                evenPairCount++;
            }
        }
    }

    return evenPairCount;
}
