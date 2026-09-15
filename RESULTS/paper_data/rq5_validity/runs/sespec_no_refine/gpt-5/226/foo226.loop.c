
/*@
  // No additional predicates or logic functions are required.
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
