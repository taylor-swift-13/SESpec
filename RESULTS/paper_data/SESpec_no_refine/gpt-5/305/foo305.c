
/*@
  // no extra predicates or logic functions are needed
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
  assigns \nothing;   
  ensures \result >= 0;
  ensures \result <= \old(n);
  ensures \old(n) >= 0;
  ensures \old(n) <= \old(arr_len);
  ensures arr == \old(arr);
  ensures arr_len == \old(arr_len);
  ensures \forall integer k; 0 <= k < \old(arr_len) ==> arr[k] == \old(arr[k]);
  ensures \result == \old(\result);
  ensures \result == \result;  
*/
int foo305(int * arr, int arr_len, int n) {

        int left = 0, right = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= n <= arr_len;
          loop invariant 0 <= left <= right + 1 <= n;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \valid_read(arr + (0..arr_len-1));
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k],Pre);
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
