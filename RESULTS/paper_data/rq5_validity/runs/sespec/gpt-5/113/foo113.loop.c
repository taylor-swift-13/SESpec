


int foo113(int * arr, int arr_len) {

        int n = arr_len;
        if (n < 2) {
            return 1;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer k; 0 <= k < n ==> arr[k] == \at(arr[k], Pre);
          loop invariant \forall integer k; 0 <= k < i ==> arr[k] < arr[k+1];
          loop invariant \forall integer a, b; 0 <= a < b && b <= i ==> arr[a] < arr[b];
          loop invariant i == 0 || (\exists integer t; 0 <= t < i && arr[t] < arr[t+1]);
          loop invariant (i < n) ==> (\forall integer k; 0 <= k < i ==> arr[k] < arr[k+1]);
          loop invariant !(i < n) ==> (\forall integer k; 0 <= k < n - 1 ==> arr[k] < arr[k+1]);
          loop assigns i;
            */
            for (int i = 0; i < n; i++) {
            if(arr[i] >= arr[i+1])
                return 0;
        }
            
        return 1;
}
