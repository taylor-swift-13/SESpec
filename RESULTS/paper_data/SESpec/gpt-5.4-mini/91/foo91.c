

/*@
  requires arr_len >= 0;
  requires arr_len == 0 || \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires \forall integer i, j; 0 <= i <= j < arr_len ==> arr[i] <= arr[j];
  assigns \nothing;
  ensures arr_len == 0 ==> \result == -1;
  ensures arr_len > 0 && \result == -1 ==> \true;
  ensures arr_len > 0 && \result != -1 ==> 0 <= \result < arr_len;
  ensures arr_len > 0 && \result != -1 ==> arr[\result] == key;
  ensures arr_len > 0 && key >= 0 && key <= 100 ==> (\result == -1 || arr[\result] == key);
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
          loop invariant 0 <= low;
          loop invariant arr_len < 0 || (low <= high && high <= arr_len);
          loop invariant arr_len < 0 || (0 <= mid && mid <= arr_len);
          loop invariant key == \at(key,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
          loop invariant mid == low + (high - low) / 2;
          loop invariant low <= high || arr_len < 0;
          loop invariant arr_len < 0 || high - low >= 0 || low == high;
          loop invariant (low < high) ==> (low <= mid < high);

          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (0 <= mid && mid <= \at(arr_len,Pre));
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= low && low <= high));
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (arr_len < 0 || (low <= high && high <= arr_len)));
          loop invariant (0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre)) ==> (((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (arr_len < 0 || (0 <= mid && mid <= arr_len)));
          loop invariant (!(0 < \at(arr_len,Pre) && \at(arr,Pre)[\at(arr_len,Pre) / 2] != \at(key,Pre))) ==> ((mid == \at(arr_len,Pre) / 2)&&(high == \at(arr_len,Pre))&&(low == 0)&&(key == \at(key,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i], Pre);
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
