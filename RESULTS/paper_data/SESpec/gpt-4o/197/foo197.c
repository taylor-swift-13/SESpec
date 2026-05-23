
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  requires n >= 0;
  ensures \result == \sum(0, n, \lambda integer i; \sum(0, i, \lambda integer k; \old(arr[k]) * \old(arr[i - k - 1])));
  assigns \result, \nothing;
*/
int foo197(int n) {
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    int arr_len = n + 1;
    arr[0] = 1;
    /*@
      loop invariant 1 <= c <= n + 1;
      loop invariant \forall integer i; 0 <= i < c ==> arr[i] == \sum(0, i, \lambda integer k; arr[k] * arr[i - k - 1]);
      loop assigns c, arr[..];
      loop variant n - c;
    */
    for (int c = 1; c <= n; c++) {
        arr[c] = 0;
        /*@
          loop invariant 0 <= k <= c;
          loop invariant arr[c] == \sum(0, k, \lambda integer j; arr[j] * arr[c - j - 1]);
          loop assigns k, arr[c];
          loop variant c - k;
        */
        for (int k = 0; k < c; k++) {
            arr[c] += arr[k] * arr[c - k - 1];
        }
    }
    return arr[n];
}
