
/*@
requires \valid(arr + (0 .. arr_len - 1));
requires 0 <= n <= arr_len;
requires \forall integer i, j; 0 <= i <= j < arr_len ==> arr[i] <= arr[j];
*/

int foo263(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= start;
          loop invariant -1 <= end;
          loop invariant start <= n;
          loop invariant end < n;
          loop invariant start <= end + 1;
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
