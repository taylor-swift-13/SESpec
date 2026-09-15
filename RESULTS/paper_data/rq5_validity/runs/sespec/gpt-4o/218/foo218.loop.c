
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0 .. args_len - 1));
  requires n >= 0;
  requires args_len == n;
  requires \forall integer k; 0 <= k < n - 1 ==> args[k] <= args[k + 1]; // Array is sorted
  ensures (\result == -1) ==> (\forall integer k; 0 <= k < n ==> args[k] != Array);
  ensures (\result != -1) ==> (0 <= \result < n && args[\result] == Array);
*/
int foo218(int * args, int args_len, int Array, int n) {

    int i = 0;
    int hi = n - 1;
    int result = -1;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant -1 <= hi < n;
      loop invariant -1 <= result < n;
      loop invariant (result == -1) || (args[result] == Array);
      loop invariant (result == -1) ==> (i <= hi + 1);
      loop assigns i, hi, result;
    */
    while (i <= hi) {
        int tmp = (i + hi) / 2;
        if (args[tmp] == Array) {
            result = tmp;
            hi = tmp - 1;
        } else if (args[tmp] < Array) {
            i = tmp + 1;
        } else {
            hi = tmp - 1;
        }
    }

    return result;
}
