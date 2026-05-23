
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
  requires \at(args_len, Pre) > 0 && \at(args_len, Pre) < 100;
  requires \valid(args + (0 .. args_len - 1));
  ensures \result == last_odd(args, 0, array);
*/
int foo144(int * args, int args_len, int array) {

    int ret = 0;
    int start = 0;

    /*@
      loop invariant array == \at(array, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop assigns index, ret, start;
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
