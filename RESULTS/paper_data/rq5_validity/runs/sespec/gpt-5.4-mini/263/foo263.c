
/*@
  requires n >= 0;
  requires \valid_read(arr + (0 .. n-1));
  assigns \nothing;
  ensures \result == -1 || (0 <= \result < n && arr[\result] == \result);
  ensures \result == -1 ==> \result < 0;
  ensures \result != -1 ==> 0 <= \result < n;
  ensures \result != -1 ==> arr[\result] == \result;
*/
int foo263(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        
            
        /*@
          loop invariant 0 <= start <= \at(n,Pre);
          loop invariant -1 <= end < \at(n,Pre);
          loop invariant start <= end + 1;
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre);
          loop invariant (0 <= \at(n,Pre) - 1) ==> (start <= end + 1);
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (0 <= start <= \at(n,Pre)));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre))) || (-1 <= end < \at(n,Pre)));
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((end == \at(n,Pre) - 1)&&(start == 0)&&(n == \at(n,Pre))&&(arr_len == \at(arr_len,Pre))&&(arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < arr_len ==> arr[k] == \at(arr[k], Pre) ;
          loop assigns start, end;
            */
            while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == mid) {
                return mid;
            } else if (arr[mid] < mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
            
        return -1;
}
