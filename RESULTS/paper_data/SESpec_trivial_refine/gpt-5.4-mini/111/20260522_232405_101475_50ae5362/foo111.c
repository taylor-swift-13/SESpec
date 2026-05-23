
/*@
predicate rev_eq{L}(int *x, int *y, integer n) =
  \forall integer i; 0 <= i < n ==> x[i] == y[n - 1 - i];
*/

/*@
  requires 0 <= x_len;
  requires 0 <= y_len;
  requires x_len == y_len;
  requires \valid_read(x + (0 .. x_len - 1));
  requires \valid_read(y + (0 .. y_len - 1));
  assigns \nothing;
  ensures x_len == y_len ==> (\result == 1 <==> \forall integer i; 0 <= i < x_len ==> x[i] == y[x_len - 1 - i]);
  ensures \result == 1 ==> \forall integer i; 0 <= i < x_len ==> x[i] == y[x_len - 1 - i];
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
