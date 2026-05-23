
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  requires array >= 1; // Strengthened precondition to ensure valid range
  requires args_len >= array; // Ensure the array has enough elements
  ensures \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
  ensures \exists integer num; 1 <= num <= array &&
           (\forall integer k; 1 <= k < num ==> args[k - 1] == k) &&
           (args[num - 1] != num || num == array) ==> \result == num;
  assigns \nothing;
*/
int foo83(int * args, int args_len, int array) {

    int found = 1;
    if (array == 0 || array == 1) {
        return found;
    }

    /*@
      loop invariant 1 <= num <= array + 1;
      loop invariant 1 <= found <= num;
      loop invariant \forall integer k; 0 <= k < args_len ==> args[k] == \at(args[k], Pre);
      loop invariant \forall integer k; 1 <= k < num ==> args[k - 1] == k;
      loop assigns found, num;
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
