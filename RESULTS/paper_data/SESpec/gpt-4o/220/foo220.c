
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires count_eq(args, 0, args_len, array) <= 1; // Ensure no duplicates of 'array' in 'args'.
*/
int foo220(int * args, int args_len, int array, int n) {

    int i = 0;
    int hi = n - 1;
    int result = -1;

    /*@
      loop invariant n == \at(n,Pre);
      loop invariant array == \at(array,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns i, hi, result;
      loop variant hi - i + 1;
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
