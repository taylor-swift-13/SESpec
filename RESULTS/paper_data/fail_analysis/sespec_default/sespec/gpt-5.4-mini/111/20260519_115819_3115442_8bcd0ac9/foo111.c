
/*@
  predicate unchanged_segment{L}(int* a, integer n, integer i) =
    i >= n ||
    (a[i] == \at(a[i], L) && unchanged_segment(a, n, i + 1));
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
