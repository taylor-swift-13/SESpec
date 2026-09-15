
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires array > 0;
  requires \valid(args + (0 .. array - 1));
  requires \forall integer k; 0 <= k < array ==> args[k] >= 0 && args[k] < array;
  requires \forall integer k1, k2; 0 <= k1 < k2 < array ==> args[k1] != args[k2]; // Strengthened precondition
  assigns \nothing;
  ensures \result != -1 ==> (0 <= \result < array && args[\result] == \result);
*/
int foo259(int * args, int args_len, int array) {

    int i = 0;
    int stop = array - 1;

    /*@
      loop invariant 0 <= i <= array;
      loop invariant -1 <= stop < array;
      loop invariant i <= stop + 1;
      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant \forall integer k; 0 <= k < array ==> args[k] == \at(args[k],Pre);
      loop assigns i, stop;
      loop variant stop - i + 1;
    */
    while (i <= stop) {
        int cur = i + (stop - i) / 2;
        if (args[cur] == cur) {
            return cur;
        } else if (args[cur] < cur) {
            i = cur + 1;
        } else {
            stop = cur - 1;
        }
    }

    return -1;
}
