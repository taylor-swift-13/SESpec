
/*@ 
  // Count how many indices in [lo,hi) satisfy args[i] == (i+1)
  logic integer count_matches(int* args, integer lo, integer hi) =
    lo >= hi ? 0
             : count_matches(args, lo, hi - 1) + (args[hi - 1] == (hi) ? 1 : 0);
*/

/*@
  requires \valid_read(args + (0 .. args_len-1));
  assigns \nothing;
  ensures (array == 0 || array == 1) ==> \result == 1;
*/
int foo224(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant count_matches(args, 0, num-1) == num-1;
      loop invariant (num == 1) ==> (found == 1);
      loop invariant (num > 1) ==> (found == num-1);
      loop assigns num, found;
    */
    for (int num = 1; num <= array; num++) {
        if (args[num - 1] == num) {
            found = num;
        } else if (args[num - 1] != num) {
            return num;
        }
    }

    return found;
}
