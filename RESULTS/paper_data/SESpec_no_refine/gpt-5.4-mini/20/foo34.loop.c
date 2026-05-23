
/*@ predicate arrays_unchanged{L1,L2}(int *a, integer n) =
      \forall integer i; 0 <= i < n ==> a[i] == \at(a[i], L2);
*/

int foo34(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
          loop invariant (0 < \at(x_len,Pre)) ==> (0 <= index <= x_len && \forall integer i; 0 <= i < index ==> x[i] == y[x_len - 1 - i]);
          loop invariant (!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)));
          loop invariant y_len == \at(y_len,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant x_len == \at(x_len,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant arrays_unchanged(x, x_len);
          loop invariant arrays_unchanged(y, y_len);
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
