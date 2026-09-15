
/*@
  requires 0 < n <= arr_len;
  requires \valid_read(arr + (0 .. n-1));
*/

int foo157(int * arr, int arr_len, int n) {

        int *mpis = (int *)malloc(sizeof(int) * (n));
        int mpis_len = n;
        
        /*@
          loop invariant 0 <= i <= n;
          loop assigns i, mpis[0 .. n-1];
        */
        for (int i = 0; i < n; i++) {
            mpis[i] = arr[i];
        }
            
        /*@
          loop invariant 1 <= i <= n;
          loop assigns i, mpis[i];
        */
        for (int i = 1; i < n; i++) {
            
            /*@
              loop invariant 0 <= j <= i;
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
          loop invariant \forall integer k; 0 <= k < i ==> max >= mpis[k];
          loop invariant \exists integer k; 0 <= k < i && max == mpis[k];
          loop assigns i, max;
        */
        for (int i = 1; i < n; i++) {
            if (mpis[i] > max) {
                max = mpis[i];
            }
        }
            
        return max;
}
