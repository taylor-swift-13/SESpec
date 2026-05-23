
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  ensures \result >= 1;
  ensures array == 0 || array == 1 ==> \result == 1;
  ensures array > 1 ==> (
    (\exists integer num; 1 <= num <= array && args[num - 1] != num && \result == num) ||
    (\forall integer num; 1 <= num <= array ==> args[num - 1] == num && \result == array)
  );
  assigns \nothing;
*/
int foo83(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= found <= num;
      loop invariant \forall integer k; 1 <= k < num ==> 
                       (args[k - 1] == k ==> found == k);
      loop invariant \forall integer k; 1 <= k < num ==> 
                       (args[k - 1] != k ==> found != k);
      loop assigns found;
      loop variant array - num;
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
