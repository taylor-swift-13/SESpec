
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  ensures \result >= 1 && \result <= array;
  ensures \forall integer i; 1 <= i <= array ==> 
            (args[i - 1] == i ==> \result == i);
  ensures \forall integer i; 1 <= i <= array ==> 
            (args[i - 1] != i ==> \result == i);
  assigns \nothing;
*/
int foo85(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= found <= remaining;
                       (args[i - 1] == i ==> found == i);
                       (args[i - 1] != i ==> found == 1);
      loop invariant \forall integer i; 1 <= i < remaining ==> 
                       (args[i - 1] == i || args[i - 1] != i);
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
