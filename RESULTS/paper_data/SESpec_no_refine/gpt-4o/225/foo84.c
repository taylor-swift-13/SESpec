
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  ensures \result >= 1 && \result <= array;
  assigns \nothing;
*/
int foo84(int * args, int args_len, int array) {

    int find = 1;
    if (array == 0 || array == 1) {
        return find;
    }

    /*@
      loop invariant 1 <= find <= remaining;
                       (args[k - 1] == k ==> find == k);
      loop invariant \forall integer k; 1 <= k < remaining ==> 
                       (args[k - 1] != k ==> find != k);
                       0 <= args[k - 1] <= array;
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
