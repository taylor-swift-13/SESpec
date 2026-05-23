
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo219(int * args, int args_len, int array, int n) {

    int ret = 0;
    int hi = n - 1;
    int result = -1;

    /*@
      loop invariant -1 <= hi < n;
      loop invariant -1 <= result < n;
      loop invariant (result == -1) || (args[result] == array);
                       (result == -1 ? 0 : 1);
      loop assigns ret, hi, result;
    */
    while (ret <= hi) {
        int tmp = (ret + hi) / 2;
        if (args[tmp] == array) {
            result = tmp;
            hi = tmp - 1;
        } else if (args[tmp] < array) {
            ret = tmp + 1;
        } else {
            hi = tmp - 1;
        }
    }

    return result;
}
