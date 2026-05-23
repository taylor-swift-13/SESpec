
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@ 
  predicate sorted_subarray(int* a, integer lo, integer hi) =
    lo >= hi - 1 ||
    (\forall integer i, j; lo <= i <= j < hi ==> a[i] <= a[j]);
*/

/*@ 
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo96(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= low <= high + 1));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (high < n));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (result == -1 || (0 <= result < n && arr[result] == x)));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((result == -1)&&(high == \at(n,Pre) - 1)&&(low == 0)&&(n == \at(n,Pre))&&(x == \at(x,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop assigns result, high, low;
            */
            while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            
        return result;
}
