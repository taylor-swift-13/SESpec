
/*@
  // No additional predicates or logic functions are required.
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  assigns \nothing;
  ensures (array == 0 || array == 1) ==> \result == 1;
  ensures (array != 0 && array != 1 && mismatch_index(args, array) != 0) ==> \result == mismatch_index(args, array);
  ensures (array != 0 && array != 1 && mismatch_index(args, array) == 0) ==> \result == array;
  ensures \result == ((array == 0 || array == 1) ? 1 : (mismatch_index(args, array) != 0 ? mismatch_index(args, array) : array));
*/
int foo226(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= remaining <= array + 1;
      loop invariant 1 <= found <= remaining;
      loop invariant \forall integer k; 1 <= k < remaining ==> (args[k-1] == k ==> found >= k);
      loop invariant \forall integer k; 1 <= k < remaining ==> (args[k-1] == k ==> found == k);
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
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
