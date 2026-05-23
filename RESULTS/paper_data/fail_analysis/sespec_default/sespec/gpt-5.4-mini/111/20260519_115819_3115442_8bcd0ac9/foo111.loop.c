
/*@
  predicate unchanged_segment{L}(int* a, integer n, integer i) =
    i >= n ||
    (a[i] == \at(a[i], L) && unchanged_segment(a, n, i + 1));
*/

int foo111(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
          loop invariant (0 < \at(x_len,Pre)) ==> (0 <= index <= x_len);
          loop invariant (!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)));
          loop invariant y_len == \at(y_len,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant x_len == \at(x_len,Pre);
          loop invariant x == \at(x,Pre);
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
