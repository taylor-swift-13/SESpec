
/*@
  requires n >= 1;
  requires \valid_read(arr + (0..arr_len-1));
  ensures \true;
*/
int foo8_c157(int * arr, int arr_len, int n) {

        int *mpis = (int *)malloc(sizeof(int) * (n));
        int mpis_len = n;
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant \valid_read(arr + (0..arr_len-1));
          loop assigns i, mpis[0..n-1];
        */
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }

        /*@
          loop invariant 1 <= i <= n;
          loop invariant \valid_read(arr + (0..arr_len-1));
          loop assigns i, mpis[0..n-1];
        */
        for (int i = 1; i < n; i++) {

            /*@
              loop invariant 0 <= j <= i;
              loop invariant \valid_read(arr + (0..arr_len-1));
              loop assigns j, mpis[i];
            */
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && mpis[i] < (mpis[j] * arr[i])) {
                    mpis[i] = mpis[j] * arr[i];
                }
            }
        }
            
        int max = mpis[0];
        
        /*@
          loop invariant 1 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> mpis[k] <= max;
          loop assigns i, max;
        */
        for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
            
        return max;
}
