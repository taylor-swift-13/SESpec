
/*@
  logic integer max_prefix(int* a, integer lo, integer hi) =
    lo >= hi ? a[lo]
             : (a[hi - 1] > max_prefix(a, lo, hi - 1) ? a[hi - 1] : max_prefix(a, lo, hi - 1));
*/

/*@ requires \valid(&arr[0] + (0..arr_len-1));
    requires \forall integer i; 0 <= i < arr_len ==> 0 <= arr[i] <= 100;
    requires arr_len > 0;
    requires arr_len < 100;
*/

int foo157(int * arr, int arr_len, int n) {

        int *mpis = (int *)malloc(sizeof(int) * (n));
        int mpis_len = n;

        /*@
          loop invariant i >= 0;
          loop assigns i, mpis[0 .. n-1];
        */
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }

        /*@
          loop assigns i, mpis[0 .. n-1];
        */
        for (int i = 1; i < n; i++) {
            /*@
              loop assigns j, mpis[0 .. n-1];
            */
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
        }

        int max = mpis[0];
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          
          loop assigns i, max;
            */
            for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
            
        return max;
}
