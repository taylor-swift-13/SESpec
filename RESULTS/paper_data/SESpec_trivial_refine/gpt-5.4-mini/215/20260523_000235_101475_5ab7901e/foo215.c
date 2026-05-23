
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */

/*@
  requires 0 <= y <= args_len;
  requires y == 0 || \valid_read(args + (0 .. y-1));
  assigns \nothing;
  ensures -1 <= \result;
  ensures \result < y;
  ensures \result == -1 || \result >= 0;
  ensures \result != -1 ==> args[\result] == x;
*/
int foo215(int * args, int args_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int p = -1;

    /*@
      loop invariant 0 <= i;
      loop invariant -1 <= r < y;
      loop invariant p == -1 || (0 <= p < y && args[p] == x);
      loop assigns i, r, p;
      loop variant r - i + 1;
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
