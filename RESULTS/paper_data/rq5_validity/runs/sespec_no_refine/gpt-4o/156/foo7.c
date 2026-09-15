
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

/*@
  assigns low, high, mid;
  ensures \result == -1 ==> (\forall integer i; 0 <= i < arr_len ==> arr[i] != key);
  ensures \result != -1 ==> (0 <= \result < arr_len && arr[\result] == key);
  ensures array_unchanged(arr, arr_len, \at(arr, Pre));
*/
int foo7(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

            /*@
              loop invariant 0 <= low <= high <= arr_len;
              loop invariant 0 <= mid < arr_len;
              loop invariant \forall integer i; 0 <= i < low ==> arr[i] < key;
              loop invariant \forall integer i; high <= i < arr_len ==> arr[i] >= key;
              loop invariant array_unchanged(arr, arr_len, \at(arr, Pre));
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
