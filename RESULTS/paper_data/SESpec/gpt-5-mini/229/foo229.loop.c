
/*@
  logic integer sum_slice(int* a, integer lo, integer hi) =
    lo >= hi ? 0 : sum_slice(a, lo, hi - 1) + a[hi - 1];
*/

/*@ requires seed >= 0; */
int foo229(int seed) {

    int result = 0;
    int *arr = (int *)malloc(sizeof(int) * (seed + 1));
    int arr_len = seed + 1;
    arr[0] = 1;

    /*@
      loop invariant 1 <= d <= seed + 1;
      loop invariant arr[0] == 1;
      loop invariant \forall integer i; 0 <= i < d ==> arr[i] >= 1;
      loop invariant \forall integer i; 0 <= i < d ==> arr[i] == sum_slice(arr, 0, i+1);
      loop assigns d, arr[0..seed];
    */
    for (int d = 1; d <= seed; d++) {

        /*@
          loop invariant 0 <= c <= d;
          loop invariant \forall integer i; 0 <= i < d ==> arr[i] >= 1;
          loop assigns arr[0..seed];
        */
        for (int c = 0; c < d; c++) {
            arr[d] = arr[d] + arr[c];
        }

    }

    return arr[seed];
}
