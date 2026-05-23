

/*@
  requires \valid(&x[0] + (0..x_len-1));
  requires \forall integer i; 0 <= i < x_len ==> 0 <= x[i] <= 100;
  requires \valid(&y[0] + (0..y_len-1));
  requires \forall integer i; 0 <= i < y_len ==> 0 <= y[i] <= 100;
  assigns \nothing;
  ensures x_len == \old(x_len);
  ensures y_len == \old(y_len);
  ensures \forall integer i; 0 <= i < x_len ==> x[i] == \old(x[i]);
  ensures \forall integer i; 0 <= i < y_len ==> y[i] == \old(y[i]);
  ensures \result == 1 ==> (\old(x_len) == \old(y_len) && \forall integer i; 0 <= i < \old(x_len) ==> \old(x[i]) == \old(y[\old(x_len) - 1 - i]));
  ensures \result == 0 ==> (\old(x_len) != \old(y_len) || \exists integer i; 0 <= i < \old(x_len) && \old(x[i]) != \old(y[\old(x_len) - 1 - i]));
  ensures 0 <= \result <= 1;
*/
int foo111(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
          loop invariant 0 <= index;
          loop invariant (x_len < 0) || (index <= x_len);
          loop invariant (0 < \at(x_len,Pre)) ==> (index <= \at(x_len,Pre));
          loop invariant (0 < \at(x_len,Pre)) ==> (index == 0 || \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k]);
          loop invariant (!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)));
          loop invariant y_len == \at(y_len,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant x_len == \at(x_len,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant \forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k], Pre);
          loop invariant \forall integer k; 0 <= k < y_len ==> y[k] == \at(y[k], Pre);
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
