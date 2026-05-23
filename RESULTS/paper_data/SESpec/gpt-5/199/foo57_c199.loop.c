
/*@ 
  logic integer conv_sum(int* arr, integer c, integer hi) =
    hi <= 0 ? 0 : conv_sum(arr, c, hi - 1) + arr[hi - 1] * arr[c - (hi - 1) - 1];
*/

/*@
  requires number >= 0;
  assigns \nothing;
*/


int foo57_c199(int number) {

    int *arr = (int *)malloc(sizeof(int) * (number + 1));
    int arr_len = number + 1;
    arr[0] = 1;
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= c <= number + 1;
          loop invariant arr_len == number + 1;
          loop invariant arr[0] == 1;
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
          loop assigns c, arr[1 .. number];
            */
            for (int c = 1; c <= number; c++) {
        arr[c] = 0;
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 0 <= n <= c;
          loop invariant 1 <= c <= number;
          loop invariant \forall integer i; 0 <= i < c ==> arr[i] >= 0;
          loop invariant arr[c] == conv_sum(arr, c, n);
          loop assigns arr[c];
        */
        for (int n = 0; n < c; n++) {
            arr[c] += arr[n]
                    * arr[c - n - 1];
        }
        
    }
            
    return arr[number];
}
