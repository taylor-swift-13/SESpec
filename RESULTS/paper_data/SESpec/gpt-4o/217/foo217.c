
/*@
  predicate sorted_prefix(int* a, integer lo, integer hi) =
    \forall integer i; lo <= i < hi - 1 ==> a[i] <= a[i + 1];
*/

/*@
  predicate binary_search_progress(int* a, integer lo, integer hi, integer x) =
    \forall integer i; lo <= i < hi ==> (a[i] == x || a[i] < x || a[i] > x);
*/

/*@
  requires args_len >= 0;
  requires \valid_read(args + (0 .. args_len - 1));
  requires sorted_prefix(args, 0, args_len);
  requires y >= 0 && y <= args_len;
  ensures \forall integer j; 0 <= j < args_len ==> args[j] == \at(args[j], Pre);
*/
int foo217(int * args, int args_len, int x, int y) {

    int i = 0;
    int r = y - 1;
    int k = -1;

    /*@
      loop invariant 0 <= i;
      loop invariant -1 <= r && r < args_len;
      loop invariant i <= args_len;
      loop invariant -1 <= k < args_len;
      loop invariant \forall integer j; 0 <= j < args_len ==> args[j] == \at(args[j], Pre);
      loop invariant binary_search_progress(args, i, r + 1, x);
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
