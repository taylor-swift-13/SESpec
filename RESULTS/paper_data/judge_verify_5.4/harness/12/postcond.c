#include <limits.h>

/*@ logic integer foo40_result(integer i) =
      i <= 0 ? 1 : foo40_result(i - 1); */

/*@ requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == foo40_result(i);
  ensures i == 0 ==> \result == 1;
  ensures i > 0 ==> \result == foo40_result(i - 1); */
int stub_A(int i);

/*@ requires i >= 0;
ensures i > 0 ==> \result == 1;
ensures i == 0 ==> \result == 1;
ensures i < 0 ==> \result == 0;
ensures \result == 1;
assigns \nothing; */
int stub_B(int i);

/*@ requires i >= 0;
ensures i > 0 ==> \result == 1;
ensures i == 0 ==> \result == 1;
ensures i < 0 ==> \result == 0;
ensures \result == 1;
assigns \nothing; */
int check_A_implies_B(int i) {
    return stub_A(i);
}

/*@ requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == foo40_result(i);
  ensures i == 0 ==> \result == 1;
  ensures i > 0 ==> \result == foo40_result(i - 1); */
int check_B_implies_A(int i) {
    return stub_B(i);
}
