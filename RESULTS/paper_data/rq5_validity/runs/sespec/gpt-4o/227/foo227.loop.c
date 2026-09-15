
/*@
  // Predicate or logic function to define properties of the array
  predicate valid_array(int *arr, integer len) = \valid(arr + (0 .. len - 1));

  // Logic function to compute the sum of array elements in a given range
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

int foo227(int b) {

    int result = 0;
    int *arr = (int *)malloc(sizeof(int) * (b + 1));
    int arr_len = b + 1;
    arr[0] = 1;

    /*@
      loop invariant arr[0] == 1;
      loop assigns d, arr[1 .. b];
    */
    for (int d = 1; d <= b; d++) {

        /*@
          loop assigns c, arr[d];
        */
        for (int c = 0; c < d; c++) {
            arr[d] = arr[d] + arr[c];
        }
    }
    return arr[b];
}
