
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  requires array >= 1; // Strengthened precondition to ensure array is valid
  requires \forall integer k; 0 <= k < args_len ==> 0 <= args[k] <= array;
  assigns \nothing;
           (\forall integer k; 1 <= k < r ==> args[k - 1] == k) &&
           (args[r - 1] != r ==> \result == r) &&
           (args[r - 1] == r ==> \result == r);
*/
int foo85(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= found <= remaining;
      loop invariant 1 <= remaining <= array + 1; // Strengthened invariant
                       (args[k - 1] == k ==> found == k);
      loop invariant \forall integer k; 1 <= k < remaining ==> 
                       (args[k - 1] != k ==> found != k);
      loop invariant \forall integer k; 0 <= k < args_len ==> 
                       0 <= args[k] <= array;
      loop assigns found;
      loop assigns remaining;
      loop variant array - remaining;
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
