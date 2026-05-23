
/*@
*/

int foo42(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= arr[k+1];
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop assigns i;
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] <= arr[i+1])
                return 0;
        }
            
        return 1;
}
