

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures n == 0 ==> \result == 0;
  ensures n > 0 ==> 1 <= \result <= n;
  ensures n > 0 ==> arr == \at(arr,Pre);
  ensures n > 0 ==> arr_len == \at(arr_len,Pre);
  ensures n > 0 ==> n == \at(n,Pre);
  ensures \result == 0 <==> n == 0;
*/
int foo183(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant left >= 0;
          loop invariant right < n;
          loop invariant (n > 0) ==> left <= right + 1;
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= left && left <= right));
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= right && left <= right));
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop assigns left, right;
            */
            while (left < right) {
            if (arr[left] < arr[right]) {
                return left + 1;
            }
            int mid = (left + right) / 2;
            if (arr[mid] > arr[left]) {
                left = mid;
            } else {
                right = mid;
            }
        }
            
        return left + 1;
}
