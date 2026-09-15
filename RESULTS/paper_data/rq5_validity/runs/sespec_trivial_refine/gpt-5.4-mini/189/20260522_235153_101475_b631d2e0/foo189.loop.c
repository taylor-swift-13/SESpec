
/*@
*/

/*
int foo189(int n, int * arr, int arr_len) {

        if (n == 0) {
            return 0;
        }

        int min = arr[0];
        int count = 1;

        
        /*@
          loop invariant 1 <= i <= n;
          loop invariant count >= 1;
          loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
          loop invariant \exists integer k; 0 <= k < i && arr[k] == min;
          loop assigns i, min, count;
        */
        for (int i = 1; i < n; i++) {
            if (min > arr[i]) {
                min = arr[i];
                count = 1;
            } else if (min == arr[i]) {
                count++;
            }
        }
            
        return count;
}
*/
