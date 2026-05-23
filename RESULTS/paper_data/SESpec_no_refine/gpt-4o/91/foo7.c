
/*@
  logic integer unchanged_array{L1,L2}(int* arr, integer len) =
    \forall integer i; 0 <= i < len ==> \at(arr[i],L1) == \at(arr[i],L2);
*/

/*@
  requires \at(arr_len,Pre) != 0 && \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires \valid(arr + (0..\at(arr_len,Pre)-1));
  ensures \result == -1 || (0 <= \result < \at(arr_len,Pre) && arr[\result] == key);
  ensures \result == -1 ==> \forall integer i; 0 <= i < \at(arr_len,Pre) ==> arr[i] != key;
  ensures \result != -1 ==> arr[\result] == key;
  ensures unchanged_array{Pre,Post}(arr, \at(arr_len,Pre));
  assigns \nothing;
*/
int foo7(int * arr, int arr_len, int key) {

    if (arr_len == 0) {
        return -1;
    } else {
        int low = 0;
        int high = arr_len;
        int mid = high / 2;

        /*@
          loop invariant 0 <= low <= high <= \at(arr_len,Pre);
          loop invariant 0 <= mid < \at(arr_len,Pre);
          loop invariant \forall integer i; 0 <= i < low ==> arr[i] < key;
          loop invariant \forall integer i; high <= i < \at(arr_len,Pre) ==> arr[i] > key;
          loop invariant key == \at(key,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array{Pre,Here}(arr, \at(arr_len,Pre));
          loop assigns low, high, mid;
          loop variant high - low;
        */
        while (low < high && arr[mid] != key) {
            if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
            mid = low + (high - low) / 2;
        }

        if (low >= high) {
            return -1;
        }
        return mid;
    }
}
