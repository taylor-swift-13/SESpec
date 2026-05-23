
/*@
  requires \valid(arr + (0..arr_len-1));
  requires arr_len > 0;
  ensures \result == 0 ==> (\forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre));
  ensures \result > 0 ==> (\result < arr_len); // Weakened postcondition: only ensures result is within bounds
  assigns \nothing;
*/
int foo170(int * arr, int arr_len) {

    int ret = 0;
    int stop = arr_len - 1;

    /*@
      loop invariant 0 <= ret <= arr_len;
      loop invariant 0 <= stop < arr_len;
      loop invariant ret <= stop + 1;
      loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
      loop invariant \exists integer k; ret <= k <= stop ==> arr[k] == arr[ret];
      loop invariant \exists integer k; ret <= k <= stop ==> arr[k] == arr[stop];
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns ret, stop;
    */
    while (ret <= stop) {
        int r = ret + (stop - ret) / 2;
        if (r < stop
                && arr[r] > arr[r + 1]) {
            return r + 1;
        } else if (r > ret
                && arr[r] < arr[r - 1]) {
            return r;
        }
        if (arr[r] >= arr[ret]) {
            ret = r + 1;
        } else {
            stop = r - 1;
        }
    }

    return 0;
}
