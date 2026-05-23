

/*@
  requires 0 <= n;
  requires \valid(&arr[0] + (0..n-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
  ensures \result != -1 ==> 0 <= \result < n;
  ensures \result != -1 ==> arr[\result] == \result;
  ensures n == \old(n);
  ensures arr_len == \old(arr_len);
  ensures arr == \old(arr);
  ensures \result == -1 || (0 <= \result && \result < n && arr[\result] == \result);
*/
int foo263(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= n ==> 0 <= start;
          loop invariant end < n;

          loop invariant (start == 0) || (0 < start && start <= \at(n,Pre));
          loop invariant (0 <= \at(n,Pre) - 1) ==> (
              ((end == \at(n,Pre) - 1) && (start == 0) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)))
              ||
              (-1 <= end && end < \at(n,Pre))
          );
          loop invariant (!(0 <= \at(n,Pre) - 1)) ==> ((end == \at(n,Pre) - 1) && (start == 0) && (n == \at(n,Pre)) && (arr_len == \at(arr_len,Pre)) && (arr == \at(arr,Pre)));
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
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
