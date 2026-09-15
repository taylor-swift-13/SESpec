
/*@ 
  requires \valid(&arr[0] + (0..arr_len-1));
  requires \forall integer ii; 0 <= ii < arr_len ==> 0 <= arr[ii] <= 100;
*/

int foo241(int * arr, int arr_len, int n) {

        int count = 0;
        int length = arr_len;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count;
          loop invariant length == \at(arr_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant arr_len == \at(arr_len,Pre);
          loop invariant arr == \at(arr,Pre);
          loop invariant \forall integer k; 0 <= k < length ==> arr[k] == \at(arr[k], Pre);
          loop assigns i, count;
            */
            for (int i = 0; i < length - 1; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i+1 <= j <= length;
          loop invariant 0 <= count;
          loop invariant \forall integer k; 0 <= k < length ==> arr[k] == \at(arr[k], Pre);
          loop assigns count, j;
            */
            for (int j = i + 1; j < length; j++) {
                if (arr[i] != arr[j]) {
                    count++;
                }
            }
            
        }
            
        return count;
}
