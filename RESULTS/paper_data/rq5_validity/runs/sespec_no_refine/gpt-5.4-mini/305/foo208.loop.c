
/*@
  logic integer prefix_len(int* arr, integer lo, integer hi) =
    lo >= hi ? 0 : prefix_len(arr, lo, hi - 1) + 1;
*/

/*@ 
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
*/
int foo208(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
            
        /*@
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (left >= 0 && left <= right + 1 && right < n));
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (right >= 0 && left <= n - 1));
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant arr == \at(arr,Pre);
          loop assigns mid, left, right;
            */
            while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
            
        return left;
}
