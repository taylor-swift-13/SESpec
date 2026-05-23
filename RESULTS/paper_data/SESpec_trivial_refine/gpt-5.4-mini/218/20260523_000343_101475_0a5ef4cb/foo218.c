
/*@
  predicate exists_in_range(int *a, integer l, integer u, int v) =
    \exists integer k; l <= k <= u && a[k] == v;
*/

/*@ 
  requires n <= 0 || \valid_read(args + (0 .. n - 1));
  assigns \nothing;
  ensures \result >= -1;
  ensures \result == -1 || \result >= 0;
*/
int foo218(int * args, int args_len, int Array, int n) {

    int i = 0;
    int hi = n - 1;
    int result = -1;

    /*@
      loop invariant 0 <= i;
      loop invariant n <= 0 || (-1 <= hi < n);
      loop invariant n <= 0 || i <= hi + 1;
      loop invariant result == -1 || result >= 0;
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
