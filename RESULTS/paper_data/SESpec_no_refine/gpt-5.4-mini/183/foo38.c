
/*@
  logic integer max_int(integer a, integer b) = a >= b ? a : b;

  predicate unchanged_array(int *arr, integer n) =
    \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;
  ensures n == 0 ==> \result == 0;
  ensures n != 0 ==> \result >= 1;
  ensures n != 0 ==> \result <= n;
  ensures \result == 0 || \result == left + 1;
*/
int foo38(int * arr, int arr_len, int n) {

        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= left <= right && right < \at(n,Pre)));
          loop invariant (0 < \at(n,Pre) - 1) ==> (((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= left <= right && left < \at(n,Pre)));
          loop invariant (!(0 < \at(n,Pre) - 1)) ==> ((right == \at(n,Pre) - 1)&&(left == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant unchanged_array(arr, n);
          loop assigns mid, left, right;
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
