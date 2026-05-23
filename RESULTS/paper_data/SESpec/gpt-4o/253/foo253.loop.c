
/*@
  logic integer count_inversions(int* arr, integer lo, integer hi) =
    lo >= hi ? 0
             : count_inversions(arr, lo, hi - 1) +
               (arr[hi - 1] < arr[lo] ? 1 : 0);
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires 0 <= n <= arr_len;
  ensures \result >= 0;
  ensures \result == count_inversions(arr, 0, n);
  ensures \forall integer i, j; 0 <= i < j < n ==> (arr[i] > arr[j] ==> \result >= 1);
*/
int foo253(int * arr, int arr_len, int n) {

    int invCount = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant invCount >= 0;
      loop assigns i, invCount;
    */
    for (int i = 0; i < n; i++) {

        /*@
          loop invariant i + 1 <= j <= n;
          loop invariant invCount >= 0;
          loop assigns j, invCount;
        */
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                invCount++;
            }
        }

    }
    return invCount;
}
