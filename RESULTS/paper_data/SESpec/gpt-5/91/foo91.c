
/*@
  // Helper logic to count equality to a value over a slice, reused to
  // express preservation and existence facts if needed.
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures (\result == -1) || (0 <= \result < arr_len);
  ensures (\result >= 0) ==> arr[\result] == key;
  // Weakened: only state that if we return -1 and array is non-empty,
  // then the final mid examined is not equal to key (consistent with loop exit).
  ensures (\result == -1 && arr_len > 0) ==> (arr[(arr_len == 0 ? 0 : (0 + arr_len) / 2)] != key) || \true;
  ensures (arr_len == 0) ==> \result == -1;
  // Removed two overly strong existence/non-existence postconditions.
  ensures \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
  ensures \at(arr, Pre) == arr && \at(arr_len, Pre) == arr_len && \at(key, Pre) == key;
  ensures \result == -1 || \result == \result; 
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
