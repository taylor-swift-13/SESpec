
/*@
  logic integer reverse_index(int len, integer index) = len - 1 - index;

  predicate arrays_unchanged(int* arr, integer len, int* arr_pre) =
    \forall integer i; 0 <= i < len ==> arr[i] == \at(arr_pre[i], Pre);
*/

/*@
  requires \at(x_len,Pre) == \at(y_len,Pre) && \at(x_len,Pre) > 0 && \at(x_len,Pre) < 100 && \at(y_len,Pre) > 0 && \at(y_len,Pre) < 100;
*/
int foo34(int * x, int x_len, int * y, int y_len) {

    if (x_len != y_len) return 0;
    int index = 0;

    /*@
      loop invariant 0 <= index <= x_len;
      loop invariant (0 < \at(x_len,Pre)) ==> 
                     (\forall integer k; 0 <= k < index ==> x[k] == y[reverse_index(x_len, k)]);
      loop invariant (!(0 < \at(x_len,Pre))) ==> 
                     ((index == 0) && (y_len == \at(y_len,Pre)) && (y == \at(y,Pre)) && (x_len == \at(x_len,Pre)) && (x == \at(x,Pre)));
      loop invariant y_len == \at(y_len,Pre);
      loop invariant y == \at(y,Pre);
      loop invariant x_len == \at(x_len,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant arrays_unchanged(y, y_len, y);
      loop invariant arrays_unchanged(x, x_len, x);
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
