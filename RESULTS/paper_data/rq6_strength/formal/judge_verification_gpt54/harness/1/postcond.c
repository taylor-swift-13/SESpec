#include <limits.h>

/*@ requires n >= 0;
  decreases n;
  assigns \nothing;
  ensures \result == m + n; */
int stub_A(int m, int n);

/*@ requires \true;
ensures \result == m + n;
assigns \nothing; */
int stub_B(int m, int n);

/*@ requires \true;
ensures \result == m + n;
assigns \nothing; */
int check_A_implies_B(int m, int n) {
    return stub_A(m, n);
}

/*@ requires n >= 0;
  decreases n;
  assigns \nothing;
  ensures \result == m + n; */
int check_B_implies_A(int m, int n) {
    return stub_B(m, n);
}
