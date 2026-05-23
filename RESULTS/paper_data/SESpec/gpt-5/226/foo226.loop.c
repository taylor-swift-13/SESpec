
/*@
  // Count how many positions in [1..hi] satisfy args[k-1] == k.
  logic integer cnt_match(int* args, integer hi) =
    hi <= 0 ? 0 : cnt_match(args, hi - 1) + (args[hi - 1] == hi ? 1 : 0);
*/

/*@
  requires args_len >= 0;
  requires array >= 0;
  requires \valid_read(args + (0 .. args_len-1));
  requires array <= args_len;
  assigns \nothing;
*/
int foo226(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      // Loop counter bounds; at termination remaining == array + 1.
      loop invariant 1 <= remaining <= array + 1;

      // Bounds on found relative to progress.
      loop invariant 1 <= found <= (remaining <= array ? remaining : array);

      // Array contents remain unchanged.
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);

      // All indices strictly before 'remaining' matched.

      // Found tracks the last matched index in the processed prefix.
      loop invariant (remaining == 1 ==> found == 1);
      loop invariant (remaining > 1 ==> found == remaining - 1);

      // Counting characterization of the processed prefix.
      loop invariant cnt_match(args, remaining - 1) == (remaining - 1);

      // Exit implication: when remaining > array, everything up to 'array' matched and found == array.

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
