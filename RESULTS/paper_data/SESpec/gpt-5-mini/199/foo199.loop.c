
/*@ 
  logic integer sum_prod(int* a, integer lo, integer hi, integer c) =
    lo >= hi ? 0
             : sum_prod(a, lo, hi - 1, c) + a[hi - 1] * a[c - (hi - 1) - 1];
*/

/*@ requires number >= 0; */
int foo199(int number) {

    int *arr = (int *)malloc(sizeof(int) * (number + 1));
    int arr_len = number + 1;
    arr[0] = 1;

    /*@
      loop invariant 1 <= c <= number + 1;
      loop invariant arr[0] == 1;
      loop assigns c, arr[0..number];
    */
    for (int c = 1; c <= number; c++) {
        arr[c] = 0;

        /*@
          loop invariant 0 <= n <= c;
          loop assigns n, arr[c];
        */
        for (int n = 0; n < c; n++) {
            arr[c] += arr[n] * arr[c - n - 1];
        }
    }

    return arr[number];
}
