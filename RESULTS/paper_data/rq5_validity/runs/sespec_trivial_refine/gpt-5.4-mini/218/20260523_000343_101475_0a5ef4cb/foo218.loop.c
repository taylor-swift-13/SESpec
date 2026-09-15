
/*@
  predicate exists_in_range(int *a, integer l, integer u, int v) =
    \exists integer k; l <= k <= u && a[k] == v;
*/

int foo218(int * args, int args_len, int Array, int n) {

    int i = 0;
    int hi = n - 1;
    int result = -1;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant (i == 0) || (0 <= i && i <= hi + 1);
      loop invariant hi < n;
      loop invariant result == -1 || (0 <= result && result < n && args[result] == Array);
      loop assigns i, hi, result;
    */
    while (i <= hi) {
        int tmp = (i + hi) / 2;
        if (args[tmp] == Array) {
            result = tmp;
            hi = tmp - 1;
        } else if (args[tmp] < Array) {
            i = tmp + 1;
        } else {
            hi = tmp - 1;
        }
    }

    return result;
}
