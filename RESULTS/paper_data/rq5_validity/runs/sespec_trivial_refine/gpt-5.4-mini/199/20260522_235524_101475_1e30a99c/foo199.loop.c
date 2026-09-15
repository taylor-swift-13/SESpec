
/*@
*/

 /*@
  requires 0 <= number;
*/

int foo199(int number) {

    int *arr = (int *)malloc(sizeof(int) * (number + 1));
    int arr_len = number + 1;
    arr[0] = 1;
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS;
          loop invariant 1 <= c <= number + 1;
          loop invariant arr[0] == 1;
          loop invariant \forall integer k; 1 <= k < c ==> arr[k] == \sum integer i; 0 <= i < k; arr[i] * arr[k - i - 1];
          loop assigns c, arr[0..number];
            */
            for (int c = 1; c <= number; c++) {
        arr[c] = 0;

        /* >>> LOOP INVARIANT TO FILL <<< */

        /*@
          loop invariant 0 <= n <= c;
          loop invariant arr[c] == \sum integer i; 0 <= i < n; arr[i] * arr[c - i - 1];
          loop assigns n, arr[c];
        */
        for (int n = 0; n < c; n++) {
            arr[c] += arr[n] * arr[c - n - 1];
        }

    }
            
    return arr[number];
}
