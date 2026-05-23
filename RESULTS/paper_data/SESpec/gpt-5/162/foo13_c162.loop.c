
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

        
/*@
  requires \at(arr_len,Pre) > 0 && \at(arr_len,Pre) < 100;
  requires n >= 0;
  requires n == 0 || \valid(arr + (0 .. n-1));
*/

int foo13_c162(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant n >= 0;
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant n == 0 || \valid(arr + (0 .. n-1));
          loop assigns arr[0..n-1], i;
            */
            while (i < n) {
            if (arr[i] <= 0 || arr[i] > n || arr[i] == i + 1) {
                i++;
            } else {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            }
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
          loop assigns i;
            */
            for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
            
        return n + 1;
}
