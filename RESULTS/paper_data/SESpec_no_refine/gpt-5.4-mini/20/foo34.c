
/*@ predicate arrays_unchanged{L1,L2}(int *a, integer n) =
      \forall integer i; 0 <= i < n ==> a[i] == \at(a[i], L2);
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
  ensures \result == 0 ==> x_len != y_len || (\exists integer i; 0 <= i < x_len && x[i] != y[x_len - 1 - i]);
  ensures \result == 1 ==> x_len == y_len && \forall integer i; 0 <= i < x_len ==> x[i] == y[x_len - 1 - i];
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
