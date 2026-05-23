
/*@
  logic integer reverse_index(int len, integer index) = len - 1 - index;

  predicate arrays_unchanged(int* arr, integer len, int* arr_pre) =
    \forall integer i; 0 <= i < len ==> arr[i] == \at(arr_pre[i], Pre);
*/

/*@
  requires \valid(x + (0 .. x_len - 1)) && \valid(y + (0 .. y_len - 1));
  requires x_len == y_len && x_len > 0 && x_len < 100;
  assigns \nothing;
  ensures \result == 1 <==> (\forall integer i; 0 <= i < x_len ==> x[i] == y[reverse_index(x_len, i)]);
  ensures \result == 0 <==> !(\forall integer i; 0 <= i < x_len ==> x[i] == y[reverse_index(x_len, i)]);
*/
int foo34(int * x, int x_len, int * y, int y_len) {

    if (x_len != y_len) return 0;
    int index = 0;

    /*@
      loop invariant 0 <= index <= x_len;
      loop invariant (\forall integer k; 0 <= k < index ==> x[k] == y[reverse_index(x_len, k)]);
      loop invariant x_len == y_len;
      loop invariant \valid(x + (0 .. x_len - 1)) && \valid(y + (0 .. y_len - 1));
      loop invariant arrays_unchanged(x, x_len, x);
      loop invariant arrays_unchanged(y, y_len, y);
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
