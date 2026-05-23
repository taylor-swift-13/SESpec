#include <limits.h>

/*@ requires i == 0.0;
  assigns \nothing;
  ensures \result == 0 ==> i == 0.0;
  ensures \result == 1 ==> i != 0.0;
  ensures \result == 0 || \result == 1; */
int stub_A(double i);

/*@ requires i != 0.0;
ensures i == 0.0 ==> \result == 0;
ensures \result == 1;
assigns \nothing; */
int stub_B(double i);

/*@ requires i != 0.0;
ensures i == 0.0 ==> \result == 0;
ensures \result == 1;
assigns \nothing; */
int check_A_implies_B(double i) {
    return stub_A(i);
}

/*@ requires i == 0.0;
  assigns \nothing;
  ensures \result == 0 ==> i == 0.0;
  ensures \result == 1 ==> i != 0.0;
  ensures \result == 0 || \result == 1; */
int check_B_implies_A(double i) {
    return stub_B(i);
}
