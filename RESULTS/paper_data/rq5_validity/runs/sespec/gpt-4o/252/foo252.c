
/*@
  logic integer count_pairs(int* arr, integer lo, integer hi, integer sum) =
    lo >= hi ? 0
             : count_pairs(arr, lo, hi - 1, sum) + 
               (\exists integer j; lo <= j < hi && arr[hi - 1] + arr[j] == sum ? 1 : 0);
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires arr_len >= n && n >= 0;
  ensures \result >= 0;
  ensures \result == count_pairs(arr, 0, n, sum);
  assigns \nothing;
*/
int foo252(int * arr, int arr_len, int n, int sum) {

    int count = 0;
    /*@
      loop invariant 0 <= i <= n;
      loop invariant count >= 0;
      loop invariant count == count_pairs(arr, 0, i, sum);
      loop assigns i, count;
    */
    for (int i = 0; i < n; i++) {
        /*@
          loop invariant i + 1 <= j <= n;
          loop invariant count >= 0;
          loop invariant count == count_pairs(arr, 0, i, sum) + count_pairs(arr + i + 1, i + 1, j, sum);
          loop assigns j, count;
        */
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                count++;
            }
        }
    }
    return count;
}
