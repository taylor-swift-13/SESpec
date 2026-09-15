
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires args_len >= 0;
  requires arr_len >= 0;
  requires \valid(args + (0 .. args_len - 1));
  requires \valid(arr + (0 .. arr_len - 1));
  ensures 0 <= \result <= args_len || 0 <= \result <= arr_len;
*/
int foo206(int * args, int args_len, int * arr, int arr_len, int array) {

    int ret = 0;
    int r = 0;
    
    /*@
      loop invariant 0 <= ret <= args_len;
      loop invariant 0 <= r <= arr_len;
      loop invariant \forall integer k; 0 <= k < ret ==> (\exists integer j; 0 <= j < r && args[k] == arr[j]) || (\forall integer j; 0 <= j < r ==> args[k] != arr[j]);
      loop invariant \forall integer k; 0 <= k < r ==> (\exists integer j; 0 <= j < ret && arr[k] == args[j]) || (\forall integer j; 0 <= j < ret ==> arr[k] != args[j]);
      loop invariant \forall integer k; 0 <= k < ret ==> args[k] == \at(args[k], Pre);
      loop invariant \forall integer k; 0 <= k < r ==> arr[k] == \at(arr[k], Pre);
      loop invariant array == \at(array,Pre);
      loop invariant arr_len == \at(arr_len,Pre);
      loop invariant arr == \at(arr,Pre);
      loop invariant args_len == \at(args_len,Pre);
      loop invariant args == \at(args,Pre);
      loop assigns ret, r;
    */
    while (ret < args_len && r < arr_len) {
        if (args[ret] < arr[r]) {
            ret++;
        } else if (args[ret] > arr[r]) {
            r++;
        } else {
            ret++;
            r++;
        }
    }
    
    return ret < args_len ? ret : r;
}
