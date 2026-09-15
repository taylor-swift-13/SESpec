
/*@
*/

/*@ requires 0 <= n <= arr_len;
    requires \valid_read(arr + (0 .. n - 1));
    assigns \nothing;
    ensures \result == inv_count(arr, n);
    ensures \result >= 0;
    ensures n <= 1 ==> \result == 0;
    ensures \result <= n * (n - 1) / 2;
*/

int foo253(int * arr, int arr_len, int n) {

        int invCount = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= invCount;
          loop assigns i, invCount;
            */
            for (int i = 0; i < n; i++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i < n;
          loop invariant 0 <= i <= n && 0 <= invCount;
          loop invariant i + 1 <= j <= n;
          loop invariant invCount >= 0;
          loop assigns invCount, j;
            */
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
            
        }
            
        return invCount;
}
