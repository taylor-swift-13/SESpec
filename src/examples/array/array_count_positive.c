/*@
  logic integer cntpos(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : cntpos(a, lo, hi - 1) + (a[hi - 1] > 0 ? 1 : 0);
*/

/*@
  requires \valid_read(a + (0..n-1));
  requires n >= 0;
  ensures 0 <= \result <= n;
  ensures \result == cntpos(a, 0, n);
*/
int count_positive(int* a, int n) {
    int cnt = 0;
    int i = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= cnt <= i;
      loop invariant cnt == cntpos(a, 0, i);
      loop assigns i, cnt;
      loop variant n - i;
    */
    while (i < n) {
        if (a[i] > 0) {
            cnt++;
        }
        i++;
    }
    return cnt;
}
