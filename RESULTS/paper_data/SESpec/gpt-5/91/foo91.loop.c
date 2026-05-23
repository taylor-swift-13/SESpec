
/*@
  // Helper logic to count equality to a value over a slice, reused to
  // express preservation and existence facts if needed.
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo91(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

            /*@
              loop invariant key == \at(key,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant arr == \at(arr,Pre);
              loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
              loop invariant (low < high) ==> (mid == low + (high - low) / 2);
              loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
              loop invariant (high - low == 0) ==> (low >= high);
              loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (low >= 0 && low <= \at(arr_len,Pre)));
              loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (high >= 0 && high <= \at(arr_len,Pre)));
              loop invariant (!(0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre))) ==> ((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
              loop invariant key == \at(key,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant arr == \at(arr,Pre);
              loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr[k],Pre);
              loop assigns low, high, mid;
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
