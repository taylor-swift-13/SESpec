
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  assigns args[0 .. array-1];
  ensures args == \at(args,Pre);
  ensures args_len == \at(args_len,Pre);
  ensures array == \at(array,Pre);
  ensures (\result >= 1) ==> (\result <= array + 1);
  ensures (1 <= \result && \result <= array) ==> (args[\result - 1] != \result);
  ensures (!(\exists integer i; 0 <= i < array && args[i] != i + 1)) ==> (\result == array + 1);
*/
int foo10_c159(int * args, int args_len, int array) {

    int ret = 0;

    /*@
      loop invariant 0 <= ret;
      loop invariant args == \at(args,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant array == \at(array,Pre);
      loop assigns ret, args[0..array-1];
    */
    while (ret < array) {
      if (args[ret] <= 0 || args[ret] > array
          || args[ret] == ret + 1) {
        ret++;
      } else {
        int j = args[ret];
        args[ret] = args[j - 1];
        args[j - 1] = j;
      }
    }

    /*@
      loop invariant 0 <= ret;
      loop invariant args == \at(args,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant array == \at(array,Pre);
      loop assigns ret;
    */
    for (ret = 0; ret < array; ret++) {
      if (args[ret] != ret + 1) {
        return ret + 1;
      }
    }

    return array + 1;
}
