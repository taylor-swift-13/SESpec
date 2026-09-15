
/*@
  logic integer x_prefix_match(int *x, int *y, integer n, integer i) =
    i <= 0 ? 1 :
    (x[i - 1] == y[n - 1 - (i - 1)] && x_prefix_match(x, y, n, i - 1));
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
  ensures x_len != y_len ==> \result == 0;
  ensures x_len == y_len && (\forall integer i; 0 <= i < x_len ==> x[i] == y[x_len - 1 - i]) ==> \result == 1;
  ensures x_len == y_len && (\exists integer i; 0 <= i < x_len && x[i] != y[x_len - 1 - i]) ==> \result == 0;
  ensures \result == 0 || \result == 1;
*/
int foo34(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
          loop invariant (0 < \at(x_len,Pre)) ==> (0 <= index <= x_len && x_prefix_match(x, y, x_len, index));
          loop invariant (!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)));
          loop invariant y_len == \at(y_len,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant x_len == \at(x_len,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant y_len == \at(y_len,Pre);
          loop invariant x_len == \at(x_len,Pre);
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
