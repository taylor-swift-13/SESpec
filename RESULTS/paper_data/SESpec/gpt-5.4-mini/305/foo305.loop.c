
/*@
  requires n > 0;
  requires \valid_read(arr + (0 .. n - 1));
*/
int foo305(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
            
        /*@
          loop invariant 0 <= left;
          loop invariant right < n;
          loop invariant left <= right + 1;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (0 < \at(n,Pre) - 1) ==> (0 <= left <= right + 1);
          loop invariant (0 < \at(n,Pre) - 1) ==> (right < \at(n,Pre));
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop assigns left, right;
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
