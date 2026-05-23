
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
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
  ensures array == 0 ==> \result == 1;
  ensures array == 1 ==> \result == 1;
  ensures array >= 2 && (\forall integer i; 1 <= i <= array ==> args[i-1] == i) ==> \result == array;
  ensures 1 <= \result <= (array == 0 ? 1 : array);
  ensures (\result == array && array >= 2) ==> (cnt_match(args, array) <= array);
  ensures (\result == 1 && array >= 1) ==> (cnt_match(args, 0) == 0);
*/
int foo226(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= remaining <= array + 1;
      loop invariant 1 <= found <= (remaining <= array ? remaining : array);
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant (remaining == 1 ==> found == 1);
      loop invariant (remaining > 1 ==> found == remaining - 1);
      loop invariant cnt_match(args, remaining - 1) == (remaining - 1);
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
