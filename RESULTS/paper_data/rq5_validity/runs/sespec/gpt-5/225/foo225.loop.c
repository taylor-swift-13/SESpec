
/*@
  logic integer prefix_matches(int* a, integer hi) =
    hi <= 0 ? 1
            : (a[hi - 1] == hi ? prefix_matches(a, hi - 1) : 0);
*/

int foo225(int * args, int args_len, int array) {

    int find = 1;
    if (array == 0 || array == 1) {
        return find;
    }

    /*@
      loop invariant 1 <= remaining;
      loop invariant 1 <= find <= remaining;
      loop invariant (remaining <= array) ==> (remaining >= 1);
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant \forall integer j; 1 <= j < remaining && args[j-1] == j ==> find >= j;
      loop invariant \forall integer j; 1 <= j < remaining && find < j ==> args[j-1] != j;
      loop invariant (\exists integer j; 1 <= j < remaining && args[j-1] != j) ==> 
                      (\exists integer t; 1 <= t < remaining && args[t-1] != t);
      loop invariant (!(remaining <= array)) ==> \true;
      loop assigns remaining, find;
    */
    for (int remaining = 1; remaining <= array; remaining++) {
        if (args[remaining - 1] == remaining) {
            find = remaining;
        } else if (args[remaining - 1] != remaining) {
            return remaining;
        }
    }

    return find;
}
