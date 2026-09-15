
        /*@
        */
        
int foo271(int * arr, int arr_len, int arrSize) {

        int result = 0;
        int count = 0;
        
            
        /*@ 
          loop invariant 0 <= i <= arrSize;
          loop invariant 0 <= count <= i;
          loop invariant count <= arrSize;
          loop invariant count == ( \numof int k; 0 <= k < i && arr[k] % 2 != 0 );
          loop invariant result == 0 || (\exists integer j; 0 <= j < i && arr[j] % 2 != 0 && result == arr[j]);
          loop assigns i, count, result;
        */
            for (int i = 0; i < arrSize; i++) {
            if (arr[i] % 2 != 0) {
                count++;
                if (count % 2 != 0) {
                    result = arr[i];
                }
            }
        }
            
        return result;
}
