
/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \valid_read(args + (0..args_len-1));
  requires args_len >= 0;
  requires sorted(args, 0, args_len);
  requires -1 <= y - 1 < args_len; // Ensure r is within valid range
  requires args_len == 0 || (args[0] <= x && x <= args[args_len - 1]); // Ensure x is within range of sorted array
  assigns \nothing;
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
      loop invariant i <= r + 1; // Companion invariant to ensure i does not exceed r + 1
      loop assigns i, r, p;
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
