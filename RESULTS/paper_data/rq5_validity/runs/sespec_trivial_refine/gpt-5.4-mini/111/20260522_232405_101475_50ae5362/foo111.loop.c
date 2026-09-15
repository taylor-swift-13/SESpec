
/*@
predicate rev_eq{L}(int *x, int *y, integer n) =
  \forall integer i; 0 <= i < n ==> x[i] == y[n - 1 - i];
*/

int foo111(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
          loop invariant 0 <= index;
          loop invariant x_len < 0 || index <= x_len;
          loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k];
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
