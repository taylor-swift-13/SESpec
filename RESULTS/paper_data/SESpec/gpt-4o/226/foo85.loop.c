
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  requires \forall integer k; 0 <= k < args_len ==> 0 <= args[k] <= array;
  ensures \result >= 1 && \result <= array;
*/
int foo85(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= found <= remaining;
                       (args[k - 1] == k ==> found == k);
      loop invariant \forall integer k; 1 <= k < remaining ==> 
                       (args[k - 1] != k ==> found != k);
      loop invariant \forall integer k; 0 <= k < args_len ==> 
                       0 <= args[k] <= array;
      loop assigns remaining, found;
    */
    for (int remaining = 1; remaining <= array; remaining++) {
        if (args[remaining - 1] == remaining) {
            found = remaining;
        } else if (args[remaining - 1] != remaining) {
            return remaining;
        }
    }

    return found;
}
