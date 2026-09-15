
/*@
  logic integer reverse_index(integer len, integer index) = len - 1 - index;
*/

/*@
  predicate arrays_are_reverse(int* x, int x_len, int* y, int y_len) =
    \forall integer k; 0 <= k < x_len ==> x[k] == y[reverse_index(x_len, k)];
*/

/*@
  predicate unchanged_array(int* arr, integer len, integer start, integer end, int* arr_pre) =
    \forall integer k; start <= k < end ==> arr[k] == arr_pre[k];
*/

/*@
  requires \valid(&x[0] + (0..x_len-1));
  requires \forall integer i; 0 <= i < x_len ==> 0 <= x[i] <= 100;
  requires x_len > 0;
  requires x_len < 100;
  requires \valid(&y[0] + (0..y_len-1));
  requires \forall integer i; 0 <= i < y_len ==> 0 <= y[i] <= 100;
  requires y_len > 0;
  requires y_len < 100;
  assigns \nothing;
  ensures \result == 0 ==> x_len != y_len || !arrays_are_reverse(x, x_len, y, y_len);
  ensures \result == 1 ==> x_len == y_len && \forall integer k; 0 <= k < x_len ==> x[k] == y[reverse_index(x_len, k)];
  ensures unchanged_array(x, x_len, 0, x_len, \at(x, Pre));
  ensures unchanged_array(y, y_len, 0, y_len, \at(y, Pre));
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
      loop invariant 0 <= index <= x_len;
      loop assigns index;
      loop variant x_len - index;
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
