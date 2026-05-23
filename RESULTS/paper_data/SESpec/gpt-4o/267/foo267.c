
/*@
  logic integer count_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : count_odd(a, lo, hi - 1) + (a[hi - 1] % 2 != 0 ? 1 : 0);
*/

/*@
  logic integer last_odd(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : (a[hi - 1] % 2 != 0 ? a[hi - 1] : last_odd(a, lo, hi - 1));
*/

/*@
  requires \valid(args + (0..args_len-1));
  requires args_len >= 0;
  requires array == args_len;
   // Weakened clause
*/
int foo267(int * args, int args_len, int array) {

    int ret = 0;
    int start = 0;

    /*@
      loop invariant 0 <= index <= array;
      loop invariant 0 <= start <= count_odd(args, 0, index);
      loop invariant start % 2 != 0 ==> ret == last_odd(args, 0, index);
      loop invariant \forall integer k; 0 <= k < index ==> args[k] == \at(args[k], Pre);
      loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> count_odd(args, 0, k + 1) > count_odd(args, 0, k));
      loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 == 0 ==> count_odd(args, 0, k + 1) == count_odd(args, 0, k));
      loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 != 0 ==> last_odd(args, 0, k + 1) == args[k]);
      loop invariant \forall integer k; 0 <= k < index ==> (args[k] % 2 == 0 ==> last_odd(args, 0, k + 1) == last_odd(args, 0, k));
      loop invariant array == \at(array, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop assigns index, ret, start;
      loop variant array - index;
    */
    for (int index = 0; index < array; index++) {
        if (args[index] % 2 != 0) {
            start++;
            if (start % 2 != 0) {
                ret = args[index];
            }
        }
    }

    return ret;
}
