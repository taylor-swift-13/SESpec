
        /*@
          requires n > 0;
          requires \valid(arr + (0 .. n-1));
        */
        
int foo283(int * arr, int arr_len, int n) {

        int i = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i % 2 == 0;
          loop assigns i;
            */
            while (i < n - 1) {
            if (arr[i] == arr[i + 1]) {
                i += 2;
            } else {
                return arr[i];
            }
        }
            
        return arr[n - 1];
}
