
/*@
  logic integer idx(int i) = i;
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
*/
int foo91(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (0 <= low <= high <= \at(arr_len,Pre) && mid == low + (high - low) / 2);
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= low <= \at(arr_len,Pre)));
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= high <= \at(arr_len,Pre)));
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (mid == low + (high - low) / 2));
          loop invariant (!(0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre))) ==> ((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant key == \at(key,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < \at(arr_len,Pre) ==> arr[k] == \at(arr,Pre)[k];
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
