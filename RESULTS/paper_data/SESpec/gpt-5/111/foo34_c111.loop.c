
/*@
  logic integer cnt_eq_rev(int* x, int* y, integer n, integer len) =
    n <= 0 ? 0
           : cnt_eq_rev(x, y, n - 1, len) + (x[n - 1] == y[len - n] ? 1 : 0);
*/

/*@
  logic boolean rev_eq(int* x, int* y, integer n, integer len) =
    n < 0 ? \false
          : cnt_eq_rev(x, y, n, len) == n;
*/

int foo34_c111(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
          loop invariant 0 <= index;
          loop invariant (0 < \at(x_len,Pre)) ==> (index <= x_len);
          loop invariant (\at(x_len,Pre) == \at(y_len,Pre) && \at(x_len,Pre) > 0 && \at(x_len,Pre) < 100 && \at(y_len,Pre) > 0 && \at(y_len,Pre) < 100) ==> rev_eq(x, y, index, x_len);
          loop invariant (!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)));
          loop invariant y_len == \at(y_len,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant x_len == \at(x_len,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant \forall integer k; 0 <= k < x_len ==> y[k] == \at(y[k], Pre);
          loop invariant \forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k], Pre);
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
