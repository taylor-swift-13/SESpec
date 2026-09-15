
/*@
  logic integer prefix_decr{L}(int* a, integer lo, integer hi) =
    lo >= hi ? 1
             : (a[lo] > a[lo+1] ? prefix_decr(a, lo+1, hi) : 0);
*/

/*@
  requires \valid(arr + (0..arr_len-1)) || arr_len == 0;
  requires arr_len >= 0;
  assigns \nothing;
*/
int foo42(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
        */
        for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
