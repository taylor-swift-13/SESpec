
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sorted{L}(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? 1
                 : (a[lo] <= a[lo + 1] ? sorted(a, lo + 1, hi) : 0);
*/

/*@
  requires \at(args_len, Pre) > 0 && \at(args_len, Pre) < 100;
  requires \valid(args + (0 .. args_len - 1));
  requires sorted(args, 0, args_len) == 1;
  ensures \result == -1 || (0 <= \result < args_len && args[\result] == x);
  ensures \forall integer k; 0 <= k < args_len && args[k] == x ==> \result == k;
*/
int foo76(int * args, int args_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant 0 <= i <= args_len;
      loop invariant -1 <= r < args_len;
      loop invariant -1 <= k < args_len;
      loop invariant (k == -1) || (0 <= k < args_len && args[k] == x);
      loop invariant \forall integer j; 0 <= j < i ==> args[j] <= x;
      loop invariant \forall integer j; r < j < args_len ==> args[j] >= x;
      loop invariant y == \at(y, Pre);
      loop invariant x == \at(x, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop invariant sorted(args, 0, args_len) == 1;
      loop assigns tmp, k, i, r;
    */
    while (i <= r) {
        int tmp = (i + r) / 2;
        if (args[tmp] == x) {
            k = tmp;
            i = tmp + 1;
        } else if (args[tmp] < x) {
            i = tmp + 1;
        } else {
            r = tmp - 1;
        }
    }

    return k;
}
