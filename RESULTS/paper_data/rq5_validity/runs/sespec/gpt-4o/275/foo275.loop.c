
/*@
  logic integer sum_range(int* arr, integer lo, integer hi) =
    lo >= hi ? 0 : sum_range(arr, lo, hi - 1) + arr[hi - 1];
*/

/*@
  requires arr != \null;
  requires arr_len >= 0;
  requires \valid(arr + (0 .. arr_len - 1));
  ensures \forall integer i, j; 0 <= i < j < arr_len ==> 
            \result == sum_range(arr, 0, arr_len);
*/
int foo275(int * arr, int arr_len, int n) {

    int sum = 0;
    /*@
      loop invariant 0 <= i <= arr_len;
      loop assigns i, sum;
      loop variant arr_len - i;
    */
    for (int i = 0; i < arr_len; i++) {
        /*@
          loop invariant i + 1 <= j <= arr_len;
          loop assigns j, sum;
          loop variant arr_len - j;
        */
        for (int j = i + 1; j < arr_len; j++) {
            sum += arr[i] ^ arr[j];
        }
    }
    return sum;
}
