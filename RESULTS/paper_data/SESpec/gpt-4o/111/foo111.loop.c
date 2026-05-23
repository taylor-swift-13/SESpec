
/*@
  logic integer reverse_index(integer len, integer index) = len - 1 - index;
*/

/*@
  predicate arrays_are_reverse(int* x, int x_len, int* y, int y_len, integer index) =
    \forall integer k; 0 <= k < index ==> x[k] == y[reverse_index(x_len, k)];
*/

/*@
  predicate unchanged_array(int* arr, integer len, integer start, integer end, int* arr_pre) =
    \forall integer k; start <= k < end ==> arr[k] == arr_pre[k];
*/

int foo111(int * x, int x_len, int * y, int y_len) {

    if (x_len != y_len) return 0;
    int index = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[reverse_index(x_len, k)];
      loop invariant \forall integer k; index <= k < x_len ==> x[k] == \at(x[k], Pre);
      loop invariant \forall integer k; index <= k < y_len ==> y[k] == \at(y[k], Pre);
      loop invariant x_len == \at(x_len, Pre);
      loop invariant y_len == \at(y_len, Pre);
      loop invariant x == \at(x, Pre);
      loop invariant y == \at(y, Pre);
      loop assigns index;
    */
    while (index < x_len) {
        if (x[index] != y[x_len - 1 - index]) {
            return 0;
        } else {
            index = index + 1;
        }
    }

    return 1;
}
