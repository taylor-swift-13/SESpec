


/*@
  requires \valid_read(args + (0 .. args_len - 1));
  requires args_len >= 0;
*/
int foo226(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= remaining;
      loop invariant 1 <= found <= remaining;

      loop invariant
        (found == 1 && (\forall integer t; 1 <= t < remaining ==> args[t-1] != t))
        ||
        (1 <= found && found < remaining &&
         args[found-1] == found &&
         (\forall integer u; found < u < remaining ==> args[u-1] != u));

      loop invariant (\forall integer u; found < u < remaining ==> args[u-1] != u);

      loop invariant (remaining == array + 1) ==>
        ((found == 1 && (\forall integer t; 1 <= t <= array ==> args[t-1] != t))
         || (1 <= found && found <= array &&
             args[found-1] == found &&
             (\forall integer u; found < u <= array ==> args[u-1] != u)));

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
