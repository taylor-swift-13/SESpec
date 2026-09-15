
        /*@
        predicate sorted{L}(int *a, integer n) =
          \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
        */

/*@
  requires 0 <= arr_len;
  requires arr_len == 0 || \valid_read(arr + (0 .. arr_len-1));
  assigns \nothing;
  ensures arr_len == 0 ==> \result == -1;
  ensures \result == -1 ==> \true;
  ensures \result != -1 ==> 0 <= \result < arr_len;
  ensures \result != -1 ==> arr[\result] == key;
*/
int foo91(int * arr, int arr_len, int key) {

        if (arr_len == 0) {
            return -1;
        } else {
            int low = 0;
            int high = arr_len;
            int mid = low + (high - low) / 2;

            /*@
              loop invariant 0 <= low <= high <= arr_len;
              loop invariant mid == low + (high - low) / 2;
              loop invariant low <= mid <= high;
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
