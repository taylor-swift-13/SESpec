
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo205(int * args, int args_len, int * arr, int arr_len, int Array) {

    int ret = 0;
    int len = 0;

    /*@
      loop invariant (0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre)) ==> (ret + len <= args_len + arr_len);
      loop invariant (!(0 < \at(args_len,Pre) && 0 < \at(arr_len,Pre))) ==> ((len == 0)&&(ret == 0)&&(Array == \at(Array,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))&&(args_len == \at(args_len,Pre))&&(args == \at(args,Pre)));
      loop invariant Array == \at(Array,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns ret, len;
    */
    while (ret < args_len && len < arr_len) {
        if (args[ret] < arr[len]) {
            ret++;
        } else if (args[ret] > arr[len]) {
            len++;
        } else {
            ret++;
            len++;
        }
    }

    return ret < args_len ? ret : len;
}
