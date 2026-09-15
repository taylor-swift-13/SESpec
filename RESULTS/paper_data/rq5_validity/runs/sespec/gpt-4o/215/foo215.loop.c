
/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid_read(args + (0..args_len-1));
  requires args_len >= 0;
  requires sorted(args, 0, args_len);
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
*/
int foo215(int * args, int args_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int p = -1;

    /*@
      loop invariant 0 <= i <= args_len;
      loop invariant -1 <= r < args_len;
      loop invariant -1 <= p < args_len;
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant sorted(args, 0, args_len);
      loop invariant \forall integer k; 0 <= k < i ==> args[k] < x;
      loop invariant \forall integer k; r < k < args_len ==> args[k] > x;
      loop invariant p == -1 || args[p] == x;
      loop invariant p == -1 || (i > p && r < p);
      loop assigns i, r, p, tmp;
    */
    while (i <= r) {
        int tmp = (i + r) / 2;
        if (args[tmp] == x) {
            p = tmp;
            i = tmp + 1;
        } else if (args[tmp] < x) {
            i = tmp + 1;
        } else {
            r = tmp - 1;
        }
    }

    return p;
}
