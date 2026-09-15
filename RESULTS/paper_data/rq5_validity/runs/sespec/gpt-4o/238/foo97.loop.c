
/*@
  logic integer count_pairs(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_pairs(a, lo, hi - 1) + (a[lo] ^ a[hi - 1]) % 2 == 1 ? 1 : 0;
*/

/*@
  requires \valid(a + (0 .. a_len - 1)) && a_len >= 0;
  ensures \result >= 0;
*/
int foo97(int * a, int a_len, int n) {

    int count = 0;
    int length = a_len;
    /*@
      loop invariant 0 <= i <= length;
      loop invariant count >= 0;
      loop assigns i, count;
      loop variant length - i;
    */
    for (int i = 0; i < length; i++) {
        /*@
          loop invariant i + 1 <= j <= length;
          loop invariant count >= 0;
          loop assigns j, count;
          loop variant length - j;
        */
        for (int j = i + 1; j < length; j++) {
            if ((a[i] ^ a[j]) % 2 == 1) {
                count++;
            }
        }
    }
    return count;
}
