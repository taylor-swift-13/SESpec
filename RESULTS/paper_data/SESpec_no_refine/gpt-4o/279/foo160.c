
/*@
  logic integer max(int* array, integer lo, integer hi) =
    lo >= hi ? array[lo - 1] : (max(array, lo, hi - 1) > array[hi - 1] ? max(array, lo, hi - 1) : array[hi - 1]);

  logic integer second_max(int* array, integer lo, integer hi) =
    lo >= hi ? 0 : (array[hi - 1] < max(array, lo, hi) ? max(array, lo, hi - 1) : second_max(array, lo, hi - 1));
*/

/*@
  requires \at(args_len,Pre) > 0 && \at(args_len,Pre) < 100;
  requires \valid(args + (0..\at(args_len,Pre)-1));
  assigns g, ret;
  ensures \result == second_max(args, 0, \at(args_len,Pre));
*/
int foo160(int * args, int args_len) {

    int g = 0;
    int ret = args[0];

    /*@
      loop invariant 1 <= j <= \at(args_len,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop invariant g == second_max(args, 0, j);
      loop invariant ret == max(args, 0, j);
      loop assigns j, g, ret;
    */
    for (int j = 1; j < args_len; j++) {
        if (args[j] > ret) {
            g = g > ret ? g : ret;
        } else {
            ret = args[j];
        }
    }

    return g;
}
