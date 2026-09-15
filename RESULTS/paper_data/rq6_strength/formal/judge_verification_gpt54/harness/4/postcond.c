#include <limits.h>

/*@ logic integer foo25_count(integer n) =
      n <= 0 ? 0 : 1 + 2 * foo25_count(n - 1); */

/*@ requires n >= 0;
  decreases n;
  assigns counter;
  ensures counter == \old(counter) + foo25_count(n); */
void stub_A(int n, int from, int to, int via);

/*@ requires n >= 1;
ensures n == 1 ==> \result == 1;
ensures \result == (1 << n) - 1;
assigns \nothing; */
void stub_B(int n, int from, int to, int via);

/*@ requires n >= 1;
ensures n == 1 ==> \result == 1;
ensures \result == (1 << n) - 1;
assigns \nothing; */
void check_A_implies_B(int n, int from, int to, int via) {
    stub_A(n, from, to, via);
}

/*@ requires n >= 0;
  decreases n;
  assigns counter;
  ensures counter == \old(counter) + foo25_count(n); */
void check_B_implies_A(int n, int from, int to, int via) {
    stub_B(n, from, to, via);
}
