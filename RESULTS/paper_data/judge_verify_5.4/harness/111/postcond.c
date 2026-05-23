#include <limits.h>

/*@ requires \valid(&x[0] + (0..x_len-1));
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
  ensures 0 <= \result <= 1; */
int stub_A(int * x, int x_len, int * y, int y_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int * x, int x_len, int * y, int y_len);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int * x, int x_len, int * y, int y_len) {
    return stub_A(x, x_len, y, y_len);
}

/*@ requires \valid(&x[0] + (0..x_len-1));
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
  ensures 0 <= \result <= 1; */
int check_B_implies_A(int * x, int x_len, int * y, int y_len) {
    return stub_B(x, x_len, y, y_len);
}
