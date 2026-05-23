
/*@ 
  // Logic function to compute the sum of an array slice
  logic integer sum(int* arr, integer start, integer end) =
    (start > end) ? 0 : arr[start] + sum(arr, start + 1, end);
*/

/*@ 
  // Logic function to compute the value of arr[d] based on the nested loop logic
  logic integer compute_arr(integer d) =
    (d == 0) ? 1 : \sum(0, d - 1, compute_arr);
*/
/*@
  requires seed >= 0;
   // The function modifies the array elements from 0 to seed.
*/
int foo229(int seed) {

    int result = 0;
    int *arr = (int *)malloc(sizeof(int) * (seed + 1));
    int arr_len = seed + 1;
    arr[0] = 1;

    /*@
      loop invariant arr[0] == 1;
      loop invariant \forall integer i; 0 <= i < d ==> arr[i] >= 1;
      loop assigns arr[1 .. d];
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
