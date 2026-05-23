
/*@
  requires 0 <= y <= args_len;
  requires \valid_read(args + (0 .. y-1));
  requires \forall integer p, q; 0 <= p <= q < y ==> args[p] <= args[q];
  assigns \nothing;

  ensures 0 <= \result < y ==> args[\result] == x;
  ensures \result == -1 || (0 <= \result < y);
  ensures \result != -1 ==> \exists integer p; 0 <= p < y && \result == p && args[p] == x;
*/
int foo217(int * args, int args_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant 0 <= i <= y;
      loop invariant -1 <= r < y;
      loop invariant i <= r + 1;
      loop invariant k == -1 || (0 <= k < y && args[k] == x);

      loop assigns i, r, k;
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
