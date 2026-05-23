
/*@
  logic integer array_unchanged(int* arr, integer len, int* arr_pre) =
    \forall integer i; 0 <= i < len ==> arr[i] == arr_pre[i];
*/

/*@
  logic integer is_valid_low(int low, int mid, int high, int key, int* arr, int arr_len) =
    (arr[mid] < key && low == mid + 1 && high == \at(arr_len, Pre)) ||
    (arr[mid] >= key && low == \at(low, Pre) && high == \at(high, Pre));
*/

/*@
  logic integer is_valid_high(int low, int mid, int high, int key, int* arr, int arr_len) =
    (arr[mid] >= key && high == mid && low == \at(low, Pre)) ||
    (arr[mid] < key && high == \at(high, Pre) && low == \at(low, Pre));
*/

/*@
  logic integer is_valid_mid(int low, int mid, int high, int key, int* arr, int arr_len) =
    mid == low + (high - low) / 2;
*/

int foo7(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (is_valid_low(low, mid, high, key, arr, arr_len)));
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (is_valid_high(low, mid, high, key, arr, arr_len)));
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (is_valid_mid(low, mid, high, key, arr, arr_len)));
          loop invariant (!(0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre))) ==> ((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant key == \at(key,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant array_unchanged(arr, arr_len, \at(arr,Pre));
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
