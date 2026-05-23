
/*@
  logic integer prod(int* arr, integer lo, integer hi) =
    lo > hi ? 1 : prod(arr, lo, hi - 1) * arr[hi - 1];

  logic integer nested_sum(int* arr, integer lo, integer hi) =
    lo > hi ? 0 : nested_sum(arr, lo, hi - 1) + prod(arr, lo, hi - 1);

  logic integer total_sum(int* arr, integer lo, integer hi) =
    lo > hi ? 0 : total_sum(arr, lo, hi - 1) + nested_sum(arr, lo, hi - 1);
*/

/*@
  requires \valid(arr + (0 .. arr_len - 1));
  requires 0 <= n <= arr_len;
  ensures \result == total_sum(arr, 0, n);
*/
int foo153(int * arr, int arr_len, int n) {

    int sum = 0;

    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == \at(n, Pre);
      loop invariant arr_len == \at(arr_len, Pre);
      loop invariant arr == \at(arr, Pre);
      loop assigns i, sum;
    */
    for (int i = 0; i < n; i++) {
        int product = 1;

        /*@
          loop invariant i <= j <= n;
          loop invariant n == \at(n, Pre);
          loop invariant arr_len == \at(arr_len, Pre);
          loop invariant arr == \at(arr, Pre);
          loop assigns j, product, sum;
        */
        for (int j = i; j < n; j++) {
            product *= arr[j];
            sum += product;
        }
    }

    return sum;
}
