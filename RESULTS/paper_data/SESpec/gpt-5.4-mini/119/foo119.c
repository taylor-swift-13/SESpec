
/*@
  logic boolean strict_decreasing_prefix(int* a, integer lo, integer hi) =
    hi <= lo + 1 ? \true
                  : strict_decreasing_prefix(a, lo, hi - 1) && a[hi - 2] > a[hi - 1];
*/

/*@
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
  assigns \nothing;
*/
int foo119(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /*@
          loop invariant 0 <= i <= n;
          loop invariant strict_decreasing_prefix(arr, 0, i);
          loop invariant \forall integer k; 0 <= k < i ==> (k + 1 < n ==> arr[k] > arr[k+1]);
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop invariant (i < n) ==> (i + 1 <= n);
          loop invariant (i == n) ==> strict_decreasing_prefix(arr, 0, n);
          loop invariant (i == n) ==> (\forall integer k; 0 <= k < n - 1 ==> arr[k] > arr[k+1]);
          loop invariant (i > 0) ==> arr[i-1] > arr[i];
          loop assigns i;
        */
            for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
