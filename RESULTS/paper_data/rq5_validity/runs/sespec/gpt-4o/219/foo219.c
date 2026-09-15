
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len - 1 ==> args[i] <= args[i + 1]; // Array is sorted
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  ensures \result != -1 ==> args[\result] == array;
*/
int foo219(int * args, int args_len, int array, int n) {

    int ret = 0;
    int hi = n - 1;
    int result = -1;

    /*@
      loop invariant (result == -1) || (args[result] == array);
      loop assigns ret, hi, result;
      loop variant hi - ret + 1;
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
