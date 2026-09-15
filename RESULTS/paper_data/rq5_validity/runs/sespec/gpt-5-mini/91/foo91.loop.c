
#include <stddef.h>

/*@
  predicate sorted_non_decreasing(int* a, integer lo, integer hi) =
    lo >= hi - 1 ? \true
                 : (\forall integer k; lo <= k < hi-1 ==> a[k] <= a[k+1]);
*/

/*@
  requires arr_len > 0;
  requires \valid_read(arr + (0 .. arr_len-1));
  requires sorted_non_decreasing(arr, 0, arr_len);
*/
int foo91(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid =  high / 2;

            /*@
              loop invariant 0 <= low <= arr_len;
              loop invariant 0 <= high <= arr_len;
              loop invariant low <= high;
              loop invariant 0 <= mid <= arr_len;
              loop invariant low < high ==> mid == low + (high - low) / 2;
              loop invariant key == \at(key,Pre);
              loop invariant arr_len == \at(arr_len,Pre);
              loop invariant arr == \at(arr,Pre);
              loop invariant \forall integer i; 0 <= i < arr_len ==> arr[i] == \at(arr[i],Pre);
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
