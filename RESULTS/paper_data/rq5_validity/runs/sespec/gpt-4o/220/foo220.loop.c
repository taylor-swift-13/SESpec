
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo220(int * args, int args_len, int array, int n) {

    int i = 0;
    int hi = n - 1;
    int result = -1;

    /*@
      loop invariant result == -1 || args[result] == array;
      loop invariant n == \at(n,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns i, hi, result;
    */
    while (i <= hi) {
        int tmp = (i + hi) / 2;
        if (args[tmp] == array) {
            result = tmp;
            hi = tmp - 1;
        } else if (args[tmp] < array) {
            i = tmp + 1;
        } else {
            hi = tmp - 1;
        }
    }

    return result;
}
