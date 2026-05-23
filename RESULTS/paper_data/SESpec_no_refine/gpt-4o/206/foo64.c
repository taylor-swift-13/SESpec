
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  logic integer sum{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : sum(a, lo, hi - 1) + a[hi - 1];
*/

/*@
  requires \valid(&args[0] + (0..args_len-1));
  requires \forall integer i; 0 <= i < args_len ==> 0 <= args[i] <= 100;
  requires args_len > 0;
  requires args_len < 100;
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns ret, r;
  ensures \result == (ret < args_len ? ret : r);
  ensures \forall integer i; 0 <= i < \old(args_len) ==> 
            (\exists integer j; 0 <= j < \old(arr_len) && args[i] == arr[j]) ==> 
            (i < \result || j < \result);
  ensures \forall integer i; 0 <= i < \result ==> 
            (args[i] < arr[\result] || arr[i] < args[\result]);
*/
int foo64(int * args, int args_len, int * arr, int arr_len, int array) {

    int ret = 0;
    int r = 0;

    /*@
      loop invariant 0 <= ret <= args_len;
      loop invariant 0 <= r <= arr_len;
      loop invariant \forall integer i; 0 <= i < ret ==> 
                      (\exists integer j; 0 <= j < r && args[i] == arr[j]);
      loop invariant \forall integer i; 0 <= i < r ==> 
                      (\exists integer j; 0 <= j < ret && arr[i] == args[j]);
      loop invariant array == \at(array, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop invariant args_len == \at(args_len, Pre);
      loop invariant args == \at(args, Pre);
      loop assigns ret, r;
      loop variant args_len - ret + arr_len - r;
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
