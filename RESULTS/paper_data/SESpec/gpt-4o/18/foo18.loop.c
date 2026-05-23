
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(a + (0 .. a_len - 1));
  requires a_len >= 1;
  ensures \forall integer k1, k2; 0 <= k1 <= k2 < a_len ==> a[k1] <= a[k2];
*/
void foo18(int * a, int a_len) {

    int N = a_len;

    /*@
      loop invariant 1 <= i <= N;
      loop assigns i, a[0..N-1];
    */
    for (int i = 1; i < N; i++) { // N branches
        int j = i - 1;
        int x = a[i];

        /*@
          loop invariant -1 <= j < i;
          loop assigns j, a[0..N-1];
        */
        while ((j >= 0) && (a[j] > x)) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}
