
        /*@
        predicate sorted{L}(int *a, integer n) =
          \forall integer i, j; 0 <= i <= j < n ==> a[i] <= a[j];
        */
        
int foo237(int * arr, int arr_len, int x, int n) {

        int low = 0;
        int high = n - 1;
        int result = -1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= low;
          loop invariant high < n;
          loop invariant result == -1 || (0 <= result < n && arr[result] == x);
          loop assigns low, high, result;
            */
            while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                result = mid;
                high = mid - 1;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            
        return result;
}
