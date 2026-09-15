
/*@
  logic integer count_eq(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

        /*@
        predicate unchanged_segment{L1,L2}(int* a, integer lo, integer hi) =
          \forall integer k; lo <= k < hi ==> \at(a[k], L1) == \at(a[k], L2);
        */
        
/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  requires arr_len > 0;
  requires arr_len < 100;
*/

int foo162(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \valid(arr + (0 .. arr_len-1));
          loop invariant 0 <= n <= arr_len;
          loop invariant \forall integer k; 0 <= k < n ==> 0 <= arr[k] <= n;
          loop invariant \forall integer v; 1 <= v <= n ==> count_eq(arr, 0, n, v) == \at(count_eq(arr, 0, n, v), Pre);
          loop assigns i, arr[..];
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
          loop invariant \valid(arr + (0 .. arr_len-1));
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] == k + 1;
          loop invariant unchanged_segment{Pre,Here}(arr, i, n);
          loop assigns i;
            */
            for (i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
            
        return n + 1;
}
