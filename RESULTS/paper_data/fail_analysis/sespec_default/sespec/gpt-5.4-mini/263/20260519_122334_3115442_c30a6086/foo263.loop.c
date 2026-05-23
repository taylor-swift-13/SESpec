
int foo263(int * arr, int arr_len, int n) {

        int start = 0;
        int end = n - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= start;
          loop invariant end < n;
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
