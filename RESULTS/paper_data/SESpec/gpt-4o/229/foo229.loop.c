
/*@
  // Define a logic function to compute the sum of an array slice.
  logic integer sum(int* arr, integer start, integer end) =
    (start >= end) ? 0 : sum(arr, start, end - 1) + arr[end - 1];
*/

int foo229(int seed) {

    int result = 0;
    int *arr = (int *)malloc(sizeof(int) * (seed + 1));
    int arr_len = seed + 1;
    arr[0] = 1;

    /*@
      loop invariant arr[0] == 1;
      loop invariant \forall integer i; 0 <= i < d ==> arr[i] >= 1;
      loop assigns arr[1 .. seed];
    */
    for (int d = 1; d <= seed; d++) {
        /*@
          loop invariant 0 <= c <= d;
          loop invariant arr[0] == 1;
          loop invariant \forall integer i; 0 <= i < d ==> arr[i] >= 1;
          loop assigns arr[d];
        */
        for (int c = 0; c < d; c++) {
            arr[d] = arr[d] + arr[c];
        }
    }
    return arr[seed];
}
