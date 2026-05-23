
/*@
  predicate is_peak(int* arr, integer n, integer i) =
    0 <= i < n &&
    (
      (0 < i && i < n-1 && arr[i-1] < arr[i] && arr[i] > arr[i+1]) ||
      (i == 0 && n > 1 && arr[0] >= arr[1]) ||
      (i == n-1 && n > 1 && arr[n-2] < arr[n-1]) ||
      (n <= 1)
    );
*/

/*@
  requires \valid(arr + (0..arr_len-1));
  requires 0 <= n && n <= arr_len;
  ensures (0 <= \result && \result < n) || n == 0;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> 0 <= \result && \result < n;
  ensures \forall integer k; 0 <= k && k < arr_len ==> arr[k] == \old(arr[k]);
  assigns \nothing;
*/
int foo305(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k && k < arr_len ==> arr[k] == \at(arr[k], Pre);

          loop invariant 0 <= left || n == 0;
          loop invariant -1 <= right && right < n;
          loop invariant left <= right || n == 0;

          loop invariant n == 0 ==> (left == 0 && right == -1);

          loop invariant !(left < right) ==> (left == right || n == 0);
          loop invariant n > 0 ==> (0 <= left && left < n);

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
